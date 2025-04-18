#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1444822050377652636) {
   out_1444822050377652636[0] = delta_x[0] + nom_x[0];
   out_1444822050377652636[1] = delta_x[1] + nom_x[1];
   out_1444822050377652636[2] = delta_x[2] + nom_x[2];
   out_1444822050377652636[3] = delta_x[3] + nom_x[3];
   out_1444822050377652636[4] = delta_x[4] + nom_x[4];
   out_1444822050377652636[5] = delta_x[5] + nom_x[5];
   out_1444822050377652636[6] = delta_x[6] + nom_x[6];
   out_1444822050377652636[7] = delta_x[7] + nom_x[7];
   out_1444822050377652636[8] = delta_x[8] + nom_x[8];
   out_1444822050377652636[9] = delta_x[9] + nom_x[9];
   out_1444822050377652636[10] = delta_x[10] + nom_x[10];
   out_1444822050377652636[11] = delta_x[11] + nom_x[11];
   out_1444822050377652636[12] = delta_x[12] + nom_x[12];
   out_1444822050377652636[13] = delta_x[13] + nom_x[13];
   out_1444822050377652636[14] = delta_x[14] + nom_x[14];
   out_1444822050377652636[15] = delta_x[15] + nom_x[15];
   out_1444822050377652636[16] = delta_x[16] + nom_x[16];
   out_1444822050377652636[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2786220128142028057) {
   out_2786220128142028057[0] = -nom_x[0] + true_x[0];
   out_2786220128142028057[1] = -nom_x[1] + true_x[1];
   out_2786220128142028057[2] = -nom_x[2] + true_x[2];
   out_2786220128142028057[3] = -nom_x[3] + true_x[3];
   out_2786220128142028057[4] = -nom_x[4] + true_x[4];
   out_2786220128142028057[5] = -nom_x[5] + true_x[5];
   out_2786220128142028057[6] = -nom_x[6] + true_x[6];
   out_2786220128142028057[7] = -nom_x[7] + true_x[7];
   out_2786220128142028057[8] = -nom_x[8] + true_x[8];
   out_2786220128142028057[9] = -nom_x[9] + true_x[9];
   out_2786220128142028057[10] = -nom_x[10] + true_x[10];
   out_2786220128142028057[11] = -nom_x[11] + true_x[11];
   out_2786220128142028057[12] = -nom_x[12] + true_x[12];
   out_2786220128142028057[13] = -nom_x[13] + true_x[13];
   out_2786220128142028057[14] = -nom_x[14] + true_x[14];
   out_2786220128142028057[15] = -nom_x[15] + true_x[15];
   out_2786220128142028057[16] = -nom_x[16] + true_x[16];
   out_2786220128142028057[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7982786345480560970) {
   out_7982786345480560970[0] = 1.0;
   out_7982786345480560970[1] = 0.0;
   out_7982786345480560970[2] = 0.0;
   out_7982786345480560970[3] = 0.0;
   out_7982786345480560970[4] = 0.0;
   out_7982786345480560970[5] = 0.0;
   out_7982786345480560970[6] = 0.0;
   out_7982786345480560970[7] = 0.0;
   out_7982786345480560970[8] = 0.0;
   out_7982786345480560970[9] = 0.0;
   out_7982786345480560970[10] = 0.0;
   out_7982786345480560970[11] = 0.0;
   out_7982786345480560970[12] = 0.0;
   out_7982786345480560970[13] = 0.0;
   out_7982786345480560970[14] = 0.0;
   out_7982786345480560970[15] = 0.0;
   out_7982786345480560970[16] = 0.0;
   out_7982786345480560970[17] = 0.0;
   out_7982786345480560970[18] = 0.0;
   out_7982786345480560970[19] = 1.0;
   out_7982786345480560970[20] = 0.0;
   out_7982786345480560970[21] = 0.0;
   out_7982786345480560970[22] = 0.0;
   out_7982786345480560970[23] = 0.0;
   out_7982786345480560970[24] = 0.0;
   out_7982786345480560970[25] = 0.0;
   out_7982786345480560970[26] = 0.0;
   out_7982786345480560970[27] = 0.0;
   out_7982786345480560970[28] = 0.0;
   out_7982786345480560970[29] = 0.0;
   out_7982786345480560970[30] = 0.0;
   out_7982786345480560970[31] = 0.0;
   out_7982786345480560970[32] = 0.0;
   out_7982786345480560970[33] = 0.0;
   out_7982786345480560970[34] = 0.0;
   out_7982786345480560970[35] = 0.0;
   out_7982786345480560970[36] = 0.0;
   out_7982786345480560970[37] = 0.0;
   out_7982786345480560970[38] = 1.0;
   out_7982786345480560970[39] = 0.0;
   out_7982786345480560970[40] = 0.0;
   out_7982786345480560970[41] = 0.0;
   out_7982786345480560970[42] = 0.0;
   out_7982786345480560970[43] = 0.0;
   out_7982786345480560970[44] = 0.0;
   out_7982786345480560970[45] = 0.0;
   out_7982786345480560970[46] = 0.0;
   out_7982786345480560970[47] = 0.0;
   out_7982786345480560970[48] = 0.0;
   out_7982786345480560970[49] = 0.0;
   out_7982786345480560970[50] = 0.0;
   out_7982786345480560970[51] = 0.0;
   out_7982786345480560970[52] = 0.0;
   out_7982786345480560970[53] = 0.0;
   out_7982786345480560970[54] = 0.0;
   out_7982786345480560970[55] = 0.0;
   out_7982786345480560970[56] = 0.0;
   out_7982786345480560970[57] = 1.0;
   out_7982786345480560970[58] = 0.0;
   out_7982786345480560970[59] = 0.0;
   out_7982786345480560970[60] = 0.0;
   out_7982786345480560970[61] = 0.0;
   out_7982786345480560970[62] = 0.0;
   out_7982786345480560970[63] = 0.0;
   out_7982786345480560970[64] = 0.0;
   out_7982786345480560970[65] = 0.0;
   out_7982786345480560970[66] = 0.0;
   out_7982786345480560970[67] = 0.0;
   out_7982786345480560970[68] = 0.0;
   out_7982786345480560970[69] = 0.0;
   out_7982786345480560970[70] = 0.0;
   out_7982786345480560970[71] = 0.0;
   out_7982786345480560970[72] = 0.0;
   out_7982786345480560970[73] = 0.0;
   out_7982786345480560970[74] = 0.0;
   out_7982786345480560970[75] = 0.0;
   out_7982786345480560970[76] = 1.0;
   out_7982786345480560970[77] = 0.0;
   out_7982786345480560970[78] = 0.0;
   out_7982786345480560970[79] = 0.0;
   out_7982786345480560970[80] = 0.0;
   out_7982786345480560970[81] = 0.0;
   out_7982786345480560970[82] = 0.0;
   out_7982786345480560970[83] = 0.0;
   out_7982786345480560970[84] = 0.0;
   out_7982786345480560970[85] = 0.0;
   out_7982786345480560970[86] = 0.0;
   out_7982786345480560970[87] = 0.0;
   out_7982786345480560970[88] = 0.0;
   out_7982786345480560970[89] = 0.0;
   out_7982786345480560970[90] = 0.0;
   out_7982786345480560970[91] = 0.0;
   out_7982786345480560970[92] = 0.0;
   out_7982786345480560970[93] = 0.0;
   out_7982786345480560970[94] = 0.0;
   out_7982786345480560970[95] = 1.0;
   out_7982786345480560970[96] = 0.0;
   out_7982786345480560970[97] = 0.0;
   out_7982786345480560970[98] = 0.0;
   out_7982786345480560970[99] = 0.0;
   out_7982786345480560970[100] = 0.0;
   out_7982786345480560970[101] = 0.0;
   out_7982786345480560970[102] = 0.0;
   out_7982786345480560970[103] = 0.0;
   out_7982786345480560970[104] = 0.0;
   out_7982786345480560970[105] = 0.0;
   out_7982786345480560970[106] = 0.0;
   out_7982786345480560970[107] = 0.0;
   out_7982786345480560970[108] = 0.0;
   out_7982786345480560970[109] = 0.0;
   out_7982786345480560970[110] = 0.0;
   out_7982786345480560970[111] = 0.0;
   out_7982786345480560970[112] = 0.0;
   out_7982786345480560970[113] = 0.0;
   out_7982786345480560970[114] = 1.0;
   out_7982786345480560970[115] = 0.0;
   out_7982786345480560970[116] = 0.0;
   out_7982786345480560970[117] = 0.0;
   out_7982786345480560970[118] = 0.0;
   out_7982786345480560970[119] = 0.0;
   out_7982786345480560970[120] = 0.0;
   out_7982786345480560970[121] = 0.0;
   out_7982786345480560970[122] = 0.0;
   out_7982786345480560970[123] = 0.0;
   out_7982786345480560970[124] = 0.0;
   out_7982786345480560970[125] = 0.0;
   out_7982786345480560970[126] = 0.0;
   out_7982786345480560970[127] = 0.0;
   out_7982786345480560970[128] = 0.0;
   out_7982786345480560970[129] = 0.0;
   out_7982786345480560970[130] = 0.0;
   out_7982786345480560970[131] = 0.0;
   out_7982786345480560970[132] = 0.0;
   out_7982786345480560970[133] = 1.0;
   out_7982786345480560970[134] = 0.0;
   out_7982786345480560970[135] = 0.0;
   out_7982786345480560970[136] = 0.0;
   out_7982786345480560970[137] = 0.0;
   out_7982786345480560970[138] = 0.0;
   out_7982786345480560970[139] = 0.0;
   out_7982786345480560970[140] = 0.0;
   out_7982786345480560970[141] = 0.0;
   out_7982786345480560970[142] = 0.0;
   out_7982786345480560970[143] = 0.0;
   out_7982786345480560970[144] = 0.0;
   out_7982786345480560970[145] = 0.0;
   out_7982786345480560970[146] = 0.0;
   out_7982786345480560970[147] = 0.0;
   out_7982786345480560970[148] = 0.0;
   out_7982786345480560970[149] = 0.0;
   out_7982786345480560970[150] = 0.0;
   out_7982786345480560970[151] = 0.0;
   out_7982786345480560970[152] = 1.0;
   out_7982786345480560970[153] = 0.0;
   out_7982786345480560970[154] = 0.0;
   out_7982786345480560970[155] = 0.0;
   out_7982786345480560970[156] = 0.0;
   out_7982786345480560970[157] = 0.0;
   out_7982786345480560970[158] = 0.0;
   out_7982786345480560970[159] = 0.0;
   out_7982786345480560970[160] = 0.0;
   out_7982786345480560970[161] = 0.0;
   out_7982786345480560970[162] = 0.0;
   out_7982786345480560970[163] = 0.0;
   out_7982786345480560970[164] = 0.0;
   out_7982786345480560970[165] = 0.0;
   out_7982786345480560970[166] = 0.0;
   out_7982786345480560970[167] = 0.0;
   out_7982786345480560970[168] = 0.0;
   out_7982786345480560970[169] = 0.0;
   out_7982786345480560970[170] = 0.0;
   out_7982786345480560970[171] = 1.0;
   out_7982786345480560970[172] = 0.0;
   out_7982786345480560970[173] = 0.0;
   out_7982786345480560970[174] = 0.0;
   out_7982786345480560970[175] = 0.0;
   out_7982786345480560970[176] = 0.0;
   out_7982786345480560970[177] = 0.0;
   out_7982786345480560970[178] = 0.0;
   out_7982786345480560970[179] = 0.0;
   out_7982786345480560970[180] = 0.0;
   out_7982786345480560970[181] = 0.0;
   out_7982786345480560970[182] = 0.0;
   out_7982786345480560970[183] = 0.0;
   out_7982786345480560970[184] = 0.0;
   out_7982786345480560970[185] = 0.0;
   out_7982786345480560970[186] = 0.0;
   out_7982786345480560970[187] = 0.0;
   out_7982786345480560970[188] = 0.0;
   out_7982786345480560970[189] = 0.0;
   out_7982786345480560970[190] = 1.0;
   out_7982786345480560970[191] = 0.0;
   out_7982786345480560970[192] = 0.0;
   out_7982786345480560970[193] = 0.0;
   out_7982786345480560970[194] = 0.0;
   out_7982786345480560970[195] = 0.0;
   out_7982786345480560970[196] = 0.0;
   out_7982786345480560970[197] = 0.0;
   out_7982786345480560970[198] = 0.0;
   out_7982786345480560970[199] = 0.0;
   out_7982786345480560970[200] = 0.0;
   out_7982786345480560970[201] = 0.0;
   out_7982786345480560970[202] = 0.0;
   out_7982786345480560970[203] = 0.0;
   out_7982786345480560970[204] = 0.0;
   out_7982786345480560970[205] = 0.0;
   out_7982786345480560970[206] = 0.0;
   out_7982786345480560970[207] = 0.0;
   out_7982786345480560970[208] = 0.0;
   out_7982786345480560970[209] = 1.0;
   out_7982786345480560970[210] = 0.0;
   out_7982786345480560970[211] = 0.0;
   out_7982786345480560970[212] = 0.0;
   out_7982786345480560970[213] = 0.0;
   out_7982786345480560970[214] = 0.0;
   out_7982786345480560970[215] = 0.0;
   out_7982786345480560970[216] = 0.0;
   out_7982786345480560970[217] = 0.0;
   out_7982786345480560970[218] = 0.0;
   out_7982786345480560970[219] = 0.0;
   out_7982786345480560970[220] = 0.0;
   out_7982786345480560970[221] = 0.0;
   out_7982786345480560970[222] = 0.0;
   out_7982786345480560970[223] = 0.0;
   out_7982786345480560970[224] = 0.0;
   out_7982786345480560970[225] = 0.0;
   out_7982786345480560970[226] = 0.0;
   out_7982786345480560970[227] = 0.0;
   out_7982786345480560970[228] = 1.0;
   out_7982786345480560970[229] = 0.0;
   out_7982786345480560970[230] = 0.0;
   out_7982786345480560970[231] = 0.0;
   out_7982786345480560970[232] = 0.0;
   out_7982786345480560970[233] = 0.0;
   out_7982786345480560970[234] = 0.0;
   out_7982786345480560970[235] = 0.0;
   out_7982786345480560970[236] = 0.0;
   out_7982786345480560970[237] = 0.0;
   out_7982786345480560970[238] = 0.0;
   out_7982786345480560970[239] = 0.0;
   out_7982786345480560970[240] = 0.0;
   out_7982786345480560970[241] = 0.0;
   out_7982786345480560970[242] = 0.0;
   out_7982786345480560970[243] = 0.0;
   out_7982786345480560970[244] = 0.0;
   out_7982786345480560970[245] = 0.0;
   out_7982786345480560970[246] = 0.0;
   out_7982786345480560970[247] = 1.0;
   out_7982786345480560970[248] = 0.0;
   out_7982786345480560970[249] = 0.0;
   out_7982786345480560970[250] = 0.0;
   out_7982786345480560970[251] = 0.0;
   out_7982786345480560970[252] = 0.0;
   out_7982786345480560970[253] = 0.0;
   out_7982786345480560970[254] = 0.0;
   out_7982786345480560970[255] = 0.0;
   out_7982786345480560970[256] = 0.0;
   out_7982786345480560970[257] = 0.0;
   out_7982786345480560970[258] = 0.0;
   out_7982786345480560970[259] = 0.0;
   out_7982786345480560970[260] = 0.0;
   out_7982786345480560970[261] = 0.0;
   out_7982786345480560970[262] = 0.0;
   out_7982786345480560970[263] = 0.0;
   out_7982786345480560970[264] = 0.0;
   out_7982786345480560970[265] = 0.0;
   out_7982786345480560970[266] = 1.0;
   out_7982786345480560970[267] = 0.0;
   out_7982786345480560970[268] = 0.0;
   out_7982786345480560970[269] = 0.0;
   out_7982786345480560970[270] = 0.0;
   out_7982786345480560970[271] = 0.0;
   out_7982786345480560970[272] = 0.0;
   out_7982786345480560970[273] = 0.0;
   out_7982786345480560970[274] = 0.0;
   out_7982786345480560970[275] = 0.0;
   out_7982786345480560970[276] = 0.0;
   out_7982786345480560970[277] = 0.0;
   out_7982786345480560970[278] = 0.0;
   out_7982786345480560970[279] = 0.0;
   out_7982786345480560970[280] = 0.0;
   out_7982786345480560970[281] = 0.0;
   out_7982786345480560970[282] = 0.0;
   out_7982786345480560970[283] = 0.0;
   out_7982786345480560970[284] = 0.0;
   out_7982786345480560970[285] = 1.0;
   out_7982786345480560970[286] = 0.0;
   out_7982786345480560970[287] = 0.0;
   out_7982786345480560970[288] = 0.0;
   out_7982786345480560970[289] = 0.0;
   out_7982786345480560970[290] = 0.0;
   out_7982786345480560970[291] = 0.0;
   out_7982786345480560970[292] = 0.0;
   out_7982786345480560970[293] = 0.0;
   out_7982786345480560970[294] = 0.0;
   out_7982786345480560970[295] = 0.0;
   out_7982786345480560970[296] = 0.0;
   out_7982786345480560970[297] = 0.0;
   out_7982786345480560970[298] = 0.0;
   out_7982786345480560970[299] = 0.0;
   out_7982786345480560970[300] = 0.0;
   out_7982786345480560970[301] = 0.0;
   out_7982786345480560970[302] = 0.0;
   out_7982786345480560970[303] = 0.0;
   out_7982786345480560970[304] = 1.0;
   out_7982786345480560970[305] = 0.0;
   out_7982786345480560970[306] = 0.0;
   out_7982786345480560970[307] = 0.0;
   out_7982786345480560970[308] = 0.0;
   out_7982786345480560970[309] = 0.0;
   out_7982786345480560970[310] = 0.0;
   out_7982786345480560970[311] = 0.0;
   out_7982786345480560970[312] = 0.0;
   out_7982786345480560970[313] = 0.0;
   out_7982786345480560970[314] = 0.0;
   out_7982786345480560970[315] = 0.0;
   out_7982786345480560970[316] = 0.0;
   out_7982786345480560970[317] = 0.0;
   out_7982786345480560970[318] = 0.0;
   out_7982786345480560970[319] = 0.0;
   out_7982786345480560970[320] = 0.0;
   out_7982786345480560970[321] = 0.0;
   out_7982786345480560970[322] = 0.0;
   out_7982786345480560970[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3891050436305113138) {
   out_3891050436305113138[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3891050436305113138[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3891050436305113138[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3891050436305113138[3] = dt*state[12] + state[3];
   out_3891050436305113138[4] = dt*state[13] + state[4];
   out_3891050436305113138[5] = dt*state[14] + state[5];
   out_3891050436305113138[6] = state[6];
   out_3891050436305113138[7] = state[7];
   out_3891050436305113138[8] = state[8];
   out_3891050436305113138[9] = state[9];
   out_3891050436305113138[10] = state[10];
   out_3891050436305113138[11] = state[11];
   out_3891050436305113138[12] = state[12];
   out_3891050436305113138[13] = state[13];
   out_3891050436305113138[14] = state[14];
   out_3891050436305113138[15] = state[15];
   out_3891050436305113138[16] = state[16];
   out_3891050436305113138[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5269798254466500565) {
   out_5269798254466500565[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5269798254466500565[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5269798254466500565[2] = 0;
   out_5269798254466500565[3] = 0;
   out_5269798254466500565[4] = 0;
   out_5269798254466500565[5] = 0;
   out_5269798254466500565[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5269798254466500565[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5269798254466500565[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5269798254466500565[9] = 0;
   out_5269798254466500565[10] = 0;
   out_5269798254466500565[11] = 0;
   out_5269798254466500565[12] = 0;
   out_5269798254466500565[13] = 0;
   out_5269798254466500565[14] = 0;
   out_5269798254466500565[15] = 0;
   out_5269798254466500565[16] = 0;
   out_5269798254466500565[17] = 0;
   out_5269798254466500565[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5269798254466500565[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5269798254466500565[20] = 0;
   out_5269798254466500565[21] = 0;
   out_5269798254466500565[22] = 0;
   out_5269798254466500565[23] = 0;
   out_5269798254466500565[24] = 0;
   out_5269798254466500565[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5269798254466500565[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5269798254466500565[27] = 0;
   out_5269798254466500565[28] = 0;
   out_5269798254466500565[29] = 0;
   out_5269798254466500565[30] = 0;
   out_5269798254466500565[31] = 0;
   out_5269798254466500565[32] = 0;
   out_5269798254466500565[33] = 0;
   out_5269798254466500565[34] = 0;
   out_5269798254466500565[35] = 0;
   out_5269798254466500565[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5269798254466500565[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5269798254466500565[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5269798254466500565[39] = 0;
   out_5269798254466500565[40] = 0;
   out_5269798254466500565[41] = 0;
   out_5269798254466500565[42] = 0;
   out_5269798254466500565[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5269798254466500565[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5269798254466500565[45] = 0;
   out_5269798254466500565[46] = 0;
   out_5269798254466500565[47] = 0;
   out_5269798254466500565[48] = 0;
   out_5269798254466500565[49] = 0;
   out_5269798254466500565[50] = 0;
   out_5269798254466500565[51] = 0;
   out_5269798254466500565[52] = 0;
   out_5269798254466500565[53] = 0;
   out_5269798254466500565[54] = 0;
   out_5269798254466500565[55] = 0;
   out_5269798254466500565[56] = 0;
   out_5269798254466500565[57] = 1;
   out_5269798254466500565[58] = 0;
   out_5269798254466500565[59] = 0;
   out_5269798254466500565[60] = 0;
   out_5269798254466500565[61] = 0;
   out_5269798254466500565[62] = 0;
   out_5269798254466500565[63] = 0;
   out_5269798254466500565[64] = 0;
   out_5269798254466500565[65] = 0;
   out_5269798254466500565[66] = dt;
   out_5269798254466500565[67] = 0;
   out_5269798254466500565[68] = 0;
   out_5269798254466500565[69] = 0;
   out_5269798254466500565[70] = 0;
   out_5269798254466500565[71] = 0;
   out_5269798254466500565[72] = 0;
   out_5269798254466500565[73] = 0;
   out_5269798254466500565[74] = 0;
   out_5269798254466500565[75] = 0;
   out_5269798254466500565[76] = 1;
   out_5269798254466500565[77] = 0;
   out_5269798254466500565[78] = 0;
   out_5269798254466500565[79] = 0;
   out_5269798254466500565[80] = 0;
   out_5269798254466500565[81] = 0;
   out_5269798254466500565[82] = 0;
   out_5269798254466500565[83] = 0;
   out_5269798254466500565[84] = 0;
   out_5269798254466500565[85] = dt;
   out_5269798254466500565[86] = 0;
   out_5269798254466500565[87] = 0;
   out_5269798254466500565[88] = 0;
   out_5269798254466500565[89] = 0;
   out_5269798254466500565[90] = 0;
   out_5269798254466500565[91] = 0;
   out_5269798254466500565[92] = 0;
   out_5269798254466500565[93] = 0;
   out_5269798254466500565[94] = 0;
   out_5269798254466500565[95] = 1;
   out_5269798254466500565[96] = 0;
   out_5269798254466500565[97] = 0;
   out_5269798254466500565[98] = 0;
   out_5269798254466500565[99] = 0;
   out_5269798254466500565[100] = 0;
   out_5269798254466500565[101] = 0;
   out_5269798254466500565[102] = 0;
   out_5269798254466500565[103] = 0;
   out_5269798254466500565[104] = dt;
   out_5269798254466500565[105] = 0;
   out_5269798254466500565[106] = 0;
   out_5269798254466500565[107] = 0;
   out_5269798254466500565[108] = 0;
   out_5269798254466500565[109] = 0;
   out_5269798254466500565[110] = 0;
   out_5269798254466500565[111] = 0;
   out_5269798254466500565[112] = 0;
   out_5269798254466500565[113] = 0;
   out_5269798254466500565[114] = 1;
   out_5269798254466500565[115] = 0;
   out_5269798254466500565[116] = 0;
   out_5269798254466500565[117] = 0;
   out_5269798254466500565[118] = 0;
   out_5269798254466500565[119] = 0;
   out_5269798254466500565[120] = 0;
   out_5269798254466500565[121] = 0;
   out_5269798254466500565[122] = 0;
   out_5269798254466500565[123] = 0;
   out_5269798254466500565[124] = 0;
   out_5269798254466500565[125] = 0;
   out_5269798254466500565[126] = 0;
   out_5269798254466500565[127] = 0;
   out_5269798254466500565[128] = 0;
   out_5269798254466500565[129] = 0;
   out_5269798254466500565[130] = 0;
   out_5269798254466500565[131] = 0;
   out_5269798254466500565[132] = 0;
   out_5269798254466500565[133] = 1;
   out_5269798254466500565[134] = 0;
   out_5269798254466500565[135] = 0;
   out_5269798254466500565[136] = 0;
   out_5269798254466500565[137] = 0;
   out_5269798254466500565[138] = 0;
   out_5269798254466500565[139] = 0;
   out_5269798254466500565[140] = 0;
   out_5269798254466500565[141] = 0;
   out_5269798254466500565[142] = 0;
   out_5269798254466500565[143] = 0;
   out_5269798254466500565[144] = 0;
   out_5269798254466500565[145] = 0;
   out_5269798254466500565[146] = 0;
   out_5269798254466500565[147] = 0;
   out_5269798254466500565[148] = 0;
   out_5269798254466500565[149] = 0;
   out_5269798254466500565[150] = 0;
   out_5269798254466500565[151] = 0;
   out_5269798254466500565[152] = 1;
   out_5269798254466500565[153] = 0;
   out_5269798254466500565[154] = 0;
   out_5269798254466500565[155] = 0;
   out_5269798254466500565[156] = 0;
   out_5269798254466500565[157] = 0;
   out_5269798254466500565[158] = 0;
   out_5269798254466500565[159] = 0;
   out_5269798254466500565[160] = 0;
   out_5269798254466500565[161] = 0;
   out_5269798254466500565[162] = 0;
   out_5269798254466500565[163] = 0;
   out_5269798254466500565[164] = 0;
   out_5269798254466500565[165] = 0;
   out_5269798254466500565[166] = 0;
   out_5269798254466500565[167] = 0;
   out_5269798254466500565[168] = 0;
   out_5269798254466500565[169] = 0;
   out_5269798254466500565[170] = 0;
   out_5269798254466500565[171] = 1;
   out_5269798254466500565[172] = 0;
   out_5269798254466500565[173] = 0;
   out_5269798254466500565[174] = 0;
   out_5269798254466500565[175] = 0;
   out_5269798254466500565[176] = 0;
   out_5269798254466500565[177] = 0;
   out_5269798254466500565[178] = 0;
   out_5269798254466500565[179] = 0;
   out_5269798254466500565[180] = 0;
   out_5269798254466500565[181] = 0;
   out_5269798254466500565[182] = 0;
   out_5269798254466500565[183] = 0;
   out_5269798254466500565[184] = 0;
   out_5269798254466500565[185] = 0;
   out_5269798254466500565[186] = 0;
   out_5269798254466500565[187] = 0;
   out_5269798254466500565[188] = 0;
   out_5269798254466500565[189] = 0;
   out_5269798254466500565[190] = 1;
   out_5269798254466500565[191] = 0;
   out_5269798254466500565[192] = 0;
   out_5269798254466500565[193] = 0;
   out_5269798254466500565[194] = 0;
   out_5269798254466500565[195] = 0;
   out_5269798254466500565[196] = 0;
   out_5269798254466500565[197] = 0;
   out_5269798254466500565[198] = 0;
   out_5269798254466500565[199] = 0;
   out_5269798254466500565[200] = 0;
   out_5269798254466500565[201] = 0;
   out_5269798254466500565[202] = 0;
   out_5269798254466500565[203] = 0;
   out_5269798254466500565[204] = 0;
   out_5269798254466500565[205] = 0;
   out_5269798254466500565[206] = 0;
   out_5269798254466500565[207] = 0;
   out_5269798254466500565[208] = 0;
   out_5269798254466500565[209] = 1;
   out_5269798254466500565[210] = 0;
   out_5269798254466500565[211] = 0;
   out_5269798254466500565[212] = 0;
   out_5269798254466500565[213] = 0;
   out_5269798254466500565[214] = 0;
   out_5269798254466500565[215] = 0;
   out_5269798254466500565[216] = 0;
   out_5269798254466500565[217] = 0;
   out_5269798254466500565[218] = 0;
   out_5269798254466500565[219] = 0;
   out_5269798254466500565[220] = 0;
   out_5269798254466500565[221] = 0;
   out_5269798254466500565[222] = 0;
   out_5269798254466500565[223] = 0;
   out_5269798254466500565[224] = 0;
   out_5269798254466500565[225] = 0;
   out_5269798254466500565[226] = 0;
   out_5269798254466500565[227] = 0;
   out_5269798254466500565[228] = 1;
   out_5269798254466500565[229] = 0;
   out_5269798254466500565[230] = 0;
   out_5269798254466500565[231] = 0;
   out_5269798254466500565[232] = 0;
   out_5269798254466500565[233] = 0;
   out_5269798254466500565[234] = 0;
   out_5269798254466500565[235] = 0;
   out_5269798254466500565[236] = 0;
   out_5269798254466500565[237] = 0;
   out_5269798254466500565[238] = 0;
   out_5269798254466500565[239] = 0;
   out_5269798254466500565[240] = 0;
   out_5269798254466500565[241] = 0;
   out_5269798254466500565[242] = 0;
   out_5269798254466500565[243] = 0;
   out_5269798254466500565[244] = 0;
   out_5269798254466500565[245] = 0;
   out_5269798254466500565[246] = 0;
   out_5269798254466500565[247] = 1;
   out_5269798254466500565[248] = 0;
   out_5269798254466500565[249] = 0;
   out_5269798254466500565[250] = 0;
   out_5269798254466500565[251] = 0;
   out_5269798254466500565[252] = 0;
   out_5269798254466500565[253] = 0;
   out_5269798254466500565[254] = 0;
   out_5269798254466500565[255] = 0;
   out_5269798254466500565[256] = 0;
   out_5269798254466500565[257] = 0;
   out_5269798254466500565[258] = 0;
   out_5269798254466500565[259] = 0;
   out_5269798254466500565[260] = 0;
   out_5269798254466500565[261] = 0;
   out_5269798254466500565[262] = 0;
   out_5269798254466500565[263] = 0;
   out_5269798254466500565[264] = 0;
   out_5269798254466500565[265] = 0;
   out_5269798254466500565[266] = 1;
   out_5269798254466500565[267] = 0;
   out_5269798254466500565[268] = 0;
   out_5269798254466500565[269] = 0;
   out_5269798254466500565[270] = 0;
   out_5269798254466500565[271] = 0;
   out_5269798254466500565[272] = 0;
   out_5269798254466500565[273] = 0;
   out_5269798254466500565[274] = 0;
   out_5269798254466500565[275] = 0;
   out_5269798254466500565[276] = 0;
   out_5269798254466500565[277] = 0;
   out_5269798254466500565[278] = 0;
   out_5269798254466500565[279] = 0;
   out_5269798254466500565[280] = 0;
   out_5269798254466500565[281] = 0;
   out_5269798254466500565[282] = 0;
   out_5269798254466500565[283] = 0;
   out_5269798254466500565[284] = 0;
   out_5269798254466500565[285] = 1;
   out_5269798254466500565[286] = 0;
   out_5269798254466500565[287] = 0;
   out_5269798254466500565[288] = 0;
   out_5269798254466500565[289] = 0;
   out_5269798254466500565[290] = 0;
   out_5269798254466500565[291] = 0;
   out_5269798254466500565[292] = 0;
   out_5269798254466500565[293] = 0;
   out_5269798254466500565[294] = 0;
   out_5269798254466500565[295] = 0;
   out_5269798254466500565[296] = 0;
   out_5269798254466500565[297] = 0;
   out_5269798254466500565[298] = 0;
   out_5269798254466500565[299] = 0;
   out_5269798254466500565[300] = 0;
   out_5269798254466500565[301] = 0;
   out_5269798254466500565[302] = 0;
   out_5269798254466500565[303] = 0;
   out_5269798254466500565[304] = 1;
   out_5269798254466500565[305] = 0;
   out_5269798254466500565[306] = 0;
   out_5269798254466500565[307] = 0;
   out_5269798254466500565[308] = 0;
   out_5269798254466500565[309] = 0;
   out_5269798254466500565[310] = 0;
   out_5269798254466500565[311] = 0;
   out_5269798254466500565[312] = 0;
   out_5269798254466500565[313] = 0;
   out_5269798254466500565[314] = 0;
   out_5269798254466500565[315] = 0;
   out_5269798254466500565[316] = 0;
   out_5269798254466500565[317] = 0;
   out_5269798254466500565[318] = 0;
   out_5269798254466500565[319] = 0;
   out_5269798254466500565[320] = 0;
   out_5269798254466500565[321] = 0;
   out_5269798254466500565[322] = 0;
   out_5269798254466500565[323] = 1;
}
void h_4(double *state, double *unused, double *out_955557096790646594) {
   out_955557096790646594[0] = state[6] + state[9];
   out_955557096790646594[1] = state[7] + state[10];
   out_955557096790646594[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1519596062171169304) {
   out_1519596062171169304[0] = 0;
   out_1519596062171169304[1] = 0;
   out_1519596062171169304[2] = 0;
   out_1519596062171169304[3] = 0;
   out_1519596062171169304[4] = 0;
   out_1519596062171169304[5] = 0;
   out_1519596062171169304[6] = 1;
   out_1519596062171169304[7] = 0;
   out_1519596062171169304[8] = 0;
   out_1519596062171169304[9] = 1;
   out_1519596062171169304[10] = 0;
   out_1519596062171169304[11] = 0;
   out_1519596062171169304[12] = 0;
   out_1519596062171169304[13] = 0;
   out_1519596062171169304[14] = 0;
   out_1519596062171169304[15] = 0;
   out_1519596062171169304[16] = 0;
   out_1519596062171169304[17] = 0;
   out_1519596062171169304[18] = 0;
   out_1519596062171169304[19] = 0;
   out_1519596062171169304[20] = 0;
   out_1519596062171169304[21] = 0;
   out_1519596062171169304[22] = 0;
   out_1519596062171169304[23] = 0;
   out_1519596062171169304[24] = 0;
   out_1519596062171169304[25] = 1;
   out_1519596062171169304[26] = 0;
   out_1519596062171169304[27] = 0;
   out_1519596062171169304[28] = 1;
   out_1519596062171169304[29] = 0;
   out_1519596062171169304[30] = 0;
   out_1519596062171169304[31] = 0;
   out_1519596062171169304[32] = 0;
   out_1519596062171169304[33] = 0;
   out_1519596062171169304[34] = 0;
   out_1519596062171169304[35] = 0;
   out_1519596062171169304[36] = 0;
   out_1519596062171169304[37] = 0;
   out_1519596062171169304[38] = 0;
   out_1519596062171169304[39] = 0;
   out_1519596062171169304[40] = 0;
   out_1519596062171169304[41] = 0;
   out_1519596062171169304[42] = 0;
   out_1519596062171169304[43] = 0;
   out_1519596062171169304[44] = 1;
   out_1519596062171169304[45] = 0;
   out_1519596062171169304[46] = 0;
   out_1519596062171169304[47] = 1;
   out_1519596062171169304[48] = 0;
   out_1519596062171169304[49] = 0;
   out_1519596062171169304[50] = 0;
   out_1519596062171169304[51] = 0;
   out_1519596062171169304[52] = 0;
   out_1519596062171169304[53] = 0;
}
void h_10(double *state, double *unused, double *out_837743937244112795) {
   out_837743937244112795[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_837743937244112795[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_837743937244112795[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4063371073341436919) {
   out_4063371073341436919[0] = 0;
   out_4063371073341436919[1] = 9.8100000000000005*cos(state[1]);
   out_4063371073341436919[2] = 0;
   out_4063371073341436919[3] = 0;
   out_4063371073341436919[4] = -state[8];
   out_4063371073341436919[5] = state[7];
   out_4063371073341436919[6] = 0;
   out_4063371073341436919[7] = state[5];
   out_4063371073341436919[8] = -state[4];
   out_4063371073341436919[9] = 0;
   out_4063371073341436919[10] = 0;
   out_4063371073341436919[11] = 0;
   out_4063371073341436919[12] = 1;
   out_4063371073341436919[13] = 0;
   out_4063371073341436919[14] = 0;
   out_4063371073341436919[15] = 1;
   out_4063371073341436919[16] = 0;
   out_4063371073341436919[17] = 0;
   out_4063371073341436919[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4063371073341436919[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4063371073341436919[20] = 0;
   out_4063371073341436919[21] = state[8];
   out_4063371073341436919[22] = 0;
   out_4063371073341436919[23] = -state[6];
   out_4063371073341436919[24] = -state[5];
   out_4063371073341436919[25] = 0;
   out_4063371073341436919[26] = state[3];
   out_4063371073341436919[27] = 0;
   out_4063371073341436919[28] = 0;
   out_4063371073341436919[29] = 0;
   out_4063371073341436919[30] = 0;
   out_4063371073341436919[31] = 1;
   out_4063371073341436919[32] = 0;
   out_4063371073341436919[33] = 0;
   out_4063371073341436919[34] = 1;
   out_4063371073341436919[35] = 0;
   out_4063371073341436919[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4063371073341436919[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4063371073341436919[38] = 0;
   out_4063371073341436919[39] = -state[7];
   out_4063371073341436919[40] = state[6];
   out_4063371073341436919[41] = 0;
   out_4063371073341436919[42] = state[4];
   out_4063371073341436919[43] = -state[3];
   out_4063371073341436919[44] = 0;
   out_4063371073341436919[45] = 0;
   out_4063371073341436919[46] = 0;
   out_4063371073341436919[47] = 0;
   out_4063371073341436919[48] = 0;
   out_4063371073341436919[49] = 0;
   out_4063371073341436919[50] = 1;
   out_4063371073341436919[51] = 0;
   out_4063371073341436919[52] = 0;
   out_4063371073341436919[53] = 1;
}
void h_13(double *state, double *unused, double *out_4744417553824752666) {
   out_4744417553824752666[0] = state[3];
   out_4744417553824752666[1] = state[4];
   out_4744417553824752666[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4731869887503502105) {
   out_4731869887503502105[0] = 0;
   out_4731869887503502105[1] = 0;
   out_4731869887503502105[2] = 0;
   out_4731869887503502105[3] = 1;
   out_4731869887503502105[4] = 0;
   out_4731869887503502105[5] = 0;
   out_4731869887503502105[6] = 0;
   out_4731869887503502105[7] = 0;
   out_4731869887503502105[8] = 0;
   out_4731869887503502105[9] = 0;
   out_4731869887503502105[10] = 0;
   out_4731869887503502105[11] = 0;
   out_4731869887503502105[12] = 0;
   out_4731869887503502105[13] = 0;
   out_4731869887503502105[14] = 0;
   out_4731869887503502105[15] = 0;
   out_4731869887503502105[16] = 0;
   out_4731869887503502105[17] = 0;
   out_4731869887503502105[18] = 0;
   out_4731869887503502105[19] = 0;
   out_4731869887503502105[20] = 0;
   out_4731869887503502105[21] = 0;
   out_4731869887503502105[22] = 1;
   out_4731869887503502105[23] = 0;
   out_4731869887503502105[24] = 0;
   out_4731869887503502105[25] = 0;
   out_4731869887503502105[26] = 0;
   out_4731869887503502105[27] = 0;
   out_4731869887503502105[28] = 0;
   out_4731869887503502105[29] = 0;
   out_4731869887503502105[30] = 0;
   out_4731869887503502105[31] = 0;
   out_4731869887503502105[32] = 0;
   out_4731869887503502105[33] = 0;
   out_4731869887503502105[34] = 0;
   out_4731869887503502105[35] = 0;
   out_4731869887503502105[36] = 0;
   out_4731869887503502105[37] = 0;
   out_4731869887503502105[38] = 0;
   out_4731869887503502105[39] = 0;
   out_4731869887503502105[40] = 0;
   out_4731869887503502105[41] = 1;
   out_4731869887503502105[42] = 0;
   out_4731869887503502105[43] = 0;
   out_4731869887503502105[44] = 0;
   out_4731869887503502105[45] = 0;
   out_4731869887503502105[46] = 0;
   out_4731869887503502105[47] = 0;
   out_4731869887503502105[48] = 0;
   out_4731869887503502105[49] = 0;
   out_4731869887503502105[50] = 0;
   out_4731869887503502105[51] = 0;
   out_4731869887503502105[52] = 0;
   out_4731869887503502105[53] = 0;
}
void h_14(double *state, double *unused, double *out_3756453749111016413) {
   out_3756453749111016413[0] = state[6];
   out_3756453749111016413[1] = state[7];
   out_3756453749111016413[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5482836918510653833) {
   out_5482836918510653833[0] = 0;
   out_5482836918510653833[1] = 0;
   out_5482836918510653833[2] = 0;
   out_5482836918510653833[3] = 0;
   out_5482836918510653833[4] = 0;
   out_5482836918510653833[5] = 0;
   out_5482836918510653833[6] = 1;
   out_5482836918510653833[7] = 0;
   out_5482836918510653833[8] = 0;
   out_5482836918510653833[9] = 0;
   out_5482836918510653833[10] = 0;
   out_5482836918510653833[11] = 0;
   out_5482836918510653833[12] = 0;
   out_5482836918510653833[13] = 0;
   out_5482836918510653833[14] = 0;
   out_5482836918510653833[15] = 0;
   out_5482836918510653833[16] = 0;
   out_5482836918510653833[17] = 0;
   out_5482836918510653833[18] = 0;
   out_5482836918510653833[19] = 0;
   out_5482836918510653833[20] = 0;
   out_5482836918510653833[21] = 0;
   out_5482836918510653833[22] = 0;
   out_5482836918510653833[23] = 0;
   out_5482836918510653833[24] = 0;
   out_5482836918510653833[25] = 1;
   out_5482836918510653833[26] = 0;
   out_5482836918510653833[27] = 0;
   out_5482836918510653833[28] = 0;
   out_5482836918510653833[29] = 0;
   out_5482836918510653833[30] = 0;
   out_5482836918510653833[31] = 0;
   out_5482836918510653833[32] = 0;
   out_5482836918510653833[33] = 0;
   out_5482836918510653833[34] = 0;
   out_5482836918510653833[35] = 0;
   out_5482836918510653833[36] = 0;
   out_5482836918510653833[37] = 0;
   out_5482836918510653833[38] = 0;
   out_5482836918510653833[39] = 0;
   out_5482836918510653833[40] = 0;
   out_5482836918510653833[41] = 0;
   out_5482836918510653833[42] = 0;
   out_5482836918510653833[43] = 0;
   out_5482836918510653833[44] = 1;
   out_5482836918510653833[45] = 0;
   out_5482836918510653833[46] = 0;
   out_5482836918510653833[47] = 0;
   out_5482836918510653833[48] = 0;
   out_5482836918510653833[49] = 0;
   out_5482836918510653833[50] = 0;
   out_5482836918510653833[51] = 0;
   out_5482836918510653833[52] = 0;
   out_5482836918510653833[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_1444822050377652636) {
  err_fun(nom_x, delta_x, out_1444822050377652636);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2786220128142028057) {
  inv_err_fun(nom_x, true_x, out_2786220128142028057);
}
void pose_H_mod_fun(double *state, double *out_7982786345480560970) {
  H_mod_fun(state, out_7982786345480560970);
}
void pose_f_fun(double *state, double dt, double *out_3891050436305113138) {
  f_fun(state,  dt, out_3891050436305113138);
}
void pose_F_fun(double *state, double dt, double *out_5269798254466500565) {
  F_fun(state,  dt, out_5269798254466500565);
}
void pose_h_4(double *state, double *unused, double *out_955557096790646594) {
  h_4(state, unused, out_955557096790646594);
}
void pose_H_4(double *state, double *unused, double *out_1519596062171169304) {
  H_4(state, unused, out_1519596062171169304);
}
void pose_h_10(double *state, double *unused, double *out_837743937244112795) {
  h_10(state, unused, out_837743937244112795);
}
void pose_H_10(double *state, double *unused, double *out_4063371073341436919) {
  H_10(state, unused, out_4063371073341436919);
}
void pose_h_13(double *state, double *unused, double *out_4744417553824752666) {
  h_13(state, unused, out_4744417553824752666);
}
void pose_H_13(double *state, double *unused, double *out_4731869887503502105) {
  H_13(state, unused, out_4731869887503502105);
}
void pose_h_14(double *state, double *unused, double *out_3756453749111016413) {
  h_14(state, unused, out_3756453749111016413);
}
void pose_H_14(double *state, double *unused, double *out_5482836918510653833) {
  H_14(state, unused, out_5482836918510653833);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
