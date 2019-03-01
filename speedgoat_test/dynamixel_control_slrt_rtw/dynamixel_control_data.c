/*
 * dynamixel_control_data.c
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

#include "dynamixel_control.h"
#include "dynamixel_control_private.h"

/* Block parameters (default storage) */
P_dynamixel_control_T dynamixel_control_P = {
  /* Expression: 3.451678
   * Referenced by: '<Root>/Constant32'
   */
  3.451678,

  /* Computed Parameter: ASCIIEncode_P1_Size
   * Referenced by: '<Root>/ASCII Encode '
   */
  { 1.0, 15.0 },

  /* Computed Parameter: ASCIIEncode_P1
   * Referenced by: '<Root>/ASCII Encode '
   */
  { 118.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0, 32.0, 37.0, 52.0, 46.0, 50.0,
    102.0, 13.0, 10.0 },

  /* Computed Parameter: ASCIIEncode_P2_Size
   * Referenced by: '<Root>/ASCII Encode '
   */
  { 1.0, 1.0 },

  /* Expression: maxlength
   * Referenced by: '<Root>/ASCII Encode '
   */
  128.0,

  /* Computed Parameter: ASCIIEncode_P3_Size
   * Referenced by: '<Root>/ASCII Encode '
   */
  { 1.0, 1.0 },

  /* Expression: nvars
   * Referenced by: '<Root>/ASCII Encode '
   */
  1.0,

  /* Computed Parameter: ASCIIEncode_P4_Size
   * Referenced by: '<Root>/ASCII Encode '
   */
  { 1.0, 1.0 },

  /* Expression: varids
   * Referenced by: '<Root>/ASCII Encode '
   */
  0.0,

  /* Computed Parameter: Setup1_P1_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: addr
   * Referenced by: '<S1>/Setup1'
   */
  1016.0,

  /* Computed Parameter: Setup1_P2_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: baud
   * Referenced by: '<S1>/Setup1'
   */
  5.0,

  /* Computed Parameter: Setup1_P3_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: width
   * Referenced by: '<S1>/Setup1'
   */
  4.0,

  /* Computed Parameter: Setup1_P4_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: nstop
   * Referenced by: '<S1>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P5_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: parity
   * Referenced by: '<S1>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P6_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: fmode
   * Referenced by: '<S1>/Setup1'
   */
  2.0,

  /* Computed Parameter: Setup1_P7_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: ctsmode
   * Referenced by: '<S1>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P8_Size
   * Referenced by: '<S1>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: rlevel
   * Referenced by: '<S1>/Setup1'
   */
  3.0,

  /* Computed Parameter: Setup2_P1_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: addr
   * Referenced by: '<S1>/Setup2'
   */
  0.0,

  /* Computed Parameter: Setup2_P2_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: baud
   * Referenced by: '<S1>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P3_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: width
   * Referenced by: '<S1>/Setup2'
   */
  4.0,

  /* Computed Parameter: Setup2_P4_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: nstop
   * Referenced by: '<S1>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P5_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: parity
   * Referenced by: '<S1>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P6_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: fmode
   * Referenced by: '<S1>/Setup2'
   */
  2.0,

  /* Computed Parameter: Setup2_P7_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: ctsmode
   * Referenced by: '<S1>/Setup2'
   */
  0.0,

  /* Computed Parameter: Setup2_P8_Size
   * Referenced by: '<S1>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: rlevel
   * Referenced by: '<S1>/Setup2'
   */
  3.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S8>/Constant'
   */
  1U,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S10>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S9>/Constant'
   */
  1U,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S11>/Constant2'
   */
  1U
};
