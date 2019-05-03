/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Copy_of_Robot_leg_3_0/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "Copy_of_Robot_leg_3_0_7d8ca6e_1.h"

void Copy_of_Robot_leg_3_0_7d8ca6e_1_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 0, 0.001, 0, 0.001, 0, 0, 0,
    0, (SscLoggingSetting) 0, 472727709, };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0.001, 1e-06, 1e-09, 0, 0,
    100, 0, 1, 0, 1e-09, 0, (NeLocalSolverChoice) 0, 0.001, 0, 3, 2,
    (NeLinearAlgebraChoice) 0, (NeEquationFormulationChoice) 0, 1024, 1, 0.001,
  };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0, 0,
        "Copy_of_Robot_leg_3_0/Solver\nConfiguration", }, { 0, 1,
        "Copy_of_Robot_leg_3_0/Solver\nConfiguration", }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  Copy_of_Robot_leg_3_0_7d8ca6e_1_dae(&dae,
    &modelparams,
    &solverparams);
  nesl_register_simulator_group("Copy_of_Robot_leg_3_0/Solver Configuration_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    1);
}
