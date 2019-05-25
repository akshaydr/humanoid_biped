/*
 * Copy_of_Robot_leg_3_0.c
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

#include "rt_logging_mmi.h"
#include "Copy_of_Robot_leg_3_0_capi.h"
#include "Copy_of_Robot_leg_3_0.h"
#include "Copy_of_Robot_leg_3_0_private.h"

/* Block signals (default storage) */
B_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_B;

/* Continuous states */
X_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_X;

/* Block states (default storage) */
DW_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_Y;

/* Real-time model */
RT_MODEL_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_M_;
RT_MODEL_Copy_of_Robot_leg_3_0_T *const Copy_of_Robot_leg_3_0_M =
  &Copy_of_Robot_leg_3_0_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
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
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

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

/* Projection for root system: '<Root>' */
void Copy_of_Robot_leg_3_0_projection(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[432];
  int_T tmp_1[109];
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;

  /* Projection for SimscapeExecutionBlock: '<S583>/STATE_1' */
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_SimulationData;
  time = Copy_of_Robot_leg_3_0_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX = (real_T *)
    &Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0x6_DOF_Joi;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Copy_of_Robot_leg_3_0_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Copy_of_Robot_leg_3_0_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[0];
  tmp_0[1] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[1];
  tmp_0[2] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[2];
  tmp_0[3] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[0];
  tmp_0[5] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[1];
  tmp_0[6] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[2];
  tmp_0[7] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[0];
  tmp_0[9] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[1];
  tmp_0[10] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[2];
  tmp_0[11] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[0];
  tmp_0[13] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[1];
  tmp_0[14] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[2];
  tmp_0[15] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[0];
  tmp_0[17] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[1];
  tmp_0[18] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[2];
  tmp_0[19] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[0];
  tmp_0[21] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[1];
  tmp_0[22] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[2];
  tmp_0[23] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[0];
  tmp_0[25] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[1];
  tmp_0[26] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[2];
  tmp_0[27] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[0];
  tmp_0[29] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[1];
  tmp_0[30] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[2];
  tmp_0[31] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[3];
  tmp_1[8] = 32;
  tmp_0[32] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[0];
  tmp_0[33] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[1];
  tmp_0[34] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[2];
  tmp_0[35] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[3];
  tmp_1[9] = 36;
  tmp_0[36] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[0];
  tmp_0[37] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[1];
  tmp_0[38] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[2];
  tmp_0[39] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[3];
  tmp_1[10] = 40;
  tmp_0[40] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[0];
  tmp_0[41] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[1];
  tmp_0[42] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[2];
  tmp_0[43] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[3];
  tmp_1[11] = 44;
  tmp_0[44] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[0];
  tmp_0[45] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[1];
  tmp_0[46] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[2];
  tmp_0[47] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[3];
  tmp_1[12] = 48;
  tmp_0[48] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[0];
  tmp_0[49] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[1];
  tmp_0[50] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[2];
  tmp_0[51] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[3];
  tmp_1[13] = 52;
  tmp_0[52] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[0];
  tmp_0[53] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[1];
  tmp_0[54] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[2];
  tmp_0[55] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[3];
  tmp_1[14] = 56;
  tmp_0[56] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[0];
  tmp_0[57] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[1];
  tmp_0[58] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[2];
  tmp_0[59] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[3];
  tmp_1[15] = 60;
  tmp_0[60] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[0];
  tmp_0[61] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[1];
  tmp_0[62] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[2];
  tmp_0[63] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[3];
  tmp_1[16] = 64;
  tmp_0[64] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[0];
  tmp_0[65] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[1];
  tmp_0[66] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[2];
  tmp_0[67] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[3];
  tmp_1[17] = 68;
  tmp_0[68] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[0];
  tmp_0[69] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[1];
  tmp_0[70] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[2];
  tmp_0[71] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[3];
  tmp_1[18] = 72;
  tmp_0[72] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[0];
  tmp_0[73] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[1];
  tmp_0[74] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[2];
  tmp_0[75] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[3];
  tmp_1[19] = 76;
  tmp_0[76] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[0];
  tmp_0[77] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[1];
  tmp_0[78] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[2];
  tmp_0[79] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[3];
  tmp_1[20] = 80;
  tmp_0[80] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[0];
  tmp_0[81] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[1];
  tmp_0[82] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[2];
  tmp_0[83] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[3];
  tmp_1[21] = 84;
  tmp_0[84] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[0];
  tmp_0[85] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[1];
  tmp_0[86] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[2];
  tmp_0[87] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[3];
  tmp_1[22] = 88;
  tmp_0[88] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[0];
  tmp_0[89] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[1];
  tmp_0[90] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[2];
  tmp_0[91] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[3];
  tmp_1[23] = 92;
  tmp_0[92] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[0];
  tmp_0[93] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[1];
  tmp_0[94] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[2];
  tmp_0[95] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[3];
  tmp_1[24] = 96;
  tmp_0[96] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[0];
  tmp_0[97] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[1];
  tmp_0[98] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[2];
  tmp_0[99] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[3];
  tmp_1[25] = 100;
  tmp_0[100] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[0];
  tmp_0[101] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[1];
  tmp_0[102] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[2];
  tmp_0[103] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[3];
  tmp_1[26] = 104;
  tmp_0[104] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[0];
  tmp_0[105] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[1];
  tmp_0[106] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[2];
  tmp_0[107] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[3];
  tmp_1[27] = 108;
  tmp_0[108] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[0];
  tmp_0[109] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[1];
  tmp_0[110] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[2];
  tmp_0[111] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[3];
  tmp_1[28] = 112;
  tmp_0[112] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[0];
  tmp_0[113] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[1];
  tmp_0[114] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[2];
  tmp_0[115] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[3];
  tmp_1[29] = 116;
  tmp_0[116] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[0];
  tmp_0[117] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[1];
  tmp_0[118] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[2];
  tmp_0[119] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[3];
  tmp_1[30] = 120;
  tmp_0[120] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[0];
  tmp_0[121] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[1];
  tmp_0[122] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[2];
  tmp_0[123] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[3];
  tmp_1[31] = 124;
  tmp_0[124] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[0];
  tmp_0[125] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[1];
  tmp_0[126] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[2];
  tmp_0[127] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[3];
  tmp_1[32] = 128;
  tmp_0[128] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[0];
  tmp_0[129] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[1];
  tmp_0[130] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[2];
  tmp_0[131] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[3];
  tmp_1[33] = 132;
  tmp_0[132] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[0];
  tmp_0[133] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[1];
  tmp_0[134] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[2];
  tmp_0[135] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[3];
  tmp_1[34] = 136;
  tmp_0[136] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[0];
  tmp_0[137] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[1];
  tmp_0[138] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[2];
  tmp_0[139] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[3];
  tmp_1[35] = 140;
  tmp_0[140] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[0];
  tmp_0[141] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[1];
  tmp_0[142] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[2];
  tmp_0[143] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[3];
  tmp_1[36] = 144;
  tmp_0[144] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[0];
  tmp_0[145] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[1];
  tmp_0[146] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[2];
  tmp_0[147] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[3];
  tmp_1[37] = 148;
  tmp_0[148] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[0];
  tmp_0[149] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[1];
  tmp_0[150] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[2];
  tmp_0[151] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[3];
  tmp_1[38] = 152;
  tmp_0[152] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[0];
  tmp_0[153] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[1];
  tmp_0[154] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[2];
  tmp_0[155] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[3];
  tmp_1[39] = 156;
  tmp_0[156] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[0];
  tmp_0[157] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[1];
  tmp_0[158] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[2];
  tmp_0[159] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[3];
  tmp_1[40] = 160;
  tmp_0[160] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[0];
  tmp_0[161] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[1];
  tmp_0[162] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[2];
  tmp_0[163] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[3];
  tmp_1[41] = 164;
  tmp_0[164] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[0];
  tmp_0[165] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[1];
  tmp_0[166] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[2];
  tmp_0[167] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[3];
  tmp_1[42] = 168;
  tmp_0[168] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[0];
  tmp_0[169] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[1];
  tmp_0[170] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[2];
  tmp_0[171] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[3];
  tmp_1[43] = 172;
  tmp_0[172] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[0];
  tmp_0[173] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[1];
  tmp_0[174] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[2];
  tmp_0[175] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[3];
  tmp_1[44] = 176;
  tmp_0[176] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[0];
  tmp_0[177] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[1];
  tmp_0[178] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[2];
  tmp_0[179] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[3];
  tmp_1[45] = 180;
  tmp_0[180] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[0];
  tmp_0[181] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[1];
  tmp_0[182] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[2];
  tmp_0[183] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[3];
  tmp_1[46] = 184;
  tmp_0[184] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[0];
  tmp_0[185] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[1];
  tmp_0[186] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[2];
  tmp_0[187] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[3];
  tmp_1[47] = 188;
  tmp_0[188] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[0];
  tmp_0[189] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[1];
  tmp_0[190] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[2];
  tmp_0[191] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[3];
  tmp_1[48] = 192;
  tmp_0[192] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[0];
  tmp_0[193] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[1];
  tmp_0[194] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[2];
  tmp_0[195] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[3];
  tmp_1[49] = 196;
  tmp_0[196] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[0];
  tmp_0[197] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[1];
  tmp_0[198] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[2];
  tmp_0[199] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[3];
  tmp_1[50] = 200;
  tmp_0[200] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[0];
  tmp_0[201] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[1];
  tmp_0[202] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[2];
  tmp_0[203] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[3];
  tmp_1[51] = 204;
  tmp_0[204] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[0];
  tmp_0[205] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[1];
  tmp_0[206] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[2];
  tmp_0[207] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[3];
  tmp_1[52] = 208;
  tmp_0[208] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[0];
  tmp_0[209] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[1];
  tmp_0[210] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[2];
  tmp_0[211] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[3];
  tmp_1[53] = 212;
  tmp_0[212] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[0];
  tmp_0[213] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[1];
  tmp_0[214] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[2];
  tmp_0[215] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[3];
  tmp_1[54] = 216;
  tmp_0[216] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[0];
  tmp_0[217] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[1];
  tmp_0[218] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[2];
  tmp_0[219] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[3];
  tmp_1[55] = 220;
  tmp_0[220] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[0];
  tmp_0[221] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[1];
  tmp_0[222] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[2];
  tmp_0[223] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[3];
  tmp_1[56] = 224;
  tmp_0[224] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[0];
  tmp_0[225] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[1];
  tmp_0[226] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[2];
  tmp_0[227] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[3];
  tmp_1[57] = 228;
  tmp_0[228] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[0];
  tmp_0[229] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[1];
  tmp_0[230] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[2];
  tmp_0[231] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[3];
  tmp_1[58] = 232;
  tmp_0[232] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[0];
  tmp_0[233] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[1];
  tmp_0[234] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[2];
  tmp_0[235] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[3];
  tmp_1[59] = 236;
  tmp_0[236] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[0];
  tmp_0[237] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[1];
  tmp_0[238] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[2];
  tmp_0[239] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[3];
  tmp_1[60] = 240;
  tmp_0[240] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[0];
  tmp_0[241] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[1];
  tmp_0[242] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[2];
  tmp_0[243] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[3];
  tmp_1[61] = 244;
  tmp_0[244] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[0];
  tmp_0[245] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[1];
  tmp_0[246] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[2];
  tmp_0[247] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[3];
  tmp_1[62] = 248;
  tmp_0[248] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[0];
  tmp_0[249] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[1];
  tmp_0[250] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[2];
  tmp_0[251] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[3];
  tmp_1[63] = 252;
  tmp_0[252] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[0];
  tmp_0[253] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[1];
  tmp_0[254] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[2];
  tmp_0[255] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[3];
  tmp_1[64] = 256;
  tmp_0[256] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[0];
  tmp_0[257] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[1];
  tmp_0[258] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[2];
  tmp_0[259] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[3];
  tmp_1[65] = 260;
  tmp_0[260] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[0];
  tmp_0[261] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[1];
  tmp_0[262] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[2];
  tmp_0[263] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[3];
  tmp_1[66] = 264;
  tmp_0[264] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[0];
  tmp_0[265] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[1];
  tmp_0[266] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[2];
  tmp_0[267] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[3];
  tmp_1[67] = 268;
  tmp_0[268] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[0];
  tmp_0[269] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[1];
  tmp_0[270] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[2];
  tmp_0[271] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[3];
  tmp_1[68] = 272;
  tmp_0[272] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[0];
  tmp_0[273] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[1];
  tmp_0[274] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[2];
  tmp_0[275] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[3];
  tmp_1[69] = 276;
  tmp_0[276] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[0];
  tmp_0[277] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[1];
  tmp_0[278] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[2];
  tmp_0[279] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[3];
  tmp_1[70] = 280;
  tmp_0[280] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[0];
  tmp_0[281] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[1];
  tmp_0[282] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[2];
  tmp_0[283] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[3];
  tmp_1[71] = 284;
  tmp_0[284] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[0];
  tmp_0[285] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[1];
  tmp_0[286] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[2];
  tmp_0[287] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[3];
  tmp_1[72] = 288;
  tmp_0[288] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[0];
  tmp_0[289] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[1];
  tmp_0[290] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[2];
  tmp_0[291] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[3];
  tmp_1[73] = 292;
  tmp_0[292] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[0];
  tmp_0[293] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[1];
  tmp_0[294] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[2];
  tmp_0[295] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[3];
  tmp_1[74] = 296;
  tmp_0[296] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[0];
  tmp_0[297] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[1];
  tmp_0[298] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[2];
  tmp_0[299] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[3];
  tmp_1[75] = 300;
  tmp_0[300] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[0];
  tmp_0[301] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[1];
  tmp_0[302] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[2];
  tmp_0[303] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[3];
  tmp_1[76] = 304;
  tmp_0[304] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[0];
  tmp_0[305] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[1];
  tmp_0[306] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[2];
  tmp_0[307] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[3];
  tmp_1[77] = 308;
  tmp_0[308] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[0];
  tmp_0[309] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[1];
  tmp_0[310] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[2];
  tmp_0[311] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[3];
  tmp_1[78] = 312;
  tmp_0[312] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[0];
  tmp_0[313] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[1];
  tmp_0[314] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[2];
  tmp_0[315] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[3];
  tmp_1[79] = 316;
  tmp_0[316] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[0];
  tmp_0[317] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[1];
  tmp_0[318] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[2];
  tmp_0[319] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[3];
  tmp_1[80] = 320;
  tmp_0[320] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[0];
  tmp_0[321] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[1];
  tmp_0[322] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[2];
  tmp_0[323] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[3];
  tmp_1[81] = 324;
  tmp_0[324] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[0];
  tmp_0[325] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[1];
  tmp_0[326] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[2];
  tmp_0[327] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[3];
  tmp_1[82] = 328;
  tmp_0[328] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[0];
  tmp_0[329] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[1];
  tmp_0[330] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[2];
  tmp_0[331] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[3];
  tmp_1[83] = 332;
  tmp_0[332] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[0];
  tmp_0[333] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[1];
  tmp_0[334] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[2];
  tmp_0[335] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[3];
  tmp_1[84] = 336;
  tmp_0[336] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[0];
  tmp_0[337] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[1];
  tmp_0[338] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[2];
  tmp_0[339] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[3];
  tmp_1[85] = 340;
  tmp_0[340] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[0];
  tmp_0[341] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[1];
  tmp_0[342] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[2];
  tmp_0[343] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[3];
  tmp_1[86] = 344;
  tmp_0[344] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[0];
  tmp_0[345] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[1];
  tmp_0[346] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[2];
  tmp_0[347] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[3];
  tmp_1[87] = 348;
  tmp_0[348] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[0];
  tmp_0[349] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[1];
  tmp_0[350] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[2];
  tmp_0[351] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[3];
  tmp_1[88] = 352;
  tmp_0[352] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[0];
  tmp_0[353] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[1];
  tmp_0[354] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[2];
  tmp_0[355] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[3];
  tmp_1[89] = 356;
  tmp_0[356] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[0];
  tmp_0[357] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[1];
  tmp_0[358] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[2];
  tmp_0[359] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[3];
  tmp_1[90] = 360;
  tmp_0[360] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[0];
  tmp_0[361] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[1];
  tmp_0[362] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[2];
  tmp_0[363] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[3];
  tmp_1[91] = 364;
  tmp_0[364] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[0];
  tmp_0[365] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[1];
  tmp_0[366] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[2];
  tmp_0[367] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[3];
  tmp_1[92] = 368;
  tmp_0[368] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[0];
  tmp_0[369] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[1];
  tmp_0[370] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[2];
  tmp_0[371] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[3];
  tmp_1[93] = 372;
  tmp_0[372] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[0];
  tmp_0[373] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[1];
  tmp_0[374] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[2];
  tmp_0[375] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[3];
  tmp_1[94] = 376;
  tmp_0[376] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[0];
  tmp_0[377] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[1];
  tmp_0[378] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[2];
  tmp_0[379] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[3];
  tmp_1[95] = 380;
  tmp_0[380] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[0];
  tmp_0[381] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[1];
  tmp_0[382] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[2];
  tmp_0[383] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[3];
  tmp_1[96] = 384;
  tmp_0[384] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[0];
  tmp_0[385] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[1];
  tmp_0[386] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[2];
  tmp_0[387] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[3];
  tmp_1[97] = 388;
  tmp_0[388] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[0];
  tmp_0[389] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[1];
  tmp_0[390] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[2];
  tmp_0[391] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[3];
  tmp_1[98] = 392;
  tmp_0[392] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[0];
  tmp_0[393] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[1];
  tmp_0[394] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[2];
  tmp_0[395] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[3];
  tmp_1[99] = 396;
  tmp_0[396] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[0];
  tmp_0[397] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[1];
  tmp_0[398] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[2];
  tmp_0[399] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[3];
  tmp_1[100] = 400;
  tmp_0[400] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[0];
  tmp_0[401] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[1];
  tmp_0[402] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[2];
  tmp_0[403] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[3];
  tmp_1[101] = 404;
  tmp_0[404] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[0];
  tmp_0[405] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[1];
  tmp_0[406] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[2];
  tmp_0[407] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[3];
  tmp_1[102] = 408;
  tmp_0[408] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[0];
  tmp_0[409] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[1];
  tmp_0[410] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[2];
  tmp_0[411] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[3];
  tmp_1[103] = 412;
  tmp_0[412] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[0];
  tmp_0[413] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[1];
  tmp_0[414] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[2];
  tmp_0[415] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[3];
  tmp_1[104] = 416;
  tmp_0[416] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[0];
  tmp_0[417] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[1];
  tmp_0[418] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[2];
  tmp_0[419] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[3];
  tmp_1[105] = 420;
  tmp_0[420] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[0];
  tmp_0[421] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[1];
  tmp_0[422] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[2];
  tmp_0[423] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[3];
  tmp_1[106] = 424;
  tmp_0[424] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[0];
  tmp_0[425] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[1];
  tmp_0[426] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[2];
  tmp_0[427] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[3];
  tmp_1[107] = 428;
  tmp_0[428] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[0];
  tmp_0[429] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[1];
  tmp_0[430] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[2];
  tmp_0[431] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[3];
  tmp_1[108] = 432;
  simulationData->mData->mInputValues.mN = 432;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 109;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method(simulator, NESL_SIM_PROJECTION, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S583>/STATE_1' */
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 37;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Copy_of_Robot_leg_3_0_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Copy_of_Robot_leg_3_0_output();
  Copy_of_Robot_leg_3_0_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Copy_of_Robot_leg_3_0_output();
  Copy_of_Robot_leg_3_0_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  Copy_of_Robot_leg_3_0_output();
  Copy_of_Robot_leg_3_0_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for action system:
 *    '<S4>/Switch Case Action Subsystem'
 *    '<S4>/Switch Case Action Subsystem1'
 */
void SwitchCaseActionSubsystem_Init(B_SwitchCaseActionSubsystem_C_T *localB,
  P_SwitchCaseActionSubsystem_C_T *localP)
{
  int32_T i;

  /* SystemInitialize for Outport: '<S42>/Out1' */
  for (i = 0; i < 6; i++) {
    localB->In1[i] = localP->Out1_Y0;
  }

  /* End of SystemInitialize for Outport: '<S42>/Out1' */
}

/*
 * Output and update for action system:
 *    '<S4>/Switch Case Action Subsystem'
 *    '<S4>/Switch Case Action Subsystem1'
 */
void Copy__SwitchCaseActionSubsystem(real_T rtu_In1, real_T rtu_In1_j, real_T
  rtu_In1_m, real_T rtu_In1_f, real_T rtu_In1_o, real_T rtu_In1_oq,
  B_SwitchCaseActionSubsystem_C_T *localB)
{
  /* Inport: '<S42>/In1' */
  localB->In1[0] = rtu_In1;
  localB->In1[1] = rtu_In1_j;
  localB->In1[2] = rtu_In1_m;
  localB->In1[3] = rtu_In1_f;
  localB->In1[4] = rtu_In1_o;
  localB->In1[5] = rtu_In1_oq;
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

      /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
      if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }

      /* End of DiscretePulseGenerator: '<S4>/Pulse Generator' */
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void rt_mldivide_U1d3x3_U2d_9O8lG8ax(const real_T u0[9], const real_T u1[3],
  real_T y[3])
{
  real_T u0_0[9];
  int32_T ONE;
  int32_T THREE;
  int32_T r1;
  int32_T r2;
  real_T maxval;
  real_T a21;
  real_T y_0;
  real_T u0_1;
  for (THREE = 0; THREE < 9; THREE++) {
    u0_1 = u0[THREE];
    u0_0[THREE] = u0_1;
  }

  THREE = 2;
  r1 = 0;
  r2 = 1;
  u0_1 = u0_0[0];
  y_0 = fabs(u0_1);
  maxval = y_0;
  u0_1 = u0_0[1];
  y_0 = fabs(u0_1);
  a21 = y_0;
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  u0_1 = u0_0[2];
  y_0 = fabs(u0_1);
  a21 = y_0;
  if (a21 > maxval) {
    r1 = 2;
    r2 = 1;
    THREE = 0;
  }

  u0_1 = u0_0[r2];
  y_0 = u0_0[r1];
  maxval = u0_1 / y_0;
  u0_0[r2] = maxval;
  u0_1 = u0_0[THREE];
  y_0 = u0_0[r1];
  maxval = u0_1 / y_0;
  u0_0[THREE] = maxval;
  u0_0[3 + r2] -= u0_0[3 + r1] * u0_0[r2];
  u0_0[3 + THREE] -= u0_0[3 + r1] * u0_0[THREE];
  u0_0[6 + r2] -= u0_0[6 + r1] * u0_0[r2];
  u0_0[6 + THREE] -= u0_0[6 + r1] * u0_0[THREE];
  u0_1 = u0_0[3 + THREE];
  y_0 = fabs(u0_1);
  a21 = y_0;
  u0_1 = u0_0[3 + r2];
  y_0 = fabs(u0_1);
  maxval = y_0;
  if (a21 > maxval) {
    ONE = r2 + 1;
    r2 = THREE;
    THREE = ONE - 1;
  }

  u0_1 = u0_0[3 + THREE];
  y_0 = u0_0[3 + r2];
  maxval = u0_1 / y_0;
  u0_0[3 + THREE] = maxval;
  u0_0[6 + THREE] -= u0_0[3 + THREE] * u0_0[6 + r2];
  y[0] = u1[r1];
  y[1] = u1[r2] - y[0] * u0_0[r2];
  y[2] = (u1[THREE] - y[0] * u0_0[THREE]) - u0_0[3 + THREE] * y[1];
  u0_1 = y[2];
  y_0 = u0_0[6 + THREE];
  maxval = u0_1 / y_0;
  y[2] = maxval;
  y[0] -= u0_0[6 + r1] * y[2];
  y[1] -= u0_0[6 + r2] * y[2];
  u0_1 = y[1];
  y_0 = u0_0[3 + r2];
  maxval = u0_1 / y_0;
  y[1] = maxval;
  y[0] -= u0_0[3 + r1] * y[1];
  u0_1 = y[0];
  y_0 = u0_0[r1];
  maxval = u0_1 / y_0;
  y[0] = maxval;
  y_0 = y[0];
  y[0] = y_0;
  y_0 = y[1];
  y[1] = y_0;
  y_0 = y[2];
  y[2] = y_0;
}

/* Model output function */
void Copy_of_Robot_leg_3_0_output(void)
{
  boolean_T first_output;
  NeslSimulationData *simulationData;
  real_T time;
  real_T tmp[432];
  int_T tmp_0[109];
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_1;
  char *msg;
  real_T time_0;
  real_T tmp_2[445];
  int_T tmp_3[110];
  real_T time_1;
  real_T tmp_4[445];
  int_T tmp_5[110];
  real_T pulseWidth;
  real_T diff;
  real_T ratio;
  uint32_T numCycles;
  int8_T rtAction;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    /* set solver stop time */
    if (!(Copy_of_Robot_leg_3_0_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Copy_of_Robot_leg_3_0_M->solverInfo,
                            ((Copy_of_Robot_leg_3_0_M->Timing.clockTickH0 + 1) *
        Copy_of_Robot_leg_3_0_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Copy_of_Robot_leg_3_0_M->solverInfo,
                            ((Copy_of_Robot_leg_3_0_M->Timing.clockTick0 + 1) *
        Copy_of_Robot_leg_3_0_M->Timing.stepSize0 +
        Copy_of_Robot_leg_3_0_M->Timing.clockTickH0 *
        Copy_of_Robot_leg_3_0_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    Copy_of_Robot_leg_3_0_M->Timing.t[0] = rtsiGetT
      (&Copy_of_Robot_leg_3_0_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_iy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_is);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_l);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_b);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_i);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_i);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_o);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_d);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_b);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_e);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_p);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (Copy_of_Robot_leg_3_0_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy);

  /* Clock: '<S572>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S572>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S572>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum = Copy_of_Robot_leg_3_0_B.Clock - (0.0);

  /* Math: '<S572>/Math Function' incorporates:
   *  Constant: '<S572>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction = rt_remd_snf(Copy_of_Robot_leg_3_0_B.Sum,
    Copy_of_Robot_leg_3_0_P.Constant_Value);

  /* Lookup_n-D: '<S572>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1 = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data,
     Copy_of_Robot_leg_3_0_P.left_theta_3, 39U);

  /* SignalConversion: '<S572>/Output' */
  Copy_of_Robot_leg_3_0_B.Output = Copy_of_Robot_leg_3_0_B.LookUpTable1;

  /* SimscapeInputBlock: '<S583>/INPUT_3_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_3_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_3_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[0] =
      Copy_of_Robot_leg_3_0_B.Output;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[0];
  Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[1];
  Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Output -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_3_1_1' */

  /* Clock: '<S4>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_b = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
  if (Copy_of_Robot_leg_3_0_B.Clock_b >=
      Copy_of_Robot_leg_3_0_P.PulseGenerator_PhaseDelay) {
    pulseWidth = Copy_of_Robot_leg_3_0_P.PulseGenerator_Duty / 100.0 *
      Copy_of_Robot_leg_3_0_P.PulseGenerator_Period;
    diff = Copy_of_Robot_leg_3_0_B.Clock_b -
      Copy_of_Robot_leg_3_0_P.PulseGenerator_PhaseDelay;
    ratio = diff / Copy_of_Robot_leg_3_0_P.PulseGenerator_Period;
    numCycles = (uint32_T)floor(ratio);
    if (fabs((real_T)(numCycles + 1U) - ratio) < DBL_EPSILON * ratio) {
      numCycles++;
    }

    if (diff < Copy_of_Robot_leg_3_0_P.PulseGenerator_Period * (real_T)numCycles
        + pulseWidth) {
      Copy_of_Robot_leg_3_0_B.PulseGenerator =
        Copy_of_Robot_leg_3_0_P.PulseGenerator_Amp;
    } else {
      Copy_of_Robot_leg_3_0_B.PulseGenerator = 0.0;
    }
  } else {
    Copy_of_Robot_leg_3_0_B.PulseGenerator = 0.0;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator' */

  /* TransportDelay: '<S4>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &Copy_of_Robot_leg_3_0_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &Copy_of_Robot_leg_3_0_DW.TransportDelay_PWORK.TUbufferPtrs[3];
    real_T simTime = Copy_of_Robot_leg_3_0_M->Timing.t[0];
    real_T tMinusDelay ;

    {
      int_T i1;
      real_T *y0 = &Copy_of_Robot_leg_3_0_B.TransportDelay[0];
      int_T *iw_Tail = &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[0];
      int_T *iw_Head = &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0];
      int_T *iw_Last = &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Last[0];
      int_T *iw_CircularBufSize =
        &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[0];
      for (i1=0; i1 < 3; i1++) {
        tMinusDelay = ((Copy_of_Robot_leg_3_0_P.TransportDelay_Delay > 0.0) ?
                       Copy_of_Robot_leg_3_0_P.TransportDelay_Delay : 0.0);
        tMinusDelay = simTime - tMinusDelay;
        y0[i1] = rt_TDelayInterpolate(
          tMinusDelay,
          0.0,
          *tBuffer,
          *uBuffer,
          iw_CircularBufSize[i1],
          &iw_Last[i1],
          iw_Tail[i1],
          iw_Head[i1],
          Copy_of_Robot_leg_3_0_P.TransportDelay_InitOutput,
          0,
          0);
        tBuffer++;
        uBuffer++;
      }
    }
  }

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add[0] = Copy_of_Robot_leg_3_0_B.TransportDelay[0] -
    Copy_of_Robot_leg_3_0_P.Constant_Value_l;
  Copy_of_Robot_leg_3_0_B.Add[1] = Copy_of_Robot_leg_3_0_B.TransportDelay[1] -
    Copy_of_Robot_leg_3_0_P.Constant_Value_l;
  Copy_of_Robot_leg_3_0_B.Add[2] = Copy_of_Robot_leg_3_0_B.TransportDelay[2] -
    Copy_of_Robot_leg_3_0_P.Constant_Value_l;

  /* Gain: '<S15>/Gain2' */
  Copy_of_Robot_leg_3_0_B.Gain2 = Copy_of_Robot_leg_3_0_P.Gain2_Gain_ax *
    Copy_of_Robot_leg_3_0_B.Add[2];

  /* Gain: '<S15>/Gain5' */
  Copy_of_Robot_leg_3_0_B.Gain5 = Copy_of_Robot_leg_3_0_P.Gain5_Gain *
    Copy_of_Robot_leg_3_0_B.Gain2;

  /* Gain: '<S15>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1 = Copy_of_Robot_leg_3_0_P.Gain1_Gain *
    Copy_of_Robot_leg_3_0_B.Add[1];

  /* Gain: '<S15>/Gain4' */
  Copy_of_Robot_leg_3_0_B.Gain4 = Copy_of_Robot_leg_3_0_P.Gain4_Gain *
    Copy_of_Robot_leg_3_0_B.Gain1;

  /* Gain: '<S15>/Gain3' */
  Copy_of_Robot_leg_3_0_B.Gain3 = Copy_of_Robot_leg_3_0_P.Gain3_Gain *
    Copy_of_Robot_leg_3_0_B.Add[0];

  /* Gain: '<S15>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain = Copy_of_Robot_leg_3_0_P.Gain_Gain_ap *
    Copy_of_Robot_leg_3_0_B.Gain3;

  /* Gain: '<S24>/Gain2' */
  Copy_of_Robot_leg_3_0_B.Gain2_f = Copy_of_Robot_leg_3_0_P.Gain2_Gain_aq *
    Copy_of_Robot_leg_3_0_B.Add[2];

  /* Gain: '<S24>/Gain5' */
  Copy_of_Robot_leg_3_0_B.Gain5_n = Copy_of_Robot_leg_3_0_P.Gain5_Gain_m *
    Copy_of_Robot_leg_3_0_B.Gain2_f;

  /* Gain: '<S24>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_g = Copy_of_Robot_leg_3_0_P.Gain1_Gain_f *
    Copy_of_Robot_leg_3_0_B.Add[1];

  /* Gain: '<S24>/Gain4' */
  Copy_of_Robot_leg_3_0_B.Gain4_o = Copy_of_Robot_leg_3_0_P.Gain4_Gain_n *
    Copy_of_Robot_leg_3_0_B.Gain1_g;

  /* Gain: '<S24>/Gain3' */
  Copy_of_Robot_leg_3_0_B.Gain3_a = Copy_of_Robot_leg_3_0_P.Gain3_Gain_i *
    Copy_of_Robot_leg_3_0_B.Add[0];

  /* Gain: '<S24>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_e = Copy_of_Robot_leg_3_0_P.Gain_Gain_no *
    Copy_of_Robot_leg_3_0_B.Gain3_a;

  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  Constant: '<S15>/Constant6'
   *  Constant: '<S15>/Constant7'
   *  Constant: '<S15>/Constant8'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S24>/Constant2'
   */
  rtAction = -1;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    pulseWidth = Copy_of_Robot_leg_3_0_B.PulseGenerator;
    if (pulseWidth < 0.0) {
      pulseWidth = ceil(pulseWidth);
    } else {
      pulseWidth = floor(pulseWidth);
    }

    if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
      pulseWidth = 0.0;
    } else {
      pulseWidth = fmod(pulseWidth, 4.294967296E+9);
    }

    switch (pulseWidth < 0.0 ? -(int32_T)(uint32_T)-pulseWidth : (int32_T)
            (uint32_T)pulseWidth) {
     case 1:
      rtAction = 0;
      break;

     case 0:
      rtAction = 1;
      break;
    }

    Copy_of_Robot_leg_3_0_DW.SwitchCase_ActiveSubsystem = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.SwitchCase_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    Copy__SwitchCaseActionSubsystem(Copy_of_Robot_leg_3_0_B.Gain_e,
      Copy_of_Robot_leg_3_0_B.Gain4_o, Copy_of_Robot_leg_3_0_B.Gain5_n,
      Copy_of_Robot_leg_3_0_P.Constant_Value_m,
      Copy_of_Robot_leg_3_0_P.Constant1_Value,
      Copy_of_Robot_leg_3_0_P.Constant2_Value,
      &Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem);
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC
        (Copy_of_Robot_leg_3_0_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy);
    }

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    Copy__SwitchCaseActionSubsystem(Copy_of_Robot_leg_3_0_P.Constant6_Value,
      Copy_of_Robot_leg_3_0_P.Constant7_Value,
      Copy_of_Robot_leg_3_0_P.Constant8_Value, Copy_of_Robot_leg_3_0_B.Gain,
      Copy_of_Robot_leg_3_0_B.Gain4, Copy_of_Robot_leg_3_0_B.Gain5,
      &Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1);
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC
        (Copy_of_Robot_leg_3_0_DW.SwitchCaseActionSubsystem1.SwitchCaseActionSubsystem_Subsy);
    }

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem1' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* Clock: '<S574>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_n = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S574>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S574>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_i = Copy_of_Robot_leg_3_0_B.Clock_n - (0.0);

  /* Math: '<S574>/Math Function' incorporates:
   *  Constant: '<S574>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_p = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_i, Copy_of_Robot_leg_3_0_P.Constant_Value_a);

  /* Lookup_n-D: '<S574>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_p = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_p,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_l,
     Copy_of_Robot_leg_3_0_P.left_theta_1, 39U);

  /* SignalConversion: '<S574>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_f = Copy_of_Robot_leg_3_0_B.LookUpTable1_p;

  /* Sum: '<S29>/Add4' */
  Copy_of_Robot_leg_3_0_B.Add4 =
    (Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem.In1[3] +
     Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1.In1[3]) +
    Copy_of_Robot_leg_3_0_B.Output_f;

  /* SimscapeInputBlock: '<S583>/INPUT_2_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_2_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_2_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[0] =
      Copy_of_Robot_leg_3_0_B.Add4;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[0];
  Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[1];
  Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Add4 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_2_1_1' */

  /* Clock: '<S575>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_e = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S575>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S575>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_c = Copy_of_Robot_leg_3_0_B.Clock_e - (0.0);

  /* Math: '<S575>/Math Function' incorporates:
   *  Constant: '<S575>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_m = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_c, Copy_of_Robot_leg_3_0_P.Constant_Value_c);

  /* Lookup_n-D: '<S575>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_h = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_m,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_i,
     Copy_of_Robot_leg_3_0_P.left_theta_2, 39U);

  /* SignalConversion: '<S575>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_d = Copy_of_Robot_leg_3_0_B.LookUpTable1_h;

  /* SimscapeInputBlock: '<S583>/INPUT_1_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_1_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_1_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[0] =
      Copy_of_Robot_leg_3_0_B.Output_d;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[0];
  Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[1];
  Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Output_d -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_1_1_1' */

  /* Clock: '<S571>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_eu = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S571>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S571>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_a = Copy_of_Robot_leg_3_0_B.Clock_eu - (0.0);

  /* Math: '<S571>/Math Function' incorporates:
   *  Constant: '<S571>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_d = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_a, Copy_of_Robot_leg_3_0_P.Constant_Value_i);

  /* Lookup_n-D: '<S571>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_j = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_d,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_f,
     Copy_of_Robot_leg_3_0_P.left_theta_5, 39U);

  /* SignalConversion: '<S571>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_j = Copy_of_Robot_leg_3_0_B.LookUpTable1_j;

  /* Sum: '<S29>/Add5' */
  Copy_of_Robot_leg_3_0_B.Add5 =
    (Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem.In1[4] +
     Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1.In1[4]) +
    Copy_of_Robot_leg_3_0_B.Output_j;

  /* SimscapeInputBlock: '<S583>/INPUT_6_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_6_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_6_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[0] =
      Copy_of_Robot_leg_3_0_B.Add5;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[0];
  Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[1];
  Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Add5 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_6_1_1' */

  /* Clock: '<S573>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_n0 = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S573>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S573>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_f = Copy_of_Robot_leg_3_0_B.Clock_n0 - (0.0);

  /* Math: '<S573>/Math Function' incorporates:
   *  Constant: '<S573>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_dn = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_f, Copy_of_Robot_leg_3_0_P.Constant_Value_ah);

  /* Lookup_n-D: '<S573>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_jm = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_dn,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_n,
     Copy_of_Robot_leg_3_0_P.left_theta_4, 39U);

  /* SignalConversion: '<S573>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_o = Copy_of_Robot_leg_3_0_B.LookUpTable1_jm;

  /* SimscapeInputBlock: '<S583>/INPUT_4_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_4_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_4_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[0] =
      Copy_of_Robot_leg_3_0_B.Output_o;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[0];
  Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[1];
  Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Output_o -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_4_1_1' */

  /* Clock: '<S576>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_euk = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S576>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S576>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_fb = Copy_of_Robot_leg_3_0_B.Clock_euk - (0.0);

  /* Math: '<S576>/Math Function' incorporates:
   *  Constant: '<S576>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_a = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_fb, Copy_of_Robot_leg_3_0_P.Constant_Value_b);

  /* Lookup_n-D: '<S576>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_e = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_a,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_d,
     Copy_of_Robot_leg_3_0_P.left_theta_6, 39U);

  /* SignalConversion: '<S576>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_jd = Copy_of_Robot_leg_3_0_B.LookUpTable1_e;

  /* Sum: '<S29>/Add6' */
  Copy_of_Robot_leg_3_0_B.Add6 =
    (Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem.In1[5] +
     Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1.In1[5]) +
    Copy_of_Robot_leg_3_0_B.Output_jd;

  /* SimscapeInputBlock: '<S583>/INPUT_5_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_5_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_5_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[0] =
      Copy_of_Robot_leg_3_0_B.Add6;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[0];
  Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[1];
  Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Add6 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_5_1_1' */

  /* Clock: '<S577>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_ny = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S577>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S577>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_e = Copy_of_Robot_leg_3_0_B.Clock_ny - (0.0);

  /* Math: '<S577>/Math Function' incorporates:
   *  Constant: '<S577>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_dy = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_e, Copy_of_Robot_leg_3_0_P.Constant_Value_k);

  /* Lookup_n-D: '<S577>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_d = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_dy,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_k,
     Copy_of_Robot_leg_3_0_P.right_theta_5, 39U);

  /* SignalConversion: '<S577>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_h = Copy_of_Robot_leg_3_0_B.LookUpTable1_d;

  /* Sum: '<S29>/Add2' */
  Copy_of_Robot_leg_3_0_B.Add2 = (Copy_of_Robot_leg_3_0_B.Output_h +
    Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem.In1[1]) +
    Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1.In1[1];

  /* SimscapeInputBlock: '<S583>/INPUT_28_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_28_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_28_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[0] =
      Copy_of_Robot_leg_3_0_B.Add2;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[0];
  Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[1];
  Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Add2 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_28_1_1' */

  /* Clock: '<S578>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_ev = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S578>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S578>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_cc = Copy_of_Robot_leg_3_0_B.Clock_ev - (0.0);

  /* Math: '<S578>/Math Function' incorporates:
   *  Constant: '<S578>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_pp = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_cc, Copy_of_Robot_leg_3_0_P.Constant_Value_h);

  /* Lookup_n-D: '<S578>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_hj = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_pp,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_kg,
     Copy_of_Robot_leg_3_0_P.right_theta_3, 39U);

  /* SignalConversion: '<S578>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_hw = Copy_of_Robot_leg_3_0_B.LookUpTable1_hj;

  /* SimscapeInputBlock: '<S583>/INPUT_25_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_25_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_25_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[0] =
      Copy_of_Robot_leg_3_0_B.Output_hw;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[0];
  Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[1];
  Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Output_hw
    - Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_25_1_1' */

  /* Clock: '<S579>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_p = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S579>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S579>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_k = Copy_of_Robot_leg_3_0_B.Clock_p - (0.0);

  /* Math: '<S579>/Math Function' incorporates:
   *  Constant: '<S579>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_h = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_k, Copy_of_Robot_leg_3_0_P.Constant_Value_j);

  /* Lookup_n-D: '<S579>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_dv = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_h,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_j,
     Copy_of_Robot_leg_3_0_P.right_theta_4, 39U);

  /* SignalConversion: '<S579>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_p = Copy_of_Robot_leg_3_0_B.LookUpTable1_dv;

  /* SimscapeInputBlock: '<S583>/INPUT_26_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_26_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_26_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[0] =
      Copy_of_Robot_leg_3_0_B.Output_p;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[0];
  Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[1];
  Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Output_p -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_26_1_1' */

  /* Clock: '<S580>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_bo = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S580>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S580>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_l = Copy_of_Robot_leg_3_0_B.Clock_bo - (0.0);

  /* Math: '<S580>/Math Function' incorporates:
   *  Constant: '<S580>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_c = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_l, Copy_of_Robot_leg_3_0_P.Constant_Value_cw);

  /* Lookup_n-D: '<S580>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_c = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_c,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_p,
     Copy_of_Robot_leg_3_0_P.right_theta_1, 39U);

  /* SignalConversion: '<S580>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_fa = Copy_of_Robot_leg_3_0_B.LookUpTable1_c;

  /* Sum: '<S29>/Add1' */
  Copy_of_Robot_leg_3_0_B.Add1 = (Copy_of_Robot_leg_3_0_B.Output_fa +
    Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem.In1[0]) +
    Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1.In1[0];

  /* SimscapeInputBlock: '<S583>/INPUT_24_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_24_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_24_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[0] =
      Copy_of_Robot_leg_3_0_B.Add1;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[0];
  Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[1];
  Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Add1 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_24_1_1' */

  /* Clock: '<S581>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_l = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S581>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S581>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_ff = Copy_of_Robot_leg_3_0_B.Clock_l - (0.0);

  /* Math: '<S581>/Math Function' incorporates:
   *  Constant: '<S581>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_l = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_ff, Copy_of_Robot_leg_3_0_P.Constant_Value_o);

  /* Lookup_n-D: '<S581>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_k = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_l,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_m,
     Copy_of_Robot_leg_3_0_P.right_theta_2, 39U);

  /* SignalConversion: '<S581>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_g = Copy_of_Robot_leg_3_0_B.LookUpTable1_k;

  /* SimscapeInputBlock: '<S583>/INPUT_23_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_23_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_23_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[0] =
      Copy_of_Robot_leg_3_0_B.Output_g;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[0];
  Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[1];
  Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Output_g -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_23_1_1' */

  /* Clock: '<S582>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_a = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S582>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S582>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_p = Copy_of_Robot_leg_3_0_B.Clock_a - (0.0);

  /* Math: '<S582>/Math Function' incorporates:
   *  Constant: '<S582>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_h5 = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_p, Copy_of_Robot_leg_3_0_P.Constant_Value_bu);

  /* Lookup_n-D: '<S582>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_l = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_h5,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_b,
     Copy_of_Robot_leg_3_0_P.right_theta_6, 39U);

  /* SignalConversion: '<S582>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_ds = Copy_of_Robot_leg_3_0_B.LookUpTable1_l;

  /* Sum: '<S29>/Add3' */
  Copy_of_Robot_leg_3_0_B.Add3 = (Copy_of_Robot_leg_3_0_B.Output_ds +
    Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem.In1[2]) +
    Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1.In1[2];

  /* SimscapeInputBlock: '<S583>/INPUT_27_1_1' */
  first_output = false;
  if (Copy_of_Robot_leg_3_0_DW.INPUT_27_1_1_discrete[0] == 0.0) {
    Copy_of_Robot_leg_3_0_DW.INPUT_27_1_1_discrete[0] = 1.0;
    first_output = true;
  }

  if (first_output) {
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[0] =
      Copy_of_Robot_leg_3_0_B.Add3;
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[1] = 0.0;
  }

  Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[0];
  Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[1] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[1];
  Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[2] = ((Copy_of_Robot_leg_3_0_B.Add3 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[1]) * 100.0;
  Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S583>/INPUT_27_1_1' */

  /* SimscapeExecutionBlock: '<S583>/STATE_1' */
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_SimulationData;
  time = Copy_of_Robot_leg_3_0_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX = (real_T *)
    &Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0x6_DOF_Joi;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  first_output = false;
  simulationData->mData->mFoundZcEvents = first_output;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Copy_of_Robot_leg_3_0_M);
  first_output = false;
  simulationData->mData->mIsSolverAssertCheck = first_output;
  simulationData->mData->mIsSolverCheckingCIC = false;
  first_output = rtsiIsSolverComputingJacobian
    (&Copy_of_Robot_leg_3_0_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = first_output;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_0[0] = 0;
  tmp[0] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[0];
  tmp[1] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[1];
  tmp[2] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[2];
  tmp[3] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[3];
  tmp_0[1] = 4;
  tmp[4] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[0];
  tmp[5] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[1];
  tmp[6] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[2];
  tmp[7] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[3];
  tmp_0[2] = 8;
  tmp[8] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[0];
  tmp[9] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[1];
  tmp[10] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[2];
  tmp[11] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[3];
  tmp_0[3] = 12;
  tmp[12] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[0];
  tmp[13] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[1];
  tmp[14] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[2];
  tmp[15] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[3];
  tmp_0[4] = 16;
  tmp[16] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[0];
  tmp[17] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[1];
  tmp[18] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[2];
  tmp[19] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[3];
  tmp_0[5] = 20;
  tmp[20] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[0];
  tmp[21] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[1];
  tmp[22] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[2];
  tmp[23] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[3];
  tmp_0[6] = 24;
  tmp[24] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[0];
  tmp[25] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[1];
  tmp[26] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[2];
  tmp[27] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[3];
  tmp_0[7] = 28;
  tmp[28] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[0];
  tmp[29] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[1];
  tmp[30] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[2];
  tmp[31] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[3];
  tmp_0[8] = 32;
  tmp[32] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[0];
  tmp[33] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[1];
  tmp[34] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[2];
  tmp[35] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[3];
  tmp_0[9] = 36;
  tmp[36] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[0];
  tmp[37] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[1];
  tmp[38] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[2];
  tmp[39] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[3];
  tmp_0[10] = 40;
  tmp[40] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[0];
  tmp[41] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[1];
  tmp[42] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[2];
  tmp[43] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[3];
  tmp_0[11] = 44;
  tmp[44] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[0];
  tmp[45] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[1];
  tmp[46] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[2];
  tmp[47] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[3];
  tmp_0[12] = 48;
  tmp[48] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[0];
  tmp[49] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[1];
  tmp[50] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[2];
  tmp[51] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[3];
  tmp_0[13] = 52;
  tmp[52] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[0];
  tmp[53] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[1];
  tmp[54] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[2];
  tmp[55] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[3];
  tmp_0[14] = 56;
  tmp[56] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[0];
  tmp[57] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[1];
  tmp[58] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[2];
  tmp[59] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[3];
  tmp_0[15] = 60;
  tmp[60] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[0];
  tmp[61] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[1];
  tmp[62] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[2];
  tmp[63] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[3];
  tmp_0[16] = 64;
  tmp[64] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[0];
  tmp[65] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[1];
  tmp[66] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[2];
  tmp[67] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[3];
  tmp_0[17] = 68;
  tmp[68] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[0];
  tmp[69] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[1];
  tmp[70] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[2];
  tmp[71] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[3];
  tmp_0[18] = 72;
  tmp[72] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[0];
  tmp[73] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[1];
  tmp[74] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[2];
  tmp[75] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[3];
  tmp_0[19] = 76;
  tmp[76] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[0];
  tmp[77] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[1];
  tmp[78] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[2];
  tmp[79] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[3];
  tmp_0[20] = 80;
  tmp[80] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[0];
  tmp[81] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[1];
  tmp[82] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[2];
  tmp[83] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[3];
  tmp_0[21] = 84;
  tmp[84] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[0];
  tmp[85] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[1];
  tmp[86] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[2];
  tmp[87] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[3];
  tmp_0[22] = 88;
  tmp[88] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[0];
  tmp[89] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[1];
  tmp[90] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[2];
  tmp[91] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[3];
  tmp_0[23] = 92;
  tmp[92] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[0];
  tmp[93] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[1];
  tmp[94] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[2];
  tmp[95] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[3];
  tmp_0[24] = 96;
  tmp[96] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[0];
  tmp[97] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[1];
  tmp[98] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[2];
  tmp[99] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[3];
  tmp_0[25] = 100;
  tmp[100] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[0];
  tmp[101] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[1];
  tmp[102] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[2];
  tmp[103] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[3];
  tmp_0[26] = 104;
  tmp[104] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[0];
  tmp[105] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[1];
  tmp[106] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[2];
  tmp[107] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[3];
  tmp_0[27] = 108;
  tmp[108] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[0];
  tmp[109] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[1];
  tmp[110] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[2];
  tmp[111] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[3];
  tmp_0[28] = 112;
  tmp[112] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[0];
  tmp[113] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[1];
  tmp[114] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[2];
  tmp[115] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[3];
  tmp_0[29] = 116;
  tmp[116] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[0];
  tmp[117] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[1];
  tmp[118] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[2];
  tmp[119] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[3];
  tmp_0[30] = 120;
  tmp[120] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[0];
  tmp[121] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[1];
  tmp[122] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[2];
  tmp[123] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[3];
  tmp_0[31] = 124;
  tmp[124] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[0];
  tmp[125] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[1];
  tmp[126] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[2];
  tmp[127] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[3];
  tmp_0[32] = 128;
  tmp[128] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[0];
  tmp[129] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[1];
  tmp[130] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[2];
  tmp[131] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[3];
  tmp_0[33] = 132;
  tmp[132] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[0];
  tmp[133] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[1];
  tmp[134] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[2];
  tmp[135] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[3];
  tmp_0[34] = 136;
  tmp[136] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[0];
  tmp[137] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[1];
  tmp[138] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[2];
  tmp[139] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[3];
  tmp_0[35] = 140;
  tmp[140] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[0];
  tmp[141] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[1];
  tmp[142] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[2];
  tmp[143] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[3];
  tmp_0[36] = 144;
  tmp[144] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[0];
  tmp[145] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[1];
  tmp[146] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[2];
  tmp[147] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[3];
  tmp_0[37] = 148;
  tmp[148] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[0];
  tmp[149] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[1];
  tmp[150] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[2];
  tmp[151] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[3];
  tmp_0[38] = 152;
  tmp[152] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[0];
  tmp[153] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[1];
  tmp[154] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[2];
  tmp[155] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[3];
  tmp_0[39] = 156;
  tmp[156] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[0];
  tmp[157] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[1];
  tmp[158] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[2];
  tmp[159] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[3];
  tmp_0[40] = 160;
  tmp[160] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[0];
  tmp[161] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[1];
  tmp[162] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[2];
  tmp[163] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[3];
  tmp_0[41] = 164;
  tmp[164] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[0];
  tmp[165] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[1];
  tmp[166] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[2];
  tmp[167] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[3];
  tmp_0[42] = 168;
  tmp[168] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[0];
  tmp[169] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[1];
  tmp[170] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[2];
  tmp[171] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[3];
  tmp_0[43] = 172;
  tmp[172] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[0];
  tmp[173] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[1];
  tmp[174] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[2];
  tmp[175] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[3];
  tmp_0[44] = 176;
  tmp[176] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[0];
  tmp[177] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[1];
  tmp[178] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[2];
  tmp[179] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[3];
  tmp_0[45] = 180;
  tmp[180] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[0];
  tmp[181] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[1];
  tmp[182] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[2];
  tmp[183] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[3];
  tmp_0[46] = 184;
  tmp[184] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[0];
  tmp[185] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[1];
  tmp[186] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[2];
  tmp[187] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[3];
  tmp_0[47] = 188;
  tmp[188] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[0];
  tmp[189] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[1];
  tmp[190] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[2];
  tmp[191] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[3];
  tmp_0[48] = 192;
  tmp[192] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[0];
  tmp[193] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[1];
  tmp[194] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[2];
  tmp[195] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[3];
  tmp_0[49] = 196;
  tmp[196] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[0];
  tmp[197] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[1];
  tmp[198] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[2];
  tmp[199] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[3];
  tmp_0[50] = 200;
  tmp[200] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[0];
  tmp[201] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[1];
  tmp[202] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[2];
  tmp[203] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[3];
  tmp_0[51] = 204;
  tmp[204] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[0];
  tmp[205] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[1];
  tmp[206] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[2];
  tmp[207] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[3];
  tmp_0[52] = 208;
  tmp[208] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[0];
  tmp[209] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[1];
  tmp[210] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[2];
  tmp[211] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[3];
  tmp_0[53] = 212;
  tmp[212] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[0];
  tmp[213] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[1];
  tmp[214] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[2];
  tmp[215] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[3];
  tmp_0[54] = 216;
  tmp[216] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[0];
  tmp[217] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[1];
  tmp[218] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[2];
  tmp[219] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[3];
  tmp_0[55] = 220;
  tmp[220] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[0];
  tmp[221] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[1];
  tmp[222] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[2];
  tmp[223] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[3];
  tmp_0[56] = 224;
  tmp[224] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[0];
  tmp[225] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[1];
  tmp[226] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[2];
  tmp[227] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[3];
  tmp_0[57] = 228;
  tmp[228] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[0];
  tmp[229] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[1];
  tmp[230] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[2];
  tmp[231] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[3];
  tmp_0[58] = 232;
  tmp[232] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[0];
  tmp[233] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[1];
  tmp[234] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[2];
  tmp[235] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[3];
  tmp_0[59] = 236;
  tmp[236] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[0];
  tmp[237] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[1];
  tmp[238] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[2];
  tmp[239] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[3];
  tmp_0[60] = 240;
  tmp[240] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[0];
  tmp[241] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[1];
  tmp[242] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[2];
  tmp[243] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[3];
  tmp_0[61] = 244;
  tmp[244] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[0];
  tmp[245] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[1];
  tmp[246] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[2];
  tmp[247] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[3];
  tmp_0[62] = 248;
  tmp[248] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[0];
  tmp[249] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[1];
  tmp[250] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[2];
  tmp[251] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[3];
  tmp_0[63] = 252;
  tmp[252] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[0];
  tmp[253] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[1];
  tmp[254] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[2];
  tmp[255] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[3];
  tmp_0[64] = 256;
  tmp[256] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[0];
  tmp[257] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[1];
  tmp[258] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[2];
  tmp[259] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[3];
  tmp_0[65] = 260;
  tmp[260] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[0];
  tmp[261] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[1];
  tmp[262] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[2];
  tmp[263] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[3];
  tmp_0[66] = 264;
  tmp[264] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[0];
  tmp[265] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[1];
  tmp[266] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[2];
  tmp[267] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[3];
  tmp_0[67] = 268;
  tmp[268] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[0];
  tmp[269] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[1];
  tmp[270] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[2];
  tmp[271] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[3];
  tmp_0[68] = 272;
  tmp[272] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[0];
  tmp[273] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[1];
  tmp[274] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[2];
  tmp[275] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[3];
  tmp_0[69] = 276;
  tmp[276] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[0];
  tmp[277] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[1];
  tmp[278] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[2];
  tmp[279] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[3];
  tmp_0[70] = 280;
  tmp[280] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[0];
  tmp[281] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[1];
  tmp[282] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[2];
  tmp[283] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[3];
  tmp_0[71] = 284;
  tmp[284] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[0];
  tmp[285] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[1];
  tmp[286] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[2];
  tmp[287] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[3];
  tmp_0[72] = 288;
  tmp[288] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[0];
  tmp[289] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[1];
  tmp[290] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[2];
  tmp[291] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[3];
  tmp_0[73] = 292;
  tmp[292] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[0];
  tmp[293] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[1];
  tmp[294] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[2];
  tmp[295] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[3];
  tmp_0[74] = 296;
  tmp[296] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[0];
  tmp[297] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[1];
  tmp[298] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[2];
  tmp[299] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[3];
  tmp_0[75] = 300;
  tmp[300] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[0];
  tmp[301] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[1];
  tmp[302] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[2];
  tmp[303] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[3];
  tmp_0[76] = 304;
  tmp[304] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[0];
  tmp[305] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[1];
  tmp[306] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[2];
  tmp[307] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[3];
  tmp_0[77] = 308;
  tmp[308] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[0];
  tmp[309] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[1];
  tmp[310] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[2];
  tmp[311] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[3];
  tmp_0[78] = 312;
  tmp[312] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[0];
  tmp[313] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[1];
  tmp[314] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[2];
  tmp[315] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[3];
  tmp_0[79] = 316;
  tmp[316] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[0];
  tmp[317] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[1];
  tmp[318] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[2];
  tmp[319] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[3];
  tmp_0[80] = 320;
  tmp[320] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[0];
  tmp[321] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[1];
  tmp[322] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[2];
  tmp[323] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[3];
  tmp_0[81] = 324;
  tmp[324] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[0];
  tmp[325] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[1];
  tmp[326] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[2];
  tmp[327] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[3];
  tmp_0[82] = 328;
  tmp[328] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[0];
  tmp[329] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[1];
  tmp[330] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[2];
  tmp[331] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[3];
  tmp_0[83] = 332;
  tmp[332] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[0];
  tmp[333] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[1];
  tmp[334] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[2];
  tmp[335] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[3];
  tmp_0[84] = 336;
  tmp[336] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[0];
  tmp[337] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[1];
  tmp[338] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[2];
  tmp[339] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[3];
  tmp_0[85] = 340;
  tmp[340] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[0];
  tmp[341] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[1];
  tmp[342] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[2];
  tmp[343] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[3];
  tmp_0[86] = 344;
  tmp[344] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[0];
  tmp[345] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[1];
  tmp[346] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[2];
  tmp[347] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[3];
  tmp_0[87] = 348;
  tmp[348] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[0];
  tmp[349] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[1];
  tmp[350] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[2];
  tmp[351] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[3];
  tmp_0[88] = 352;
  tmp[352] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[0];
  tmp[353] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[1];
  tmp[354] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[2];
  tmp[355] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[3];
  tmp_0[89] = 356;
  tmp[356] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[0];
  tmp[357] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[1];
  tmp[358] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[2];
  tmp[359] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[3];
  tmp_0[90] = 360;
  tmp[360] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[0];
  tmp[361] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[1];
  tmp[362] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[2];
  tmp[363] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[3];
  tmp_0[91] = 364;
  tmp[364] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[0];
  tmp[365] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[1];
  tmp[366] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[2];
  tmp[367] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[3];
  tmp_0[92] = 368;
  tmp[368] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[0];
  tmp[369] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[1];
  tmp[370] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[2];
  tmp[371] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[3];
  tmp_0[93] = 372;
  tmp[372] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[0];
  tmp[373] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[1];
  tmp[374] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[2];
  tmp[375] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[3];
  tmp_0[94] = 376;
  tmp[376] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[0];
  tmp[377] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[1];
  tmp[378] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[2];
  tmp[379] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[3];
  tmp_0[95] = 380;
  tmp[380] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[0];
  tmp[381] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[1];
  tmp[382] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[2];
  tmp[383] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[3];
  tmp_0[96] = 384;
  tmp[384] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[0];
  tmp[385] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[1];
  tmp[386] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[2];
  tmp[387] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[3];
  tmp_0[97] = 388;
  tmp[388] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[0];
  tmp[389] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[1];
  tmp[390] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[2];
  tmp[391] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[3];
  tmp_0[98] = 392;
  tmp[392] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[0];
  tmp[393] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[1];
  tmp[394] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[2];
  tmp[395] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[3];
  tmp_0[99] = 396;
  tmp[396] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[0];
  tmp[397] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[1];
  tmp[398] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[2];
  tmp[399] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[3];
  tmp_0[100] = 400;
  tmp[400] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[0];
  tmp[401] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[1];
  tmp[402] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[2];
  tmp[403] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[3];
  tmp_0[101] = 404;
  tmp[404] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[0];
  tmp[405] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[1];
  tmp[406] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[2];
  tmp[407] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[3];
  tmp_0[102] = 408;
  tmp[408] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[0];
  tmp[409] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[1];
  tmp[410] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[2];
  tmp[411] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[3];
  tmp_0[103] = 412;
  tmp[412] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[0];
  tmp[413] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[1];
  tmp[414] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[2];
  tmp[415] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[3];
  tmp_0[104] = 416;
  tmp[416] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[0];
  tmp[417] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[1];
  tmp[418] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[2];
  tmp[419] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[3];
  tmp_0[105] = 420;
  tmp[420] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[0];
  tmp[421] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[1];
  tmp[422] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[2];
  tmp[423] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[3];
  tmp_0[106] = 424;
  tmp[424] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[0];
  tmp[425] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[1];
  tmp[426] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[2];
  tmp[427] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[3];
  tmp_0[107] = 428;
  tmp[428] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[0];
  tmp[429] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[1];
  tmp[430] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[2];
  tmp[431] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[3];
  tmp_0[108] = 432;
  simulationData->mData->mInputValues.mN = 432;
  simulationData->mData->mInputValues.mX = &tmp[0];
  simulationData->mData->mInputOffsets.mN = 109;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  simulationData->mData->mOutputs.mN = 13;
  simulationData->mData->mOutputs.mX = &Copy_of_Robot_leg_3_0_B.STATE_1[0];
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  simulationData->mData->mIsFundamentalSampleHit = false;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData,
    diagnosticManager);
  if (tmp_1 != 0) {
    first_output = error_buffer_is_empty(rtmGetErrorStatus
      (Copy_of_Robot_leg_3_0_M));
    if (first_output) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S583>/STATE_1' */

  /* SimscapeExecutionBlock: '<S583>/OUTPUT_1_0' */
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_SimulationData;
  time_0 = Copy_of_Robot_leg_3_0_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  first_output = false;
  simulationData->mData->mFoundZcEvents = first_output;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Copy_of_Robot_leg_3_0_M);
  first_output = false;
  simulationData->mData->mIsSolverAssertCheck = first_output;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_3[0] = 0;
  tmp_2[0] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[0];
  tmp_2[1] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[1];
  tmp_2[2] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[2];
  tmp_2[3] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[3];
  tmp_3[1] = 4;
  tmp_2[4] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[0];
  tmp_2[5] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[1];
  tmp_2[6] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[2];
  tmp_2[7] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[3];
  tmp_3[2] = 8;
  tmp_2[8] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[0];
  tmp_2[9] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[1];
  tmp_2[10] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[2];
  tmp_2[11] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[3];
  tmp_3[3] = 12;
  tmp_2[12] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[0];
  tmp_2[13] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[1];
  tmp_2[14] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[2];
  tmp_2[15] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[3];
  tmp_3[4] = 16;
  tmp_2[16] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[0];
  tmp_2[17] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[1];
  tmp_2[18] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[2];
  tmp_2[19] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[3];
  tmp_3[5] = 20;
  tmp_2[20] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[0];
  tmp_2[21] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[1];
  tmp_2[22] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[2];
  tmp_2[23] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[3];
  tmp_3[6] = 24;
  tmp_2[24] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[0];
  tmp_2[25] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[1];
  tmp_2[26] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[2];
  tmp_2[27] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[3];
  tmp_3[7] = 28;
  tmp_2[28] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[0];
  tmp_2[29] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[1];
  tmp_2[30] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[2];
  tmp_2[31] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[3];
  tmp_3[8] = 32;
  tmp_2[32] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[0];
  tmp_2[33] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[1];
  tmp_2[34] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[2];
  tmp_2[35] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[3];
  tmp_3[9] = 36;
  tmp_2[36] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[0];
  tmp_2[37] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[1];
  tmp_2[38] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[2];
  tmp_2[39] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[3];
  tmp_3[10] = 40;
  tmp_2[40] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[0];
  tmp_2[41] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[1];
  tmp_2[42] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[2];
  tmp_2[43] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[3];
  tmp_3[11] = 44;
  tmp_2[44] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[0];
  tmp_2[45] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[1];
  tmp_2[46] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[2];
  tmp_2[47] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[3];
  tmp_3[12] = 48;
  tmp_2[48] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[0];
  tmp_2[49] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[1];
  tmp_2[50] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[2];
  tmp_2[51] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[3];
  tmp_3[13] = 52;
  tmp_2[52] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[0];
  tmp_2[53] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[1];
  tmp_2[54] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[2];
  tmp_2[55] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[3];
  tmp_3[14] = 56;
  tmp_2[56] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[0];
  tmp_2[57] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[1];
  tmp_2[58] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[2];
  tmp_2[59] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[3];
  tmp_3[15] = 60;
  tmp_2[60] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[0];
  tmp_2[61] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[1];
  tmp_2[62] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[2];
  tmp_2[63] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[3];
  tmp_3[16] = 64;
  tmp_2[64] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[0];
  tmp_2[65] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[1];
  tmp_2[66] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[2];
  tmp_2[67] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[3];
  tmp_3[17] = 68;
  tmp_2[68] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[0];
  tmp_2[69] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[1];
  tmp_2[70] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[2];
  tmp_2[71] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[3];
  tmp_3[18] = 72;
  tmp_2[72] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[0];
  tmp_2[73] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[1];
  tmp_2[74] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[2];
  tmp_2[75] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[3];
  tmp_3[19] = 76;
  tmp_2[76] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[0];
  tmp_2[77] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[1];
  tmp_2[78] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[2];
  tmp_2[79] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[3];
  tmp_3[20] = 80;
  tmp_2[80] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[0];
  tmp_2[81] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[1];
  tmp_2[82] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[2];
  tmp_2[83] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[3];
  tmp_3[21] = 84;
  tmp_2[84] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[0];
  tmp_2[85] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[1];
  tmp_2[86] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[2];
  tmp_2[87] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[3];
  tmp_3[22] = 88;
  tmp_2[88] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[0];
  tmp_2[89] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[1];
  tmp_2[90] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[2];
  tmp_2[91] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[3];
  tmp_3[23] = 92;
  tmp_2[92] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[0];
  tmp_2[93] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[1];
  tmp_2[94] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[2];
  tmp_2[95] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[3];
  tmp_3[24] = 96;
  tmp_2[96] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[0];
  tmp_2[97] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[1];
  tmp_2[98] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[2];
  tmp_2[99] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[3];
  tmp_3[25] = 100;
  tmp_2[100] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[0];
  tmp_2[101] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[1];
  tmp_2[102] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[2];
  tmp_2[103] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[3];
  tmp_3[26] = 104;
  tmp_2[104] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[0];
  tmp_2[105] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[1];
  tmp_2[106] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[2];
  tmp_2[107] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[3];
  tmp_3[27] = 108;
  tmp_2[108] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[0];
  tmp_2[109] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[1];
  tmp_2[110] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[2];
  tmp_2[111] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[3];
  tmp_3[28] = 112;
  tmp_2[112] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[0];
  tmp_2[113] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[1];
  tmp_2[114] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[2];
  tmp_2[115] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[3];
  tmp_3[29] = 116;
  tmp_2[116] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[0];
  tmp_2[117] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[1];
  tmp_2[118] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[2];
  tmp_2[119] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[3];
  tmp_3[30] = 120;
  tmp_2[120] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[0];
  tmp_2[121] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[1];
  tmp_2[122] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[2];
  tmp_2[123] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[3];
  tmp_3[31] = 124;
  tmp_2[124] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[0];
  tmp_2[125] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[1];
  tmp_2[126] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[2];
  tmp_2[127] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[3];
  tmp_3[32] = 128;
  tmp_2[128] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[0];
  tmp_2[129] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[1];
  tmp_2[130] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[2];
  tmp_2[131] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[3];
  tmp_3[33] = 132;
  tmp_2[132] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[0];
  tmp_2[133] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[1];
  tmp_2[134] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[2];
  tmp_2[135] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[3];
  tmp_3[34] = 136;
  tmp_2[136] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[0];
  tmp_2[137] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[1];
  tmp_2[138] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[2];
  tmp_2[139] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[3];
  tmp_3[35] = 140;
  tmp_2[140] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[0];
  tmp_2[141] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[1];
  tmp_2[142] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[2];
  tmp_2[143] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[3];
  tmp_3[36] = 144;
  tmp_2[144] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[0];
  tmp_2[145] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[1];
  tmp_2[146] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[2];
  tmp_2[147] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[3];
  tmp_3[37] = 148;
  tmp_2[148] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[0];
  tmp_2[149] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[1];
  tmp_2[150] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[2];
  tmp_2[151] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[3];
  tmp_3[38] = 152;
  tmp_2[152] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[0];
  tmp_2[153] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[1];
  tmp_2[154] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[2];
  tmp_2[155] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[3];
  tmp_3[39] = 156;
  tmp_2[156] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[0];
  tmp_2[157] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[1];
  tmp_2[158] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[2];
  tmp_2[159] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[3];
  tmp_3[40] = 160;
  tmp_2[160] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[0];
  tmp_2[161] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[1];
  tmp_2[162] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[2];
  tmp_2[163] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[3];
  tmp_3[41] = 164;
  tmp_2[164] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[0];
  tmp_2[165] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[1];
  tmp_2[166] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[2];
  tmp_2[167] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[3];
  tmp_3[42] = 168;
  tmp_2[168] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[0];
  tmp_2[169] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[1];
  tmp_2[170] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[2];
  tmp_2[171] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[3];
  tmp_3[43] = 172;
  tmp_2[172] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[0];
  tmp_2[173] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[1];
  tmp_2[174] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[2];
  tmp_2[175] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[3];
  tmp_3[44] = 176;
  tmp_2[176] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[0];
  tmp_2[177] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[1];
  tmp_2[178] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[2];
  tmp_2[179] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[3];
  tmp_3[45] = 180;
  tmp_2[180] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[0];
  tmp_2[181] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[1];
  tmp_2[182] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[2];
  tmp_2[183] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[3];
  tmp_3[46] = 184;
  tmp_2[184] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[0];
  tmp_2[185] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[1];
  tmp_2[186] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[2];
  tmp_2[187] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[3];
  tmp_3[47] = 188;
  tmp_2[188] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[0];
  tmp_2[189] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[1];
  tmp_2[190] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[2];
  tmp_2[191] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[3];
  tmp_3[48] = 192;
  tmp_2[192] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[0];
  tmp_2[193] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[1];
  tmp_2[194] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[2];
  tmp_2[195] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[3];
  tmp_3[49] = 196;
  tmp_2[196] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[0];
  tmp_2[197] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[1];
  tmp_2[198] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[2];
  tmp_2[199] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[3];
  tmp_3[50] = 200;
  tmp_2[200] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[0];
  tmp_2[201] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[1];
  tmp_2[202] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[2];
  tmp_2[203] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[3];
  tmp_3[51] = 204;
  tmp_2[204] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[0];
  tmp_2[205] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[1];
  tmp_2[206] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[2];
  tmp_2[207] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[3];
  tmp_3[52] = 208;
  tmp_2[208] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[0];
  tmp_2[209] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[1];
  tmp_2[210] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[2];
  tmp_2[211] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[3];
  tmp_3[53] = 212;
  tmp_2[212] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[0];
  tmp_2[213] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[1];
  tmp_2[214] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[2];
  tmp_2[215] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[3];
  tmp_3[54] = 216;
  tmp_2[216] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[0];
  tmp_2[217] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[1];
  tmp_2[218] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[2];
  tmp_2[219] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[3];
  tmp_3[55] = 220;
  tmp_2[220] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[0];
  tmp_2[221] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[1];
  tmp_2[222] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[2];
  tmp_2[223] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[3];
  tmp_3[56] = 224;
  tmp_2[224] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[0];
  tmp_2[225] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[1];
  tmp_2[226] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[2];
  tmp_2[227] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[3];
  tmp_3[57] = 228;
  tmp_2[228] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[0];
  tmp_2[229] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[1];
  tmp_2[230] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[2];
  tmp_2[231] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[3];
  tmp_3[58] = 232;
  tmp_2[232] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[0];
  tmp_2[233] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[1];
  tmp_2[234] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[2];
  tmp_2[235] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[3];
  tmp_3[59] = 236;
  tmp_2[236] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[0];
  tmp_2[237] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[1];
  tmp_2[238] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[2];
  tmp_2[239] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[3];
  tmp_3[60] = 240;
  tmp_2[240] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[0];
  tmp_2[241] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[1];
  tmp_2[242] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[2];
  tmp_2[243] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[3];
  tmp_3[61] = 244;
  tmp_2[244] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[0];
  tmp_2[245] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[1];
  tmp_2[246] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[2];
  tmp_2[247] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[3];
  tmp_3[62] = 248;
  tmp_2[248] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[0];
  tmp_2[249] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[1];
  tmp_2[250] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[2];
  tmp_2[251] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[3];
  tmp_3[63] = 252;
  tmp_2[252] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[0];
  tmp_2[253] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[1];
  tmp_2[254] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[2];
  tmp_2[255] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[3];
  tmp_3[64] = 256;
  tmp_2[256] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[0];
  tmp_2[257] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[1];
  tmp_2[258] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[2];
  tmp_2[259] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[3];
  tmp_3[65] = 260;
  tmp_2[260] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[0];
  tmp_2[261] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[1];
  tmp_2[262] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[2];
  tmp_2[263] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[3];
  tmp_3[66] = 264;
  tmp_2[264] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[0];
  tmp_2[265] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[1];
  tmp_2[266] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[2];
  tmp_2[267] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[3];
  tmp_3[67] = 268;
  tmp_2[268] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[0];
  tmp_2[269] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[1];
  tmp_2[270] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[2];
  tmp_2[271] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[3];
  tmp_3[68] = 272;
  tmp_2[272] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[0];
  tmp_2[273] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[1];
  tmp_2[274] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[2];
  tmp_2[275] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[3];
  tmp_3[69] = 276;
  tmp_2[276] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[0];
  tmp_2[277] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[1];
  tmp_2[278] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[2];
  tmp_2[279] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[3];
  tmp_3[70] = 280;
  tmp_2[280] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[0];
  tmp_2[281] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[1];
  tmp_2[282] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[2];
  tmp_2[283] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[3];
  tmp_3[71] = 284;
  tmp_2[284] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[0];
  tmp_2[285] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[1];
  tmp_2[286] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[2];
  tmp_2[287] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[3];
  tmp_3[72] = 288;
  tmp_2[288] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[0];
  tmp_2[289] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[1];
  tmp_2[290] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[2];
  tmp_2[291] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[3];
  tmp_3[73] = 292;
  tmp_2[292] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[0];
  tmp_2[293] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[1];
  tmp_2[294] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[2];
  tmp_2[295] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[3];
  tmp_3[74] = 296;
  tmp_2[296] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[0];
  tmp_2[297] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[1];
  tmp_2[298] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[2];
  tmp_2[299] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[3];
  tmp_3[75] = 300;
  tmp_2[300] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[0];
  tmp_2[301] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[1];
  tmp_2[302] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[2];
  tmp_2[303] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[3];
  tmp_3[76] = 304;
  tmp_2[304] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[0];
  tmp_2[305] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[1];
  tmp_2[306] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[2];
  tmp_2[307] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[3];
  tmp_3[77] = 308;
  tmp_2[308] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[0];
  tmp_2[309] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[1];
  tmp_2[310] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[2];
  tmp_2[311] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[3];
  tmp_3[78] = 312;
  tmp_2[312] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[0];
  tmp_2[313] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[1];
  tmp_2[314] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[2];
  tmp_2[315] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[3];
  tmp_3[79] = 316;
  tmp_2[316] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[0];
  tmp_2[317] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[1];
  tmp_2[318] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[2];
  tmp_2[319] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[3];
  tmp_3[80] = 320;
  tmp_2[320] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[0];
  tmp_2[321] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[1];
  tmp_2[322] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[2];
  tmp_2[323] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[3];
  tmp_3[81] = 324;
  tmp_2[324] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[0];
  tmp_2[325] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[1];
  tmp_2[326] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[2];
  tmp_2[327] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[3];
  tmp_3[82] = 328;
  tmp_2[328] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[0];
  tmp_2[329] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[1];
  tmp_2[330] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[2];
  tmp_2[331] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[3];
  tmp_3[83] = 332;
  tmp_2[332] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[0];
  tmp_2[333] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[1];
  tmp_2[334] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[2];
  tmp_2[335] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[3];
  tmp_3[84] = 336;
  tmp_2[336] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[0];
  tmp_2[337] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[1];
  tmp_2[338] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[2];
  tmp_2[339] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[3];
  tmp_3[85] = 340;
  tmp_2[340] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[0];
  tmp_2[341] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[1];
  tmp_2[342] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[2];
  tmp_2[343] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[3];
  tmp_3[86] = 344;
  tmp_2[344] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[0];
  tmp_2[345] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[1];
  tmp_2[346] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[2];
  tmp_2[347] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[3];
  tmp_3[87] = 348;
  tmp_2[348] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[0];
  tmp_2[349] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[1];
  tmp_2[350] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[2];
  tmp_2[351] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[3];
  tmp_3[88] = 352;
  tmp_2[352] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[0];
  tmp_2[353] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[1];
  tmp_2[354] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[2];
  tmp_2[355] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[3];
  tmp_3[89] = 356;
  tmp_2[356] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[0];
  tmp_2[357] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[1];
  tmp_2[358] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[2];
  tmp_2[359] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[3];
  tmp_3[90] = 360;
  tmp_2[360] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[0];
  tmp_2[361] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[1];
  tmp_2[362] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[2];
  tmp_2[363] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[3];
  tmp_3[91] = 364;
  tmp_2[364] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[0];
  tmp_2[365] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[1];
  tmp_2[366] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[2];
  tmp_2[367] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[3];
  tmp_3[92] = 368;
  tmp_2[368] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[0];
  tmp_2[369] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[1];
  tmp_2[370] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[2];
  tmp_2[371] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[3];
  tmp_3[93] = 372;
  tmp_2[372] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[0];
  tmp_2[373] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[1];
  tmp_2[374] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[2];
  tmp_2[375] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[3];
  tmp_3[94] = 376;
  tmp_2[376] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[0];
  tmp_2[377] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[1];
  tmp_2[378] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[2];
  tmp_2[379] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[3];
  tmp_3[95] = 380;
  tmp_2[380] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[0];
  tmp_2[381] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[1];
  tmp_2[382] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[2];
  tmp_2[383] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[3];
  tmp_3[96] = 384;
  tmp_2[384] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[0];
  tmp_2[385] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[1];
  tmp_2[386] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[2];
  tmp_2[387] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[3];
  tmp_3[97] = 388;
  tmp_2[388] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[0];
  tmp_2[389] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[1];
  tmp_2[390] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[2];
  tmp_2[391] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[3];
  tmp_3[98] = 392;
  tmp_2[392] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[0];
  tmp_2[393] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[1];
  tmp_2[394] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[2];
  tmp_2[395] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[3];
  tmp_3[99] = 396;
  tmp_2[396] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[0];
  tmp_2[397] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[1];
  tmp_2[398] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[2];
  tmp_2[399] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[3];
  tmp_3[100] = 400;
  tmp_2[400] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[0];
  tmp_2[401] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[1];
  tmp_2[402] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[2];
  tmp_2[403] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[3];
  tmp_3[101] = 404;
  tmp_2[404] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[0];
  tmp_2[405] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[1];
  tmp_2[406] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[2];
  tmp_2[407] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[3];
  tmp_3[102] = 408;
  tmp_2[408] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[0];
  tmp_2[409] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[1];
  tmp_2[410] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[2];
  tmp_2[411] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[3];
  tmp_3[103] = 412;
  tmp_2[412] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[0];
  tmp_2[413] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[1];
  tmp_2[414] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[2];
  tmp_2[415] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[3];
  tmp_3[104] = 416;
  tmp_2[416] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[0];
  tmp_2[417] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[1];
  tmp_2[418] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[2];
  tmp_2[419] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[3];
  tmp_3[105] = 420;
  tmp_2[420] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[0];
  tmp_2[421] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[1];
  tmp_2[422] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[2];
  tmp_2[423] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[3];
  tmp_3[106] = 424;
  tmp_2[424] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[0];
  tmp_2[425] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[1];
  tmp_2[426] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[2];
  tmp_2[427] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[3];
  tmp_3[107] = 428;
  tmp_2[428] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[0];
  tmp_2[429] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[1];
  tmp_2[430] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[2];
  tmp_2[431] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[3];
  tmp_3[108] = 432;
  memcpy(&tmp_2[432], &Copy_of_Robot_leg_3_0_B.STATE_1[0], 13U * sizeof(real_T));
  tmp_3[109] = 445;
  simulationData->mData->mInputValues.mN = 445;
  simulationData->mData->mInputValues.mX = &tmp_2[0];
  simulationData->mData->mInputOffsets.mN = 110;
  simulationData->mData->mInputOffsets.mX = &tmp_3[0];
  simulationData->mData->mOutputs.mN = 166;
  simulationData->mData->mOutputs.mX = &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[0];
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  simulationData->mData->mIsFundamentalSampleHit = false;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData,
    diagnosticManager);
  if (tmp_1 != 0) {
    first_output = error_buffer_is_empty(rtmGetErrorStatus
      (Copy_of_Robot_leg_3_0_M));
    if (first_output) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S583>/OUTPUT_1_0' */

  /* Outport: '<Root>/w' */
  Copy_of_Robot_leg_3_0_Y.w = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[163];

  /* Outport: '<Root>/x' */
  Copy_of_Robot_leg_3_0_Y.x = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[164];

  /* Gain: '<S6>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN = Copy_of_Robot_leg_3_0_P.GAIN_Gain *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[165];

  /* Outport: '<Root>/z' */
  Copy_of_Robot_leg_3_0_Y.z = Copy_of_Robot_leg_3_0_B.GAIN;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Gain: '<S379>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_c = Copy_of_Robot_leg_3_0_P.Gain_Gain_d *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[103];

  /* Abs: '<S379>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs = fabs(Copy_of_Robot_leg_3_0_B.Gain_c);

  /* RelationalOperator: '<S385>/Compare' incorporates:
   *  Constant: '<S385>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare = (Copy_of_Robot_leg_3_0_B.Abs <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_lenx);

  /* Gain: '<S379>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_f = Copy_of_Robot_leg_3_0_P.Gain1_Gain_k *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[104];

  /* Abs: '<S379>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1 = fabs(Copy_of_Robot_leg_3_0_B.Gain1_f);

  /* RelationalOperator: '<S386>/Compare' incorporates:
   *  Constant: '<S386>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_n = (Copy_of_Robot_leg_3_0_B.Abs1 <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_leny);

  /* Logic: '<S379>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator = (Copy_of_Robot_leg_3_0_B.Compare &&
    Copy_of_Robot_leg_3_0_B.Compare_n);

  /* DataTypeConversion: '<S379>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion =
    Copy_of_Robot_leg_3_0_B.LogicalOperator;

  /* Reshape: '<S420>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[92], 9U * sizeof(real_T));

  /* If: '<S322>/If1' incorporates:
   *  Constant: '<S383>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S322>/Forces' incorporates:
     *  ActionPort: '<S382>/Action Port'
     */
    /* Abs: '<S395>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_a = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[105]);

    /* Sum: '<S395>/Sum' incorporates:
     *  Constant: '<S395>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad_m +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_dept_p;
    Copy_of_Robot_leg_3_0_B.Sum_p0 = pulseWidth - Copy_of_Robot_leg_3_0_B.Abs_a;

    /* DeadZone: '<S395>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_p0 > Copy_of_Robot_leg_3_0_P.DeadZone_End_ln)
    {
      Copy_of_Robot_leg_3_0_B.DeadZone_e = Copy_of_Robot_leg_3_0_B.Sum_p0 -
        Copy_of_Robot_leg_3_0_P.DeadZone_End_ln;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_p0 >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start_n) {
      Copy_of_Robot_leg_3_0_B.DeadZone_e = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone_e = Copy_of_Robot_leg_3_0_B.Sum_p0 -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start_n;
    }

    /* End of DeadZone: '<S395>/Dead Zone' */

    /* Signum: '<S395>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[105];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_h = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_h = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_h = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx_h = (rtNaN);
    }

    /* End of Signum: '<S395>/Sign x' */

    /* Product: '<S395>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_br = Copy_of_Robot_leg_3_0_B.Signx_h *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[108];

    /* Gain: '<S395>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_k = Copy_of_Robot_leg_3_0_P.Gain2_Gain_j *
      Copy_of_Robot_leg_3_0_B.Product_br;

    /* Signum: '<S395>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[108];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_e = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_e = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_e = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx_e = (rtNaN);
    }

    /* End of Signum: '<S395>/Sign vx' */

    /* Gain: '<S406>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force_k =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_k_contact_h *
      Copy_of_Robot_leg_3_0_B.DeadZone_e;

    /* Product: '<S382>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce_p = Copy_of_Robot_leg_3_0_B.Signx_h *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force_k;

    /* Signum: '<S406>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone_e;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_b = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_b = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_b = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign_b = (rtNaN);
    }

    /* End of Signum: '<S406>/Sign' */

    /* Abs: '<S406>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_k = fabs
      (Copy_of_Robot_leg_3_0_B.Sign_b);

    /* Saturate: '<S406>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_k;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_d;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_p;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation_e = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation_e = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation_e = pulseWidth;
    }

    /* End of Saturate: '<S406>/Saturation' */

    /* Gain: '<S406>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_b_contact_m;
    Copy_of_Robot_leg_3_0_B.Damping_Force_e = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation_e;

    /* Product: '<S406>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_cz =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_k *
      Copy_of_Robot_leg_3_0_B.Damping_Force_e;

    /* Product: '<S382>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce_h =
      Copy_of_Robot_leg_3_0_B.Damping_Force_cz *
      Copy_of_Robot_leg_3_0_B.Signvx_e;

    /* Sum: '<S398>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_kge = Copy_of_Robot_leg_3_0_B.SprForce_p +
      Copy_of_Robot_leg_3_0_B.DampForce_h;

    /* SignalConversion: '<S398>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S398>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_b[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_o;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_b[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_o;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_b[2] =
      Copy_of_Robot_leg_3_0_B.Sum_kge;

    /* Gain: '<S398>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ii[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_c *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_b[0];
    Copy_of_Robot_leg_3_0_B.Gain_ii[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_c *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_b[1];
    Copy_of_Robot_leg_3_0_B.Gain_ii[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_c *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_b[2];

    /* Product: '<S402>/Product3' incorporates:
     *  Constant: '<S402>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_p = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[101]
      * Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad_m;

    /* Product: '<S397>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_ij = Copy_of_Robot_leg_3_0_B.Signx_h *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[107];

    /* Sum: '<S402>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy_c = Copy_of_Robot_leg_3_0_B.Product3_p +
      Copy_of_Robot_leg_3_0_B.Product5_ij;

    /* Math: '<S402>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_c2 = Copy_of_Robot_leg_3_0_B.slipy_c *
      Copy_of_Robot_leg_3_0_B.slipy_c;

    /* Product: '<S402>/Product4' incorporates:
     *  Constant: '<S402>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4_l =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad_m *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[102];

    /* Product: '<S397>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6_l = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[106]
      * Copy_of_Robot_leg_3_0_B.Signx_h;

    /* Sum: '<S402>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx_c = Copy_of_Robot_leg_3_0_B.Product6_l -
      Copy_of_Robot_leg_3_0_B.Product4_l;

    /* Math: '<S402>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1_a = Copy_of_Robot_leg_3_0_B.slipx_c *
      Copy_of_Robot_leg_3_0_B.slipx_c;

    /* Sum: '<S402>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3_d = Copy_of_Robot_leg_3_0_B.MathFunction_c2 +
      Copy_of_Robot_leg_3_0_B.MathFunction1_a;

    /* Sqrt: '<S402>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt_m = sqrt(Copy_of_Robot_leg_3_0_B.Sum3_d);

    /* Lookup_n-D: '<S404>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_cu = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt_m,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_ao,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_i, 5U);

    /* Product: '<S404>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_a =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_cu *
      Copy_of_Robot_leg_3_0_B.Gain_ii[2];

    /* Gain: '<S404>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force_l =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_c * Copy_of_Robot_leg_3_0_B.Product_a;

    /* Trigonometry: '<S402>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_i = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy_c, Copy_of_Robot_leg_3_0_B.slipx_c);

    /* Trigonometry: '<S397>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_k = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_i);

    /* Product: '<S397>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_l1 =
      Copy_of_Robot_leg_3_0_B.Friction_Force_l *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_k;

    /* Trigonometry: '<S397>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_c = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_i);

    /* Product: '<S397>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_a =
      Copy_of_Robot_leg_3_0_B.Friction_Force_l *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_c;

    /* SignalConversion: '<S397>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S397>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_g[0] =
      Copy_of_Robot_leg_3_0_B.Product3_l1;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_g[1] =
      Copy_of_Robot_leg_3_0_B.Product4_a;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_g[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value_c;

    /* Gain: '<S397>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_jd[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_mo *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_g[0];

    /* Sum: '<S382>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_h[0] = Copy_of_Robot_leg_3_0_B.Gain_ii[0] +
      Copy_of_Robot_leg_3_0_B.Gain_jd[0];

    /* SignalConversion: '<S382>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_i[6] = Copy_of_Robot_leg_3_0_B.FPla_h[0];

    /* Gain: '<S397>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_jd[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_mo *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_g[1];

    /* Sum: '<S382>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_h[1] = Copy_of_Robot_leg_3_0_B.Gain_ii[1] +
      Copy_of_Robot_leg_3_0_B.Gain_jd[1];

    /* SignalConversion: '<S382>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_i[7] = Copy_of_Robot_leg_3_0_B.FPla_h[1];

    /* Gain: '<S397>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_jd[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_mo *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_g[2];

    /* Sum: '<S382>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_h[2] = Copy_of_Robot_leg_3_0_B.Gain_ii[2] +
      Copy_of_Robot_leg_3_0_B.Gain_jd[2];

    /* SignalConversion: '<S382>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_i[8] = Copy_of_Robot_leg_3_0_B.FPla_h[2];

    /* Product: '<S396>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_np = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[104]
      * Copy_of_Robot_leg_3_0_B.FPla_h[2];

    /* Product: '<S396>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_cpr = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0
      [105] * Copy_of_Robot_leg_3_0_B.FPla_h[1];

    /* Product: '<S396>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_i = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[105]
      * Copy_of_Robot_leg_3_0_B.FPla_h[0];

    /* Product: '<S396>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_gk = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[103]
      * Copy_of_Robot_leg_3_0_B.FPla_h[2];

    /* Product: '<S396>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_p4 = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[103]
      * Copy_of_Robot_leg_3_0_B.FPla_h[1];

    /* Product: '<S396>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_k = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[104]
      * Copy_of_Robot_leg_3_0_B.FPla_h[0];

    /* Sum: '<S396>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_i[9] = Copy_of_Robot_leg_3_0_B.Product_np -
      Copy_of_Robot_leg_3_0_B.Product1_cpr;

    /* Sum: '<S396>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph_i[10] = Copy_of_Robot_leg_3_0_B.Product2_i -
      Copy_of_Robot_leg_3_0_B.Product3_gk;

    /* Sum: '<S396>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph_i[11] = Copy_of_Robot_leg_3_0_B.Product4_p4 -
      Copy_of_Robot_leg_3_0_B.Product5_k;

    /* Product: '<S397>/Product7' incorporates:
     *  Constant: '<S397>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7_b[0] = Copy_of_Robot_leg_3_0_P.Fx2_Value_o
      [0] * Copy_of_Robot_leg_3_0_B.Signx_h;
    Copy_of_Robot_leg_3_0_B.Product7_b[1] = Copy_of_Robot_leg_3_0_P.Fx2_Value_o
      [1] * Copy_of_Robot_leg_3_0_B.Signx_h;
    Copy_of_Robot_leg_3_0_B.Product7_b[2] = Copy_of_Robot_leg_3_0_P.Fx2_Value_o
      [2] * Copy_of_Robot_leg_3_0_B.Signx_h;

    /* Product: '<S400>/Product' incorporates:
     *  Constant: '<S397>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_bl = Copy_of_Robot_leg_3_0_B.Product7_b[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_c;

    /* Product: '<S400>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_ik = Copy_of_Robot_leg_3_0_B.Product7_b[2] *
      Copy_of_Robot_leg_3_0_B.Product4_a;

    /* Product: '<S400>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_b = Copy_of_Robot_leg_3_0_B.Product7_b[2] *
      Copy_of_Robot_leg_3_0_B.Product3_l1;

    /* Product: '<S400>/Product3' incorporates:
     *  Constant: '<S397>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_d = Copy_of_Robot_leg_3_0_B.Product7_b[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_c;

    /* Product: '<S400>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_cw = Copy_of_Robot_leg_3_0_B.Product7_b[0] *
      Copy_of_Robot_leg_3_0_B.Product4_a;

    /* Product: '<S400>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_e = Copy_of_Robot_leg_3_0_B.Product7_b[1] *
      Copy_of_Robot_leg_3_0_B.Product3_l1;

    /* Sum: '<S400>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_ph = Copy_of_Robot_leg_3_0_B.Product_bl -
      Copy_of_Robot_leg_3_0_B.Product1_ik;

    /* Sum: '<S400>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1_c = Copy_of_Robot_leg_3_0_B.Product2_b -
      Copy_of_Robot_leg_3_0_B.Product3_d;

    /* Sum: '<S400>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2_h = Copy_of_Robot_leg_3_0_B.Product4_cw -
      Copy_of_Robot_leg_3_0_B.Product5_e;

    /* Product: '<S397>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_g,
      Copy_of_Robot_leg_3_0_B.Product1_oi);

    /* SignalConversion: '<S397>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_m[0] =
      Copy_of_Robot_leg_3_0_B.Sum_ph;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_m[1] =
      Copy_of_Robot_leg_3_0_B.Sum1_c;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_m[2] =
      Copy_of_Robot_leg_3_0_B.Sum2_h;

    /* Product: '<S397>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_m,
      &Copy_of_Robot_leg_3_0_B.FSph_i[3]);

    /* Product: '<S398>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_b,
      Copy_of_Robot_leg_3_0_B.Product2_j2);

    /* Sum: '<S382>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_i[0] = Copy_of_Robot_leg_3_0_B.Product2_j2[0] +
      Copy_of_Robot_leg_3_0_B.Product1_oi[0];
    Copy_of_Robot_leg_3_0_B.FSph_i[1] = Copy_of_Robot_leg_3_0_B.Product2_j2[1] +
      Copy_of_Robot_leg_3_0_B.Product1_oi[1];
    Copy_of_Robot_leg_3_0_B.FSph_i[2] = Copy_of_Robot_leg_3_0_B.Product2_j2[2] +
      Copy_of_Robot_leg_3_0_B.Product1_oi[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_c);
    }

    /* End of Outputs for SubSystem: '<S322>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S322>/No Force' incorporates:
     *  ActionPort: '<S383>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph_i[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value_h[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_f);
    }

    /* End of Outputs for SubSystem: '<S322>/No Force' */
    break;
  }

  /* End of If: '<S322>/If1' */

  /* Product: '<S381>/Product' */
  Copy_of_Robot_leg_3_0_B.Product[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion * Copy_of_Robot_leg_3_0_B.Sum_kge;
  Copy_of_Robot_leg_3_0_B.Product[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion *
    Copy_of_Robot_leg_3_0_B.Gain_jd[0];
  Copy_of_Robot_leg_3_0_B.Product[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion *
    Copy_of_Robot_leg_3_0_B.Gain_jd[1];
  Copy_of_Robot_leg_3_0_B.Product[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion *
    Copy_of_Robot_leg_3_0_B.Gain_jd[2];
  Copy_of_Robot_leg_3_0_B.Product[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion *
    Copy_of_Robot_leg_3_0_B.DeadZone_e;
  Copy_of_Robot_leg_3_0_B.Product[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion * Copy_of_Robot_leg_3_0_B.Gain2_k;
  Copy_of_Robot_leg_3_0_B.Product[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion *
    Copy_of_Robot_leg_3_0_B.SprForce_p;
  Copy_of_Robot_leg_3_0_B.Product[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion *
    Copy_of_Robot_leg_3_0_B.DampForce_h;

  /* Gain: '<S427>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_f = Copy_of_Robot_leg_3_0_P.Gain_Gain_o *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[120];

  /* Abs: '<S427>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs_g = fabs(Copy_of_Robot_leg_3_0_B.Gain_f);

  /* RelationalOperator: '<S433>/Compare' incorporates:
   *  Constant: '<S433>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_o = (Copy_of_Robot_leg_3_0_B.Abs_g <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_lenx);

  /* Gain: '<S427>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_gt = Copy_of_Robot_leg_3_0_P.Gain1_Gain_a *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[121];

  /* Abs: '<S427>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1_o = fabs(Copy_of_Robot_leg_3_0_B.Gain1_gt);

  /* RelationalOperator: '<S434>/Compare' incorporates:
   *  Constant: '<S434>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_m = (Copy_of_Robot_leg_3_0_B.Abs1_o <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_leny);

  /* Logic: '<S427>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator_a = (Copy_of_Robot_leg_3_0_B.Compare_o
    && Copy_of_Robot_leg_3_0_B.Compare_m);

  /* DataTypeConversion: '<S427>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion_m =
    Copy_of_Robot_leg_3_0_B.LogicalOperator_a;

  /* Reshape: '<S468>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE_f[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[109], 9U * sizeof(real_T));

  /* If: '<S323>/If1' incorporates:
   *  Constant: '<S431>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion_m > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_j = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_j;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S323>/Forces' incorporates:
     *  ActionPort: '<S430>/Action Port'
     */
    /* Abs: '<S443>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_db = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[122]);

    /* Sum: '<S443>/Sum' incorporates:
     *  Constant: '<S443>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_ra_b +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_dep_h;
    Copy_of_Robot_leg_3_0_B.Sum_pm = pulseWidth - Copy_of_Robot_leg_3_0_B.Abs_db;

    /* DeadZone: '<S443>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_pm > Copy_of_Robot_leg_3_0_P.DeadZone_End_m)
    {
      Copy_of_Robot_leg_3_0_B.DeadZone_a = Copy_of_Robot_leg_3_0_B.Sum_pm -
        Copy_of_Robot_leg_3_0_P.DeadZone_End_m;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_pm >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start_i) {
      Copy_of_Robot_leg_3_0_B.DeadZone_a = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone_a = Copy_of_Robot_leg_3_0_B.Sum_pm -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start_i;
    }

    /* End of DeadZone: '<S443>/Dead Zone' */

    /* Signum: '<S443>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[122];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_o = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_o = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_o = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx_o = (rtNaN);
    }

    /* End of Signum: '<S443>/Sign x' */

    /* Product: '<S443>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_jh = Copy_of_Robot_leg_3_0_B.Signx_o *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[125];

    /* Gain: '<S443>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_m = Copy_of_Robot_leg_3_0_P.Gain2_Gain_f3 *
      Copy_of_Robot_leg_3_0_B.Product_jh;

    /* Signum: '<S443>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[125];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_c = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_c = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_c = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx_c = (rtNaN);
    }

    /* End of Signum: '<S443>/Sign vx' */

    /* Gain: '<S454>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force_i =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_k_contact_o *
      Copy_of_Robot_leg_3_0_B.DeadZone_a;

    /* Product: '<S430>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce_n = Copy_of_Robot_leg_3_0_B.Signx_o *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force_i;

    /* Signum: '<S454>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone_a;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_l = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_l = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_l = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign_l = (rtNaN);
    }

    /* End of Signum: '<S454>/Sign' */

    /* Abs: '<S454>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_d = fabs
      (Copy_of_Robot_leg_3_0_B.Sign_l);

    /* Saturate: '<S454>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_m;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_a;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_o;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation_f = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation_f = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation_f = pulseWidth;
    }

    /* End of Saturate: '<S454>/Saturation' */

    /* Gain: '<S454>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_b_contact_b;
    Copy_of_Robot_leg_3_0_B.Damping_Force_c = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation_f;

    /* Product: '<S454>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_o =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_d *
      Copy_of_Robot_leg_3_0_B.Damping_Force_c;

    /* Product: '<S430>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce_c =
      Copy_of_Robot_leg_3_0_B.Damping_Force_o * Copy_of_Robot_leg_3_0_B.Signvx_c;

    /* Sum: '<S446>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_o3 = Copy_of_Robot_leg_3_0_B.SprForce_n +
      Copy_of_Robot_leg_3_0_B.DampForce_c;

    /* SignalConversion: '<S446>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S446>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_ol[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_b;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_ol[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_b;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_ol[2] =
      Copy_of_Robot_leg_3_0_B.Sum_o3;

    /* Gain: '<S446>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_a[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_mj *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_ol[0];
    Copy_of_Robot_leg_3_0_B.Gain_a[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_mj *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_ol[1];
    Copy_of_Robot_leg_3_0_B.Gain_a[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_mj *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_ol[2];

    /* Product: '<S450>/Product3' incorporates:
     *  Constant: '<S450>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_f = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[118]
      * Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_ra_b;

    /* Product: '<S445>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_m = Copy_of_Robot_leg_3_0_B.Signx_o *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[124];

    /* Sum: '<S450>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy_a = Copy_of_Robot_leg_3_0_B.Product3_f +
      Copy_of_Robot_leg_3_0_B.Product5_m;

    /* Math: '<S450>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_mw = Copy_of_Robot_leg_3_0_B.slipy_a *
      Copy_of_Robot_leg_3_0_B.slipy_a;

    /* Product: '<S450>/Product4' incorporates:
     *  Constant: '<S450>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4_ft =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_ra_b *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[119];

    /* Product: '<S445>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6_d = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[123]
      * Copy_of_Robot_leg_3_0_B.Signx_o;

    /* Sum: '<S450>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx_h = Copy_of_Robot_leg_3_0_B.Product6_d -
      Copy_of_Robot_leg_3_0_B.Product4_ft;

    /* Math: '<S450>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1_j = Copy_of_Robot_leg_3_0_B.slipx_h *
      Copy_of_Robot_leg_3_0_B.slipx_h;

    /* Sum: '<S450>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3_i = Copy_of_Robot_leg_3_0_B.MathFunction_mw +
      Copy_of_Robot_leg_3_0_B.MathFunction1_j;

    /* Sqrt: '<S450>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt_f = sqrt(Copy_of_Robot_leg_3_0_B.Sum3_i);

    /* Lookup_n-D: '<S452>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_c = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt_f,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_mt,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_m, 5U);

    /* Product: '<S452>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_p =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_c *
      Copy_of_Robot_leg_3_0_B.Gain_a[2];

    /* Gain: '<S452>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force_b =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_fy * Copy_of_Robot_leg_3_0_B.Product_p;

    /* Trigonometry: '<S450>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_j1 = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy_a, Copy_of_Robot_leg_3_0_B.slipx_h);

    /* Trigonometry: '<S445>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_o = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_j1);

    /* Product: '<S445>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_gs =
      Copy_of_Robot_leg_3_0_B.Friction_Force_b *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_o;

    /* Trigonometry: '<S445>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_js = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_j1);

    /* Product: '<S445>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_d =
      Copy_of_Robot_leg_3_0_B.Friction_Force_b *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_js;

    /* SignalConversion: '<S445>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S445>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_d[0] =
      Copy_of_Robot_leg_3_0_B.Product3_gs;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_d[1] =
      Copy_of_Robot_leg_3_0_B.Product4_d;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_d[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value_j;

    /* Gain: '<S445>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ph[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_b *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_d[0];

    /* Sum: '<S430>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_a[0] = Copy_of_Robot_leg_3_0_B.Gain_a[0] +
      Copy_of_Robot_leg_3_0_B.Gain_ph[0];

    /* SignalConversion: '<S430>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_mf[6] = Copy_of_Robot_leg_3_0_B.FPla_a[0];

    /* Gain: '<S445>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ph[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_b *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_d[1];

    /* Sum: '<S430>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_a[1] = Copy_of_Robot_leg_3_0_B.Gain_a[1] +
      Copy_of_Robot_leg_3_0_B.Gain_ph[1];

    /* SignalConversion: '<S430>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_mf[7] = Copy_of_Robot_leg_3_0_B.FPla_a[1];

    /* Gain: '<S445>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ph[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_b *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_d[2];

    /* Sum: '<S430>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_a[2] = Copy_of_Robot_leg_3_0_B.Gain_a[2] +
      Copy_of_Robot_leg_3_0_B.Gain_ph[2];

    /* SignalConversion: '<S430>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_mf[8] = Copy_of_Robot_leg_3_0_B.FPla_a[2];

    /* Product: '<S444>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_o = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[121] *
      Copy_of_Robot_leg_3_0_B.FPla_a[2];

    /* Product: '<S444>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_k = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[122]
      * Copy_of_Robot_leg_3_0_B.FPla_a[1];

    /* Product: '<S444>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_h = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[122]
      * Copy_of_Robot_leg_3_0_B.FPla_a[0];

    /* Product: '<S444>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_n = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[120]
      * Copy_of_Robot_leg_3_0_B.FPla_a[2];

    /* Product: '<S444>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_ew = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[120]
      * Copy_of_Robot_leg_3_0_B.FPla_a[1];

    /* Product: '<S444>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_n = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[121]
      * Copy_of_Robot_leg_3_0_B.FPla_a[0];

    /* Sum: '<S444>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_mf[9] = Copy_of_Robot_leg_3_0_B.Product_o -
      Copy_of_Robot_leg_3_0_B.Product1_k;

    /* Sum: '<S444>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph_mf[10] = Copy_of_Robot_leg_3_0_B.Product2_h -
      Copy_of_Robot_leg_3_0_B.Product3_n;

    /* Sum: '<S444>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph_mf[11] = Copy_of_Robot_leg_3_0_B.Product4_ew -
      Copy_of_Robot_leg_3_0_B.Product5_n;

    /* Product: '<S445>/Product7' incorporates:
     *  Constant: '<S445>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7_p[0] = Copy_of_Robot_leg_3_0_P.Fx2_Value_h
      [0] * Copy_of_Robot_leg_3_0_B.Signx_o;
    Copy_of_Robot_leg_3_0_B.Product7_p[1] = Copy_of_Robot_leg_3_0_P.Fx2_Value_h
      [1] * Copy_of_Robot_leg_3_0_B.Signx_o;
    Copy_of_Robot_leg_3_0_B.Product7_p[2] = Copy_of_Robot_leg_3_0_P.Fx2_Value_h
      [2] * Copy_of_Robot_leg_3_0_B.Signx_o;

    /* Product: '<S448>/Product' incorporates:
     *  Constant: '<S445>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_nx = Copy_of_Robot_leg_3_0_B.Product7_p[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_j;

    /* Product: '<S448>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_b = Copy_of_Robot_leg_3_0_B.Product7_p[2] *
      Copy_of_Robot_leg_3_0_B.Product4_d;

    /* Product: '<S448>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_hx = Copy_of_Robot_leg_3_0_B.Product7_p[2] *
      Copy_of_Robot_leg_3_0_B.Product3_gs;

    /* Product: '<S448>/Product3' incorporates:
     *  Constant: '<S445>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_hs = Copy_of_Robot_leg_3_0_B.Product7_p[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_j;

    /* Product: '<S448>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_bz = Copy_of_Robot_leg_3_0_B.Product7_p[0] *
      Copy_of_Robot_leg_3_0_B.Product4_d;

    /* Product: '<S448>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_i = Copy_of_Robot_leg_3_0_B.Product7_p[1] *
      Copy_of_Robot_leg_3_0_B.Product3_gs;

    /* Sum: '<S448>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_mh = Copy_of_Robot_leg_3_0_B.Product_nx -
      Copy_of_Robot_leg_3_0_B.Product1_b;

    /* Sum: '<S448>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1_e = Copy_of_Robot_leg_3_0_B.Product2_hx -
      Copy_of_Robot_leg_3_0_B.Product3_hs;

    /* Sum: '<S448>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2_m = Copy_of_Robot_leg_3_0_B.Product4_bz -
      Copy_of_Robot_leg_3_0_B.Product5_i;

    /* Product: '<S445>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_f,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_d,
      Copy_of_Robot_leg_3_0_B.Product1_o);

    /* SignalConversion: '<S445>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_p[0] =
      Copy_of_Robot_leg_3_0_B.Sum_mh;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_p[1] =
      Copy_of_Robot_leg_3_0_B.Sum1_e;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_p[2] =
      Copy_of_Robot_leg_3_0_B.Sum2_m;

    /* Product: '<S445>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_f,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_p,
      &Copy_of_Robot_leg_3_0_B.FSph_mf[3]);

    /* Product: '<S446>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_f,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_ol,
      Copy_of_Robot_leg_3_0_B.Product2_hxv);

    /* Sum: '<S430>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_mf[0] = Copy_of_Robot_leg_3_0_B.Product2_hxv[0]
      + Copy_of_Robot_leg_3_0_B.Product1_o[0];
    Copy_of_Robot_leg_3_0_B.FSph_mf[1] = Copy_of_Robot_leg_3_0_B.Product2_hxv[1]
      + Copy_of_Robot_leg_3_0_B.Product1_o[1];
    Copy_of_Robot_leg_3_0_B.FSph_mf[2] = Copy_of_Robot_leg_3_0_B.Product2_hxv[2]
      + Copy_of_Robot_leg_3_0_B.Product1_o[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_b);
    }

    /* End of Outputs for SubSystem: '<S323>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S323>/No Force' incorporates:
     *  ActionPort: '<S431>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph_mf[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value_c[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_e);
    }

    /* End of Outputs for SubSystem: '<S323>/No Force' */
    break;
  }

  /* End of If: '<S323>/If1' */

  /* Product: '<S429>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_g[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.Sum_o3;
  Copy_of_Robot_leg_3_0_B.Product_g[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.Gain_ph[0];
  Copy_of_Robot_leg_3_0_B.Product_g[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.Gain_ph[1];
  Copy_of_Robot_leg_3_0_B.Product_g[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.Gain_ph[2];
  Copy_of_Robot_leg_3_0_B.Product_g[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.DeadZone_a;
  Copy_of_Robot_leg_3_0_B.Product_g[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.Gain2_m;
  Copy_of_Robot_leg_3_0_B.Product_g[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.SprForce_n;
  Copy_of_Robot_leg_3_0_B.Product_g[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_m *
    Copy_of_Robot_leg_3_0_B.DampForce_c;

  /* Gain: '<S475>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_j = Copy_of_Robot_leg_3_0_P.Gain_Gain_i *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[137];

  /* Abs: '<S475>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs_e = fabs(Copy_of_Robot_leg_3_0_B.Gain_j);

  /* RelationalOperator: '<S481>/Compare' incorporates:
   *  Constant: '<S481>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_l = (Copy_of_Robot_leg_3_0_B.Abs_e <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_lenx);

  /* Gain: '<S475>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_j = Copy_of_Robot_leg_3_0_P.Gain1_Gain_h *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[138];

  /* Abs: '<S475>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1_d = fabs(Copy_of_Robot_leg_3_0_B.Gain1_j);

  /* RelationalOperator: '<S482>/Compare' incorporates:
   *  Constant: '<S482>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_g = (Copy_of_Robot_leg_3_0_B.Abs1_d <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_leny);

  /* Logic: '<S475>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator_l = (Copy_of_Robot_leg_3_0_B.Compare_l
    && Copy_of_Robot_leg_3_0_B.Compare_g);

  /* DataTypeConversion: '<S475>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc =
    Copy_of_Robot_leg_3_0_B.LogicalOperator_l;

  /* Reshape: '<S516>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE_p[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[126], 9U * sizeof(real_T));

  /* If: '<S324>/If1' incorporates:
   *  Constant: '<S479>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_jw = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_jw;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S324>/Forces' incorporates:
     *  ActionPort: '<S478>/Action Port'
     */
    /* Abs: '<S491>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_i = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[139]);

    /* Sum: '<S491>/Sum' incorporates:
     *  Constant: '<S491>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_ra_p +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_dep_k;
    Copy_of_Robot_leg_3_0_B.Sum_lb = pulseWidth - Copy_of_Robot_leg_3_0_B.Abs_i;

    /* DeadZone: '<S491>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_lb > Copy_of_Robot_leg_3_0_P.DeadZone_End_k)
    {
      Copy_of_Robot_leg_3_0_B.DeadZone_b = Copy_of_Robot_leg_3_0_B.Sum_lb -
        Copy_of_Robot_leg_3_0_P.DeadZone_End_k;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_lb >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start_n5) {
      Copy_of_Robot_leg_3_0_B.DeadZone_b = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone_b = Copy_of_Robot_leg_3_0_B.Sum_lb -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start_n5;
    }

    /* End of DeadZone: '<S491>/Dead Zone' */

    /* Signum: '<S491>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[139];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_l = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_l = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_l = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx_l = (rtNaN);
    }

    /* End of Signum: '<S491>/Sign x' */

    /* Product: '<S491>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_i = Copy_of_Robot_leg_3_0_B.Signx_l *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[142];

    /* Gain: '<S491>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_g = Copy_of_Robot_leg_3_0_P.Gain2_Gain_h *
      Copy_of_Robot_leg_3_0_B.Product_i;

    /* Signum: '<S491>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[142];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_a = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_a = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_a = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx_a = (rtNaN);
    }

    /* End of Signum: '<S491>/Sign vx' */

    /* Gain: '<S502>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force_m =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_k_contact_d *
      Copy_of_Robot_leg_3_0_B.DeadZone_b;

    /* Product: '<S478>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce_j = Copy_of_Robot_leg_3_0_B.Signx_l *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force_m;

    /* Signum: '<S502>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone_b;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_k = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_k = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_k = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign_k = (rtNaN);
    }

    /* End of Signum: '<S502>/Sign' */

    /* Abs: '<S502>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_b = fabs
      (Copy_of_Robot_leg_3_0_B.Sign_k);

    /* Saturate: '<S502>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_g;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_g5;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_e;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation_j = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation_j = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation_j = pulseWidth;
    }

    /* End of Saturate: '<S502>/Saturation' */

    /* Gain: '<S502>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_b_contact_j;
    Copy_of_Robot_leg_3_0_B.Damping_Force_p = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation_j;

    /* Product: '<S502>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_nm =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_b *
      Copy_of_Robot_leg_3_0_B.Damping_Force_p;

    /* Product: '<S478>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce_j =
      Copy_of_Robot_leg_3_0_B.Damping_Force_nm *
      Copy_of_Robot_leg_3_0_B.Signvx_a;

    /* Sum: '<S494>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_kg = Copy_of_Robot_leg_3_0_B.SprForce_j +
      Copy_of_Robot_leg_3_0_B.DampForce_j;

    /* SignalConversion: '<S494>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S494>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_o[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_l;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_o[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_l;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_o[2] =
      Copy_of_Robot_leg_3_0_B.Sum_kg;

    /* Gain: '<S494>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_cq[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_g *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_o[0];
    Copy_of_Robot_leg_3_0_B.Gain_cq[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_g *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_o[1];
    Copy_of_Robot_leg_3_0_B.Gain_cq[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_g *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_o[2];

    /* Product: '<S498>/Product3' incorporates:
     *  Constant: '<S498>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_e = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[135]
      * Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_ra_p;

    /* Product: '<S493>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_ha = Copy_of_Robot_leg_3_0_B.Signx_l *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[141];

    /* Sum: '<S498>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy_e = Copy_of_Robot_leg_3_0_B.Product3_e +
      Copy_of_Robot_leg_3_0_B.Product5_ha;

    /* Math: '<S498>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_o = Copy_of_Robot_leg_3_0_B.slipy_e *
      Copy_of_Robot_leg_3_0_B.slipy_e;

    /* Product: '<S498>/Product4' incorporates:
     *  Constant: '<S498>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4_p =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_ra_p *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[136];

    /* Product: '<S493>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6_g = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[140]
      * Copy_of_Robot_leg_3_0_B.Signx_l;

    /* Sum: '<S498>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx_k = Copy_of_Robot_leg_3_0_B.Product6_g -
      Copy_of_Robot_leg_3_0_B.Product4_p;

    /* Math: '<S498>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1_n = Copy_of_Robot_leg_3_0_B.slipx_k *
      Copy_of_Robot_leg_3_0_B.slipx_k;

    /* Sum: '<S498>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3_p = Copy_of_Robot_leg_3_0_B.MathFunction_o +
      Copy_of_Robot_leg_3_0_B.MathFunction1_n;

    /* Sqrt: '<S498>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt_l = sqrt(Copy_of_Robot_leg_3_0_B.Sum3_p);

    /* Lookup_n-D: '<S500>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_e = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt_l,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_ab,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_nk, 5U);

    /* Product: '<S500>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_bb =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_e *
      Copy_of_Robot_leg_3_0_B.Gain_cq[2];

    /* Gain: '<S500>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force_i =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_f1 * Copy_of_Robot_leg_3_0_B.Product_bb;

    /* Trigonometry: '<S498>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_l = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy_e, Copy_of_Robot_leg_3_0_B.slipx_k);

    /* Trigonometry: '<S493>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_g = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_l);

    /* Product: '<S493>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_l =
      Copy_of_Robot_leg_3_0_B.Friction_Force_i *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_g;

    /* Trigonometry: '<S493>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_j = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_l);

    /* Product: '<S493>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_po =
      Copy_of_Robot_leg_3_0_B.Friction_Force_i *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_j;

    /* SignalConversion: '<S493>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S493>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_h[0] =
      Copy_of_Robot_leg_3_0_B.Product3_l;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_h[1] =
      Copy_of_Robot_leg_3_0_B.Product4_po;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_h[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value_k;

    /* Gain: '<S493>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_cp[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_f *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_h[0];

    /* Sum: '<S478>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_o[0] = Copy_of_Robot_leg_3_0_B.Gain_cq[0] +
      Copy_of_Robot_leg_3_0_B.Gain_cp[0];

    /* SignalConversion: '<S478>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_a0[6] = Copy_of_Robot_leg_3_0_B.FPla_o[0];

    /* Gain: '<S493>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_cp[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_f *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_h[1];

    /* Sum: '<S478>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_o[1] = Copy_of_Robot_leg_3_0_B.Gain_cq[1] +
      Copy_of_Robot_leg_3_0_B.Gain_cp[1];

    /* SignalConversion: '<S478>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_a0[7] = Copy_of_Robot_leg_3_0_B.FPla_o[1];

    /* Gain: '<S493>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_cp[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_f *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_h[2];

    /* Sum: '<S478>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_o[2] = Copy_of_Robot_leg_3_0_B.Gain_cq[2] +
      Copy_of_Robot_leg_3_0_B.Gain_cp[2];

    /* SignalConversion: '<S478>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_a0[8] = Copy_of_Robot_leg_3_0_B.FPla_o[2];

    /* Product: '<S492>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_n = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[138] *
      Copy_of_Robot_leg_3_0_B.FPla_o[2];

    /* Product: '<S492>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_h = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[139]
      * Copy_of_Robot_leg_3_0_B.FPla_o[1];

    /* Product: '<S492>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_o = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[139]
      * Copy_of_Robot_leg_3_0_B.FPla_o[0];

    /* Product: '<S492>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_h = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[137]
      * Copy_of_Robot_leg_3_0_B.FPla_o[2];

    /* Product: '<S492>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_e = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[137]
      * Copy_of_Robot_leg_3_0_B.FPla_o[1];

    /* Product: '<S492>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_jd = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[138]
      * Copy_of_Robot_leg_3_0_B.FPla_o[0];

    /* Sum: '<S492>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_a0[9] = Copy_of_Robot_leg_3_0_B.Product_n -
      Copy_of_Robot_leg_3_0_B.Product1_h;

    /* Sum: '<S492>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph_a0[10] = Copy_of_Robot_leg_3_0_B.Product2_o -
      Copy_of_Robot_leg_3_0_B.Product3_h;

    /* Sum: '<S492>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph_a0[11] = Copy_of_Robot_leg_3_0_B.Product4_e -
      Copy_of_Robot_leg_3_0_B.Product5_jd;

    /* Product: '<S493>/Product7' incorporates:
     *  Constant: '<S493>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7_a[0] =
      Copy_of_Robot_leg_3_0_P.Fx2_Value_ip[0] * Copy_of_Robot_leg_3_0_B.Signx_l;
    Copy_of_Robot_leg_3_0_B.Product7_a[1] =
      Copy_of_Robot_leg_3_0_P.Fx2_Value_ip[1] * Copy_of_Robot_leg_3_0_B.Signx_l;
    Copy_of_Robot_leg_3_0_B.Product7_a[2] =
      Copy_of_Robot_leg_3_0_P.Fx2_Value_ip[2] * Copy_of_Robot_leg_3_0_B.Signx_l;

    /* Product: '<S496>/Product' incorporates:
     *  Constant: '<S493>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_bbt = Copy_of_Robot_leg_3_0_B.Product7_a[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_k;

    /* Product: '<S496>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_h1 = Copy_of_Robot_leg_3_0_B.Product7_a[2] *
      Copy_of_Robot_leg_3_0_B.Product4_po;

    /* Product: '<S496>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_a = Copy_of_Robot_leg_3_0_B.Product7_a[2] *
      Copy_of_Robot_leg_3_0_B.Product3_l;

    /* Product: '<S496>/Product3' incorporates:
     *  Constant: '<S493>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_i = Copy_of_Robot_leg_3_0_B.Product7_a[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_k;

    /* Product: '<S496>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_f = Copy_of_Robot_leg_3_0_B.Product7_a[0] *
      Copy_of_Robot_leg_3_0_B.Product4_po;

    /* Product: '<S496>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_ju = Copy_of_Robot_leg_3_0_B.Product7_a[1] *
      Copy_of_Robot_leg_3_0_B.Product3_l;

    /* Sum: '<S496>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_g = Copy_of_Robot_leg_3_0_B.Product_bbt -
      Copy_of_Robot_leg_3_0_B.Product1_h1;

    /* Sum: '<S496>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1_j = Copy_of_Robot_leg_3_0_B.Product2_a -
      Copy_of_Robot_leg_3_0_B.Product3_i;

    /* Sum: '<S496>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2_e = Copy_of_Robot_leg_3_0_B.Product4_f -
      Copy_of_Robot_leg_3_0_B.Product5_ju;

    /* Product: '<S493>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_p,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_h,
      Copy_of_Robot_leg_3_0_B.Product1_cp);

    /* SignalConversion: '<S493>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_c[0] =
      Copy_of_Robot_leg_3_0_B.Sum_g;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_c[1] =
      Copy_of_Robot_leg_3_0_B.Sum1_j;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_c[2] =
      Copy_of_Robot_leg_3_0_B.Sum2_e;

    /* Product: '<S493>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_p,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_c,
      &Copy_of_Robot_leg_3_0_B.FSph_a0[3]);

    /* Product: '<S494>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_p,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_o,
      Copy_of_Robot_leg_3_0_B.Product2_m);

    /* Sum: '<S478>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_a0[0] = Copy_of_Robot_leg_3_0_B.Product2_m[0] +
      Copy_of_Robot_leg_3_0_B.Product1_cp[0];
    Copy_of_Robot_leg_3_0_B.FSph_a0[1] = Copy_of_Robot_leg_3_0_B.Product2_m[1] +
      Copy_of_Robot_leg_3_0_B.Product1_cp[1];
    Copy_of_Robot_leg_3_0_B.FSph_a0[2] = Copy_of_Robot_leg_3_0_B.Product2_m[2] +
      Copy_of_Robot_leg_3_0_B.Product1_cp[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_g);
    }

    /* End of Outputs for SubSystem: '<S324>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S324>/No Force' incorporates:
     *  ActionPort: '<S479>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph_a0[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value_d[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_p);
    }

    /* End of Outputs for SubSystem: '<S324>/No Force' */
    break;
  }

  /* End of If: '<S324>/If1' */

  /* Product: '<S477>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_k[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.Sum_kg;
  Copy_of_Robot_leg_3_0_B.Product_k[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.Gain_cp[0];
  Copy_of_Robot_leg_3_0_B.Product_k[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.Gain_cp[1];
  Copy_of_Robot_leg_3_0_B.Product_k[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.Gain_cp[2];
  Copy_of_Robot_leg_3_0_B.Product_k[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.DeadZone_b;
  Copy_of_Robot_leg_3_0_B.Product_k[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.Gain2_g;
  Copy_of_Robot_leg_3_0_B.Product_k[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.SprForce_j;
  Copy_of_Robot_leg_3_0_B.Product_k[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc *
    Copy_of_Robot_leg_3_0_B.DampForce_j;

  /* Gain: '<S523>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_p = Copy_of_Robot_leg_3_0_P.Gain_Gain_dr *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[154];

  /* Abs: '<S523>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs_d = fabs(Copy_of_Robot_leg_3_0_B.Gain_p);

  /* RelationalOperator: '<S529>/Compare' incorporates:
   *  Constant: '<S529>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_b = (Copy_of_Robot_leg_3_0_B.Abs_d <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_lenx);

  /* Gain: '<S523>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_o = Copy_of_Robot_leg_3_0_P.Gain1_Gain_p *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[155];

  /* Abs: '<S523>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1_l = fabs(Copy_of_Robot_leg_3_0_B.Gain1_o);

  /* RelationalOperator: '<S530>/Compare' incorporates:
   *  Constant: '<S530>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_f = (Copy_of_Robot_leg_3_0_B.Abs1_l <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_leny);

  /* Logic: '<S523>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator_e = (Copy_of_Robot_leg_3_0_B.Compare_b
    && Copy_of_Robot_leg_3_0_B.Compare_f);

  /* DataTypeConversion: '<S523>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion_l =
    Copy_of_Robot_leg_3_0_B.LogicalOperator_e;

  /* Reshape: '<S564>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE_j[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[143], 9U * sizeof(real_T));

  /* If: '<S325>/If1' incorporates:
   *  Constant: '<S527>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion_l > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_m = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_m;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S325>/Forces' incorporates:
     *  ActionPort: '<S526>/Action Port'
     */
    /* Abs: '<S539>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_c = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[156]);

    /* Sum: '<S539>/Sum' incorporates:
     *  Constant: '<S539>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_ra_i +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_dep_a;
    Copy_of_Robot_leg_3_0_B.Sum_ml = pulseWidth - Copy_of_Robot_leg_3_0_B.Abs_c;

    /* DeadZone: '<S539>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_ml > Copy_of_Robot_leg_3_0_P.DeadZone_End_j)
    {
      Copy_of_Robot_leg_3_0_B.DeadZone = Copy_of_Robot_leg_3_0_B.Sum_ml -
        Copy_of_Robot_leg_3_0_P.DeadZone_End_j;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_ml >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start_o) {
      Copy_of_Robot_leg_3_0_B.DeadZone = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone = Copy_of_Robot_leg_3_0_B.Sum_ml -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start_o;
    }

    /* End of DeadZone: '<S539>/Dead Zone' */

    /* Signum: '<S539>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[156];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx = (rtNaN);
    }

    /* End of Signum: '<S539>/Sign x' */

    /* Product: '<S539>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_b = Copy_of_Robot_leg_3_0_B.Signx *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[159];

    /* Gain: '<S539>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_i = Copy_of_Robot_leg_3_0_P.Gain2_Gain_e *
      Copy_of_Robot_leg_3_0_B.Product_b;

    /* Signum: '<S539>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[159];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx = (rtNaN);
    }

    /* End of Signum: '<S539>/Sign vx' */

    /* Gain: '<S550>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_k_contact_e *
      Copy_of_Robot_leg_3_0_B.DeadZone;

    /* Product: '<S526>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce = Copy_of_Robot_leg_3_0_B.Signx *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force;

    /* Signum: '<S550>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign = (rtNaN);
    }

    /* End of Signum: '<S550>/Sign' */

    /* Abs: '<S550>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable = fabs
      (Copy_of_Robot_leg_3_0_B.Sign);

    /* Saturate: '<S550>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_i;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_af;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_f;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation = pulseWidth;
    }

    /* End of Saturate: '<S550>/Saturation' */

    /* Gain: '<S550>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_b_contact_h;
    Copy_of_Robot_leg_3_0_B.Damping_Force = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation;

    /* Product: '<S550>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_n =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable *
      Copy_of_Robot_leg_3_0_B.Damping_Force;

    /* Product: '<S526>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce = Copy_of_Robot_leg_3_0_B.Damping_Force_n *
      Copy_of_Robot_leg_3_0_B.Signvx;

    /* Sum: '<S542>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_kn = Copy_of_Robot_leg_3_0_B.SprForce +
      Copy_of_Robot_leg_3_0_B.DampForce;

    /* SignalConversion: '<S542>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S542>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2In[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_oe;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2In[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_oe;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2In[2] =
      Copy_of_Robot_leg_3_0_B.Sum_kn;

    /* Gain: '<S542>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_mv[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_ns *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2In[0];
    Copy_of_Robot_leg_3_0_B.Gain_mv[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_ns *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2In[1];
    Copy_of_Robot_leg_3_0_B.Gain_mv[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_ns *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2In[2];

    /* Product: '<S546>/Product3' incorporates:
     *  Constant: '<S546>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3 = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[152] *
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_ra_i;

    /* Product: '<S541>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5 = Copy_of_Robot_leg_3_0_B.Signx *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[158];

    /* Sum: '<S546>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy = Copy_of_Robot_leg_3_0_B.Product3 +
      Copy_of_Robot_leg_3_0_B.Product5;

    /* Math: '<S546>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_mn = Copy_of_Robot_leg_3_0_B.slipy *
      Copy_of_Robot_leg_3_0_B.slipy;

    /* Product: '<S546>/Product4' incorporates:
     *  Constant: '<S546>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4 =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_ra_i *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[153];

    /* Product: '<S541>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6 = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[157] *
      Copy_of_Robot_leg_3_0_B.Signx;

    /* Sum: '<S546>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx = Copy_of_Robot_leg_3_0_B.Product6 -
      Copy_of_Robot_leg_3_0_B.Product4;

    /* Math: '<S546>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1 = Copy_of_Robot_leg_3_0_B.slipx *
      Copy_of_Robot_leg_3_0_B.slipx;

    /* Sum: '<S546>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3 = Copy_of_Robot_leg_3_0_B.MathFunction_mn +
      Copy_of_Robot_leg_3_0_B.MathFunction1;

    /* Sqrt: '<S546>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt = sqrt(Copy_of_Robot_leg_3_0_B.Sum3);

    /* Lookup_n-D: '<S548>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVelocity = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_lt,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_in, 5U);

    /* Product: '<S548>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_ke =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVelocity *
      Copy_of_Robot_leg_3_0_B.Gain_mv[2];

    /* Gain: '<S548>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_n * Copy_of_Robot_leg_3_0_B.Product_ke;

    /* Trigonometry: '<S546>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy, Copy_of_Robot_leg_3_0_B.slipx);

    /* Trigonometry: '<S541>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1 = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction);

    /* Product: '<S541>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_g = Copy_of_Robot_leg_3_0_B.Friction_Force *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1;

    /* Trigonometry: '<S541>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_d = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction);

    /* Product: '<S541>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_k = Copy_of_Robot_leg_3_0_B.Friction_Force *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_d;

    /* SignalConversion: '<S541>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S541>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1In[0] =
      Copy_of_Robot_leg_3_0_B.Product3_g;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1In[1] =
      Copy_of_Robot_leg_3_0_B.Product4_k;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1In[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value_o;

    /* Gain: '<S541>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_b5[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_jj *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1In[0];

    /* Sum: '<S526>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla[0] = Copy_of_Robot_leg_3_0_B.Gain_mv[0] +
      Copy_of_Robot_leg_3_0_B.Gain_b5[0];

    /* SignalConversion: '<S526>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_n[6] = Copy_of_Robot_leg_3_0_B.FPla[0];

    /* Gain: '<S541>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_b5[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_jj *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1In[1];

    /* Sum: '<S526>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla[1] = Copy_of_Robot_leg_3_0_B.Gain_mv[1] +
      Copy_of_Robot_leg_3_0_B.Gain_b5[1];

    /* SignalConversion: '<S526>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_n[7] = Copy_of_Robot_leg_3_0_B.FPla[1];

    /* Gain: '<S541>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_b5[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_jj *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1In[2];

    /* Sum: '<S526>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla[2] = Copy_of_Robot_leg_3_0_B.Gain_mv[2] +
      Copy_of_Robot_leg_3_0_B.Gain_b5[2];

    /* SignalConversion: '<S526>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_n[8] = Copy_of_Robot_leg_3_0_B.FPla[2];

    /* Product: '<S540>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_jb = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[155]
      * Copy_of_Robot_leg_3_0_B.FPla[2];

    /* Product: '<S540>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1 = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[156] *
      Copy_of_Robot_leg_3_0_B.FPla[1];

    /* Product: '<S540>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2 = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[156] *
      Copy_of_Robot_leg_3_0_B.FPla[0];

    /* Product: '<S540>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_m = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[154]
      * Copy_of_Robot_leg_3_0_B.FPla[2];

    /* Product: '<S540>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_b = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[154]
      * Copy_of_Robot_leg_3_0_B.FPla[1];

    /* Product: '<S540>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_h = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[155]
      * Copy_of_Robot_leg_3_0_B.FPla[0];

    /* Sum: '<S540>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_n[9] = Copy_of_Robot_leg_3_0_B.Product_jb -
      Copy_of_Robot_leg_3_0_B.Product1;

    /* Sum: '<S540>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph_n[10] = Copy_of_Robot_leg_3_0_B.Product2 -
      Copy_of_Robot_leg_3_0_B.Product3_m;

    /* Sum: '<S540>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph_n[11] = Copy_of_Robot_leg_3_0_B.Product4_b -
      Copy_of_Robot_leg_3_0_B.Product5_h;

    /* Product: '<S541>/Product7' incorporates:
     *  Constant: '<S541>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7[0] = Copy_of_Robot_leg_3_0_P.Fx2_Value_he[0]
      * Copy_of_Robot_leg_3_0_B.Signx;
    Copy_of_Robot_leg_3_0_B.Product7[1] = Copy_of_Robot_leg_3_0_P.Fx2_Value_he[1]
      * Copy_of_Robot_leg_3_0_B.Signx;
    Copy_of_Robot_leg_3_0_B.Product7[2] = Copy_of_Robot_leg_3_0_P.Fx2_Value_he[2]
      * Copy_of_Robot_leg_3_0_B.Signx;

    /* Product: '<S544>/Product' incorporates:
     *  Constant: '<S541>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_eg = Copy_of_Robot_leg_3_0_B.Product7[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_o;

    /* Product: '<S544>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_c = Copy_of_Robot_leg_3_0_B.Product7[2] *
      Copy_of_Robot_leg_3_0_B.Product4_k;

    /* Product: '<S544>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_n = Copy_of_Robot_leg_3_0_B.Product7[2] *
      Copy_of_Robot_leg_3_0_B.Product3_g;

    /* Product: '<S544>/Product3' incorporates:
     *  Constant: '<S541>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_a = Copy_of_Robot_leg_3_0_B.Product7[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_o;

    /* Product: '<S544>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_c = Copy_of_Robot_leg_3_0_B.Product7[0] *
      Copy_of_Robot_leg_3_0_B.Product4_k;

    /* Product: '<S544>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_j = Copy_of_Robot_leg_3_0_B.Product7[1] *
      Copy_of_Robot_leg_3_0_B.Product3_g;

    /* Sum: '<S544>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_m4 = Copy_of_Robot_leg_3_0_B.Product_eg -
      Copy_of_Robot_leg_3_0_B.Product1_c;

    /* Sum: '<S544>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1 = Copy_of_Robot_leg_3_0_B.Product2_n -
      Copy_of_Robot_leg_3_0_B.Product3_a;

    /* Sum: '<S544>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2 = Copy_of_Robot_leg_3_0_B.Product4_c -
      Copy_of_Robot_leg_3_0_B.Product5_j;

    /* Product: '<S541>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_j,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1In,
      Copy_of_Robot_leg_3_0_B.Product1_i);

    /* SignalConversion: '<S541>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_h[0] =
      Copy_of_Robot_leg_3_0_B.Sum_m4;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_h[1] =
      Copy_of_Robot_leg_3_0_B.Sum1;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_h[2] =
      Copy_of_Robot_leg_3_0_B.Sum2;

    /* Product: '<S541>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_j,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_h,
      &Copy_of_Robot_leg_3_0_B.FSph_n[3]);

    /* Product: '<S542>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_j,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2In,
      Copy_of_Robot_leg_3_0_B.Product2_j);

    /* Sum: '<S526>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_n[0] = Copy_of_Robot_leg_3_0_B.Product2_j[0] +
      Copy_of_Robot_leg_3_0_B.Product1_i[0];
    Copy_of_Robot_leg_3_0_B.FSph_n[1] = Copy_of_Robot_leg_3_0_B.Product2_j[1] +
      Copy_of_Robot_leg_3_0_B.Product1_i[1];
    Copy_of_Robot_leg_3_0_B.FSph_n[2] = Copy_of_Robot_leg_3_0_B.Product2_j[2] +
      Copy_of_Robot_leg_3_0_B.Product1_i[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S325>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S325>/No Force' incorporates:
     *  ActionPort: '<S527>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph_n[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value_du[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S325>/No Force' */
    break;
  }

  /* End of If: '<S325>/If1' */

  /* Product: '<S525>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_f[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.Sum_kn;
  Copy_of_Robot_leg_3_0_B.Product_f[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.Gain_b5[0];
  Copy_of_Robot_leg_3_0_B.Product_f[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.Gain_b5[1];
  Copy_of_Robot_leg_3_0_B.Product_f[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.Gain_b5[2];
  Copy_of_Robot_leg_3_0_B.Product_f[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.DeadZone;
  Copy_of_Robot_leg_3_0_B.Product_f[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.Gain2_i;
  Copy_of_Robot_leg_3_0_B.Product_f[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.SprForce;
  Copy_of_Robot_leg_3_0_B.Product_f[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_l *
    Copy_of_Robot_leg_3_0_B.DampForce;

  /* Sum: '<S312>/Add' */
  Copy_of_Robot_leg_3_0_B.NormalForce = ((Copy_of_Robot_leg_3_0_B.Product[0] +
    Copy_of_Robot_leg_3_0_B.Product_g[0]) + Copy_of_Robot_leg_3_0_B.Product_k[0])
    + Copy_of_Robot_leg_3_0_B.Product_f[0];

  /* Sum: '<S312>/Add1' */
  Copy_of_Robot_leg_3_0_B.Add1_f[0] = ((Copy_of_Robot_leg_3_0_B.Product[1] +
    Copy_of_Robot_leg_3_0_B.Product_g[1]) + Copy_of_Robot_leg_3_0_B.Product_k[1])
    + Copy_of_Robot_leg_3_0_B.Product_f[1];

  /* Math: '<S312>/Math Function' */
  Copy_of_Robot_leg_3_0_B.MathFunction_g[0] = Copy_of_Robot_leg_3_0_B.Add1_f[0] *
    Copy_of_Robot_leg_3_0_B.Add1_f[0];

  /* Sum: '<S312>/Add1' */
  Copy_of_Robot_leg_3_0_B.Add1_f[1] = ((Copy_of_Robot_leg_3_0_B.Product[2] +
    Copy_of_Robot_leg_3_0_B.Product_g[2]) + Copy_of_Robot_leg_3_0_B.Product_k[2])
    + Copy_of_Robot_leg_3_0_B.Product_f[2];

  /* Math: '<S312>/Math Function' */
  Copy_of_Robot_leg_3_0_B.MathFunction_g[1] = Copy_of_Robot_leg_3_0_B.Add1_f[1] *
    Copy_of_Robot_leg_3_0_B.Add1_f[1];

  /* Sum: '<S312>/Add1' */
  Copy_of_Robot_leg_3_0_B.Add1_f[2] = ((Copy_of_Robot_leg_3_0_B.Product[3] +
    Copy_of_Robot_leg_3_0_B.Product_g[3]) + Copy_of_Robot_leg_3_0_B.Product_k[3])
    + Copy_of_Robot_leg_3_0_B.Product_f[3];

  /* Math: '<S312>/Math Function' */
  Copy_of_Robot_leg_3_0_B.MathFunction_g[2] = Copy_of_Robot_leg_3_0_B.Add1_f[2] *
    Copy_of_Robot_leg_3_0_B.Add1_f[2];

  /* Sum: '<S312>/Sum of Elements' */
  pulseWidth = Copy_of_Robot_leg_3_0_B.MathFunction_g[0];
  pulseWidth += Copy_of_Robot_leg_3_0_B.MathFunction_g[1];
  pulseWidth += Copy_of_Robot_leg_3_0_B.MathFunction_g[2];
  Copy_of_Robot_leg_3_0_B.SumofElements = pulseWidth;

  /* Sqrt: '<S312>/Sqrt' */
  Copy_of_Robot_leg_3_0_B.FrictionForce = sqrt
    (Copy_of_Robot_leg_3_0_B.SumofElements);

  /* Gain: '<S352>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_e = Copy_of_Robot_leg_3_0_P.GAIN_Gain_o *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[16];

  /* Gain: '<S115>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_p1 = Copy_of_Robot_leg_3_0_P.Gain_Gain_nz *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[35];

  /* Abs: '<S115>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs_f = fabs(Copy_of_Robot_leg_3_0_B.Gain_p1);

  /* RelationalOperator: '<S121>/Compare' incorporates:
   *  Constant: '<S121>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_n1 = (Copy_of_Robot_leg_3_0_B.Abs_f <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_lenx_d);

  /* Gain: '<S115>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_b = Copy_of_Robot_leg_3_0_P.Gain1_Gain_d *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[36];

  /* Abs: '<S115>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1_k = fabs(Copy_of_Robot_leg_3_0_B.Gain1_b);

  /* RelationalOperator: '<S122>/Compare' incorporates:
   *  Constant: '<S122>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_k = (Copy_of_Robot_leg_3_0_B.Abs1_k <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_leny_n);

  /* Logic: '<S115>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator_n =
    (Copy_of_Robot_leg_3_0_B.Compare_n1 && Copy_of_Robot_leg_3_0_B.Compare_k);

  /* DataTypeConversion: '<S115>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion_a =
    Copy_of_Robot_leg_3_0_B.LogicalOperator_n;

  /* Reshape: '<S156>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE_l[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[24], 9U * sizeof(real_T));

  /* If: '<S58>/If1' incorporates:
   *  Constant: '<S119>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion_a > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_p = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_p;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S58>/Forces' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* Abs: '<S131>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_ky = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[37]);

    /* Sum: '<S131>/Sum' incorporates:
     *  Constant: '<S131>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_depth;
    Copy_of_Robot_leg_3_0_B.Sum_l4 = pulseWidth - Copy_of_Robot_leg_3_0_B.Abs_ky;

    /* DeadZone: '<S131>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_l4 > Copy_of_Robot_leg_3_0_P.DeadZone_End) {
      Copy_of_Robot_leg_3_0_B.DeadZone_ko = Copy_of_Robot_leg_3_0_B.Sum_l4 -
        Copy_of_Robot_leg_3_0_P.DeadZone_End;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_l4 >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start) {
      Copy_of_Robot_leg_3_0_B.DeadZone_ko = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone_ko = Copy_of_Robot_leg_3_0_B.Sum_l4 -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start;
    }

    /* End of DeadZone: '<S131>/Dead Zone' */

    /* Signum: '<S131>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[37];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_l2 = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_l2 = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_l2 = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx_l2 = (rtNaN);
    }

    /* End of Signum: '<S131>/Sign x' */

    /* Product: '<S131>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_g0 = Copy_of_Robot_leg_3_0_B.Signx_l2 *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[40];

    /* Gain: '<S131>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_l = Copy_of_Robot_leg_3_0_P.Gain2_Gain *
      Copy_of_Robot_leg_3_0_B.Product_g0;

    /* Signum: '<S131>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[40];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_ax = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_ax = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_ax = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx_ax = (rtNaN);
    }

    /* End of Signum: '<S131>/Sign vx' */

    /* Gain: '<S142>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force_k0 =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_k_contact *
      Copy_of_Robot_leg_3_0_B.DeadZone_ko;

    /* Product: '<S118>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce_ny = Copy_of_Robot_leg_3_0_B.Signx_l2 *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force_k0;

    /* Signum: '<S142>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone_ko;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_kv = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_kv = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_kv = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign_kv = (rtNaN);
    }

    /* End of Signum: '<S142>/Sign' */

    /* Abs: '<S142>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_o = fabs
      (Copy_of_Robot_leg_3_0_B.Sign_kv);

    /* Saturate: '<S142>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_l;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation_dc = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation_dc = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation_dc = pulseWidth;
    }

    /* End of Saturate: '<S142>/Saturation' */

    /* Gain: '<S142>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_b_contact;
    Copy_of_Robot_leg_3_0_B.Damping_Force_l = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation_dc;

    /* Product: '<S142>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_d2 =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_o *
      Copy_of_Robot_leg_3_0_B.Damping_Force_l;

    /* Product: '<S118>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce_b =
      Copy_of_Robot_leg_3_0_B.Damping_Force_d2 *
      Copy_of_Robot_leg_3_0_B.Signvx_ax;

    /* Sum: '<S134>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_bz = Copy_of_Robot_leg_3_0_B.SprForce_ny +
      Copy_of_Robot_leg_3_0_B.DampForce_b;

    /* SignalConversion: '<S134>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S134>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_kh[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_kh[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_kh[2] =
      Copy_of_Robot_leg_3_0_B.Sum_bz;

    /* Gain: '<S134>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_em[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_kh[0];
    Copy_of_Robot_leg_3_0_B.Gain_em[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_kh[1];
    Copy_of_Robot_leg_3_0_B.Gain_em[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_kh[2];

    /* Product: '<S138>/Product3' incorporates:
     *  Constant: '<S138>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_nd = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[33]
      * Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad;

    /* Product: '<S133>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_mo = Copy_of_Robot_leg_3_0_B.Signx_l2 *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[39];

    /* Sum: '<S138>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy_j = Copy_of_Robot_leg_3_0_B.Product3_nd +
      Copy_of_Robot_leg_3_0_B.Product5_mo;

    /* Math: '<S138>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_gn = Copy_of_Robot_leg_3_0_B.slipy_j *
      Copy_of_Robot_leg_3_0_B.slipy_j;

    /* Product: '<S138>/Product4' incorporates:
     *  Constant: '<S138>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4_m =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[34];

    /* Product: '<S133>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6_a = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[38] *
      Copy_of_Robot_leg_3_0_B.Signx_l2;

    /* Sum: '<S138>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx_p = Copy_of_Robot_leg_3_0_B.Product6_a -
      Copy_of_Robot_leg_3_0_B.Product4_m;

    /* Math: '<S138>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1_aw = Copy_of_Robot_leg_3_0_B.slipx_p *
      Copy_of_Robot_leg_3_0_B.slipx_p;

    /* Sum: '<S138>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3_dn = Copy_of_Robot_leg_3_0_B.MathFunction_gn +
      Copy_of_Robot_leg_3_0_B.MathFunction1_aw;

    /* Sqrt: '<S138>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt_o = sqrt(Copy_of_Robot_leg_3_0_B.Sum3_dn);

    /* Lookup_n-D: '<S140>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_id = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt_o,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_l,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVelocity, 5U);

    /* Product: '<S140>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_mc =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_id *
      Copy_of_Robot_leg_3_0_B.Gain_em[2];

    /* Gain: '<S140>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force_p =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_l * Copy_of_Robot_leg_3_0_B.Product_mc;

    /* Trigonometry: '<S138>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pg = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy_j, Copy_of_Robot_leg_3_0_B.slipx_p);

    /* Trigonometry: '<S133>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_oc = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pg);

    /* Product: '<S133>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_bw =
      Copy_of_Robot_leg_3_0_B.Friction_Force_p *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_oc;

    /* Trigonometry: '<S133>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_lx = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pg);

    /* Product: '<S133>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_at =
      Copy_of_Robot_leg_3_0_B.Friction_Force_p *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_lx;

    /* SignalConversion: '<S133>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S133>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_au[0] =
      Copy_of_Robot_leg_3_0_B.Product3_bw;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_au[1] =
      Copy_of_Robot_leg_3_0_B.Product4_at;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_au[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value;

    /* Gain: '<S133>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_hg[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_m *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_au[0];

    /* Sum: '<S118>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_j[0] = Copy_of_Robot_leg_3_0_B.Gain_em[0] +
      Copy_of_Robot_leg_3_0_B.Gain_hg[0];

    /* SignalConversion: '<S118>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph[6] = Copy_of_Robot_leg_3_0_B.FPla_j[0];

    /* Gain: '<S133>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_hg[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_m *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_au[1];

    /* Sum: '<S118>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_j[1] = Copy_of_Robot_leg_3_0_B.Gain_em[1] +
      Copy_of_Robot_leg_3_0_B.Gain_hg[1];

    /* SignalConversion: '<S118>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph[7] = Copy_of_Robot_leg_3_0_B.FPla_j[1];

    /* Gain: '<S133>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_hg[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_m *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_au[2];

    /* Sum: '<S118>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_j[2] = Copy_of_Robot_leg_3_0_B.Gain_em[2] +
      Copy_of_Robot_leg_3_0_B.Gain_hg[2];

    /* SignalConversion: '<S118>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph[8] = Copy_of_Robot_leg_3_0_B.FPla_j[2];

    /* Product: '<S132>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_mw = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[36] *
      Copy_of_Robot_leg_3_0_B.FPla_j[2];

    /* Product: '<S132>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_oq = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[37]
      * Copy_of_Robot_leg_3_0_B.FPla_j[1];

    /* Product: '<S132>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_f = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[37] *
      Copy_of_Robot_leg_3_0_B.FPla_j[0];

    /* Product: '<S132>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_ax = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[35]
      * Copy_of_Robot_leg_3_0_B.FPla_j[2];

    /* Product: '<S132>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_ab = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[35]
      * Copy_of_Robot_leg_3_0_B.FPla_j[1];

    /* Product: '<S132>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_gg = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[36]
      * Copy_of_Robot_leg_3_0_B.FPla_j[0];

    /* Sum: '<S132>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph[9] = Copy_of_Robot_leg_3_0_B.Product_mw -
      Copy_of_Robot_leg_3_0_B.Product1_oq;

    /* Sum: '<S132>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph[10] = Copy_of_Robot_leg_3_0_B.Product2_f -
      Copy_of_Robot_leg_3_0_B.Product3_ax;

    /* Sum: '<S132>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph[11] = Copy_of_Robot_leg_3_0_B.Product4_ab -
      Copy_of_Robot_leg_3_0_B.Product5_gg;

    /* Product: '<S133>/Product7' incorporates:
     *  Constant: '<S133>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7_c[0] = Copy_of_Robot_leg_3_0_P.Fx2_Value[0]
      * Copy_of_Robot_leg_3_0_B.Signx_l2;
    Copy_of_Robot_leg_3_0_B.Product7_c[1] = Copy_of_Robot_leg_3_0_P.Fx2_Value[1]
      * Copy_of_Robot_leg_3_0_B.Signx_l2;
    Copy_of_Robot_leg_3_0_B.Product7_c[2] = Copy_of_Robot_leg_3_0_P.Fx2_Value[2]
      * Copy_of_Robot_leg_3_0_B.Signx_l2;

    /* Product: '<S136>/Product' incorporates:
     *  Constant: '<S133>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_ms = Copy_of_Robot_leg_3_0_B.Product7_c[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value;

    /* Product: '<S136>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_kj = Copy_of_Robot_leg_3_0_B.Product7_c[2] *
      Copy_of_Robot_leg_3_0_B.Product4_at;

    /* Product: '<S136>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_i1 = Copy_of_Robot_leg_3_0_B.Product7_c[2] *
      Copy_of_Robot_leg_3_0_B.Product3_bw;

    /* Product: '<S136>/Product3' incorporates:
     *  Constant: '<S133>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_ny = Copy_of_Robot_leg_3_0_B.Product7_c[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value;

    /* Product: '<S136>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_d1 = Copy_of_Robot_leg_3_0_B.Product7_c[0] *
      Copy_of_Robot_leg_3_0_B.Product4_at;

    /* Product: '<S136>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_i3 = Copy_of_Robot_leg_3_0_B.Product7_c[1] *
      Copy_of_Robot_leg_3_0_B.Product3_bw;

    /* Sum: '<S136>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_iw = Copy_of_Robot_leg_3_0_B.Product_ms -
      Copy_of_Robot_leg_3_0_B.Product1_kj;

    /* Sum: '<S136>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1_f = Copy_of_Robot_leg_3_0_B.Product2_i1 -
      Copy_of_Robot_leg_3_0_B.Product3_ny;

    /* Sum: '<S136>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2_k = Copy_of_Robot_leg_3_0_B.Product4_d1 -
      Copy_of_Robot_leg_3_0_B.Product5_i3;

    /* Product: '<S133>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_l,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_au,
      Copy_of_Robot_leg_3_0_B.Product1_e);

    /* SignalConversion: '<S133>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_i[0] =
      Copy_of_Robot_leg_3_0_B.Sum_iw;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_i[1] =
      Copy_of_Robot_leg_3_0_B.Sum1_f;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_i[2] =
      Copy_of_Robot_leg_3_0_B.Sum2_k;

    /* Product: '<S133>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_l,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_i,
      &Copy_of_Robot_leg_3_0_B.FSph[3]);

    /* Product: '<S134>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_l,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_kh,
      Copy_of_Robot_leg_3_0_B.Product2_g);

    /* Sum: '<S118>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph[0] = Copy_of_Robot_leg_3_0_B.Product2_g[0] +
      Copy_of_Robot_leg_3_0_B.Product1_e[0];
    Copy_of_Robot_leg_3_0_B.FSph[1] = Copy_of_Robot_leg_3_0_B.Product2_g[1] +
      Copy_of_Robot_leg_3_0_B.Product1_e[1];
    Copy_of_Robot_leg_3_0_B.FSph[2] = Copy_of_Robot_leg_3_0_B.Product2_g[2] +
      Copy_of_Robot_leg_3_0_B.Product1_e[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_iy);
    }

    /* End of Outputs for SubSystem: '<S58>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S58>/No Force' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_is);
    }

    /* End of Outputs for SubSystem: '<S58>/No Force' */
    break;
  }

  /* End of If: '<S58>/If1' */

  /* SimscapeInputBlock: '<S583>/INPUT_10_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph[6];
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_10_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph[7];
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_10_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph[8];
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_9_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph[9];
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_9_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph[10];
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_9_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph[11];
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_7_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph[0];
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_7_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph[1];
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_7_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph[2];
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_8_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph[3];
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_8_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph[4];
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_8_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph[5];
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[3] = 0.0;

  /* Gain: '<S163>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_m = Copy_of_Robot_leg_3_0_P.Gain_Gain_gs *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[52];

  /* Abs: '<S163>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs_k = fabs(Copy_of_Robot_leg_3_0_B.Gain_m);

  /* RelationalOperator: '<S169>/Compare' incorporates:
   *  Constant: '<S169>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_nc = (Copy_of_Robot_leg_3_0_B.Abs_k <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_len_m);

  /* Gain: '<S163>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_n = Copy_of_Robot_leg_3_0_P.Gain1_Gain_g *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[53];

  /* Abs: '<S163>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1_o2 = fabs(Copy_of_Robot_leg_3_0_B.Gain1_n);

  /* RelationalOperator: '<S170>/Compare' incorporates:
   *  Constant: '<S170>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_j = (Copy_of_Robot_leg_3_0_B.Abs1_o2 <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_len_d);

  /* Logic: '<S163>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator_k =
    (Copy_of_Robot_leg_3_0_B.Compare_nc && Copy_of_Robot_leg_3_0_B.Compare_j);

  /* DataTypeConversion: '<S163>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion_p =
    Copy_of_Robot_leg_3_0_B.LogicalOperator_k;

  /* Reshape: '<S204>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE_b[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[41], 9U * sizeof(real_T));

  /* If: '<S59>/If1' incorporates:
   *  Constant: '<S167>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion_p > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_i = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_i;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S59>/Forces' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    /* Abs: '<S179>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_kv = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[54]);

    /* Sum: '<S179>/Sum' incorporates:
     *  Constant: '<S179>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_rad +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_depth;
    Copy_of_Robot_leg_3_0_B.Sum_la = pulseWidth - Copy_of_Robot_leg_3_0_B.Abs_kv;

    /* DeadZone: '<S179>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_la > Copy_of_Robot_leg_3_0_P.DeadZone_End_a)
    {
      Copy_of_Robot_leg_3_0_B.DeadZone_l = Copy_of_Robot_leg_3_0_B.Sum_la -
        Copy_of_Robot_leg_3_0_P.DeadZone_End_a;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_la >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start_b) {
      Copy_of_Robot_leg_3_0_B.DeadZone_l = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone_l = Copy_of_Robot_leg_3_0_B.Sum_la -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start_b;
    }

    /* End of DeadZone: '<S179>/Dead Zone' */

    /* Signum: '<S179>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[54];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_j = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_j = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_j = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx_j = (rtNaN);
    }

    /* End of Signum: '<S179>/Sign x' */

    /* Product: '<S179>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_gr = Copy_of_Robot_leg_3_0_B.Signx_j *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[57];

    /* Gain: '<S179>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_fs = Copy_of_Robot_leg_3_0_P.Gain2_Gain_m *
      Copy_of_Robot_leg_3_0_B.Product_gr;

    /* Signum: '<S179>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[57];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_p = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_p = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_p = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx_p = (rtNaN);
    }

    /* End of Signum: '<S179>/Sign vx' */

    /* Gain: '<S190>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force_kw =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_k_contact *
      Copy_of_Robot_leg_3_0_B.DeadZone_l;

    /* Product: '<S166>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce_a = Copy_of_Robot_leg_3_0_B.Signx_j *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force_kw;

    /* Signum: '<S190>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone_l;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_g = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_g = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_g = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign_g = (rtNaN);
    }

    /* End of Signum: '<S190>/Sign' */

    /* Abs: '<S190>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_i = fabs
      (Copy_of_Robot_leg_3_0_B.Sign_g);

    /* Saturate: '<S190>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_fs;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_g;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_l;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation_el = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation_el = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation_el = pulseWidth;
    }

    /* End of Saturate: '<S190>/Saturation' */

    /* Gain: '<S190>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_b_contact;
    Copy_of_Robot_leg_3_0_B.Damping_Force_mh = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation_el;

    /* Product: '<S190>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_g =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_i *
      Copy_of_Robot_leg_3_0_B.Damping_Force_mh;

    /* Product: '<S166>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce_hs =
      Copy_of_Robot_leg_3_0_B.Damping_Force_g * Copy_of_Robot_leg_3_0_B.Signvx_p;

    /* Sum: '<S182>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_aw = Copy_of_Robot_leg_3_0_B.SprForce_a +
      Copy_of_Robot_leg_3_0_B.DampForce_hs;

    /* SignalConversion: '<S182>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S182>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_jm[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_c;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_jm[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_c;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_jm[2] =
      Copy_of_Robot_leg_3_0_B.Sum_aw;

    /* Gain: '<S182>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_fu[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_n *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_jm[0];
    Copy_of_Robot_leg_3_0_B.Gain_fu[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_n *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_jm[1];
    Copy_of_Robot_leg_3_0_B.Gain_fu[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_n *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_jm[2];

    /* Product: '<S186>/Product3' incorporates:
     *  Constant: '<S186>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_c3 = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[50]
      * Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_rad;

    /* Product: '<S181>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_is = Copy_of_Robot_leg_3_0_B.Signx_j *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[56];

    /* Sum: '<S186>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy_n = Copy_of_Robot_leg_3_0_B.Product3_c3 +
      Copy_of_Robot_leg_3_0_B.Product5_is;

    /* Math: '<S186>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_ke = Copy_of_Robot_leg_3_0_B.slipy_n *
      Copy_of_Robot_leg_3_0_B.slipy_n;

    /* Product: '<S186>/Product4' incorporates:
     *  Constant: '<S186>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4_bh =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_rad *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[51];

    /* Product: '<S181>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6_b = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[55] *
      Copy_of_Robot_leg_3_0_B.Signx_j;

    /* Sum: '<S186>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx_f = Copy_of_Robot_leg_3_0_B.Product6_b -
      Copy_of_Robot_leg_3_0_B.Product4_bh;

    /* Math: '<S186>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1_p = Copy_of_Robot_leg_3_0_B.slipx_f *
      Copy_of_Robot_leg_3_0_B.slipx_f;

    /* Sum: '<S186>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3_g = Copy_of_Robot_leg_3_0_B.MathFunction_ke +
      Copy_of_Robot_leg_3_0_B.MathFunction1_p;

    /* Sqrt: '<S186>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt_d = sqrt(Copy_of_Robot_leg_3_0_B.Sum3_g);

    /* Lookup_n-D: '<S188>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_i = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt_d,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_j,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_k, 5U);

    /* Product: '<S188>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_h =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_i *
      Copy_of_Robot_leg_3_0_B.Gain_fu[2];

    /* Gain: '<S188>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force_m =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_o * Copy_of_Robot_leg_3_0_B.Product_h;

    /* Trigonometry: '<S186>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_f = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy_n, Copy_of_Robot_leg_3_0_B.slipx_f);

    /* Trigonometry: '<S181>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_n = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_f);

    /* Product: '<S181>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_ab =
      Copy_of_Robot_leg_3_0_B.Friction_Force_m *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_n;

    /* Trigonometry: '<S181>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_jh = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_f);

    /* Product: '<S181>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_j =
      Copy_of_Robot_leg_3_0_B.Friction_Force_m *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_jh;

    /* SignalConversion: '<S181>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S181>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_a[0] =
      Copy_of_Robot_leg_3_0_B.Product3_ab;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_a[1] =
      Copy_of_Robot_leg_3_0_B.Product4_j;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_a[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value_l;

    /* Gain: '<S181>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_d1[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_j *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_a[0];

    /* Sum: '<S166>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_p[0] = Copy_of_Robot_leg_3_0_B.Gain_fu[0] +
      Copy_of_Robot_leg_3_0_B.Gain_d1[0];

    /* SignalConversion: '<S166>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_m[6] = Copy_of_Robot_leg_3_0_B.FPla_p[0];

    /* Gain: '<S181>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_d1[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_j *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_a[1];

    /* Sum: '<S166>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_p[1] = Copy_of_Robot_leg_3_0_B.Gain_fu[1] +
      Copy_of_Robot_leg_3_0_B.Gain_d1[1];

    /* SignalConversion: '<S166>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_m[7] = Copy_of_Robot_leg_3_0_B.FPla_p[1];

    /* Gain: '<S181>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_d1[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_j *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_a[2];

    /* Sum: '<S166>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_p[2] = Copy_of_Robot_leg_3_0_B.Gain_fu[2] +
      Copy_of_Robot_leg_3_0_B.Gain_d1[2];

    /* SignalConversion: '<S166>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_m[8] = Copy_of_Robot_leg_3_0_B.FPla_p[2];

    /* Product: '<S180>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_jf = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[53] *
      Copy_of_Robot_leg_3_0_B.FPla_p[2];

    /* Product: '<S180>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_l = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[54] *
      Copy_of_Robot_leg_3_0_B.FPla_p[1];

    /* Product: '<S180>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_jh = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[54]
      * Copy_of_Robot_leg_3_0_B.FPla_p[0];

    /* Product: '<S180>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_ep = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[52]
      * Copy_of_Robot_leg_3_0_B.FPla_p[2];

    /* Product: '<S180>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_o = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[52] *
      Copy_of_Robot_leg_3_0_B.FPla_p[1];

    /* Product: '<S180>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_np = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[53]
      * Copy_of_Robot_leg_3_0_B.FPla_p[0];

    /* Sum: '<S180>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_m[9] = Copy_of_Robot_leg_3_0_B.Product_jf -
      Copy_of_Robot_leg_3_0_B.Product1_l;

    /* Sum: '<S180>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph_m[10] = Copy_of_Robot_leg_3_0_B.Product2_jh -
      Copy_of_Robot_leg_3_0_B.Product3_ep;

    /* Sum: '<S180>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph_m[11] = Copy_of_Robot_leg_3_0_B.Product4_o -
      Copy_of_Robot_leg_3_0_B.Product5_np;

    /* Product: '<S181>/Product7' incorporates:
     *  Constant: '<S181>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7_j[0] = Copy_of_Robot_leg_3_0_P.Fx2_Value_n
      [0] * Copy_of_Robot_leg_3_0_B.Signx_j;
    Copy_of_Robot_leg_3_0_B.Product7_j[1] = Copy_of_Robot_leg_3_0_P.Fx2_Value_n
      [1] * Copy_of_Robot_leg_3_0_B.Signx_j;
    Copy_of_Robot_leg_3_0_B.Product7_j[2] = Copy_of_Robot_leg_3_0_P.Fx2_Value_n
      [2] * Copy_of_Robot_leg_3_0_B.Signx_j;

    /* Product: '<S184>/Product' incorporates:
     *  Constant: '<S181>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_n4 = Copy_of_Robot_leg_3_0_B.Product7_j[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_l;

    /* Product: '<S184>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_g = Copy_of_Robot_leg_3_0_B.Product7_j[2] *
      Copy_of_Robot_leg_3_0_B.Product4_j;

    /* Product: '<S184>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_ox = Copy_of_Robot_leg_3_0_B.Product7_j[2] *
      Copy_of_Robot_leg_3_0_B.Product3_ab;

    /* Product: '<S184>/Product3' incorporates:
     *  Constant: '<S181>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_in = Copy_of_Robot_leg_3_0_B.Product7_j[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_l;

    /* Product: '<S184>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_fk = Copy_of_Robot_leg_3_0_B.Product7_j[0] *
      Copy_of_Robot_leg_3_0_B.Product4_j;

    /* Product: '<S184>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_id = Copy_of_Robot_leg_3_0_B.Product7_j[1] *
      Copy_of_Robot_leg_3_0_B.Product3_ab;

    /* Sum: '<S184>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_d0 = Copy_of_Robot_leg_3_0_B.Product_n4 -
      Copy_of_Robot_leg_3_0_B.Product1_g;

    /* Sum: '<S184>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1_o = Copy_of_Robot_leg_3_0_B.Product2_ox -
      Copy_of_Robot_leg_3_0_B.Product3_in;

    /* Sum: '<S184>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2_j = Copy_of_Robot_leg_3_0_B.Product4_fk -
      Copy_of_Robot_leg_3_0_B.Product5_id;

    /* Product: '<S181>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_b,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_a,
      Copy_of_Robot_leg_3_0_B.Product1_o4);

    /* SignalConversion: '<S181>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_n[0] =
      Copy_of_Robot_leg_3_0_B.Sum_d0;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_n[1] =
      Copy_of_Robot_leg_3_0_B.Sum1_o;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_n[2] =
      Copy_of_Robot_leg_3_0_B.Sum2_j;

    /* Product: '<S181>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_b,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_n,
      &Copy_of_Robot_leg_3_0_B.FSph_m[3]);

    /* Product: '<S182>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_b,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_jm,
      Copy_of_Robot_leg_3_0_B.Product2_ib);

    /* Sum: '<S166>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_m[0] = Copy_of_Robot_leg_3_0_B.Product2_ib[0] +
      Copy_of_Robot_leg_3_0_B.Product1_o4[0];
    Copy_of_Robot_leg_3_0_B.FSph_m[1] = Copy_of_Robot_leg_3_0_B.Product2_ib[1] +
      Copy_of_Robot_leg_3_0_B.Product1_o4[1];
    Copy_of_Robot_leg_3_0_B.FSph_m[2] = Copy_of_Robot_leg_3_0_B.Product2_ib[2] +
      Copy_of_Robot_leg_3_0_B.Product1_o4[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_l);
    }

    /* End of Outputs for SubSystem: '<S59>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S59>/No Force' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph_m[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value_m[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_b);
    }

    /* End of Outputs for SubSystem: '<S59>/No Force' */
    break;
  }

  /* End of If: '<S59>/If1' */

  /* SimscapeInputBlock: '<S583>/INPUT_14_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_m[6];
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_14_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_m[7];
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_14_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_m[8];
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_13_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_m[9];
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_13_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_m[10];
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_13_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_m[11];
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_11_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_m[0];
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_11_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_m[1];
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_11_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_m[2];
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_12_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_m[3];
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_12_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_m[4];
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_12_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_m[5];
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[3] = 0.0;

  /* Gain: '<S211>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_g = Copy_of_Robot_leg_3_0_P.Gain_Gain_gp *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[69];

  /* Abs: '<S211>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs_n = fabs(Copy_of_Robot_leg_3_0_B.Gain_g);

  /* RelationalOperator: '<S217>/Compare' incorporates:
   *  Constant: '<S217>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_p = (Copy_of_Robot_leg_3_0_B.Abs_n <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_len_b);

  /* Gain: '<S211>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_gi = Copy_of_Robot_leg_3_0_P.Gain1_Gain_kc *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[70];

  /* Abs: '<S211>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1_n = fabs(Copy_of_Robot_leg_3_0_B.Gain1_gi);

  /* RelationalOperator: '<S218>/Compare' incorporates:
   *  Constant: '<S218>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_a = (Copy_of_Robot_leg_3_0_B.Abs1_n <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_len_p);

  /* Logic: '<S211>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator_aj =
    (Copy_of_Robot_leg_3_0_B.Compare_p && Copy_of_Robot_leg_3_0_B.Compare_a);

  /* DataTypeConversion: '<S211>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion_b =
    Copy_of_Robot_leg_3_0_B.LogicalOperator_aj;

  /* Reshape: '<S252>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE_j1[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[58], 9U * sizeof(real_T));

  /* If: '<S60>/If1' incorporates:
   *  Constant: '<S215>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion_b > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_o = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_o;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S60>/Forces' incorporates:
     *  ActionPort: '<S214>/Action Port'
     */
    /* Abs: '<S227>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_b = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[71]);

    /* Sum: '<S227>/Sum' incorporates:
     *  Constant: '<S227>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_rad +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_depth;
    Copy_of_Robot_leg_3_0_B.Sum_j4 = pulseWidth - Copy_of_Robot_leg_3_0_B.Abs_b;

    /* DeadZone: '<S227>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_j4 > Copy_of_Robot_leg_3_0_P.DeadZone_End_i)
    {
      Copy_of_Robot_leg_3_0_B.DeadZone_k = Copy_of_Robot_leg_3_0_B.Sum_j4 -
        Copy_of_Robot_leg_3_0_P.DeadZone_End_i;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_j4 >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start_p) {
      Copy_of_Robot_leg_3_0_B.DeadZone_k = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone_k = Copy_of_Robot_leg_3_0_B.Sum_j4 -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start_p;
    }

    /* End of DeadZone: '<S227>/Dead Zone' */

    /* Signum: '<S227>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[71];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_e = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_e = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_e = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx_e = (rtNaN);
    }

    /* End of Signum: '<S227>/Sign x' */

    /* Product: '<S227>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_if = Copy_of_Robot_leg_3_0_B.Signx_e *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[74];

    /* Gain: '<S227>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_b = Copy_of_Robot_leg_3_0_P.Gain2_Gain_b *
      Copy_of_Robot_leg_3_0_B.Product_if;

    /* Signum: '<S227>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[74];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_h = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_h = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_h = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx_h = (rtNaN);
    }

    /* End of Signum: '<S227>/Sign vx' */

    /* Gain: '<S238>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force_kv =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_k_contact *
      Copy_of_Robot_leg_3_0_B.DeadZone_k;

    /* Product: '<S214>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce_e = Copy_of_Robot_leg_3_0_B.Signx_e *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force_kv;

    /* Signum: '<S238>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone_k;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_m = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_m = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_m = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign_m = (rtNaN);
    }

    /* End of Signum: '<S238>/Sign' */

    /* Abs: '<S238>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_df = fabs
      (Copy_of_Robot_leg_3_0_B.Sign_m);

    /* Saturate: '<S238>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_b;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_j;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_b;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation_d = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation_d = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation_d = pulseWidth;
    }

    /* End of Saturate: '<S238>/Saturation' */

    /* Gain: '<S238>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_b_contact;
    Copy_of_Robot_leg_3_0_B.Damping_Force_m = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation_d;

    /* Product: '<S238>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_a =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_df *
      Copy_of_Robot_leg_3_0_B.Damping_Force_m;

    /* Product: '<S214>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce_f =
      Copy_of_Robot_leg_3_0_B.Damping_Force_a * Copy_of_Robot_leg_3_0_B.Signvx_h;

    /* Sum: '<S230>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_iz = Copy_of_Robot_leg_3_0_B.SprForce_e +
      Copy_of_Robot_leg_3_0_B.DampForce_f;

    /* SignalConversion: '<S230>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S230>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_c3[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_j;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_c3[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_j;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_c3[2] =
      Copy_of_Robot_leg_3_0_B.Sum_iz;

    /* Gain: '<S230>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ar[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_p *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_c3[0];
    Copy_of_Robot_leg_3_0_B.Gain_ar[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_p *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_c3[1];
    Copy_of_Robot_leg_3_0_B.Gain_ar[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_p *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_c3[2];

    /* Product: '<S234>/Product3' incorporates:
     *  Constant: '<S234>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_ao = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[67]
      * Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_rad;

    /* Product: '<S229>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_jn = Copy_of_Robot_leg_3_0_B.Signx_e *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[73];

    /* Sum: '<S234>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy_o = Copy_of_Robot_leg_3_0_B.Product3_ao +
      Copy_of_Robot_leg_3_0_B.Product5_jn;

    /* Math: '<S234>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_hr = Copy_of_Robot_leg_3_0_B.slipy_o *
      Copy_of_Robot_leg_3_0_B.slipy_o;

    /* Product: '<S234>/Product4' incorporates:
     *  Constant: '<S234>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4_a5 =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_rad *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[68];

    /* Product: '<S229>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6_c = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[72] *
      Copy_of_Robot_leg_3_0_B.Signx_e;

    /* Sum: '<S234>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx_l = Copy_of_Robot_leg_3_0_B.Product6_c -
      Copy_of_Robot_leg_3_0_B.Product4_a5;

    /* Math: '<S234>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1_a2 = Copy_of_Robot_leg_3_0_B.slipx_l *
      Copy_of_Robot_leg_3_0_B.slipx_l;

    /* Sum: '<S234>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3_a = Copy_of_Robot_leg_3_0_B.MathFunction_hr +
      Copy_of_Robot_leg_3_0_B.MathFunction1_a2;

    /* Sqrt: '<S234>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt_h = sqrt(Copy_of_Robot_leg_3_0_B.Sum3_a);

    /* Lookup_n-D: '<S236>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_ow = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt_h,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_d,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_n, 5U);

    /* Product: '<S236>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_ka =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_ow *
      Copy_of_Robot_leg_3_0_B.Gain_ar[2];

    /* Gain: '<S236>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force_bg =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_a * Copy_of_Robot_leg_3_0_B.Product_ka;

    /* Trigonometry: '<S234>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pt = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy_o, Copy_of_Robot_leg_3_0_B.slipx_l);

    /* Trigonometry: '<S229>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_dl = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pt);

    /* Product: '<S229>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_kn =
      Copy_of_Robot_leg_3_0_B.Friction_Force_bg *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_dl;

    /* Trigonometry: '<S229>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_iw = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pt);

    /* Product: '<S229>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_iys =
      Copy_of_Robot_leg_3_0_B.Friction_Force_bg *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_iw;

    /* SignalConversion: '<S229>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S229>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_p[0] =
      Copy_of_Robot_leg_3_0_B.Product3_kn;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_p[1] =
      Copy_of_Robot_leg_3_0_B.Product4_iys;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_p[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value_g;

    /* Gain: '<S229>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ib[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_m4 *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_p[0];

    /* Sum: '<S214>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_n[0] = Copy_of_Robot_leg_3_0_B.Gain_ar[0] +
      Copy_of_Robot_leg_3_0_B.Gain_ib[0];

    /* SignalConversion: '<S214>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_l[6] = Copy_of_Robot_leg_3_0_B.FPla_n[0];

    /* Gain: '<S229>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ib[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_m4 *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_p[1];

    /* Sum: '<S214>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_n[1] = Copy_of_Robot_leg_3_0_B.Gain_ar[1] +
      Copy_of_Robot_leg_3_0_B.Gain_ib[1];

    /* SignalConversion: '<S214>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_l[7] = Copy_of_Robot_leg_3_0_B.FPla_n[1];

    /* Gain: '<S229>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_ib[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_m4 *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_p[2];

    /* Sum: '<S214>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_n[2] = Copy_of_Robot_leg_3_0_B.Gain_ar[2] +
      Copy_of_Robot_leg_3_0_B.Gain_ib[2];

    /* SignalConversion: '<S214>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_l[8] = Copy_of_Robot_leg_3_0_B.FPla_n[2];

    /* Product: '<S228>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_fd = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[70] *
      Copy_of_Robot_leg_3_0_B.FPla_n[2];

    /* Product: '<S228>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_ij = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[71]
      * Copy_of_Robot_leg_3_0_B.FPla_n[1];

    /* Product: '<S228>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_e = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[71] *
      Copy_of_Robot_leg_3_0_B.FPla_n[0];

    /* Product: '<S228>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_ma = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[69]
      * Copy_of_Robot_leg_3_0_B.FPla_n[2];

    /* Product: '<S228>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_ae = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[69]
      * Copy_of_Robot_leg_3_0_B.FPla_n[1];

    /* Product: '<S228>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_jh = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[70]
      * Copy_of_Robot_leg_3_0_B.FPla_n[0];

    /* Sum: '<S228>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_l[9] = Copy_of_Robot_leg_3_0_B.Product_fd -
      Copy_of_Robot_leg_3_0_B.Product1_ij;

    /* Sum: '<S228>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph_l[10] = Copy_of_Robot_leg_3_0_B.Product2_e -
      Copy_of_Robot_leg_3_0_B.Product3_ma;

    /* Sum: '<S228>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph_l[11] = Copy_of_Robot_leg_3_0_B.Product4_ae -
      Copy_of_Robot_leg_3_0_B.Product5_jh;

    /* Product: '<S229>/Product7' incorporates:
     *  Constant: '<S229>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7_bi[0] =
      Copy_of_Robot_leg_3_0_P.Fx2_Value_j[0] * Copy_of_Robot_leg_3_0_B.Signx_e;
    Copy_of_Robot_leg_3_0_B.Product7_bi[1] =
      Copy_of_Robot_leg_3_0_P.Fx2_Value_j[1] * Copy_of_Robot_leg_3_0_B.Signx_e;
    Copy_of_Robot_leg_3_0_B.Product7_bi[2] =
      Copy_of_Robot_leg_3_0_P.Fx2_Value_j[2] * Copy_of_Robot_leg_3_0_B.Signx_e;

    /* Product: '<S232>/Product' incorporates:
     *  Constant: '<S229>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_j2 = Copy_of_Robot_leg_3_0_B.Product7_bi[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_g;

    /* Product: '<S232>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_f = Copy_of_Robot_leg_3_0_B.Product7_bi[2] *
      Copy_of_Robot_leg_3_0_B.Product4_iys;

    /* Product: '<S232>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_hu = Copy_of_Robot_leg_3_0_B.Product7_bi[2]
      * Copy_of_Robot_leg_3_0_B.Product3_kn;

    /* Product: '<S232>/Product3' incorporates:
     *  Constant: '<S229>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_b = Copy_of_Robot_leg_3_0_B.Product7_bi[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_g;

    /* Product: '<S232>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_ad = Copy_of_Robot_leg_3_0_B.Product7_bi[0]
      * Copy_of_Robot_leg_3_0_B.Product4_iys;

    /* Product: '<S232>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_gd = Copy_of_Robot_leg_3_0_B.Product7_bi[1]
      * Copy_of_Robot_leg_3_0_B.Product3_kn;

    /* Sum: '<S232>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_ec = Copy_of_Robot_leg_3_0_B.Product_j2 -
      Copy_of_Robot_leg_3_0_B.Product1_f;

    /* Sum: '<S232>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1_cv = Copy_of_Robot_leg_3_0_B.Product2_hu -
      Copy_of_Robot_leg_3_0_B.Product3_b;

    /* Sum: '<S232>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2_n = Copy_of_Robot_leg_3_0_B.Product4_ad -
      Copy_of_Robot_leg_3_0_B.Product5_gd;

    /* Product: '<S229>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_j1,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_p,
      Copy_of_Robot_leg_3_0_B.Product1_m);

    /* SignalConversion: '<S229>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_k[0] =
      Copy_of_Robot_leg_3_0_B.Sum_ec;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_k[1] =
      Copy_of_Robot_leg_3_0_B.Sum1_cv;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_k[2] =
      Copy_of_Robot_leg_3_0_B.Sum2_n;

    /* Product: '<S229>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_j1,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_k,
      &Copy_of_Robot_leg_3_0_B.FSph_l[3]);

    /* Product: '<S230>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_j1,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_c3,
      Copy_of_Robot_leg_3_0_B.Product2_d);

    /* Sum: '<S214>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_l[0] = Copy_of_Robot_leg_3_0_B.Product2_d[0] +
      Copy_of_Robot_leg_3_0_B.Product1_m[0];
    Copy_of_Robot_leg_3_0_B.FSph_l[1] = Copy_of_Robot_leg_3_0_B.Product2_d[1] +
      Copy_of_Robot_leg_3_0_B.Product1_m[1];
    Copy_of_Robot_leg_3_0_B.FSph_l[2] = Copy_of_Robot_leg_3_0_B.Product2_d[2] +
      Copy_of_Robot_leg_3_0_B.Product1_m[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_i);
    }

    /* End of Outputs for SubSystem: '<S60>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S60>/No Force' incorporates:
     *  ActionPort: '<S215>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph_l[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value_m2[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_i);
    }

    /* End of Outputs for SubSystem: '<S60>/No Force' */
    break;
  }

  /* End of If: '<S60>/If1' */

  /* SimscapeInputBlock: '<S583>/INPUT_18_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_l[6];
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_18_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_l[7];
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_18_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_l[8];
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_17_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_l[9];
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_17_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_l[10];
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_17_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_l[11];
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_15_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_l[0];
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_15_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_l[1];
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_15_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_l[2];
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_16_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_l[3];
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_16_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_l[4];
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_16_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_l[5];
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[3] = 0.0;

  /* Gain: '<S259>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_m5 = Copy_of_Robot_leg_3_0_P.Gain_Gain_a0 *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[86];

  /* Abs: '<S259>/Abs' */
  Copy_of_Robot_leg_3_0_B.Abs_ff = fabs(Copy_of_Robot_leg_3_0_B.Gain_m5);

  /* RelationalOperator: '<S265>/Compare' incorporates:
   *  Constant: '<S265>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_aq = (Copy_of_Robot_leg_3_0_B.Abs_ff <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_len_p);

  /* Gain: '<S259>/Gain1' */
  Copy_of_Robot_leg_3_0_B.Gain1_c = Copy_of_Robot_leg_3_0_P.Gain1_Gain_l *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[87];

  /* Abs: '<S259>/Abs1' */
  Copy_of_Robot_leg_3_0_B.Abs1_b = fabs(Copy_of_Robot_leg_3_0_B.Gain1_c);

  /* RelationalOperator: '<S266>/Compare' incorporates:
   *  Constant: '<S266>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Compare_i = (Copy_of_Robot_leg_3_0_B.Abs1_b <
    Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_len_c);

  /* Logic: '<S259>/Logical Operator' */
  Copy_of_Robot_leg_3_0_B.LogicalOperator_nt =
    (Copy_of_Robot_leg_3_0_B.Compare_aq && Copy_of_Robot_leg_3_0_B.Compare_i);

  /* DataTypeConversion: '<S259>/Data Type Conversion' */
  Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu =
    Copy_of_Robot_leg_3_0_B.LogicalOperator_nt;

  /* Reshape: '<S300>/RESHAPE' */
  memcpy(&Copy_of_Robot_leg_3_0_B.RESHAPE_jw[0],
         &Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[75], 9U * sizeof(real_T));

  /* If: '<S61>/If1' incorporates:
   *  Constant: '<S263>/Zeros'
   */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rtAction = (int8_T)!(Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu > 0.0);
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_e = rtAction;
  } else {
    rtAction = Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_e;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S61>/Forces' incorporates:
     *  ActionPort: '<S262>/Action Port'
     */
    /* Abs: '<S275>/Abs' */
    Copy_of_Robot_leg_3_0_B.Abs_g4 = fabs(Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[88]);

    /* Sum: '<S275>/Sum' incorporates:
     *  Constant: '<S275>/Constant'
     */
    pulseWidth = Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_rad +
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_depth;
    Copy_of_Robot_leg_3_0_B.Sum_eb0 = pulseWidth -
      Copy_of_Robot_leg_3_0_B.Abs_g4;

    /* DeadZone: '<S275>/Dead Zone' */
    if (Copy_of_Robot_leg_3_0_B.Sum_eb0 > Copy_of_Robot_leg_3_0_P.DeadZone_End_l)
    {
      Copy_of_Robot_leg_3_0_B.DeadZone_ap = Copy_of_Robot_leg_3_0_B.Sum_eb0 -
        Copy_of_Robot_leg_3_0_P.DeadZone_End_l;
    } else if (Copy_of_Robot_leg_3_0_B.Sum_eb0 >=
               Copy_of_Robot_leg_3_0_P.DeadZone_Start_a) {
      Copy_of_Robot_leg_3_0_B.DeadZone_ap = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.DeadZone_ap = Copy_of_Robot_leg_3_0_B.Sum_eb0 -
        Copy_of_Robot_leg_3_0_P.DeadZone_Start_a;
    }

    /* End of DeadZone: '<S275>/Dead Zone' */

    /* Signum: '<S275>/Sign x' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[88];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_lq = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_lq = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signx_lq = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signx_lq = (rtNaN);
    }

    /* End of Signum: '<S275>/Sign x' */

    /* Product: '<S275>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_gy = Copy_of_Robot_leg_3_0_B.Signx_lq *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[91];

    /* Gain: '<S275>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Gain2_e = Copy_of_Robot_leg_3_0_P.Gain2_Gain_p *
      Copy_of_Robot_leg_3_0_B.Product_gy;

    /* Signum: '<S275>/Sign vx' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[91];
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_l = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_l = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Signvx_l = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Signvx_l = (rtNaN);
    }

    /* End of Signum: '<S275>/Sign vx' */

    /* Gain: '<S286>/Gain1' */
    Copy_of_Robot_leg_3_0_B.Stiffness_Force_kg =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_k_contact *
      Copy_of_Robot_leg_3_0_B.DeadZone_ap;

    /* Product: '<S262>/Product' */
    Copy_of_Robot_leg_3_0_B.SprForce_m = Copy_of_Robot_leg_3_0_B.Signx_lq *
      Copy_of_Robot_leg_3_0_B.Stiffness_Force_kg;

    /* Signum: '<S286>/Sign' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.DeadZone_ap;
    if (pulseWidth < 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_f = -1.0;
    } else if (pulseWidth > 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_f = 1.0;
    } else if (pulseWidth == 0.0) {
      Copy_of_Robot_leg_3_0_B.Sign_f = 0.0;
    } else {
      Copy_of_Robot_leg_3_0_B.Sign_f = (rtNaN);
    }

    /* End of Signum: '<S286>/Sign' */

    /* Abs: '<S286>/Abs' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_h = fabs
      (Copy_of_Robot_leg_3_0_B.Sign_f);

    /* Saturate: '<S286>/Saturation' */
    pulseWidth = Copy_of_Robot_leg_3_0_B.Gain2_e;
    diff = Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_c;
    ratio = Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_d;
    if (pulseWidth > ratio) {
      Copy_of_Robot_leg_3_0_B.Saturation_jq = ratio;
    } else if (pulseWidth < diff) {
      Copy_of_Robot_leg_3_0_B.Saturation_jq = diff;
    } else {
      Copy_of_Robot_leg_3_0_B.Saturation_jq = pulseWidth;
    }

    /* End of Saturate: '<S286>/Saturation' */

    /* Gain: '<S286>/Gain2' */
    pulseWidth = -Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_b_contact;
    Copy_of_Robot_leg_3_0_B.Damping_Force_d = pulseWidth *
      Copy_of_Robot_leg_3_0_B.Saturation_jq;

    /* Product: '<S286>/Product' */
    Copy_of_Robot_leg_3_0_B.Damping_Force_cq =
      Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_h *
      Copy_of_Robot_leg_3_0_B.Damping_Force_d;

    /* Product: '<S262>/Product1' */
    Copy_of_Robot_leg_3_0_B.DampForce_n =
      Copy_of_Robot_leg_3_0_B.Damping_Force_cq *
      Copy_of_Robot_leg_3_0_B.Signvx_l;

    /* Sum: '<S278>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_jg = Copy_of_Robot_leg_3_0_B.SprForce_m +
      Copy_of_Robot_leg_3_0_B.DampForce_n;

    /* SignalConversion: '<S278>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S278>/Fx'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_j[0] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_p;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_j[1] =
      Copy_of_Robot_leg_3_0_P.Fx_Value_p;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_j[2] =
      Copy_of_Robot_leg_3_0_B.Sum_jg;

    /* Gain: '<S278>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_d[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_h *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_j[0];
    Copy_of_Robot_leg_3_0_B.Gain_d[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_h *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_j[1];
    Copy_of_Robot_leg_3_0_B.Gain_d[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_h *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_j[2];

    /* Product: '<S282>/Product3' incorporates:
     *  Constant: '<S282>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_j = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[84] *
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_rad;

    /* Product: '<S277>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_a = Copy_of_Robot_leg_3_0_B.Signx_lq *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[90];

    /* Sum: '<S282>/Sum1' */
    Copy_of_Robot_leg_3_0_B.slipy_h = Copy_of_Robot_leg_3_0_B.Product3_j +
      Copy_of_Robot_leg_3_0_B.Product5_a;

    /* Math: '<S282>/Math Function' */
    Copy_of_Robot_leg_3_0_B.MathFunction_pq = Copy_of_Robot_leg_3_0_B.slipy_h *
      Copy_of_Robot_leg_3_0_B.slipy_h;

    /* Product: '<S282>/Product4' incorporates:
     *  Constant: '<S282>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product4_i =
      Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_rad *
      Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[85];

    /* Product: '<S277>/Product6' */
    Copy_of_Robot_leg_3_0_B.Product6_p = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[89] *
      Copy_of_Robot_leg_3_0_B.Signx_lq;

    /* Sum: '<S282>/Sum2' */
    Copy_of_Robot_leg_3_0_B.slipx_m = Copy_of_Robot_leg_3_0_B.Product6_p -
      Copy_of_Robot_leg_3_0_B.Product4_i;

    /* Math: '<S282>/Math Function1' */
    Copy_of_Robot_leg_3_0_B.MathFunction1_m = Copy_of_Robot_leg_3_0_B.slipx_m *
      Copy_of_Robot_leg_3_0_B.slipx_m;

    /* Sum: '<S282>/Sum3' */
    Copy_of_Robot_leg_3_0_B.Sum3_c = Copy_of_Robot_leg_3_0_B.MathFunction_pq +
      Copy_of_Robot_leg_3_0_B.MathFunction1_m;

    /* Sqrt: '<S282>/Sqrt' */
    Copy_of_Robot_leg_3_0_B.Sqrt_l3 = sqrt(Copy_of_Robot_leg_3_0_B.Sum3_c);

    /* Lookup_n-D: '<S284>/Coefficient of Friction vs Velocity' */
    Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_o = look1_binlxpw
      (Copy_of_Robot_leg_3_0_B.Sqrt_l3,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_a,
       Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_p, 5U);

    /* Product: '<S284>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_db =
      Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_o *
      Copy_of_Robot_leg_3_0_B.Gain_d[2];

    /* Gain: '<S284>/Gain2' */
    Copy_of_Robot_leg_3_0_B.Friction_Force_n =
      Copy_of_Robot_leg_3_0_P.Gain2_Gain_f * Copy_of_Robot_leg_3_0_B.Product_db;

    /* Trigonometry: '<S282>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_p = rt_atan2d_snf
      (Copy_of_Robot_leg_3_0_B.slipy_h, Copy_of_Robot_leg_3_0_B.slipx_m);

    /* Trigonometry: '<S277>/Trigonometric Function1' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_d = cos
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_p);

    /* Product: '<S277>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_dh =
      Copy_of_Robot_leg_3_0_B.Friction_Force_n *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_d;

    /* Trigonometry: '<S277>/Trigonometric Function' */
    Copy_of_Robot_leg_3_0_B.TrigonometricFunction_h = sin
      (Copy_of_Robot_leg_3_0_B.TrigonometricFunction_p);

    /* Product: '<S277>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_k5 =
      Copy_of_Robot_leg_3_0_B.Friction_Force_n *
      Copy_of_Robot_leg_3_0_B.TrigonometricFunction_h;

    /* SignalConversion: '<S277>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S277>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_i[0] =
      Copy_of_Robot_leg_3_0_B.Product3_dh;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_i[1] =
      Copy_of_Robot_leg_3_0_B.Product4_k5;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_i[2] =
      Copy_of_Robot_leg_3_0_P.Fx1_Value_f;

    /* Gain: '<S277>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_eu[0] = Copy_of_Robot_leg_3_0_P.Gain_Gain_a *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_i[0];

    /* Sum: '<S262>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_d[0] = Copy_of_Robot_leg_3_0_B.Gain_d[0] +
      Copy_of_Robot_leg_3_0_B.Gain_eu[0];

    /* SignalConversion: '<S262>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_a[6] = Copy_of_Robot_leg_3_0_B.FPla_d[0];

    /* Gain: '<S277>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_eu[1] = Copy_of_Robot_leg_3_0_P.Gain_Gain_a *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_i[1];

    /* Sum: '<S262>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_d[1] = Copy_of_Robot_leg_3_0_B.Gain_d[1] +
      Copy_of_Robot_leg_3_0_B.Gain_eu[1];

    /* SignalConversion: '<S262>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_a[7] = Copy_of_Robot_leg_3_0_B.FPla_d[1];

    /* Gain: '<S277>/Gain' */
    Copy_of_Robot_leg_3_0_B.Gain_eu[2] = Copy_of_Robot_leg_3_0_P.Gain_Gain_a *
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_i[2];

    /* Sum: '<S262>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FPla_d[2] = Copy_of_Robot_leg_3_0_B.Gain_d[2] +
      Copy_of_Robot_leg_3_0_B.Gain_eu[2];

    /* SignalConversion: '<S262>/Copy for Merge' */
    Copy_of_Robot_leg_3_0_B.FSph_a[8] = Copy_of_Robot_leg_3_0_B.FPla_d[2];

    /* Product: '<S276>/Product' */
    Copy_of_Robot_leg_3_0_B.Product_a4 = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[87] *
      Copy_of_Robot_leg_3_0_B.FPla_d[2];

    /* Product: '<S276>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_hn = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[88]
      * Copy_of_Robot_leg_3_0_B.FPla_d[1];

    /* Product: '<S276>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_k = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[88] *
      Copy_of_Robot_leg_3_0_B.FPla_d[0];

    /* Product: '<S276>/Product3' */
    Copy_of_Robot_leg_3_0_B.Product3_k = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[86] *
      Copy_of_Robot_leg_3_0_B.FPla_d[2];

    /* Product: '<S276>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_ku = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[86]
      * Copy_of_Robot_leg_3_0_B.FPla_d[1];

    /* Product: '<S276>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_ae = Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[87]
      * Copy_of_Robot_leg_3_0_B.FPla_d[0];

    /* Sum: '<S276>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_a[9] = Copy_of_Robot_leg_3_0_B.Product_a4 -
      Copy_of_Robot_leg_3_0_B.Product1_hn;

    /* Sum: '<S276>/Sum1' */
    Copy_of_Robot_leg_3_0_B.FSph_a[10] = Copy_of_Robot_leg_3_0_B.Product2_k -
      Copy_of_Robot_leg_3_0_B.Product3_k;

    /* Sum: '<S276>/Sum2' */
    Copy_of_Robot_leg_3_0_B.FSph_a[11] = Copy_of_Robot_leg_3_0_B.Product4_ku -
      Copy_of_Robot_leg_3_0_B.Product5_ae;

    /* Product: '<S277>/Product7' incorporates:
     *  Constant: '<S277>/Fx2'
     */
    Copy_of_Robot_leg_3_0_B.Product7_f[0] = Copy_of_Robot_leg_3_0_P.Fx2_Value_i
      [0] * Copy_of_Robot_leg_3_0_B.Signx_lq;
    Copy_of_Robot_leg_3_0_B.Product7_f[1] = Copy_of_Robot_leg_3_0_P.Fx2_Value_i
      [1] * Copy_of_Robot_leg_3_0_B.Signx_lq;
    Copy_of_Robot_leg_3_0_B.Product7_f[2] = Copy_of_Robot_leg_3_0_P.Fx2_Value_i
      [2] * Copy_of_Robot_leg_3_0_B.Signx_lq;

    /* Product: '<S280>/Product' incorporates:
     *  Constant: '<S277>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product_pw = Copy_of_Robot_leg_3_0_B.Product7_f[1] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_f;

    /* Product: '<S280>/Product1' */
    Copy_of_Robot_leg_3_0_B.Product1_a = Copy_of_Robot_leg_3_0_B.Product7_f[2] *
      Copy_of_Robot_leg_3_0_B.Product4_k5;

    /* Product: '<S280>/Product2' */
    Copy_of_Robot_leg_3_0_B.Product2_l = Copy_of_Robot_leg_3_0_B.Product7_f[2] *
      Copy_of_Robot_leg_3_0_B.Product3_dh;

    /* Product: '<S280>/Product3' incorporates:
     *  Constant: '<S277>/Fx1'
     */
    Copy_of_Robot_leg_3_0_B.Product3_c = Copy_of_Robot_leg_3_0_B.Product7_f[0] *
      Copy_of_Robot_leg_3_0_P.Fx1_Value_f;

    /* Product: '<S280>/Product4' */
    Copy_of_Robot_leg_3_0_B.Product4_iy = Copy_of_Robot_leg_3_0_B.Product7_f[0] *
      Copy_of_Robot_leg_3_0_B.Product4_k5;

    /* Product: '<S280>/Product5' */
    Copy_of_Robot_leg_3_0_B.Product5_g = Copy_of_Robot_leg_3_0_B.Product7_f[1] *
      Copy_of_Robot_leg_3_0_B.Product3_dh;

    /* Sum: '<S280>/Sum' */
    Copy_of_Robot_leg_3_0_B.Sum_ei = Copy_of_Robot_leg_3_0_B.Product_pw -
      Copy_of_Robot_leg_3_0_B.Product1_a;

    /* Sum: '<S280>/Sum1' */
    Copy_of_Robot_leg_3_0_B.Sum1_ck = Copy_of_Robot_leg_3_0_B.Product2_l -
      Copy_of_Robot_leg_3_0_B.Product3_c;

    /* Sum: '<S280>/Sum2' */
    Copy_of_Robot_leg_3_0_B.Sum2_g = Copy_of_Robot_leg_3_0_B.Product4_iy -
      Copy_of_Robot_leg_3_0_B.Product5_g;

    /* Product: '<S277>/Product1' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_jw,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct1_i,
      Copy_of_Robot_leg_3_0_B.Product1_km);

    /* SignalConversion: '<S277>/TmpSignal ConversionAtProduct2Inport2' */
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_oq[0] =
      Copy_of_Robot_leg_3_0_B.Sum_ei;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_oq[1] =
      Copy_of_Robot_leg_3_0_B.Sum1_ck;
    Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_oq[2] =
      Copy_of_Robot_leg_3_0_B.Sum2_g;

    /* Product: '<S277>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_jw,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct_oq,
      &Copy_of_Robot_leg_3_0_B.FSph_a[3]);

    /* Product: '<S278>/Product2' */
    rt_mldivide_U1d3x3_U2d_9O8lG8ax(Copy_of_Robot_leg_3_0_B.RESHAPE_jw,
      Copy_of_Robot_leg_3_0_B.TmpSignalConversionAtProduct2_j,
      Copy_of_Robot_leg_3_0_B.Product2_ld);

    /* Sum: '<S262>/Sum' */
    Copy_of_Robot_leg_3_0_B.FSph_a[0] = Copy_of_Robot_leg_3_0_B.Product2_ld[0] +
      Copy_of_Robot_leg_3_0_B.Product1_km[0];
    Copy_of_Robot_leg_3_0_B.FSph_a[1] = Copy_of_Robot_leg_3_0_B.Product2_ld[1] +
      Copy_of_Robot_leg_3_0_B.Product1_km[1];
    Copy_of_Robot_leg_3_0_B.FSph_a[2] = Copy_of_Robot_leg_3_0_B.Product2_ld[2] +
      Copy_of_Robot_leg_3_0_B.Product1_km[2];
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.Forces_SubsysRanBC_o);
    }

    /* End of Outputs for SubSystem: '<S61>/Forces' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S61>/No Force' incorporates:
     *  ActionPort: '<S263>/Action Port'
     */
    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      memcpy(&Copy_of_Robot_leg_3_0_B.FSph_a[0],
             &Copy_of_Robot_leg_3_0_P.Zeros_Value_m4[0], 12U * sizeof(real_T));
    }

    if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
      srUpdateBC(Copy_of_Robot_leg_3_0_DW.NoForce_SubsysRanBC_d);
    }

    /* End of Outputs for SubSystem: '<S61>/No Force' */
    break;
  }

  /* End of If: '<S61>/If1' */

  /* SimscapeInputBlock: '<S583>/INPUT_22_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a[6];
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_22_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a[7];
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_22_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a[8];
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_21_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a[9];
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_21_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a[10];
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_21_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a[11];
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_19_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a[0];
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_19_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a[1];
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_19_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a[2];
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_20_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a[3];
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_20_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a[4];
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_20_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a[5];
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_32_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_i[6];
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_32_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_i[7];
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_32_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_i[8];
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_31_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_i[9];
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_31_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_i[10];
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_31_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_i[11];
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_29_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_i[0];
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_29_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_i[1];
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_29_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_i[2];
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_30_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_i[3];
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_30_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_i[4];
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_30_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_i[5];
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_36_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[6];
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_36_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[7];
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_36_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[8];
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_35_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[9];
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_35_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[10];
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_35_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[11];
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_33_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[0];
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_33_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[1];
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_33_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[2];
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_34_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[3];
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_34_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[4];
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_34_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_mf[5];
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_40_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[6];
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_40_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[7];
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_40_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[8];
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_39_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[9];
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_39_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[10];
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_39_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[11];
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_37_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[0];
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_37_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[1];
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_37_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[2];
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_38_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[3];
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_38_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[4];
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_38_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_a0[5];
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_44_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_n[6];
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_44_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_n[7];
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_44_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_n[8];
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_43_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_n[9];
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_43_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_n[10];
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_43_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_n[11];
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_41_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_n[0];
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_41_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_n[1];
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_41_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_n[2];
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_42_1_1' */
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[0] = Copy_of_Robot_leg_3_0_B.FSph_n[3];
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_42_1_2' */
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[0] = Copy_of_Robot_leg_3_0_B.FSph_n[4];
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S583>/INPUT_42_1_3' */
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[0] = Copy_of_Robot_leg_3_0_B.FSph_n[5];
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[1] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[2] = 0.0;
  Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[3] = 0.0;

  /* SimscapeExecutionBlock: '<S583>/OUTPUT_1_1' */
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_SimulationData;
  time_1 = Copy_of_Robot_leg_3_0_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  first_output = false;
  simulationData->mData->mFoundZcEvents = first_output;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Copy_of_Robot_leg_3_0_M);
  first_output = false;
  simulationData->mData->mIsSolverAssertCheck = first_output;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_5[0] = 0;
  tmp_4[0] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[0];
  tmp_4[1] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[1];
  tmp_4[2] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[2];
  tmp_4[3] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[3];
  tmp_5[1] = 4;
  tmp_4[4] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[0];
  tmp_4[5] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[1];
  tmp_4[6] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[2];
  tmp_4[7] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[3];
  tmp_5[2] = 8;
  tmp_4[8] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[0];
  tmp_4[9] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[1];
  tmp_4[10] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[2];
  tmp_4[11] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[3];
  tmp_5[3] = 12;
  tmp_4[12] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[0];
  tmp_4[13] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[1];
  tmp_4[14] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[2];
  tmp_4[15] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[3];
  tmp_5[4] = 16;
  tmp_4[16] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[0];
  tmp_4[17] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[1];
  tmp_4[18] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[2];
  tmp_4[19] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[3];
  tmp_5[5] = 20;
  tmp_4[20] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[0];
  tmp_4[21] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[1];
  tmp_4[22] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[2];
  tmp_4[23] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[3];
  tmp_5[6] = 24;
  tmp_4[24] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[0];
  tmp_4[25] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[1];
  tmp_4[26] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[2];
  tmp_4[27] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[3];
  tmp_5[7] = 28;
  tmp_4[28] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[0];
  tmp_4[29] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[1];
  tmp_4[30] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[2];
  tmp_4[31] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[3];
  tmp_5[8] = 32;
  tmp_4[32] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[0];
  tmp_4[33] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[1];
  tmp_4[34] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[2];
  tmp_4[35] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[3];
  tmp_5[9] = 36;
  tmp_4[36] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[0];
  tmp_4[37] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[1];
  tmp_4[38] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[2];
  tmp_4[39] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[3];
  tmp_5[10] = 40;
  tmp_4[40] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[0];
  tmp_4[41] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[1];
  tmp_4[42] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[2];
  tmp_4[43] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[3];
  tmp_5[11] = 44;
  tmp_4[44] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[0];
  tmp_4[45] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[1];
  tmp_4[46] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[2];
  tmp_4[47] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[3];
  tmp_5[12] = 48;
  tmp_4[48] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[0];
  tmp_4[49] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[1];
  tmp_4[50] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[2];
  tmp_4[51] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[3];
  tmp_5[13] = 52;
  tmp_4[52] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[0];
  tmp_4[53] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[1];
  tmp_4[54] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[2];
  tmp_4[55] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[3];
  tmp_5[14] = 56;
  tmp_4[56] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[0];
  tmp_4[57] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[1];
  tmp_4[58] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[2];
  tmp_4[59] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[3];
  tmp_5[15] = 60;
  tmp_4[60] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[0];
  tmp_4[61] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[1];
  tmp_4[62] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[2];
  tmp_4[63] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[3];
  tmp_5[16] = 64;
  tmp_4[64] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[0];
  tmp_4[65] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[1];
  tmp_4[66] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[2];
  tmp_4[67] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[3];
  tmp_5[17] = 68;
  tmp_4[68] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[0];
  tmp_4[69] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[1];
  tmp_4[70] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[2];
  tmp_4[71] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[3];
  tmp_5[18] = 72;
  tmp_4[72] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[0];
  tmp_4[73] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[1];
  tmp_4[74] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[2];
  tmp_4[75] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[3];
  tmp_5[19] = 76;
  tmp_4[76] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[0];
  tmp_4[77] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[1];
  tmp_4[78] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[2];
  tmp_4[79] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[3];
  tmp_5[20] = 80;
  tmp_4[80] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[0];
  tmp_4[81] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[1];
  tmp_4[82] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[2];
  tmp_4[83] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[3];
  tmp_5[21] = 84;
  tmp_4[84] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[0];
  tmp_4[85] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[1];
  tmp_4[86] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[2];
  tmp_4[87] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[3];
  tmp_5[22] = 88;
  tmp_4[88] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[0];
  tmp_4[89] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[1];
  tmp_4[90] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[2];
  tmp_4[91] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[3];
  tmp_5[23] = 92;
  tmp_4[92] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[0];
  tmp_4[93] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[1];
  tmp_4[94] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[2];
  tmp_4[95] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[3];
  tmp_5[24] = 96;
  tmp_4[96] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[0];
  tmp_4[97] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[1];
  tmp_4[98] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[2];
  tmp_4[99] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[3];
  tmp_5[25] = 100;
  tmp_4[100] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[0];
  tmp_4[101] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[1];
  tmp_4[102] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[2];
  tmp_4[103] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[3];
  tmp_5[26] = 104;
  tmp_4[104] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[0];
  tmp_4[105] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[1];
  tmp_4[106] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[2];
  tmp_4[107] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[3];
  tmp_5[27] = 108;
  tmp_4[108] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[0];
  tmp_4[109] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[1];
  tmp_4[110] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[2];
  tmp_4[111] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[3];
  tmp_5[28] = 112;
  tmp_4[112] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[0];
  tmp_4[113] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[1];
  tmp_4[114] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[2];
  tmp_4[115] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[3];
  tmp_5[29] = 116;
  tmp_4[116] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[0];
  tmp_4[117] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[1];
  tmp_4[118] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[2];
  tmp_4[119] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[3];
  tmp_5[30] = 120;
  tmp_4[120] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[0];
  tmp_4[121] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[1];
  tmp_4[122] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[2];
  tmp_4[123] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[3];
  tmp_5[31] = 124;
  tmp_4[124] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[0];
  tmp_4[125] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[1];
  tmp_4[126] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[2];
  tmp_4[127] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[3];
  tmp_5[32] = 128;
  tmp_4[128] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[0];
  tmp_4[129] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[1];
  tmp_4[130] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[2];
  tmp_4[131] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[3];
  tmp_5[33] = 132;
  tmp_4[132] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[0];
  tmp_4[133] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[1];
  tmp_4[134] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[2];
  tmp_4[135] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[3];
  tmp_5[34] = 136;
  tmp_4[136] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[0];
  tmp_4[137] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[1];
  tmp_4[138] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[2];
  tmp_4[139] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[3];
  tmp_5[35] = 140;
  tmp_4[140] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[0];
  tmp_4[141] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[1];
  tmp_4[142] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[2];
  tmp_4[143] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[3];
  tmp_5[36] = 144;
  tmp_4[144] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[0];
  tmp_4[145] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[1];
  tmp_4[146] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[2];
  tmp_4[147] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[3];
  tmp_5[37] = 148;
  tmp_4[148] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[0];
  tmp_4[149] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[1];
  tmp_4[150] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[2];
  tmp_4[151] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[3];
  tmp_5[38] = 152;
  tmp_4[152] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[0];
  tmp_4[153] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[1];
  tmp_4[154] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[2];
  tmp_4[155] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[3];
  tmp_5[39] = 156;
  tmp_4[156] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[0];
  tmp_4[157] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[1];
  tmp_4[158] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[2];
  tmp_4[159] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[3];
  tmp_5[40] = 160;
  tmp_4[160] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[0];
  tmp_4[161] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[1];
  tmp_4[162] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[2];
  tmp_4[163] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[3];
  tmp_5[41] = 164;
  tmp_4[164] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[0];
  tmp_4[165] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[1];
  tmp_4[166] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[2];
  tmp_4[167] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[3];
  tmp_5[42] = 168;
  tmp_4[168] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[0];
  tmp_4[169] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[1];
  tmp_4[170] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[2];
  tmp_4[171] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[3];
  tmp_5[43] = 172;
  tmp_4[172] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[0];
  tmp_4[173] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[1];
  tmp_4[174] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[2];
  tmp_4[175] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[3];
  tmp_5[44] = 176;
  tmp_4[176] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[0];
  tmp_4[177] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[1];
  tmp_4[178] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[2];
  tmp_4[179] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[3];
  tmp_5[45] = 180;
  tmp_4[180] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[0];
  tmp_4[181] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[1];
  tmp_4[182] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[2];
  tmp_4[183] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[3];
  tmp_5[46] = 184;
  tmp_4[184] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[0];
  tmp_4[185] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[1];
  tmp_4[186] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[2];
  tmp_4[187] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[3];
  tmp_5[47] = 188;
  tmp_4[188] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[0];
  tmp_4[189] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[1];
  tmp_4[190] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[2];
  tmp_4[191] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[3];
  tmp_5[48] = 192;
  tmp_4[192] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[0];
  tmp_4[193] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[1];
  tmp_4[194] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[2];
  tmp_4[195] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[3];
  tmp_5[49] = 196;
  tmp_4[196] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[0];
  tmp_4[197] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[1];
  tmp_4[198] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[2];
  tmp_4[199] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[3];
  tmp_5[50] = 200;
  tmp_4[200] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[0];
  tmp_4[201] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[1];
  tmp_4[202] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[2];
  tmp_4[203] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[3];
  tmp_5[51] = 204;
  tmp_4[204] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[0];
  tmp_4[205] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[1];
  tmp_4[206] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[2];
  tmp_4[207] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[3];
  tmp_5[52] = 208;
  tmp_4[208] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[0];
  tmp_4[209] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[1];
  tmp_4[210] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[2];
  tmp_4[211] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[3];
  tmp_5[53] = 212;
  tmp_4[212] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[0];
  tmp_4[213] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[1];
  tmp_4[214] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[2];
  tmp_4[215] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[3];
  tmp_5[54] = 216;
  tmp_4[216] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[0];
  tmp_4[217] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[1];
  tmp_4[218] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[2];
  tmp_4[219] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[3];
  tmp_5[55] = 220;
  tmp_4[220] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[0];
  tmp_4[221] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[1];
  tmp_4[222] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[2];
  tmp_4[223] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[3];
  tmp_5[56] = 224;
  tmp_4[224] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[0];
  tmp_4[225] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[1];
  tmp_4[226] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[2];
  tmp_4[227] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[3];
  tmp_5[57] = 228;
  tmp_4[228] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[0];
  tmp_4[229] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[1];
  tmp_4[230] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[2];
  tmp_4[231] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[3];
  tmp_5[58] = 232;
  tmp_4[232] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[0];
  tmp_4[233] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[1];
  tmp_4[234] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[2];
  tmp_4[235] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[3];
  tmp_5[59] = 236;
  tmp_4[236] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[0];
  tmp_4[237] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[1];
  tmp_4[238] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[2];
  tmp_4[239] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[3];
  tmp_5[60] = 240;
  tmp_4[240] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[0];
  tmp_4[241] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[1];
  tmp_4[242] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[2];
  tmp_4[243] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[3];
  tmp_5[61] = 244;
  tmp_4[244] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[0];
  tmp_4[245] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[1];
  tmp_4[246] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[2];
  tmp_4[247] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[3];
  tmp_5[62] = 248;
  tmp_4[248] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[0];
  tmp_4[249] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[1];
  tmp_4[250] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[2];
  tmp_4[251] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[3];
  tmp_5[63] = 252;
  tmp_4[252] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[0];
  tmp_4[253] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[1];
  tmp_4[254] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[2];
  tmp_4[255] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[3];
  tmp_5[64] = 256;
  tmp_4[256] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[0];
  tmp_4[257] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[1];
  tmp_4[258] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[2];
  tmp_4[259] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[3];
  tmp_5[65] = 260;
  tmp_4[260] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[0];
  tmp_4[261] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[1];
  tmp_4[262] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[2];
  tmp_4[263] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[3];
  tmp_5[66] = 264;
  tmp_4[264] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[0];
  tmp_4[265] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[1];
  tmp_4[266] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[2];
  tmp_4[267] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[3];
  tmp_5[67] = 268;
  tmp_4[268] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[0];
  tmp_4[269] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[1];
  tmp_4[270] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[2];
  tmp_4[271] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[3];
  tmp_5[68] = 272;
  tmp_4[272] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[0];
  tmp_4[273] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[1];
  tmp_4[274] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[2];
  tmp_4[275] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[3];
  tmp_5[69] = 276;
  tmp_4[276] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[0];
  tmp_4[277] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[1];
  tmp_4[278] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[2];
  tmp_4[279] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[3];
  tmp_5[70] = 280;
  tmp_4[280] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[0];
  tmp_4[281] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[1];
  tmp_4[282] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[2];
  tmp_4[283] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[3];
  tmp_5[71] = 284;
  tmp_4[284] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[0];
  tmp_4[285] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[1];
  tmp_4[286] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[2];
  tmp_4[287] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[3];
  tmp_5[72] = 288;
  tmp_4[288] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[0];
  tmp_4[289] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[1];
  tmp_4[290] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[2];
  tmp_4[291] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[3];
  tmp_5[73] = 292;
  tmp_4[292] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[0];
  tmp_4[293] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[1];
  tmp_4[294] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[2];
  tmp_4[295] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[3];
  tmp_5[74] = 296;
  tmp_4[296] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[0];
  tmp_4[297] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[1];
  tmp_4[298] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[2];
  tmp_4[299] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[3];
  tmp_5[75] = 300;
  tmp_4[300] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[0];
  tmp_4[301] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[1];
  tmp_4[302] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[2];
  tmp_4[303] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[3];
  tmp_5[76] = 304;
  tmp_4[304] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[0];
  tmp_4[305] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[1];
  tmp_4[306] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[2];
  tmp_4[307] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[3];
  tmp_5[77] = 308;
  tmp_4[308] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[0];
  tmp_4[309] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[1];
  tmp_4[310] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[2];
  tmp_4[311] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[3];
  tmp_5[78] = 312;
  tmp_4[312] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[0];
  tmp_4[313] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[1];
  tmp_4[314] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[2];
  tmp_4[315] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[3];
  tmp_5[79] = 316;
  tmp_4[316] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[0];
  tmp_4[317] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[1];
  tmp_4[318] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[2];
  tmp_4[319] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[3];
  tmp_5[80] = 320;
  tmp_4[320] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[0];
  tmp_4[321] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[1];
  tmp_4[322] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[2];
  tmp_4[323] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[3];
  tmp_5[81] = 324;
  tmp_4[324] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[0];
  tmp_4[325] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[1];
  tmp_4[326] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[2];
  tmp_4[327] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[3];
  tmp_5[82] = 328;
  tmp_4[328] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[0];
  tmp_4[329] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[1];
  tmp_4[330] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[2];
  tmp_4[331] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[3];
  tmp_5[83] = 332;
  tmp_4[332] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[0];
  tmp_4[333] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[1];
  tmp_4[334] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[2];
  tmp_4[335] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[3];
  tmp_5[84] = 336;
  tmp_4[336] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[0];
  tmp_4[337] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[1];
  tmp_4[338] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[2];
  tmp_4[339] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[3];
  tmp_5[85] = 340;
  tmp_4[340] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[0];
  tmp_4[341] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[1];
  tmp_4[342] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[2];
  tmp_4[343] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[3];
  tmp_5[86] = 344;
  tmp_4[344] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[0];
  tmp_4[345] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[1];
  tmp_4[346] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[2];
  tmp_4[347] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[3];
  tmp_5[87] = 348;
  tmp_4[348] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[0];
  tmp_4[349] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[1];
  tmp_4[350] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[2];
  tmp_4[351] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[3];
  tmp_5[88] = 352;
  tmp_4[352] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[0];
  tmp_4[353] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[1];
  tmp_4[354] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[2];
  tmp_4[355] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[3];
  tmp_5[89] = 356;
  tmp_4[356] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[0];
  tmp_4[357] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[1];
  tmp_4[358] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[2];
  tmp_4[359] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[3];
  tmp_5[90] = 360;
  tmp_4[360] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[0];
  tmp_4[361] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[1];
  tmp_4[362] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[2];
  tmp_4[363] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[3];
  tmp_5[91] = 364;
  tmp_4[364] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[0];
  tmp_4[365] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[1];
  tmp_4[366] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[2];
  tmp_4[367] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[3];
  tmp_5[92] = 368;
  tmp_4[368] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[0];
  tmp_4[369] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[1];
  tmp_4[370] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[2];
  tmp_4[371] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[3];
  tmp_5[93] = 372;
  tmp_4[372] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[0];
  tmp_4[373] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[1];
  tmp_4[374] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[2];
  tmp_4[375] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[3];
  tmp_5[94] = 376;
  tmp_4[376] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[0];
  tmp_4[377] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[1];
  tmp_4[378] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[2];
  tmp_4[379] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[3];
  tmp_5[95] = 380;
  tmp_4[380] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[0];
  tmp_4[381] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[1];
  tmp_4[382] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[2];
  tmp_4[383] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[3];
  tmp_5[96] = 384;
  tmp_4[384] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[0];
  tmp_4[385] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[1];
  tmp_4[386] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[2];
  tmp_4[387] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[3];
  tmp_5[97] = 388;
  tmp_4[388] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[0];
  tmp_4[389] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[1];
  tmp_4[390] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[2];
  tmp_4[391] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[3];
  tmp_5[98] = 392;
  tmp_4[392] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[0];
  tmp_4[393] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[1];
  tmp_4[394] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[2];
  tmp_4[395] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[3];
  tmp_5[99] = 396;
  tmp_4[396] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[0];
  tmp_4[397] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[1];
  tmp_4[398] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[2];
  tmp_4[399] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[3];
  tmp_5[100] = 400;
  tmp_4[400] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[0];
  tmp_4[401] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[1];
  tmp_4[402] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[2];
  tmp_4[403] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[3];
  tmp_5[101] = 404;
  tmp_4[404] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[0];
  tmp_4[405] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[1];
  tmp_4[406] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[2];
  tmp_4[407] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[3];
  tmp_5[102] = 408;
  tmp_4[408] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[0];
  tmp_4[409] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[1];
  tmp_4[410] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[2];
  tmp_4[411] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[3];
  tmp_5[103] = 412;
  tmp_4[412] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[0];
  tmp_4[413] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[1];
  tmp_4[414] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[2];
  tmp_4[415] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[3];
  tmp_5[104] = 416;
  tmp_4[416] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[0];
  tmp_4[417] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[1];
  tmp_4[418] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[2];
  tmp_4[419] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[3];
  tmp_5[105] = 420;
  tmp_4[420] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[0];
  tmp_4[421] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[1];
  tmp_4[422] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[2];
  tmp_4[423] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[3];
  tmp_5[106] = 424;
  tmp_4[424] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[0];
  tmp_4[425] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[1];
  tmp_4[426] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[2];
  tmp_4[427] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[3];
  tmp_5[107] = 428;
  tmp_4[428] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[0];
  tmp_4[429] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[1];
  tmp_4[430] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[2];
  tmp_4[431] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[3];
  tmp_5[108] = 432;
  memcpy(&tmp_4[432], &Copy_of_Robot_leg_3_0_B.STATE_1[0], 13U * sizeof(real_T));
  tmp_5[109] = 445;
  simulationData->mData->mInputValues.mN = 445;
  simulationData->mData->mInputValues.mX = &tmp_4[0];
  simulationData->mData->mInputOffsets.mN = 110;
  simulationData->mData->mInputOffsets.mX = &tmp_5[0];
  simulationData->mData->mOutputs.mN = 12;
  simulationData->mData->mOutputs.mX = &Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[0];
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  simulationData->mData->mIsFundamentalSampleHit = false;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData,
    diagnosticManager);
  if (tmp_1 != 0) {
    first_output = error_buffer_is_empty(rtmGetErrorStatus
      (Copy_of_Robot_leg_3_0_M));
    if (first_output) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S583>/OUTPUT_1_1' */

  /* Gain: '<S346>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_h = Copy_of_Robot_leg_3_0_P.GAIN_Gain_h *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[14];

  /* Gain: '<S364>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_d = Copy_of_Robot_leg_3_0_P.GAIN_Gain_c *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[20];

  /* Gain: '<S358>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_i = Copy_of_Robot_leg_3_0_P.GAIN_Gain_p *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[18];

  /* Gain: '<S334>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_hs = Copy_of_Robot_leg_3_0_P.GAIN_Gain_ci *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[12];

  /* Gain: '<S370>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_p = Copy_of_Robot_leg_3_0_P.GAIN_Gain_k *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[22];

  /* Outport: '<Root>/measR' */
  Copy_of_Robot_leg_3_0_Y.measR[0] = Copy_of_Robot_leg_3_0_B.NormalForce;
  Copy_of_Robot_leg_3_0_Y.measR[1] = Copy_of_Robot_leg_3_0_B.FrictionForce;
  Copy_of_Robot_leg_3_0_Y.measR[2] = Copy_of_Robot_leg_3_0_B.GAIN_e;
  Copy_of_Robot_leg_3_0_Y.measR[3] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[8];
  Copy_of_Robot_leg_3_0_Y.measR[4] = Copy_of_Robot_leg_3_0_B.GAIN_h;
  Copy_of_Robot_leg_3_0_Y.measR[5] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[7];
  Copy_of_Robot_leg_3_0_Y.measR[6] = Copy_of_Robot_leg_3_0_B.GAIN_d;
  Copy_of_Robot_leg_3_0_Y.measR[7] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[10];
  Copy_of_Robot_leg_3_0_Y.measR[8] = Copy_of_Robot_leg_3_0_B.GAIN_i;
  Copy_of_Robot_leg_3_0_Y.measR[9] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[9];
  Copy_of_Robot_leg_3_0_Y.measR[10] = Copy_of_Robot_leg_3_0_B.GAIN_hs;
  Copy_of_Robot_leg_3_0_Y.measR[11] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[6];
  Copy_of_Robot_leg_3_0_Y.measR[12] = Copy_of_Robot_leg_3_0_B.GAIN_p;
  Copy_of_Robot_leg_3_0_Y.measR[13] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[11];

  /* Product: '<S117>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_d[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.Sum_bz;
  Copy_of_Robot_leg_3_0_B.Product_d[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.DeadZone_ko;
  Copy_of_Robot_leg_3_0_B.Product_d[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.Gain2_l;
  Copy_of_Robot_leg_3_0_B.Product_d[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.SprForce_ny;
  Copy_of_Robot_leg_3_0_B.Product_d[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.DampForce_b;

  /* Product: '<S165>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_m[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.Sum_aw;
  Copy_of_Robot_leg_3_0_B.Product_m[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.DeadZone_l;
  Copy_of_Robot_leg_3_0_B.Product_m[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.Gain2_fs;
  Copy_of_Robot_leg_3_0_B.Product_m[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.SprForce_a;
  Copy_of_Robot_leg_3_0_B.Product_m[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.DampForce_hs;

  /* Product: '<S213>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_e[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.Sum_iz;
  Copy_of_Robot_leg_3_0_B.Product_e[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.DeadZone_k;
  Copy_of_Robot_leg_3_0_B.Product_e[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.Gain2_b;
  Copy_of_Robot_leg_3_0_B.Product_e[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.SprForce_e;
  Copy_of_Robot_leg_3_0_B.Product_e[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.DampForce_f;

  /* Product: '<S261>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_j[0] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.Sum_jg;

  /* Product: '<S117>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_d[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.Gain_hg[0];

  /* Product: '<S165>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_m[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.Gain_d1[0];

  /* Product: '<S213>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_e[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.Gain_ib[0];

  /* Product: '<S261>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_j[1] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.Gain_eu[0];

  /* Product: '<S117>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_d[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.Gain_hg[1];

  /* Product: '<S165>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_m[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.Gain_d1[1];

  /* Product: '<S213>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_e[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.Gain_ib[1];

  /* Product: '<S261>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_j[2] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.Gain_eu[1];

  /* Product: '<S117>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_d[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_a *
    Copy_of_Robot_leg_3_0_B.Gain_hg[2];

  /* Product: '<S165>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_m[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_p *
    Copy_of_Robot_leg_3_0_B.Gain_d1[2];

  /* Product: '<S213>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_e[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_b *
    Copy_of_Robot_leg_3_0_B.Gain_ib[2];

  /* Product: '<S261>/Product' */
  Copy_of_Robot_leg_3_0_B.Product_j[3] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.Gain_eu[2];
  Copy_of_Robot_leg_3_0_B.Product_j[4] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.DeadZone_ap;
  Copy_of_Robot_leg_3_0_B.Product_j[5] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.Gain2_e;
  Copy_of_Robot_leg_3_0_B.Product_j[6] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.SprForce_m;
  Copy_of_Robot_leg_3_0_B.Product_j[7] =
    Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu *
    Copy_of_Robot_leg_3_0_B.DampForce_n;

  /* Sum: '<S48>/Add' */
  Copy_of_Robot_leg_3_0_B.NormalForce_i = ((Copy_of_Robot_leg_3_0_B.Product_d[0]
    + Copy_of_Robot_leg_3_0_B.Product_m[0]) + Copy_of_Robot_leg_3_0_B.Product_e
    [0]) + Copy_of_Robot_leg_3_0_B.Product_j[0];

  /* Sum: '<S48>/Add1' */
  Copy_of_Robot_leg_3_0_B.Add1_i[0] = ((Copy_of_Robot_leg_3_0_B.Product_d[1] +
    Copy_of_Robot_leg_3_0_B.Product_m[1]) + Copy_of_Robot_leg_3_0_B.Product_e[1])
    + Copy_of_Robot_leg_3_0_B.Product_j[1];

  /* Math: '<S48>/Math Function' */
  Copy_of_Robot_leg_3_0_B.MathFunction_i[0] = Copy_of_Robot_leg_3_0_B.Add1_i[0] *
    Copy_of_Robot_leg_3_0_B.Add1_i[0];

  /* Sum: '<S48>/Add1' */
  Copy_of_Robot_leg_3_0_B.Add1_i[1] = ((Copy_of_Robot_leg_3_0_B.Product_d[2] +
    Copy_of_Robot_leg_3_0_B.Product_m[2]) + Copy_of_Robot_leg_3_0_B.Product_e[2])
    + Copy_of_Robot_leg_3_0_B.Product_j[2];

  /* Math: '<S48>/Math Function' */
  Copy_of_Robot_leg_3_0_B.MathFunction_i[1] = Copy_of_Robot_leg_3_0_B.Add1_i[1] *
    Copy_of_Robot_leg_3_0_B.Add1_i[1];

  /* Sum: '<S48>/Add1' */
  Copy_of_Robot_leg_3_0_B.Add1_i[2] = ((Copy_of_Robot_leg_3_0_B.Product_d[3] +
    Copy_of_Robot_leg_3_0_B.Product_m[3]) + Copy_of_Robot_leg_3_0_B.Product_e[3])
    + Copy_of_Robot_leg_3_0_B.Product_j[3];

  /* Math: '<S48>/Math Function' */
  Copy_of_Robot_leg_3_0_B.MathFunction_i[2] = Copy_of_Robot_leg_3_0_B.Add1_i[2] *
    Copy_of_Robot_leg_3_0_B.Add1_i[2];

  /* Sum: '<S48>/Sum of Elements' */
  pulseWidth = Copy_of_Robot_leg_3_0_B.MathFunction_i[0];
  pulseWidth += Copy_of_Robot_leg_3_0_B.MathFunction_i[1];
  pulseWidth += Copy_of_Robot_leg_3_0_B.MathFunction_i[2];
  Copy_of_Robot_leg_3_0_B.SumofElements_l = pulseWidth;

  /* Sqrt: '<S48>/Sqrt' */
  Copy_of_Robot_leg_3_0_B.FrictionForce_k = sqrt
    (Copy_of_Robot_leg_3_0_B.SumofElements_l);

  /* Gain: '<S88>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_dq = Copy_of_Robot_leg_3_0_P.GAIN_Gain_cu *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[8];

  /* Gain: '<S82>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_b = Copy_of_Robot_leg_3_0_P.GAIN_Gain_hy *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[0];

  /* Gain: '<S100>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_eg = Copy_of_Robot_leg_3_0_P.GAIN_Gain_pv *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[4];

  /* Gain: '<S94>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_hq = Copy_of_Robot_leg_3_0_P.GAIN_Gain_e *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[2];

  /* Gain: '<S70>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_m = Copy_of_Robot_leg_3_0_P.GAIN_Gain_a *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[6];

  /* Gain: '<S106>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_em = Copy_of_Robot_leg_3_0_P.GAIN_Gain_m *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[10];

  /* Outport: '<Root>/measL' */
  Copy_of_Robot_leg_3_0_Y.measL[0] = Copy_of_Robot_leg_3_0_B.NormalForce_i;
  Copy_of_Robot_leg_3_0_Y.measL[1] = Copy_of_Robot_leg_3_0_B.FrictionForce_k;
  Copy_of_Robot_leg_3_0_Y.measL[2] = Copy_of_Robot_leg_3_0_B.GAIN_dq;
  Copy_of_Robot_leg_3_0_Y.measL[3] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[4];
  Copy_of_Robot_leg_3_0_Y.measL[4] = Copy_of_Robot_leg_3_0_B.GAIN_b;
  Copy_of_Robot_leg_3_0_Y.measL[5] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[0];
  Copy_of_Robot_leg_3_0_Y.measL[6] = Copy_of_Robot_leg_3_0_B.GAIN_eg;
  Copy_of_Robot_leg_3_0_Y.measL[7] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[2];
  Copy_of_Robot_leg_3_0_Y.measL[8] = Copy_of_Robot_leg_3_0_B.GAIN_hq;
  Copy_of_Robot_leg_3_0_Y.measL[9] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[1];
  Copy_of_Robot_leg_3_0_Y.measL[10] = Copy_of_Robot_leg_3_0_B.GAIN_m;
  Copy_of_Robot_leg_3_0_Y.measL[11] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[3];
  Copy_of_Robot_leg_3_0_Y.measL[12] = Copy_of_Robot_leg_3_0_B.GAIN_em;
  Copy_of_Robot_leg_3_0_Y.measL[13] = Copy_of_Robot_leg_3_0_B.OUTPUT_1_1[5];
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    /* S-Function (slrtIPConfig): '<S4>/UDP Configure' */

    /* Level2 S-Function Block: '<S4>/UDP Configure' (slrtIPConfig) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }
  }

  /* S-Function (scblock): '<S26>/S-Function' */
  /* ok to acquire for <S26>/S-Function */
  Copy_of_Robot_leg_3_0_DW.SFunction_IWORK.AcquireOK = 1;

  /* Gain: '<S307>/GAIN' */
  Copy_of_Robot_leg_3_0_B.GAIN_l[0] = Copy_of_Robot_leg_3_0_P.GAIN_Gain_mq *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[160];
  Copy_of_Robot_leg_3_0_B.GAIN_l[1] = Copy_of_Robot_leg_3_0_P.GAIN_Gain_mq *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[161];
  Copy_of_Robot_leg_3_0_B.GAIN_l[2] = Copy_of_Robot_leg_3_0_P.GAIN_Gain_mq *
    Copy_of_Robot_leg_3_0_B.OUTPUT_1_0[162];

  /* Clock: '<S9>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_lc = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S9>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S9>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_er = Copy_of_Robot_leg_3_0_B.Clock_lc - (0.0);

  /* Math: '<S9>/Math Function' incorporates:
   *  Constant: '<S9>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_b = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_er, Copy_of_Robot_leg_3_0_P.Constant_Value_c0);

  /* Lookup_n-D: '<S9>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_hv = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_b,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_c,
     Copy_of_Robot_leg_3_0_P.left_abduction, 39U);

  /* SignalConversion: '<S9>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_k = Copy_of_Robot_leg_3_0_B.LookUpTable1_hv;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S10>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_b5 = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S10>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S10>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_eb = Copy_of_Robot_leg_3_0_B.Clock_b5 - (0.0);

  /* Math: '<S10>/Math Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_bl = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_eb, Copy_of_Robot_leg_3_0_P.Constant_Value_ld);

  /* Lookup_n-D: '<S10>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_l4 = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_bl,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_pu,
     Copy_of_Robot_leg_3_0_P.left_knee_twist, 39U);

  /* SignalConversion: '<S10>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_h2 = Copy_of_Robot_leg_3_0_B.LookUpTable1_l4;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S11>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_i = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S11>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S11>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_o = Copy_of_Robot_leg_3_0_B.Clock_i - (0.0);

  /* Math: '<S11>/Math Function' incorporates:
   *  Constant: '<S11>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_gl = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_o, Copy_of_Robot_leg_3_0_P.Constant_Value_ahx);

  /* Lookup_n-D: '<S11>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_pq = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_gl,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_pc,
     Copy_of_Robot_leg_3_0_P.left_ankle, 39U);

  /* SignalConversion: '<S11>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_dc = Copy_of_Robot_leg_3_0_B.LookUpTable1_pq;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S12>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_d = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S12>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S12>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_d = Copy_of_Robot_leg_3_0_B.Clock_d - (0.0);

  /* Math: '<S12>/Math Function' incorporates:
   *  Constant: '<S12>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_hx = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_d, Copy_of_Robot_leg_3_0_P.Constant_Value_e);

  /* Lookup_n-D: '<S12>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_pv = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_hx,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_cv,
     Copy_of_Robot_leg_3_0_P.left_hip, 39U);

  /* SignalConversion: '<S12>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_n = Copy_of_Robot_leg_3_0_B.LookUpTable1_pv;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S13>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_h = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S13>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S13>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_m = Copy_of_Robot_leg_3_0_B.Clock_h - (0.0);

  /* Math: '<S13>/Math Function' incorporates:
   *  Constant: '<S13>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_cx = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_m, Copy_of_Robot_leg_3_0_P.Constant_Value_ca);

  /* Lookup_n-D: '<S13>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_m = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_cx,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_m4,
     Copy_of_Robot_leg_3_0_P.left_knee, 39U);

  /* SignalConversion: '<S13>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_i = Copy_of_Robot_leg_3_0_B.LookUpTable1_m;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S14>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_hr = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S14>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S14>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_j = Copy_of_Robot_leg_3_0_B.Clock_hr - (0.0);

  /* Math: '<S14>/Math Function' incorporates:
   *  Constant: '<S14>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_l4 = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_j, Copy_of_Robot_leg_3_0_P.Constant_Value_ci);

  /* Lookup_n-D: '<S14>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_du = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_l4,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_cm,
     Copy_of_Robot_leg_3_0_P.left_rotation, 39U);

  /* SignalConversion: '<S14>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_e = Copy_of_Robot_leg_3_0_B.LookUpTable1_du;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S18>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_f = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S18>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S18>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_a5 = Copy_of_Robot_leg_3_0_B.Clock_f - (0.0);

  /* Math: '<S18>/Math Function' incorporates:
   *  Constant: '<S18>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_j = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_a5, Copy_of_Robot_leg_3_0_P.Constant_Value_ii);

  /* Lookup_n-D: '<S18>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_b = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_j,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_bl,
     Copy_of_Robot_leg_3_0_P.right_abduction, 39U);

  /* SignalConversion: '<S18>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_b = Copy_of_Robot_leg_3_0_B.LookUpTable1_b;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S19>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_lw = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S19>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S19>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_n = Copy_of_Robot_leg_3_0_B.Clock_lw - (0.0);

  /* Math: '<S19>/Math Function' incorporates:
   *  Constant: '<S19>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_ar = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_n, Copy_of_Robot_leg_3_0_P.Constant_Value_n);

  /* Lookup_n-D: '<S19>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_i = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_ar,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_fq,
     Copy_of_Robot_leg_3_0_P.right_knee_twist, 39U);

  /* SignalConversion: '<S19>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_nc = Copy_of_Robot_leg_3_0_B.LookUpTable1_i;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S20>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_ly = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S20>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S20>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_me = Copy_of_Robot_leg_3_0_B.Clock_ly - (0.0);

  /* Math: '<S20>/Math Function' incorporates:
   *  Constant: '<S20>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_f = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_me, Copy_of_Robot_leg_3_0_P.Constant_Value_d);

  /* Lookup_n-D: '<S20>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_iy = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_f,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_dg,
     Copy_of_Robot_leg_3_0_P.right_ankle, 39U);

  /* SignalConversion: '<S20>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_f3 = Copy_of_Robot_leg_3_0_B.LookUpTable1_iy;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S21>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_ao = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S21>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S21>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_ebu = Copy_of_Robot_leg_3_0_B.Clock_ao - (0.0);

  /* Math: '<S21>/Math Function' incorporates:
   *  Constant: '<S21>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_k = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_ebu, Copy_of_Robot_leg_3_0_P.Constant_Value_de);

  /* Lookup_n-D: '<S21>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_ba = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_k,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_jd,
     Copy_of_Robot_leg_3_0_P.right_hip, 39U);

  /* SignalConversion: '<S21>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_kh = Copy_of_Robot_leg_3_0_B.LookUpTable1_ba;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S22>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_c = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S22>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S22>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_ez = Copy_of_Robot_leg_3_0_B.Clock_c - (0.0);

  /* Math: '<S22>/Math Function' incorporates:
   *  Constant: '<S22>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_m0 = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_ez, Copy_of_Robot_leg_3_0_P.Constant_Value_f);

  /* Lookup_n-D: '<S22>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_cs = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_m0,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_g,
     Copy_of_Robot_leg_3_0_P.right_knee, 39U);

  /* SignalConversion: '<S22>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_fc = Copy_of_Robot_leg_3_0_B.LookUpTable1_cs;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Clock: '<S23>/Clock' */
  Copy_of_Robot_leg_3_0_B.Clock_o = Copy_of_Robot_leg_3_0_M->Timing.t[0];

  /* Sum: '<S23>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S23>/startTime'
   */
  Copy_of_Robot_leg_3_0_B.Sum_b = Copy_of_Robot_leg_3_0_B.Clock_o - (0.0);

  /* Math: '<S23>/Math Function' incorporates:
   *  Constant: '<S23>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.MathFunction_lq = rt_remd_snf
    (Copy_of_Robot_leg_3_0_B.Sum_b, Copy_of_Robot_leg_3_0_P.Constant_Value_hw);

  /* Lookup_n-D: '<S23>/Look-Up Table1' */
  Copy_of_Robot_leg_3_0_B.LookUpTable1_mf = look1_binlxpw
    (Copy_of_Robot_leg_3_0_B.MathFunction_lq,
     Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_gn,
     Copy_of_Robot_leg_3_0_P.right_rotation, 39U);

  /* SignalConversion: '<S23>/Output' */
  Copy_of_Robot_leg_3_0_B.Output_l = Copy_of_Robot_leg_3_0_B.LookUpTable1_mf;
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
  }

  /* Gain: '<S30>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_o = Copy_of_Robot_leg_3_0_P.Gain_Gain_gm *
    Copy_of_Robot_leg_3_0_B.Output_l;

  /* Sum: '<S30>/Add' incorporates:
   *  Constant: '<S30>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_g = Copy_of_Robot_leg_3_0_B.Gain_o +
    Copy_of_Robot_leg_3_0_P.Constant_Value_ir;

  /* DataTypeConversion: '<S30>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_g);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_e = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S30>/Data Type Conversion' */

  /* Gain: '<S32>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_h = Copy_of_Robot_leg_3_0_P.Gain_Gain_jt *
    Copy_of_Robot_leg_3_0_B.Output_b;

  /* Sum: '<S32>/Add' incorporates:
   *  Constant: '<S32>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_j = Copy_of_Robot_leg_3_0_B.Gain_h +
    Copy_of_Robot_leg_3_0_P.Constant_Value_lc;

  /* DataTypeConversion: '<S32>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_j);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_g = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S32>/Data Type Conversion' */

  /* Gain: '<S31>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_jh = Copy_of_Robot_leg_3_0_P.Gain_Gain_k *
    Copy_of_Robot_leg_3_0_B.Output_kh;

  /* Sum: '<S31>/Add' incorporates:
   *  Constant: '<S31>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_l = Copy_of_Robot_leg_3_0_B.Gain_jh +
    Copy_of_Robot_leg_3_0_P.Constant_Value_p;

  /* DataTypeConversion: '<S31>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_l);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_p5 = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S31>/Data Type Conversion' */

  /* Gain: '<S33>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_k = Copy_of_Robot_leg_3_0_P.Gain_Gain_e *
    Copy_of_Robot_leg_3_0_B.Output_fc;

  /* Sum: '<S33>/Add' incorporates:
   *  Constant: '<S33>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_n = Copy_of_Robot_leg_3_0_B.Gain_k +
    Copy_of_Robot_leg_3_0_P.Constant_Value_jj;

  /* DataTypeConversion: '<S33>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_n);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_c = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S33>/Data Type Conversion' */

  /* Gain: '<S41>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_js = Copy_of_Robot_leg_3_0_P.Gain_Gain_pn *
    Copy_of_Robot_leg_3_0_B.Output_f3;

  /* Sum: '<S41>/Add' incorporates:
   *  Constant: '<S41>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_b = Copy_of_Robot_leg_3_0_B.Gain_js +
    Copy_of_Robot_leg_3_0_P.Constant_Value_ch;

  /* DataTypeConversion: '<S41>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_b);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_f = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S41>/Data Type Conversion' */

  /* Gain: '<S40>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_jw = Copy_of_Robot_leg_3_0_P.Gain_Gain_iz *
    Copy_of_Robot_leg_3_0_B.Output_nc;

  /* Sum: '<S40>/Add' incorporates:
   *  Constant: '<S40>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_a = Copy_of_Robot_leg_3_0_B.Gain_jw +
    Copy_of_Robot_leg_3_0_P.Constant_Value_k0;

  /* DataTypeConversion: '<S40>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_a);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_j = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S40>/Data Type Conversion' */

  /* Gain: '<S39>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_gb = Copy_of_Robot_leg_3_0_P.Gain_Gain_nu *
    Copy_of_Robot_leg_3_0_B.Output_e;

  /* Sum: '<S39>/Add' incorporates:
   *  Constant: '<S39>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_jp = Copy_of_Robot_leg_3_0_B.Gain_gb +
    Copy_of_Robot_leg_3_0_P.Constant_Value_ih;

  /* DataTypeConversion: '<S39>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_jp);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_d = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S39>/Data Type Conversion' */

  /* Gain: '<S38>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_i = Copy_of_Robot_leg_3_0_P.Gain_Gain_dl *
    Copy_of_Robot_leg_3_0_B.Output_k;

  /* Sum: '<S38>/Add' incorporates:
   *  Constant: '<S38>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_jr = Copy_of_Robot_leg_3_0_B.Gain_i +
    Copy_of_Robot_leg_3_0_P.Constant_Value_dx;

  /* DataTypeConversion: '<S38>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_jr);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_k = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S38>/Data Type Conversion' */

  /* Gain: '<S37>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_gp = Copy_of_Robot_leg_3_0_P.Gain_Gain_nx *
    Copy_of_Robot_leg_3_0_B.Output_n;

  /* Sum: '<S37>/Add' incorporates:
   *  Constant: '<S37>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_i = Copy_of_Robot_leg_3_0_B.Gain_gp +
    Copy_of_Robot_leg_3_0_P.Constant_Value_od;

  /* DataTypeConversion: '<S37>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_i);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_aq = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S37>/Data Type Conversion' */

  /* Gain: '<S36>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_b = Copy_of_Robot_leg_3_0_P.Gain_Gain_mo4 *
    Copy_of_Robot_leg_3_0_B.Output_i;

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_aa = Copy_of_Robot_leg_3_0_B.Gain_b +
    Copy_of_Robot_leg_3_0_P.Constant_Value_pq;

  /* DataTypeConversion: '<S36>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_aa);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_ec = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S36>/Data Type Conversion' */

  /* Gain: '<S35>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_i3 = Copy_of_Robot_leg_3_0_P.Gain_Gain_nu0 *
    Copy_of_Robot_leg_3_0_B.Output_dc;

  /* Sum: '<S35>/Add' incorporates:
   *  Constant: '<S35>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_by = Copy_of_Robot_leg_3_0_B.Gain_i3 +
    Copy_of_Robot_leg_3_0_P.Constant_Value_dr;

  /* DataTypeConversion: '<S35>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_by);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_a4 = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S35>/Data Type Conversion' */

  /* Gain: '<S34>/Gain' */
  Copy_of_Robot_leg_3_0_B.Gain_fj = Copy_of_Robot_leg_3_0_P.Gain_Gain_nv *
    Copy_of_Robot_leg_3_0_B.Output_h2;

  /* Sum: '<S34>/Add' incorporates:
   *  Constant: '<S34>/Constant'
   */
  Copy_of_Robot_leg_3_0_B.Add_i5 = Copy_of_Robot_leg_3_0_B.Gain_fj +
    Copy_of_Robot_leg_3_0_P.Constant_Value_mm;

  /* DataTypeConversion: '<S34>/Data Type Conversion' */
  pulseWidth = floor(Copy_of_Robot_leg_3_0_B.Add_i5);
  if (rtIsNaN(pulseWidth) || rtIsInf(pulseWidth)) {
    pulseWidth = 0.0;
  } else {
    pulseWidth = fmod(pulseWidth, 4.294967296E+9);
  }

  Copy_of_Robot_leg_3_0_B.DataTypeConversion_dj = pulseWidth < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-pulseWidth : (uint32_T)pulseWidth;

  /* End of DataTypeConversion: '<S34>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    /* S-Function (asciiencode): '<S4>/ASCII Encode 2' */

    /* Level2 S-Function Block: '<S4>/ASCII Encode 2' (asciiencode) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[1];
      sfcnOutputs(rts,1);
    }

    /* Constant: '<S4>/Constant3' */
    Copy_of_Robot_leg_3_0_B.Constant3 = Copy_of_Robot_leg_3_0_P.Constant3_Value;

    /* S-Function (slrtUDPSend): '<S4>/UDP Send' */

    /* Level2 S-Function Block: '<S4>/UDP Send' (slrtUDPSend) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[2];
      sfcnOutputs(rts,1);
    }
  }
}

/* Model update function */
void Copy_of_Robot_leg_3_0_update(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[432];
  int_T tmp_1[109];
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;

  /* Update for TransportDelay: '<S4>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &Copy_of_Robot_leg_3_0_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &Copy_of_Robot_leg_3_0_DW.TransportDelay_PWORK.TUbufferPtrs[3];
    real_T simTime = Copy_of_Robot_leg_3_0_M->Timing.t[0];
    Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0] =
      ((Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0] <
        (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[0]-1)) ?
       (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0]+1) : 0);
    if (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0] ==
        Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[0]) {
      Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[0] =
        ((Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[0] <
          (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[0]-1)) ?
         (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[0]+1) : 0);
    }

    (*tBuffer++)[Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0]] =
      simTime;
    (*uBuffer++)[Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0]] =
      Copy_of_Robot_leg_3_0_B.GAIN_l[0];
    Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[1] =
      ((Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[1] <
        (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[1]-1)) ?
       (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[1]+1) : 0);
    if (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[1] ==
        Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[1]) {
      Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[1] =
        ((Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[1] <
          (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[1]-1)) ?
         (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[1]+1) : 0);
    }

    (*tBuffer++)[Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[1]] =
      simTime;
    (*uBuffer++)[Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[1]] =
      Copy_of_Robot_leg_3_0_B.GAIN_l[1];
    Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[2] =
      ((Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[2] <
        (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[2]-1)) ?
       (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[2]+1) : 0);
    if (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[2] ==
        Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[2]) {
      Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[2] =
        ((Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[2] <
          (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[2]-1)) ?
         (Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[2]+1) : 0);
    }

    (*tBuffer)[Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[2]] = simTime;
    (*uBuffer)[Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[2]] =
      Copy_of_Robot_leg_3_0_B.GAIN_l[2];
  }

  /* Update for SimscapeExecutionBlock: '<S583>/STATE_1' */
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_SimulationData;
  time = Copy_of_Robot_leg_3_0_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX = (real_T *)
    &Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0x6_DOF_Joi;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Copy_of_Robot_leg_3_0_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Copy_of_Robot_leg_3_0_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[0];
  tmp_0[1] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[1];
  tmp_0[2] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[2];
  tmp_0[3] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[0];
  tmp_0[5] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[1];
  tmp_0[6] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[2];
  tmp_0[7] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[0];
  tmp_0[9] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[1];
  tmp_0[10] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[2];
  tmp_0[11] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[0];
  tmp_0[13] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[1];
  tmp_0[14] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[2];
  tmp_0[15] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[0];
  tmp_0[17] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[1];
  tmp_0[18] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[2];
  tmp_0[19] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[0];
  tmp_0[21] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[1];
  tmp_0[22] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[2];
  tmp_0[23] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[0];
  tmp_0[25] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[1];
  tmp_0[26] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[2];
  tmp_0[27] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[0];
  tmp_0[29] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[1];
  tmp_0[30] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[2];
  tmp_0[31] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[3];
  tmp_1[8] = 32;
  tmp_0[32] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[0];
  tmp_0[33] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[1];
  tmp_0[34] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[2];
  tmp_0[35] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[3];
  tmp_1[9] = 36;
  tmp_0[36] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[0];
  tmp_0[37] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[1];
  tmp_0[38] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[2];
  tmp_0[39] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[3];
  tmp_1[10] = 40;
  tmp_0[40] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[0];
  tmp_0[41] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[1];
  tmp_0[42] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[2];
  tmp_0[43] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[3];
  tmp_1[11] = 44;
  tmp_0[44] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[0];
  tmp_0[45] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[1];
  tmp_0[46] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[2];
  tmp_0[47] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[3];
  tmp_1[12] = 48;
  tmp_0[48] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[0];
  tmp_0[49] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[1];
  tmp_0[50] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[2];
  tmp_0[51] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[3];
  tmp_1[13] = 52;
  tmp_0[52] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[0];
  tmp_0[53] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[1];
  tmp_0[54] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[2];
  tmp_0[55] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[3];
  tmp_1[14] = 56;
  tmp_0[56] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[0];
  tmp_0[57] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[1];
  tmp_0[58] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[2];
  tmp_0[59] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[3];
  tmp_1[15] = 60;
  tmp_0[60] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[0];
  tmp_0[61] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[1];
  tmp_0[62] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[2];
  tmp_0[63] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[3];
  tmp_1[16] = 64;
  tmp_0[64] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[0];
  tmp_0[65] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[1];
  tmp_0[66] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[2];
  tmp_0[67] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[3];
  tmp_1[17] = 68;
  tmp_0[68] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[0];
  tmp_0[69] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[1];
  tmp_0[70] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[2];
  tmp_0[71] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[3];
  tmp_1[18] = 72;
  tmp_0[72] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[0];
  tmp_0[73] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[1];
  tmp_0[74] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[2];
  tmp_0[75] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[3];
  tmp_1[19] = 76;
  tmp_0[76] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[0];
  tmp_0[77] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[1];
  tmp_0[78] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[2];
  tmp_0[79] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[3];
  tmp_1[20] = 80;
  tmp_0[80] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[0];
  tmp_0[81] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[1];
  tmp_0[82] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[2];
  tmp_0[83] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[3];
  tmp_1[21] = 84;
  tmp_0[84] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[0];
  tmp_0[85] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[1];
  tmp_0[86] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[2];
  tmp_0[87] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[3];
  tmp_1[22] = 88;
  tmp_0[88] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[0];
  tmp_0[89] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[1];
  tmp_0[90] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[2];
  tmp_0[91] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[3];
  tmp_1[23] = 92;
  tmp_0[92] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[0];
  tmp_0[93] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[1];
  tmp_0[94] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[2];
  tmp_0[95] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[3];
  tmp_1[24] = 96;
  tmp_0[96] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[0];
  tmp_0[97] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[1];
  tmp_0[98] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[2];
  tmp_0[99] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[3];
  tmp_1[25] = 100;
  tmp_0[100] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[0];
  tmp_0[101] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[1];
  tmp_0[102] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[2];
  tmp_0[103] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[3];
  tmp_1[26] = 104;
  tmp_0[104] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[0];
  tmp_0[105] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[1];
  tmp_0[106] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[2];
  tmp_0[107] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[3];
  tmp_1[27] = 108;
  tmp_0[108] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[0];
  tmp_0[109] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[1];
  tmp_0[110] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[2];
  tmp_0[111] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[3];
  tmp_1[28] = 112;
  tmp_0[112] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[0];
  tmp_0[113] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[1];
  tmp_0[114] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[2];
  tmp_0[115] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[3];
  tmp_1[29] = 116;
  tmp_0[116] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[0];
  tmp_0[117] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[1];
  tmp_0[118] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[2];
  tmp_0[119] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[3];
  tmp_1[30] = 120;
  tmp_0[120] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[0];
  tmp_0[121] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[1];
  tmp_0[122] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[2];
  tmp_0[123] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[3];
  tmp_1[31] = 124;
  tmp_0[124] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[0];
  tmp_0[125] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[1];
  tmp_0[126] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[2];
  tmp_0[127] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[3];
  tmp_1[32] = 128;
  tmp_0[128] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[0];
  tmp_0[129] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[1];
  tmp_0[130] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[2];
  tmp_0[131] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[3];
  tmp_1[33] = 132;
  tmp_0[132] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[0];
  tmp_0[133] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[1];
  tmp_0[134] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[2];
  tmp_0[135] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[3];
  tmp_1[34] = 136;
  tmp_0[136] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[0];
  tmp_0[137] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[1];
  tmp_0[138] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[2];
  tmp_0[139] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[3];
  tmp_1[35] = 140;
  tmp_0[140] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[0];
  tmp_0[141] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[1];
  tmp_0[142] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[2];
  tmp_0[143] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[3];
  tmp_1[36] = 144;
  tmp_0[144] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[0];
  tmp_0[145] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[1];
  tmp_0[146] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[2];
  tmp_0[147] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[3];
  tmp_1[37] = 148;
  tmp_0[148] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[0];
  tmp_0[149] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[1];
  tmp_0[150] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[2];
  tmp_0[151] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[3];
  tmp_1[38] = 152;
  tmp_0[152] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[0];
  tmp_0[153] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[1];
  tmp_0[154] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[2];
  tmp_0[155] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[3];
  tmp_1[39] = 156;
  tmp_0[156] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[0];
  tmp_0[157] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[1];
  tmp_0[158] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[2];
  tmp_0[159] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[3];
  tmp_1[40] = 160;
  tmp_0[160] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[0];
  tmp_0[161] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[1];
  tmp_0[162] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[2];
  tmp_0[163] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[3];
  tmp_1[41] = 164;
  tmp_0[164] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[0];
  tmp_0[165] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[1];
  tmp_0[166] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[2];
  tmp_0[167] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[3];
  tmp_1[42] = 168;
  tmp_0[168] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[0];
  tmp_0[169] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[1];
  tmp_0[170] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[2];
  tmp_0[171] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[3];
  tmp_1[43] = 172;
  tmp_0[172] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[0];
  tmp_0[173] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[1];
  tmp_0[174] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[2];
  tmp_0[175] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[3];
  tmp_1[44] = 176;
  tmp_0[176] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[0];
  tmp_0[177] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[1];
  tmp_0[178] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[2];
  tmp_0[179] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[3];
  tmp_1[45] = 180;
  tmp_0[180] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[0];
  tmp_0[181] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[1];
  tmp_0[182] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[2];
  tmp_0[183] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[3];
  tmp_1[46] = 184;
  tmp_0[184] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[0];
  tmp_0[185] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[1];
  tmp_0[186] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[2];
  tmp_0[187] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[3];
  tmp_1[47] = 188;
  tmp_0[188] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[0];
  tmp_0[189] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[1];
  tmp_0[190] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[2];
  tmp_0[191] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[3];
  tmp_1[48] = 192;
  tmp_0[192] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[0];
  tmp_0[193] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[1];
  tmp_0[194] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[2];
  tmp_0[195] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[3];
  tmp_1[49] = 196;
  tmp_0[196] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[0];
  tmp_0[197] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[1];
  tmp_0[198] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[2];
  tmp_0[199] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[3];
  tmp_1[50] = 200;
  tmp_0[200] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[0];
  tmp_0[201] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[1];
  tmp_0[202] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[2];
  tmp_0[203] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[3];
  tmp_1[51] = 204;
  tmp_0[204] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[0];
  tmp_0[205] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[1];
  tmp_0[206] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[2];
  tmp_0[207] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[3];
  tmp_1[52] = 208;
  tmp_0[208] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[0];
  tmp_0[209] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[1];
  tmp_0[210] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[2];
  tmp_0[211] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[3];
  tmp_1[53] = 212;
  tmp_0[212] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[0];
  tmp_0[213] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[1];
  tmp_0[214] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[2];
  tmp_0[215] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[3];
  tmp_1[54] = 216;
  tmp_0[216] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[0];
  tmp_0[217] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[1];
  tmp_0[218] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[2];
  tmp_0[219] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[3];
  tmp_1[55] = 220;
  tmp_0[220] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[0];
  tmp_0[221] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[1];
  tmp_0[222] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[2];
  tmp_0[223] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[3];
  tmp_1[56] = 224;
  tmp_0[224] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[0];
  tmp_0[225] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[1];
  tmp_0[226] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[2];
  tmp_0[227] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[3];
  tmp_1[57] = 228;
  tmp_0[228] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[0];
  tmp_0[229] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[1];
  tmp_0[230] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[2];
  tmp_0[231] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[3];
  tmp_1[58] = 232;
  tmp_0[232] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[0];
  tmp_0[233] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[1];
  tmp_0[234] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[2];
  tmp_0[235] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[3];
  tmp_1[59] = 236;
  tmp_0[236] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[0];
  tmp_0[237] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[1];
  tmp_0[238] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[2];
  tmp_0[239] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[3];
  tmp_1[60] = 240;
  tmp_0[240] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[0];
  tmp_0[241] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[1];
  tmp_0[242] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[2];
  tmp_0[243] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[3];
  tmp_1[61] = 244;
  tmp_0[244] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[0];
  tmp_0[245] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[1];
  tmp_0[246] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[2];
  tmp_0[247] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[3];
  tmp_1[62] = 248;
  tmp_0[248] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[0];
  tmp_0[249] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[1];
  tmp_0[250] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[2];
  tmp_0[251] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[3];
  tmp_1[63] = 252;
  tmp_0[252] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[0];
  tmp_0[253] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[1];
  tmp_0[254] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[2];
  tmp_0[255] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[3];
  tmp_1[64] = 256;
  tmp_0[256] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[0];
  tmp_0[257] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[1];
  tmp_0[258] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[2];
  tmp_0[259] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[3];
  tmp_1[65] = 260;
  tmp_0[260] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[0];
  tmp_0[261] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[1];
  tmp_0[262] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[2];
  tmp_0[263] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[3];
  tmp_1[66] = 264;
  tmp_0[264] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[0];
  tmp_0[265] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[1];
  tmp_0[266] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[2];
  tmp_0[267] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[3];
  tmp_1[67] = 268;
  tmp_0[268] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[0];
  tmp_0[269] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[1];
  tmp_0[270] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[2];
  tmp_0[271] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[3];
  tmp_1[68] = 272;
  tmp_0[272] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[0];
  tmp_0[273] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[1];
  tmp_0[274] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[2];
  tmp_0[275] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[3];
  tmp_1[69] = 276;
  tmp_0[276] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[0];
  tmp_0[277] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[1];
  tmp_0[278] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[2];
  tmp_0[279] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[3];
  tmp_1[70] = 280;
  tmp_0[280] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[0];
  tmp_0[281] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[1];
  tmp_0[282] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[2];
  tmp_0[283] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[3];
  tmp_1[71] = 284;
  tmp_0[284] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[0];
  tmp_0[285] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[1];
  tmp_0[286] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[2];
  tmp_0[287] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[3];
  tmp_1[72] = 288;
  tmp_0[288] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[0];
  tmp_0[289] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[1];
  tmp_0[290] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[2];
  tmp_0[291] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[3];
  tmp_1[73] = 292;
  tmp_0[292] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[0];
  tmp_0[293] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[1];
  tmp_0[294] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[2];
  tmp_0[295] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[3];
  tmp_1[74] = 296;
  tmp_0[296] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[0];
  tmp_0[297] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[1];
  tmp_0[298] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[2];
  tmp_0[299] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[3];
  tmp_1[75] = 300;
  tmp_0[300] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[0];
  tmp_0[301] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[1];
  tmp_0[302] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[2];
  tmp_0[303] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[3];
  tmp_1[76] = 304;
  tmp_0[304] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[0];
  tmp_0[305] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[1];
  tmp_0[306] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[2];
  tmp_0[307] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[3];
  tmp_1[77] = 308;
  tmp_0[308] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[0];
  tmp_0[309] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[1];
  tmp_0[310] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[2];
  tmp_0[311] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[3];
  tmp_1[78] = 312;
  tmp_0[312] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[0];
  tmp_0[313] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[1];
  tmp_0[314] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[2];
  tmp_0[315] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[3];
  tmp_1[79] = 316;
  tmp_0[316] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[0];
  tmp_0[317] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[1];
  tmp_0[318] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[2];
  tmp_0[319] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[3];
  tmp_1[80] = 320;
  tmp_0[320] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[0];
  tmp_0[321] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[1];
  tmp_0[322] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[2];
  tmp_0[323] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[3];
  tmp_1[81] = 324;
  tmp_0[324] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[0];
  tmp_0[325] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[1];
  tmp_0[326] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[2];
  tmp_0[327] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[3];
  tmp_1[82] = 328;
  tmp_0[328] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[0];
  tmp_0[329] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[1];
  tmp_0[330] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[2];
  tmp_0[331] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[3];
  tmp_1[83] = 332;
  tmp_0[332] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[0];
  tmp_0[333] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[1];
  tmp_0[334] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[2];
  tmp_0[335] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[3];
  tmp_1[84] = 336;
  tmp_0[336] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[0];
  tmp_0[337] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[1];
  tmp_0[338] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[2];
  tmp_0[339] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[3];
  tmp_1[85] = 340;
  tmp_0[340] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[0];
  tmp_0[341] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[1];
  tmp_0[342] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[2];
  tmp_0[343] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[3];
  tmp_1[86] = 344;
  tmp_0[344] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[0];
  tmp_0[345] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[1];
  tmp_0[346] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[2];
  tmp_0[347] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[3];
  tmp_1[87] = 348;
  tmp_0[348] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[0];
  tmp_0[349] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[1];
  tmp_0[350] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[2];
  tmp_0[351] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[3];
  tmp_1[88] = 352;
  tmp_0[352] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[0];
  tmp_0[353] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[1];
  tmp_0[354] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[2];
  tmp_0[355] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[3];
  tmp_1[89] = 356;
  tmp_0[356] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[0];
  tmp_0[357] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[1];
  tmp_0[358] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[2];
  tmp_0[359] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[3];
  tmp_1[90] = 360;
  tmp_0[360] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[0];
  tmp_0[361] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[1];
  tmp_0[362] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[2];
  tmp_0[363] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[3];
  tmp_1[91] = 364;
  tmp_0[364] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[0];
  tmp_0[365] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[1];
  tmp_0[366] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[2];
  tmp_0[367] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[3];
  tmp_1[92] = 368;
  tmp_0[368] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[0];
  tmp_0[369] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[1];
  tmp_0[370] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[2];
  tmp_0[371] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[3];
  tmp_1[93] = 372;
  tmp_0[372] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[0];
  tmp_0[373] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[1];
  tmp_0[374] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[2];
  tmp_0[375] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[3];
  tmp_1[94] = 376;
  tmp_0[376] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[0];
  tmp_0[377] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[1];
  tmp_0[378] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[2];
  tmp_0[379] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[3];
  tmp_1[95] = 380;
  tmp_0[380] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[0];
  tmp_0[381] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[1];
  tmp_0[382] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[2];
  tmp_0[383] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[3];
  tmp_1[96] = 384;
  tmp_0[384] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[0];
  tmp_0[385] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[1];
  tmp_0[386] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[2];
  tmp_0[387] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[3];
  tmp_1[97] = 388;
  tmp_0[388] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[0];
  tmp_0[389] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[1];
  tmp_0[390] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[2];
  tmp_0[391] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[3];
  tmp_1[98] = 392;
  tmp_0[392] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[0];
  tmp_0[393] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[1];
  tmp_0[394] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[2];
  tmp_0[395] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[3];
  tmp_1[99] = 396;
  tmp_0[396] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[0];
  tmp_0[397] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[1];
  tmp_0[398] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[2];
  tmp_0[399] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[3];
  tmp_1[100] = 400;
  tmp_0[400] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[0];
  tmp_0[401] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[1];
  tmp_0[402] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[2];
  tmp_0[403] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[3];
  tmp_1[101] = 404;
  tmp_0[404] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[0];
  tmp_0[405] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[1];
  tmp_0[406] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[2];
  tmp_0[407] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[3];
  tmp_1[102] = 408;
  tmp_0[408] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[0];
  tmp_0[409] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[1];
  tmp_0[410] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[2];
  tmp_0[411] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[3];
  tmp_1[103] = 412;
  tmp_0[412] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[0];
  tmp_0[413] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[1];
  tmp_0[414] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[2];
  tmp_0[415] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[3];
  tmp_1[104] = 416;
  tmp_0[416] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[0];
  tmp_0[417] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[1];
  tmp_0[418] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[2];
  tmp_0[419] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[3];
  tmp_1[105] = 420;
  tmp_0[420] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[0];
  tmp_0[421] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[1];
  tmp_0[422] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[2];
  tmp_0[423] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[3];
  tmp_1[106] = 424;
  tmp_0[424] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[0];
  tmp_0[425] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[1];
  tmp_0[426] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[2];
  tmp_0[427] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[3];
  tmp_1[107] = 428;
  tmp_0[428] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[0];
  tmp_0[429] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[1];
  tmp_0[430] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[2];
  tmp_0[431] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[3];
  tmp_1[108] = 432;
  simulationData->mData->mInputValues.mN = 432;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 109;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method(simulator, NESL_SIM_UPDATE, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
    }
  }

  /* End of Update for SimscapeExecutionBlock: '<S583>/STATE_1' */
  if (rtmIsMajorTimeStep(Copy_of_Robot_leg_3_0_M)) {
    rt_ertODEUpdateContinuousStates(&Copy_of_Robot_leg_3_0_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Copy_of_Robot_leg_3_0_M->Timing.clockTick0)) {
    ++Copy_of_Robot_leg_3_0_M->Timing.clockTickH0;
  }

  Copy_of_Robot_leg_3_0_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Copy_of_Robot_leg_3_0_M->solverInfo);

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
    if (!(++Copy_of_Robot_leg_3_0_M->Timing.clockTick1)) {
      ++Copy_of_Robot_leg_3_0_M->Timing.clockTickH1;
    }

    Copy_of_Robot_leg_3_0_M->Timing.t[1] =
      Copy_of_Robot_leg_3_0_M->Timing.clockTick1 *
      Copy_of_Robot_leg_3_0_M->Timing.stepSize1 +
      Copy_of_Robot_leg_3_0_M->Timing.clockTickH1 *
      Copy_of_Robot_leg_3_0_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Copy_of_Robot_leg_3_0_derivatives(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[432];
  int_T tmp_1[109];
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;
  XDot_Copy_of_Robot_leg_3_0_T *_rtXdot;
  _rtXdot = ((XDot_Copy_of_Robot_leg_3_0_T *) Copy_of_Robot_leg_3_0_M->derivs);

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_3_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotLeft_[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotLeft_[1] = ((Copy_of_Robot_leg_3_0_B.Output
    - Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLeft_[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_2_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_e[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_e[1] = ((Copy_of_Robot_leg_3_0_B.Add4 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_e[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_1_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_f[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_f[1] =
    ((Copy_of_Robot_leg_3_0_B.Output_d -
      Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[0]) * 100.0 - 2.0 *
     Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_f[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_6_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_d[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_d[1] = ((Copy_of_Robot_leg_3_0_B.Add5 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_d[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_4_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_c[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotLef_c[1] =
    ((Copy_of_Robot_leg_3_0_B.Output_o -
      Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[0]) * 100.0 - 2.0 *
     Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLef_c[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_5_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotLe_cb[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotLe_cb[1] = ((Copy_of_Robot_leg_3_0_B.Add6 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotLe_cb[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_28_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotRight[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotRight[1] = ((Copy_of_Robot_leg_3_0_B.Add2 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRight[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_25_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_p[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_p[1] =
    ((Copy_of_Robot_leg_3_0_B.Output_hw -
      Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[0]) * 100.0 - 2.0 *
     Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_p[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_26_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_n[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_n[1] =
    ((Copy_of_Robot_leg_3_0_B.Output_p -
      Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[0]) * 100.0 - 2.0 *
     Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_n[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_24_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_b[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_b[1] = ((Copy_of_Robot_leg_3_0_B.Add1 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_b[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_23_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_j[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_j[1] =
    ((Copy_of_Robot_leg_3_0_B.Output_g -
      Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[0]) * 100.0 - 2.0 *
     Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_j[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S583>/INPUT_27_1_1' */
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_a[0] =
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[1];
  _rtXdot->Copy_of_Robot_leg_3_0RobotRig_a[1] = ((Copy_of_Robot_leg_3_0_B.Add3 -
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[0]) * 100.0 - 2.0 *
    Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0RobotRig_a[1]) * 100.0;

  /* Derivatives for SimscapeExecutionBlock: '<S583>/STATE_1' */
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_SimulationData;
  time = Copy_of_Robot_leg_3_0_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX = (real_T *)
    &Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0x6_DOF_Joi;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Copy_of_Robot_leg_3_0_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Copy_of_Robot_leg_3_0_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[0];
  tmp_0[1] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[1];
  tmp_0[2] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[2];
  tmp_0[3] = Copy_of_Robot_leg_3_0_B.INPUT_3_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[0];
  tmp_0[5] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[1];
  tmp_0[6] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[2];
  tmp_0[7] = Copy_of_Robot_leg_3_0_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[0];
  tmp_0[9] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[1];
  tmp_0[10] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[2];
  tmp_0[11] = Copy_of_Robot_leg_3_0_B.INPUT_1_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[0];
  tmp_0[13] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[1];
  tmp_0[14] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[2];
  tmp_0[15] = Copy_of_Robot_leg_3_0_B.INPUT_6_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[0];
  tmp_0[17] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[1];
  tmp_0[18] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[2];
  tmp_0[19] = Copy_of_Robot_leg_3_0_B.INPUT_4_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[0];
  tmp_0[21] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[1];
  tmp_0[22] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[2];
  tmp_0[23] = Copy_of_Robot_leg_3_0_B.INPUT_5_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[0];
  tmp_0[25] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[1];
  tmp_0[26] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[2];
  tmp_0[27] = Copy_of_Robot_leg_3_0_B.INPUT_28_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[0];
  tmp_0[29] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[1];
  tmp_0[30] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[2];
  tmp_0[31] = Copy_of_Robot_leg_3_0_B.INPUT_25_1_1[3];
  tmp_1[8] = 32;
  tmp_0[32] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[0];
  tmp_0[33] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[1];
  tmp_0[34] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[2];
  tmp_0[35] = Copy_of_Robot_leg_3_0_B.INPUT_26_1_1[3];
  tmp_1[9] = 36;
  tmp_0[36] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[0];
  tmp_0[37] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[1];
  tmp_0[38] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[2];
  tmp_0[39] = Copy_of_Robot_leg_3_0_B.INPUT_24_1_1[3];
  tmp_1[10] = 40;
  tmp_0[40] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[0];
  tmp_0[41] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[1];
  tmp_0[42] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[2];
  tmp_0[43] = Copy_of_Robot_leg_3_0_B.INPUT_23_1_1[3];
  tmp_1[11] = 44;
  tmp_0[44] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[0];
  tmp_0[45] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[1];
  tmp_0[46] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[2];
  tmp_0[47] = Copy_of_Robot_leg_3_0_B.INPUT_27_1_1[3];
  tmp_1[12] = 48;
  tmp_0[48] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[0];
  tmp_0[49] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[1];
  tmp_0[50] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[2];
  tmp_0[51] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_1[3];
  tmp_1[13] = 52;
  tmp_0[52] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[0];
  tmp_0[53] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[1];
  tmp_0[54] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[2];
  tmp_0[55] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_2[3];
  tmp_1[14] = 56;
  tmp_0[56] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[0];
  tmp_0[57] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[1];
  tmp_0[58] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[2];
  tmp_0[59] = Copy_of_Robot_leg_3_0_B.INPUT_10_1_3[3];
  tmp_1[15] = 60;
  tmp_0[60] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[0];
  tmp_0[61] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[1];
  tmp_0[62] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[2];
  tmp_0[63] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_1[3];
  tmp_1[16] = 64;
  tmp_0[64] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[0];
  tmp_0[65] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[1];
  tmp_0[66] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[2];
  tmp_0[67] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_2[3];
  tmp_1[17] = 68;
  tmp_0[68] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[0];
  tmp_0[69] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[1];
  tmp_0[70] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[2];
  tmp_0[71] = Copy_of_Robot_leg_3_0_B.INPUT_9_1_3[3];
  tmp_1[18] = 72;
  tmp_0[72] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[0];
  tmp_0[73] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[1];
  tmp_0[74] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[2];
  tmp_0[75] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_1[3];
  tmp_1[19] = 76;
  tmp_0[76] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[0];
  tmp_0[77] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[1];
  tmp_0[78] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[2];
  tmp_0[79] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_2[3];
  tmp_1[20] = 80;
  tmp_0[80] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[0];
  tmp_0[81] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[1];
  tmp_0[82] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[2];
  tmp_0[83] = Copy_of_Robot_leg_3_0_B.INPUT_7_1_3[3];
  tmp_1[21] = 84;
  tmp_0[84] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[0];
  tmp_0[85] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[1];
  tmp_0[86] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[2];
  tmp_0[87] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_1[3];
  tmp_1[22] = 88;
  tmp_0[88] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[0];
  tmp_0[89] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[1];
  tmp_0[90] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[2];
  tmp_0[91] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_2[3];
  tmp_1[23] = 92;
  tmp_0[92] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[0];
  tmp_0[93] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[1];
  tmp_0[94] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[2];
  tmp_0[95] = Copy_of_Robot_leg_3_0_B.INPUT_8_1_3[3];
  tmp_1[24] = 96;
  tmp_0[96] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[0];
  tmp_0[97] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[1];
  tmp_0[98] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[2];
  tmp_0[99] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_1[3];
  tmp_1[25] = 100;
  tmp_0[100] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[0];
  tmp_0[101] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[1];
  tmp_0[102] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[2];
  tmp_0[103] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_2[3];
  tmp_1[26] = 104;
  tmp_0[104] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[0];
  tmp_0[105] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[1];
  tmp_0[106] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[2];
  tmp_0[107] = Copy_of_Robot_leg_3_0_B.INPUT_14_1_3[3];
  tmp_1[27] = 108;
  tmp_0[108] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[0];
  tmp_0[109] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[1];
  tmp_0[110] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[2];
  tmp_0[111] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_1[3];
  tmp_1[28] = 112;
  tmp_0[112] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[0];
  tmp_0[113] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[1];
  tmp_0[114] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[2];
  tmp_0[115] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_2[3];
  tmp_1[29] = 116;
  tmp_0[116] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[0];
  tmp_0[117] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[1];
  tmp_0[118] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[2];
  tmp_0[119] = Copy_of_Robot_leg_3_0_B.INPUT_13_1_3[3];
  tmp_1[30] = 120;
  tmp_0[120] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[0];
  tmp_0[121] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[1];
  tmp_0[122] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[2];
  tmp_0[123] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_1[3];
  tmp_1[31] = 124;
  tmp_0[124] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[0];
  tmp_0[125] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[1];
  tmp_0[126] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[2];
  tmp_0[127] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_2[3];
  tmp_1[32] = 128;
  tmp_0[128] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[0];
  tmp_0[129] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[1];
  tmp_0[130] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[2];
  tmp_0[131] = Copy_of_Robot_leg_3_0_B.INPUT_11_1_3[3];
  tmp_1[33] = 132;
  tmp_0[132] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[0];
  tmp_0[133] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[1];
  tmp_0[134] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[2];
  tmp_0[135] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_1[3];
  tmp_1[34] = 136;
  tmp_0[136] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[0];
  tmp_0[137] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[1];
  tmp_0[138] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[2];
  tmp_0[139] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_2[3];
  tmp_1[35] = 140;
  tmp_0[140] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[0];
  tmp_0[141] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[1];
  tmp_0[142] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[2];
  tmp_0[143] = Copy_of_Robot_leg_3_0_B.INPUT_12_1_3[3];
  tmp_1[36] = 144;
  tmp_0[144] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[0];
  tmp_0[145] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[1];
  tmp_0[146] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[2];
  tmp_0[147] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_1[3];
  tmp_1[37] = 148;
  tmp_0[148] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[0];
  tmp_0[149] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[1];
  tmp_0[150] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[2];
  tmp_0[151] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_2[3];
  tmp_1[38] = 152;
  tmp_0[152] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[0];
  tmp_0[153] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[1];
  tmp_0[154] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[2];
  tmp_0[155] = Copy_of_Robot_leg_3_0_B.INPUT_18_1_3[3];
  tmp_1[39] = 156;
  tmp_0[156] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[0];
  tmp_0[157] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[1];
  tmp_0[158] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[2];
  tmp_0[159] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_1[3];
  tmp_1[40] = 160;
  tmp_0[160] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[0];
  tmp_0[161] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[1];
  tmp_0[162] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[2];
  tmp_0[163] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_2[3];
  tmp_1[41] = 164;
  tmp_0[164] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[0];
  tmp_0[165] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[1];
  tmp_0[166] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[2];
  tmp_0[167] = Copy_of_Robot_leg_3_0_B.INPUT_17_1_3[3];
  tmp_1[42] = 168;
  tmp_0[168] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[0];
  tmp_0[169] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[1];
  tmp_0[170] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[2];
  tmp_0[171] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_1[3];
  tmp_1[43] = 172;
  tmp_0[172] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[0];
  tmp_0[173] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[1];
  tmp_0[174] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[2];
  tmp_0[175] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_2[3];
  tmp_1[44] = 176;
  tmp_0[176] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[0];
  tmp_0[177] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[1];
  tmp_0[178] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[2];
  tmp_0[179] = Copy_of_Robot_leg_3_0_B.INPUT_15_1_3[3];
  tmp_1[45] = 180;
  tmp_0[180] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[0];
  tmp_0[181] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[1];
  tmp_0[182] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[2];
  tmp_0[183] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_1[3];
  tmp_1[46] = 184;
  tmp_0[184] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[0];
  tmp_0[185] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[1];
  tmp_0[186] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[2];
  tmp_0[187] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_2[3];
  tmp_1[47] = 188;
  tmp_0[188] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[0];
  tmp_0[189] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[1];
  tmp_0[190] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[2];
  tmp_0[191] = Copy_of_Robot_leg_3_0_B.INPUT_16_1_3[3];
  tmp_1[48] = 192;
  tmp_0[192] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[0];
  tmp_0[193] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[1];
  tmp_0[194] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[2];
  tmp_0[195] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_1[3];
  tmp_1[49] = 196;
  tmp_0[196] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[0];
  tmp_0[197] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[1];
  tmp_0[198] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[2];
  tmp_0[199] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_2[3];
  tmp_1[50] = 200;
  tmp_0[200] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[0];
  tmp_0[201] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[1];
  tmp_0[202] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[2];
  tmp_0[203] = Copy_of_Robot_leg_3_0_B.INPUT_22_1_3[3];
  tmp_1[51] = 204;
  tmp_0[204] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[0];
  tmp_0[205] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[1];
  tmp_0[206] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[2];
  tmp_0[207] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_1[3];
  tmp_1[52] = 208;
  tmp_0[208] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[0];
  tmp_0[209] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[1];
  tmp_0[210] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[2];
  tmp_0[211] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_2[3];
  tmp_1[53] = 212;
  tmp_0[212] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[0];
  tmp_0[213] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[1];
  tmp_0[214] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[2];
  tmp_0[215] = Copy_of_Robot_leg_3_0_B.INPUT_21_1_3[3];
  tmp_1[54] = 216;
  tmp_0[216] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[0];
  tmp_0[217] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[1];
  tmp_0[218] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[2];
  tmp_0[219] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_1[3];
  tmp_1[55] = 220;
  tmp_0[220] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[0];
  tmp_0[221] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[1];
  tmp_0[222] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[2];
  tmp_0[223] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_2[3];
  tmp_1[56] = 224;
  tmp_0[224] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[0];
  tmp_0[225] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[1];
  tmp_0[226] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[2];
  tmp_0[227] = Copy_of_Robot_leg_3_0_B.INPUT_19_1_3[3];
  tmp_1[57] = 228;
  tmp_0[228] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[0];
  tmp_0[229] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[1];
  tmp_0[230] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[2];
  tmp_0[231] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_1[3];
  tmp_1[58] = 232;
  tmp_0[232] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[0];
  tmp_0[233] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[1];
  tmp_0[234] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[2];
  tmp_0[235] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_2[3];
  tmp_1[59] = 236;
  tmp_0[236] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[0];
  tmp_0[237] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[1];
  tmp_0[238] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[2];
  tmp_0[239] = Copy_of_Robot_leg_3_0_B.INPUT_20_1_3[3];
  tmp_1[60] = 240;
  tmp_0[240] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[0];
  tmp_0[241] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[1];
  tmp_0[242] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[2];
  tmp_0[243] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_1[3];
  tmp_1[61] = 244;
  tmp_0[244] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[0];
  tmp_0[245] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[1];
  tmp_0[246] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[2];
  tmp_0[247] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_2[3];
  tmp_1[62] = 248;
  tmp_0[248] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[0];
  tmp_0[249] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[1];
  tmp_0[250] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[2];
  tmp_0[251] = Copy_of_Robot_leg_3_0_B.INPUT_32_1_3[3];
  tmp_1[63] = 252;
  tmp_0[252] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[0];
  tmp_0[253] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[1];
  tmp_0[254] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[2];
  tmp_0[255] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_1[3];
  tmp_1[64] = 256;
  tmp_0[256] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[0];
  tmp_0[257] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[1];
  tmp_0[258] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[2];
  tmp_0[259] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_2[3];
  tmp_1[65] = 260;
  tmp_0[260] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[0];
  tmp_0[261] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[1];
  tmp_0[262] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[2];
  tmp_0[263] = Copy_of_Robot_leg_3_0_B.INPUT_31_1_3[3];
  tmp_1[66] = 264;
  tmp_0[264] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[0];
  tmp_0[265] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[1];
  tmp_0[266] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[2];
  tmp_0[267] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_1[3];
  tmp_1[67] = 268;
  tmp_0[268] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[0];
  tmp_0[269] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[1];
  tmp_0[270] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[2];
  tmp_0[271] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_2[3];
  tmp_1[68] = 272;
  tmp_0[272] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[0];
  tmp_0[273] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[1];
  tmp_0[274] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[2];
  tmp_0[275] = Copy_of_Robot_leg_3_0_B.INPUT_29_1_3[3];
  tmp_1[69] = 276;
  tmp_0[276] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[0];
  tmp_0[277] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[1];
  tmp_0[278] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[2];
  tmp_0[279] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_1[3];
  tmp_1[70] = 280;
  tmp_0[280] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[0];
  tmp_0[281] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[1];
  tmp_0[282] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[2];
  tmp_0[283] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_2[3];
  tmp_1[71] = 284;
  tmp_0[284] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[0];
  tmp_0[285] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[1];
  tmp_0[286] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[2];
  tmp_0[287] = Copy_of_Robot_leg_3_0_B.INPUT_30_1_3[3];
  tmp_1[72] = 288;
  tmp_0[288] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[0];
  tmp_0[289] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[1];
  tmp_0[290] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[2];
  tmp_0[291] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_1[3];
  tmp_1[73] = 292;
  tmp_0[292] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[0];
  tmp_0[293] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[1];
  tmp_0[294] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[2];
  tmp_0[295] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_2[3];
  tmp_1[74] = 296;
  tmp_0[296] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[0];
  tmp_0[297] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[1];
  tmp_0[298] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[2];
  tmp_0[299] = Copy_of_Robot_leg_3_0_B.INPUT_36_1_3[3];
  tmp_1[75] = 300;
  tmp_0[300] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[0];
  tmp_0[301] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[1];
  tmp_0[302] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[2];
  tmp_0[303] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_1[3];
  tmp_1[76] = 304;
  tmp_0[304] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[0];
  tmp_0[305] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[1];
  tmp_0[306] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[2];
  tmp_0[307] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_2[3];
  tmp_1[77] = 308;
  tmp_0[308] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[0];
  tmp_0[309] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[1];
  tmp_0[310] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[2];
  tmp_0[311] = Copy_of_Robot_leg_3_0_B.INPUT_35_1_3[3];
  tmp_1[78] = 312;
  tmp_0[312] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[0];
  tmp_0[313] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[1];
  tmp_0[314] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[2];
  tmp_0[315] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_1[3];
  tmp_1[79] = 316;
  tmp_0[316] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[0];
  tmp_0[317] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[1];
  tmp_0[318] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[2];
  tmp_0[319] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_2[3];
  tmp_1[80] = 320;
  tmp_0[320] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[0];
  tmp_0[321] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[1];
  tmp_0[322] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[2];
  tmp_0[323] = Copy_of_Robot_leg_3_0_B.INPUT_33_1_3[3];
  tmp_1[81] = 324;
  tmp_0[324] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[0];
  tmp_0[325] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[1];
  tmp_0[326] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[2];
  tmp_0[327] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_1[3];
  tmp_1[82] = 328;
  tmp_0[328] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[0];
  tmp_0[329] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[1];
  tmp_0[330] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[2];
  tmp_0[331] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_2[3];
  tmp_1[83] = 332;
  tmp_0[332] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[0];
  tmp_0[333] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[1];
  tmp_0[334] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[2];
  tmp_0[335] = Copy_of_Robot_leg_3_0_B.INPUT_34_1_3[3];
  tmp_1[84] = 336;
  tmp_0[336] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[0];
  tmp_0[337] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[1];
  tmp_0[338] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[2];
  tmp_0[339] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_1[3];
  tmp_1[85] = 340;
  tmp_0[340] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[0];
  tmp_0[341] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[1];
  tmp_0[342] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[2];
  tmp_0[343] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_2[3];
  tmp_1[86] = 344;
  tmp_0[344] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[0];
  tmp_0[345] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[1];
  tmp_0[346] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[2];
  tmp_0[347] = Copy_of_Robot_leg_3_0_B.INPUT_40_1_3[3];
  tmp_1[87] = 348;
  tmp_0[348] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[0];
  tmp_0[349] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[1];
  tmp_0[350] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[2];
  tmp_0[351] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_1[3];
  tmp_1[88] = 352;
  tmp_0[352] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[0];
  tmp_0[353] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[1];
  tmp_0[354] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[2];
  tmp_0[355] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_2[3];
  tmp_1[89] = 356;
  tmp_0[356] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[0];
  tmp_0[357] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[1];
  tmp_0[358] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[2];
  tmp_0[359] = Copy_of_Robot_leg_3_0_B.INPUT_39_1_3[3];
  tmp_1[90] = 360;
  tmp_0[360] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[0];
  tmp_0[361] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[1];
  tmp_0[362] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[2];
  tmp_0[363] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_1[3];
  tmp_1[91] = 364;
  tmp_0[364] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[0];
  tmp_0[365] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[1];
  tmp_0[366] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[2];
  tmp_0[367] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_2[3];
  tmp_1[92] = 368;
  tmp_0[368] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[0];
  tmp_0[369] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[1];
  tmp_0[370] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[2];
  tmp_0[371] = Copy_of_Robot_leg_3_0_B.INPUT_37_1_3[3];
  tmp_1[93] = 372;
  tmp_0[372] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[0];
  tmp_0[373] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[1];
  tmp_0[374] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[2];
  tmp_0[375] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_1[3];
  tmp_1[94] = 376;
  tmp_0[376] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[0];
  tmp_0[377] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[1];
  tmp_0[378] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[2];
  tmp_0[379] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_2[3];
  tmp_1[95] = 380;
  tmp_0[380] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[0];
  tmp_0[381] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[1];
  tmp_0[382] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[2];
  tmp_0[383] = Copy_of_Robot_leg_3_0_B.INPUT_38_1_3[3];
  tmp_1[96] = 384;
  tmp_0[384] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[0];
  tmp_0[385] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[1];
  tmp_0[386] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[2];
  tmp_0[387] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_1[3];
  tmp_1[97] = 388;
  tmp_0[388] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[0];
  tmp_0[389] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[1];
  tmp_0[390] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[2];
  tmp_0[391] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_2[3];
  tmp_1[98] = 392;
  tmp_0[392] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[0];
  tmp_0[393] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[1];
  tmp_0[394] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[2];
  tmp_0[395] = Copy_of_Robot_leg_3_0_B.INPUT_44_1_3[3];
  tmp_1[99] = 396;
  tmp_0[396] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[0];
  tmp_0[397] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[1];
  tmp_0[398] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[2];
  tmp_0[399] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_1[3];
  tmp_1[100] = 400;
  tmp_0[400] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[0];
  tmp_0[401] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[1];
  tmp_0[402] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[2];
  tmp_0[403] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_2[3];
  tmp_1[101] = 404;
  tmp_0[404] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[0];
  tmp_0[405] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[1];
  tmp_0[406] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[2];
  tmp_0[407] = Copy_of_Robot_leg_3_0_B.INPUT_43_1_3[3];
  tmp_1[102] = 408;
  tmp_0[408] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[0];
  tmp_0[409] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[1];
  tmp_0[410] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[2];
  tmp_0[411] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_1[3];
  tmp_1[103] = 412;
  tmp_0[412] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[0];
  tmp_0[413] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[1];
  tmp_0[414] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[2];
  tmp_0[415] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_2[3];
  tmp_1[104] = 416;
  tmp_0[416] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[0];
  tmp_0[417] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[1];
  tmp_0[418] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[2];
  tmp_0[419] = Copy_of_Robot_leg_3_0_B.INPUT_41_1_3[3];
  tmp_1[105] = 420;
  tmp_0[420] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[0];
  tmp_0[421] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[1];
  tmp_0[422] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[2];
  tmp_0[423] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_1[3];
  tmp_1[106] = 424;
  tmp_0[424] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[0];
  tmp_0[425] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[1];
  tmp_0[426] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[2];
  tmp_0[427] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_2[3];
  tmp_1[107] = 428;
  tmp_0[428] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[0];
  tmp_0[429] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[1];
  tmp_0[430] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[2];
  tmp_0[431] = Copy_of_Robot_leg_3_0_B.INPUT_42_1_3[3];
  tmp_1[108] = 432;
  simulationData->mData->mInputValues.mN = 432;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 109;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 13;
  simulationData->mData->mDx.mX = (real_T *)
    &_rtXdot->Copy_of_Robot_leg_3_0x6_DOF_Joi;
  simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method(simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S583>/STATE_1' */
}

/* Model initialize function */
void Copy_of_Robot_leg_3_0_initialize(void)
{
  {
    boolean_T tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeModelParameters modelParameters;
    real_T tmp_0;
    NeslSimulator *simulator;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    int_T parameterBundle_mLogicalParamet;
    NeslSimulationData *simulationData;
    real_T time;
    NeModelParameters modelParameters_0;
    real_T time_0;
    NeModelParameters modelParameters_1;
    real_T time_1;
    NeParameterBundle expl_temp;

    /* Start for TransportDelay: '<S4>/Transport Delay' */
    {
      real_T *pBuffer =
        &Copy_of_Robot_leg_3_0_DW.TransportDelay_RWORK.TUbufferArea[0];

      {
        int_T i1;
        int_T *iw_Tail = &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Tail[0];
        int_T *iw_Head = &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Head[0];
        int_T *iw_Last = &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.Last[0];
        int_T *iw_CircularBufSize =
          &Copy_of_Robot_leg_3_0_DW.TransportDelay_IWORK.CircularBufSize[0];
        void **pw_TUbufferPtrs =
          &Copy_of_Robot_leg_3_0_DW.TransportDelay_PWORK.TUbufferPtrs[0];
        for (i1=0; i1 < 3; i1++) {
          iw_Tail[i1] = 0;
          iw_Head[i1] = 0;
          iw_Last[i1] = 0;
          iw_CircularBufSize[i1] = 1024;
          pBuffer[0] = Copy_of_Robot_leg_3_0_P.TransportDelay_InitOutput;
          pBuffer[1024] = Copy_of_Robot_leg_3_0_M->Timing.t[0];
          pw_TUbufferPtrs[i1] = (void *) &pBuffer[0];
          pw_TUbufferPtrs[i1+3] = (void *) &pBuffer[1024];
          pBuffer += 2048;
        }
      }
    }

    /* Start for SwitchCase: '<S4>/Switch Case' */
    Copy_of_Robot_leg_3_0_DW.SwitchCase_ActiveSubsystem = -1;

    /* Start for SimscapeExecutionBlock: '<S583>/STATE_1' */
    simulator = nesl_lease_simulator(
      "Copy_of_Robot_leg_3_0/Solver Configuration_1", 0, 0);
    Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator = (void *)simulator;
    tmp = pointer_is_null(Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator);
    if (tmp) {
      Copy_of_Robot_leg_3_0_7d8ca6e_1_gateway();
      simulator = nesl_lease_simulator(
        "Copy_of_Robot_leg_3_0/Solver Configuration_1", 0, 0);
      Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator = (void *)simulator;
    }

    simulationData = nesl_create_simulation_data();
    Copy_of_Robot_leg_3_0_DW.STATE_1_SimulationData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager = (void *)
      diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters.mRTWModifiedTimeStamp = 4.72727709E+8;
    tmp_0 = 0.001;
    modelParameters.mSolverTolerance = tmp_0;
    tmp_0 = 0.001;
    modelParameters.mFixedStepSize = tmp_0;
    tmp = false;
    modelParameters.mVariableStepSolver = tmp;
    simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    parameterBundle_mLogicalParamet = nesl_initialize_simulator(simulator,
      &modelParameters, diagnosticManager);
    if (parameterBundle_mLogicalParamet != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
      }
    }

    simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator;
    expl_temp.mRealParameters.mN = 0;
    expl_temp.mRealParameters.mX = NULL;
    expl_temp.mLogicalParameters.mN = 0;
    expl_temp.mLogicalParameters.mX = NULL;
    expl_temp.mIntegerParameters.mN = 0;
    expl_temp.mIntegerParameters.mX = NULL;
    expl_temp.mIndexParameters.mN = 0;
    expl_temp.mIndexParameters.mX = NULL;
    nesl_simulator_set_rtps(simulator, expl_temp);
    simulationData = (NeslSimulationData *)
      Copy_of_Robot_leg_3_0_DW.STATE_1_SimulationData;
    time = Copy_of_Robot_leg_3_0_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 13;
    simulationData->mData->mContStates.mX = (real_T *)
      &Copy_of_Robot_leg_3_0_X.Copy_of_Robot_leg_3_0x6_DOF_Joi;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = NULL;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = NULL;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (Copy_of_Robot_leg_3_0_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&Copy_of_Robot_leg_3_0_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.STATE_1_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    parameterBundle_mLogicalParamet = ne_simulator_method(simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (parameterBundle_mLogicalParamet != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S583>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S583>/OUTPUT_1_0' */
    simulator = nesl_lease_simulator(
      "Copy_of_Robot_leg_3_0/Solver Configuration_1", 2, 0);
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_Simulator = (void *)simulator;
    tmp = pointer_is_null(Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_Simulator);
    if (tmp) {
      Copy_of_Robot_leg_3_0_7d8ca6e_1_gateway();
      simulator = nesl_lease_simulator(
        "Copy_of_Robot_leg_3_0/Solver Configuration_1", 2, 0);
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_Simulator = (void *)simulator;
    }

    simulationData = nesl_create_simulation_data();
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_SimulationData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_DiagnosticManager = (void *)
      diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_0.mRTWModifiedTimeStamp = 4.72727709E+8;
    tmp_0 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_0;
    tmp_0 = 0.001;
    modelParameters_0.mFixedStepSize = tmp_0;
    tmp = false;
    modelParameters_0.mVariableStepSolver = tmp;
    simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    parameterBundle_mLogicalParamet = nesl_initialize_simulator(simulator,
      &modelParameters_0, diagnosticManager);
    if (parameterBundle_mLogicalParamet != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
      }
    }

    simulationData = (NeslSimulationData *)
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_SimulationData;
    time_0 = Copy_of_Robot_leg_3_0_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = NULL;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = NULL;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (Copy_of_Robot_leg_3_0_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    parameterBundle_mLogicalParamet = ne_simulator_method(simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (parameterBundle_mLogicalParamet != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S583>/OUTPUT_1_0' */
    /* Start for If: '<S322>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem = -1;

    /* Start for If: '<S323>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_j = -1;

    /* Start for If: '<S324>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_jw = -1;

    /* Start for If: '<S325>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_m = -1;

    /* Start for If: '<S58>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_p = -1;

    /* Start for If: '<S59>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_i = -1;

    /* Start for If: '<S60>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_o = -1;

    /* Start for If: '<S61>/If1' */
    Copy_of_Robot_leg_3_0_DW.If1_ActiveSubsystem_e = -1;

    /* Start for SimscapeExecutionBlock: '<S583>/OUTPUT_1_1' */
    simulator = nesl_lease_simulator(
      "Copy_of_Robot_leg_3_0/Solver Configuration_1", 2, 1);
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_Simulator = (void *)simulator;
    tmp = pointer_is_null(Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_Simulator);
    if (tmp) {
      Copy_of_Robot_leg_3_0_7d8ca6e_1_gateway();
      simulator = nesl_lease_simulator(
        "Copy_of_Robot_leg_3_0/Solver Configuration_1", 2, 1);
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_Simulator = (void *)simulator;
    }

    simulationData = nesl_create_simulation_data();
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_SimulationData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_DiagnosticManager = (void *)
      diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverTolerance = 0.001;
    modelParameters_1.mVariableStepSolver = false;
    modelParameters_1.mFixedStepSize = 0.001;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_1.mRTWModifiedTimeStamp = 4.72727709E+8;
    tmp_0 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_0;
    tmp_0 = 0.001;
    modelParameters_1.mFixedStepSize = tmp_0;
    tmp = false;
    modelParameters_1.mVariableStepSolver = tmp;
    simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    parameterBundle_mLogicalParamet = nesl_initialize_simulator(simulator,
      &modelParameters_1, diagnosticManager);
    if (parameterBundle_mLogicalParamet != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
      }
    }

    simulationData = (NeslSimulationData *)
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_SimulationData;
    time_1 = Copy_of_Robot_leg_3_0_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = NULL;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = NULL;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (Copy_of_Robot_leg_3_0_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulator = (NeslSimulator *)Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    parameterBundle_mLogicalParamet = ne_simulator_method(simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (parameterBundle_mLogicalParamet != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S583>/OUTPUT_1_1' */
    /* Start for S-Function (slrtIPConfig): '<S4>/UDP Configure' */
    /* Level2 S-Function Block: '<S4>/UDP Configure' (slrtIPConfig) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (scblock): '<S26>/S-Function' */

    /* S-Function Block: <S26>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(3)) == 0) {
        if ((i = rl32eDefScope(3,2)) != 0) {
          printf("Error creating scope 3\n");
        } else {
          rl32eAddSignal(3, rl32eGetSignalNo("Robot/Transport Delay/s1"));
          rl32eAddSignal(3, rl32eGetSignalNo("Robot/Transport Delay/s2"));
          rl32eAddSignal(3, rl32eGetSignalNo("Robot/Transport Delay/s3"));
          rl32eSetScope(3, 4, 250);
          rl32eSetScope(3, 5, 0);
          rl32eSetScope(3, 6, 1);
          rl32eSetScope(3, 0, 0);
          rl32eSetScope(3, 3, rl32eGetSignalNo("Robot/Transport Delay/s1"));
          rl32eSetScope(3, 1, 0.0);
          rl32eSetScope(3, 2, 0);
          rl32eSetScope(3, 9, 0);
          rl32eSetTargetScope(3, 11, 0.0);
          rl32eSetTargetScope(3, 10, 0.0);
          xpceScopeAcqOK(3, &Copy_of_Robot_leg_3_0_DW.SFunction_IWORK.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(3);
      }
    }

    /* Start for S-Function (asciiencode): '<S4>/ASCII Encode 2' */
    /* Level2 S-Function Block: '<S4>/ASCII Encode 2' (asciiencode) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[1];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S4>/Constant3' */
    Copy_of_Robot_leg_3_0_B.Constant3 = Copy_of_Robot_leg_3_0_P.Constant3_Value;

    /* Start for S-Function (slrtUDPSend): '<S4>/UDP Send' */
    /* Level2 S-Function Block: '<S4>/UDP Send' (slrtUDPSend) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[2];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  {
    boolean_T tmp;
    char *tmp_0;
    int32_T i;

    /* InitializeConditions for SimscapeExecutionBlock: '<S583>/STATE_1' */
    tmp = false;
    if (tmp) {
      i = strcmp("ode3", rtsiGetSolverName(&Copy_of_Robot_leg_3_0_M->solverInfo));
      if (i != 0) {
        tmp_0 = solver_mismatch_message("ode3", rtsiGetSolverName
          (&Copy_of_Robot_leg_3_0_M->solverInfo));
        rtmSetErrorStatus(Copy_of_Robot_leg_3_0_M, tmp_0);
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S583>/STATE_1' */

    /* SystemInitialize for IfAction SubSystem: '<S4>/Switch Case Action Subsystem' */
    SwitchCaseActionSubsystem_Init
      (&Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem,
       &Copy_of_Robot_leg_3_0_P.SwitchCaseActionSubsystem);

    /* End of SystemInitialize for SubSystem: '<S4>/Switch Case Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<S4>/Switch Case Action Subsystem1' */
    SwitchCaseActionSubsystem_Init
      (&Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1,
       &Copy_of_Robot_leg_3_0_P.SwitchCaseActionSubsystem1);

    /* End of SystemInitialize for SubSystem: '<S4>/Switch Case Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S322>/Forces' */
    /* SystemInitialize for Outport: '<S382>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone_e = Copy_of_Robot_leg_3_0_P.Out_Y0_n;
    Copy_of_Robot_leg_3_0_B.Gain2_k = Copy_of_Robot_leg_3_0_P.Out_Y0_n;
    Copy_of_Robot_leg_3_0_B.SprForce_p = Copy_of_Robot_leg_3_0_P.Out_Y0_n;
    Copy_of_Robot_leg_3_0_B.DampForce_h = Copy_of_Robot_leg_3_0_P.Out_Y0_n;
    Copy_of_Robot_leg_3_0_B.Sum_kge = Copy_of_Robot_leg_3_0_P.Out_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S322>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S323>/Forces' */
    /* SystemInitialize for Outport: '<S430>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone_a = Copy_of_Robot_leg_3_0_P.Out_Y0_f;
    Copy_of_Robot_leg_3_0_B.Gain2_m = Copy_of_Robot_leg_3_0_P.Out_Y0_f;
    Copy_of_Robot_leg_3_0_B.SprForce_n = Copy_of_Robot_leg_3_0_P.Out_Y0_f;
    Copy_of_Robot_leg_3_0_B.DampForce_c = Copy_of_Robot_leg_3_0_P.Out_Y0_f;
    Copy_of_Robot_leg_3_0_B.Sum_o3 = Copy_of_Robot_leg_3_0_P.Out_Y0_f;

    /* End of SystemInitialize for SubSystem: '<S323>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S324>/Forces' */
    /* SystemInitialize for Outport: '<S478>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone_b = Copy_of_Robot_leg_3_0_P.Out_Y0_e;
    Copy_of_Robot_leg_3_0_B.Gain2_g = Copy_of_Robot_leg_3_0_P.Out_Y0_e;
    Copy_of_Robot_leg_3_0_B.SprForce_j = Copy_of_Robot_leg_3_0_P.Out_Y0_e;
    Copy_of_Robot_leg_3_0_B.DampForce_j = Copy_of_Robot_leg_3_0_P.Out_Y0_e;
    Copy_of_Robot_leg_3_0_B.Sum_kg = Copy_of_Robot_leg_3_0_P.Out_Y0_e;

    /* End of SystemInitialize for SubSystem: '<S324>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S325>/Forces' */
    /* SystemInitialize for Outport: '<S526>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;
    Copy_of_Robot_leg_3_0_B.Gain2_i = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;
    Copy_of_Robot_leg_3_0_B.SprForce = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;
    Copy_of_Robot_leg_3_0_B.DampForce = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;
    Copy_of_Robot_leg_3_0_B.Sum_kn = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;

    /* End of SystemInitialize for SubSystem: '<S325>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S58>/Forces' */
    /* SystemInitialize for Outport: '<S118>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone_ko = Copy_of_Robot_leg_3_0_P.Out_Y0;
    Copy_of_Robot_leg_3_0_B.Gain2_l = Copy_of_Robot_leg_3_0_P.Out_Y0;
    Copy_of_Robot_leg_3_0_B.SprForce_ny = Copy_of_Robot_leg_3_0_P.Out_Y0;
    Copy_of_Robot_leg_3_0_B.DampForce_b = Copy_of_Robot_leg_3_0_P.Out_Y0;
    Copy_of_Robot_leg_3_0_B.Sum_bz = Copy_of_Robot_leg_3_0_P.Out_Y0;

    /* End of SystemInitialize for SubSystem: '<S58>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S322>/Forces' */
    /* SystemInitialize for Outport: '<S382>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_jd[0] = Copy_of_Robot_leg_3_0_P.Out_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S322>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S323>/Forces' */
    /* SystemInitialize for Outport: '<S430>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_ph[0] = Copy_of_Robot_leg_3_0_P.Out_Y0_f;

    /* End of SystemInitialize for SubSystem: '<S323>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S324>/Forces' */
    /* SystemInitialize for Outport: '<S478>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_cp[0] = Copy_of_Robot_leg_3_0_P.Out_Y0_e;

    /* End of SystemInitialize for SubSystem: '<S324>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S325>/Forces' */
    /* SystemInitialize for Outport: '<S526>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_b5[0] = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;

    /* End of SystemInitialize for SubSystem: '<S325>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S58>/Forces' */
    /* SystemInitialize for Outport: '<S118>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_hg[0] = Copy_of_Robot_leg_3_0_P.Out_Y0;

    /* End of SystemInitialize for SubSystem: '<S58>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S322>/Forces' */
    /* SystemInitialize for Outport: '<S382>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_jd[1] = Copy_of_Robot_leg_3_0_P.Out_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S322>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S323>/Forces' */
    /* SystemInitialize for Outport: '<S430>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_ph[1] = Copy_of_Robot_leg_3_0_P.Out_Y0_f;

    /* End of SystemInitialize for SubSystem: '<S323>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S324>/Forces' */
    /* SystemInitialize for Outport: '<S478>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_cp[1] = Copy_of_Robot_leg_3_0_P.Out_Y0_e;

    /* End of SystemInitialize for SubSystem: '<S324>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S325>/Forces' */
    /* SystemInitialize for Outport: '<S526>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_b5[1] = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;

    /* End of SystemInitialize for SubSystem: '<S325>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S58>/Forces' */
    /* SystemInitialize for Outport: '<S118>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_hg[1] = Copy_of_Robot_leg_3_0_P.Out_Y0;

    /* End of SystemInitialize for SubSystem: '<S58>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S322>/Forces' */
    /* SystemInitialize for Outport: '<S382>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_jd[2] = Copy_of_Robot_leg_3_0_P.Out_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S322>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S323>/Forces' */
    /* SystemInitialize for Outport: '<S430>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_ph[2] = Copy_of_Robot_leg_3_0_P.Out_Y0_f;

    /* End of SystemInitialize for SubSystem: '<S323>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S324>/Forces' */
    /* SystemInitialize for Outport: '<S478>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_cp[2] = Copy_of_Robot_leg_3_0_P.Out_Y0_e;

    /* End of SystemInitialize for SubSystem: '<S324>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S325>/Forces' */
    /* SystemInitialize for Outport: '<S526>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_b5[2] = Copy_of_Robot_leg_3_0_P.Out_Y0_d3;

    /* End of SystemInitialize for SubSystem: '<S325>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S58>/Forces' */
    /* SystemInitialize for Outport: '<S118>/Out' */
    Copy_of_Robot_leg_3_0_B.Gain_hg[2] = Copy_of_Robot_leg_3_0_P.Out_Y0;

    /* End of SystemInitialize for SubSystem: '<S58>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S59>/Forces' */
    /* SystemInitialize for Outport: '<S166>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone_l = Copy_of_Robot_leg_3_0_P.Out_Y0_p;
    Copy_of_Robot_leg_3_0_B.Gain2_fs = Copy_of_Robot_leg_3_0_P.Out_Y0_p;
    Copy_of_Robot_leg_3_0_B.SprForce_a = Copy_of_Robot_leg_3_0_P.Out_Y0_p;
    Copy_of_Robot_leg_3_0_B.DampForce_hs = Copy_of_Robot_leg_3_0_P.Out_Y0_p;
    Copy_of_Robot_leg_3_0_B.Sum_aw = Copy_of_Robot_leg_3_0_P.Out_Y0_p;
    Copy_of_Robot_leg_3_0_B.Gain_d1[0] = Copy_of_Robot_leg_3_0_P.Out_Y0_p;
    Copy_of_Robot_leg_3_0_B.Gain_d1[1] = Copy_of_Robot_leg_3_0_P.Out_Y0_p;
    Copy_of_Robot_leg_3_0_B.Gain_d1[2] = Copy_of_Robot_leg_3_0_P.Out_Y0_p;

    /* End of SystemInitialize for SubSystem: '<S59>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S60>/Forces' */
    /* SystemInitialize for Outport: '<S214>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone_k = Copy_of_Robot_leg_3_0_P.Out_Y0_d;
    Copy_of_Robot_leg_3_0_B.Gain2_b = Copy_of_Robot_leg_3_0_P.Out_Y0_d;
    Copy_of_Robot_leg_3_0_B.SprForce_e = Copy_of_Robot_leg_3_0_P.Out_Y0_d;
    Copy_of_Robot_leg_3_0_B.DampForce_f = Copy_of_Robot_leg_3_0_P.Out_Y0_d;
    Copy_of_Robot_leg_3_0_B.Sum_iz = Copy_of_Robot_leg_3_0_P.Out_Y0_d;
    Copy_of_Robot_leg_3_0_B.Gain_ib[0] = Copy_of_Robot_leg_3_0_P.Out_Y0_d;
    Copy_of_Robot_leg_3_0_B.Gain_ib[1] = Copy_of_Robot_leg_3_0_P.Out_Y0_d;
    Copy_of_Robot_leg_3_0_B.Gain_ib[2] = Copy_of_Robot_leg_3_0_P.Out_Y0_d;

    /* End of SystemInitialize for SubSystem: '<S60>/Forces' */

    /* SystemInitialize for IfAction SubSystem: '<S61>/Forces' */
    /* SystemInitialize for Outport: '<S262>/Out' */
    Copy_of_Robot_leg_3_0_B.DeadZone_ap = Copy_of_Robot_leg_3_0_P.Out_Y0_m;
    Copy_of_Robot_leg_3_0_B.Gain2_e = Copy_of_Robot_leg_3_0_P.Out_Y0_m;
    Copy_of_Robot_leg_3_0_B.SprForce_m = Copy_of_Robot_leg_3_0_P.Out_Y0_m;
    Copy_of_Robot_leg_3_0_B.DampForce_n = Copy_of_Robot_leg_3_0_P.Out_Y0_m;
    Copy_of_Robot_leg_3_0_B.Sum_jg = Copy_of_Robot_leg_3_0_P.Out_Y0_m;
    Copy_of_Robot_leg_3_0_B.Gain_eu[0] = Copy_of_Robot_leg_3_0_P.Out_Y0_m;
    Copy_of_Robot_leg_3_0_B.Gain_eu[1] = Copy_of_Robot_leg_3_0_P.Out_Y0_m;
    Copy_of_Robot_leg_3_0_B.Gain_eu[2] = Copy_of_Robot_leg_3_0_P.Out_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S61>/Forces' */
    for (i = 0; i < 12; i++) {
      /* SystemInitialize for Merge: '<S58>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput;

      /* SystemInitialize for Merge: '<S59>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph_m[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_n;

      /* SystemInitialize for Merge: '<S60>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph_l[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_d;

      /* SystemInitialize for Merge: '<S61>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph_a[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_nd;

      /* SystemInitialize for Merge: '<S322>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph_i[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_k;

      /* SystemInitialize for Merge: '<S323>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph_mf[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_o;

      /* SystemInitialize for Merge: '<S324>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph_a0[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_m;

      /* SystemInitialize for Merge: '<S325>/Merge' */
      Copy_of_Robot_leg_3_0_B.FSph_n[i] =
        Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_e;
    }
  }
}

/* Model terminate function */
void Copy_of_Robot_leg_3_0_terminate(void)
{
  NeuDiagnosticManager *diagnosticManager;
  NeslSimulationData *simulationData;

  /* Terminate for SimscapeExecutionBlock: '<S583>/STATE_1' */
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_DiagnosticManager;
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.STATE_1_SimulationData;
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("Copy_of_Robot_leg_3_0/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S583>/OUTPUT_1_0' */
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_DiagnosticManager;
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_0_SimulationData;
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("Copy_of_Robot_leg_3_0/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S583>/OUTPUT_1_1' */
  diagnosticManager = (NeuDiagnosticManager *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_DiagnosticManager;
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = (NeslSimulationData *)
    Copy_of_Robot_leg_3_0_DW.OUTPUT_1_1_SimulationData;
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("Copy_of_Robot_leg_3_0/Solver Configuration_1");

  /* Terminate for S-Function (slrtIPConfig): '<S4>/UDP Configure' */
  /* Level2 S-Function Block: '<S4>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (asciiencode): '<S4>/ASCII Encode 2' */
  /* Level2 S-Function Block: '<S4>/ASCII Encode 2' (asciiencode) */
  {
    SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (slrtUDPSend): '<S4>/UDP Send' */
  /* Level2 S-Function Block: '<S4>/UDP Send' (slrtUDPSend) */
  {
    SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Copy_of_Robot_leg_3_0_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Copy_of_Robot_leg_3_0_update();
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
  Copy_of_Robot_leg_3_0_initialize();
}

void MdlTerminate(void)
{
  Copy_of_Robot_leg_3_0_terminate();
}

/* Registration function */
RT_MODEL_Copy_of_Robot_leg_3_0_T *Copy_of_Robot_leg_3_0(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Copy_of_Robot_leg_3_0_P.DeadZone_Start = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat = rtInf;
  Copy_of_Robot_leg_3_0_P.DeadZone_Start_b = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_l = rtInf;
  Copy_of_Robot_leg_3_0_P.DeadZone_Start_p = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_b = rtInf;
  Copy_of_Robot_leg_3_0_P.DeadZone_Start_a = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_d = rtInf;
  Copy_of_Robot_leg_3_0_P.DeadZone_Start_n = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_p = rtInf;
  Copy_of_Robot_leg_3_0_P.DeadZone_Start_i = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_o = rtInf;
  Copy_of_Robot_leg_3_0_P.DeadZone_Start_n5 = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_e = rtInf;
  Copy_of_Robot_leg_3_0_P.DeadZone_Start_o = rtMinusInf;
  Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_f = rtInf;

  /* initialize real-time model */
  (void) memset((void *)Copy_of_Robot_leg_3_0_M, 0,
                sizeof(RT_MODEL_Copy_of_Robot_leg_3_0_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
                          &Copy_of_Robot_leg_3_0_M->Timing.simTimeStep);
    rtsiSetTPtr(&Copy_of_Robot_leg_3_0_M->solverInfo, &rtmGetTPtr
                (Copy_of_Robot_leg_3_0_M));
    rtsiSetStepSizePtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
                       &Copy_of_Robot_leg_3_0_M->Timing.stepSize0);
    rtsiSetdXPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
                 &Copy_of_Robot_leg_3_0_M->derivs);
    rtsiSetContStatesPtr(&Copy_of_Robot_leg_3_0_M->solverInfo, (real_T **)
                         &Copy_of_Robot_leg_3_0_M->contStates);
    rtsiSetNumContStatesPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
      &Copy_of_Robot_leg_3_0_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
      &Copy_of_Robot_leg_3_0_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
      &Copy_of_Robot_leg_3_0_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
      &Copy_of_Robot_leg_3_0_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
                          (&rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M)));
    rtsiSetRTModelPtr(&Copy_of_Robot_leg_3_0_M->solverInfo,
                      Copy_of_Robot_leg_3_0_M);
  }

  rtsiSetSimTimeStep(&Copy_of_Robot_leg_3_0_M->solverInfo, MAJOR_TIME_STEP);
  Copy_of_Robot_leg_3_0_M->intgData.y = Copy_of_Robot_leg_3_0_M->odeY;
  Copy_of_Robot_leg_3_0_M->intgData.f[0] = Copy_of_Robot_leg_3_0_M->odeF[0];
  Copy_of_Robot_leg_3_0_M->intgData.f[1] = Copy_of_Robot_leg_3_0_M->odeF[1];
  Copy_of_Robot_leg_3_0_M->intgData.f[2] = Copy_of_Robot_leg_3_0_M->odeF[2];
  Copy_of_Robot_leg_3_0_M->contStates = ((real_T *) &Copy_of_Robot_leg_3_0_X);
  rtsiSetSolverData(&Copy_of_Robot_leg_3_0_M->solverInfo, (void *)
                    &Copy_of_Robot_leg_3_0_M->intgData);
  rtsiSetSolverName(&Copy_of_Robot_leg_3_0_M->solverInfo,"ode3");
  Copy_of_Robot_leg_3_0_M->solverInfoPtr = (&Copy_of_Robot_leg_3_0_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Copy_of_Robot_leg_3_0_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Copy_of_Robot_leg_3_0_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Copy_of_Robot_leg_3_0_M->Timing.sampleTimes =
      (&Copy_of_Robot_leg_3_0_M->Timing.sampleTimesArray[0]);
    Copy_of_Robot_leg_3_0_M->Timing.offsetTimes =
      (&Copy_of_Robot_leg_3_0_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Copy_of_Robot_leg_3_0_M->Timing.sampleTimes[0] = (0.0);
    Copy_of_Robot_leg_3_0_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Copy_of_Robot_leg_3_0_M->Timing.offsetTimes[0] = (0.0);
    Copy_of_Robot_leg_3_0_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Copy_of_Robot_leg_3_0_M, &Copy_of_Robot_leg_3_0_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Copy_of_Robot_leg_3_0_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Copy_of_Robot_leg_3_0_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Copy_of_Robot_leg_3_0_M, -1);
  Copy_of_Robot_leg_3_0_M->Timing.stepSize0 = 0.001;
  Copy_of_Robot_leg_3_0_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Copy_of_Robot_leg_3_0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Copy_of_Robot_leg_3_0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Copy_of_Robot_leg_3_0_M->rtwLogInfo, (NULL));
    rtliSetLogT(Copy_of_Robot_leg_3_0_M->rtwLogInfo, "tout");
    rtliSetLogX(Copy_of_Robot_leg_3_0_M->rtwLogInfo, "");
    rtliSetLogXFinal(Copy_of_Robot_leg_3_0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Copy_of_Robot_leg_3_0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Copy_of_Robot_leg_3_0_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(Copy_of_Robot_leg_3_0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Copy_of_Robot_leg_3_0_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Copy_of_Robot_leg_3_0_Y.w,
        &Copy_of_Robot_leg_3_0_Y.x,
        &Copy_of_Robot_leg_3_0_Y.z,
        &Copy_of_Robot_leg_3_0_Y.measR[0],
        &Copy_of_Robot_leg_3_0_Y.measL[0]
      };

      rtliSetLogYSignalPtrs(Copy_of_Robot_leg_3_0_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        14,
        14
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        14,
        14
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "angular velocity [rad/s]",
        "x distance [m]",
        "torso height [cm]",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Copy_of_Robot_leg_3_0/w",
        "Copy_of_Robot_leg_3_0/x",
        "Copy_of_Robot_leg_3_0/z",
        "Copy_of_Robot_leg_3_0/measR",
        "Copy_of_Robot_leg_3_0/measL" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          5,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Copy_of_Robot_leg_3_0_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
    }

    rtliSetLogY(Copy_of_Robot_leg_3_0_M->rtwLogInfo, "yout");
  }

  Copy_of_Robot_leg_3_0_M->solverInfoPtr = (&Copy_of_Robot_leg_3_0_M->solverInfo);
  Copy_of_Robot_leg_3_0_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Copy_of_Robot_leg_3_0_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Copy_of_Robot_leg_3_0_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Copy_of_Robot_leg_3_0_M->blockIO = ((void *) &Copy_of_Robot_leg_3_0_B);
  (void) memset(((void *) &Copy_of_Robot_leg_3_0_B), 0,
                sizeof(B_Copy_of_Robot_leg_3_0_T));

  /* parameters */
  Copy_of_Robot_leg_3_0_M->defaultParam = ((real_T *)&Copy_of_Robot_leg_3_0_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Copy_of_Robot_leg_3_0_X;
    Copy_of_Robot_leg_3_0_M->contStates = (x);
    (void) memset((void *)&Copy_of_Robot_leg_3_0_X, 0,
                  sizeof(X_Copy_of_Robot_leg_3_0_T));
  }

  /* states (dwork) */
  Copy_of_Robot_leg_3_0_M->dwork = ((void *) &Copy_of_Robot_leg_3_0_DW);
  (void) memset((void *)&Copy_of_Robot_leg_3_0_DW, 0,
                sizeof(DW_Copy_of_Robot_leg_3_0_T));

  /* external outputs */
  Copy_of_Robot_leg_3_0_M->outputs = (&Copy_of_Robot_leg_3_0_Y);
  (void) memset((void *)&Copy_of_Robot_leg_3_0_Y, 0,
                sizeof(ExtY_Copy_of_Robot_leg_3_0_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  Copy_of_Robot_leg_3_0_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.sfcnInfo;
    Copy_of_Robot_leg_3_0_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Copy_of_Robot_leg_3_0_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Copy_of_Robot_leg_3_0_M->Sizes.numSampTimes);
    Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Copy_of_Robot_leg_3_0_M)[0]);
    Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Copy_of_Robot_leg_3_0_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Copy_of_Robot_leg_3_0_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Copy_of_Robot_leg_3_0_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Copy_of_Robot_leg_3_0_M));
    rtssSetStepSizePtr(sfcnInfo, &Copy_of_Robot_leg_3_0_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (Copy_of_Robot_leg_3_0_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Copy_of_Robot_leg_3_0_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Copy_of_Robot_leg_3_0_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Copy_of_Robot_leg_3_0_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Copy_of_Robot_leg_3_0_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Copy_of_Robot_leg_3_0_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Copy_of_Robot_leg_3_0_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Copy_of_Robot_leg_3_0_M->solverInfoPtr);
  }

  Copy_of_Robot_leg_3_0_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)
                  &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  3*sizeof(SimStruct));
    Copy_of_Robot_leg_3_0_M->childSfunctions =
      (&Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Copy_of_Robot_leg_3_0_M->childSfunctions[0] =
      (&Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.childSFunctions[0]);
    Copy_of_Robot_leg_3_0_M->childSfunctions[1] =
      (&Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.childSFunctions[1]);
    Copy_of_Robot_leg_3_0_M->childSfunctions[2] =
      (&Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: Copy_of_Robot_leg_3_0/<S4>/UDP Configure (slrtIPConfig) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_Robot_leg_3_0_M->
                         NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_Robot_leg_3_0_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "UDP Configure");
      ssSetPath(rts, "Copy_of_Robot_leg_3_0/Robot/UDP Configure");
      ssSetRTModel(rts,Copy_of_Robot_leg_3_0_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.UDPConfigure_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &Copy_of_Robot_leg_3_0_DW.UDPConfigure_IWORK[0]);
      ssSetPWork(rts, (void **) &Copy_of_Robot_leg_3_0_DW.UDPConfigure_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Copy_of_Robot_leg_3_0_DW.UDPConfigure_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Copy_of_Robot_leg_3_0_DW.UDPConfigure_PWORK[0]);
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

    /* Level2 S-Function Block: Copy_of_Robot_leg_3_0/<S4>/ASCII Encode 2 (asciiencode) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_Robot_leg_3_0_M->
                         NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_Robot_leg_3_0_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 12);
        ssSetPortInfoForInputs(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
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
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
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
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_e;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_g;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs2;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_p5;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs3;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_c;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs4;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_f;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs5;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_j;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs6;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_d;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs7;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_k;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }

        /* port 8 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs8;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_aq;
          ssSetInputPortSignalPtrs(rts, 8, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 1);
        }

        /* port 9 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs9;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_ec;
          ssSetInputPortSignalPtrs(rts, 9, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 9, 1);
          ssSetInputPortWidth(rts, 9, 1);
        }

        /* port 10 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs10;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_a4;
          ssSetInputPortSignalPtrs(rts, 10, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 1);
        }

        /* port 11 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.UPtrs11;
          sfcnUPtrs[0] = &Copy_of_Robot_leg_3_0_B.DataTypeConversion_dj;
          ssSetInputPortSignalPtrs(rts, 11, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 128);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            Copy_of_Robot_leg_3_0_B.ASCIIEncode2));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Encode 2");
      ssSetPath(rts, "Copy_of_Robot_leg_3_0/Robot/ASCII Encode 2");
      ssSetRTModel(rts,Copy_of_Robot_leg_3_0_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Copy_of_Robot_leg_3_0_DW.ASCIIEncode2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Copy_of_Robot_leg_3_0_DW.ASCIIEncode2_PWORK);
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

    /* Level2 S-Function Block: Copy_of_Robot_leg_3_0/<S4>/UDP Send (slrtUDPSend) */
    {
      SimStruct *rts = Copy_of_Robot_leg_3_0_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_Robot_leg_3_0_M->
                         NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_Robot_leg_3_0_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, Copy_of_Robot_leg_3_0_B.ASCIIEncode2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 128);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &Copy_of_Robot_leg_3_0_B.Constant3);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Send");
      ssSetPath(rts, "Copy_of_Robot_leg_3_0/Robot/UDP Send");
      ssSetRTModel(rts,Copy_of_Robot_leg_3_0_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_Robot_leg_3_0_P.UDPSend_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_Robot_leg_3_0_P.UDPSend_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Copy_of_Robot_leg_3_0_P.UDPSend_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Copy_of_Robot_leg_3_0_P.UDPSend_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Copy_of_Robot_leg_3_0_P.UDPSend_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Copy_of_Robot_leg_3_0_P.UDPSend_P6_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &Copy_of_Robot_leg_3_0_DW.UDPSend_IWORK[0]);
      ssSetPWork(rts, (void **) &Copy_of_Robot_leg_3_0_DW.UDPSend_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Copy_of_Robot_leg_3_0_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Copy_of_Robot_leg_3_0_DW.UDPSend_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Copy_of_Robot_leg_3_0_DW.UDPSend_PWORK);
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
  Copy_of_Robot_leg_3_0_M->Sizes.numContStates = (37);/* Number of continuous states */
  Copy_of_Robot_leg_3_0_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Copy_of_Robot_leg_3_0_M->Sizes.numY = (31);/* Number of model outputs */
  Copy_of_Robot_leg_3_0_M->Sizes.numU = (0);/* Number of model inputs */
  Copy_of_Robot_leg_3_0_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Copy_of_Robot_leg_3_0_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Copy_of_Robot_leg_3_0_M->Sizes.numBlocks = (1520);/* Number of blocks */
  Copy_of_Robot_leg_3_0_M->Sizes.numBlockIO = (869);/* Number of block outputs */
  Copy_of_Robot_leg_3_0_M->Sizes.numBlockPrms = (2525);/* Sum of parameter "widths" */
  return Copy_of_Robot_leg_3_0_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
