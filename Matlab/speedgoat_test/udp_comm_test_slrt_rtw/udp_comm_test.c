/*
 * udp_comm_test.c
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

#include "rt_logging_mmi.h"
#include "udp_comm_test_capi.h"
#include "udp_comm_test.h"
#include "udp_comm_test_private.h"

/* Block signals (default storage) */
B_udp_comm_test_T udp_comm_test_B;

/* Block states (default storage) */
DW_udp_comm_test_T udp_comm_test_DW;

/* Real-time model */
RT_MODEL_udp_comm_test_T udp_comm_test_M_;
RT_MODEL_udp_comm_test_T *const udp_comm_test_M = &udp_comm_test_M_;

/* Model output function */
static void udp_comm_test_output(void)
{
  /* S-Function (slrtIPConfig): '<Root>/UDP Configure' */

  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Sum: '<Root>/1' incorporates:
   *  Constant: '<Root>/right_rotation2'
   *  Constant: '<Root>/rotation_tune'
   */
  udp_comm_test_B.u = udp_comm_test_P.right_rotation2_Value +
    udp_comm_test_P.rotation_tune_Value;

  /* Sum: '<Root>/2' incorporates:
   *  Constant: '<Root>/abduction_tune'
   *  Constant: '<Root>/right_abduction2 '
   */
  udp_comm_test_B.u_j = udp_comm_test_P.right_abduction2_Value +
    udp_comm_test_P.abduction_tune_Value;

  /* Sum: '<Root>/3' incorporates:
   *  Constant: '<Root>/hip_tune'
   *  Constant: '<Root>/right_hip2 '
   */
  udp_comm_test_B.u_k = udp_comm_test_P.right_hip2_Value +
    udp_comm_test_P.hip_tune_Value;

  /* Sum: '<Root>/4' incorporates:
   *  Constant: '<Root>/knee_tune'
   *  Constant: '<Root>/right_knee2'
   */
  udp_comm_test_B.u_d = udp_comm_test_P.right_knee2_Value +
    udp_comm_test_P.knee_tune_Value;

  /* Sum: '<Root>/5' incorporates:
   *  Constant: '<Root>/ankle_tune'
   *  Constant: '<Root>/right_annkle2'
   */
  udp_comm_test_B.u_h = udp_comm_test_P.right_annkle2_Value +
    udp_comm_test_P.ankle_tune_Value;

  /* Sum: '<Root>/6' incorporates:
   *  Constant: '<Root>/ankle_twist_tune'
   *  Constant: '<Root>/right_annkle_twist2 '
   */
  udp_comm_test_B.u_o = udp_comm_test_P.right_annkle_twist2_Value +
    udp_comm_test_P.ankle_twist_tune_Value;

  /* Sum: '<Root>/Add6' incorporates:
   *  Constant: '<Root>/left_rotation2 '
   *  Constant: '<Root>/rotation_tune'
   */
  udp_comm_test_B.Add6 = udp_comm_test_P.left_rotation2_Value -
    udp_comm_test_P.rotation_tune_Value;

  /* Sum: '<Root>/Add5' incorporates:
   *  Constant: '<Root>/abduction_tune'
   *  Constant: '<Root>/left_abduction2 '
   */
  udp_comm_test_B.Add5 = udp_comm_test_P.left_abduction2_Value -
    udp_comm_test_P.abduction_tune_Value;

  /* Sum: '<Root>/Add4' incorporates:
   *  Constant: '<Root>/hip_tune'
   *  Constant: '<Root>/left_hip2 '
   */
  udp_comm_test_B.Add4 = udp_comm_test_P.left_hip2_Value +
    udp_comm_test_P.hip_tune_Value;

  /* Sum: '<Root>/Add3' incorporates:
   *  Constant: '<Root>/knee_tune'
   *  Constant: '<Root>/left_knee2'
   */
  udp_comm_test_B.Add3 = udp_comm_test_P.left_knee2_Value +
    udp_comm_test_P.knee_tune_Value;

  /* Sum: '<Root>/Add2' incorporates:
   *  Constant: '<Root>/ankle_tune'
   *  Constant: '<Root>/left_ankle2'
   */
  udp_comm_test_B.Add2 = udp_comm_test_P.left_ankle2_Value +
    udp_comm_test_P.ankle_tune_Value;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/ankle_twist_tune'
   *  Constant: '<Root>/left_ankle_twist2 '
   */
  udp_comm_test_B.Add1 = udp_comm_test_P.left_ankle_twist2_Value -
    udp_comm_test_P.ankle_twist_tune_Value;

  /* S-Function (asciiencode): '<Root>/ASCII Encode 2' */

  /* Level2 S-Function Block: '<Root>/ASCII Encode 2' (asciiencode) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Constant3' */
  udp_comm_test_B.Constant3 = udp_comm_test_P.Constant3_Value;

  /* S-Function (slrtUDPSend): '<Root>/UDP Send' */

  /* Level2 S-Function Block: '<Root>/UDP Send' (slrtUDPSend) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (slrtUDPReceive): '<Root>/UDP Receive' */

  /* Level2 S-Function Block: '<Root>/UDP Receive' (slrtUDPReceive) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (asciidecode): '<Root>/ASCII Decode ' */

  /* Level2 S-Function Block: '<Root>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
static void udp_comm_test_update(void)
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
  if (!(++udp_comm_test_M->Timing.clockTick0)) {
    ++udp_comm_test_M->Timing.clockTickH0;
  }

  udp_comm_test_M->Timing.t[0] = udp_comm_test_M->Timing.clockTick0 *
    udp_comm_test_M->Timing.stepSize0 + udp_comm_test_M->Timing.clockTickH0 *
    udp_comm_test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void udp_comm_test_initialize(void)
{
  /* Start for S-Function (slrtIPConfig): '<Root>/UDP Configure' */
  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (asciiencode): '<Root>/ASCII Encode 2' */
  /* Level2 S-Function Block: '<Root>/ASCII Encode 2' (asciiencode) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant3' */
  udp_comm_test_B.Constant3 = udp_comm_test_P.Constant3_Value;

  /* Start for S-Function (slrtUDPSend): '<Root>/UDP Send' */
  /* Level2 S-Function Block: '<Root>/UDP Send' (slrtUDPSend) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (slrtUDPReceive): '<Root>/UDP Receive' */
  /* Level2 S-Function Block: '<Root>/UDP Receive' (slrtUDPReceive) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (asciidecode): '<Root>/ASCII Decode ' */
  /* Level2 S-Function Block: '<Root>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void udp_comm_test_terminate(void)
{
  /* Terminate for S-Function (slrtIPConfig): '<Root>/UDP Configure' */
  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (asciiencode): '<Root>/ASCII Encode 2' */
  /* Level2 S-Function Block: '<Root>/ASCII Encode 2' (asciiencode) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (slrtUDPSend): '<Root>/UDP Send' */
  /* Level2 S-Function Block: '<Root>/UDP Send' (slrtUDPSend) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (slrtUDPReceive): '<Root>/UDP Receive' */
  /* Level2 S-Function Block: '<Root>/UDP Receive' (slrtUDPReceive) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (asciidecode): '<Root>/ASCII Decode ' */
  /* Level2 S-Function Block: '<Root>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = udp_comm_test_M->childSfunctions[4];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  udp_comm_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  udp_comm_test_update();
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
  udp_comm_test_initialize();
}

void MdlTerminate(void)
{
  udp_comm_test_terminate();
}

/* Registration function */
RT_MODEL_udp_comm_test_T *udp_comm_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)udp_comm_test_M, 0,
                sizeof(RT_MODEL_udp_comm_test_T));
  rtsiSetSolverName(&udp_comm_test_M->solverInfo,"FixedStepDiscrete");
  udp_comm_test_M->solverInfoPtr = (&udp_comm_test_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = udp_comm_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    udp_comm_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    udp_comm_test_M->Timing.sampleTimes =
      (&udp_comm_test_M->Timing.sampleTimesArray[0]);
    udp_comm_test_M->Timing.offsetTimes =
      (&udp_comm_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    udp_comm_test_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    udp_comm_test_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(udp_comm_test_M, &udp_comm_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = udp_comm_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    udp_comm_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(udp_comm_test_M, -1);
  udp_comm_test_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    udp_comm_test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(udp_comm_test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(udp_comm_test_M->rtwLogInfo, (NULL));
    rtliSetLogT(udp_comm_test_M->rtwLogInfo, "tout");
    rtliSetLogX(udp_comm_test_M->rtwLogInfo, "");
    rtliSetLogXFinal(udp_comm_test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(udp_comm_test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(udp_comm_test_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(udp_comm_test_M->rtwLogInfo, 0);
    rtliSetLogDecimation(udp_comm_test_M->rtwLogInfo, 1);
    rtliSetLogY(udp_comm_test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(udp_comm_test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(udp_comm_test_M->rtwLogInfo, (NULL));
  }

  udp_comm_test_M->solverInfoPtr = (&udp_comm_test_M->solverInfo);
  udp_comm_test_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&udp_comm_test_M->solverInfo, 0.001);
  rtsiSetSolverMode(&udp_comm_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  udp_comm_test_M->blockIO = ((void *) &udp_comm_test_B);
  (void) memset(((void *) &udp_comm_test_B), 0,
                sizeof(B_udp_comm_test_T));

  /* parameters */
  udp_comm_test_M->defaultParam = ((real_T *)&udp_comm_test_P);

  /* states (dwork) */
  udp_comm_test_M->dwork = ((void *) &udp_comm_test_DW);
  (void) memset((void *)&udp_comm_test_DW, 0,
                sizeof(DW_udp_comm_test_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  udp_comm_test_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &udp_comm_test_M->NonInlinedSFcns.sfcnInfo;
    udp_comm_test_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(udp_comm_test_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &udp_comm_test_M->Sizes.numSampTimes);
    udp_comm_test_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (udp_comm_test_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,udp_comm_test_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(udp_comm_test_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(udp_comm_test_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(udp_comm_test_M));
    rtssSetStepSizePtr(sfcnInfo, &udp_comm_test_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(udp_comm_test_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &udp_comm_test_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &udp_comm_test_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &udp_comm_test_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &udp_comm_test_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &udp_comm_test_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &udp_comm_test_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &udp_comm_test_M->solverInfoPtr);
  }

  udp_comm_test_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)&udp_comm_test_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  5*sizeof(SimStruct));
    udp_comm_test_M->childSfunctions =
      (&udp_comm_test_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        udp_comm_test_M->childSfunctions[i] =
          (&udp_comm_test_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: udp_comm_test/<Root>/UDP Configure (slrtIPConfig) */
    {
      SimStruct *rts = udp_comm_test_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = udp_comm_test_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = udp_comm_test_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = udp_comm_test_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &udp_comm_test_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &udp_comm_test_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, udp_comm_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &udp_comm_test_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &udp_comm_test_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &udp_comm_test_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &udp_comm_test_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &udp_comm_test_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "UDP Configure");
      ssSetPath(rts, "udp_comm_test/UDP Configure");
      ssSetRTModel(rts,udp_comm_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)udp_comm_test_P.UDPConfigure_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)udp_comm_test_P.UDPConfigure_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)udp_comm_test_P.UDPConfigure_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)udp_comm_test_P.UDPConfigure_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)udp_comm_test_P.UDPConfigure_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)udp_comm_test_P.UDPConfigure_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)udp_comm_test_P.UDPConfigure_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)udp_comm_test_P.UDPConfigure_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)udp_comm_test_P.UDPConfigure_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)udp_comm_test_P.UDPConfigure_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)udp_comm_test_P.UDPConfigure_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)udp_comm_test_P.UDPConfigure_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &udp_comm_test_DW.UDPConfigure_IWORK[0]);
      ssSetPWork(rts, (void **) &udp_comm_test_DW.UDPConfigure_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &udp_comm_test_DW.UDPConfigure_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &udp_comm_test_DW.UDPConfigure_PWORK[0]);
      }

      /* registration */
      slrtIPConfig(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: udp_comm_test/<Root>/ASCII Encode 2 (asciiencode) */
    {
      SimStruct *rts = udp_comm_test_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = udp_comm_test_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = udp_comm_test_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = udp_comm_test_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &udp_comm_test_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &udp_comm_test_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, udp_comm_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &udp_comm_test_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &udp_comm_test_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &udp_comm_test_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &udp_comm_test_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &udp_comm_test_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 12);
        ssSetPortInfoForInputs(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
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
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
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
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &udp_comm_test_B.u;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &udp_comm_test_B.u_j;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs2;
          sfcnUPtrs[0] = &udp_comm_test_B.u_k;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs3;
          sfcnUPtrs[0] = &udp_comm_test_B.u_d;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs4;
          sfcnUPtrs[0] = &udp_comm_test_B.u_h;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs5;
          sfcnUPtrs[0] = &udp_comm_test_B.u_o;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs6;
          sfcnUPtrs[0] = &udp_comm_test_B.Add6;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs7;
          sfcnUPtrs[0] = &udp_comm_test_B.Add5;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }

        /* port 8 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs8;
          sfcnUPtrs[0] = &udp_comm_test_B.Add4;
          ssSetInputPortSignalPtrs(rts, 8, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 1);
        }

        /* port 9 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs9;
          sfcnUPtrs[0] = &udp_comm_test_B.Add3;
          ssSetInputPortSignalPtrs(rts, 9, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 9, 1);
          ssSetInputPortWidth(rts, 9, 1);
        }

        /* port 10 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs10;
          sfcnUPtrs[0] = &udp_comm_test_B.Add2;
          ssSetInputPortSignalPtrs(rts, 10, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 1);
        }

        /* port 11 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &udp_comm_test_M->NonInlinedSFcns.Sfcn1.UPtrs11;
          sfcnUPtrs[0] = &udp_comm_test_B.Add1;
          ssSetInputPortSignalPtrs(rts, 11, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 128);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            udp_comm_test_B.ASCIIEncode2));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Encode 2");
      ssSetPath(rts, "udp_comm_test/ASCII Encode 2");
      ssSetRTModel(rts,udp_comm_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)udp_comm_test_P.ASCIIEncode2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)udp_comm_test_P.ASCIIEncode2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)udp_comm_test_P.ASCIIEncode2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)udp_comm_test_P.ASCIIEncode2_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &udp_comm_test_DW.ASCIIEncode2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &udp_comm_test_DW.ASCIIEncode2_PWORK);
      }

      /* registration */
      asciiencode(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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

    /* Level2 S-Function Block: udp_comm_test/<Root>/UDP Send (slrtUDPSend) */
    {
      SimStruct *rts = udp_comm_test_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = udp_comm_test_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = udp_comm_test_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = udp_comm_test_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &udp_comm_test_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &udp_comm_test_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, udp_comm_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &udp_comm_test_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &udp_comm_test_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &udp_comm_test_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &udp_comm_test_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &udp_comm_test_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, udp_comm_test_B.ASCIIEncode2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 128);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &udp_comm_test_B.Constant3);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Send");
      ssSetPath(rts, "udp_comm_test/UDP Send");
      ssSetRTModel(rts,udp_comm_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)udp_comm_test_P.UDPSend_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)udp_comm_test_P.UDPSend_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)udp_comm_test_P.UDPSend_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)udp_comm_test_P.UDPSend_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)udp_comm_test_P.UDPSend_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)udp_comm_test_P.UDPSend_P6_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &udp_comm_test_DW.UDPSend_IWORK[0]);
      ssSetPWork(rts, (void **) &udp_comm_test_DW.UDPSend_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &udp_comm_test_DW.UDPSend_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &udp_comm_test_DW.UDPSend_PWORK);
      }

      /* registration */
      slrtUDPSend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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

    /* Level2 S-Function Block: udp_comm_test/<Root>/UDP Receive (slrtUDPReceive) */
    {
      SimStruct *rts = udp_comm_test_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = udp_comm_test_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = udp_comm_test_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = udp_comm_test_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &udp_comm_test_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &udp_comm_test_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, udp_comm_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &udp_comm_test_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &udp_comm_test_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &udp_comm_test_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &udp_comm_test_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &udp_comm_test_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 128);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            udp_comm_test_B.UDPReceive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &udp_comm_test_B.UDPReceive_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Receive");
      ssSetPath(rts, "udp_comm_test/UDP Receive");
      ssSetRTModel(rts,udp_comm_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)udp_comm_test_P.UDPReceive_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)udp_comm_test_P.UDPReceive_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)udp_comm_test_P.UDPReceive_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)udp_comm_test_P.UDPReceive_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)udp_comm_test_P.UDPReceive_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)udp_comm_test_P.UDPReceive_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)udp_comm_test_P.UDPReceive_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)udp_comm_test_P.UDPReceive_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)udp_comm_test_P.UDPReceive_P9_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &udp_comm_test_DW.UDPReceive_IWORK[0]);
      ssSetPWork(rts, (void **) &udp_comm_test_DW.UDPReceive_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &udp_comm_test_DW.UDPReceive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &udp_comm_test_DW.UDPReceive_PWORK[0]);
      }

      /* registration */
      slrtUDPReceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: udp_comm_test/<Root>/ASCII Decode  (asciidecode) */
    {
      SimStruct *rts = udp_comm_test_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = udp_comm_test_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = udp_comm_test_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = udp_comm_test_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &udp_comm_test_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &udp_comm_test_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, udp_comm_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &udp_comm_test_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &udp_comm_test_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &udp_comm_test_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &udp_comm_test_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &udp_comm_test_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, udp_comm_test_B.UDPReceive_o1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 128);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 12);
        _ssSetPortInfo2ForOutputUnits(rts,
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
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
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
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
            &udp_comm_test_B.ASCIIDecode_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((uint32_T *)
            &udp_comm_test_B.ASCIIDecode_o12));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Decode ");
      ssSetPath(rts, "udp_comm_test/ASCII Decode ");
      ssSetRTModel(rts,udp_comm_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)udp_comm_test_P.ASCIIDecode_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)udp_comm_test_P.ASCIIDecode_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)udp_comm_test_P.ASCIIDecode_P3_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &udp_comm_test_DW.ASCIIDecode_IWORK[0]);
      ssSetPWork(rts, (void **) &udp_comm_test_DW.ASCIIDecode_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &udp_comm_test_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &udp_comm_test_DW.ASCIIDecode_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &udp_comm_test_DW.ASCIIDecode_PWORK[0]);
      }

      /* registration */
      asciidecode(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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
  }

  /* Initialize Sizes */
  udp_comm_test_M->Sizes.numContStates = (0);/* Number of continuous states */
  udp_comm_test_M->Sizes.numY = (0);   /* Number of model outputs */
  udp_comm_test_M->Sizes.numU = (0);   /* Number of model inputs */
  udp_comm_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  udp_comm_test_M->Sizes.numSampTimes = (1);/* Number of sample times */
  udp_comm_test_M->Sizes.numBlocks = (40);/* Number of blocks */
  udp_comm_test_M->Sizes.numBlockIO = (28);/* Number of block outputs */
  udp_comm_test_M->Sizes.numBlockPrms = (260);/* Sum of parameter "widths" */
  return udp_comm_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
