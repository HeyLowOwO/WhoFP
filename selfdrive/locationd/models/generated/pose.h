#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4866654133542511122);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4207447887306676146);
void pose_H_mod_fun(double *state, double *out_7671947703506535444);
void pose_f_fun(double *state, double dt, double *out_303783976482334145);
void pose_F_fun(double *state, double dt, double *out_5261897322821554191);
void pose_h_4(double *state, double *unused, double *out_3942085955838143602);
void pose_H_4(double *state, double *unused, double *out_4397725624715586191);
void pose_h_10(double *state, double *unused, double *out_3945842508446122879);
void pose_H_10(double *state, double *unused, double *out_5550901447520007296);
void pose_h_13(double *state, double *unused, double *out_2457106912242730238);
void pose_H_13(double *state, double *unused, double *out_7609999450047918992);
void pose_h_14(double *state, double *unused, double *out_8441301839110070003);
void pose_H_14(double *state, double *unused, double *out_8360966481055070720);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}