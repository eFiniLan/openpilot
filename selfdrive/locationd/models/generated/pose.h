#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1444822050377652636);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2786220128142028057);
void pose_H_mod_fun(double *state, double *out_7982786345480560970);
void pose_f_fun(double *state, double dt, double *out_3891050436305113138);
void pose_F_fun(double *state, double dt, double *out_5269798254466500565);
void pose_h_4(double *state, double *unused, double *out_955557096790646594);
void pose_H_4(double *state, double *unused, double *out_1519596062171169304);
void pose_h_10(double *state, double *unused, double *out_837743937244112795);
void pose_H_10(double *state, double *unused, double *out_4063371073341436919);
void pose_h_13(double *state, double *unused, double *out_4744417553824752666);
void pose_H_13(double *state, double *unused, double *out_4731869887503502105);
void pose_h_14(double *state, double *unused, double *out_3756453749111016413);
void pose_H_14(double *state, double *unused, double *out_5482836918510653833);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}