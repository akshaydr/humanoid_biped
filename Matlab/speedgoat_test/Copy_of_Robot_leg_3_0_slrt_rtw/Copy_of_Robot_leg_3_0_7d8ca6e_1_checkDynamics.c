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

PmfMessageId Copy_of_Robot_leg_3_0_7d8ca6e_1_checkDynamics(const double *rtdv,
  const double *state, const double *input, const double *inputDot, const double
  *inputDdot, const double *discreteState, double *result, NeuDiagnosticManager *
  neDiagMgr)
{
  double xx[62];
  (void) rtdv;
  (void) state;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = - 0.03834662387806272;
  xx[1] = - 3.273602501000982e-3;
  xx[2] = 0.094029934348221;
  xx[3] = 0.0181326805158776;
  xx[4] = xx[3] * input[19];
  xx[5] = 0.9998355894332374;
  xx[6] = xx[3] * input[20];
  xx[7] = 2.0;
  xx[8] = input[19] - (xx[3] * xx[4] - xx[5] * xx[6]) * xx[7];
  xx[9] = input[20] - xx[7] * (xx[5] * xx[4] + xx[3] * xx[6]);
  xx[10] = input[18];
  xx[11] = xx[8];
  xx[12] = xx[9];
  pm_math_cross3(xx + 0, xx + 10, xx + 13);
  xx[0] = 0.03834662387806283;
  xx[10] = xx[0];
  xx[11] = - 9.078822698867147e-3;
  xx[12] = - 0.06596727944516941;
  xx[1] = xx[3] * input[31];
  xx[2] = xx[3] * input[32];
  xx[4] = input[31] - (xx[3] * xx[1] - xx[5] * xx[2]) * xx[7];
  xx[6] = input[32] - xx[7] * (xx[5] * xx[1] + xx[3] * xx[2]);
  xx[16] = input[30];
  xx[17] = xx[4];
  xx[18] = xx[6];
  pm_math_cross3(xx + 10, xx + 16, xx + 19);
  xx[1] = 0.09402993434822095;
  xx[10] = 0.03834662387806295;
  xx[11] = - 3.273602501000975e-3;
  xx[12] = xx[1];
  xx[2] = xx[3] * input[43];
  xx[16] = xx[3] * input[44];
  xx[17] = input[43] - (xx[3] * xx[2] - xx[5] * xx[16]) * xx[7];
  xx[18] = input[44] - xx[7] * (xx[5] * xx[2] + xx[3] * xx[16]);
  xx[22] = input[42];
  xx[23] = xx[17];
  xx[24] = xx[18];
  pm_math_cross3(xx + 10, xx + 22, xx + 25);
  xx[10] = - xx[0];
  xx[11] = - 9.078822698867124e-3;
  xx[12] = - 0.06596727944516946;
  xx[0] = xx[3] * input[55];
  xx[2] = xx[3] * input[56];
  xx[16] = input[55] - (xx[3] * xx[0] - xx[5] * xx[2]) * xx[7];
  xx[22] = input[56] - xx[7] * (xx[5] * xx[0] + xx[3] * xx[2]);
  xx[28] = input[54];
  xx[29] = xx[16];
  xx[30] = xx[22];
  pm_math_cross3(xx + 10, xx + 28, xx + 31);
  xx[0] = 0.03834662387806284;
  xx[10] = - xx[0];
  xx[11] = - 3.273602501000974e-3;
  xx[12] = 0.09402993434822098;
  xx[2] = 0.01813268051587749;
  xx[23] = xx[2] * input[67];
  xx[24] = xx[2] * input[68];
  xx[28] = input[67] - (xx[2] * xx[23] - xx[5] * xx[24]) * xx[7];
  xx[29] = input[68] - xx[7] * (xx[5] * xx[23] + xx[2] * xx[24]);
  xx[34] = input[66];
  xx[35] = xx[28];
  xx[36] = xx[29];
  pm_math_cross3(xx + 10, xx + 34, xx + 37);
  xx[10] = xx[0];
  xx[11] = - 3.273602501000983e-3;
  xx[12] = xx[1];
  xx[0] = xx[2] * input[79];
  xx[1] = xx[2] * input[80];
  xx[23] = input[79] - (xx[2] * xx[0] - xx[5] * xx[1]) * xx[7];
  xx[24] = input[80] - xx[7] * (xx[5] * xx[0] + xx[2] * xx[1]);
  xx[34] = input[78];
  xx[35] = xx[23];
  xx[36] = xx[24];
  pm_math_cross3(xx + 10, xx + 34, xx + 40);
  xx[10] = 0.03834662387806273;
  xx[11] = - 9.078822698867142e-3;
  xx[12] = - 0.06596727944516942;
  xx[0] = xx[2] * input[91];
  xx[1] = xx[2] * input[92];
  xx[30] = input[91] - (xx[2] * xx[0] - xx[5] * xx[1]) * xx[7];
  xx[34] = input[92] - xx[7] * (xx[5] * xx[0] + xx[2] * xx[1]);
  xx[43] = input[90];
  xx[44] = xx[30];
  xx[45] = xx[34];
  pm_math_cross3(xx + 10, xx + 43, xx + 46);
  xx[10] = - 0.03834662387806292;
  xx[11] = - 9.078822698867102e-3;
  xx[12] = - 0.06596727944516947;
  xx[0] = xx[2] * input[103];
  xx[1] = xx[2] * input[104];
  xx[35] = input[103] - (xx[2] * xx[0] - xx[5] * xx[1]) * xx[7];
  xx[36] = input[104] - xx[7] * (xx[5] * xx[0] + xx[2] * xx[1]);
  xx[43] = input[102];
  xx[44] = xx[35];
  xx[45] = xx[36];
  pm_math_cross3(xx + 10, xx + 43, xx + 49);
  xx[0] = xx[13] + input[21] + xx[19] + input[33] + xx[25] + input[45] + xx[31]
    + input[57] + xx[37] + input[69] + xx[40] + input[81] + xx[46] + input[93] +
    xx[49] + input[105];
  xx[1] = xx[3] * input[22];
  xx[10] = xx[3] * input[23];
  xx[11] = xx[3] * input[34];
  xx[12] = xx[3] * input[35];
  xx[43] = xx[3] * input[46];
  xx[44] = xx[3] * input[47];
  xx[45] = xx[3] * input[58];
  xx[52] = xx[3] * input[59];
  xx[53] = xx[2] * input[70];
  xx[54] = xx[2] * input[71];
  xx[55] = xx[2] * input[82];
  xx[56] = xx[2] * input[83];
  xx[57] = xx[2] * input[94];
  xx[58] = xx[2] * input[95];
  xx[59] = xx[2] * input[106];
  xx[60] = xx[2] * input[107];
  xx[61] = xx[14] + input[22] - (xx[3] * xx[1] - xx[5] * xx[10]) * xx[7] + xx[20]
    + input[34] - (xx[3] * xx[11] - xx[5] * xx[12]) * xx[7] + xx[26] + input[46]
    - (xx[3] * xx[43] - xx[5] * xx[44]) * xx[7] + xx[32] + input[58] - (xx[3] *
    xx[45] - xx[5] * xx[52]) * xx[7] + xx[38] + input[70] - (xx[2] * xx[53] -
    xx[5] * xx[54]) * xx[7] + xx[41] + input[82] - (xx[2] * xx[55] - xx[5] * xx
    [56]) * xx[7] + xx[47] + input[94] - (xx[2] * xx[57] - xx[5] * xx[58]) * xx
    [7] + xx[50] + input[106] - (xx[2] * xx[59] - xx[5] * xx[60]) * xx[7];
  xx[13] = xx[15] + input[23] - xx[7] * (xx[5] * xx[1] + xx[3] * xx[10]) + xx[21]
    + input[35] - xx[7] * (xx[5] * xx[11] + xx[3] * xx[12]) + xx[27] + input[47]
    - xx[7] * (xx[5] * xx[43] + xx[3] * xx[44]) + xx[33] + input[59] - xx[7] *
    (xx[5] * xx[45] + xx[3] * xx[52]) + xx[39] + input[71] - xx[7] * (xx[5] *
    xx[53] + xx[2] * xx[54]) + xx[42] + input[83] - xx[7] * (xx[5] * xx[55] +
    xx[2] * xx[56]) + xx[48] + input[95] - xx[7] * (xx[5] * xx[57] + xx[2] * xx
    [58]) + xx[51] + input[107] - xx[7] * (xx[5] * xx[59] + xx[2] * xx[60]);
  xx[1] = input[18] + input[30] + input[42] + input[54] + input[66] + input[78]
    + input[90] + input[102];
  xx[2] = xx[8] + xx[4] + xx[17] + xx[16] + xx[28] + xx[23] + xx[30] + xx[35];
  xx[3] = xx[9] + xx[6] + xx[18] + xx[22] + xx[29] + xx[24] + xx[34] + xx[36];
  result[0] = xx[0] * xx[0] + xx[61] * xx[61] + xx[13] * xx[13] + xx[1] * xx[1]
    + xx[2] * xx[2] + xx[3] * xx[3];
  return NULL;
}
