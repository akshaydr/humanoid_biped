/*
 * dynamixel_control_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "dynamixel_control".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Thu Feb  7 10:44:48 2019
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dynamixel_control_private_h_
#define RTW_HEADER_dynamixel_control_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "dynamixel_control.h"

/* Define interrupt functions for board 1 */
xpcPCIDevice xpcDev_1;

/* Done with interrupt functions for board 1 */
extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *fifowrite(int32_T *fifo, void *iPtr, void **oPtrs,
  int *settings);
extern void fiforead(const void *iPorts[], void *oPorts[], int *settings);
extern void asciiencode(SimStruct *rts);
extern void sersetupbase(SimStruct *rts);
extern void dynamixel_co_RS232ISR_Start(void);
extern void dynamixel_control_RS232ISR(void);
extern void dynamixel_con_RS232ISR_Term(void);

#endif                                 /* RTW_HEADER_dynamixel_control_private_h_ */
