/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Copy_of_Robot_leg_3_0/Solver Configuration'.
 */

#include "ne_std.h"
#include "pm_default_allocator.h"
#include "ne_dae.h"
#include "ne_solverparameters.h"
#include "sm_ssci_NeDaePrivateData.h"

NeDae *sm_ssci_constructDae(NeDaePrivateData *smData);
void Copy_of_Robot_leg_3_0_7d8ca6e_1_NeDaePrivateData_create(NeDaePrivateData
  *smData);
void Copy_of_Robot_leg_3_0_7d8ca6e_1_dae(
  NeDae **dae,
  const NeModelParameters *modelParams,
  const NeSolverParameters *solverParams)
{
  PmAllocator *alloc = pm_default_allocator();
  NeDaePrivateData *smData =
    (NeDaePrivateData *) alloc->mCallocFcn(alloc, sizeof(NeDaePrivateData), 1);
  (void) modelParams;
  (void) solverParams;
  Copy_of_Robot_leg_3_0_7d8ca6e_1_NeDaePrivateData_create(smData);
  *dae = sm_ssci_constructDae(smData);
}
