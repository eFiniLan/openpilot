#! /bin/bash

git checkout pfeifer-always-on-lateral
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/always-on-lateral/
cd panda
git format-patch -1 HEAD
mv *.patch ../../openpilot-patches/always-on-lateral/panda/
cd ..

git checkout pfeifer-current-max-speed
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/current-max-speed/

git checkout pfeifer-experimental-mode-toggle
git format-patch -3 HEAD --stdout > experimental-mode-toggle-combined.patch
mv *.patch ../openpilot-patches/experimental-mode-toggle/

git checkout pfeifer-fast-boot
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/fast-boot/

git checkout pfeifer-gap-adjust-control
git format-patch -3 HEAD --stdout > gap-adjust-control-combined.patch
mv *.patch ../openpilot-patches/gap-adjust-control/

git checkout pfeifer-hkg-long-control-tune
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/hkg-can-longitudinal-tuning-improvements/

git checkout pfeifer-lane-detection
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/lane-detection/

git checkout pfeifer-nudgeless-lane-change
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/nudgeless-lane-change/

git checkout pfeifer-speed-limit-control
git format-patch -3 HEAD --stdout > speed-limit-control-combined.patch
mv *.patch ../openpilot-patches/speed-limit-control/

git checkout pfeifer-vtsc
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/vtsc/

git checkout pfeifer-mapd
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/mapd/

git checkout pfeifer-button-manager
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/utils/button-manager/

git checkout pfeifer-gap-adjust-button
git format-patch -1 HEAD
mv *.patch ../openpilot-patches/utils/gap-adjust-button/


