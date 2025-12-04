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
void car_err_fun(double *nom_x, double *delta_x, double *out_8905508431035548747);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6402161051811411103);
void car_H_mod_fun(double *state, double *out_5207245781188636331);
void car_f_fun(double *state, double dt, double *out_8020868675377486510);
void car_F_fun(double *state, double dt, double *out_7496499370956575958);
void car_h_25(double *state, double *unused, double *out_3606067786099245470);
void car_H_25(double *state, double *unused, double *out_7537077878412291703);
void car_h_24(double *state, double *unused, double *out_1668965083184547451);
void car_H_24(double *state, double *unused, double *out_8732451771690109940);
void car_h_30(double *state, double *unused, double *out_3555107671989218883);
void car_H_30(double *state, double *unused, double *out_8391333236790011286);
void car_h_26(double *state, double *unused, double *out_3447655031803846896);
void car_H_26(double *state, double *unused, double *out_3795574559538235479);
void car_h_27(double *state, double *unused, double *out_1395605481561600175);
void car_H_27(double *state, double *unused, double *out_6167739165606068069);
void car_h_29(double *state, double *unused, double *out_1670799543846106064);
void car_H_29(double *state, double *unused, double *out_7881101892475619102);
void car_h_28(double *state, double *unused, double *out_1208799839247097476);
void car_H_28(double *state, double *unused, double *out_5483243164164401940);
void car_h_31(double *state, double *unused, double *out_7467751262527747122);
void car_H_31(double *state, double *unused, double *out_7567723840289252131);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}