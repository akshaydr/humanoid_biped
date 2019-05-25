/*
 * Copy_of_Robot_leg_3_0_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Copy_of_Robot_leg_3_0".
 *
 * Model version              : 1.24
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Fri Feb 22 09:15:27 2019
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_of_Robot_leg_3_0_types_h_
#define RTW_HEADER_Copy_of_Robot_leg_3_0_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_QRk3VBh93sY1ebp6AlyVw_
#define DEFINED_TYPEDEF_FOR_struct_QRk3VBh93sY1ebp6AlyVw_

typedef struct {
  real_T gaitPeriod;
  real_T gaitTime[7];
  real_T a0_hip[6];
  real_T a1_hip[6];
  real_T a2_hip[6];
  real_T a3_hip[6];
  real_T a0_knee[6];
  real_T a1_knee[6];
  real_T a2_knee[6];
  real_T a3_knee[6];
  real_T a0_ankle[6];
  real_T a1_ankle[6];
  real_T a2_ankle[6];
  real_T a3_ankle[6];
} struct_QRk3VBh93sY1ebp6AlyVw;

#endif

/* Parameters for system: '<S4>/Switch Case Action Subsystem' */
typedef struct P_SwitchCaseActionSubsystem_C_T_ P_SwitchCaseActionSubsystem_C_T;

/* Parameters (default storage) */
typedef struct P_Copy_of_Robot_leg_3_0_T_ P_Copy_of_Robot_leg_3_0_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Copy_of_Robot_leg_3_0_T RT_MODEL_Copy_of_Robot_leg_3_0_T;

#endif                                 /* RTW_HEADER_Copy_of_Robot_leg_3_0_types_h_ */
