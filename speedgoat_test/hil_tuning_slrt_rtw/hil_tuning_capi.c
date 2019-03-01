/*
 * hil_tuning_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "hil_tuning".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Fri Mar  1 11:09:38 2019
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "hil_tuning_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "hil_tuning.h"
#include "hil_tuning_capi.h"
#include "hil_tuning_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("Constant3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("ASCII Decode /p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 2, 0, TARGET_STRING("ASCII Decode /p2"),
    TARGET_STRING(""), 1, 1, 0, 0, 0 },

  { 3, 0, TARGET_STRING("ASCII Decode /p3"),
    TARGET_STRING(""), 2, 1, 0, 0, 0 },

  { 4, 0, TARGET_STRING("ASCII Decode /p4"),
    TARGET_STRING(""), 3, 1, 0, 0, 0 },

  { 5, 0, TARGET_STRING("ASCII Decode /p5"),
    TARGET_STRING(""), 4, 1, 0, 0, 0 },

  { 6, 0, TARGET_STRING("ASCII Decode /p6"),
    TARGET_STRING(""), 5, 1, 0, 0, 0 },

  { 7, 0, TARGET_STRING("ASCII Decode /p7"),
    TARGET_STRING(""), 6, 1, 0, 0, 0 },

  { 8, 0, TARGET_STRING("ASCII Decode /p8"),
    TARGET_STRING(""), 7, 1, 0, 0, 0 },

  { 9, 0, TARGET_STRING("ASCII Decode /p9"),
    TARGET_STRING(""), 8, 1, 0, 0, 0 },

  { 10, 0, TARGET_STRING("ASCII Decode /p10"),
    TARGET_STRING(""), 9, 1, 0, 0, 0 },

  { 11, 0, TARGET_STRING("ASCII Decode /p11"),
    TARGET_STRING(""), 10, 1, 0, 0, 0 },

  { 12, 0, TARGET_STRING("ASCII Decode /p12"),
    TARGET_STRING(""), 11, 1, 0, 0, 0 },

  { 13, 0, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 14, 0, TARGET_STRING("UDP Receive/p1"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 15, 0, TARGET_STRING("UDP Receive/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("Left Abduction1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 17, 0, TARGET_STRING("Left Abduction1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 18, 0, TARGET_STRING("Left Abduction1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 19, 0, TARGET_STRING("Left Abduction1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 20, 0, TARGET_STRING("Left Abduction1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 21, 0, TARGET_STRING("Left Ankle Twist1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 22, 0, TARGET_STRING("Left Ankle Twist1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 23, 0, TARGET_STRING("Left Ankle Twist1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 24, 0, TARGET_STRING("Left Ankle Twist1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 25, 0, TARGET_STRING("Left Ankle Twist1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 26, 0, TARGET_STRING("Left Ankle1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 27, 0, TARGET_STRING("Left Ankle1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 28, 0, TARGET_STRING("Left Ankle1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 29, 0, TARGET_STRING("Left Ankle1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 30, 0, TARGET_STRING("Left Ankle1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 31, 0, TARGET_STRING("Left Hip1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 32, 0, TARGET_STRING("Left Hip1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 33, 0, TARGET_STRING("Left Hip1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 34, 0, TARGET_STRING("Left Hip1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 35, 0, TARGET_STRING("Left Hip1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 36, 0, TARGET_STRING("Left Knee1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 37, 0, TARGET_STRING("Left Knee1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 38, 0, TARGET_STRING("Left Knee1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 39, 0, TARGET_STRING("Left Knee1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 40, 0, TARGET_STRING("Left Knee1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 41, 0, TARGET_STRING("Left Rotation1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 42, 0, TARGET_STRING("Left Rotation1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 43, 0, TARGET_STRING("Left Rotation1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 44, 0, TARGET_STRING("Left Rotation1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 45, 0, TARGET_STRING("Left Rotation1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 46, 0, TARGET_STRING("Right Abduction1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 47, 0, TARGET_STRING("Right Abduction1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 48, 0, TARGET_STRING("Right Abduction1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 49, 0, TARGET_STRING("Right Abduction1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 50, 0, TARGET_STRING("Right Abduction1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 51, 0, TARGET_STRING("Right Ankle Twist1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 52, 0, TARGET_STRING("Right Ankle Twist1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 53, 0, TARGET_STRING("Right Ankle Twist1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 54, 0, TARGET_STRING("Right Ankle Twist1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 55, 0, TARGET_STRING("Right Ankle Twist1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 56, 0, TARGET_STRING("Right Ankle1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 57, 0, TARGET_STRING("Right Ankle1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 58, 0, TARGET_STRING("Right Ankle1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 59, 0, TARGET_STRING("Right Ankle1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 60, 0, TARGET_STRING("Right Ankle1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 61, 0, TARGET_STRING("Right Hip1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 62, 0, TARGET_STRING("Right Hip1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 63, 0, TARGET_STRING("Right Hip1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 64, 0, TARGET_STRING("Right Hip1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 65, 0, TARGET_STRING("Right Hip1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 66, 0, TARGET_STRING("Right Knee1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 67, 0, TARGET_STRING("Right Knee1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 68, 0, TARGET_STRING("Right Knee1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 69, 0, TARGET_STRING("Right Knee1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 70, 0, TARGET_STRING("Right Knee1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 71, 0, TARGET_STRING("Right Rotation1/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 72, 0, TARGET_STRING("Right Rotation1/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 73, 0, TARGET_STRING("Right Rotation1/Look-Up Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 74, 0, TARGET_STRING("Right Rotation1/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 75, 0, TARGET_STRING("Right Rotation1/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 76, 0, TARGET_STRING("Subsystem1/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 77, 0, TARGET_STRING("Subsystem1/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 78, 0, TARGET_STRING("Subsystem1/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 79, 0, TARGET_STRING("Subsystem10/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 80, 0, TARGET_STRING("Subsystem10/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 81, 0, TARGET_STRING("Subsystem10/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 82, 0, TARGET_STRING("Subsystem11/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 83, 0, TARGET_STRING("Subsystem11/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 84, 0, TARGET_STRING("Subsystem11/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 85, 0, TARGET_STRING("Subsystem12/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 86, 0, TARGET_STRING("Subsystem12/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 87, 0, TARGET_STRING("Subsystem12/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 88, 0, TARGET_STRING("Subsystem2/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 89, 0, TARGET_STRING("Subsystem2/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 90, 0, TARGET_STRING("Subsystem2/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 91, 0, TARGET_STRING("Subsystem3/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 92, 0, TARGET_STRING("Subsystem3/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 93, 0, TARGET_STRING("Subsystem3/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 94, 0, TARGET_STRING("Subsystem4/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 95, 0, TARGET_STRING("Subsystem4/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 96, 0, TARGET_STRING("Subsystem4/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 97, 0, TARGET_STRING("Subsystem5/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 98, 0, TARGET_STRING("Subsystem5/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 99, 0, TARGET_STRING("Subsystem5/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 100, 0, TARGET_STRING("Subsystem6/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 101, 0, TARGET_STRING("Subsystem6/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 102, 0, TARGET_STRING("Subsystem6/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 103, 0, TARGET_STRING("Subsystem7/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 104, 0, TARGET_STRING("Subsystem7/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 105, 0, TARGET_STRING("Subsystem7/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 106, 0, TARGET_STRING("Subsystem8/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 107, 0, TARGET_STRING("Subsystem8/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 108, 0, TARGET_STRING("Subsystem8/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 109, 0, TARGET_STRING("Subsystem9/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 110, 0, TARGET_STRING("Subsystem9/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 111, 0, TARGET_STRING("Subsystem9/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 112, TARGET_STRING("Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 113, TARGET_STRING("abduction_tune"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 114, TARGET_STRING("ankle_tune"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 115, TARGET_STRING("ankle_twist_tune"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 116, TARGET_STRING("hip_tune"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 117, TARGET_STRING("knee_tune"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 118, TARGET_STRING("rotation_tune"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 119, TARGET_STRING("ASCII Decode "),
    TARGET_STRING("P1"), 0, 2, 0 },

  { 120, TARGET_STRING("ASCII Decode "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 121, TARGET_STRING("ASCII Decode "),
    TARGET_STRING("P3"), 0, 3, 0 },

  { 122, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P1"), 0, 2, 0 },

  { 123, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 124, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 125, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P4"), 0, 3, 0 },

  { 126, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P1"), 0, 4, 0 },

  { 127, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P2"), 0, 4, 0 },

  { 128, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P3"), 0, 4, 0 },

  { 129, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 130, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 131, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 132, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 133, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 134, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P12"), 0, 0, 0 },

  { 135, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P1"), 0, 5, 0 },

  { 136, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 137, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 138, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 139, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P5"), 0, 6, 0 },

  { 140, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 141, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 142, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 143, TARGET_STRING("UDP Send"),
    TARGET_STRING("P1"), 0, 5, 0 },

  { 144, TARGET_STRING("UDP Send"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 145, TARGET_STRING("UDP Send"),
    TARGET_STRING("P3"), 0, 6, 0 },

  { 146, TARGET_STRING("UDP Send"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 147, TARGET_STRING("UDP Send"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 148, TARGET_STRING("UDP Send"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 149, TARGET_STRING("Left Abduction1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 150, TARGET_STRING("Left Abduction1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 151, TARGET_STRING("Left Ankle Twist1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 152, TARGET_STRING("Left Ankle Twist1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 153, TARGET_STRING("Left Ankle1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 154, TARGET_STRING("Left Ankle1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 155, TARGET_STRING("Left Hip1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 156, TARGET_STRING("Left Hip1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 157, TARGET_STRING("Left Knee1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 158, TARGET_STRING("Left Knee1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 159, TARGET_STRING("Left Rotation1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 160, TARGET_STRING("Left Rotation1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 161, TARGET_STRING("Right Abduction1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 162, TARGET_STRING("Right Abduction1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 163, TARGET_STRING("Right Ankle Twist1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 164, TARGET_STRING("Right Ankle Twist1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 165, TARGET_STRING("Right Ankle1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 166, TARGET_STRING("Right Ankle1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 167, TARGET_STRING("Right Hip1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 168, TARGET_STRING("Right Hip1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 169, TARGET_STRING("Right Knee1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 170, TARGET_STRING("Right Knee1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 171, TARGET_STRING("Right Rotation1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 172, TARGET_STRING("Right Rotation1/Look-Up Table1"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 7, 0 },

  { 173, TARGET_STRING("Subsystem1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 174, TARGET_STRING("Subsystem1/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 175, TARGET_STRING("Subsystem10/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 176, TARGET_STRING("Subsystem10/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 177, TARGET_STRING("Subsystem10/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 178, TARGET_STRING("Subsystem11/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 179, TARGET_STRING("Subsystem11/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 180, TARGET_STRING("Subsystem12/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 181, TARGET_STRING("Subsystem12/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 182, TARGET_STRING("Subsystem12/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 183, TARGET_STRING("Subsystem2/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 184, TARGET_STRING("Subsystem2/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 185, TARGET_STRING("Subsystem3/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 186, TARGET_STRING("Subsystem3/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 187, TARGET_STRING("Subsystem3/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 188, TARGET_STRING("Subsystem4/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 189, TARGET_STRING("Subsystem4/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 190, TARGET_STRING("Subsystem4/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 191, TARGET_STRING("Subsystem5/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 192, TARGET_STRING("Subsystem5/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 193, TARGET_STRING("Subsystem5/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 194, TARGET_STRING("Subsystem6/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 195, TARGET_STRING("Subsystem6/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 196, TARGET_STRING("Subsystem7/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 197, TARGET_STRING("Subsystem7/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 198, TARGET_STRING("Subsystem8/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 199, TARGET_STRING("Subsystem8/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 200, TARGET_STRING("Subsystem9/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 201, TARGET_STRING("Subsystem9/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 202, TARGET_STRING("Subsystem9/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 203, TARGET_STRING("left_abduction"), 0, 7, 0 },

  { 204, TARGET_STRING("left_ankle"), 0, 7, 0 },

  { 205, TARGET_STRING("left_hip"), 0, 7, 0 },

  { 206, TARGET_STRING("left_knee"), 0, 7, 0 },

  { 207, TARGET_STRING("left_knee_twist"), 0, 7, 0 },

  { 208, TARGET_STRING("left_rotation"), 0, 7, 0 },

  { 209, TARGET_STRING("right_abduction"), 0, 7, 0 },

  { 210, TARGET_STRING("right_ankle"), 0, 7, 0 },

  { 211, TARGET_STRING("right_hip"), 0, 7, 0 },

  { 212, TARGET_STRING("right_knee"), 0, 7, 0 },

  { 213, TARGET_STRING("right_knee_twist"), 0, 7, 0 },

  { 214, TARGET_STRING("right_rotation"), 0, 7, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &hil_tuning_B.Constant3,             /* 0: Signal */
  &hil_tuning_B.ASCIIDecode_o1,        /* 1: Signal */
  &hil_tuning_B.ASCIIDecode_o2,        /* 2: Signal */
  &hil_tuning_B.ASCIIDecode_o3,        /* 3: Signal */
  &hil_tuning_B.ASCIIDecode_o4,        /* 4: Signal */
  &hil_tuning_B.ASCIIDecode_o5,        /* 5: Signal */
  &hil_tuning_B.ASCIIDecode_o6,        /* 6: Signal */
  &hil_tuning_B.ASCIIDecode_o7,        /* 7: Signal */
  &hil_tuning_B.ASCIIDecode_o8,        /* 8: Signal */
  &hil_tuning_B.ASCIIDecode_o9,        /* 9: Signal */
  &hil_tuning_B.ASCIIDecode_o10,       /* 10: Signal */
  &hil_tuning_B.ASCIIDecode_o11,       /* 11: Signal */
  &hil_tuning_B.ASCIIDecode_o12,       /* 12: Signal */
  &hil_tuning_B.ASCIIEncode2[0],       /* 13: Signal */
  &hil_tuning_B.UDPReceive_o1[0],      /* 14: Signal */
  &hil_tuning_B.UDPReceive_o2,         /* 15: Signal */
  &hil_tuning_B.Clock,                 /* 16: Signal */
  &hil_tuning_B.Output,                /* 17: Signal */
  &hil_tuning_B.LookUpTable1,          /* 18: Signal */
  &hil_tuning_B.MathFunction,          /* 19: Signal */
  &hil_tuning_B.Sum,                   /* 20: Signal */
  &hil_tuning_B.Clock_c,               /* 21: Signal */
  &hil_tuning_B.Output_a,              /* 22: Signal */
  &hil_tuning_B.LookUpTable1_k,        /* 23: Signal */
  &hil_tuning_B.MathFunction_p,        /* 24: Signal */
  &hil_tuning_B.Sum_k,                 /* 25: Signal */
  &hil_tuning_B.Clock_j,               /* 26: Signal */
  &hil_tuning_B.Output_d,              /* 27: Signal */
  &hil_tuning_B.LookUpTable1_j,        /* 28: Signal */
  &hil_tuning_B.MathFunction_l,        /* 29: Signal */
  &hil_tuning_B.Sum_ks,                /* 30: Signal */
  &hil_tuning_B.Clock_h,               /* 31: Signal */
  &hil_tuning_B.Output_i,              /* 32: Signal */
  &hil_tuning_B.LookUpTable1_jw,       /* 33: Signal */
  &hil_tuning_B.MathFunction_a,        /* 34: Signal */
  &hil_tuning_B.Sum_m,                 /* 35: Signal */
  &hil_tuning_B.Clock_l,               /* 36: Signal */
  &hil_tuning_B.Output_o,              /* 37: Signal */
  &hil_tuning_B.LookUpTable1_i,        /* 38: Signal */
  &hil_tuning_B.MathFunction_o,        /* 39: Signal */
  &hil_tuning_B.Sum_g,                 /* 40: Signal */
  &hil_tuning_B.Clock_i,               /* 41: Signal */
  &hil_tuning_B.Output_iv,             /* 42: Signal */
  &hil_tuning_B.LookUpTable1_b,        /* 43: Signal */
  &hil_tuning_B.MathFunction_e,        /* 44: Signal */
  &hil_tuning_B.Sum_e,                 /* 45: Signal */
  &hil_tuning_B.Clock_f,               /* 46: Signal */
  &hil_tuning_B.Output_k,              /* 47: Signal */
  &hil_tuning_B.LookUpTable1_o,        /* 48: Signal */
  &hil_tuning_B.MathFunction_f,        /* 49: Signal */
  &hil_tuning_B.Sum_j,                 /* 50: Signal */
  &hil_tuning_B.Clock_p,               /* 51: Signal */
  &hil_tuning_B.Output_h,              /* 52: Signal */
  &hil_tuning_B.LookUpTable1_m,        /* 53: Signal */
  &hil_tuning_B.MathFunction_d,        /* 54: Signal */
  &hil_tuning_B.Sum_l,                 /* 55: Signal */
  &hil_tuning_B.Clock_fy,              /* 56: Signal */
  &hil_tuning_B.Output_f,              /* 57: Signal */
  &hil_tuning_B.LookUpTable1_jt,       /* 58: Signal */
  &hil_tuning_B.MathFunction_h,        /* 59: Signal */
  &hil_tuning_B.Sum_b,                 /* 60: Signal */
  &hil_tuning_B.Clock_io,              /* 61: Signal */
  &hil_tuning_B.Output_i5,             /* 62: Signal */
  &hil_tuning_B.LookUpTable1_f,        /* 63: Signal */
  &hil_tuning_B.MathFunction_b,        /* 64: Signal */
  &hil_tuning_B.Sum_kw,                /* 65: Signal */
  &hil_tuning_B.Clock_l0,              /* 66: Signal */
  &hil_tuning_B.Output_o4,             /* 67: Signal */
  &hil_tuning_B.LookUpTable1_fg,       /* 68: Signal */
  &hil_tuning_B.MathFunction_n,        /* 69: Signal */
  &hil_tuning_B.Sum_p,                 /* 70: Signal */
  &hil_tuning_B.Clock_n,               /* 71: Signal */
  &hil_tuning_B.Output_p,              /* 72: Signal */
  &hil_tuning_B.LookUpTable1_p,        /* 73: Signal */
  &hil_tuning_B.MathFunction_i,        /* 74: Signal */
  &hil_tuning_B.Sum_eg,                /* 75: Signal */
  &hil_tuning_B.DataTypeConversion,    /* 76: Signal */
  &hil_tuning_B.Gain,                  /* 77: Signal */
  &hil_tuning_B.Add,                   /* 78: Signal */
  &hil_tuning_B.DataTypeConversion_e,  /* 79: Signal */
  &hil_tuning_B.Gain_m,                /* 80: Signal */
  &hil_tuning_B.Add_a,                 /* 81: Signal */
  &hil_tuning_B.DataTypeConversion_g,  /* 82: Signal */
  &hil_tuning_B.Gain_g,                /* 83: Signal */
  &hil_tuning_B.Add_f,                 /* 84: Signal */
  &hil_tuning_B.DataTypeConversion_j,  /* 85: Signal */
  &hil_tuning_B.Gain_f,                /* 86: Signal */
  &hil_tuning_B.Add_c,                 /* 87: Signal */
  &hil_tuning_B.DataTypeConversion_b,  /* 88: Signal */
  &hil_tuning_B.Gain_eb,               /* 89: Signal */
  &hil_tuning_B.Add_j,                 /* 90: Signal */
  &hil_tuning_B.DataTypeConversion_l,  /* 91: Signal */
  &hil_tuning_B.Gain_d,                /* 92: Signal */
  &hil_tuning_B.Add_ca,                /* 93: Signal */
  &hil_tuning_B.DataTypeConversion_o,  /* 94: Signal */
  &hil_tuning_B.Gain_k,                /* 95: Signal */
  &hil_tuning_B.Add_h,                 /* 96: Signal */
  &hil_tuning_B.DataTypeConversion_k,  /* 97: Signal */
  &hil_tuning_B.Gain_e,                /* 98: Signal */
  &hil_tuning_B.Add_d,                 /* 99: Signal */
  &hil_tuning_B.DataTypeConversion_ji, /* 100: Signal */
  &hil_tuning_B.Gain_c,                /* 101: Signal */
  &hil_tuning_B.Add_o,                 /* 102: Signal */
  &hil_tuning_B.DataTypeConversion_a,  /* 103: Signal */
  &hil_tuning_B.Gain_fl,               /* 104: Signal */
  &hil_tuning_B.Add_g,                 /* 105: Signal */
  &hil_tuning_B.DataTypeConversion_n,  /* 106: Signal */
  &hil_tuning_B.Gain_my,               /* 107: Signal */
  &hil_tuning_B.Add_cb,                /* 108: Signal */
  &hil_tuning_B.DataTypeConversion_i,  /* 109: Signal */
  &hil_tuning_B.Gain_j,                /* 110: Signal */
  &hil_tuning_B.Add_k,                 /* 111: Signal */
  &hil_tuning_P.Constant3_Value,       /* 112: Block Parameter */
  &hil_tuning_P.abduction_tune_Value,  /* 113: Block Parameter */
  &hil_tuning_P.ankle_tune_Value,      /* 114: Block Parameter */
  &hil_tuning_P.ankle_twist_tune_Value,/* 115: Block Parameter */
  &hil_tuning_P.hip_tune_Value,        /* 116: Block Parameter */
  &hil_tuning_P.knee_tune_Value,       /* 117: Block Parameter */
  &hil_tuning_P.rotation_tune_Value,   /* 118: Block Parameter */
  &hil_tuning_P.ASCIIDecode_P1[0],     /* 119: Block Parameter */
  &hil_tuning_P.ASCIIDecode_P2,        /* 120: Block Parameter */
  &hil_tuning_P.ASCIIDecode_P3[0],     /* 121: Block Parameter */
  &hil_tuning_P.ASCIIEncode2_P1[0],    /* 122: Block Parameter */
  &hil_tuning_P.ASCIIEncode2_P2,       /* 123: Block Parameter */
  &hil_tuning_P.ASCIIEncode2_P3,       /* 124: Block Parameter */
  &hil_tuning_P.ASCIIEncode2_P4[0],    /* 125: Block Parameter */
  &hil_tuning_P.UDPConfigure_P1[0],    /* 126: Block Parameter */
  &hil_tuning_P.UDPConfigure_P2[0],    /* 127: Block Parameter */
  &hil_tuning_P.UDPConfigure_P3[0],    /* 128: Block Parameter */
  &hil_tuning_P.UDPConfigure_P5,       /* 129: Block Parameter */
  &hil_tuning_P.UDPConfigure_P8,       /* 130: Block Parameter */
  &hil_tuning_P.UDPConfigure_P9,       /* 131: Block Parameter */
  &hil_tuning_P.UDPConfigure_P10,      /* 132: Block Parameter */
  &hil_tuning_P.UDPConfigure_P11,      /* 133: Block Parameter */
  &hil_tuning_P.UDPConfigure_P12,      /* 134: Block Parameter */
  &hil_tuning_P.UDPReceive_P1[0],      /* 135: Block Parameter */
  &hil_tuning_P.UDPReceive_P2,         /* 136: Block Parameter */
  &hil_tuning_P.UDPReceive_P3,         /* 137: Block Parameter */
  &hil_tuning_P.UDPReceive_P4,         /* 138: Block Parameter */
  &hil_tuning_P.UDPReceive_P5[0],      /* 139: Block Parameter */
  &hil_tuning_P.UDPReceive_P6,         /* 140: Block Parameter */
  &hil_tuning_P.UDPReceive_P7,         /* 141: Block Parameter */
  &hil_tuning_P.UDPReceive_P9,         /* 142: Block Parameter */
  &hil_tuning_P.UDPSend_P1[0],         /* 143: Block Parameter */
  &hil_tuning_P.UDPSend_P2,            /* 144: Block Parameter */
  &hil_tuning_P.UDPSend_P3[0],         /* 145: Block Parameter */
  &hil_tuning_P.UDPSend_P4,            /* 146: Block Parameter */
  &hil_tuning_P.UDPSend_P5,            /* 147: Block Parameter */
  &hil_tuning_P.UDPSend_P6,            /* 148: Block Parameter */
  &hil_tuning_P.Constant_Value,        /* 149: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data[0],/* 150: Block Parameter */
  &hil_tuning_P.Constant_Value_k,      /* 151: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_n[0],/* 152: Block Parameter */
  &hil_tuning_P.Constant_Value_p,      /* 153: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_d[0],/* 154: Block Parameter */
  &hil_tuning_P.Constant_Value_g,      /* 155: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_l[0],/* 156: Block Parameter */
  &hil_tuning_P.Constant_Value_h,      /* 157: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_g[0],/* 158: Block Parameter */
  &hil_tuning_P.Constant_Value_gs,     /* 159: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_gm[0],/* 160: Block Parameter */
  &hil_tuning_P.Constant_Value_gsv,    /* 161: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_nh[0],/* 162: Block Parameter */
  &hil_tuning_P.Constant_Value_a,      /* 163: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_e[0],/* 164: Block Parameter */
  &hil_tuning_P.Constant_Value_f,      /* 165: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_b[0],/* 166: Block Parameter */
  &hil_tuning_P.Constant_Value_kd,     /* 167: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_k[0],/* 168: Block Parameter */
  &hil_tuning_P.Constant_Value_m,      /* 169: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_h[0],/* 170: Block Parameter */
  &hil_tuning_P.Constant_Value_gd,     /* 171: Block Parameter */
  &hil_tuning_P.LookUpTable1_bp01Data_p[0],/* 172: Block Parameter */
  &hil_tuning_P.Constant_Value_b,      /* 173: Block Parameter */
  &hil_tuning_P.Gain_Gain,             /* 174: Block Parameter */
  &hil_tuning_P.Constant_Value_pf,     /* 175: Block Parameter */
  &hil_tuning_P.Constant1_Value,       /* 176: Block Parameter */
  &hil_tuning_P.Gain_Gain_f,           /* 177: Block Parameter */
  &hil_tuning_P.Constant_Value_i,      /* 178: Block Parameter */
  &hil_tuning_P.Gain_Gain_g,           /* 179: Block Parameter */
  &hil_tuning_P.Constant_Value_e,      /* 180: Block Parameter */
  &hil_tuning_P.Constant1_Value_e,     /* 181: Block Parameter */
  &hil_tuning_P.Gain_Gain_k,           /* 182: Block Parameter */
  &hil_tuning_P.Constant_Value_iy,     /* 183: Block Parameter */
  &hil_tuning_P.Gain_Gain_au,          /* 184: Block Parameter */
  &hil_tuning_P.Constant_Value_mw,     /* 185: Block Parameter */
  &hil_tuning_P.Constant1_Value_a,     /* 186: Block Parameter */
  &hil_tuning_P.Gain_Gain_jv,          /* 187: Block Parameter */
  &hil_tuning_P.Constant_Value_pr,     /* 188: Block Parameter */
  &hil_tuning_P.Constant1_Value_gr,    /* 189: Block Parameter */
  &hil_tuning_P.Gain_Gain_j0,          /* 190: Block Parameter */
  &hil_tuning_P.Constant_Value_pk,     /* 191: Block Parameter */
  &hil_tuning_P.Constant1_Value_g,     /* 192: Block Parameter */
  &hil_tuning_P.Gain_Gain_kd,          /* 193: Block Parameter */
  &hil_tuning_P.Constant_Value_gdr,    /* 194: Block Parameter */
  &hil_tuning_P.Gain_Gain_n,           /* 195: Block Parameter */
  &hil_tuning_P.Constant_Value_d,      /* 196: Block Parameter */
  &hil_tuning_P.Gain_Gain_d,           /* 197: Block Parameter */
  &hil_tuning_P.Constant_Value_ij,     /* 198: Block Parameter */
  &hil_tuning_P.Gain_Gain_a,           /* 199: Block Parameter */
  &hil_tuning_P.Constant_Value_l,      /* 200: Block Parameter */
  &hil_tuning_P.Constant1_Value_k,     /* 201: Block Parameter */
  &hil_tuning_P.Gain_Gain_j,           /* 202: Block Parameter */
  &hil_tuning_P.left_abduction[0],     /* 203: Model Parameter */
  &hil_tuning_P.left_ankle[0],         /* 204: Model Parameter */
  &hil_tuning_P.left_hip[0],           /* 205: Model Parameter */
  &hil_tuning_P.left_knee[0],          /* 206: Model Parameter */
  &hil_tuning_P.left_knee_twist[0],    /* 207: Model Parameter */
  &hil_tuning_P.left_rotation[0],      /* 208: Model Parameter */
  &hil_tuning_P.right_abduction[0],    /* 209: Model Parameter */
  &hil_tuning_P.right_ankle[0],        /* 210: Model Parameter */
  &hil_tuning_P.right_hip[0],          /* 211: Model Parameter */
  &hil_tuning_P.right_knee[0],         /* 212: Model Parameter */
  &hil_tuning_P.right_knee_twist[0],   /* 213: Model Parameter */
  &hil_tuning_P.right_rotation[0],     /* 214: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  128,                                 /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  35,                                  /* 5 */
  1,                                   /* 6 */
  12,                                  /* 7 */
  1,                                   /* 8 */
  4,                                   /* 9 */
  1,                                   /* 10 */
  11,                                  /* 11 */
  1,                                   /* 12 */
  13,                                  /* 13 */
  1,                                   /* 14 */
  40                                   /* 15 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 112,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 91,
    rtModelParameters, 12 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 856866824U,
    3793494117U,
    2763285899U,
    3945476315U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  hil_tuning_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void hil_tuning_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(hil_tuning_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(hil_tuning_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(hil_tuning_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(hil_tuning_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(hil_tuning_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  hil_tuning_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (hil_tuning_M);
  hil_tuning_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_hil_tuning_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(hil_tuning_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(hil_tuning_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(hil_tuning_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void hil_tuning_host_InitializeDataMapInfo(hil_tuning_host_DataMapInfo_T
    *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: hil_tuning_capi.c */
