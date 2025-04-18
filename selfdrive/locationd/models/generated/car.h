#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_453295383840605703);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1911868970296705050);
void car_H_mod_fun(double *state, double *out_2888549260601034860);
void car_f_fun(double *state, double dt, double *out_1255103046962299015);
void car_F_fun(double *state, double dt, double *out_945383962991830613);
void car_h_25(double *state, double *unused, double *out_6105482381361404151);
void car_H_25(double *state, double *unused, double *out_6304638965311202377);
void car_h_24(double *state, double *unused, double *out_2342535520600732832);
void car_H_24(double *state, double *unused, double *out_8477288564316701943);
void car_h_30(double *state, double *unused, double *out_2416846872812756224);
void car_H_30(double *state, double *unused, double *out_3786306006803953750);
void car_h_26(double *state, double *unused, double *out_3360356725714418659);
void car_H_26(double *state, double *unused, double *out_8400601789524293015);
void car_h_27(double *state, double *unused, double *out_462752510280447316);
void car_H_27(double *state, double *unused, double *out_8608741224254867358);
void car_h_29(double *state, double *unused, double *out_7418520140473601869);
void car_H_29(double *state, double *unused, double *out_8124640122585133225);
void car_h_28(double *state, double *unused, double *out_4763154705554877631);
void car_H_28(double *state, double *unused, double *out_8358473679559092140);
void car_h_31(double *state, double *unused, double *out_9101875306195315311);
void car_H_31(double *state, double *unused, double *out_6273993003434241949);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}