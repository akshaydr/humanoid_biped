/*
 * hil_tuning.c
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

#include "rt_logging_mmi.h"
#include "hil_tuning_capi.h"
#include "hil_tuning.h"
#include "hil_tuning_private.h"

/* Block signals (default storage) */
B_hil_tuning_T hil_tuning_B;

/* Block states (default storage) */
DW_hil_tuning_T hil_tuning_DW;

/* Real-time model */
RT_MODEL_hil_tuning_T hil_tuning_M_;
RT_MODEL_hil_tuning_T *const hil_tuning_M = &hil_tuning_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T q;
  boolean_T y_0;
  boolean_T y_1;
  y_0 = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
  y_1 = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
  if (!(y_0 && y_1)) {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      y = ceil(u1);
    } else {
      y = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != y)) {
      q = fabs(u0 / u1);
      if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model output function */
static void hil_tuning_output(void)
{
  real_T tmp;

  /* S-Function (slrtIPConfig): '<Root>/UDP Configure' */

  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* S-Function (slrtUDPReceive): '<Root>/UDP Receive' */

  /* Level2 S-Function Block: '<Root>/UDP Receive' (slrtUDPReceive) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* S-Function (asciidecode): '<Root>/ASCII Decode ' */

  /* Level2 S-Function Block: '<Root>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[2];
    sfcnOutputs(rts,1);
  }

  /* Clock: '<S1>/Clock' */
  hil_tuning_B.Clock = hil_tuning_M->Timing.t[0];

  /* Sum: '<S1>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S1>/startTime'
   */
  hil_tuning_B.Sum = hil_tuning_B.Clock - (0.0);

  /* Math: '<S1>/Math Function' incorporates:
   *  Constant: '<S1>/Constant'
   */
  hil_tuning_B.MathFunction = rt_remd_snf(hil_tuning_B.Sum,
    hil_tuning_P.Constant_Value);

  /* Lookup_n-D: '<S1>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1 = look1_binlxpw(hil_tuning_B.MathFunction,
    hil_tuning_P.LookUpTable1_bp01Data, hil_tuning_P.left_abduction, 39U);

  /* SignalConversion: '<S1>/Output' */
  hil_tuning_B.Output = hil_tuning_B.LookUpTable1;

  /* Clock: '<S2>/Clock' */
  hil_tuning_B.Clock_c = hil_tuning_M->Timing.t[0];

  /* Sum: '<S2>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S2>/startTime'
   */
  hil_tuning_B.Sum_k = hil_tuning_B.Clock_c - (0.0);

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   */
  hil_tuning_B.MathFunction_p = rt_remd_snf(hil_tuning_B.Sum_k,
    hil_tuning_P.Constant_Value_k);

  /* Lookup_n-D: '<S2>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_k = look1_binlxpw(hil_tuning_B.MathFunction_p,
    hil_tuning_P.LookUpTable1_bp01Data_n, hil_tuning_P.left_knee_twist, 39U);

  /* SignalConversion: '<S2>/Output' */
  hil_tuning_B.Output_a = hil_tuning_B.LookUpTable1_k;

  /* Clock: '<S3>/Clock' */
  hil_tuning_B.Clock_j = hil_tuning_M->Timing.t[0];

  /* Sum: '<S3>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S3>/startTime'
   */
  hil_tuning_B.Sum_ks = hil_tuning_B.Clock_j - (0.0);

  /* Math: '<S3>/Math Function' incorporates:
   *  Constant: '<S3>/Constant'
   */
  hil_tuning_B.MathFunction_l = rt_remd_snf(hil_tuning_B.Sum_ks,
    hil_tuning_P.Constant_Value_p);

  /* Lookup_n-D: '<S3>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_j = look1_binlxpw(hil_tuning_B.MathFunction_l,
    hil_tuning_P.LookUpTable1_bp01Data_d, hil_tuning_P.left_ankle, 39U);

  /* SignalConversion: '<S3>/Output' */
  hil_tuning_B.Output_d = hil_tuning_B.LookUpTable1_j;

  /* Clock: '<S4>/Clock' */
  hil_tuning_B.Clock_h = hil_tuning_M->Timing.t[0];

  /* Sum: '<S4>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S4>/startTime'
   */
  hil_tuning_B.Sum_m = hil_tuning_B.Clock_h - (0.0);

  /* Math: '<S4>/Math Function' incorporates:
   *  Constant: '<S4>/Constant'
   */
  hil_tuning_B.MathFunction_a = rt_remd_snf(hil_tuning_B.Sum_m,
    hil_tuning_P.Constant_Value_g);

  /* Lookup_n-D: '<S4>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_jw = look1_binlxpw(hil_tuning_B.MathFunction_a,
    hil_tuning_P.LookUpTable1_bp01Data_l, hil_tuning_P.left_hip, 39U);

  /* SignalConversion: '<S4>/Output' */
  hil_tuning_B.Output_i = hil_tuning_B.LookUpTable1_jw;

  /* Clock: '<S5>/Clock' */
  hil_tuning_B.Clock_l = hil_tuning_M->Timing.t[0];

  /* Sum: '<S5>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S5>/startTime'
   */
  hil_tuning_B.Sum_g = hil_tuning_B.Clock_l - (0.0);

  /* Math: '<S5>/Math Function' incorporates:
   *  Constant: '<S5>/Constant'
   */
  hil_tuning_B.MathFunction_o = rt_remd_snf(hil_tuning_B.Sum_g,
    hil_tuning_P.Constant_Value_h);

  /* Lookup_n-D: '<S5>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_i = look1_binlxpw(hil_tuning_B.MathFunction_o,
    hil_tuning_P.LookUpTable1_bp01Data_g, hil_tuning_P.left_knee, 39U);

  /* SignalConversion: '<S5>/Output' */
  hil_tuning_B.Output_o = hil_tuning_B.LookUpTable1_i;

  /* Clock: '<S6>/Clock' */
  hil_tuning_B.Clock_i = hil_tuning_M->Timing.t[0];

  /* Sum: '<S6>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S6>/startTime'
   */
  hil_tuning_B.Sum_e = hil_tuning_B.Clock_i - (0.0);

  /* Math: '<S6>/Math Function' incorporates:
   *  Constant: '<S6>/Constant'
   */
  hil_tuning_B.MathFunction_e = rt_remd_snf(hil_tuning_B.Sum_e,
    hil_tuning_P.Constant_Value_gs);

  /* Lookup_n-D: '<S6>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_b = look1_binlxpw(hil_tuning_B.MathFunction_e,
    hil_tuning_P.LookUpTable1_bp01Data_gm, hil_tuning_P.left_rotation, 39U);

  /* SignalConversion: '<S6>/Output' */
  hil_tuning_B.Output_iv = hil_tuning_B.LookUpTable1_b;

  /* Clock: '<S7>/Clock' */
  hil_tuning_B.Clock_f = hil_tuning_M->Timing.t[0];

  /* Sum: '<S7>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S7>/startTime'
   */
  hil_tuning_B.Sum_j = hil_tuning_B.Clock_f - (0.0);

  /* Math: '<S7>/Math Function' incorporates:
   *  Constant: '<S7>/Constant'
   */
  hil_tuning_B.MathFunction_f = rt_remd_snf(hil_tuning_B.Sum_j,
    hil_tuning_P.Constant_Value_gsv);

  /* Lookup_n-D: '<S7>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_o = look1_binlxpw(hil_tuning_B.MathFunction_f,
    hil_tuning_P.LookUpTable1_bp01Data_nh, hil_tuning_P.right_abduction, 39U);

  /* SignalConversion: '<S7>/Output' */
  hil_tuning_B.Output_k = hil_tuning_B.LookUpTable1_o;

  /* Clock: '<S8>/Clock' */
  hil_tuning_B.Clock_p = hil_tuning_M->Timing.t[0];

  /* Sum: '<S8>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S8>/startTime'
   */
  hil_tuning_B.Sum_l = hil_tuning_B.Clock_p - (0.0);

  /* Math: '<S8>/Math Function' incorporates:
   *  Constant: '<S8>/Constant'
   */
  hil_tuning_B.MathFunction_d = rt_remd_snf(hil_tuning_B.Sum_l,
    hil_tuning_P.Constant_Value_a);

  /* Lookup_n-D: '<S8>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_m = look1_binlxpw(hil_tuning_B.MathFunction_d,
    hil_tuning_P.LookUpTable1_bp01Data_e, hil_tuning_P.right_knee_twist, 39U);

  /* SignalConversion: '<S8>/Output' */
  hil_tuning_B.Output_h = hil_tuning_B.LookUpTable1_m;

  /* Clock: '<S9>/Clock' */
  hil_tuning_B.Clock_fy = hil_tuning_M->Timing.t[0];

  /* Sum: '<S9>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S9>/startTime'
   */
  hil_tuning_B.Sum_b = hil_tuning_B.Clock_fy - (0.0);

  /* Math: '<S9>/Math Function' incorporates:
   *  Constant: '<S9>/Constant'
   */
  hil_tuning_B.MathFunction_h = rt_remd_snf(hil_tuning_B.Sum_b,
    hil_tuning_P.Constant_Value_f);

  /* Lookup_n-D: '<S9>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_jt = look1_binlxpw(hil_tuning_B.MathFunction_h,
    hil_tuning_P.LookUpTable1_bp01Data_b, hil_tuning_P.right_ankle, 39U);

  /* SignalConversion: '<S9>/Output' */
  hil_tuning_B.Output_f = hil_tuning_B.LookUpTable1_jt;

  /* Clock: '<S10>/Clock' */
  hil_tuning_B.Clock_io = hil_tuning_M->Timing.t[0];

  /* Sum: '<S10>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S10>/startTime'
   */
  hil_tuning_B.Sum_kw = hil_tuning_B.Clock_io - (0.0);

  /* Math: '<S10>/Math Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  hil_tuning_B.MathFunction_b = rt_remd_snf(hil_tuning_B.Sum_kw,
    hil_tuning_P.Constant_Value_kd);

  /* Lookup_n-D: '<S10>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_f = look1_binlxpw(hil_tuning_B.MathFunction_b,
    hil_tuning_P.LookUpTable1_bp01Data_k, hil_tuning_P.right_hip, 39U);

  /* SignalConversion: '<S10>/Output' */
  hil_tuning_B.Output_i5 = hil_tuning_B.LookUpTable1_f;

  /* Clock: '<S11>/Clock' */
  hil_tuning_B.Clock_l0 = hil_tuning_M->Timing.t[0];

  /* Sum: '<S11>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S11>/startTime'
   */
  hil_tuning_B.Sum_p = hil_tuning_B.Clock_l0 - (0.0);

  /* Math: '<S11>/Math Function' incorporates:
   *  Constant: '<S11>/Constant'
   */
  hil_tuning_B.MathFunction_n = rt_remd_snf(hil_tuning_B.Sum_p,
    hil_tuning_P.Constant_Value_m);

  /* Lookup_n-D: '<S11>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_fg = look1_binlxpw(hil_tuning_B.MathFunction_n,
    hil_tuning_P.LookUpTable1_bp01Data_h, hil_tuning_P.right_knee, 39U);

  /* SignalConversion: '<S11>/Output' */
  hil_tuning_B.Output_o4 = hil_tuning_B.LookUpTable1_fg;

  /* Clock: '<S12>/Clock' */
  hil_tuning_B.Clock_n = hil_tuning_M->Timing.t[0];

  /* Sum: '<S12>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S12>/startTime'
   */
  hil_tuning_B.Sum_eg = hil_tuning_B.Clock_n - (0.0);

  /* Math: '<S12>/Math Function' incorporates:
   *  Constant: '<S12>/Constant'
   */
  hil_tuning_B.MathFunction_i = rt_remd_snf(hil_tuning_B.Sum_eg,
    hil_tuning_P.Constant_Value_gd);

  /* Lookup_n-D: '<S12>/Look-Up Table1' */
  hil_tuning_B.LookUpTable1_p = look1_binlxpw(hil_tuning_B.MathFunction_i,
    hil_tuning_P.LookUpTable1_bp01Data_p, hil_tuning_P.right_rotation, 39U);

  /* SignalConversion: '<S12>/Output' */
  hil_tuning_B.Output_p = hil_tuning_B.LookUpTable1_p;

  /* Gain: '<S13>/Gain' */
  hil_tuning_B.Gain = hil_tuning_P.Gain_Gain * hil_tuning_B.Output_p;

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<Root>/rotation_tune'
   *  Constant: '<S13>/Constant'
   */
  hil_tuning_B.Add = (hil_tuning_B.Gain + hil_tuning_P.Constant_Value_b) +
    hil_tuning_P.rotation_tune_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion' */

  /* Gain: '<S15>/Gain' */
  hil_tuning_B.Gain_g = hil_tuning_P.Gain_Gain_g * hil_tuning_B.Output_k;

  /* Sum: '<S15>/Add' incorporates:
   *  Constant: '<Root>/abduction_tune'
   *  Constant: '<S15>/Constant'
   */
  hil_tuning_B.Add_f = (hil_tuning_B.Gain_g + hil_tuning_P.Constant_Value_i) +
    hil_tuning_P.abduction_tune_Value;

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_g = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S15>/Data Type Conversion' */

  /* Gain: '<S14>/Gain' */
  hil_tuning_B.Gain_m = hil_tuning_P.Gain_Gain_f * hil_tuning_B.Output_i5;

  /* Sum: '<S14>/Add' incorporates:
   *  Constant: '<Root>/hip_tune'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   */
  hil_tuning_B.Add_a = ((hil_tuning_B.Gain_m + hil_tuning_P.Constant_Value_pf) -
                        hil_tuning_P.Constant1_Value) +
    hil_tuning_P.hip_tune_Value;

  /* DataTypeConversion: '<S14>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_a);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_e = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

  /* Gain: '<S16>/Gain' */
  hil_tuning_B.Gain_f = hil_tuning_P.Gain_Gain_k * hil_tuning_B.Output_o4;

  /* Sum: '<S16>/Add' incorporates:
   *  Constant: '<Root>/knee_tune'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S16>/Constant1'
   */
  hil_tuning_B.Add_c = ((hil_tuning_B.Gain_f + hil_tuning_P.Constant_Value_e) -
                        hil_tuning_P.Constant1_Value_e) +
    hil_tuning_P.knee_tune_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_c);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_j = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

  /* Gain: '<S24>/Gain' */
  hil_tuning_B.Gain_j = hil_tuning_P.Gain_Gain_j * hil_tuning_B.Output_f;

  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<Root>/ankle_tune'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S24>/Constant1'
   */
  hil_tuning_B.Add_k = ((hil_tuning_B.Gain_j + hil_tuning_P.Constant_Value_l) -
                        hil_tuning_P.Constant1_Value_k) +
    hil_tuning_P.ankle_tune_Value;

  /* DataTypeConversion: '<S24>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_k);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_i = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S24>/Data Type Conversion' */

  /* Gain: '<S23>/Gain' */
  hil_tuning_B.Gain_my = hil_tuning_P.Gain_Gain_a * hil_tuning_B.Output_h;

  /* Sum: '<S23>/Add' incorporates:
   *  Constant: '<Root>/ankle_twist_tune'
   *  Constant: '<S23>/Constant'
   */
  hil_tuning_B.Add_cb = (hil_tuning_B.Gain_my + hil_tuning_P.Constant_Value_ij)
    + hil_tuning_P.ankle_twist_tune_Value;

  /* DataTypeConversion: '<S23>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_cb);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_n = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S23>/Data Type Conversion' */

  /* Gain: '<S22>/Gain' */
  hil_tuning_B.Gain_fl = hil_tuning_P.Gain_Gain_d * hil_tuning_B.Output_iv;

  /* Sum: '<S22>/Add' incorporates:
   *  Constant: '<Root>/rotation_tune'
   *  Constant: '<S22>/Constant'
   */
  hil_tuning_B.Add_g = (hil_tuning_B.Gain_fl + hil_tuning_P.Constant_Value_d) -
    hil_tuning_P.rotation_tune_Value;

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_g);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_a = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S22>/Data Type Conversion' */

  /* Gain: '<S21>/Gain' */
  hil_tuning_B.Gain_c = hil_tuning_P.Gain_Gain_n * hil_tuning_B.Output;

  /* Sum: '<S21>/Add' incorporates:
   *  Constant: '<Root>/abduction_tune'
   *  Constant: '<S21>/Constant'
   */
  hil_tuning_B.Add_o = (hil_tuning_B.Gain_c + hil_tuning_P.Constant_Value_gdr) -
    hil_tuning_P.abduction_tune_Value;

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_o);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_ji = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S21>/Data Type Conversion' */

  /* Gain: '<S20>/Gain' */
  hil_tuning_B.Gain_e = hil_tuning_P.Gain_Gain_kd * hil_tuning_B.Output_i;

  /* Sum: '<S20>/Add' incorporates:
   *  Constant: '<Root>/hip_tune'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   */
  hil_tuning_B.Add_d = ((hil_tuning_B.Gain_e + hil_tuning_P.Constant_Value_pk) -
                        hil_tuning_P.Constant1_Value_g) +
    hil_tuning_P.hip_tune_Value;

  /* DataTypeConversion: '<S20>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_d);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_k = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S20>/Data Type Conversion' */

  /* Gain: '<S19>/Gain' */
  hil_tuning_B.Gain_k = hil_tuning_P.Gain_Gain_j0 * hil_tuning_B.Output_o;

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<Root>/knee_tune'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   */
  hil_tuning_B.Add_h = ((hil_tuning_B.Gain_k + hil_tuning_P.Constant_Value_pr) -
                        hil_tuning_P.Constant1_Value_gr) +
    hil_tuning_P.knee_tune_Value;

  /* DataTypeConversion: '<S19>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_h);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_o = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S19>/Data Type Conversion' */

  /* Gain: '<S18>/Gain' */
  hil_tuning_B.Gain_d = hil_tuning_P.Gain_Gain_jv * hil_tuning_B.Output_d;

  /* Sum: '<S18>/Add' incorporates:
   *  Constant: '<Root>/ankle_tune'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   */
  hil_tuning_B.Add_ca = ((hil_tuning_B.Gain_d + hil_tuning_P.Constant_Value_mw)
    - hil_tuning_P.Constant1_Value_a) + hil_tuning_P.ankle_tune_Value;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_ca);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_l = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S18>/Data Type Conversion' */

  /* Gain: '<S17>/Gain' */
  hil_tuning_B.Gain_eb = hil_tuning_P.Gain_Gain_au * hil_tuning_B.Output_a;

  /* Sum: '<S17>/Add' incorporates:
   *  Constant: '<Root>/ankle_twist_tune'
   *  Constant: '<S17>/Constant'
   */
  hil_tuning_B.Add_j = (hil_tuning_B.Gain_eb + hil_tuning_P.Constant_Value_iy) -
    hil_tuning_P.ankle_twist_tune_Value;

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  tmp = floor(hil_tuning_B.Add_j);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  hil_tuning_B.DataTypeConversion_b = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S17>/Data Type Conversion' */

  /* S-Function (asciiencode): '<Root>/ASCII Encode 2' */

  /* Level2 S-Function Block: '<Root>/ASCII Encode 2' (asciiencode) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[3];
    sfcnOutputs(rts,1);
  }

  /* Constant: '<Root>/Constant3' */
  hil_tuning_B.Constant3 = hil_tuning_P.Constant3_Value;

  /* S-Function (slrtUDPSend): '<Root>/UDP Send' */

  /* Level2 S-Function Block: '<Root>/UDP Send' (slrtUDPSend) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[4];
    sfcnOutputs(rts,1);
  }
}

/* Model update function */
static void hil_tuning_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++hil_tuning_M->Timing.clockTick0)) {
    ++hil_tuning_M->Timing.clockTickH0;
  }

  hil_tuning_M->Timing.t[0] = hil_tuning_M->Timing.clockTick0 *
    hil_tuning_M->Timing.stepSize0 + hil_tuning_M->Timing.clockTickH0 *
    hil_tuning_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++hil_tuning_M->Timing.clockTick1)) {
      ++hil_tuning_M->Timing.clockTickH1;
    }

    hil_tuning_M->Timing.t[1] = hil_tuning_M->Timing.clockTick1 *
      hil_tuning_M->Timing.stepSize1 + hil_tuning_M->Timing.clockTickH1 *
      hil_tuning_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void hil_tuning_initialize(void)
{
  /* Start for S-Function (slrtIPConfig): '<Root>/UDP Configure' */
  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (slrtUDPReceive): '<Root>/UDP Receive' */
  /* Level2 S-Function Block: '<Root>/UDP Receive' (slrtUDPReceive) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (asciidecode): '<Root>/ASCII Decode ' */
  /* Level2 S-Function Block: '<Root>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (asciiencode): '<Root>/ASCII Encode 2' */
  /* Level2 S-Function Block: '<Root>/ASCII Encode 2' (asciiencode) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant3' */
  hil_tuning_B.Constant3 = hil_tuning_P.Constant3_Value;

  /* Start for S-Function (slrtUDPSend): '<Root>/UDP Send' */
  /* Level2 S-Function Block: '<Root>/UDP Send' (slrtUDPSend) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void hil_tuning_terminate(void)
{
  /* Terminate for S-Function (slrtIPConfig): '<Root>/UDP Configure' */
  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (slrtUDPReceive): '<Root>/UDP Receive' */
  /* Level2 S-Function Block: '<Root>/UDP Receive' (slrtUDPReceive) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (asciidecode): '<Root>/ASCII Decode ' */
  /* Level2 S-Function Block: '<Root>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (asciiencode): '<Root>/ASCII Encode 2' */
  /* Level2 S-Function Block: '<Root>/ASCII Encode 2' (asciiencode) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (slrtUDPSend): '<Root>/UDP Send' */
  /* Level2 S-Function Block: '<Root>/UDP Send' (slrtUDPSend) */
  {
    SimStruct *rts = hil_tuning_M->childSfunctions[4];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  hil_tuning_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  hil_tuning_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  hil_tuning_initialize();
}

void MdlTerminate(void)
{
  hil_tuning_terminate();
}

/* Registration function */
RT_MODEL_hil_tuning_T *hil_tuning(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)hil_tuning_M, 0,
                sizeof(RT_MODEL_hil_tuning_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&hil_tuning_M->solverInfo,
                          &hil_tuning_M->Timing.simTimeStep);
    rtsiSetTPtr(&hil_tuning_M->solverInfo, &rtmGetTPtr(hil_tuning_M));
    rtsiSetStepSizePtr(&hil_tuning_M->solverInfo,
                       &hil_tuning_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&hil_tuning_M->solverInfo, (&rtmGetErrorStatus
      (hil_tuning_M)));
    rtsiSetRTModelPtr(&hil_tuning_M->solverInfo, hil_tuning_M);
  }

  rtsiSetSimTimeStep(&hil_tuning_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&hil_tuning_M->solverInfo,"FixedStepDiscrete");
  hil_tuning_M->solverInfoPtr = (&hil_tuning_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = hil_tuning_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    hil_tuning_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    hil_tuning_M->Timing.sampleTimes = (&hil_tuning_M->Timing.sampleTimesArray[0]);
    hil_tuning_M->Timing.offsetTimes = (&hil_tuning_M->Timing.offsetTimesArray[0]);

    /* task periods */
    hil_tuning_M->Timing.sampleTimes[0] = (0.0);
    hil_tuning_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    hil_tuning_M->Timing.offsetTimes[0] = (0.0);
    hil_tuning_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(hil_tuning_M, &hil_tuning_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = hil_tuning_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    hil_tuning_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(hil_tuning_M, -1);
  hil_tuning_M->Timing.stepSize0 = 0.001;
  hil_tuning_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    hil_tuning_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(hil_tuning_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(hil_tuning_M->rtwLogInfo, (NULL));
    rtliSetLogT(hil_tuning_M->rtwLogInfo, "tout");
    rtliSetLogX(hil_tuning_M->rtwLogInfo, "");
    rtliSetLogXFinal(hil_tuning_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(hil_tuning_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(hil_tuning_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(hil_tuning_M->rtwLogInfo, 0);
    rtliSetLogDecimation(hil_tuning_M->rtwLogInfo, 1);
    rtliSetLogY(hil_tuning_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(hil_tuning_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(hil_tuning_M->rtwLogInfo, (NULL));
  }

  hil_tuning_M->solverInfoPtr = (&hil_tuning_M->solverInfo);
  hil_tuning_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&hil_tuning_M->solverInfo, 0.001);
  rtsiSetSolverMode(&hil_tuning_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  hil_tuning_M->blockIO = ((void *) &hil_tuning_B);
  (void) memset(((void *) &hil_tuning_B), 0,
                sizeof(B_hil_tuning_T));

  /* parameters */
  hil_tuning_M->defaultParam = ((real_T *)&hil_tuning_P);

  /* states (dwork) */
  hil_tuning_M->dwork = ((void *) &hil_tuning_DW);
  (void) memset((void *)&hil_tuning_DW, 0,
                sizeof(DW_hil_tuning_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  hil_tuning_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &hil_tuning_M->NonInlinedSFcns.sfcnInfo;
    hil_tuning_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(hil_tuning_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &hil_tuning_M->Sizes.numSampTimes);
    hil_tuning_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(hil_tuning_M)[0]);
    hil_tuning_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(hil_tuning_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,hil_tuning_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(hil_tuning_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(hil_tuning_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(hil_tuning_M));
    rtssSetStepSizePtr(sfcnInfo, &hil_tuning_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(hil_tuning_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &hil_tuning_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &hil_tuning_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &hil_tuning_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &hil_tuning_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &hil_tuning_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &hil_tuning_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &hil_tuning_M->solverInfoPtr);
  }

  hil_tuning_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)&hil_tuning_M->NonInlinedSFcns.childSFunctions[0], 0,
                  5*sizeof(SimStruct));
    hil_tuning_M->childSfunctions =
      (&hil_tuning_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        hil_tuning_M->childSfunctions[i] =
          (&hil_tuning_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: hil_tuning/<Root>/UDP Configure (slrtIPConfig) */
    {
      SimStruct *rts = hil_tuning_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = hil_tuning_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = hil_tuning_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = hil_tuning_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &hil_tuning_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &hil_tuning_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, hil_tuning_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &hil_tuning_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &hil_tuning_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &hil_tuning_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &hil_tuning_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &hil_tuning_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "UDP Configure");
      ssSetPath(rts, "hil_tuning/UDP Configure");
      ssSetRTModel(rts,hil_tuning_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &hil_tuning_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)hil_tuning_P.UDPConfigure_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)hil_tuning_P.UDPConfigure_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)hil_tuning_P.UDPConfigure_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)hil_tuning_P.UDPConfigure_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)hil_tuning_P.UDPConfigure_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)hil_tuning_P.UDPConfigure_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)hil_tuning_P.UDPConfigure_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)hil_tuning_P.UDPConfigure_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)hil_tuning_P.UDPConfigure_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)hil_tuning_P.UDPConfigure_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)hil_tuning_P.UDPConfigure_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)hil_tuning_P.UDPConfigure_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &hil_tuning_DW.UDPConfigure_IWORK[0]);
      ssSetPWork(rts, (void **) &hil_tuning_DW.UDPConfigure_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &hil_tuning_DW.UDPConfigure_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &hil_tuning_DW.UDPConfigure_PWORK[0]);
      }

      /* registration */
      slrtIPConfig(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: hil_tuning/<Root>/UDP Receive (slrtUDPReceive) */
    {
      SimStruct *rts = hil_tuning_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = hil_tuning_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = hil_tuning_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = hil_tuning_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &hil_tuning_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &hil_tuning_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, hil_tuning_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &hil_tuning_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &hil_tuning_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &hil_tuning_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &hil_tuning_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &hil_tuning_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 128);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) hil_tuning_B.UDPReceive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &hil_tuning_B.UDPReceive_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Receive");
      ssSetPath(rts, "hil_tuning/UDP Receive");
      ssSetRTModel(rts,hil_tuning_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &hil_tuning_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)hil_tuning_P.UDPReceive_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)hil_tuning_P.UDPReceive_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)hil_tuning_P.UDPReceive_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)hil_tuning_P.UDPReceive_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)hil_tuning_P.UDPReceive_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)hil_tuning_P.UDPReceive_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)hil_tuning_P.UDPReceive_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)hil_tuning_P.UDPReceive_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)hil_tuning_P.UDPReceive_P9_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &hil_tuning_DW.UDPReceive_IWORK[0]);
      ssSetPWork(rts, (void **) &hil_tuning_DW.UDPReceive_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &hil_tuning_DW.UDPReceive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &hil_tuning_DW.UDPReceive_PWORK[0]);
      }

      /* registration */
      slrtUDPReceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: hil_tuning/<Root>/ASCII Decode  (asciidecode) */
    {
      SimStruct *rts = hil_tuning_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = hil_tuning_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = hil_tuning_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = hil_tuning_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &hil_tuning_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &hil_tuning_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, hil_tuning_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &hil_tuning_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &hil_tuning_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &hil_tuning_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &hil_tuning_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &hil_tuning_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, hil_tuning_B.UDPReceive_o1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 128);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 12);
        _ssSetPortInfo2ForOutputUnits(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        ssSetOutputPortUnit(rts, 7, 0);
        ssSetOutputPortUnit(rts, 8, 0);
        ssSetOutputPortUnit(rts, 9, 0);
        ssSetOutputPortUnit(rts, 10, 0);
        ssSetOutputPortUnit(rts, 11, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 6, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 7, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 8, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 9, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 10, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 11, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((uint32_T *)
            &hil_tuning_B.ASCIIDecode_o12));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Decode ");
      ssSetPath(rts, "hil_tuning/ASCII Decode ");
      ssSetRTModel(rts,hil_tuning_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)hil_tuning_P.ASCIIDecode_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)hil_tuning_P.ASCIIDecode_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)hil_tuning_P.ASCIIDecode_P3_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &hil_tuning_DW.ASCIIDecode_IWORK[0]);
      ssSetPWork(rts, (void **) &hil_tuning_DW.ASCIIDecode_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &hil_tuning_DW.ASCIIDecode_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &hil_tuning_DW.ASCIIDecode_PWORK[0]);
      }

      /* registration */
      asciidecode(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 128);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: hil_tuning/<Root>/ASCII Encode 2 (asciiencode) */
    {
      SimStruct *rts = hil_tuning_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = hil_tuning_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = hil_tuning_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = hil_tuning_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &hil_tuning_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &hil_tuning_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, hil_tuning_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &hil_tuning_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &hil_tuning_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &hil_tuning_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &hil_tuning_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &hil_tuning_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 12);
        ssSetPortInfoForInputs(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        ssSetInputPortUnit(rts, 4, 0);
        ssSetInputPortUnit(rts, 5, 0);
        ssSetInputPortUnit(rts, 6, 0);
        ssSetInputPortUnit(rts, 7, 0);
        ssSetInputPortUnit(rts, 8, 0);
        ssSetInputPortUnit(rts, 9, 0);
        ssSetInputPortUnit(rts, 10, 0);
        ssSetInputPortUnit(rts, 11, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);
        ssSetInputPortIsContinuousQuantity(rts, 4, 0);
        ssSetInputPortIsContinuousQuantity(rts, 5, 0);
        ssSetInputPortIsContinuousQuantity(rts, 6, 0);
        ssSetInputPortIsContinuousQuantity(rts, 7, 0);
        ssSetInputPortIsContinuousQuantity(rts, 8, 0);
        ssSetInputPortIsContinuousQuantity(rts, 9, 0);
        ssSetInputPortIsContinuousQuantity(rts, 10, 0);
        ssSetInputPortIsContinuousQuantity(rts, 11, 0);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_g;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_e;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_j;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_i;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_n;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_a;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_ji;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }

        /* port 8 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs8;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_k;
          ssSetInputPortSignalPtrs(rts, 8, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 1);
        }

        /* port 9 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs9;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_o;
          ssSetInputPortSignalPtrs(rts, 9, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 9, 1);
          ssSetInputPortWidth(rts, 9, 1);
        }

        /* port 10 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs10;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_l;
          ssSetInputPortSignalPtrs(rts, 10, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 1);
        }

        /* port 11 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &hil_tuning_M->NonInlinedSFcns.Sfcn3.UPtrs11;
          sfcnUPtrs[0] = &hil_tuning_B.DataTypeConversion_b;
          ssSetInputPortSignalPtrs(rts, 11, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 128);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) hil_tuning_B.ASCIIEncode2));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Encode 2");
      ssSetPath(rts, "hil_tuning/ASCII Encode 2");
      ssSetRTModel(rts,hil_tuning_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)hil_tuning_P.ASCIIEncode2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)hil_tuning_P.ASCIIEncode2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)hil_tuning_P.ASCIIEncode2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)hil_tuning_P.ASCIIEncode2_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &hil_tuning_DW.ASCIIEncode2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &hil_tuning_DW.ASCIIEncode2_PWORK);
      }

      /* registration */
      asciiencode(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);
      _ssSetInputPortConnected(rts, 8, 1);
      _ssSetInputPortConnected(rts, 9, 1);
      _ssSetInputPortConnected(rts, 10, 1);
      _ssSetInputPortConnected(rts, 11, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
      ssSetInputPortBufferDstPort(rts, 8, -1);
      ssSetInputPortBufferDstPort(rts, 9, -1);
      ssSetInputPortBufferDstPort(rts, 10, -1);
      ssSetInputPortBufferDstPort(rts, 11, -1);
    }

    /* Level2 S-Function Block: hil_tuning/<Root>/UDP Send (slrtUDPSend) */
    {
      SimStruct *rts = hil_tuning_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = hil_tuning_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = hil_tuning_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = hil_tuning_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &hil_tuning_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &hil_tuning_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, hil_tuning_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &hil_tuning_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &hil_tuning_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &hil_tuning_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &hil_tuning_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &hil_tuning_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &hil_tuning_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, hil_tuning_B.ASCIIEncode2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 128);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &hil_tuning_B.Constant3);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Send");
      ssSetPath(rts, "hil_tuning/UDP Send");
      ssSetRTModel(rts,hil_tuning_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &hil_tuning_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)hil_tuning_P.UDPSend_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)hil_tuning_P.UDPSend_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)hil_tuning_P.UDPSend_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)hil_tuning_P.UDPSend_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)hil_tuning_P.UDPSend_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)hil_tuning_P.UDPSend_P6_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &hil_tuning_DW.UDPSend_IWORK[0]);
      ssSetPWork(rts, (void **) &hil_tuning_DW.UDPSend_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &hil_tuning_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &hil_tuning_DW.UDPSend_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &hil_tuning_DW.UDPSend_PWORK);
      }

      /* registration */
      slrtUDPSend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 128);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  hil_tuning_M->Sizes.numContStates = (0);/* Number of continuous states */
  hil_tuning_M->Sizes.numY = (0);      /* Number of model outputs */
  hil_tuning_M->Sizes.numU = (0);      /* Number of model inputs */
  hil_tuning_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  hil_tuning_M->Sizes.numSampTimes = (2);/* Number of sample times */
  hil_tuning_M->Sizes.numBlocks = (166);/* Number of blocks */
  hil_tuning_M->Sizes.numBlockIO = (112);/* Number of block outputs */
  hil_tuning_M->Sizes.numBlockPrms = (1250);/* Sum of parameter "widths" */
  return hil_tuning_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
