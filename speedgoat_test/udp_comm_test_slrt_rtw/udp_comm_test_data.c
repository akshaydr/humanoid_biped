/*
 * udp_comm_test_data.c
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

#include "udp_comm_test.h"
#include "udp_comm_test_private.h"

/* Block parameters (default storage) */
P_udp_comm_test_T udp_comm_test_P = {
  /* Computed Parameter: UDPConfigure_P1_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: ipAdd
   * Referenced by: '<Root>/UDP Configure'
   */
  { 192.0, 168.0, 7.0, 3.0 },

  /* Computed Parameter: UDPConfigure_P2_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: snMask
   * Referenced by: '<Root>/UDP Configure'
   */
  { 255.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P3_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: gwAdd
   * Referenced by: '<Root>/UDP Configure'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P4_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P5_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: enableMulticast
   * Referenced by: '<Root>/UDP Configure'
   */
  1.0,

  /* Computed Parameter: UDPConfigure_P6_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P7_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P8_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciBus
   * Referenced by: '<Root>/UDP Configure'
   */
  2.0,

  /* Computed Parameter: UDPConfigure_P9_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciSlot
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P10_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciFunction
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P11_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: tune
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P12_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: ASCIIEncode2_P1_Size
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  { 1.0, 35.0 },

  /* Computed Parameter: ASCIIEncode2_P1
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  { 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0,
    37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0,
    37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0 },

  /* Computed Parameter: ASCIIEncode2_P2_Size
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  { 1.0, 1.0 },

  /* Expression: maxlength
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  128.0,

  /* Computed Parameter: ASCIIEncode2_P3_Size
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  { 1.0, 1.0 },

  /* Expression: nvars
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  12.0,

  /* Computed Parameter: ASCIIEncode2_P4_Size
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  { 1.0, 12.0 },

  /* Expression: varids
   * Referenced by: '<Root>/ASCII Encode 2'
   */
  { 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0 },

  /* Expression: 59
   * Referenced by: '<Root>/Constant3'
   */
  59.0,

  /* Computed Parameter: UDPSend_P1_Size
   * Referenced by: '<Root>/UDP Send'
   */
  { 1.0, 11.0 },

  /* Computed Parameter: UDPSend_P1
   * Referenced by: '<Root>/UDP Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 55.0, 46.0, 51.0 },

  /* Computed Parameter: UDPSend_P2_Size
   * Referenced by: '<Root>/UDP Send'
   */
  { 1.0, 1.0 },

  /* Expression: localPort
   * Referenced by: '<Root>/UDP Send'
   */
  25001.0,

  /* Computed Parameter: UDPSend_P3_Size
   * Referenced by: '<Root>/UDP Send'
   */
  { 1.0, 13.0 },

  /* Computed Parameter: UDPSend_P3
   * Referenced by: '<Root>/UDP Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 50.0, 46.0, 49.0, 48.0, 49.0
  },

  /* Computed Parameter: UDPSend_P4_Size
   * Referenced by: '<Root>/UDP Send'
   */
  { 1.0, 1.0 },

  /* Expression: toPort
   * Referenced by: '<Root>/UDP Send'
   */
  8001.0,

  /* Computed Parameter: UDPSend_P5_Size
   * Referenced by: '<Root>/UDP Send'
   */
  { 1.0, 1.0 },

  /* Expression: useHostTargetComm
   * Referenced by: '<Root>/UDP Send'
   */
  0.0,

  /* Computed Parameter: UDPSend_P6_Size
   * Referenced by: '<Root>/UDP Send'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/UDP Send'
   */
  -1.0,

  /* Computed Parameter: UDPReceive_P1_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 11.0 },

  /* Computed Parameter: UDPReceive_P1
   * Referenced by: '<Root>/UDP Receive'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 55.0, 46.0, 51.0 },

  /* Computed Parameter: UDPReceive_P2_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 1.0 },

  /* Expression: localPort
   * Referenced by: '<Root>/UDP Receive'
   */
  1234.0,

  /* Computed Parameter: UDPReceive_P3_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 1.0 },

  /* Expression: outWidth
   * Referenced by: '<Root>/UDP Receive'
   */
  128.0,

  /* Computed Parameter: UDPReceive_P4_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 1.0 },

  /* Expression: useHostTargetComm
   * Referenced by: '<Root>/UDP Receive'
   */
  0.0,

  /* Computed Parameter: UDPReceive_P5_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 13.0 },

  /* Computed Parameter: UDPReceive_P5
   * Referenced by: '<Root>/UDP Receive'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 50.0, 46.0, 49.0, 48.0, 49.0
  },

  /* Computed Parameter: UDPReceive_P6_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 1.0 },

  /* Expression: maxUDPQueue
   * Referenced by: '<Root>/UDP Receive'
   */
  8.0,

  /* Computed Parameter: UDPReceive_P7_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 1.0 },

  /* Expression: rcvMulticast
   * Referenced by: '<Root>/UDP Receive'
   */
  0.0,

  /* Computed Parameter: UDPReceive_P8_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: UDPReceive_P9_Size
   * Referenced by: '<Root>/UDP Receive'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/UDP Receive'
   */
  -1.0,

  /* Computed Parameter: ASCIIDecode_P1_Size
   * Referenced by: '<Root>/ASCII Decode '
   */
  { 1.0, 35.0 },

  /* Computed Parameter: ASCIIDecode_P1
   * Referenced by: '<Root>/ASCII Decode '
   */
  { 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0,
    37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0,
    37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0, 44.0, 37.0, 100.0 },

  /* Computed Parameter: ASCIIDecode_P2_Size
   * Referenced by: '<Root>/ASCII Decode '
   */
  { 1.0, 1.0 },

  /* Expression: nvars
   * Referenced by: '<Root>/ASCII Decode '
   */
  12.0,

  /* Computed Parameter: ASCIIDecode_P3_Size
   * Referenced by: '<Root>/ASCII Decode '
   */
  { 1.0, 12.0 },

  /* Expression: varids
   * Referenced by: '<Root>/ASCII Decode '
   */
  { 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0 },

  /* Computed Parameter: rotation_tune_Value
   * Referenced by: '<Root>/rotation_tune'
   */
  0,

  /* Computed Parameter: abduction_tune_Value
   * Referenced by: '<Root>/abduction_tune'
   */
  0,

  /* Computed Parameter: hip_tune_Value
   * Referenced by: '<Root>/hip_tune'
   */
  0,

  /* Computed Parameter: knee_tune_Value
   * Referenced by: '<Root>/knee_tune'
   */
  0,

  /* Computed Parameter: ankle_tune_Value
   * Referenced by: '<Root>/ankle_tune'
   */
  0,

  /* Computed Parameter: ankle_twist_tune_Value
   * Referenced by: '<Root>/ankle_twist_tune'
   */
  0,

  /* Computed Parameter: right_rotation2_Value
   * Referenced by: '<Root>/right_rotation2'
   */
  2036U,

  /* Computed Parameter: right_abduction2_Value
   * Referenced by: '<Root>/right_abduction2 '
   */
  2036U,

  /* Computed Parameter: right_hip2_Value
   * Referenced by: '<Root>/right_hip2 '
   */
  2036U,

  /* Computed Parameter: right_knee2_Value
   * Referenced by: '<Root>/right_knee2'
   */
  2036U,

  /* Computed Parameter: right_annkle2_Value
   * Referenced by: '<Root>/right_annkle2'
   */
  2036U,

  /* Computed Parameter: right_annkle_twist2_Value
   * Referenced by: '<Root>/right_annkle_twist2 '
   */
  2036U,

  /* Computed Parameter: left_rotation2_Value
   * Referenced by: '<Root>/left_rotation2 '
   */
  2036U,

  /* Computed Parameter: left_abduction2_Value
   * Referenced by: '<Root>/left_abduction2 '
   */
  2036U,

  /* Computed Parameter: left_hip2_Value
   * Referenced by: '<Root>/left_hip2 '
   */
  2036U,

  /* Computed Parameter: left_knee2_Value
   * Referenced by: '<Root>/left_knee2'
   */
  2036U,

  /* Computed Parameter: left_ankle2_Value
   * Referenced by: '<Root>/left_ankle2'
   */
  2036U,

  /* Computed Parameter: left_ankle_twist2_Value
   * Referenced by: '<Root>/left_ankle_twist2 '
   */
  2036U
};
