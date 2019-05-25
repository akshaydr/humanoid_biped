/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Copy_of_Robot_leg_3_0/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_CTarget.h"

static boolean_T checkTargets_24(const double *rtdv, const double *state)
{
  (void) rtdv;
  return fabs(state[0]) < 1.0e-9;
}

static boolean_T checkTargets_26(const double *rtdv, const double *state)
{
  (void) rtdv;
  return fabs(state[1]) < 1.0e-9;
}

static boolean_T checkTargets_28(const double *rtdv, const double *state)
{
  (void) rtdv;
  return fabs(state[2] - 0.455) < 1.0e-9;
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_checkTargets(const double *rtdv, const
  double *state)
{
  const char *msgId = "sm:compiler:state:UnsatisfiedDesiredTarget";
  if (!checkTargets_24(rtdv, state)) {
    pmf_preformatted_warning(
      msgId,
      "Copy_of_Robot_leg_3_0/6-DOF Joint Px high priority position target not achieved");
    pmf_printf("[manual]Copy_of_Robot_leg_3_0/6-DOF Joint Px high priority position target not achieved\n");
  }

  if (!checkTargets_26(rtdv, state)) {
    pmf_preformatted_warning(
      msgId,
      "Copy_of_Robot_leg_3_0/6-DOF Joint Py high priority position target not achieved");
    pmf_printf("[manual]Copy_of_Robot_leg_3_0/6-DOF Joint Py high priority position target not achieved\n");
  }

  if (!checkTargets_28(rtdv, state)) {
    pmf_preformatted_warning(
      msgId,
      "Copy_of_Robot_leg_3_0/6-DOF Joint Pz high priority position target not achieved");
    pmf_printf("[manual]Copy_of_Robot_leg_3_0/6-DOF Joint Pz high priority position target not achieved\n");
  }
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_setTargets(const double *rtdv, CTarget
  *targets)
{
  (void) rtdv;
  (void) targets;
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_resetStateVector(const void *mech, double
  *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = 1.0;
  state[4] = xx[0];
  state[5] = xx[0];
  state[6] = xx[0];
  state[7] = xx[0];
  state[8] = xx[0];
  state[9] = xx[0];
  state[10] = xx[0];
  state[11] = xx[0];
  state[12] = xx[0];
  state[13] = xx[0];
  state[14] = xx[0];
  state[15] = xx[0];
  state[16] = xx[0];
  state[17] = xx[0];
  state[18] = xx[0];
  state[19] = xx[0];
  state[20] = xx[0];
  state[21] = xx[0];
  state[22] = xx[0];
  state[23] = xx[0];
  state[24] = xx[0];
  state[25] = xx[0];
  state[26] = xx[0];
  state[27] = xx[0];
  state[28] = xx[0];
  state[29] = xx[0];
  state[30] = xx[0];
  state[31] = xx[0];
  state[32] = xx[0];
  state[33] = xx[0];
  state[34] = xx[0];
  state[35] = xx[0];
  state[36] = xx[0];
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_initializeTrackedAngleState(const void
  *mech, const double *rtdv, const double *motionData, double *state, void
  *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  (void) rtdv;
  (void) motionData;
  (void) state;
  (void) neDiagMgr;
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_computeDiscreteState(const void *mech,
  const double *rtdv, double *state)
{
  (void) mech;
  (void) rtdv;
  (void) state;
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_adjustPosition(const void *mech, const
  double *dofDeltas, double *state)
{
  double xx[11];
  (void) mech;
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  xx[4] = dofDeltas[3];
  xx[5] = dofDeltas[4];
  xx[6] = dofDeltas[5];
  pm_math_quatDeriv(xx + 0, xx + 4, xx + 7);
  xx[0] = state[3] + xx[7];
  xx[1] = state[4] + xx[8];
  xx[2] = state[5] + xx[9];
  xx[3] = state[6] + xx[10];
  xx[4] = sqrt(xx[0] * xx[0] + xx[1] * xx[1] + xx[2] * xx[2] + xx[3] * xx[3]);
  xx[5] = 1.0e-64;
  if (xx[5] > xx[4])
    xx[4] = xx[5];
  state[0] = state[0] + dofDeltas[0];
  state[1] = state[1] + dofDeltas[1];
  state[2] = state[2] + dofDeltas[2];
  state[3] = xx[0] / xx[4];
  state[4] = xx[1] / xx[4];
  state[5] = xx[2] / xx[4];
  state[6] = xx[3] / xx[4];
  state[13] = state[13] + dofDeltas[6];
  state[15] = state[15] + dofDeltas[7];
  state[17] = state[17] + dofDeltas[8];
  state[19] = state[19] + dofDeltas[9];
  state[21] = state[21] + dofDeltas[10];
  state[23] = state[23] + dofDeltas[11];
  state[25] = state[25] + dofDeltas[12];
  state[27] = state[27] + dofDeltas[13];
  state[29] = state[29] + dofDeltas[14];
  state[31] = state[31] + dofDeltas[15];
  state[33] = state[33] + dofDeltas[16];
  state[35] = state[35] + dofDeltas[17];
}

static void perturbJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[7] = state[7] - 0.875 * mag;
}

static void perturbJointPrimitiveState_0_1(double mag, double *state)
{
  state[1] = state[1] + mag;
}

static void perturbJointPrimitiveState_0_1v(double mag, double *state)
{
  state[1] = state[1] + mag;
  state[8] = state[8] - 0.875 * mag;
}

static void perturbJointPrimitiveState_0_2(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbJointPrimitiveState_0_2v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[9] = state[9] - 0.875 * mag;
}

static void perturbJointPrimitiveState_0_3(double mag, double *state)
{
  double xx[14];
  xx[0] = 0.5 * mag;
  xx[1] = fabs(mag);
  xx[2] = 1.0 / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = cos(xx[2]);
  xx[4] = sin(2.0 * xx[2]);
  xx[2] = sqrt(xx[1] * xx[1] + xx[3] * xx[3] + xx[4] * xx[4]);
  xx[5] = sin(xx[0]);
  xx[6] = cos(xx[0]);
  xx[7] = xx[1] / xx[2] * xx[5];
  xx[8] = xx[3] / xx[2] * xx[5];
  xx[9] = xx[4] / xx[2] * xx[5];
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  pm_math_quatCompose(xx + 6, xx + 0, xx + 10);
  state[3] = xx[10];
  state[4] = xx[11];
  state[5] = xx[12];
  state[6] = xx[13];
}

static void perturbJointPrimitiveState_0_3v(double mag, double *state)
{
  double xx[14];
  xx[0] = 0.5 * mag;
  xx[1] = fabs(mag);
  xx[2] = 1.0 / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = cos(xx[2]);
  xx[4] = sin(2.0 * xx[2]);
  xx[2] = sqrt(xx[1] * xx[1] + xx[3] * xx[3] + xx[4] * xx[4]);
  xx[5] = sin(xx[0]);
  xx[6] = cos(xx[0]);
  xx[7] = xx[1] / xx[2] * xx[5];
  xx[8] = xx[3] / xx[2] * xx[5];
  xx[9] = xx[4] / xx[2] * xx[5];
  xx[1] = state[3];
  xx[2] = state[4];
  xx[3] = state[5];
  xx[4] = state[6];
  pm_math_quatCompose(xx + 6, xx + 1, xx + 10);
  state[3] = xx[10];
  state[4] = xx[11];
  state[5] = xx[12];
  state[6] = xx[13];
  state[10] = state[10] + 1.2 * mag;
  state[11] = state[11] - xx[0];
  state[12] = state[12] + 0.9 * mag;
}

static void perturbJointPrimitiveState_1_0(double mag, double *state)
{
  state[13] = state[13] + mag;
}

static void perturbJointPrimitiveState_1_0v(double mag, double *state)
{
  state[13] = state[13] + mag;
  state[14] = state[14] - 0.875 * mag;
}

static void perturbJointPrimitiveState_2_0(double mag, double *state)
{
  state[15] = state[15] + mag;
}

static void perturbJointPrimitiveState_2_0v(double mag, double *state)
{
  state[15] = state[15] + mag;
  state[16] = state[16] - 0.875 * mag;
}

static void perturbJointPrimitiveState_3_0(double mag, double *state)
{
  state[17] = state[17] + mag;
}

static void perturbJointPrimitiveState_3_0v(double mag, double *state)
{
  state[17] = state[17] + mag;
  state[18] = state[18] - 0.875 * mag;
}

static void perturbJointPrimitiveState_4_0(double mag, double *state)
{
  state[19] = state[19] + mag;
}

static void perturbJointPrimitiveState_4_0v(double mag, double *state)
{
  state[19] = state[19] + mag;
  state[20] = state[20] - 0.875 * mag;
}

static void perturbJointPrimitiveState_5_0(double mag, double *state)
{
  state[21] = state[21] + mag;
}

static void perturbJointPrimitiveState_5_0v(double mag, double *state)
{
  state[21] = state[21] + mag;
  state[22] = state[22] - 0.875 * mag;
}

static void perturbJointPrimitiveState_6_0(double mag, double *state)
{
  state[23] = state[23] + mag;
}

static void perturbJointPrimitiveState_6_0v(double mag, double *state)
{
  state[23] = state[23] + mag;
  state[24] = state[24] - 0.875 * mag;
}

static void perturbJointPrimitiveState_7_0(double mag, double *state)
{
  state[25] = state[25] + mag;
}

static void perturbJointPrimitiveState_7_0v(double mag, double *state)
{
  state[25] = state[25] + mag;
  state[26] = state[26] - 0.875 * mag;
}

static void perturbJointPrimitiveState_8_0(double mag, double *state)
{
  state[27] = state[27] + mag;
}

static void perturbJointPrimitiveState_8_0v(double mag, double *state)
{
  state[27] = state[27] + mag;
  state[28] = state[28] - 0.875 * mag;
}

static void perturbJointPrimitiveState_9_0(double mag, double *state)
{
  state[29] = state[29] + mag;
}

static void perturbJointPrimitiveState_9_0v(double mag, double *state)
{
  state[29] = state[29] + mag;
  state[30] = state[30] - 0.875 * mag;
}

static void perturbJointPrimitiveState_10_0(double mag, double *state)
{
  state[31] = state[31] + mag;
}

static void perturbJointPrimitiveState_10_0v(double mag, double *state)
{
  state[31] = state[31] + mag;
  state[32] = state[32] - 0.875 * mag;
}

static void perturbJointPrimitiveState_11_0(double mag, double *state)
{
  state[33] = state[33] + mag;
}

static void perturbJointPrimitiveState_11_0v(double mag, double *state)
{
  state[33] = state[33] + mag;
  state[34] = state[34] - 0.875 * mag;
}

static void perturbJointPrimitiveState_12_0(double mag, double *state)
{
  state[35] = state[35] + mag;
}

static void perturbJointPrimitiveState_12_0v(double mag, double *state)
{
  state[35] = state[35] + mag;
  state[36] = state[36] - 0.875 * mag;
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_perturbJointPrimitiveState(const void *mech,
  size_t stageIdx, size_t primIdx, double mag, boolean_T doPerturbVelocity,
  double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch ((stageIdx * 6 + primIdx) * 2 + (doPerturbVelocity ? 1 : 0))
  {
   case 0:
    perturbJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbJointPrimitiveState_0_0v(mag, state);
    break;

   case 2:
    perturbJointPrimitiveState_0_1(mag, state);
    break;

   case 3:
    perturbJointPrimitiveState_0_1v(mag, state);
    break;

   case 4:
    perturbJointPrimitiveState_0_2(mag, state);
    break;

   case 5:
    perturbJointPrimitiveState_0_2v(mag, state);
    break;

   case 6:
    perturbJointPrimitiveState_0_3(mag, state);
    break;

   case 7:
    perturbJointPrimitiveState_0_3v(mag, state);
    break;

   case 12:
    perturbJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbJointPrimitiveState_1_0v(mag, state);
    break;

   case 24:
    perturbJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbJointPrimitiveState_2_0v(mag, state);
    break;

   case 36:
    perturbJointPrimitiveState_3_0(mag, state);
    break;

   case 37:
    perturbJointPrimitiveState_3_0v(mag, state);
    break;

   case 48:
    perturbJointPrimitiveState_4_0(mag, state);
    break;

   case 49:
    perturbJointPrimitiveState_4_0v(mag, state);
    break;

   case 60:
    perturbJointPrimitiveState_5_0(mag, state);
    break;

   case 61:
    perturbJointPrimitiveState_5_0v(mag, state);
    break;

   case 72:
    perturbJointPrimitiveState_6_0(mag, state);
    break;

   case 73:
    perturbJointPrimitiveState_6_0v(mag, state);
    break;

   case 84:
    perturbJointPrimitiveState_7_0(mag, state);
    break;

   case 85:
    perturbJointPrimitiveState_7_0v(mag, state);
    break;

   case 96:
    perturbJointPrimitiveState_8_0(mag, state);
    break;

   case 97:
    perturbJointPrimitiveState_8_0v(mag, state);
    break;

   case 108:
    perturbJointPrimitiveState_9_0(mag, state);
    break;

   case 109:
    perturbJointPrimitiveState_9_0v(mag, state);
    break;

   case 120:
    perturbJointPrimitiveState_10_0(mag, state);
    break;

   case 121:
    perturbJointPrimitiveState_10_0v(mag, state);
    break;

   case 132:
    perturbJointPrimitiveState_11_0(mag, state);
    break;

   case 133:
    perturbJointPrimitiveState_11_0v(mag, state);
    break;

   case 144:
    perturbJointPrimitiveState_12_0(mag, state);
    break;

   case 145:
    perturbJointPrimitiveState_12_0v(mag, state);
    break;
  }
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_perturbFlexibleBodyState(const void *mech,
  size_t stageIdx, double mag, boolean_T doPerturbVelocity, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch (stageIdx * 2 + (doPerturbVelocity ? 1 : 0))
  {
  }
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_computeDofBlendMatrix(const void *mech,
  size_t stageIdx, size_t primIdx, const double *state, int partialType, double *
  matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_projectPartiallyTargetedPos(const void
  *mech, size_t stageIdx, size_t primIdx, const double *origState, int
  partialType, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) origState;
  (void) partialType;
  (void) state;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_propagateMotion(const void *mech, const
  double *rtdv, const double *state, double *motionData)
{
  double xx[273];
  (void) mech;
  (void) rtdv;
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  xx[4] = 0.3243753537416494;
  xx[5] = - 0.6247353595346088;
  xx[6] = - 0.6343220719927347;
  xx[7] = - 0.3195651254673875;
  pm_math_quatComposeInverse(xx + 0, xx + 4, xx + 8);
  xx[0] = 2.087913034127322e-4;
  xx[1] = 4.724358126822398e-3;
  xx[2] = 0.05531348216674228;
  xx[12] = - xx[0];
  xx[13] = - xx[1];
  xx[14] = - xx[2];
  pm_math_quatXform(xx + 8, xx + 12, xx + 15);
  xx[3] = state[0] - xx[15];
  xx[12] = state[1] - xx[16];
  xx[13] = state[2] - xx[17] + 0.0125;
  xx[14] = 0.6243609096288675;
  xx[15] = 0.5;
  xx[16] = xx[15] * state[13];
  xx[17] = cos(xx[16]);
  xx[18] = 0.325117548042414;
  xx[19] = 2.34081706819524e-3;
  xx[20] = sin(xx[16]);
  xx[16] = xx[19] * xx[20];
  xx[21] = 0.6339419855846944;
  xx[22] = 0.9999972602839735;
  xx[23] = xx[22] * xx[20];
  xx[20] = xx[14] * xx[17] + xx[18] * xx[16] + xx[21] * xx[23];
  xx[24] = - xx[20];
  xx[25] = 0.320296102685058;
  xx[26] = xx[14] * xx[16] - xx[18] * xx[17] - xx[25] * xx[23];
  xx[27] = xx[25] * xx[17] + xx[21] * xx[16] - xx[18] * xx[23];
  xx[18] = xx[14] * xx[23] - xx[21] * xx[17] + xx[25] * xx[16];
  xx[16] = 0.02988363324652958;
  xx[17] = 9.747188055245737e-3;
  xx[23] = xx[17] * xx[27];
  xx[28] = xx[26];
  xx[29] = xx[27];
  xx[30] = xx[18];
  xx[25] = xx[16] * xx[18] + xx[26] * xx[17];
  xx[31] = xx[16] * xx[27];
  xx[32] = - xx[23];
  xx[33] = xx[25];
  xx[34] = - xx[31];
  pm_math_cross3(xx + 28, xx + 32, xx + 35);
  xx[28] = 2.0;
  xx[29] = 0.0675780786620767 - (xx[16] + (xx[23] * xx[20] + xx[35]) * xx[28]);
  xx[16] = - (0.043589833835622 + (xx[36] - xx[20] * xx[25]) * xx[28]);
  xx[23] = 0.03388710098556934 - (xx[28] * (xx[37] + xx[31] * xx[20]) - xx[17]);
  xx[30] = - 0.5228488232047223;
  xx[31] = - 0.4685564901345529;
  xx[32] = - 0.4933975870405322;
  xx[33] = - 0.5134615318880337;
  xx[17] = xx[15] * state[15];
  xx[20] = 0.01408641066835348;
  xx[25] = sin(xx[17]);
  xx[34] = 0.07688900272270711;
  xx[35] = 0.9969401457935125;
  xx[36] = cos(xx[17]);
  xx[37] = xx[20] * xx[25];
  xx[38] = xx[34] * xx[25];
  xx[39] = - (xx[35] * xx[25]);
  pm_math_quatCompose(xx + 30, xx + 36, xx + 40);
  xx[17] = 0.01847628822060771;
  xx[25] = - 0.05337232889459952;
  xx[36] = - 2.886866353305222e-4;
  xx[37] = xx[17];
  xx[38] = xx[25];
  pm_math_quatXform(xx + 40, xx + 36, xx + 44);
  xx[36] = - (0.05585012064451239 + xx[44]);
  xx[37] = - xx[45];
  xx[38] = 0.01865357678921305 - xx[46];
  xx[39] = 0.996735800993462;
  xx[44] = xx[15] * state[17];
  xx[45] = cos(xx[44]);
  xx[46] = 0.07851842045688404;
  xx[47] = sin(xx[44]);
  xx[44] = - (xx[39] * xx[45] + xx[46] * xx[47]);
  xx[48] = xx[39] * xx[47] - xx[46] * xx[45];
  xx[39] = 7.011609266658198e-3;
  xx[46] = 0.01741947193143428;
  xx[49] = xx[39] * xx[45] + xx[46] * xx[47];
  xx[50] = xx[39] * xx[47] - xx[46] * xx[45];
  xx[39] = 0.02644367981387542;
  xx[51] = xx[44];
  xx[52] = xx[48];
  xx[53] = xx[49];
  xx[54] = xx[50];
  xx[45] = 0.06065512595890243;
  xx[55] = 0.02780000000000006;
  xx[56] = xx[45];
  xx[57] = - 3.571892891955767e-3;
  pm_math_quatXform(xx + 51, xx + 55, xx + 58);
  xx[47] = xx[39] - xx[58];
  xx[55] = 0.01369049755590576;
  xx[56] = xx[55] - xx[59];
  xx[57] = 0.02126463776157213 - xx[60];
  xx[58] = 2.774682062490208e-4;
  xx[59] = 7.716874904287963e-3;
  xx[60] = - 0.9991596431053961;
  xx[61] = 0.04025394940379737;
  xx[62] = xx[15] * state[19];
  xx[63] = 0.999880745706212;
  xx[64] = sin(xx[62]);
  xx[65] = 0.01544311833278583;
  xx[66] = 6.679931604769429e-5;
  xx[67] = cos(xx[62]);
  xx[68] = - (xx[63] * xx[64]);
  xx[69] = - (xx[65] * xx[64]);
  xx[70] = xx[66] * xx[64];
  pm_math_quatCompose(xx + 58, xx + 67, xx + 71);
  xx[58] = 0.02745240391074398;
  xx[59] = 0.04500881965380649;
  xx[60] = - 5.733566089310364e-6;
  pm_math_quatXform(xx + 71, xx + 58, xx + 67);
  xx[58] = - (0.02900000000000002 + xx[67]);
  xx[59] = - (0.07395629977616552 + xx[68]);
  xx[60] = - (5.754565925706492e-3 + xx[69]);
  xx[61] = - 0.9989263853281884;
  xx[67] = 8.036273887780998e-3;
  xx[68] = 0.02483606024761018;
  xx[69] = xx[61];
  xx[70] = - 0.03827094339753623;
  xx[62] = xx[15] * state[21];
  xx[64] = 0.9992947986662437;
  xx[75] = sin(xx[62]);
  xx[76] = 0.03362414164796479;
  xx[77] = 0.01671294279981028;
  xx[78] = cos(xx[62]);
  xx[79] = xx[64] * xx[75];
  xx[80] = xx[76] * xx[75];
  xx[81] = xx[77] * xx[75];
  pm_math_quatCompose(xx + 67, xx + 78, xx + 82);
  xx[62] = 0.02644367981387541;
  xx[67] = xx[62];
  xx[68] = 0.01369049755590571;
  xx[69] = 0.02126463776157215;
  pm_math_quatXform(xx + 82, xx + 67, xx + 78);
  xx[67] = - (0.02659091123241594 + xx[78]);
  xx[68] = - (0.1339141837809728 + xx[79]);
  xx[69] = 3.843199333252611e-6 - xx[80];
  xx[70] = 0.05645734627296128;
  xx[75] = xx[15] * state[23];
  xx[78] = cos(xx[75]);
  xx[79] = 0.0172601569442824;
  xx[80] = 0.03625939862319044;
  xx[81] = sin(xx[75]);
  xx[75] = xx[80] * xx[81];
  xx[86] = 7.395109812373028e-3;
  xx[87] = 0.9993424117946184;
  xx[88] = xx[87] * xx[81];
  xx[81] = xx[70] * xx[78] - (xx[79] * xx[75] + xx[86] * xx[88]);
  xx[89] = 0.998228414434761;
  xx[90] = xx[79] * xx[88] - xx[89] * xx[78] - xx[86] * xx[75];
  xx[91] = xx[70] * xx[75] + xx[79] * xx[78] + xx[89] * xx[88];
  xx[79] = - xx[91];
  xx[92] = xx[89] * xx[75] - (xx[70] * xx[88] + xx[86] * xx[78]);
  xx[93] = xx[90];
  xx[94] = xx[79];
  xx[95] = xx[92];
  xx[70] = 0.0455619844506976;
  xx[75] = 0.02798953705505147;
  xx[78] = xx[70] * xx[91] + xx[92] * xx[75];
  xx[86] = xx[70] * xx[90];
  xx[88] = xx[75] * xx[90];
  xx[96] = - xx[78];
  xx[97] = - xx[86];
  xx[98] = xx[88];
  pm_math_cross3(xx + 93, xx + 96, xx + 99);
  xx[89] = - (2.886866353305348e-4 + (xx[99] - xx[81] * xx[78]) * xx[28]);
  xx[78] = 0.01847628822060769;
  xx[91] = xx[78] - (xx[75] + xx[28] * (xx[100] - xx[86] * xx[81]));
  xx[75] = 0.05337232889459954;
  xx[86] = - (xx[75] + xx[70] + (xx[88] * xx[81] + xx[101]) * xx[28]);
  xx[70] = xx[15] * state[25];
  xx[88] = cos(xx[70]);
  xx[93] = 0.3251175480424139;
  xx[94] = 2.34081706819499e-3;
  xx[95] = sin(xx[70]);
  xx[70] = xx[94] * xx[95];
  xx[96] = xx[22] * xx[95];
  xx[95] = xx[14] * xx[88] + xx[93] * xx[70] + xx[21] * xx[96];
  xx[97] = 0.3202961026850582;
  xx[98] = xx[93] * xx[88] - xx[14] * xx[70] + xx[97] * xx[96];
  xx[99] = xx[93] * xx[96] - (xx[97] * xx[88] + xx[21] * xx[70]);
  xx[93] = xx[21] * xx[88] - xx[14] * xx[96] - xx[97] * xx[70];
  xx[14] = 0.02988363324652947;
  xx[100] = xx[98];
  xx[101] = xx[99];
  xx[102] = xx[93];
  xx[21] = 9.747188055245751e-3;
  xx[70] = xx[21] * xx[99];
  xx[88] = xx[14] * xx[93] + xx[98] * xx[21];
  xx[96] = xx[14] * xx[99];
  xx[103] = - xx[70];
  xx[104] = xx[88];
  xx[105] = - xx[96];
  pm_math_cross3(xx + 100, xx + 103, xx + 106);
  xx[97] = - (0.06660648227706481 + xx[14] + (xx[106] - xx[70] * xx[95]) * xx[28]);
  xx[14] = - (0.0456253582752392 + (xx[95] * xx[88] + xx[107]) * xx[28]);
  xx[70] = 0.03387142214735862 - (xx[28] * (xx[108] - xx[96] * xx[95]) - xx[21]);
  xx[21] = xx[15] * state[27];
  xx[88] = sin(xx[21]);
  xx[100] = cos(xx[21]);
  xx[101] = xx[20] * xx[88];
  xx[102] = xx[34] * xx[88];
  xx[103] = - (xx[35] * xx[88]);
  pm_math_quatCompose(xx + 30, xx + 100, xx + 104);
  xx[30] = - 2.88686635330529e-4;
  xx[31] = xx[17];
  xx[32] = xx[25];
  pm_math_quatXform(xx + 104, xx + 30, xx + 100);
  xx[17] = - (0.05585012064451238 + xx[100]);
  xx[21] = - xx[101];
  xx[25] = 0.01865357678921372 - xx[102];
  xx[30] = 0.9967358009934617;
  xx[31] = xx[15] * state[29];
  xx[32] = cos(xx[31]);
  xx[33] = 0.07851842045688398;
  xx[88] = sin(xx[31]);
  xx[31] = - (xx[30] * xx[32] + xx[33] * xx[88]);
  xx[96] = xx[30] * xx[88] - xx[33] * xx[32];
  xx[30] = 7.011609266658225e-3;
  xx[33] = xx[30] * xx[32] + xx[46] * xx[88];
  xx[100] = xx[30] * xx[88] - xx[46] * xx[32];
  xx[108] = xx[31];
  xx[109] = xx[96];
  xx[110] = xx[33];
  xx[111] = xx[100];
  xx[101] = 0.02780000000000002;
  xx[102] = 0.06065512595890244;
  xx[103] = - 3.57189289195571e-3;
  pm_math_quatXform(xx + 108, xx + 101, xx + 112);
  xx[30] = xx[62] - xx[112];
  xx[32] = xx[55] - xx[113];
  xx[46] = 0.02126463776157213 - xx[114];
  xx[112] = 2.774682062476885e-4;
  xx[113] = 7.716874904288629e-3;
  xx[114] = - 0.9991596431053962;
  xx[115] = 0.04025394940379645;
  xx[55] = xx[15] * state[31];
  xx[62] = 0.9998807457062122;
  xx[88] = sin(xx[55]);
  xx[101] = 0.01544311833278705;
  xx[102] = 6.679931605035883e-5;
  xx[116] = cos(xx[55]);
  xx[117] = - (xx[62] * xx[88]);
  xx[118] = - (xx[101] * xx[88]);
  xx[119] = xx[102] * xx[88];
  pm_math_quatCompose(xx + 112, xx + 116, xx + 120);
  xx[112] = 0.02745240391074395;
  xx[113] = 0.04500881965380644;
  xx[114] = - 5.733566089473462e-6;
  pm_math_quatXform(xx + 120, xx + 112, xx + 115);
  xx[55] = - (0.029 + xx[115]);
  xx[88] = - (0.07395629977616557 + xx[116]);
  xx[103] = - (5.75456592570645e-3 + xx[117]);
  xx[112] = 8.036273887780332e-3;
  xx[113] = 0.02483606024761134;
  xx[114] = xx[61];
  xx[115] = - 0.03827094339753706;
  xx[61] = xx[15] * state[33];
  xx[116] = sin(xx[61]);
  xx[124] = cos(xx[61]);
  xx[125] = xx[64] * xx[116];
  xx[126] = xx[76] * xx[116];
  xx[127] = xx[77] * xx[116];
  pm_math_quatCompose(xx + 112, xx + 124, xx + 116);
  xx[112] = xx[39];
  xx[113] = 0.01369049755590577;
  xx[114] = 0.02126463776157214;
  pm_math_quatXform(xx + 116, xx + 112, xx + 124);
  xx[39] = - (0.02659091123241532 + xx[124]);
  xx[61] = - (0.1339141837809728 + xx[125]);
  xx[112] = 3.843199333023761e-6 - xx[126];
  xx[113] = 0.0564573462729614;
  xx[114] = xx[15] * state[35];
  xx[15] = cos(xx[114]);
  xx[115] = 0.0172601569442824;
  xx[124] = 0.03625939862319066;
  xx[125] = sin(xx[114]);
  xx[114] = xx[124] * xx[125];
  xx[126] = 7.395109812373026e-3;
  xx[127] = xx[87] * xx[125];
  xx[125] = xx[113] * xx[15] - (xx[115] * xx[114] + xx[126] * xx[127]);
  xx[128] = 0.9982284144347608;
  xx[129] = xx[115] * xx[127] - xx[128] * xx[15] - xx[126] * xx[114];
  xx[130] = xx[113] * xx[114] + xx[115] * xx[15] + xx[128] * xx[127];
  xx[115] = - xx[130];
  xx[131] = xx[128] * xx[114] - (xx[113] * xx[127] + xx[126] * xx[15]);
  xx[126] = xx[129];
  xx[127] = xx[115];
  xx[128] = xx[131];
  xx[15] = 0.04556198445069765;
  xx[113] = 0.02798953705505043;
  xx[114] = xx[15] * xx[130] + xx[131] * xx[113];
  xx[130] = xx[15] * xx[129];
  xx[132] = xx[113] * xx[129];
  xx[133] = - xx[114];
  xx[134] = - xx[130];
  xx[135] = xx[132];
  pm_math_cross3(xx + 126, xx + 133, xx + 136);
  xx[126] = - (2.88686635330514e-4 + (xx[136] - xx[125] * xx[114]) * xx[28]);
  xx[114] = xx[78] - (xx[113] + xx[28] * (xx[137] - xx[130] * xx[125]));
  xx[78] = - (xx[75] + xx[15] + (xx[132] * xx[125] + xx[138]) * xx[28]);
  xx[132] = xx[24];
  xx[133] = xx[26];
  xx[134] = xx[27];
  xx[135] = xx[18];
  pm_math_quatCompose(xx + 8, xx + 132, xx + 136);
  xx[140] = xx[29];
  xx[141] = xx[16];
  xx[142] = xx[23];
  pm_math_quatXform(xx + 8, xx + 140, xx + 143);
  xx[15] = xx[143] + xx[3];
  xx[28] = xx[144] + xx[12];
  xx[75] = xx[145] + xx[13];
  pm_math_quatCompose(xx + 136, xx + 40, xx + 143);
  pm_math_quatXform(xx + 136, xx + 36, xx + 147);
  xx[113] = xx[147] + xx[15];
  xx[127] = xx[148] + xx[28];
  xx[128] = xx[149] + xx[75];
  pm_math_quatCompose(xx + 143, xx + 51, xx + 147);
  xx[151] = xx[47];
  xx[152] = xx[56];
  xx[153] = xx[57];
  pm_math_quatXform(xx + 143, xx + 151, xx + 154);
  xx[130] = xx[154] + xx[113];
  xx[157] = xx[155] + xx[127];
  xx[154] = xx[156] + xx[128];
  pm_math_quatCompose(xx + 147, xx + 71, xx + 158);
  pm_math_quatXform(xx + 147, xx + 58, xx + 162);
  xx[155] = xx[162] + xx[130];
  xx[156] = xx[163] + xx[157];
  xx[162] = xx[164] + xx[154];
  pm_math_quatCompose(xx + 158, xx + 82, xx + 163);
  pm_math_quatXform(xx + 158, xx + 67, xx + 167);
  xx[170] = xx[167] + xx[155];
  xx[171] = xx[168] + xx[156];
  xx[167] = xx[169] + xx[162];
  xx[172] = xx[81];
  xx[173] = xx[90];
  xx[174] = xx[79];
  xx[175] = xx[92];
  pm_math_quatCompose(xx + 163, xx + 172, xx + 176);
  xx[180] = xx[89];
  xx[181] = xx[91];
  xx[182] = xx[86];
  pm_math_quatXform(xx + 163, xx + 180, xx + 183);
  xx[186] = xx[95];
  xx[187] = xx[98];
  xx[188] = xx[99];
  xx[189] = xx[93];
  pm_math_quatCompose(xx + 8, xx + 186, xx + 190);
  xx[194] = xx[97];
  xx[195] = xx[14];
  xx[196] = xx[70];
  pm_math_quatXform(xx + 8, xx + 194, xx + 197);
  xx[168] = xx[197] + xx[3];
  xx[169] = xx[198] + xx[12];
  xx[197] = xx[199] + xx[13];
  pm_math_quatCompose(xx + 190, xx + 104, xx + 198);
  xx[202] = xx[17];
  xx[203] = xx[21];
  xx[204] = xx[25];
  pm_math_quatXform(xx + 190, xx + 202, xx + 205);
  xx[208] = xx[205] + xx[168];
  xx[209] = xx[206] + xx[169];
  xx[205] = xx[207] + xx[197];
  pm_math_quatCompose(xx + 198, xx + 108, xx + 210);
  xx[214] = xx[30];
  xx[215] = xx[32];
  xx[216] = xx[46];
  pm_math_quatXform(xx + 198, xx + 214, xx + 217);
  xx[206] = xx[217] + xx[208];
  xx[207] = xx[218] + xx[209];
  xx[217] = xx[219] + xx[205];
  pm_math_quatCompose(xx + 210, xx + 120, xx + 218);
  xx[222] = xx[55];
  xx[223] = xx[88];
  xx[224] = xx[103];
  pm_math_quatXform(xx + 210, xx + 222, xx + 225);
  xx[228] = xx[225] + xx[206];
  xx[229] = xx[226] + xx[207];
  xx[225] = xx[227] + xx[217];
  pm_math_quatCompose(xx + 218, xx + 116, xx + 230);
  xx[234] = xx[39];
  xx[235] = xx[61];
  xx[236] = xx[112];
  pm_math_quatXform(xx + 218, xx + 234, xx + 237);
  xx[226] = xx[237] + xx[228];
  xx[227] = xx[238] + xx[229];
  xx[237] = xx[239] + xx[225];
  xx[238] = xx[125];
  xx[239] = xx[129];
  xx[240] = xx[115];
  xx[241] = xx[131];
  pm_math_quatCompose(xx + 230, xx + 238, xx + 242);
  xx[246] = xx[126];
  xx[247] = xx[114];
  xx[248] = xx[78];
  pm_math_quatXform(xx + 230, xx + 246, xx + 249);
  xx[252] = state[10];
  xx[253] = state[11];
  xx[254] = state[12];
  pm_math_quatXform(xx + 4, xx + 252, xx + 255);
  xx[4] = state[7];
  xx[5] = state[8];
  xx[6] = state[9];
  pm_math_quatInverseXform(xx + 8, xx + 4, xx + 252);
  pm_math_cross3(xx + 255, xx + 0, xx + 4);
  xx[0] = xx[252] + xx[4];
  xx[1] = xx[253] + xx[5];
  xx[2] = xx[254] + xx[6];
  pm_math_quatInverseXform(xx + 132, xx + 255, xx + 4);
  xx[7] = xx[4] - xx[19] * state[14];
  xx[4] = xx[6] - xx[22] * state[14];
  pm_math_cross3(xx + 255, xx + 140, xx + 252);
  xx[140] = xx[252] + xx[0];
  xx[141] = xx[253] + xx[1];
  xx[142] = xx[254] + xx[2];
  pm_math_quatInverseXform(xx + 132, xx + 140, xx + 252);
  xx[6] = xx[253] + 0.02990636775802728 * state[14];
  xx[132] = xx[7];
  xx[133] = xx[5];
  xx[134] = xx[4];
  pm_math_quatInverseXform(xx + 40, xx + 132, xx + 140);
  xx[19] = xx[140] + xx[20] * state[16];
  xx[135] = xx[141] + xx[34] * state[16];
  xx[140] = xx[142] - xx[35] * state[16];
  pm_math_cross3(xx + 132, xx + 36, xx + 258);
  xx[132] = xx[258] + xx[252];
  xx[133] = xx[259] + xx[6];
  xx[134] = xx[260] + xx[254];
  pm_math_quatInverseXform(xx + 40, xx + 132, xx + 258);
  xx[132] = 0.01431600833068153;
  xx[133] = xx[258] - xx[132] * state[16];
  xx[134] = xx[259] - 1.039627839450807e-3 * state[16];
  xx[141] = xx[260] - 2.824614109922799e-4 * state[16];
  xx[258] = xx[19];
  xx[259] = xx[135];
  xx[260] = xx[140];
  pm_math_quatInverseXform(xx + 51, xx + 258, xx + 261);
  xx[142] = xx[261] - state[18];
  pm_math_cross3(xx + 258, xx + 151, xx + 264);
  xx[151] = xx[264] + xx[133];
  xx[152] = xx[265] + xx[134];
  xx[153] = xx[266] + xx[141];
  pm_math_quatInverseXform(xx + 51, xx + 151, xx + 258);
  xx[51] = xx[259] + 3.571892891955774e-3 * state[18];
  xx[52] = xx[260] + 0.06065512595890245 * state[18];
  xx[151] = xx[142];
  xx[152] = xx[262];
  xx[153] = xx[263];
  pm_math_quatInverseXform(xx + 71, xx + 151, xx + 259);
  xx[53] = xx[259] - xx[63] * state[20];
  xx[54] = xx[260] - xx[65] * state[20];
  xx[63] = xx[261] + xx[66] * state[20];
  pm_math_cross3(xx + 151, xx + 58, xx + 259);
  xx[151] = xx[259] + xx[258];
  xx[152] = xx[260] + xx[51];
  xx[153] = xx[261] + xx[52];
  pm_math_quatInverseXform(xx + 71, xx + 151, xx + 259);
  xx[65] = xx[259] + 2.918014229402226e-6 * state[20];
  xx[66] = xx[260] + 3.89908053183275e-6 * state[20];
  xx[151] = xx[261] + 0.0445795014366914 * state[20];
  xx[259] = xx[53];
  xx[260] = xx[54];
  xx[261] = xx[63];
  pm_math_quatInverseXform(xx + 82, xx + 259, xx + 264);
  xx[152] = xx[264] + xx[64] * state[22];
  xx[153] = xx[265] + xx[76] * state[22];
  xx[253] = xx[266] + xx[77] * state[22];
  pm_math_cross3(xx + 259, xx + 67, xx + 264);
  xx[259] = xx[264] + xx[65];
  xx[260] = xx[265] + xx[66];
  xx[261] = xx[266] + xx[151];
  pm_math_quatInverseXform(xx + 82, xx + 259, xx + 264);
  xx[259] = xx[264] - 4.86196689634968e-4 * state[22];
  xx[260] = xx[265] + 0.02080769020251504 * state[22];
  xx[261] = xx[266] - 0.01279169696301433 * state[22];
  xx[264] = xx[152];
  xx[265] = xx[153];
  xx[266] = xx[253];
  pm_math_quatInverseXform(xx + 172, xx + 264, xx + 267);
  pm_math_cross3(xx + 264, xx + 180, xx + 270);
  xx[180] = xx[270] + xx[259];
  xx[181] = xx[271] + xx[260];
  xx[182] = xx[272] + xx[261];
  pm_math_quatInverseXform(xx + 172, xx + 180, xx + 264);
  pm_math_quatInverseXform(xx + 186, xx + 255, xx + 172);
  xx[175] = xx[172] - xx[94] * state[26];
  xx[94] = xx[174] - xx[22] * state[26];
  pm_math_cross3(xx + 255, xx + 194, xx + 180);
  xx[194] = xx[180] + xx[0];
  xx[195] = xx[181] + xx[1];
  xx[196] = xx[182] + xx[2];
  pm_math_quatInverseXform(xx + 186, xx + 194, xx + 180);
  xx[22] = xx[181] + 0.02990636775802716 * state[26];
  xx[186] = xx[175];
  xx[187] = xx[173];
  xx[188] = xx[94];
  pm_math_quatInverseXform(xx + 104, xx + 186, xx + 194);
  xx[172] = xx[194] + xx[20] * state[28];
  xx[20] = xx[195] + xx[34] * state[28];
  xx[34] = xx[196] - xx[35] * state[28];
  pm_math_cross3(xx + 186, xx + 202, xx + 194);
  xx[186] = xx[194] + xx[180];
  xx[187] = xx[195] + xx[22];
  xx[188] = xx[196] + xx[182];
  pm_math_quatInverseXform(xx + 104, xx + 186, xx + 194);
  xx[35] = xx[194] - xx[132] * state[28];
  xx[132] = xx[195] - 1.039627839450814e-3 * state[28];
  xx[174] = xx[196] - 2.824614109922804e-4 * state[28];
  xx[186] = xx[172];
  xx[187] = xx[20];
  xx[188] = xx[34];
  pm_math_quatInverseXform(xx + 108, xx + 186, xx + 194);
  xx[181] = xx[194] - state[30];
  pm_math_cross3(xx + 186, xx + 214, xx + 202);
  xx[186] = xx[202] + xx[35];
  xx[187] = xx[203] + xx[132];
  xx[188] = xx[204] + xx[174];
  pm_math_quatInverseXform(xx + 108, xx + 186, xx + 202);
  xx[108] = xx[203] + 3.571892891955706e-3 * state[30];
  xx[109] = xx[204] + xx[45] * state[30];
  xx[186] = xx[181];
  xx[187] = xx[195];
  xx[188] = xx[196];
  pm_math_quatInverseXform(xx + 120, xx + 186, xx + 214);
  xx[45] = xx[214] - xx[62] * state[32];
  xx[62] = xx[215] - xx[101] * state[32];
  xx[101] = xx[216] + xx[102] * state[32];
  pm_math_cross3(xx + 186, xx + 222, xx + 214);
  xx[186] = xx[214] + xx[202];
  xx[187] = xx[215] + xx[108];
  xx[188] = xx[216] + xx[109];
  pm_math_quatInverseXform(xx + 120, xx + 186, xx + 214);
  xx[102] = xx[214] + 2.918014229519624e-6 * state[32];
  xx[110] = xx[215] + 3.899080531922684e-6 * state[32];
  xx[111] = xx[216] + 0.04457950143669132 * state[32];
  xx[186] = xx[45];
  xx[187] = xx[62];
  xx[188] = xx[101];
  pm_math_quatInverseXform(xx + 116, xx + 186, xx + 214);
  xx[189] = xx[214] + xx[64] * state[34];
  xx[64] = xx[215] + xx[76] * state[34];
  xx[76] = xx[216] + xx[77] * state[34];
  pm_math_cross3(xx + 186, xx + 234, xx + 214);
  xx[186] = xx[214] + xx[102];
  xx[187] = xx[215] + xx[110];
  xx[188] = xx[216] + xx[111];
  pm_math_quatInverseXform(xx + 116, xx + 186, xx + 214);
  xx[77] = xx[214] - 4.861966896349669e-4 * state[34];
  xx[186] = xx[215] + 0.02080769020251504 * state[34];
  xx[187] = xx[216] - 0.01279169696301439 * state[34];
  xx[214] = xx[189];
  xx[215] = xx[64];
  xx[216] = xx[76];
  pm_math_quatInverseXform(xx + 238, xx + 214, xx + 222);
  pm_math_cross3(xx + 214, xx + 246, xx + 234);
  xx[214] = xx[234] + xx[77];
  xx[215] = xx[235] + xx[186];
  xx[216] = xx[236] + xx[187];
  pm_math_quatInverseXform(xx + 238, xx + 214, xx + 234);
  motionData[0] = xx[8];
  motionData[1] = xx[9];
  motionData[2] = xx[10];
  motionData[3] = xx[11];
  motionData[4] = xx[3];
  motionData[5] = xx[12];
  motionData[6] = xx[13];
  motionData[7] = xx[24];
  motionData[8] = xx[26];
  motionData[9] = xx[27];
  motionData[10] = xx[18];
  motionData[11] = xx[29];
  motionData[12] = xx[16];
  motionData[13] = xx[23];
  motionData[14] = xx[40];
  motionData[15] = xx[41];
  motionData[16] = xx[42];
  motionData[17] = xx[43];
  motionData[18] = xx[36];
  motionData[19] = xx[37];
  motionData[20] = xx[38];
  motionData[21] = xx[44];
  motionData[22] = xx[48];
  motionData[23] = xx[49];
  motionData[24] = xx[50];
  motionData[25] = xx[47];
  motionData[26] = xx[56];
  motionData[27] = xx[57];
  motionData[28] = xx[71];
  motionData[29] = xx[72];
  motionData[30] = xx[73];
  motionData[31] = xx[74];
  motionData[32] = xx[58];
  motionData[33] = xx[59];
  motionData[34] = xx[60];
  motionData[35] = xx[82];
  motionData[36] = xx[83];
  motionData[37] = xx[84];
  motionData[38] = xx[85];
  motionData[39] = xx[67];
  motionData[40] = xx[68];
  motionData[41] = xx[69];
  motionData[42] = xx[81];
  motionData[43] = xx[90];
  motionData[44] = xx[79];
  motionData[45] = xx[92];
  motionData[46] = xx[89];
  motionData[47] = xx[91];
  motionData[48] = xx[86];
  motionData[49] = xx[95];
  motionData[50] = xx[98];
  motionData[51] = xx[99];
  motionData[52] = xx[93];
  motionData[53] = xx[97];
  motionData[54] = xx[14];
  motionData[55] = xx[70];
  motionData[56] = xx[104];
  motionData[57] = xx[105];
  motionData[58] = xx[106];
  motionData[59] = xx[107];
  motionData[60] = xx[17];
  motionData[61] = xx[21];
  motionData[62] = xx[25];
  motionData[63] = xx[31];
  motionData[64] = xx[96];
  motionData[65] = xx[33];
  motionData[66] = xx[100];
  motionData[67] = xx[30];
  motionData[68] = xx[32];
  motionData[69] = xx[46];
  motionData[70] = xx[120];
  motionData[71] = xx[121];
  motionData[72] = xx[122];
  motionData[73] = xx[123];
  motionData[74] = xx[55];
  motionData[75] = xx[88];
  motionData[76] = xx[103];
  motionData[77] = xx[116];
  motionData[78] = xx[117];
  motionData[79] = xx[118];
  motionData[80] = xx[119];
  motionData[81] = xx[39];
  motionData[82] = xx[61];
  motionData[83] = xx[112];
  motionData[84] = xx[125];
  motionData[85] = xx[129];
  motionData[86] = xx[115];
  motionData[87] = xx[131];
  motionData[88] = xx[126];
  motionData[89] = xx[114];
  motionData[90] = xx[78];
  motionData[91] = xx[136];
  motionData[92] = xx[137];
  motionData[93] = xx[138];
  motionData[94] = xx[139];
  motionData[95] = xx[15];
  motionData[96] = xx[28];
  motionData[97] = xx[75];
  motionData[98] = xx[143];
  motionData[99] = xx[144];
  motionData[100] = xx[145];
  motionData[101] = xx[146];
  motionData[102] = xx[113];
  motionData[103] = xx[127];
  motionData[104] = xx[128];
  motionData[105] = xx[147];
  motionData[106] = xx[148];
  motionData[107] = xx[149];
  motionData[108] = xx[150];
  motionData[109] = xx[130];
  motionData[110] = xx[157];
  motionData[111] = xx[154];
  motionData[112] = xx[158];
  motionData[113] = xx[159];
  motionData[114] = xx[160];
  motionData[115] = xx[161];
  motionData[116] = xx[155];
  motionData[117] = xx[156];
  motionData[118] = xx[162];
  motionData[119] = xx[163];
  motionData[120] = xx[164];
  motionData[121] = xx[165];
  motionData[122] = xx[166];
  motionData[123] = xx[170];
  motionData[124] = xx[171];
  motionData[125] = xx[167];
  motionData[126] = xx[176];
  motionData[127] = xx[177];
  motionData[128] = xx[178];
  motionData[129] = xx[179];
  motionData[130] = xx[183] + xx[170];
  motionData[131] = xx[184] + xx[171];
  motionData[132] = xx[185] + xx[167];
  motionData[133] = xx[190];
  motionData[134] = xx[191];
  motionData[135] = xx[192];
  motionData[136] = xx[193];
  motionData[137] = xx[168];
  motionData[138] = xx[169];
  motionData[139] = xx[197];
  motionData[140] = xx[198];
  motionData[141] = xx[199];
  motionData[142] = xx[200];
  motionData[143] = xx[201];
  motionData[144] = xx[208];
  motionData[145] = xx[209];
  motionData[146] = xx[205];
  motionData[147] = xx[210];
  motionData[148] = xx[211];
  motionData[149] = xx[212];
  motionData[150] = xx[213];
  motionData[151] = xx[206];
  motionData[152] = xx[207];
  motionData[153] = xx[217];
  motionData[154] = xx[218];
  motionData[155] = xx[219];
  motionData[156] = xx[220];
  motionData[157] = xx[221];
  motionData[158] = xx[228];
  motionData[159] = xx[229];
  motionData[160] = xx[225];
  motionData[161] = xx[230];
  motionData[162] = xx[231];
  motionData[163] = xx[232];
  motionData[164] = xx[233];
  motionData[165] = xx[226];
  motionData[166] = xx[227];
  motionData[167] = xx[237];
  motionData[168] = xx[242];
  motionData[169] = xx[243];
  motionData[170] = xx[244];
  motionData[171] = xx[245];
  motionData[172] = xx[249] + xx[226];
  motionData[173] = xx[250] + xx[227];
  motionData[174] = xx[251] + xx[237];
  motionData[175] = xx[255];
  motionData[176] = xx[256];
  motionData[177] = xx[257];
  motionData[178] = xx[0];
  motionData[179] = xx[1];
  motionData[180] = xx[2];
  motionData[181] = xx[7];
  motionData[182] = xx[5];
  motionData[183] = xx[4];
  motionData[184] = xx[252];
  motionData[185] = xx[6];
  motionData[186] = xx[254];
  motionData[187] = xx[19];
  motionData[188] = xx[135];
  motionData[189] = xx[140];
  motionData[190] = xx[133];
  motionData[191] = xx[134];
  motionData[192] = xx[141];
  motionData[193] = xx[142];
  motionData[194] = xx[262];
  motionData[195] = xx[263];
  motionData[196] = xx[258];
  motionData[197] = xx[51];
  motionData[198] = xx[52];
  motionData[199] = xx[53];
  motionData[200] = xx[54];
  motionData[201] = xx[63];
  motionData[202] = xx[65];
  motionData[203] = xx[66];
  motionData[204] = xx[151];
  motionData[205] = xx[152];
  motionData[206] = xx[153];
  motionData[207] = xx[253];
  motionData[208] = xx[259];
  motionData[209] = xx[260];
  motionData[210] = xx[261];
  motionData[211] = xx[267];
  motionData[212] = xx[268] - xx[80] * state[24];
  motionData[213] = xx[269] - xx[87] * state[24];
  motionData[214] = xx[264] - 0.02631908130934852 * state[24];
  motionData[215] = xx[265];
  motionData[216] = xx[266];
  motionData[217] = xx[175];
  motionData[218] = xx[173];
  motionData[219] = xx[94];
  motionData[220] = xx[180];
  motionData[221] = xx[22];
  motionData[222] = xx[182];
  motionData[223] = xx[172];
  motionData[224] = xx[20];
  motionData[225] = xx[34];
  motionData[226] = xx[35];
  motionData[227] = xx[132];
  motionData[228] = xx[174];
  motionData[229] = xx[181];
  motionData[230] = xx[195];
  motionData[231] = xx[196];
  motionData[232] = xx[202];
  motionData[233] = xx[108];
  motionData[234] = xx[109];
  motionData[235] = xx[45];
  motionData[236] = xx[62];
  motionData[237] = xx[101];
  motionData[238] = xx[102];
  motionData[239] = xx[110];
  motionData[240] = xx[111];
  motionData[241] = xx[189];
  motionData[242] = xx[64];
  motionData[243] = xx[76];
  motionData[244] = xx[77];
  motionData[245] = xx[186];
  motionData[246] = xx[187];
  motionData[247] = xx[222];
  motionData[248] = xx[223] - xx[124] * state[36];
  motionData[249] = xx[224] - xx[87] * state[36];
  motionData[250] = xx[234] - 0.02631908130934748 * state[36];
  motionData[251] = xx[235];
  motionData[252] = xx[236];
}

size_t Copy_of_Robot_leg_3_0_7d8ca6e_1_computeAssemblyError(const void *mech,
  const double *rtdv, size_t constraintIdx, const double *state, const double
  *motionData, double *error)
{
  (void) mech;
  (void)rtdv;
  (void) state;
  (void) motionData;
  (void) error;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t Copy_of_Robot_leg_3_0_7d8ca6e_1_computeAssemblyJacobian(const void *mech,
  const double *rtdv, size_t constraintIdx, boolean_T forVelocitySatisfaction,
  const double *state, const double *motionData, double *J)
{
  (void) mech;
  (void) rtdv;
  (void) state;
  (void) forVelocitySatisfaction;
  (void) motionData;
  (void) J;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t Copy_of_Robot_leg_3_0_7d8ca6e_1_computeFullAssemblyJacobian(const void
  *mech, const double *rtdv, const double *state, const double *motionData,
  double *J)
{
  (void) mech;
  (void) rtdv;
  (void) state;
  (void) motionData;
  (void) J;
  return 0;
}

int Copy_of_Robot_leg_3_0_7d8ca6e_1_isInKinematicSingularity(const void *mech,
  const double *rtdv, size_t constraintIdx, const double *motionData)
{
  (void) mech;
  (void) rtdv
    ;
  (void) motionData;
  switch (constraintIdx)
  {
  }

  return 0;
}

PmfMessageId Copy_of_Robot_leg_3_0_7d8ca6e_1_convertStateVector(const void
  *asmMech, const double *rtdv, const void *simMech, const double *asmState,
  double *simState, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) asmMech;
  (void) rtdv;
  (void) simMech;
  (void) neDiagMgr;
  simState[0] = asmState[0];
  simState[1] = asmState[1];
  simState[2] = asmState[2];
  simState[3] = asmState[3];
  simState[4] = asmState[4];
  simState[5] = asmState[5];
  simState[6] = asmState[6];
  simState[7] = asmState[7];
  simState[8] = asmState[8];
  simState[9] = asmState[9];
  simState[10] = asmState[10];
  simState[11] = asmState[11];
  simState[12] = asmState[12];
  simState[13] = asmState[13];
  simState[14] = asmState[14];
  simState[15] = asmState[15];
  simState[16] = asmState[16];
  simState[17] = asmState[17];
  simState[18] = asmState[18];
  simState[19] = asmState[19];
  simState[20] = asmState[20];
  simState[21] = asmState[21];
  simState[22] = asmState[22];
  simState[23] = asmState[23];
  simState[24] = asmState[24];
  simState[25] = asmState[25];
  simState[26] = asmState[26];
  simState[27] = asmState[27];
  simState[28] = asmState[28];
  simState[29] = asmState[29];
  simState[30] = asmState[30];
  simState[31] = asmState[31];
  simState[32] = asmState[32];
  simState[33] = asmState[33];
  simState[34] = asmState[34];
  simState[35] = asmState[35];
  simState[36] = asmState[36];
  return NULL;
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_constructStateVector(const void *mech,
  const double *solverState, const double *u, const double *uDot, double
  *discreteState, double *fullState)
{
  (void) mech;
  (void) discreteState;
  fullState[0] = solverState[0];
  fullState[1] = solverState[1];
  fullState[2] = solverState[2];
  fullState[3] = solverState[3];
  fullState[4] = solverState[4];
  fullState[5] = solverState[5];
  fullState[6] = solverState[6];
  fullState[7] = solverState[7];
  fullState[8] = solverState[8];
  fullState[9] = solverState[9];
  fullState[10] = solverState[10];
  fullState[11] = solverState[11];
  fullState[12] = solverState[12];
  fullState[13] = u[5];
  fullState[14] = uDot[5];
  fullState[15] = u[3];
  fullState[16] = uDot[3];
  fullState[17] = u[1];
  fullState[18] = uDot[1];
  fullState[19] = u[2];
  fullState[20] = uDot[2];
  fullState[21] = u[0];
  fullState[22] = uDot[0];
  fullState[23] = u[4];
  fullState[24] = uDot[4];
  fullState[25] = u[11];
  fullState[26] = uDot[11];
  fullState[27] = u[6];
  fullState[28] = uDot[6];
  fullState[29] = u[9];
  fullState[30] = uDot[9];
  fullState[31] = u[10];
  fullState[32] = uDot[10];
  fullState[33] = u[7];
  fullState[34] = uDot[7];
  fullState[35] = u[8];
  fullState[36] = uDot[8];
}

void Copy_of_Robot_leg_3_0_7d8ca6e_1_extractSolverStateVector(const void *mech,
  const double *fullState, double *solverState)
{
  (void) mech;
  solverState[0] = fullState[0];
  solverState[1] = fullState[1];
  solverState[2] = fullState[2];
  solverState[3] = fullState[3];
  solverState[4] = fullState[4];
  solverState[5] = fullState[5];
  solverState[6] = fullState[6];
  solverState[7] = fullState[7];
  solverState[8] = fullState[8];
  solverState[9] = fullState[9];
  solverState[10] = fullState[10];
  solverState[11] = fullState[11];
  solverState[12] = fullState[12];
}

int Copy_of_Robot_leg_3_0_7d8ca6e_1_isPositionViolation(const void *mech, const
  double *rtdv, const int *eqnEnableFlags, const double *state)
{
  (void) mech;
  (void) rtdv;
  (void) eqnEnableFlags;
  (void) state;
  return 0;
}

int Copy_of_Robot_leg_3_0_7d8ca6e_1_isVelocityViolation(const void *mech, const
  double *rtdv, const int *eqnEnableFlags, const double *state)
{
  (void) mech;
  (void) rtdv;
  (void) eqnEnableFlags;
  (void) state;
  return 0;
}

PmfMessageId Copy_of_Robot_leg_3_0_7d8ca6e_1_projectStateSim(const void *mech,
  const double *rtdv, const int *eqnEnableFlags, const double *input, double
  *state, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  double xx[1];
  (void) mech;
  (void) rtdv;
  (void) eqnEnableFlags;
  (void) input;
  (void) neDiagMgr;
  xx[0] = 1.0 / sqrt(state[3] * state[3] + state[4] * state[4] + state[5] *
                     state[5] + state[6] * state[6]);
  state[3] = xx[0] * state[3];
  state[4] = xx[0] * state[4];
  state[5] = xx[0] * state[5];
  state[6] = xx[0] * state[6];
  return NULL;
}
