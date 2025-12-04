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
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8905508431035548747) {
   out_8905508431035548747[0] = delta_x[0] + nom_x[0];
   out_8905508431035548747[1] = delta_x[1] + nom_x[1];
   out_8905508431035548747[2] = delta_x[2] + nom_x[2];
   out_8905508431035548747[3] = delta_x[3] + nom_x[3];
   out_8905508431035548747[4] = delta_x[4] + nom_x[4];
   out_8905508431035548747[5] = delta_x[5] + nom_x[5];
   out_8905508431035548747[6] = delta_x[6] + nom_x[6];
   out_8905508431035548747[7] = delta_x[7] + nom_x[7];
   out_8905508431035548747[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6402161051811411103) {
   out_6402161051811411103[0] = -nom_x[0] + true_x[0];
   out_6402161051811411103[1] = -nom_x[1] + true_x[1];
   out_6402161051811411103[2] = -nom_x[2] + true_x[2];
   out_6402161051811411103[3] = -nom_x[3] + true_x[3];
   out_6402161051811411103[4] = -nom_x[4] + true_x[4];
   out_6402161051811411103[5] = -nom_x[5] + true_x[5];
   out_6402161051811411103[6] = -nom_x[6] + true_x[6];
   out_6402161051811411103[7] = -nom_x[7] + true_x[7];
   out_6402161051811411103[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5207245781188636331) {
   out_5207245781188636331[0] = 1.0;
   out_5207245781188636331[1] = 0.0;
   out_5207245781188636331[2] = 0.0;
   out_5207245781188636331[3] = 0.0;
   out_5207245781188636331[4] = 0.0;
   out_5207245781188636331[5] = 0.0;
   out_5207245781188636331[6] = 0.0;
   out_5207245781188636331[7] = 0.0;
   out_5207245781188636331[8] = 0.0;
   out_5207245781188636331[9] = 0.0;
   out_5207245781188636331[10] = 1.0;
   out_5207245781188636331[11] = 0.0;
   out_5207245781188636331[12] = 0.0;
   out_5207245781188636331[13] = 0.0;
   out_5207245781188636331[14] = 0.0;
   out_5207245781188636331[15] = 0.0;
   out_5207245781188636331[16] = 0.0;
   out_5207245781188636331[17] = 0.0;
   out_5207245781188636331[18] = 0.0;
   out_5207245781188636331[19] = 0.0;
   out_5207245781188636331[20] = 1.0;
   out_5207245781188636331[21] = 0.0;
   out_5207245781188636331[22] = 0.0;
   out_5207245781188636331[23] = 0.0;
   out_5207245781188636331[24] = 0.0;
   out_5207245781188636331[25] = 0.0;
   out_5207245781188636331[26] = 0.0;
   out_5207245781188636331[27] = 0.0;
   out_5207245781188636331[28] = 0.0;
   out_5207245781188636331[29] = 0.0;
   out_5207245781188636331[30] = 1.0;
   out_5207245781188636331[31] = 0.0;
   out_5207245781188636331[32] = 0.0;
   out_5207245781188636331[33] = 0.0;
   out_5207245781188636331[34] = 0.0;
   out_5207245781188636331[35] = 0.0;
   out_5207245781188636331[36] = 0.0;
   out_5207245781188636331[37] = 0.0;
   out_5207245781188636331[38] = 0.0;
   out_5207245781188636331[39] = 0.0;
   out_5207245781188636331[40] = 1.0;
   out_5207245781188636331[41] = 0.0;
   out_5207245781188636331[42] = 0.0;
   out_5207245781188636331[43] = 0.0;
   out_5207245781188636331[44] = 0.0;
   out_5207245781188636331[45] = 0.0;
   out_5207245781188636331[46] = 0.0;
   out_5207245781188636331[47] = 0.0;
   out_5207245781188636331[48] = 0.0;
   out_5207245781188636331[49] = 0.0;
   out_5207245781188636331[50] = 1.0;
   out_5207245781188636331[51] = 0.0;
   out_5207245781188636331[52] = 0.0;
   out_5207245781188636331[53] = 0.0;
   out_5207245781188636331[54] = 0.0;
   out_5207245781188636331[55] = 0.0;
   out_5207245781188636331[56] = 0.0;
   out_5207245781188636331[57] = 0.0;
   out_5207245781188636331[58] = 0.0;
   out_5207245781188636331[59] = 0.0;
   out_5207245781188636331[60] = 1.0;
   out_5207245781188636331[61] = 0.0;
   out_5207245781188636331[62] = 0.0;
   out_5207245781188636331[63] = 0.0;
   out_5207245781188636331[64] = 0.0;
   out_5207245781188636331[65] = 0.0;
   out_5207245781188636331[66] = 0.0;
   out_5207245781188636331[67] = 0.0;
   out_5207245781188636331[68] = 0.0;
   out_5207245781188636331[69] = 0.0;
   out_5207245781188636331[70] = 1.0;
   out_5207245781188636331[71] = 0.0;
   out_5207245781188636331[72] = 0.0;
   out_5207245781188636331[73] = 0.0;
   out_5207245781188636331[74] = 0.0;
   out_5207245781188636331[75] = 0.0;
   out_5207245781188636331[76] = 0.0;
   out_5207245781188636331[77] = 0.0;
   out_5207245781188636331[78] = 0.0;
   out_5207245781188636331[79] = 0.0;
   out_5207245781188636331[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8020868675377486510) {
   out_8020868675377486510[0] = state[0];
   out_8020868675377486510[1] = state[1];
   out_8020868675377486510[2] = state[2];
   out_8020868675377486510[3] = state[3];
   out_8020868675377486510[4] = state[4];
   out_8020868675377486510[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8020868675377486510[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8020868675377486510[7] = state[7];
   out_8020868675377486510[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7496499370956575958) {
   out_7496499370956575958[0] = 1;
   out_7496499370956575958[1] = 0;
   out_7496499370956575958[2] = 0;
   out_7496499370956575958[3] = 0;
   out_7496499370956575958[4] = 0;
   out_7496499370956575958[5] = 0;
   out_7496499370956575958[6] = 0;
   out_7496499370956575958[7] = 0;
   out_7496499370956575958[8] = 0;
   out_7496499370956575958[9] = 0;
   out_7496499370956575958[10] = 1;
   out_7496499370956575958[11] = 0;
   out_7496499370956575958[12] = 0;
   out_7496499370956575958[13] = 0;
   out_7496499370956575958[14] = 0;
   out_7496499370956575958[15] = 0;
   out_7496499370956575958[16] = 0;
   out_7496499370956575958[17] = 0;
   out_7496499370956575958[18] = 0;
   out_7496499370956575958[19] = 0;
   out_7496499370956575958[20] = 1;
   out_7496499370956575958[21] = 0;
   out_7496499370956575958[22] = 0;
   out_7496499370956575958[23] = 0;
   out_7496499370956575958[24] = 0;
   out_7496499370956575958[25] = 0;
   out_7496499370956575958[26] = 0;
   out_7496499370956575958[27] = 0;
   out_7496499370956575958[28] = 0;
   out_7496499370956575958[29] = 0;
   out_7496499370956575958[30] = 1;
   out_7496499370956575958[31] = 0;
   out_7496499370956575958[32] = 0;
   out_7496499370956575958[33] = 0;
   out_7496499370956575958[34] = 0;
   out_7496499370956575958[35] = 0;
   out_7496499370956575958[36] = 0;
   out_7496499370956575958[37] = 0;
   out_7496499370956575958[38] = 0;
   out_7496499370956575958[39] = 0;
   out_7496499370956575958[40] = 1;
   out_7496499370956575958[41] = 0;
   out_7496499370956575958[42] = 0;
   out_7496499370956575958[43] = 0;
   out_7496499370956575958[44] = 0;
   out_7496499370956575958[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7496499370956575958[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7496499370956575958[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7496499370956575958[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7496499370956575958[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7496499370956575958[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7496499370956575958[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7496499370956575958[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7496499370956575958[53] = -9.8100000000000005*dt;
   out_7496499370956575958[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7496499370956575958[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7496499370956575958[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7496499370956575958[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7496499370956575958[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7496499370956575958[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7496499370956575958[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7496499370956575958[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7496499370956575958[62] = 0;
   out_7496499370956575958[63] = 0;
   out_7496499370956575958[64] = 0;
   out_7496499370956575958[65] = 0;
   out_7496499370956575958[66] = 0;
   out_7496499370956575958[67] = 0;
   out_7496499370956575958[68] = 0;
   out_7496499370956575958[69] = 0;
   out_7496499370956575958[70] = 1;
   out_7496499370956575958[71] = 0;
   out_7496499370956575958[72] = 0;
   out_7496499370956575958[73] = 0;
   out_7496499370956575958[74] = 0;
   out_7496499370956575958[75] = 0;
   out_7496499370956575958[76] = 0;
   out_7496499370956575958[77] = 0;
   out_7496499370956575958[78] = 0;
   out_7496499370956575958[79] = 0;
   out_7496499370956575958[80] = 1;
}
void h_25(double *state, double *unused, double *out_3606067786099245470) {
   out_3606067786099245470[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7537077878412291703) {
   out_7537077878412291703[0] = 0;
   out_7537077878412291703[1] = 0;
   out_7537077878412291703[2] = 0;
   out_7537077878412291703[3] = 0;
   out_7537077878412291703[4] = 0;
   out_7537077878412291703[5] = 0;
   out_7537077878412291703[6] = 1;
   out_7537077878412291703[7] = 0;
   out_7537077878412291703[8] = 0;
}
void h_24(double *state, double *unused, double *out_1668965083184547451) {
   out_1668965083184547451[0] = state[4];
   out_1668965083184547451[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8732451771690109940) {
   out_8732451771690109940[0] = 0;
   out_8732451771690109940[1] = 0;
   out_8732451771690109940[2] = 0;
   out_8732451771690109940[3] = 0;
   out_8732451771690109940[4] = 1;
   out_8732451771690109940[5] = 0;
   out_8732451771690109940[6] = 0;
   out_8732451771690109940[7] = 0;
   out_8732451771690109940[8] = 0;
   out_8732451771690109940[9] = 0;
   out_8732451771690109940[10] = 0;
   out_8732451771690109940[11] = 0;
   out_8732451771690109940[12] = 0;
   out_8732451771690109940[13] = 0;
   out_8732451771690109940[14] = 1;
   out_8732451771690109940[15] = 0;
   out_8732451771690109940[16] = 0;
   out_8732451771690109940[17] = 0;
}
void h_30(double *state, double *unused, double *out_3555107671989218883) {
   out_3555107671989218883[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8391333236790011286) {
   out_8391333236790011286[0] = 0;
   out_8391333236790011286[1] = 0;
   out_8391333236790011286[2] = 0;
   out_8391333236790011286[3] = 0;
   out_8391333236790011286[4] = 1;
   out_8391333236790011286[5] = 0;
   out_8391333236790011286[6] = 0;
   out_8391333236790011286[7] = 0;
   out_8391333236790011286[8] = 0;
}
void h_26(double *state, double *unused, double *out_3447655031803846896) {
   out_3447655031803846896[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3795574559538235479) {
   out_3795574559538235479[0] = 0;
   out_3795574559538235479[1] = 0;
   out_3795574559538235479[2] = 0;
   out_3795574559538235479[3] = 0;
   out_3795574559538235479[4] = 0;
   out_3795574559538235479[5] = 0;
   out_3795574559538235479[6] = 0;
   out_3795574559538235479[7] = 1;
   out_3795574559538235479[8] = 0;
}
void h_27(double *state, double *unused, double *out_1395605481561600175) {
   out_1395605481561600175[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6167739165606068069) {
   out_6167739165606068069[0] = 0;
   out_6167739165606068069[1] = 0;
   out_6167739165606068069[2] = 0;
   out_6167739165606068069[3] = 1;
   out_6167739165606068069[4] = 0;
   out_6167739165606068069[5] = 0;
   out_6167739165606068069[6] = 0;
   out_6167739165606068069[7] = 0;
   out_6167739165606068069[8] = 0;
}
void h_29(double *state, double *unused, double *out_1670799543846106064) {
   out_1670799543846106064[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7881101892475619102) {
   out_7881101892475619102[0] = 0;
   out_7881101892475619102[1] = 1;
   out_7881101892475619102[2] = 0;
   out_7881101892475619102[3] = 0;
   out_7881101892475619102[4] = 0;
   out_7881101892475619102[5] = 0;
   out_7881101892475619102[6] = 0;
   out_7881101892475619102[7] = 0;
   out_7881101892475619102[8] = 0;
}
void h_28(double *state, double *unused, double *out_1208799839247097476) {
   out_1208799839247097476[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5483243164164401940) {
   out_5483243164164401940[0] = 1;
   out_5483243164164401940[1] = 0;
   out_5483243164164401940[2] = 0;
   out_5483243164164401940[3] = 0;
   out_5483243164164401940[4] = 0;
   out_5483243164164401940[5] = 0;
   out_5483243164164401940[6] = 0;
   out_5483243164164401940[7] = 0;
   out_5483243164164401940[8] = 0;
}
void h_31(double *state, double *unused, double *out_7467751262527747122) {
   out_7467751262527747122[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7567723840289252131) {
   out_7567723840289252131[0] = 0;
   out_7567723840289252131[1] = 0;
   out_7567723840289252131[2] = 0;
   out_7567723840289252131[3] = 0;
   out_7567723840289252131[4] = 0;
   out_7567723840289252131[5] = 0;
   out_7567723840289252131[6] = 0;
   out_7567723840289252131[7] = 0;
   out_7567723840289252131[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8905508431035548747) {
  err_fun(nom_x, delta_x, out_8905508431035548747);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6402161051811411103) {
  inv_err_fun(nom_x, true_x, out_6402161051811411103);
}
void car_H_mod_fun(double *state, double *out_5207245781188636331) {
  H_mod_fun(state, out_5207245781188636331);
}
void car_f_fun(double *state, double dt, double *out_8020868675377486510) {
  f_fun(state,  dt, out_8020868675377486510);
}
void car_F_fun(double *state, double dt, double *out_7496499370956575958) {
  F_fun(state,  dt, out_7496499370956575958);
}
void car_h_25(double *state, double *unused, double *out_3606067786099245470) {
  h_25(state, unused, out_3606067786099245470);
}
void car_H_25(double *state, double *unused, double *out_7537077878412291703) {
  H_25(state, unused, out_7537077878412291703);
}
void car_h_24(double *state, double *unused, double *out_1668965083184547451) {
  h_24(state, unused, out_1668965083184547451);
}
void car_H_24(double *state, double *unused, double *out_8732451771690109940) {
  H_24(state, unused, out_8732451771690109940);
}
void car_h_30(double *state, double *unused, double *out_3555107671989218883) {
  h_30(state, unused, out_3555107671989218883);
}
void car_H_30(double *state, double *unused, double *out_8391333236790011286) {
  H_30(state, unused, out_8391333236790011286);
}
void car_h_26(double *state, double *unused, double *out_3447655031803846896) {
  h_26(state, unused, out_3447655031803846896);
}
void car_H_26(double *state, double *unused, double *out_3795574559538235479) {
  H_26(state, unused, out_3795574559538235479);
}
void car_h_27(double *state, double *unused, double *out_1395605481561600175) {
  h_27(state, unused, out_1395605481561600175);
}
void car_H_27(double *state, double *unused, double *out_6167739165606068069) {
  H_27(state, unused, out_6167739165606068069);
}
void car_h_29(double *state, double *unused, double *out_1670799543846106064) {
  h_29(state, unused, out_1670799543846106064);
}
void car_H_29(double *state, double *unused, double *out_7881101892475619102) {
  H_29(state, unused, out_7881101892475619102);
}
void car_h_28(double *state, double *unused, double *out_1208799839247097476) {
  h_28(state, unused, out_1208799839247097476);
}
void car_H_28(double *state, double *unused, double *out_5483243164164401940) {
  H_28(state, unused, out_5483243164164401940);
}
void car_h_31(double *state, double *unused, double *out_7467751262527747122) {
  h_31(state, unused, out_7467751262527747122);
}
void car_H_31(double *state, double *unused, double *out_7567723840289252131) {
  H_31(state, unused, out_7567723840289252131);
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
