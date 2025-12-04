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
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4866654133542511122) {
   out_4866654133542511122[0] = delta_x[0] + nom_x[0];
   out_4866654133542511122[1] = delta_x[1] + nom_x[1];
   out_4866654133542511122[2] = delta_x[2] + nom_x[2];
   out_4866654133542511122[3] = delta_x[3] + nom_x[3];
   out_4866654133542511122[4] = delta_x[4] + nom_x[4];
   out_4866654133542511122[5] = delta_x[5] + nom_x[5];
   out_4866654133542511122[6] = delta_x[6] + nom_x[6];
   out_4866654133542511122[7] = delta_x[7] + nom_x[7];
   out_4866654133542511122[8] = delta_x[8] + nom_x[8];
   out_4866654133542511122[9] = delta_x[9] + nom_x[9];
   out_4866654133542511122[10] = delta_x[10] + nom_x[10];
   out_4866654133542511122[11] = delta_x[11] + nom_x[11];
   out_4866654133542511122[12] = delta_x[12] + nom_x[12];
   out_4866654133542511122[13] = delta_x[13] + nom_x[13];
   out_4866654133542511122[14] = delta_x[14] + nom_x[14];
   out_4866654133542511122[15] = delta_x[15] + nom_x[15];
   out_4866654133542511122[16] = delta_x[16] + nom_x[16];
   out_4866654133542511122[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4207447887306676146) {
   out_4207447887306676146[0] = -nom_x[0] + true_x[0];
   out_4207447887306676146[1] = -nom_x[1] + true_x[1];
   out_4207447887306676146[2] = -nom_x[2] + true_x[2];
   out_4207447887306676146[3] = -nom_x[3] + true_x[3];
   out_4207447887306676146[4] = -nom_x[4] + true_x[4];
   out_4207447887306676146[5] = -nom_x[5] + true_x[5];
   out_4207447887306676146[6] = -nom_x[6] + true_x[6];
   out_4207447887306676146[7] = -nom_x[7] + true_x[7];
   out_4207447887306676146[8] = -nom_x[8] + true_x[8];
   out_4207447887306676146[9] = -nom_x[9] + true_x[9];
   out_4207447887306676146[10] = -nom_x[10] + true_x[10];
   out_4207447887306676146[11] = -nom_x[11] + true_x[11];
   out_4207447887306676146[12] = -nom_x[12] + true_x[12];
   out_4207447887306676146[13] = -nom_x[13] + true_x[13];
   out_4207447887306676146[14] = -nom_x[14] + true_x[14];
   out_4207447887306676146[15] = -nom_x[15] + true_x[15];
   out_4207447887306676146[16] = -nom_x[16] + true_x[16];
   out_4207447887306676146[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7671947703506535444) {
   out_7671947703506535444[0] = 1.0;
   out_7671947703506535444[1] = 0.0;
   out_7671947703506535444[2] = 0.0;
   out_7671947703506535444[3] = 0.0;
   out_7671947703506535444[4] = 0.0;
   out_7671947703506535444[5] = 0.0;
   out_7671947703506535444[6] = 0.0;
   out_7671947703506535444[7] = 0.0;
   out_7671947703506535444[8] = 0.0;
   out_7671947703506535444[9] = 0.0;
   out_7671947703506535444[10] = 0.0;
   out_7671947703506535444[11] = 0.0;
   out_7671947703506535444[12] = 0.0;
   out_7671947703506535444[13] = 0.0;
   out_7671947703506535444[14] = 0.0;
   out_7671947703506535444[15] = 0.0;
   out_7671947703506535444[16] = 0.0;
   out_7671947703506535444[17] = 0.0;
   out_7671947703506535444[18] = 0.0;
   out_7671947703506535444[19] = 1.0;
   out_7671947703506535444[20] = 0.0;
   out_7671947703506535444[21] = 0.0;
   out_7671947703506535444[22] = 0.0;
   out_7671947703506535444[23] = 0.0;
   out_7671947703506535444[24] = 0.0;
   out_7671947703506535444[25] = 0.0;
   out_7671947703506535444[26] = 0.0;
   out_7671947703506535444[27] = 0.0;
   out_7671947703506535444[28] = 0.0;
   out_7671947703506535444[29] = 0.0;
   out_7671947703506535444[30] = 0.0;
   out_7671947703506535444[31] = 0.0;
   out_7671947703506535444[32] = 0.0;
   out_7671947703506535444[33] = 0.0;
   out_7671947703506535444[34] = 0.0;
   out_7671947703506535444[35] = 0.0;
   out_7671947703506535444[36] = 0.0;
   out_7671947703506535444[37] = 0.0;
   out_7671947703506535444[38] = 1.0;
   out_7671947703506535444[39] = 0.0;
   out_7671947703506535444[40] = 0.0;
   out_7671947703506535444[41] = 0.0;
   out_7671947703506535444[42] = 0.0;
   out_7671947703506535444[43] = 0.0;
   out_7671947703506535444[44] = 0.0;
   out_7671947703506535444[45] = 0.0;
   out_7671947703506535444[46] = 0.0;
   out_7671947703506535444[47] = 0.0;
   out_7671947703506535444[48] = 0.0;
   out_7671947703506535444[49] = 0.0;
   out_7671947703506535444[50] = 0.0;
   out_7671947703506535444[51] = 0.0;
   out_7671947703506535444[52] = 0.0;
   out_7671947703506535444[53] = 0.0;
   out_7671947703506535444[54] = 0.0;
   out_7671947703506535444[55] = 0.0;
   out_7671947703506535444[56] = 0.0;
   out_7671947703506535444[57] = 1.0;
   out_7671947703506535444[58] = 0.0;
   out_7671947703506535444[59] = 0.0;
   out_7671947703506535444[60] = 0.0;
   out_7671947703506535444[61] = 0.0;
   out_7671947703506535444[62] = 0.0;
   out_7671947703506535444[63] = 0.0;
   out_7671947703506535444[64] = 0.0;
   out_7671947703506535444[65] = 0.0;
   out_7671947703506535444[66] = 0.0;
   out_7671947703506535444[67] = 0.0;
   out_7671947703506535444[68] = 0.0;
   out_7671947703506535444[69] = 0.0;
   out_7671947703506535444[70] = 0.0;
   out_7671947703506535444[71] = 0.0;
   out_7671947703506535444[72] = 0.0;
   out_7671947703506535444[73] = 0.0;
   out_7671947703506535444[74] = 0.0;
   out_7671947703506535444[75] = 0.0;
   out_7671947703506535444[76] = 1.0;
   out_7671947703506535444[77] = 0.0;
   out_7671947703506535444[78] = 0.0;
   out_7671947703506535444[79] = 0.0;
   out_7671947703506535444[80] = 0.0;
   out_7671947703506535444[81] = 0.0;
   out_7671947703506535444[82] = 0.0;
   out_7671947703506535444[83] = 0.0;
   out_7671947703506535444[84] = 0.0;
   out_7671947703506535444[85] = 0.0;
   out_7671947703506535444[86] = 0.0;
   out_7671947703506535444[87] = 0.0;
   out_7671947703506535444[88] = 0.0;
   out_7671947703506535444[89] = 0.0;
   out_7671947703506535444[90] = 0.0;
   out_7671947703506535444[91] = 0.0;
   out_7671947703506535444[92] = 0.0;
   out_7671947703506535444[93] = 0.0;
   out_7671947703506535444[94] = 0.0;
   out_7671947703506535444[95] = 1.0;
   out_7671947703506535444[96] = 0.0;
   out_7671947703506535444[97] = 0.0;
   out_7671947703506535444[98] = 0.0;
   out_7671947703506535444[99] = 0.0;
   out_7671947703506535444[100] = 0.0;
   out_7671947703506535444[101] = 0.0;
   out_7671947703506535444[102] = 0.0;
   out_7671947703506535444[103] = 0.0;
   out_7671947703506535444[104] = 0.0;
   out_7671947703506535444[105] = 0.0;
   out_7671947703506535444[106] = 0.0;
   out_7671947703506535444[107] = 0.0;
   out_7671947703506535444[108] = 0.0;
   out_7671947703506535444[109] = 0.0;
   out_7671947703506535444[110] = 0.0;
   out_7671947703506535444[111] = 0.0;
   out_7671947703506535444[112] = 0.0;
   out_7671947703506535444[113] = 0.0;
   out_7671947703506535444[114] = 1.0;
   out_7671947703506535444[115] = 0.0;
   out_7671947703506535444[116] = 0.0;
   out_7671947703506535444[117] = 0.0;
   out_7671947703506535444[118] = 0.0;
   out_7671947703506535444[119] = 0.0;
   out_7671947703506535444[120] = 0.0;
   out_7671947703506535444[121] = 0.0;
   out_7671947703506535444[122] = 0.0;
   out_7671947703506535444[123] = 0.0;
   out_7671947703506535444[124] = 0.0;
   out_7671947703506535444[125] = 0.0;
   out_7671947703506535444[126] = 0.0;
   out_7671947703506535444[127] = 0.0;
   out_7671947703506535444[128] = 0.0;
   out_7671947703506535444[129] = 0.0;
   out_7671947703506535444[130] = 0.0;
   out_7671947703506535444[131] = 0.0;
   out_7671947703506535444[132] = 0.0;
   out_7671947703506535444[133] = 1.0;
   out_7671947703506535444[134] = 0.0;
   out_7671947703506535444[135] = 0.0;
   out_7671947703506535444[136] = 0.0;
   out_7671947703506535444[137] = 0.0;
   out_7671947703506535444[138] = 0.0;
   out_7671947703506535444[139] = 0.0;
   out_7671947703506535444[140] = 0.0;
   out_7671947703506535444[141] = 0.0;
   out_7671947703506535444[142] = 0.0;
   out_7671947703506535444[143] = 0.0;
   out_7671947703506535444[144] = 0.0;
   out_7671947703506535444[145] = 0.0;
   out_7671947703506535444[146] = 0.0;
   out_7671947703506535444[147] = 0.0;
   out_7671947703506535444[148] = 0.0;
   out_7671947703506535444[149] = 0.0;
   out_7671947703506535444[150] = 0.0;
   out_7671947703506535444[151] = 0.0;
   out_7671947703506535444[152] = 1.0;
   out_7671947703506535444[153] = 0.0;
   out_7671947703506535444[154] = 0.0;
   out_7671947703506535444[155] = 0.0;
   out_7671947703506535444[156] = 0.0;
   out_7671947703506535444[157] = 0.0;
   out_7671947703506535444[158] = 0.0;
   out_7671947703506535444[159] = 0.0;
   out_7671947703506535444[160] = 0.0;
   out_7671947703506535444[161] = 0.0;
   out_7671947703506535444[162] = 0.0;
   out_7671947703506535444[163] = 0.0;
   out_7671947703506535444[164] = 0.0;
   out_7671947703506535444[165] = 0.0;
   out_7671947703506535444[166] = 0.0;
   out_7671947703506535444[167] = 0.0;
   out_7671947703506535444[168] = 0.0;
   out_7671947703506535444[169] = 0.0;
   out_7671947703506535444[170] = 0.0;
   out_7671947703506535444[171] = 1.0;
   out_7671947703506535444[172] = 0.0;
   out_7671947703506535444[173] = 0.0;
   out_7671947703506535444[174] = 0.0;
   out_7671947703506535444[175] = 0.0;
   out_7671947703506535444[176] = 0.0;
   out_7671947703506535444[177] = 0.0;
   out_7671947703506535444[178] = 0.0;
   out_7671947703506535444[179] = 0.0;
   out_7671947703506535444[180] = 0.0;
   out_7671947703506535444[181] = 0.0;
   out_7671947703506535444[182] = 0.0;
   out_7671947703506535444[183] = 0.0;
   out_7671947703506535444[184] = 0.0;
   out_7671947703506535444[185] = 0.0;
   out_7671947703506535444[186] = 0.0;
   out_7671947703506535444[187] = 0.0;
   out_7671947703506535444[188] = 0.0;
   out_7671947703506535444[189] = 0.0;
   out_7671947703506535444[190] = 1.0;
   out_7671947703506535444[191] = 0.0;
   out_7671947703506535444[192] = 0.0;
   out_7671947703506535444[193] = 0.0;
   out_7671947703506535444[194] = 0.0;
   out_7671947703506535444[195] = 0.0;
   out_7671947703506535444[196] = 0.0;
   out_7671947703506535444[197] = 0.0;
   out_7671947703506535444[198] = 0.0;
   out_7671947703506535444[199] = 0.0;
   out_7671947703506535444[200] = 0.0;
   out_7671947703506535444[201] = 0.0;
   out_7671947703506535444[202] = 0.0;
   out_7671947703506535444[203] = 0.0;
   out_7671947703506535444[204] = 0.0;
   out_7671947703506535444[205] = 0.0;
   out_7671947703506535444[206] = 0.0;
   out_7671947703506535444[207] = 0.0;
   out_7671947703506535444[208] = 0.0;
   out_7671947703506535444[209] = 1.0;
   out_7671947703506535444[210] = 0.0;
   out_7671947703506535444[211] = 0.0;
   out_7671947703506535444[212] = 0.0;
   out_7671947703506535444[213] = 0.0;
   out_7671947703506535444[214] = 0.0;
   out_7671947703506535444[215] = 0.0;
   out_7671947703506535444[216] = 0.0;
   out_7671947703506535444[217] = 0.0;
   out_7671947703506535444[218] = 0.0;
   out_7671947703506535444[219] = 0.0;
   out_7671947703506535444[220] = 0.0;
   out_7671947703506535444[221] = 0.0;
   out_7671947703506535444[222] = 0.0;
   out_7671947703506535444[223] = 0.0;
   out_7671947703506535444[224] = 0.0;
   out_7671947703506535444[225] = 0.0;
   out_7671947703506535444[226] = 0.0;
   out_7671947703506535444[227] = 0.0;
   out_7671947703506535444[228] = 1.0;
   out_7671947703506535444[229] = 0.0;
   out_7671947703506535444[230] = 0.0;
   out_7671947703506535444[231] = 0.0;
   out_7671947703506535444[232] = 0.0;
   out_7671947703506535444[233] = 0.0;
   out_7671947703506535444[234] = 0.0;
   out_7671947703506535444[235] = 0.0;
   out_7671947703506535444[236] = 0.0;
   out_7671947703506535444[237] = 0.0;
   out_7671947703506535444[238] = 0.0;
   out_7671947703506535444[239] = 0.0;
   out_7671947703506535444[240] = 0.0;
   out_7671947703506535444[241] = 0.0;
   out_7671947703506535444[242] = 0.0;
   out_7671947703506535444[243] = 0.0;
   out_7671947703506535444[244] = 0.0;
   out_7671947703506535444[245] = 0.0;
   out_7671947703506535444[246] = 0.0;
   out_7671947703506535444[247] = 1.0;
   out_7671947703506535444[248] = 0.0;
   out_7671947703506535444[249] = 0.0;
   out_7671947703506535444[250] = 0.0;
   out_7671947703506535444[251] = 0.0;
   out_7671947703506535444[252] = 0.0;
   out_7671947703506535444[253] = 0.0;
   out_7671947703506535444[254] = 0.0;
   out_7671947703506535444[255] = 0.0;
   out_7671947703506535444[256] = 0.0;
   out_7671947703506535444[257] = 0.0;
   out_7671947703506535444[258] = 0.0;
   out_7671947703506535444[259] = 0.0;
   out_7671947703506535444[260] = 0.0;
   out_7671947703506535444[261] = 0.0;
   out_7671947703506535444[262] = 0.0;
   out_7671947703506535444[263] = 0.0;
   out_7671947703506535444[264] = 0.0;
   out_7671947703506535444[265] = 0.0;
   out_7671947703506535444[266] = 1.0;
   out_7671947703506535444[267] = 0.0;
   out_7671947703506535444[268] = 0.0;
   out_7671947703506535444[269] = 0.0;
   out_7671947703506535444[270] = 0.0;
   out_7671947703506535444[271] = 0.0;
   out_7671947703506535444[272] = 0.0;
   out_7671947703506535444[273] = 0.0;
   out_7671947703506535444[274] = 0.0;
   out_7671947703506535444[275] = 0.0;
   out_7671947703506535444[276] = 0.0;
   out_7671947703506535444[277] = 0.0;
   out_7671947703506535444[278] = 0.0;
   out_7671947703506535444[279] = 0.0;
   out_7671947703506535444[280] = 0.0;
   out_7671947703506535444[281] = 0.0;
   out_7671947703506535444[282] = 0.0;
   out_7671947703506535444[283] = 0.0;
   out_7671947703506535444[284] = 0.0;
   out_7671947703506535444[285] = 1.0;
   out_7671947703506535444[286] = 0.0;
   out_7671947703506535444[287] = 0.0;
   out_7671947703506535444[288] = 0.0;
   out_7671947703506535444[289] = 0.0;
   out_7671947703506535444[290] = 0.0;
   out_7671947703506535444[291] = 0.0;
   out_7671947703506535444[292] = 0.0;
   out_7671947703506535444[293] = 0.0;
   out_7671947703506535444[294] = 0.0;
   out_7671947703506535444[295] = 0.0;
   out_7671947703506535444[296] = 0.0;
   out_7671947703506535444[297] = 0.0;
   out_7671947703506535444[298] = 0.0;
   out_7671947703506535444[299] = 0.0;
   out_7671947703506535444[300] = 0.0;
   out_7671947703506535444[301] = 0.0;
   out_7671947703506535444[302] = 0.0;
   out_7671947703506535444[303] = 0.0;
   out_7671947703506535444[304] = 1.0;
   out_7671947703506535444[305] = 0.0;
   out_7671947703506535444[306] = 0.0;
   out_7671947703506535444[307] = 0.0;
   out_7671947703506535444[308] = 0.0;
   out_7671947703506535444[309] = 0.0;
   out_7671947703506535444[310] = 0.0;
   out_7671947703506535444[311] = 0.0;
   out_7671947703506535444[312] = 0.0;
   out_7671947703506535444[313] = 0.0;
   out_7671947703506535444[314] = 0.0;
   out_7671947703506535444[315] = 0.0;
   out_7671947703506535444[316] = 0.0;
   out_7671947703506535444[317] = 0.0;
   out_7671947703506535444[318] = 0.0;
   out_7671947703506535444[319] = 0.0;
   out_7671947703506535444[320] = 0.0;
   out_7671947703506535444[321] = 0.0;
   out_7671947703506535444[322] = 0.0;
   out_7671947703506535444[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_303783976482334145) {
   out_303783976482334145[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_303783976482334145[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_303783976482334145[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_303783976482334145[3] = dt*state[12] + state[3];
   out_303783976482334145[4] = dt*state[13] + state[4];
   out_303783976482334145[5] = dt*state[14] + state[5];
   out_303783976482334145[6] = state[6];
   out_303783976482334145[7] = state[7];
   out_303783976482334145[8] = state[8];
   out_303783976482334145[9] = state[9];
   out_303783976482334145[10] = state[10];
   out_303783976482334145[11] = state[11];
   out_303783976482334145[12] = state[12];
   out_303783976482334145[13] = state[13];
   out_303783976482334145[14] = state[14];
   out_303783976482334145[15] = state[15];
   out_303783976482334145[16] = state[16];
   out_303783976482334145[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5261897322821554191) {
   out_5261897322821554191[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5261897322821554191[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5261897322821554191[2] = 0;
   out_5261897322821554191[3] = 0;
   out_5261897322821554191[4] = 0;
   out_5261897322821554191[5] = 0;
   out_5261897322821554191[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5261897322821554191[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5261897322821554191[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5261897322821554191[9] = 0;
   out_5261897322821554191[10] = 0;
   out_5261897322821554191[11] = 0;
   out_5261897322821554191[12] = 0;
   out_5261897322821554191[13] = 0;
   out_5261897322821554191[14] = 0;
   out_5261897322821554191[15] = 0;
   out_5261897322821554191[16] = 0;
   out_5261897322821554191[17] = 0;
   out_5261897322821554191[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5261897322821554191[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5261897322821554191[20] = 0;
   out_5261897322821554191[21] = 0;
   out_5261897322821554191[22] = 0;
   out_5261897322821554191[23] = 0;
   out_5261897322821554191[24] = 0;
   out_5261897322821554191[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5261897322821554191[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5261897322821554191[27] = 0;
   out_5261897322821554191[28] = 0;
   out_5261897322821554191[29] = 0;
   out_5261897322821554191[30] = 0;
   out_5261897322821554191[31] = 0;
   out_5261897322821554191[32] = 0;
   out_5261897322821554191[33] = 0;
   out_5261897322821554191[34] = 0;
   out_5261897322821554191[35] = 0;
   out_5261897322821554191[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5261897322821554191[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5261897322821554191[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5261897322821554191[39] = 0;
   out_5261897322821554191[40] = 0;
   out_5261897322821554191[41] = 0;
   out_5261897322821554191[42] = 0;
   out_5261897322821554191[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5261897322821554191[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5261897322821554191[45] = 0;
   out_5261897322821554191[46] = 0;
   out_5261897322821554191[47] = 0;
   out_5261897322821554191[48] = 0;
   out_5261897322821554191[49] = 0;
   out_5261897322821554191[50] = 0;
   out_5261897322821554191[51] = 0;
   out_5261897322821554191[52] = 0;
   out_5261897322821554191[53] = 0;
   out_5261897322821554191[54] = 0;
   out_5261897322821554191[55] = 0;
   out_5261897322821554191[56] = 0;
   out_5261897322821554191[57] = 1;
   out_5261897322821554191[58] = 0;
   out_5261897322821554191[59] = 0;
   out_5261897322821554191[60] = 0;
   out_5261897322821554191[61] = 0;
   out_5261897322821554191[62] = 0;
   out_5261897322821554191[63] = 0;
   out_5261897322821554191[64] = 0;
   out_5261897322821554191[65] = 0;
   out_5261897322821554191[66] = dt;
   out_5261897322821554191[67] = 0;
   out_5261897322821554191[68] = 0;
   out_5261897322821554191[69] = 0;
   out_5261897322821554191[70] = 0;
   out_5261897322821554191[71] = 0;
   out_5261897322821554191[72] = 0;
   out_5261897322821554191[73] = 0;
   out_5261897322821554191[74] = 0;
   out_5261897322821554191[75] = 0;
   out_5261897322821554191[76] = 1;
   out_5261897322821554191[77] = 0;
   out_5261897322821554191[78] = 0;
   out_5261897322821554191[79] = 0;
   out_5261897322821554191[80] = 0;
   out_5261897322821554191[81] = 0;
   out_5261897322821554191[82] = 0;
   out_5261897322821554191[83] = 0;
   out_5261897322821554191[84] = 0;
   out_5261897322821554191[85] = dt;
   out_5261897322821554191[86] = 0;
   out_5261897322821554191[87] = 0;
   out_5261897322821554191[88] = 0;
   out_5261897322821554191[89] = 0;
   out_5261897322821554191[90] = 0;
   out_5261897322821554191[91] = 0;
   out_5261897322821554191[92] = 0;
   out_5261897322821554191[93] = 0;
   out_5261897322821554191[94] = 0;
   out_5261897322821554191[95] = 1;
   out_5261897322821554191[96] = 0;
   out_5261897322821554191[97] = 0;
   out_5261897322821554191[98] = 0;
   out_5261897322821554191[99] = 0;
   out_5261897322821554191[100] = 0;
   out_5261897322821554191[101] = 0;
   out_5261897322821554191[102] = 0;
   out_5261897322821554191[103] = 0;
   out_5261897322821554191[104] = dt;
   out_5261897322821554191[105] = 0;
   out_5261897322821554191[106] = 0;
   out_5261897322821554191[107] = 0;
   out_5261897322821554191[108] = 0;
   out_5261897322821554191[109] = 0;
   out_5261897322821554191[110] = 0;
   out_5261897322821554191[111] = 0;
   out_5261897322821554191[112] = 0;
   out_5261897322821554191[113] = 0;
   out_5261897322821554191[114] = 1;
   out_5261897322821554191[115] = 0;
   out_5261897322821554191[116] = 0;
   out_5261897322821554191[117] = 0;
   out_5261897322821554191[118] = 0;
   out_5261897322821554191[119] = 0;
   out_5261897322821554191[120] = 0;
   out_5261897322821554191[121] = 0;
   out_5261897322821554191[122] = 0;
   out_5261897322821554191[123] = 0;
   out_5261897322821554191[124] = 0;
   out_5261897322821554191[125] = 0;
   out_5261897322821554191[126] = 0;
   out_5261897322821554191[127] = 0;
   out_5261897322821554191[128] = 0;
   out_5261897322821554191[129] = 0;
   out_5261897322821554191[130] = 0;
   out_5261897322821554191[131] = 0;
   out_5261897322821554191[132] = 0;
   out_5261897322821554191[133] = 1;
   out_5261897322821554191[134] = 0;
   out_5261897322821554191[135] = 0;
   out_5261897322821554191[136] = 0;
   out_5261897322821554191[137] = 0;
   out_5261897322821554191[138] = 0;
   out_5261897322821554191[139] = 0;
   out_5261897322821554191[140] = 0;
   out_5261897322821554191[141] = 0;
   out_5261897322821554191[142] = 0;
   out_5261897322821554191[143] = 0;
   out_5261897322821554191[144] = 0;
   out_5261897322821554191[145] = 0;
   out_5261897322821554191[146] = 0;
   out_5261897322821554191[147] = 0;
   out_5261897322821554191[148] = 0;
   out_5261897322821554191[149] = 0;
   out_5261897322821554191[150] = 0;
   out_5261897322821554191[151] = 0;
   out_5261897322821554191[152] = 1;
   out_5261897322821554191[153] = 0;
   out_5261897322821554191[154] = 0;
   out_5261897322821554191[155] = 0;
   out_5261897322821554191[156] = 0;
   out_5261897322821554191[157] = 0;
   out_5261897322821554191[158] = 0;
   out_5261897322821554191[159] = 0;
   out_5261897322821554191[160] = 0;
   out_5261897322821554191[161] = 0;
   out_5261897322821554191[162] = 0;
   out_5261897322821554191[163] = 0;
   out_5261897322821554191[164] = 0;
   out_5261897322821554191[165] = 0;
   out_5261897322821554191[166] = 0;
   out_5261897322821554191[167] = 0;
   out_5261897322821554191[168] = 0;
   out_5261897322821554191[169] = 0;
   out_5261897322821554191[170] = 0;
   out_5261897322821554191[171] = 1;
   out_5261897322821554191[172] = 0;
   out_5261897322821554191[173] = 0;
   out_5261897322821554191[174] = 0;
   out_5261897322821554191[175] = 0;
   out_5261897322821554191[176] = 0;
   out_5261897322821554191[177] = 0;
   out_5261897322821554191[178] = 0;
   out_5261897322821554191[179] = 0;
   out_5261897322821554191[180] = 0;
   out_5261897322821554191[181] = 0;
   out_5261897322821554191[182] = 0;
   out_5261897322821554191[183] = 0;
   out_5261897322821554191[184] = 0;
   out_5261897322821554191[185] = 0;
   out_5261897322821554191[186] = 0;
   out_5261897322821554191[187] = 0;
   out_5261897322821554191[188] = 0;
   out_5261897322821554191[189] = 0;
   out_5261897322821554191[190] = 1;
   out_5261897322821554191[191] = 0;
   out_5261897322821554191[192] = 0;
   out_5261897322821554191[193] = 0;
   out_5261897322821554191[194] = 0;
   out_5261897322821554191[195] = 0;
   out_5261897322821554191[196] = 0;
   out_5261897322821554191[197] = 0;
   out_5261897322821554191[198] = 0;
   out_5261897322821554191[199] = 0;
   out_5261897322821554191[200] = 0;
   out_5261897322821554191[201] = 0;
   out_5261897322821554191[202] = 0;
   out_5261897322821554191[203] = 0;
   out_5261897322821554191[204] = 0;
   out_5261897322821554191[205] = 0;
   out_5261897322821554191[206] = 0;
   out_5261897322821554191[207] = 0;
   out_5261897322821554191[208] = 0;
   out_5261897322821554191[209] = 1;
   out_5261897322821554191[210] = 0;
   out_5261897322821554191[211] = 0;
   out_5261897322821554191[212] = 0;
   out_5261897322821554191[213] = 0;
   out_5261897322821554191[214] = 0;
   out_5261897322821554191[215] = 0;
   out_5261897322821554191[216] = 0;
   out_5261897322821554191[217] = 0;
   out_5261897322821554191[218] = 0;
   out_5261897322821554191[219] = 0;
   out_5261897322821554191[220] = 0;
   out_5261897322821554191[221] = 0;
   out_5261897322821554191[222] = 0;
   out_5261897322821554191[223] = 0;
   out_5261897322821554191[224] = 0;
   out_5261897322821554191[225] = 0;
   out_5261897322821554191[226] = 0;
   out_5261897322821554191[227] = 0;
   out_5261897322821554191[228] = 1;
   out_5261897322821554191[229] = 0;
   out_5261897322821554191[230] = 0;
   out_5261897322821554191[231] = 0;
   out_5261897322821554191[232] = 0;
   out_5261897322821554191[233] = 0;
   out_5261897322821554191[234] = 0;
   out_5261897322821554191[235] = 0;
   out_5261897322821554191[236] = 0;
   out_5261897322821554191[237] = 0;
   out_5261897322821554191[238] = 0;
   out_5261897322821554191[239] = 0;
   out_5261897322821554191[240] = 0;
   out_5261897322821554191[241] = 0;
   out_5261897322821554191[242] = 0;
   out_5261897322821554191[243] = 0;
   out_5261897322821554191[244] = 0;
   out_5261897322821554191[245] = 0;
   out_5261897322821554191[246] = 0;
   out_5261897322821554191[247] = 1;
   out_5261897322821554191[248] = 0;
   out_5261897322821554191[249] = 0;
   out_5261897322821554191[250] = 0;
   out_5261897322821554191[251] = 0;
   out_5261897322821554191[252] = 0;
   out_5261897322821554191[253] = 0;
   out_5261897322821554191[254] = 0;
   out_5261897322821554191[255] = 0;
   out_5261897322821554191[256] = 0;
   out_5261897322821554191[257] = 0;
   out_5261897322821554191[258] = 0;
   out_5261897322821554191[259] = 0;
   out_5261897322821554191[260] = 0;
   out_5261897322821554191[261] = 0;
   out_5261897322821554191[262] = 0;
   out_5261897322821554191[263] = 0;
   out_5261897322821554191[264] = 0;
   out_5261897322821554191[265] = 0;
   out_5261897322821554191[266] = 1;
   out_5261897322821554191[267] = 0;
   out_5261897322821554191[268] = 0;
   out_5261897322821554191[269] = 0;
   out_5261897322821554191[270] = 0;
   out_5261897322821554191[271] = 0;
   out_5261897322821554191[272] = 0;
   out_5261897322821554191[273] = 0;
   out_5261897322821554191[274] = 0;
   out_5261897322821554191[275] = 0;
   out_5261897322821554191[276] = 0;
   out_5261897322821554191[277] = 0;
   out_5261897322821554191[278] = 0;
   out_5261897322821554191[279] = 0;
   out_5261897322821554191[280] = 0;
   out_5261897322821554191[281] = 0;
   out_5261897322821554191[282] = 0;
   out_5261897322821554191[283] = 0;
   out_5261897322821554191[284] = 0;
   out_5261897322821554191[285] = 1;
   out_5261897322821554191[286] = 0;
   out_5261897322821554191[287] = 0;
   out_5261897322821554191[288] = 0;
   out_5261897322821554191[289] = 0;
   out_5261897322821554191[290] = 0;
   out_5261897322821554191[291] = 0;
   out_5261897322821554191[292] = 0;
   out_5261897322821554191[293] = 0;
   out_5261897322821554191[294] = 0;
   out_5261897322821554191[295] = 0;
   out_5261897322821554191[296] = 0;
   out_5261897322821554191[297] = 0;
   out_5261897322821554191[298] = 0;
   out_5261897322821554191[299] = 0;
   out_5261897322821554191[300] = 0;
   out_5261897322821554191[301] = 0;
   out_5261897322821554191[302] = 0;
   out_5261897322821554191[303] = 0;
   out_5261897322821554191[304] = 1;
   out_5261897322821554191[305] = 0;
   out_5261897322821554191[306] = 0;
   out_5261897322821554191[307] = 0;
   out_5261897322821554191[308] = 0;
   out_5261897322821554191[309] = 0;
   out_5261897322821554191[310] = 0;
   out_5261897322821554191[311] = 0;
   out_5261897322821554191[312] = 0;
   out_5261897322821554191[313] = 0;
   out_5261897322821554191[314] = 0;
   out_5261897322821554191[315] = 0;
   out_5261897322821554191[316] = 0;
   out_5261897322821554191[317] = 0;
   out_5261897322821554191[318] = 0;
   out_5261897322821554191[319] = 0;
   out_5261897322821554191[320] = 0;
   out_5261897322821554191[321] = 0;
   out_5261897322821554191[322] = 0;
   out_5261897322821554191[323] = 1;
}
void h_4(double *state, double *unused, double *out_3942085955838143602) {
   out_3942085955838143602[0] = state[6] + state[9];
   out_3942085955838143602[1] = state[7] + state[10];
   out_3942085955838143602[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4397725624715586191) {
   out_4397725624715586191[0] = 0;
   out_4397725624715586191[1] = 0;
   out_4397725624715586191[2] = 0;
   out_4397725624715586191[3] = 0;
   out_4397725624715586191[4] = 0;
   out_4397725624715586191[5] = 0;
   out_4397725624715586191[6] = 1;
   out_4397725624715586191[7] = 0;
   out_4397725624715586191[8] = 0;
   out_4397725624715586191[9] = 1;
   out_4397725624715586191[10] = 0;
   out_4397725624715586191[11] = 0;
   out_4397725624715586191[12] = 0;
   out_4397725624715586191[13] = 0;
   out_4397725624715586191[14] = 0;
   out_4397725624715586191[15] = 0;
   out_4397725624715586191[16] = 0;
   out_4397725624715586191[17] = 0;
   out_4397725624715586191[18] = 0;
   out_4397725624715586191[19] = 0;
   out_4397725624715586191[20] = 0;
   out_4397725624715586191[21] = 0;
   out_4397725624715586191[22] = 0;
   out_4397725624715586191[23] = 0;
   out_4397725624715586191[24] = 0;
   out_4397725624715586191[25] = 1;
   out_4397725624715586191[26] = 0;
   out_4397725624715586191[27] = 0;
   out_4397725624715586191[28] = 1;
   out_4397725624715586191[29] = 0;
   out_4397725624715586191[30] = 0;
   out_4397725624715586191[31] = 0;
   out_4397725624715586191[32] = 0;
   out_4397725624715586191[33] = 0;
   out_4397725624715586191[34] = 0;
   out_4397725624715586191[35] = 0;
   out_4397725624715586191[36] = 0;
   out_4397725624715586191[37] = 0;
   out_4397725624715586191[38] = 0;
   out_4397725624715586191[39] = 0;
   out_4397725624715586191[40] = 0;
   out_4397725624715586191[41] = 0;
   out_4397725624715586191[42] = 0;
   out_4397725624715586191[43] = 0;
   out_4397725624715586191[44] = 1;
   out_4397725624715586191[45] = 0;
   out_4397725624715586191[46] = 0;
   out_4397725624715586191[47] = 1;
   out_4397725624715586191[48] = 0;
   out_4397725624715586191[49] = 0;
   out_4397725624715586191[50] = 0;
   out_4397725624715586191[51] = 0;
   out_4397725624715586191[52] = 0;
   out_4397725624715586191[53] = 0;
}
void h_10(double *state, double *unused, double *out_3945842508446122879) {
   out_3945842508446122879[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_3945842508446122879[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_3945842508446122879[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5550901447520007296) {
   out_5550901447520007296[0] = 0;
   out_5550901447520007296[1] = 9.8100000000000005*cos(state[1]);
   out_5550901447520007296[2] = 0;
   out_5550901447520007296[3] = 0;
   out_5550901447520007296[4] = -state[8];
   out_5550901447520007296[5] = state[7];
   out_5550901447520007296[6] = 0;
   out_5550901447520007296[7] = state[5];
   out_5550901447520007296[8] = -state[4];
   out_5550901447520007296[9] = 0;
   out_5550901447520007296[10] = 0;
   out_5550901447520007296[11] = 0;
   out_5550901447520007296[12] = 1;
   out_5550901447520007296[13] = 0;
   out_5550901447520007296[14] = 0;
   out_5550901447520007296[15] = 1;
   out_5550901447520007296[16] = 0;
   out_5550901447520007296[17] = 0;
   out_5550901447520007296[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5550901447520007296[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5550901447520007296[20] = 0;
   out_5550901447520007296[21] = state[8];
   out_5550901447520007296[22] = 0;
   out_5550901447520007296[23] = -state[6];
   out_5550901447520007296[24] = -state[5];
   out_5550901447520007296[25] = 0;
   out_5550901447520007296[26] = state[3];
   out_5550901447520007296[27] = 0;
   out_5550901447520007296[28] = 0;
   out_5550901447520007296[29] = 0;
   out_5550901447520007296[30] = 0;
   out_5550901447520007296[31] = 1;
   out_5550901447520007296[32] = 0;
   out_5550901447520007296[33] = 0;
   out_5550901447520007296[34] = 1;
   out_5550901447520007296[35] = 0;
   out_5550901447520007296[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5550901447520007296[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5550901447520007296[38] = 0;
   out_5550901447520007296[39] = -state[7];
   out_5550901447520007296[40] = state[6];
   out_5550901447520007296[41] = 0;
   out_5550901447520007296[42] = state[4];
   out_5550901447520007296[43] = -state[3];
   out_5550901447520007296[44] = 0;
   out_5550901447520007296[45] = 0;
   out_5550901447520007296[46] = 0;
   out_5550901447520007296[47] = 0;
   out_5550901447520007296[48] = 0;
   out_5550901447520007296[49] = 0;
   out_5550901447520007296[50] = 1;
   out_5550901447520007296[51] = 0;
   out_5550901447520007296[52] = 0;
   out_5550901447520007296[53] = 1;
}
void h_13(double *state, double *unused, double *out_2457106912242730238) {
   out_2457106912242730238[0] = state[3];
   out_2457106912242730238[1] = state[4];
   out_2457106912242730238[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7609999450047918992) {
   out_7609999450047918992[0] = 0;
   out_7609999450047918992[1] = 0;
   out_7609999450047918992[2] = 0;
   out_7609999450047918992[3] = 1;
   out_7609999450047918992[4] = 0;
   out_7609999450047918992[5] = 0;
   out_7609999450047918992[6] = 0;
   out_7609999450047918992[7] = 0;
   out_7609999450047918992[8] = 0;
   out_7609999450047918992[9] = 0;
   out_7609999450047918992[10] = 0;
   out_7609999450047918992[11] = 0;
   out_7609999450047918992[12] = 0;
   out_7609999450047918992[13] = 0;
   out_7609999450047918992[14] = 0;
   out_7609999450047918992[15] = 0;
   out_7609999450047918992[16] = 0;
   out_7609999450047918992[17] = 0;
   out_7609999450047918992[18] = 0;
   out_7609999450047918992[19] = 0;
   out_7609999450047918992[20] = 0;
   out_7609999450047918992[21] = 0;
   out_7609999450047918992[22] = 1;
   out_7609999450047918992[23] = 0;
   out_7609999450047918992[24] = 0;
   out_7609999450047918992[25] = 0;
   out_7609999450047918992[26] = 0;
   out_7609999450047918992[27] = 0;
   out_7609999450047918992[28] = 0;
   out_7609999450047918992[29] = 0;
   out_7609999450047918992[30] = 0;
   out_7609999450047918992[31] = 0;
   out_7609999450047918992[32] = 0;
   out_7609999450047918992[33] = 0;
   out_7609999450047918992[34] = 0;
   out_7609999450047918992[35] = 0;
   out_7609999450047918992[36] = 0;
   out_7609999450047918992[37] = 0;
   out_7609999450047918992[38] = 0;
   out_7609999450047918992[39] = 0;
   out_7609999450047918992[40] = 0;
   out_7609999450047918992[41] = 1;
   out_7609999450047918992[42] = 0;
   out_7609999450047918992[43] = 0;
   out_7609999450047918992[44] = 0;
   out_7609999450047918992[45] = 0;
   out_7609999450047918992[46] = 0;
   out_7609999450047918992[47] = 0;
   out_7609999450047918992[48] = 0;
   out_7609999450047918992[49] = 0;
   out_7609999450047918992[50] = 0;
   out_7609999450047918992[51] = 0;
   out_7609999450047918992[52] = 0;
   out_7609999450047918992[53] = 0;
}
void h_14(double *state, double *unused, double *out_8441301839110070003) {
   out_8441301839110070003[0] = state[6];
   out_8441301839110070003[1] = state[7];
   out_8441301839110070003[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8360966481055070720) {
   out_8360966481055070720[0] = 0;
   out_8360966481055070720[1] = 0;
   out_8360966481055070720[2] = 0;
   out_8360966481055070720[3] = 0;
   out_8360966481055070720[4] = 0;
   out_8360966481055070720[5] = 0;
   out_8360966481055070720[6] = 1;
   out_8360966481055070720[7] = 0;
   out_8360966481055070720[8] = 0;
   out_8360966481055070720[9] = 0;
   out_8360966481055070720[10] = 0;
   out_8360966481055070720[11] = 0;
   out_8360966481055070720[12] = 0;
   out_8360966481055070720[13] = 0;
   out_8360966481055070720[14] = 0;
   out_8360966481055070720[15] = 0;
   out_8360966481055070720[16] = 0;
   out_8360966481055070720[17] = 0;
   out_8360966481055070720[18] = 0;
   out_8360966481055070720[19] = 0;
   out_8360966481055070720[20] = 0;
   out_8360966481055070720[21] = 0;
   out_8360966481055070720[22] = 0;
   out_8360966481055070720[23] = 0;
   out_8360966481055070720[24] = 0;
   out_8360966481055070720[25] = 1;
   out_8360966481055070720[26] = 0;
   out_8360966481055070720[27] = 0;
   out_8360966481055070720[28] = 0;
   out_8360966481055070720[29] = 0;
   out_8360966481055070720[30] = 0;
   out_8360966481055070720[31] = 0;
   out_8360966481055070720[32] = 0;
   out_8360966481055070720[33] = 0;
   out_8360966481055070720[34] = 0;
   out_8360966481055070720[35] = 0;
   out_8360966481055070720[36] = 0;
   out_8360966481055070720[37] = 0;
   out_8360966481055070720[38] = 0;
   out_8360966481055070720[39] = 0;
   out_8360966481055070720[40] = 0;
   out_8360966481055070720[41] = 0;
   out_8360966481055070720[42] = 0;
   out_8360966481055070720[43] = 0;
   out_8360966481055070720[44] = 1;
   out_8360966481055070720[45] = 0;
   out_8360966481055070720[46] = 0;
   out_8360966481055070720[47] = 0;
   out_8360966481055070720[48] = 0;
   out_8360966481055070720[49] = 0;
   out_8360966481055070720[50] = 0;
   out_8360966481055070720[51] = 0;
   out_8360966481055070720[52] = 0;
   out_8360966481055070720[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4866654133542511122) {
  err_fun(nom_x, delta_x, out_4866654133542511122);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4207447887306676146) {
  inv_err_fun(nom_x, true_x, out_4207447887306676146);
}
void pose_H_mod_fun(double *state, double *out_7671947703506535444) {
  H_mod_fun(state, out_7671947703506535444);
}
void pose_f_fun(double *state, double dt, double *out_303783976482334145) {
  f_fun(state,  dt, out_303783976482334145);
}
void pose_F_fun(double *state, double dt, double *out_5261897322821554191) {
  F_fun(state,  dt, out_5261897322821554191);
}
void pose_h_4(double *state, double *unused, double *out_3942085955838143602) {
  h_4(state, unused, out_3942085955838143602);
}
void pose_H_4(double *state, double *unused, double *out_4397725624715586191) {
  H_4(state, unused, out_4397725624715586191);
}
void pose_h_10(double *state, double *unused, double *out_3945842508446122879) {
  h_10(state, unused, out_3945842508446122879);
}
void pose_H_10(double *state, double *unused, double *out_5550901447520007296) {
  H_10(state, unused, out_5550901447520007296);
}
void pose_h_13(double *state, double *unused, double *out_2457106912242730238) {
  h_13(state, unused, out_2457106912242730238);
}
void pose_H_13(double *state, double *unused, double *out_7609999450047918992) {
  H_13(state, unused, out_7609999450047918992);
}
void pose_h_14(double *state, double *unused, double *out_8441301839110070003) {
  h_14(state, unused, out_8441301839110070003);
}
void pose_H_14(double *state, double *unused, double *out_8360966481055070720) {
  H_14(state, unused, out_8360966481055070720);
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
