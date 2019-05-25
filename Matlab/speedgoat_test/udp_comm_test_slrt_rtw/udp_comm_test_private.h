/*
 * udp_comm_test_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "udp_comm_test".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sat Feb 23 10:35:30 2019
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_udp_comm_test_private_h_
#define RTW_HEADER_udp_comm_test_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern void* slrtRegisterSignalToLoggingService(rtwCAPI_ModelMappingInfo* mdlMMI,
  const char* relBlkPath, int portNumber);
extern void slrtIPConfig(SimStruct *rts);
extern void asciiencode(SimStruct *rts);
extern void slrtUDPSend(SimStruct *rts);
extern void slrtUDPReceive(SimStruct *rts);
extern void asciidecode(SimStruct *rts);

#endif                                 /* RTW_HEADER_udp_comm_test_private_h_ */
