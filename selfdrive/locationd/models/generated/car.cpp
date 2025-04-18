#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_453295383840605703) {
   out_453295383840605703[0] = delta_x[0] + nom_x[0];
   out_453295383840605703[1] = delta_x[1] + nom_x[1];
   out_453295383840605703[2] = delta_x[2] + nom_x[2];
   out_453295383840605703[3] = delta_x[3] + nom_x[3];
   out_453295383840605703[4] = delta_x[4] + nom_x[4];
   out_453295383840605703[5] = delta_x[5] + nom_x[5];
   out_453295383840605703[6] = delta_x[6] + nom_x[6];
   out_453295383840605703[7] = delta_x[7] + nom_x[7];
   out_453295383840605703[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1911868970296705050) {
   out_1911868970296705050[0] = -nom_x[0] + true_x[0];
   out_1911868970296705050[1] = -nom_x[1] + true_x[1];
   out_1911868970296705050[2] = -nom_x[2] + true_x[2];
   out_1911868970296705050[3] = -nom_x[3] + true_x[3];
   out_1911868970296705050[4] = -nom_x[4] + true_x[4];
   out_1911868970296705050[5] = -nom_x[5] + true_x[5];
   out_1911868970296705050[6] = -nom_x[6] + true_x[6];
   out_1911868970296705050[7] = -nom_x[7] + true_x[7];
   out_1911868970296705050[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2888549260601034860) {
   out_2888549260601034860[0] = 1.0;
   out_2888549260601034860[1] = 0.0;
   out_2888549260601034860[2] = 0.0;
   out_2888549260601034860[3] = 0.0;
   out_2888549260601034860[4] = 0.0;
   out_2888549260601034860[5] = 0.0;
   out_2888549260601034860[6] = 0.0;
   out_2888549260601034860[7] = 0.0;
   out_2888549260601034860[8] = 0.0;
   out_2888549260601034860[9] = 0.0;
   out_2888549260601034860[10] = 1.0;
   out_2888549260601034860[11] = 0.0;
   out_2888549260601034860[12] = 0.0;
   out_2888549260601034860[13] = 0.0;
   out_2888549260601034860[14] = 0.0;
   out_2888549260601034860[15] = 0.0;
   out_2888549260601034860[16] = 0.0;
   out_2888549260601034860[17] = 0.0;
   out_2888549260601034860[18] = 0.0;
   out_2888549260601034860[19] = 0.0;
   out_2888549260601034860[20] = 1.0;
   out_2888549260601034860[21] = 0.0;
   out_2888549260601034860[22] = 0.0;
   out_2888549260601034860[23] = 0.0;
   out_2888549260601034860[24] = 0.0;
   out_2888549260601034860[25] = 0.0;
   out_2888549260601034860[26] = 0.0;
   out_2888549260601034860[27] = 0.0;
   out_2888549260601034860[28] = 0.0;
   out_2888549260601034860[29] = 0.0;
   out_2888549260601034860[30] = 1.0;
   out_2888549260601034860[31] = 0.0;
   out_2888549260601034860[32] = 0.0;
   out_2888549260601034860[33] = 0.0;
   out_2888549260601034860[34] = 0.0;
   out_2888549260601034860[35] = 0.0;
   out_2888549260601034860[36] = 0.0;
   out_2888549260601034860[37] = 0.0;
   out_2888549260601034860[38] = 0.0;
   out_2888549260601034860[39] = 0.0;
   out_2888549260601034860[40] = 1.0;
   out_2888549260601034860[41] = 0.0;
   out_2888549260601034860[42] = 0.0;
   out_2888549260601034860[43] = 0.0;
   out_2888549260601034860[44] = 0.0;
   out_2888549260601034860[45] = 0.0;
   out_2888549260601034860[46] = 0.0;
   out_2888549260601034860[47] = 0.0;
   out_2888549260601034860[48] = 0.0;
   out_2888549260601034860[49] = 0.0;
   out_2888549260601034860[50] = 1.0;
   out_2888549260601034860[51] = 0.0;
   out_2888549260601034860[52] = 0.0;
   out_2888549260601034860[53] = 0.0;
   out_2888549260601034860[54] = 0.0;
   out_2888549260601034860[55] = 0.0;
   out_2888549260601034860[56] = 0.0;
   out_2888549260601034860[57] = 0.0;
   out_2888549260601034860[58] = 0.0;
   out_2888549260601034860[59] = 0.0;
   out_2888549260601034860[60] = 1.0;
   out_2888549260601034860[61] = 0.0;
   out_2888549260601034860[62] = 0.0;
   out_2888549260601034860[63] = 0.0;
   out_2888549260601034860[64] = 0.0;
   out_2888549260601034860[65] = 0.0;
   out_2888549260601034860[66] = 0.0;
   out_2888549260601034860[67] = 0.0;
   out_2888549260601034860[68] = 0.0;
   out_2888549260601034860[69] = 0.0;
   out_2888549260601034860[70] = 1.0;
   out_2888549260601034860[71] = 0.0;
   out_2888549260601034860[72] = 0.0;
   out_2888549260601034860[73] = 0.0;
   out_2888549260601034860[74] = 0.0;
   out_2888549260601034860[75] = 0.0;
   out_2888549260601034860[76] = 0.0;
   out_2888549260601034860[77] = 0.0;
   out_2888549260601034860[78] = 0.0;
   out_2888549260601034860[79] = 0.0;
   out_2888549260601034860[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1255103046962299015) {
   out_1255103046962299015[0] = state[0];
   out_1255103046962299015[1] = state[1];
   out_1255103046962299015[2] = state[2];
   out_1255103046962299015[3] = state[3];
   out_1255103046962299015[4] = state[4];
   out_1255103046962299015[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1255103046962299015[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1255103046962299015[7] = state[7];
   out_1255103046962299015[8] = state[8];
}
void F_fun(double *state, double dt, double *out_945383962991830613) {
   out_945383962991830613[0] = 1;
   out_945383962991830613[1] = 0;
   out_945383962991830613[2] = 0;
   out_945383962991830613[3] = 0;
   out_945383962991830613[4] = 0;
   out_945383962991830613[5] = 0;
   out_945383962991830613[6] = 0;
   out_945383962991830613[7] = 0;
   out_945383962991830613[8] = 0;
   out_945383962991830613[9] = 0;
   out_945383962991830613[10] = 1;
   out_945383962991830613[11] = 0;
   out_945383962991830613[12] = 0;
   out_945383962991830613[13] = 0;
   out_945383962991830613[14] = 0;
   out_945383962991830613[15] = 0;
   out_945383962991830613[16] = 0;
   out_945383962991830613[17] = 0;
   out_945383962991830613[18] = 0;
   out_945383962991830613[19] = 0;
   out_945383962991830613[20] = 1;
   out_945383962991830613[21] = 0;
   out_945383962991830613[22] = 0;
   out_945383962991830613[23] = 0;
   out_945383962991830613[24] = 0;
   out_945383962991830613[25] = 0;
   out_945383962991830613[26] = 0;
   out_945383962991830613[27] = 0;
   out_945383962991830613[28] = 0;
   out_945383962991830613[29] = 0;
   out_945383962991830613[30] = 1;
   out_945383962991830613[31] = 0;
   out_945383962991830613[32] = 0;
   out_945383962991830613[33] = 0;
   out_945383962991830613[34] = 0;
   out_945383962991830613[35] = 0;
   out_945383962991830613[36] = 0;
   out_945383962991830613[37] = 0;
   out_945383962991830613[38] = 0;
   out_945383962991830613[39] = 0;
   out_945383962991830613[40] = 1;
   out_945383962991830613[41] = 0;
   out_945383962991830613[42] = 0;
   out_945383962991830613[43] = 0;
   out_945383962991830613[44] = 0;
   out_945383962991830613[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_945383962991830613[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_945383962991830613[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_945383962991830613[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_945383962991830613[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_945383962991830613[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_945383962991830613[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_945383962991830613[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_945383962991830613[53] = -9.8000000000000007*dt;
   out_945383962991830613[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_945383962991830613[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_945383962991830613[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_945383962991830613[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_945383962991830613[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_945383962991830613[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_945383962991830613[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_945383962991830613[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_945383962991830613[62] = 0;
   out_945383962991830613[63] = 0;
   out_945383962991830613[64] = 0;
   out_945383962991830613[65] = 0;
   out_945383962991830613[66] = 0;
   out_945383962991830613[67] = 0;
   out_945383962991830613[68] = 0;
   out_945383962991830613[69] = 0;
   out_945383962991830613[70] = 1;
   out_945383962991830613[71] = 0;
   out_945383962991830613[72] = 0;
   out_945383962991830613[73] = 0;
   out_945383962991830613[74] = 0;
   out_945383962991830613[75] = 0;
   out_945383962991830613[76] = 0;
   out_945383962991830613[77] = 0;
   out_945383962991830613[78] = 0;
   out_945383962991830613[79] = 0;
   out_945383962991830613[80] = 1;
}
void h_25(double *state, double *unused, double *out_6105482381361404151) {
   out_6105482381361404151[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6304638965311202377) {
   out_6304638965311202377[0] = 0;
   out_6304638965311202377[1] = 0;
   out_6304638965311202377[2] = 0;
   out_6304638965311202377[3] = 0;
   out_6304638965311202377[4] = 0;
   out_6304638965311202377[5] = 0;
   out_6304638965311202377[6] = 1;
   out_6304638965311202377[7] = 0;
   out_6304638965311202377[8] = 0;
}
void h_24(double *state, double *unused, double *out_2342535520600732832) {
   out_2342535520600732832[0] = state[4];
   out_2342535520600732832[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8477288564316701943) {
   out_8477288564316701943[0] = 0;
   out_8477288564316701943[1] = 0;
   out_8477288564316701943[2] = 0;
   out_8477288564316701943[3] = 0;
   out_8477288564316701943[4] = 1;
   out_8477288564316701943[5] = 0;
   out_8477288564316701943[6] = 0;
   out_8477288564316701943[7] = 0;
   out_8477288564316701943[8] = 0;
   out_8477288564316701943[9] = 0;
   out_8477288564316701943[10] = 0;
   out_8477288564316701943[11] = 0;
   out_8477288564316701943[12] = 0;
   out_8477288564316701943[13] = 0;
   out_8477288564316701943[14] = 1;
   out_8477288564316701943[15] = 0;
   out_8477288564316701943[16] = 0;
   out_8477288564316701943[17] = 0;
}
void h_30(double *state, double *unused, double *out_2416846872812756224) {
   out_2416846872812756224[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3786306006803953750) {
   out_3786306006803953750[0] = 0;
   out_3786306006803953750[1] = 0;
   out_3786306006803953750[2] = 0;
   out_3786306006803953750[3] = 0;
   out_3786306006803953750[4] = 1;
   out_3786306006803953750[5] = 0;
   out_3786306006803953750[6] = 0;
   out_3786306006803953750[7] = 0;
   out_3786306006803953750[8] = 0;
}
void h_26(double *state, double *unused, double *out_3360356725714418659) {
   out_3360356725714418659[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8400601789524293015) {
   out_8400601789524293015[0] = 0;
   out_8400601789524293015[1] = 0;
   out_8400601789524293015[2] = 0;
   out_8400601789524293015[3] = 0;
   out_8400601789524293015[4] = 0;
   out_8400601789524293015[5] = 0;
   out_8400601789524293015[6] = 0;
   out_8400601789524293015[7] = 1;
   out_8400601789524293015[8] = 0;
}
void h_27(double *state, double *unused, double *out_462752510280447316) {
   out_462752510280447316[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8608741224254867358) {
   out_8608741224254867358[0] = 0;
   out_8608741224254867358[1] = 0;
   out_8608741224254867358[2] = 0;
   out_8608741224254867358[3] = 1;
   out_8608741224254867358[4] = 0;
   out_8608741224254867358[5] = 0;
   out_8608741224254867358[6] = 0;
   out_8608741224254867358[7] = 0;
   out_8608741224254867358[8] = 0;
}
void h_29(double *state, double *unused, double *out_7418520140473601869) {
   out_7418520140473601869[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8124640122585133225) {
   out_8124640122585133225[0] = 0;
   out_8124640122585133225[1] = 1;
   out_8124640122585133225[2] = 0;
   out_8124640122585133225[3] = 0;
   out_8124640122585133225[4] = 0;
   out_8124640122585133225[5] = 0;
   out_8124640122585133225[6] = 0;
   out_8124640122585133225[7] = 0;
   out_8124640122585133225[8] = 0;
}
void h_28(double *state, double *unused, double *out_4763154705554877631) {
   out_4763154705554877631[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8358473679559092140) {
   out_8358473679559092140[0] = 1;
   out_8358473679559092140[1] = 0;
   out_8358473679559092140[2] = 0;
   out_8358473679559092140[3] = 0;
   out_8358473679559092140[4] = 0;
   out_8358473679559092140[5] = 0;
   out_8358473679559092140[6] = 0;
   out_8358473679559092140[7] = 0;
   out_8358473679559092140[8] = 0;
}
void h_31(double *state, double *unused, double *out_9101875306195315311) {
   out_9101875306195315311[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6273993003434241949) {
   out_6273993003434241949[0] = 0;
   out_6273993003434241949[1] = 0;
   out_6273993003434241949[2] = 0;
   out_6273993003434241949[3] = 0;
   out_6273993003434241949[4] = 0;
   out_6273993003434241949[5] = 0;
   out_6273993003434241949[6] = 0;
   out_6273993003434241949[7] = 0;
   out_6273993003434241949[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_453295383840605703) {
  err_fun(nom_x, delta_x, out_453295383840605703);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1911868970296705050) {
  inv_err_fun(nom_x, true_x, out_1911868970296705050);
}
void car_H_mod_fun(double *state, double *out_2888549260601034860) {
  H_mod_fun(state, out_2888549260601034860);
}
void car_f_fun(double *state, double dt, double *out_1255103046962299015) {
  f_fun(state,  dt, out_1255103046962299015);
}
void car_F_fun(double *state, double dt, double *out_945383962991830613) {
  F_fun(state,  dt, out_945383962991830613);
}
void car_h_25(double *state, double *unused, double *out_6105482381361404151) {
  h_25(state, unused, out_6105482381361404151);
}
void car_H_25(double *state, double *unused, double *out_6304638965311202377) {
  H_25(state, unused, out_6304638965311202377);
}
void car_h_24(double *state, double *unused, double *out_2342535520600732832) {
  h_24(state, unused, out_2342535520600732832);
}
void car_H_24(double *state, double *unused, double *out_8477288564316701943) {
  H_24(state, unused, out_8477288564316701943);
}
void car_h_30(double *state, double *unused, double *out_2416846872812756224) {
  h_30(state, unused, out_2416846872812756224);
}
void car_H_30(double *state, double *unused, double *out_3786306006803953750) {
  H_30(state, unused, out_3786306006803953750);
}
void car_h_26(double *state, double *unused, double *out_3360356725714418659) {
  h_26(state, unused, out_3360356725714418659);
}
void car_H_26(double *state, double *unused, double *out_8400601789524293015) {
  H_26(state, unused, out_8400601789524293015);
}
void car_h_27(double *state, double *unused, double *out_462752510280447316) {
  h_27(state, unused, out_462752510280447316);
}
void car_H_27(double *state, double *unused, double *out_8608741224254867358) {
  H_27(state, unused, out_8608741224254867358);
}
void car_h_29(double *state, double *unused, double *out_7418520140473601869) {
  h_29(state, unused, out_7418520140473601869);
}
void car_H_29(double *state, double *unused, double *out_8124640122585133225) {
  H_29(state, unused, out_8124640122585133225);
}
void car_h_28(double *state, double *unused, double *out_4763154705554877631) {
  h_28(state, unused, out_4763154705554877631);
}
void car_H_28(double *state, double *unused, double *out_8358473679559092140) {
  H_28(state, unused, out_8358473679559092140);
}
void car_h_31(double *state, double *unused, double *out_9101875306195315311) {
  h_31(state, unused, out_9101875306195315311);
}
void car_H_31(double *state, double *unused, double *out_6273993003434241949) {
  H_31(state, unused, out_6273993003434241949);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
