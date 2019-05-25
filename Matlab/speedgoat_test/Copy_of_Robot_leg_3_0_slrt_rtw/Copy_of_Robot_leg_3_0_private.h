/*
 * Copy_of_Robot_leg_3_0_private.h
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

#ifndef RTW_HEADER_Copy_of_Robot_leg_3_0_private_h_
#define RTW_HEADER_Copy_of_Robot_leg_3_0_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Copy_of_Robot_leg_3_0.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void rt_mldivide_U1d3x3_U2d_9O8lG8ax(const real_T u0[9], const real_T u1
  [3], real_T y[3]);
extern void* slrtRegisterSignalToLoggingService(rtwCAPI_ModelMappingInfo* mdlMMI,
  const char* relBlkPath, int portNumber);
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
  ;
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void slrtIPConfig(SimStruct *rts);
extern void asciiencode(SimStruct *rts);
extern void slrtUDPSend(SimStruct *rts);
extern void SwitchCaseActionSubsystem_Init(B_SwitchCaseActionSubsystem_C_T
  *localB, P_SwitchCaseActionSubsystem_C_T *localP);
extern void Copy__SwitchCaseActionSubsystem(real_T rtu_In1, real_T rtu_In1_j,
  real_T rtu_In1_m, real_T rtu_In1_f, real_T rtu_In1_o, real_T rtu_In1_oq,
  B_SwitchCaseActionSubsystem_C_T *localB);

/* private model entry point functions */
extern void Copy_of_Robot_leg_3_0_derivatives(void);

#endif                                 /* RTW_HEADER_Copy_of_Robot_leg_3_0_private_h_ */
