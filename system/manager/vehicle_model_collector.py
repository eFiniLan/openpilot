#!/usr/bin/env python3

# MIT Non-Commercial License
#
# Copyright (c) 2019, dragonpilot
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, for non-commercial purposes only, subject to the following conditions:
#
# - The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
# - Commercial use (e.g., use in a product, service, or activity intended to generate revenue) is prohibited without explicit written permission from dragonpilot. Contact ricklan@gmail.com for inquiries.
# - Any project that uses the Software must visibly mention the following acknowledgment: "This project uses software from dragonpilot and is licensed under a custom license requiring permission for use."
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

import os
import importlib
import json
from openpilot.common.basedir import BASEDIR
from openpilot.common.params import Params


class VehicleModelCollector:
  def __init__(self):
    self.base_package = "opendbc.car"
    self.base_path = f"{BASEDIR}/opendbc/car"
    self.exclude_brands = ['body', 'mock']

    # Define the lookup dictionary for brand-to-group mappings
    self.brand_to_group_map = {
      "chrysler": [
        {"prefix": "DODGE_", "group": "Dodge"},
        {"prefix": "RAM_", "group": "Ram"},
        {"prefix": "JEEP_", "group": "Jeep"},
      ],
      "gm": [
        {"prefix": "BUICK_", "group": "Buick"},
        {"prefix": "CADILLAC_", "group": "Cadillac"},
        {"prefix": "CHEVROLET_", "group": "Chevrolet"},
        {"prefix": "HOLDEN_", "group": "Holden"},
      ],
      "honda": {"prefix": "ACURA_", "group": "Acura"},
      "toyota": {"prefix": "LEXUS_", "group": "Lexus"},
      "hyundai": [
        {"prefix": "KIA_", "group": "Kia"},
        {"prefix": "GENESIS_", "group": "Genesis"}
      ],
      "volkswagen": [
        {"prefix": "AUDI_", "group": "Audi"},
        {"prefix": "SKODA_", "group": "Skoda"},
        {"prefix": "SEAT_", "group": "Seat"}
      ]
    }

    # Define exceptions for group names
    self.group_name_exceptions = {
      "gm": "GM",
    }

  @staticmethod
  def is_car_model(car_class, attr):
    """Check if the attribute is a car model (not callable and not a dunder attribute)"""
    return not callable(getattr(car_class, attr)) and not attr.startswith("__")

  @staticmethod
  def move_to_proper_group(models, prefix):
    """
    Moves models with a certain prefix to their respective group.
    Example: Models starting with 'LEXUS_' should go to 'Lexus' group.
    """
    moved_models = []
    for model in models[:]:  # Iterate over a copy to avoid modifying during iteration
      if model.startswith(prefix):
        moved_models.append(model)
        models.remove(model)  # Remove from the original group
    return moved_models

  def format_group_name(self, group_name):
    """
    Formats group names according to the exceptions dictionary.
    Groups in the exceptions dictionary are returned in all caps, others are title cased.
    """
    return self.group_name_exceptions.get(group_name, group_name.title())

  def collect_models(self):
    """Collect all car models and organize them by brand/group"""
    # List all subdirectories (car brands)
    car_brands = sorted([
      name for name in os.listdir(self.base_path)
      if os.path.isdir(os.path.join(self.base_path, name)) and not name.startswith("__")
    ])

    grouped_models = {}

    # Import CAR from each subdirectory and group models by brand
    for brand in car_brands:
      if brand in self.exclude_brands:
        continue

      module_name = f"{self.base_package}.{brand}.values"
      try:
        module = importlib.import_module(module_name)
        if hasattr(module, "CAR"):
          car_class = getattr(module, "CAR")
          models = sorted([attr for attr in dir(car_class) if self.is_car_model(car_class, attr)])

          # Check if the brand has a special group in the lookup map
          if brand in self.brand_to_group_map:
            group_info = self.brand_to_group_map[brand]

            if isinstance(group_info, list):  # If multiple prefixes for the brand
              for prefix_info in group_info:
                moved_models = self.move_to_proper_group(models, prefix_info["prefix"])
                if moved_models:
                  if prefix_info["group"] not in grouped_models:
                    grouped_models[prefix_info["group"]] = []
                  grouped_models[prefix_info["group"]].extend(moved_models)
            else:  # Single prefix for the brand
              moved_models = self.move_to_proper_group(models, group_info["prefix"])
              if moved_models:
                if group_info["group"] not in grouped_models:
                  grouped_models[group_info["group"]] = []
                grouped_models[group_info["group"]].extend(moved_models)

          # Add remaining models to the respective brand
          if models:
            grouped_models[brand] = models
      except ModuleNotFoundError:
        pass

    # Sort the groups alphabetically
    sorted_grouped_models = sorted(grouped_models.items(), key=lambda x: x[0])

    # Convert to the desired output structure, ensuring models are sorted within each group
    output = [{"group": self.format_group_name(group), "models": sorted(models)}
              for group, models in sorted_grouped_models]

    return output

  # def save_to_params(self, output=None):
  #   """Save the collected model list to Params"""
  #   if output is None:
  #     output = self.collect_models()
  #   Params().put("dp_device_model_list", json.dumps(output))
  #   return output
  #
  # def run(self):
  #   """Collect models and save to params"""
  #   models = self.collect_models()
  #   self.save_to_params(models)
  #   return models

  def get_json(self):
    return self.collect_models()

  def get(self):
    return json.dumps(self.collect_models())

# Allow running as a script
if __name__ == "__main__":
  collector = VehicleModelCollector()
  print(collector.get())
