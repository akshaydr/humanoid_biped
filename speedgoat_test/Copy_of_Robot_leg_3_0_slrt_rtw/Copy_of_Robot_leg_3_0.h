/*
 * Copy_of_Robot_leg_3_0.h
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

#ifndef RTW_HEADER_Copy_of_Robot_leg_3_0_h_
#define RTW_HEADER_Copy_of_Robot_leg_3_0_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef Copy_of_Robot_leg_3_0_COMMON_INCLUDES_
# define Copy_of_Robot_leg_3_0_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "nesl_rtw.h"
#include "Copy_of_Robot_leg_3_0_7d8ca6e_1_gateway.h"
#endif                                 /* Copy_of_Robot_leg_3_0_COMMON_INCLUDES_ */

#include "Copy_of_Robot_leg_3_0_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_Copy_of_Robot_leg_3_0  RT_MODEL_Copy_of_Robot_leg_3_0_T

/* Definition for use in the target main file */
#define Copy_of_Robot_leg_3_0_rtModel  RT_MODEL_Copy_of_Robot_leg_3_0_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<S4>/Switch Case Action Subsystem' */
typedef struct {
  real_T In1[6];                       /* '<S42>/In1' */
} B_SwitchCaseActionSubsystem_C_T;

/* Block states (default storage) for system '<S4>/Switch Case Action Subsystem' */
typedef struct {
  int8_T SwitchCaseActionSubsystem_Subsy;/* '<S4>/Switch Case Action Subsystem' */
} DW_SwitchCaseActionSubsystem__T;

/* Block signals (default storage) */
typedef struct {
  real_T Clock;                        /* '<S572>/Clock' */
  real_T Sum;                          /* '<S572>/Sum' */
  real_T MathFunction;                 /* '<S572>/Math Function' */
  real_T LookUpTable1;                 /* '<S572>/Look-Up Table1' */
  real_T Output;                       /* '<S572>/Output' */
  real_T INPUT_3_1_1[4];               /* '<S583>/INPUT_3_1_1' */
  real_T Clock_b;                      /* '<S4>/Clock' */
  real_T PulseGenerator;               /* '<S4>/Pulse Generator' */
  real_T TransportDelay[3];            /* '<S4>/Transport Delay' */
  real_T Add[3];                       /* '<S4>/Add' */
  real_T Gain2;                        /* '<S15>/Gain2' */
  real_T Gain5;                        /* '<S15>/Gain5' */
  real_T Gain1;                        /* '<S15>/Gain1' */
  real_T Gain4;                        /* '<S15>/Gain4' */
  real_T Gain3;                        /* '<S15>/Gain3' */
  real_T Gain;                         /* '<S15>/Gain' */
  real_T Gain2_f;                      /* '<S24>/Gain2' */
  real_T Gain5_n;                      /* '<S24>/Gain5' */
  real_T Gain1_g;                      /* '<S24>/Gain1' */
  real_T Gain4_o;                      /* '<S24>/Gain4' */
  real_T Gain3_a;                      /* '<S24>/Gain3' */
  real_T Gain_e;                       /* '<S24>/Gain' */
  real_T Clock_n;                      /* '<S574>/Clock' */
  real_T Sum_i;                        /* '<S574>/Sum' */
  real_T MathFunction_p;               /* '<S574>/Math Function' */
  real_T LookUpTable1_p;               /* '<S574>/Look-Up Table1' */
  real_T Output_f;                     /* '<S574>/Output' */
  real_T Add4;                         /* '<S29>/Add4' */
  real_T INPUT_2_1_1[4];               /* '<S583>/INPUT_2_1_1' */
  real_T Clock_e;                      /* '<S575>/Clock' */
  real_T Sum_c;                        /* '<S575>/Sum' */
  real_T MathFunction_m;               /* '<S575>/Math Function' */
  real_T LookUpTable1_h;               /* '<S575>/Look-Up Table1' */
  real_T Output_d;                     /* '<S575>/Output' */
  real_T INPUT_1_1_1[4];               /* '<S583>/INPUT_1_1_1' */
  real_T Clock_eu;                     /* '<S571>/Clock' */
  real_T Sum_a;                        /* '<S571>/Sum' */
  real_T MathFunction_d;               /* '<S571>/Math Function' */
  real_T LookUpTable1_j;               /* '<S571>/Look-Up Table1' */
  real_T Output_j;                     /* '<S571>/Output' */
  real_T Add5;                         /* '<S29>/Add5' */
  real_T INPUT_6_1_1[4];               /* '<S583>/INPUT_6_1_1' */
  real_T Clock_n0;                     /* '<S573>/Clock' */
  real_T Sum_f;                        /* '<S573>/Sum' */
  real_T MathFunction_dn;              /* '<S573>/Math Function' */
  real_T LookUpTable1_jm;              /* '<S573>/Look-Up Table1' */
  real_T Output_o;                     /* '<S573>/Output' */
  real_T INPUT_4_1_1[4];               /* '<S583>/INPUT_4_1_1' */
  real_T Clock_euk;                    /* '<S576>/Clock' */
  real_T Sum_fb;                       /* '<S576>/Sum' */
  real_T MathFunction_a;               /* '<S576>/Math Function' */
  real_T LookUpTable1_e;               /* '<S576>/Look-Up Table1' */
  real_T Output_jd;                    /* '<S576>/Output' */
  real_T Add6;                         /* '<S29>/Add6' */
  real_T INPUT_5_1_1[4];               /* '<S583>/INPUT_5_1_1' */
  real_T Clock_ny;                     /* '<S577>/Clock' */
  real_T Sum_e;                        /* '<S577>/Sum' */
  real_T MathFunction_dy;              /* '<S577>/Math Function' */
  real_T LookUpTable1_d;               /* '<S577>/Look-Up Table1' */
  real_T Output_h;                     /* '<S577>/Output' */
  real_T Add2;                         /* '<S29>/Add2' */
  real_T INPUT_28_1_1[4];              /* '<S583>/INPUT_28_1_1' */
  real_T Clock_ev;                     /* '<S578>/Clock' */
  real_T Sum_cc;                       /* '<S578>/Sum' */
  real_T MathFunction_pp;              /* '<S578>/Math Function' */
  real_T LookUpTable1_hj;              /* '<S578>/Look-Up Table1' */
  real_T Output_hw;                    /* '<S578>/Output' */
  real_T INPUT_25_1_1[4];              /* '<S583>/INPUT_25_1_1' */
  real_T Clock_p;                      /* '<S579>/Clock' */
  real_T Sum_k;                        /* '<S579>/Sum' */
  real_T MathFunction_h;               /* '<S579>/Math Function' */
  real_T LookUpTable1_dv;              /* '<S579>/Look-Up Table1' */
  real_T Output_p;                     /* '<S579>/Output' */
  real_T INPUT_26_1_1[4];              /* '<S583>/INPUT_26_1_1' */
  real_T Clock_bo;                     /* '<S580>/Clock' */
  real_T Sum_l;                        /* '<S580>/Sum' */
  real_T MathFunction_c;               /* '<S580>/Math Function' */
  real_T LookUpTable1_c;               /* '<S580>/Look-Up Table1' */
  real_T Output_fa;                    /* '<S580>/Output' */
  real_T Add1;                         /* '<S29>/Add1' */
  real_T INPUT_24_1_1[4];              /* '<S583>/INPUT_24_1_1' */
  real_T Clock_l;                      /* '<S581>/Clock' */
  real_T Sum_ff;                       /* '<S581>/Sum' */
  real_T MathFunction_l;               /* '<S581>/Math Function' */
  real_T LookUpTable1_k;               /* '<S581>/Look-Up Table1' */
  real_T Output_g;                     /* '<S581>/Output' */
  real_T INPUT_23_1_1[4];              /* '<S583>/INPUT_23_1_1' */
  real_T Clock_a;                      /* '<S582>/Clock' */
  real_T Sum_p;                        /* '<S582>/Sum' */
  real_T MathFunction_h5;              /* '<S582>/Math Function' */
  real_T LookUpTable1_l;               /* '<S582>/Look-Up Table1' */
  real_T Output_ds;                    /* '<S582>/Output' */
  real_T Add3;                         /* '<S29>/Add3' */
  real_T INPUT_27_1_1[4];              /* '<S583>/INPUT_27_1_1' */
  real_T STATE_1[13];                  /* '<S583>/STATE_1' */
  real_T OUTPUT_1_0[166];              /* '<S583>/OUTPUT_1_0' */
  real_T GAIN;                         /* '<S6>/GAIN' */
  real_T Gain_c;                       /* '<S379>/Gain' */
  real_T Abs;                          /* '<S379>/Abs' */
  real_T Gain1_f;                      /* '<S379>/Gain1' */
  real_T Abs1;                         /* '<S379>/Abs1' */
  real_T DataTypeConversion;           /* '<S379>/Data Type Conversion' */
  real_T RESHAPE[9];                   /* '<S420>/RESHAPE' */
  real_T Product[8];                   /* '<S381>/Product' */
  real_T Gain_f;                       /* '<S427>/Gain' */
  real_T Abs_g;                        /* '<S427>/Abs' */
  real_T Gain1_gt;                     /* '<S427>/Gain1' */
  real_T Abs1_o;                       /* '<S427>/Abs1' */
  real_T DataTypeConversion_m;         /* '<S427>/Data Type Conversion' */
  real_T RESHAPE_f[9];                 /* '<S468>/RESHAPE' */
  real_T Product_g[8];                 /* '<S429>/Product' */
  real_T Gain_j;                       /* '<S475>/Gain' */
  real_T Abs_e;                        /* '<S475>/Abs' */
  real_T Gain1_j;                      /* '<S475>/Gain1' */
  real_T Abs1_d;                       /* '<S475>/Abs1' */
  real_T DataTypeConversion_mc;        /* '<S475>/Data Type Conversion' */
  real_T RESHAPE_p[9];                 /* '<S516>/RESHAPE' */
  real_T Product_k[8];                 /* '<S477>/Product' */
  real_T Gain_p;                       /* '<S523>/Gain' */
  real_T Abs_d;                        /* '<S523>/Abs' */
  real_T Gain1_o;                      /* '<S523>/Gain1' */
  real_T Abs1_l;                       /* '<S523>/Abs1' */
  real_T DataTypeConversion_l;         /* '<S523>/Data Type Conversion' */
  real_T RESHAPE_j[9];                 /* '<S564>/RESHAPE' */
  real_T Product_f[8];                 /* '<S525>/Product' */
  real_T NormalForce;                  /* '<S312>/Add' */
  real_T Add1_f[3];                    /* '<S312>/Add1' */
  real_T MathFunction_g[3];            /* '<S312>/Math Function' */
  real_T SumofElements;                /* '<S312>/Sum of Elements' */
  real_T FrictionForce;                /* '<S312>/Sqrt' */
  real_T GAIN_e;                       /* '<S352>/GAIN' */
  real_T Gain_p1;                      /* '<S115>/Gain' */
  real_T Abs_f;                        /* '<S115>/Abs' */
  real_T Gain1_b;                      /* '<S115>/Gain1' */
  real_T Abs1_k;                       /* '<S115>/Abs1' */
  real_T DataTypeConversion_a;         /* '<S115>/Data Type Conversion' */
  real_T RESHAPE_l[9];                 /* '<S156>/RESHAPE' */
  real_T FSph[12];                     /* '<S58>/Merge' */
  real_T INPUT_10_1_1[4];              /* '<S583>/INPUT_10_1_1' */
  real_T INPUT_10_1_2[4];              /* '<S583>/INPUT_10_1_2' */
  real_T INPUT_10_1_3[4];              /* '<S583>/INPUT_10_1_3' */
  real_T INPUT_9_1_1[4];               /* '<S583>/INPUT_9_1_1' */
  real_T INPUT_9_1_2[4];               /* '<S583>/INPUT_9_1_2' */
  real_T INPUT_9_1_3[4];               /* '<S583>/INPUT_9_1_3' */
  real_T INPUT_7_1_1[4];               /* '<S583>/INPUT_7_1_1' */
  real_T INPUT_7_1_2[4];               /* '<S583>/INPUT_7_1_2' */
  real_T INPUT_7_1_3[4];               /* '<S583>/INPUT_7_1_3' */
  real_T INPUT_8_1_1[4];               /* '<S583>/INPUT_8_1_1' */
  real_T INPUT_8_1_2[4];               /* '<S583>/INPUT_8_1_2' */
  real_T INPUT_8_1_3[4];               /* '<S583>/INPUT_8_1_3' */
  real_T Gain_m;                       /* '<S163>/Gain' */
  real_T Abs_k;                        /* '<S163>/Abs' */
  real_T Gain1_n;                      /* '<S163>/Gain1' */
  real_T Abs1_o2;                      /* '<S163>/Abs1' */
  real_T DataTypeConversion_p;         /* '<S163>/Data Type Conversion' */
  real_T RESHAPE_b[9];                 /* '<S204>/RESHAPE' */
  real_T FSph_m[12];                   /* '<S59>/Merge' */
  real_T INPUT_14_1_1[4];              /* '<S583>/INPUT_14_1_1' */
  real_T INPUT_14_1_2[4];              /* '<S583>/INPUT_14_1_2' */
  real_T INPUT_14_1_3[4];              /* '<S583>/INPUT_14_1_3' */
  real_T INPUT_13_1_1[4];              /* '<S583>/INPUT_13_1_1' */
  real_T INPUT_13_1_2[4];              /* '<S583>/INPUT_13_1_2' */
  real_T INPUT_13_1_3[4];              /* '<S583>/INPUT_13_1_3' */
  real_T INPUT_11_1_1[4];              /* '<S583>/INPUT_11_1_1' */
  real_T INPUT_11_1_2[4];              /* '<S583>/INPUT_11_1_2' */
  real_T INPUT_11_1_3[4];              /* '<S583>/INPUT_11_1_3' */
  real_T INPUT_12_1_1[4];              /* '<S583>/INPUT_12_1_1' */
  real_T INPUT_12_1_2[4];              /* '<S583>/INPUT_12_1_2' */
  real_T INPUT_12_1_3[4];              /* '<S583>/INPUT_12_1_3' */
  real_T Gain_g;                       /* '<S211>/Gain' */
  real_T Abs_n;                        /* '<S211>/Abs' */
  real_T Gain1_gi;                     /* '<S211>/Gain1' */
  real_T Abs1_n;                       /* '<S211>/Abs1' */
  real_T DataTypeConversion_b;         /* '<S211>/Data Type Conversion' */
  real_T RESHAPE_j1[9];                /* '<S252>/RESHAPE' */
  real_T FSph_l[12];                   /* '<S60>/Merge' */
  real_T INPUT_18_1_1[4];              /* '<S583>/INPUT_18_1_1' */
  real_T INPUT_18_1_2[4];              /* '<S583>/INPUT_18_1_2' */
  real_T INPUT_18_1_3[4];              /* '<S583>/INPUT_18_1_3' */
  real_T INPUT_17_1_1[4];              /* '<S583>/INPUT_17_1_1' */
  real_T INPUT_17_1_2[4];              /* '<S583>/INPUT_17_1_2' */
  real_T INPUT_17_1_3[4];              /* '<S583>/INPUT_17_1_3' */
  real_T INPUT_15_1_1[4];              /* '<S583>/INPUT_15_1_1' */
  real_T INPUT_15_1_2[4];              /* '<S583>/INPUT_15_1_2' */
  real_T INPUT_15_1_3[4];              /* '<S583>/INPUT_15_1_3' */
  real_T INPUT_16_1_1[4];              /* '<S583>/INPUT_16_1_1' */
  real_T INPUT_16_1_2[4];              /* '<S583>/INPUT_16_1_2' */
  real_T INPUT_16_1_3[4];              /* '<S583>/INPUT_16_1_3' */
  real_T Gain_m5;                      /* '<S259>/Gain' */
  real_T Abs_ff;                       /* '<S259>/Abs' */
  real_T Gain1_c;                      /* '<S259>/Gain1' */
  real_T Abs1_b;                       /* '<S259>/Abs1' */
  real_T DataTypeConversion_bu;        /* '<S259>/Data Type Conversion' */
  real_T RESHAPE_jw[9];                /* '<S300>/RESHAPE' */
  real_T FSph_a[12];                   /* '<S61>/Merge' */
  real_T INPUT_22_1_1[4];              /* '<S583>/INPUT_22_1_1' */
  real_T INPUT_22_1_2[4];              /* '<S583>/INPUT_22_1_2' */
  real_T INPUT_22_1_3[4];              /* '<S583>/INPUT_22_1_3' */
  real_T INPUT_21_1_1[4];              /* '<S583>/INPUT_21_1_1' */
  real_T INPUT_21_1_2[4];              /* '<S583>/INPUT_21_1_2' */
  real_T INPUT_21_1_3[4];              /* '<S583>/INPUT_21_1_3' */
  real_T INPUT_19_1_1[4];              /* '<S583>/INPUT_19_1_1' */
  real_T INPUT_19_1_2[4];              /* '<S583>/INPUT_19_1_2' */
  real_T INPUT_19_1_3[4];              /* '<S583>/INPUT_19_1_3' */
  real_T INPUT_20_1_1[4];              /* '<S583>/INPUT_20_1_1' */
  real_T INPUT_20_1_2[4];              /* '<S583>/INPUT_20_1_2' */
  real_T INPUT_20_1_3[4];              /* '<S583>/INPUT_20_1_3' */
  real_T FSph_i[12];                   /* '<S322>/Merge' */
  real_T INPUT_32_1_1[4];              /* '<S583>/INPUT_32_1_1' */
  real_T INPUT_32_1_2[4];              /* '<S583>/INPUT_32_1_2' */
  real_T INPUT_32_1_3[4];              /* '<S583>/INPUT_32_1_3' */
  real_T INPUT_31_1_1[4];              /* '<S583>/INPUT_31_1_1' */
  real_T INPUT_31_1_2[4];              /* '<S583>/INPUT_31_1_2' */
  real_T INPUT_31_1_3[4];              /* '<S583>/INPUT_31_1_3' */
  real_T INPUT_29_1_1[4];              /* '<S583>/INPUT_29_1_1' */
  real_T INPUT_29_1_2[4];              /* '<S583>/INPUT_29_1_2' */
  real_T INPUT_29_1_3[4];              /* '<S583>/INPUT_29_1_3' */
  real_T INPUT_30_1_1[4];              /* '<S583>/INPUT_30_1_1' */
  real_T INPUT_30_1_2[4];              /* '<S583>/INPUT_30_1_2' */
  real_T INPUT_30_1_3[4];              /* '<S583>/INPUT_30_1_3' */
  real_T FSph_mf[12];                  /* '<S323>/Merge' */
  real_T INPUT_36_1_1[4];              /* '<S583>/INPUT_36_1_1' */
  real_T INPUT_36_1_2[4];              /* '<S583>/INPUT_36_1_2' */
  real_T INPUT_36_1_3[4];              /* '<S583>/INPUT_36_1_3' */
  real_T INPUT_35_1_1[4];              /* '<S583>/INPUT_35_1_1' */
  real_T INPUT_35_1_2[4];              /* '<S583>/INPUT_35_1_2' */
  real_T INPUT_35_1_3[4];              /* '<S583>/INPUT_35_1_3' */
  real_T INPUT_33_1_1[4];              /* '<S583>/INPUT_33_1_1' */
  real_T INPUT_33_1_2[4];              /* '<S583>/INPUT_33_1_2' */
  real_T INPUT_33_1_3[4];              /* '<S583>/INPUT_33_1_3' */
  real_T INPUT_34_1_1[4];              /* '<S583>/INPUT_34_1_1' */
  real_T INPUT_34_1_2[4];              /* '<S583>/INPUT_34_1_2' */
  real_T INPUT_34_1_3[4];              /* '<S583>/INPUT_34_1_3' */
  real_T FSph_a0[12];                  /* '<S324>/Merge' */
  real_T INPUT_40_1_1[4];              /* '<S583>/INPUT_40_1_1' */
  real_T INPUT_40_1_2[4];              /* '<S583>/INPUT_40_1_2' */
  real_T INPUT_40_1_3[4];              /* '<S583>/INPUT_40_1_3' */
  real_T INPUT_39_1_1[4];              /* '<S583>/INPUT_39_1_1' */
  real_T INPUT_39_1_2[4];              /* '<S583>/INPUT_39_1_2' */
  real_T INPUT_39_1_3[4];              /* '<S583>/INPUT_39_1_3' */
  real_T INPUT_37_1_1[4];              /* '<S583>/INPUT_37_1_1' */
  real_T INPUT_37_1_2[4];              /* '<S583>/INPUT_37_1_2' */
  real_T INPUT_37_1_3[4];              /* '<S583>/INPUT_37_1_3' */
  real_T INPUT_38_1_1[4];              /* '<S583>/INPUT_38_1_1' */
  real_T INPUT_38_1_2[4];              /* '<S583>/INPUT_38_1_2' */
  real_T INPUT_38_1_3[4];              /* '<S583>/INPUT_38_1_3' */
  real_T FSph_n[12];                   /* '<S325>/Merge' */
  real_T INPUT_44_1_1[4];              /* '<S583>/INPUT_44_1_1' */
  real_T INPUT_44_1_2[4];              /* '<S583>/INPUT_44_1_2' */
  real_T INPUT_44_1_3[4];              /* '<S583>/INPUT_44_1_3' */
  real_T INPUT_43_1_1[4];              /* '<S583>/INPUT_43_1_1' */
  real_T INPUT_43_1_2[4];              /* '<S583>/INPUT_43_1_2' */
  real_T INPUT_43_1_3[4];              /* '<S583>/INPUT_43_1_3' */
  real_T INPUT_41_1_1[4];              /* '<S583>/INPUT_41_1_1' */
  real_T INPUT_41_1_2[4];              /* '<S583>/INPUT_41_1_2' */
  real_T INPUT_41_1_3[4];              /* '<S583>/INPUT_41_1_3' */
  real_T INPUT_42_1_1[4];              /* '<S583>/INPUT_42_1_1' */
  real_T INPUT_42_1_2[4];              /* '<S583>/INPUT_42_1_2' */
  real_T INPUT_42_1_3[4];              /* '<S583>/INPUT_42_1_3' */
  real_T OUTPUT_1_1[12];               /* '<S583>/OUTPUT_1_1' */
  real_T GAIN_h;                       /* '<S346>/GAIN' */
  real_T GAIN_d;                       /* '<S364>/GAIN' */
  real_T GAIN_i;                       /* '<S358>/GAIN' */
  real_T GAIN_hs;                      /* '<S334>/GAIN' */
  real_T GAIN_p;                       /* '<S370>/GAIN' */
  real_T Product_d[8];                 /* '<S117>/Product' */
  real_T Product_m[8];                 /* '<S165>/Product' */
  real_T Product_e[8];                 /* '<S213>/Product' */
  real_T Product_j[8];                 /* '<S261>/Product' */
  real_T NormalForce_i;                /* '<S48>/Add' */
  real_T Add1_i[3];                    /* '<S48>/Add1' */
  real_T MathFunction_i[3];            /* '<S48>/Math Function' */
  real_T SumofElements_l;              /* '<S48>/Sum of Elements' */
  real_T FrictionForce_k;              /* '<S48>/Sqrt' */
  real_T GAIN_dq;                      /* '<S88>/GAIN' */
  real_T GAIN_b;                       /* '<S82>/GAIN' */
  real_T GAIN_eg;                      /* '<S100>/GAIN' */
  real_T GAIN_hq;                      /* '<S94>/GAIN' */
  real_T GAIN_m;                       /* '<S70>/GAIN' */
  real_T GAIN_em;                      /* '<S106>/GAIN' */
  real_T GAIN_l[3];                    /* '<S307>/GAIN' */
  real_T Clock_lc;                     /* '<S9>/Clock' */
  real_T Sum_er;                       /* '<S9>/Sum' */
  real_T MathFunction_b;               /* '<S9>/Math Function' */
  real_T LookUpTable1_hv;              /* '<S9>/Look-Up Table1' */
  real_T Output_k;                     /* '<S9>/Output' */
  real_T Clock_b5;                     /* '<S10>/Clock' */
  real_T Sum_eb;                       /* '<S10>/Sum' */
  real_T MathFunction_bl;              /* '<S10>/Math Function' */
  real_T LookUpTable1_l4;              /* '<S10>/Look-Up Table1' */
  real_T Output_h2;                    /* '<S10>/Output' */
  real_T Clock_i;                      /* '<S11>/Clock' */
  real_T Sum_o;                        /* '<S11>/Sum' */
  real_T MathFunction_gl;              /* '<S11>/Math Function' */
  real_T LookUpTable1_pq;              /* '<S11>/Look-Up Table1' */
  real_T Output_dc;                    /* '<S11>/Output' */
  real_T Clock_d;                      /* '<S12>/Clock' */
  real_T Sum_d;                        /* '<S12>/Sum' */
  real_T MathFunction_hx;              /* '<S12>/Math Function' */
  real_T LookUpTable1_pv;              /* '<S12>/Look-Up Table1' */
  real_T Output_n;                     /* '<S12>/Output' */
  real_T Clock_h;                      /* '<S13>/Clock' */
  real_T Sum_m;                        /* '<S13>/Sum' */
  real_T MathFunction_cx;              /* '<S13>/Math Function' */
  real_T LookUpTable1_m;               /* '<S13>/Look-Up Table1' */
  real_T Output_i;                     /* '<S13>/Output' */
  real_T Clock_hr;                     /* '<S14>/Clock' */
  real_T Sum_j;                        /* '<S14>/Sum' */
  real_T MathFunction_l4;              /* '<S14>/Math Function' */
  real_T LookUpTable1_du;              /* '<S14>/Look-Up Table1' */
  real_T Output_e;                     /* '<S14>/Output' */
  real_T Clock_f;                      /* '<S18>/Clock' */
  real_T Sum_a5;                       /* '<S18>/Sum' */
  real_T MathFunction_j;               /* '<S18>/Math Function' */
  real_T LookUpTable1_b;               /* '<S18>/Look-Up Table1' */
  real_T Output_b;                     /* '<S18>/Output' */
  real_T Clock_lw;                     /* '<S19>/Clock' */
  real_T Sum_n;                        /* '<S19>/Sum' */
  real_T MathFunction_ar;              /* '<S19>/Math Function' */
  real_T LookUpTable1_i;               /* '<S19>/Look-Up Table1' */
  real_T Output_nc;                    /* '<S19>/Output' */
  real_T Clock_ly;                     /* '<S20>/Clock' */
  real_T Sum_me;                       /* '<S20>/Sum' */
  real_T MathFunction_f;               /* '<S20>/Math Function' */
  real_T LookUpTable1_iy;              /* '<S20>/Look-Up Table1' */
  real_T Output_f3;                    /* '<S20>/Output' */
  real_T Clock_ao;                     /* '<S21>/Clock' */
  real_T Sum_ebu;                      /* '<S21>/Sum' */
  real_T MathFunction_k;               /* '<S21>/Math Function' */
  real_T LookUpTable1_ba;              /* '<S21>/Look-Up Table1' */
  real_T Output_kh;                    /* '<S21>/Output' */
  real_T Clock_c;                      /* '<S22>/Clock' */
  real_T Sum_ez;                       /* '<S22>/Sum' */
  real_T MathFunction_m0;              /* '<S22>/Math Function' */
  real_T LookUpTable1_cs;              /* '<S22>/Look-Up Table1' */
  real_T Output_fc;                    /* '<S22>/Output' */
  real_T Clock_o;                      /* '<S23>/Clock' */
  real_T Sum_b;                        /* '<S23>/Sum' */
  real_T MathFunction_lq;              /* '<S23>/Math Function' */
  real_T LookUpTable1_mf;              /* '<S23>/Look-Up Table1' */
  real_T Output_l;                     /* '<S23>/Output' */
  real_T Gain_o;                       /* '<S30>/Gain' */
  real_T Add_g;                        /* '<S30>/Add' */
  real_T Gain_h;                       /* '<S32>/Gain' */
  real_T Add_j;                        /* '<S32>/Add' */
  real_T Gain_jh;                      /* '<S31>/Gain' */
  real_T Add_l;                        /* '<S31>/Add' */
  real_T Gain_k;                       /* '<S33>/Gain' */
  real_T Add_n;                        /* '<S33>/Add' */
  real_T Gain_js;                      /* '<S41>/Gain' */
  real_T Add_b;                        /* '<S41>/Add' */
  real_T Gain_jw;                      /* '<S40>/Gain' */
  real_T Add_a;                        /* '<S40>/Add' */
  real_T Gain_gb;                      /* '<S39>/Gain' */
  real_T Add_jp;                       /* '<S39>/Add' */
  real_T Gain_i;                       /* '<S38>/Gain' */
  real_T Add_jr;                       /* '<S38>/Add' */
  real_T Gain_gp;                      /* '<S37>/Gain' */
  real_T Add_i;                        /* '<S37>/Add' */
  real_T Gain_b;                       /* '<S36>/Gain' */
  real_T Add_aa;                       /* '<S36>/Add' */
  real_T Gain_i3;                      /* '<S35>/Gain' */
  real_T Add_by;                       /* '<S35>/Add' */
  real_T Gain_fj;                      /* '<S34>/Gain' */
  real_T Add_i5;                       /* '<S34>/Add' */
  real_T Constant3;                    /* '<S4>/Constant3' */
  real_T Abs_c;                        /* '<S539>/Abs' */
  real_T Sum_ml;                       /* '<S539>/Sum' */
  real_T DeadZone;                     /* '<S539>/Dead Zone' */
  real_T Signx;                        /* '<S539>/Sign x' */
  real_T Product_b;                    /* '<S539>/Product' */
  real_T Gain2_i;                      /* '<S539>/Gain2' */
  real_T Signvx;                       /* '<S539>/Sign vx' */
  real_T Stiffness_Force;              /* '<S550>/Gain1' */
  real_T SprForce;                     /* '<S526>/Product' */
  real_T Sign;                         /* '<S550>/Sign' */
  real_T Damping_Force_Enable;         /* '<S550>/Abs' */
  real_T Saturation;                   /* '<S550>/Saturation' */
  real_T Damping_Force;                /* '<S550>/Gain2' */
  real_T Damping_Force_n;              /* '<S550>/Product' */
  real_T DampForce;                    /* '<S526>/Product1' */
  real_T Sum_kn;                       /* '<S542>/Sum' */
  real_T TmpSignalConversionAtProduct2In[3];
  real_T Gain_mv[3];                   /* '<S542>/Gain' */
  real_T Product3;                     /* '<S546>/Product3' */
  real_T Product5;                     /* '<S541>/Product5' */
  real_T slipy;                        /* '<S546>/Sum1' */
  real_T MathFunction_mn;              /* '<S546>/Math Function' */
  real_T Product4;                     /* '<S546>/Product4' */
  real_T Product6;                     /* '<S541>/Product6' */
  real_T slipx;                        /* '<S546>/Sum2' */
  real_T MathFunction1;                /* '<S546>/Math Function1' */
  real_T Sum3;                         /* '<S546>/Sum3' */
  real_T Sqrt;                         /* '<S546>/Sqrt' */
  real_T CoefficientofFrictionvsVelocity;/* '<S548>/Coefficient of Friction vs Velocity' */
  real_T Product_ke;                   /* '<S548>/Product' */
  real_T Friction_Force;               /* '<S548>/Gain2' */
  real_T TrigonometricFunction;        /* '<S546>/Trigonometric Function' */
  real_T TrigonometricFunction1;       /* '<S541>/Trigonometric Function1' */
  real_T Product3_g;                   /* '<S541>/Product3' */
  real_T TrigonometricFunction_d;      /* '<S541>/Trigonometric Function' */
  real_T Product4_k;                   /* '<S541>/Product4' */
  real_T TmpSignalConversionAtProduct1In[3];
  real_T Gain_b5[3];                   /* '<S541>/Gain' */
  real_T FPla[3];                      /* '<S526>/Sum1' */
  real_T Product_jb;                   /* '<S540>/Product' */
  real_T Product1;                     /* '<S540>/Product1' */
  real_T Product2;                     /* '<S540>/Product2' */
  real_T Product3_m;                   /* '<S540>/Product3' */
  real_T Product4_b;                   /* '<S540>/Product4' */
  real_T Product5_h;                   /* '<S540>/Product5' */
  real_T Product7[3];                  /* '<S541>/Product7' */
  real_T Product_eg;                   /* '<S544>/Product' */
  real_T Product1_c;                   /* '<S544>/Product1' */
  real_T Product2_n;                   /* '<S544>/Product2' */
  real_T Product3_a;                   /* '<S544>/Product3' */
  real_T Product4_c;                   /* '<S544>/Product4' */
  real_T Product5_j;                   /* '<S544>/Product5' */
  real_T Sum_m4;                       /* '<S544>/Sum' */
  real_T Sum1;                         /* '<S544>/Sum1' */
  real_T Sum2;                         /* '<S544>/Sum2' */
  real_T Product1_i[3];                /* '<S541>/Product1' */
  real_T TmpSignalConversionAtProduct2_h[3];/* '<S541>/Cross Product' */
  real_T Product2_j[3];                /* '<S542>/Product2' */
  real_T Abs_i;                        /* '<S491>/Abs' */
  real_T Sum_lb;                       /* '<S491>/Sum' */
  real_T DeadZone_b;                   /* '<S491>/Dead Zone' */
  real_T Signx_l;                      /* '<S491>/Sign x' */
  real_T Product_i;                    /* '<S491>/Product' */
  real_T Gain2_g;                      /* '<S491>/Gain2' */
  real_T Signvx_a;                     /* '<S491>/Sign vx' */
  real_T Stiffness_Force_m;            /* '<S502>/Gain1' */
  real_T SprForce_j;                   /* '<S478>/Product' */
  real_T Sign_k;                       /* '<S502>/Sign' */
  real_T Damping_Force_Enable_b;       /* '<S502>/Abs' */
  real_T Saturation_j;                 /* '<S502>/Saturation' */
  real_T Damping_Force_p;              /* '<S502>/Gain2' */
  real_T Damping_Force_nm;             /* '<S502>/Product' */
  real_T DampForce_j;                  /* '<S478>/Product1' */
  real_T Sum_kg;                       /* '<S494>/Sum' */
  real_T TmpSignalConversionAtProduct2_o[3];
  real_T Gain_cq[3];                   /* '<S494>/Gain' */
  real_T Product3_e;                   /* '<S498>/Product3' */
  real_T Product5_ha;                  /* '<S493>/Product5' */
  real_T slipy_e;                      /* '<S498>/Sum1' */
  real_T MathFunction_o;               /* '<S498>/Math Function' */
  real_T Product4_p;                   /* '<S498>/Product4' */
  real_T Product6_g;                   /* '<S493>/Product6' */
  real_T slipx_k;                      /* '<S498>/Sum2' */
  real_T MathFunction1_n;              /* '<S498>/Math Function1' */
  real_T Sum3_p;                       /* '<S498>/Sum3' */
  real_T Sqrt_l;                       /* '<S498>/Sqrt' */
  real_T CoefficientofFrictionvsVeloci_e;/* '<S500>/Coefficient of Friction vs Velocity' */
  real_T Product_bb;                   /* '<S500>/Product' */
  real_T Friction_Force_i;             /* '<S500>/Gain2' */
  real_T TrigonometricFunction_l;      /* '<S498>/Trigonometric Function' */
  real_T TrigonometricFunction1_g;     /* '<S493>/Trigonometric Function1' */
  real_T Product3_l;                   /* '<S493>/Product3' */
  real_T TrigonometricFunction_j;      /* '<S493>/Trigonometric Function' */
  real_T Product4_po;                  /* '<S493>/Product4' */
  real_T TmpSignalConversionAtProduct1_h[3];
  real_T Gain_cp[3];                   /* '<S493>/Gain' */
  real_T FPla_o[3];                    /* '<S478>/Sum1' */
  real_T Product_n;                    /* '<S492>/Product' */
  real_T Product1_h;                   /* '<S492>/Product1' */
  real_T Product2_o;                   /* '<S492>/Product2' */
  real_T Product3_h;                   /* '<S492>/Product3' */
  real_T Product4_e;                   /* '<S492>/Product4' */
  real_T Product5_jd;                  /* '<S492>/Product5' */
  real_T Product7_a[3];                /* '<S493>/Product7' */
  real_T Product_bbt;                  /* '<S496>/Product' */
  real_T Product1_h1;                  /* '<S496>/Product1' */
  real_T Product2_a;                   /* '<S496>/Product2' */
  real_T Product3_i;                   /* '<S496>/Product3' */
  real_T Product4_f;                   /* '<S496>/Product4' */
  real_T Product5_ju;                  /* '<S496>/Product5' */
  real_T Sum_g;                        /* '<S496>/Sum' */
  real_T Sum1_j;                       /* '<S496>/Sum1' */
  real_T Sum2_e;                       /* '<S496>/Sum2' */
  real_T Product1_cp[3];               /* '<S493>/Product1' */
  real_T TmpSignalConversionAtProduct2_c[3];/* '<S493>/Cross Product' */
  real_T Product2_m[3];                /* '<S494>/Product2' */
  real_T Abs_db;                       /* '<S443>/Abs' */
  real_T Sum_pm;                       /* '<S443>/Sum' */
  real_T DeadZone_a;                   /* '<S443>/Dead Zone' */
  real_T Signx_o;                      /* '<S443>/Sign x' */
  real_T Product_jh;                   /* '<S443>/Product' */
  real_T Gain2_m;                      /* '<S443>/Gain2' */
  real_T Signvx_c;                     /* '<S443>/Sign vx' */
  real_T Stiffness_Force_i;            /* '<S454>/Gain1' */
  real_T SprForce_n;                   /* '<S430>/Product' */
  real_T Sign_l;                       /* '<S454>/Sign' */
  real_T Damping_Force_Enable_d;       /* '<S454>/Abs' */
  real_T Saturation_f;                 /* '<S454>/Saturation' */
  real_T Damping_Force_c;              /* '<S454>/Gain2' */
  real_T Damping_Force_o;              /* '<S454>/Product' */
  real_T DampForce_c;                  /* '<S430>/Product1' */
  real_T Sum_o3;                       /* '<S446>/Sum' */
  real_T TmpSignalConversionAtProduct_ol[3];
  real_T Gain_a[3];                    /* '<S446>/Gain' */
  real_T Product3_f;                   /* '<S450>/Product3' */
  real_T Product5_m;                   /* '<S445>/Product5' */
  real_T slipy_a;                      /* '<S450>/Sum1' */
  real_T MathFunction_mw;              /* '<S450>/Math Function' */
  real_T Product4_ft;                  /* '<S450>/Product4' */
  real_T Product6_d;                   /* '<S445>/Product6' */
  real_T slipx_h;                      /* '<S450>/Sum2' */
  real_T MathFunction1_j;              /* '<S450>/Math Function1' */
  real_T Sum3_i;                       /* '<S450>/Sum3' */
  real_T Sqrt_f;                       /* '<S450>/Sqrt' */
  real_T CoefficientofFrictionvsVeloci_c;/* '<S452>/Coefficient of Friction vs Velocity' */
  real_T Product_p;                    /* '<S452>/Product' */
  real_T Friction_Force_b;             /* '<S452>/Gain2' */
  real_T TrigonometricFunction_j1;     /* '<S450>/Trigonometric Function' */
  real_T TrigonometricFunction1_o;     /* '<S445>/Trigonometric Function1' */
  real_T Product3_gs;                  /* '<S445>/Product3' */
  real_T TrigonometricFunction_js;     /* '<S445>/Trigonometric Function' */
  real_T Product4_d;                   /* '<S445>/Product4' */
  real_T TmpSignalConversionAtProduct1_d[3];
  real_T Gain_ph[3];                   /* '<S445>/Gain' */
  real_T FPla_a[3];                    /* '<S430>/Sum1' */
  real_T Product_o;                    /* '<S444>/Product' */
  real_T Product1_k;                   /* '<S444>/Product1' */
  real_T Product2_h;                   /* '<S444>/Product2' */
  real_T Product3_n;                   /* '<S444>/Product3' */
  real_T Product4_ew;                  /* '<S444>/Product4' */
  real_T Product5_n;                   /* '<S444>/Product5' */
  real_T Product7_p[3];                /* '<S445>/Product7' */
  real_T Product_nx;                   /* '<S448>/Product' */
  real_T Product1_b;                   /* '<S448>/Product1' */
  real_T Product2_hx;                  /* '<S448>/Product2' */
  real_T Product3_hs;                  /* '<S448>/Product3' */
  real_T Product4_bz;                  /* '<S448>/Product4' */
  real_T Product5_i;                   /* '<S448>/Product5' */
  real_T Sum_mh;                       /* '<S448>/Sum' */
  real_T Sum1_e;                       /* '<S448>/Sum1' */
  real_T Sum2_m;                       /* '<S448>/Sum2' */
  real_T Product1_o[3];                /* '<S445>/Product1' */
  real_T TmpSignalConversionAtProduct2_p[3];/* '<S445>/Cross Product' */
  real_T Product2_hxv[3];              /* '<S446>/Product2' */
  real_T Abs_a;                        /* '<S395>/Abs' */
  real_T Sum_p0;                       /* '<S395>/Sum' */
  real_T DeadZone_e;                   /* '<S395>/Dead Zone' */
  real_T Signx_h;                      /* '<S395>/Sign x' */
  real_T Product_br;                   /* '<S395>/Product' */
  real_T Gain2_k;                      /* '<S395>/Gain2' */
  real_T Signvx_e;                     /* '<S395>/Sign vx' */
  real_T Stiffness_Force_k;            /* '<S406>/Gain1' */
  real_T SprForce_p;                   /* '<S382>/Product' */
  real_T Sign_b;                       /* '<S406>/Sign' */
  real_T Damping_Force_Enable_k;       /* '<S406>/Abs' */
  real_T Saturation_e;                 /* '<S406>/Saturation' */
  real_T Damping_Force_e;              /* '<S406>/Gain2' */
  real_T Damping_Force_cz;             /* '<S406>/Product' */
  real_T DampForce_h;                  /* '<S382>/Product1' */
  real_T Sum_kge;                      /* '<S398>/Sum' */
  real_T TmpSignalConversionAtProduct2_b[3];
  real_T Gain_ii[3];                   /* '<S398>/Gain' */
  real_T Product3_p;                   /* '<S402>/Product3' */
  real_T Product5_ij;                  /* '<S397>/Product5' */
  real_T slipy_c;                      /* '<S402>/Sum1' */
  real_T MathFunction_c2;              /* '<S402>/Math Function' */
  real_T Product4_l;                   /* '<S402>/Product4' */
  real_T Product6_l;                   /* '<S397>/Product6' */
  real_T slipx_c;                      /* '<S402>/Sum2' */
  real_T MathFunction1_a;              /* '<S402>/Math Function1' */
  real_T Sum3_d;                       /* '<S402>/Sum3' */
  real_T Sqrt_m;                       /* '<S402>/Sqrt' */
  real_T CoefficientofFrictionvsVeloc_cu;/* '<S404>/Coefficient of Friction vs Velocity' */
  real_T Product_a;                    /* '<S404>/Product' */
  real_T Friction_Force_l;             /* '<S404>/Gain2' */
  real_T TrigonometricFunction_i;      /* '<S402>/Trigonometric Function' */
  real_T TrigonometricFunction1_k;     /* '<S397>/Trigonometric Function1' */
  real_T Product3_l1;                  /* '<S397>/Product3' */
  real_T TrigonometricFunction_c;      /* '<S397>/Trigonometric Function' */
  real_T Product4_a;                   /* '<S397>/Product4' */
  real_T TmpSignalConversionAtProduct1_g[3];
  real_T Gain_jd[3];                   /* '<S397>/Gain' */
  real_T FPla_h[3];                    /* '<S382>/Sum1' */
  real_T Product_np;                   /* '<S396>/Product' */
  real_T Product1_cpr;                 /* '<S396>/Product1' */
  real_T Product2_i;                   /* '<S396>/Product2' */
  real_T Product3_gk;                  /* '<S396>/Product3' */
  real_T Product4_p4;                  /* '<S396>/Product4' */
  real_T Product5_k;                   /* '<S396>/Product5' */
  real_T Product7_b[3];                /* '<S397>/Product7' */
  real_T Product_bl;                   /* '<S400>/Product' */
  real_T Product1_ik;                  /* '<S400>/Product1' */
  real_T Product2_b;                   /* '<S400>/Product2' */
  real_T Product3_d;                   /* '<S400>/Product3' */
  real_T Product4_cw;                  /* '<S400>/Product4' */
  real_T Product5_e;                   /* '<S400>/Product5' */
  real_T Sum_ph;                       /* '<S400>/Sum' */
  real_T Sum1_c;                       /* '<S400>/Sum1' */
  real_T Sum2_h;                       /* '<S400>/Sum2' */
  real_T Product1_oi[3];               /* '<S397>/Product1' */
  real_T TmpSignalConversionAtProduct2_m[3];/* '<S397>/Cross Product' */
  real_T Product2_j2[3];               /* '<S398>/Product2' */
  real_T Abs_g4;                       /* '<S275>/Abs' */
  real_T Sum_eb0;                      /* '<S275>/Sum' */
  real_T DeadZone_ap;                  /* '<S275>/Dead Zone' */
  real_T Signx_lq;                     /* '<S275>/Sign x' */
  real_T Product_gy;                   /* '<S275>/Product' */
  real_T Gain2_e;                      /* '<S275>/Gain2' */
  real_T Signvx_l;                     /* '<S275>/Sign vx' */
  real_T Stiffness_Force_kg;           /* '<S286>/Gain1' */
  real_T SprForce_m;                   /* '<S262>/Product' */
  real_T Sign_f;                       /* '<S286>/Sign' */
  real_T Damping_Force_Enable_h;       /* '<S286>/Abs' */
  real_T Saturation_jq;                /* '<S286>/Saturation' */
  real_T Damping_Force_d;              /* '<S286>/Gain2' */
  real_T Damping_Force_cq;             /* '<S286>/Product' */
  real_T DampForce_n;                  /* '<S262>/Product1' */
  real_T Sum_jg;                       /* '<S278>/Sum' */
  real_T TmpSignalConversionAtProduct2_j[3];
  real_T Gain_d[3];                    /* '<S278>/Gain' */
  real_T Product3_j;                   /* '<S282>/Product3' */
  real_T Product5_a;                   /* '<S277>/Product5' */
  real_T slipy_h;                      /* '<S282>/Sum1' */
  real_T MathFunction_pq;              /* '<S282>/Math Function' */
  real_T Product4_i;                   /* '<S282>/Product4' */
  real_T Product6_p;                   /* '<S277>/Product6' */
  real_T slipx_m;                      /* '<S282>/Sum2' */
  real_T MathFunction1_m;              /* '<S282>/Math Function1' */
  real_T Sum3_c;                       /* '<S282>/Sum3' */
  real_T Sqrt_l3;                      /* '<S282>/Sqrt' */
  real_T CoefficientofFrictionvsVeloci_o;/* '<S284>/Coefficient of Friction vs Velocity' */
  real_T Product_db;                   /* '<S284>/Product' */
  real_T Friction_Force_n;             /* '<S284>/Gain2' */
  real_T TrigonometricFunction_p;      /* '<S282>/Trigonometric Function' */
  real_T TrigonometricFunction1_d;     /* '<S277>/Trigonometric Function1' */
  real_T Product3_dh;                  /* '<S277>/Product3' */
  real_T TrigonometricFunction_h;      /* '<S277>/Trigonometric Function' */
  real_T Product4_k5;                  /* '<S277>/Product4' */
  real_T TmpSignalConversionAtProduct1_i[3];
  real_T Gain_eu[3];                   /* '<S277>/Gain' */
  real_T FPla_d[3];                    /* '<S262>/Sum1' */
  real_T Product_a4;                   /* '<S276>/Product' */
  real_T Product1_hn;                  /* '<S276>/Product1' */
  real_T Product2_k;                   /* '<S276>/Product2' */
  real_T Product3_k;                   /* '<S276>/Product3' */
  real_T Product4_ku;                  /* '<S276>/Product4' */
  real_T Product5_ae;                  /* '<S276>/Product5' */
  real_T Product7_f[3];                /* '<S277>/Product7' */
  real_T Product_pw;                   /* '<S280>/Product' */
  real_T Product1_a;                   /* '<S280>/Product1' */
  real_T Product2_l;                   /* '<S280>/Product2' */
  real_T Product3_c;                   /* '<S280>/Product3' */
  real_T Product4_iy;                  /* '<S280>/Product4' */
  real_T Product5_g;                   /* '<S280>/Product5' */
  real_T Sum_ei;                       /* '<S280>/Sum' */
  real_T Sum1_ck;                      /* '<S280>/Sum1' */
  real_T Sum2_g;                       /* '<S280>/Sum2' */
  real_T Product1_km[3];               /* '<S277>/Product1' */
  real_T TmpSignalConversionAtProduct_oq[3];/* '<S277>/Cross Product' */
  real_T Product2_ld[3];               /* '<S278>/Product2' */
  real_T Abs_b;                        /* '<S227>/Abs' */
  real_T Sum_j4;                       /* '<S227>/Sum' */
  real_T DeadZone_k;                   /* '<S227>/Dead Zone' */
  real_T Signx_e;                      /* '<S227>/Sign x' */
  real_T Product_if;                   /* '<S227>/Product' */
  real_T Gain2_b;                      /* '<S227>/Gain2' */
  real_T Signvx_h;                     /* '<S227>/Sign vx' */
  real_T Stiffness_Force_kv;           /* '<S238>/Gain1' */
  real_T SprForce_e;                   /* '<S214>/Product' */
  real_T Sign_m;                       /* '<S238>/Sign' */
  real_T Damping_Force_Enable_df;      /* '<S238>/Abs' */
  real_T Saturation_d;                 /* '<S238>/Saturation' */
  real_T Damping_Force_m;              /* '<S238>/Gain2' */
  real_T Damping_Force_a;              /* '<S238>/Product' */
  real_T DampForce_f;                  /* '<S214>/Product1' */
  real_T Sum_iz;                       /* '<S230>/Sum' */
  real_T TmpSignalConversionAtProduct_c3[3];
  real_T Gain_ar[3];                   /* '<S230>/Gain' */
  real_T Product3_ao;                  /* '<S234>/Product3' */
  real_T Product5_jn;                  /* '<S229>/Product5' */
  real_T slipy_o;                      /* '<S234>/Sum1' */
  real_T MathFunction_hr;              /* '<S234>/Math Function' */
  real_T Product4_a5;                  /* '<S234>/Product4' */
  real_T Product6_c;                   /* '<S229>/Product6' */
  real_T slipx_l;                      /* '<S234>/Sum2' */
  real_T MathFunction1_a2;             /* '<S234>/Math Function1' */
  real_T Sum3_a;                       /* '<S234>/Sum3' */
  real_T Sqrt_h;                       /* '<S234>/Sqrt' */
  real_T CoefficientofFrictionvsVeloc_ow;/* '<S236>/Coefficient of Friction vs Velocity' */
  real_T Product_ka;                   /* '<S236>/Product' */
  real_T Friction_Force_bg;            /* '<S236>/Gain2' */
  real_T TrigonometricFunction_pt;     /* '<S234>/Trigonometric Function' */
  real_T TrigonometricFunction1_dl;    /* '<S229>/Trigonometric Function1' */
  real_T Product3_kn;                  /* '<S229>/Product3' */
  real_T TrigonometricFunction_iw;     /* '<S229>/Trigonometric Function' */
  real_T Product4_iys;                 /* '<S229>/Product4' */
  real_T TmpSignalConversionAtProduct1_p[3];
  real_T Gain_ib[3];                   /* '<S229>/Gain' */
  real_T FPla_n[3];                    /* '<S214>/Sum1' */
  real_T Product_fd;                   /* '<S228>/Product' */
  real_T Product1_ij;                  /* '<S228>/Product1' */
  real_T Product2_e;                   /* '<S228>/Product2' */
  real_T Product3_ma;                  /* '<S228>/Product3' */
  real_T Product4_ae;                  /* '<S228>/Product4' */
  real_T Product5_jh;                  /* '<S228>/Product5' */
  real_T Product7_bi[3];               /* '<S229>/Product7' */
  real_T Product_j2;                   /* '<S232>/Product' */
  real_T Product1_f;                   /* '<S232>/Product1' */
  real_T Product2_hu;                  /* '<S232>/Product2' */
  real_T Product3_b;                   /* '<S232>/Product3' */
  real_T Product4_ad;                  /* '<S232>/Product4' */
  real_T Product5_gd;                  /* '<S232>/Product5' */
  real_T Sum_ec;                       /* '<S232>/Sum' */
  real_T Sum1_cv;                      /* '<S232>/Sum1' */
  real_T Sum2_n;                       /* '<S232>/Sum2' */
  real_T Product1_m[3];                /* '<S229>/Product1' */
  real_T TmpSignalConversionAtProduct2_k[3];/* '<S229>/Cross Product' */
  real_T Product2_d[3];                /* '<S230>/Product2' */
  real_T Abs_kv;                       /* '<S179>/Abs' */
  real_T Sum_la;                       /* '<S179>/Sum' */
  real_T DeadZone_l;                   /* '<S179>/Dead Zone' */
  real_T Signx_j;                      /* '<S179>/Sign x' */
  real_T Product_gr;                   /* '<S179>/Product' */
  real_T Gain2_fs;                     /* '<S179>/Gain2' */
  real_T Signvx_p;                     /* '<S179>/Sign vx' */
  real_T Stiffness_Force_kw;           /* '<S190>/Gain1' */
  real_T SprForce_a;                   /* '<S166>/Product' */
  real_T Sign_g;                       /* '<S190>/Sign' */
  real_T Damping_Force_Enable_i;       /* '<S190>/Abs' */
  real_T Saturation_el;                /* '<S190>/Saturation' */
  real_T Damping_Force_mh;             /* '<S190>/Gain2' */
  real_T Damping_Force_g;              /* '<S190>/Product' */
  real_T DampForce_hs;                 /* '<S166>/Product1' */
  real_T Sum_aw;                       /* '<S182>/Sum' */
  real_T TmpSignalConversionAtProduct_jm[3];
  real_T Gain_fu[3];                   /* '<S182>/Gain' */
  real_T Product3_c3;                  /* '<S186>/Product3' */
  real_T Product5_is;                  /* '<S181>/Product5' */
  real_T slipy_n;                      /* '<S186>/Sum1' */
  real_T MathFunction_ke;              /* '<S186>/Math Function' */
  real_T Product4_bh;                  /* '<S186>/Product4' */
  real_T Product6_b;                   /* '<S181>/Product6' */
  real_T slipx_f;                      /* '<S186>/Sum2' */
  real_T MathFunction1_p;              /* '<S186>/Math Function1' */
  real_T Sum3_g;                       /* '<S186>/Sum3' */
  real_T Sqrt_d;                       /* '<S186>/Sqrt' */
  real_T CoefficientofFrictionvsVeloci_i;/* '<S188>/Coefficient of Friction vs Velocity' */
  real_T Product_h;                    /* '<S188>/Product' */
  real_T Friction_Force_m;             /* '<S188>/Gain2' */
  real_T TrigonometricFunction_f;      /* '<S186>/Trigonometric Function' */
  real_T TrigonometricFunction1_n;     /* '<S181>/Trigonometric Function1' */
  real_T Product3_ab;                  /* '<S181>/Product3' */
  real_T TrigonometricFunction_jh;     /* '<S181>/Trigonometric Function' */
  real_T Product4_j;                   /* '<S181>/Product4' */
  real_T TmpSignalConversionAtProduct1_a[3];
  real_T Gain_d1[3];                   /* '<S181>/Gain' */
  real_T FPla_p[3];                    /* '<S166>/Sum1' */
  real_T Product_jf;                   /* '<S180>/Product' */
  real_T Product1_l;                   /* '<S180>/Product1' */
  real_T Product2_jh;                  /* '<S180>/Product2' */
  real_T Product3_ep;                  /* '<S180>/Product3' */
  real_T Product4_o;                   /* '<S180>/Product4' */
  real_T Product5_np;                  /* '<S180>/Product5' */
  real_T Product7_j[3];                /* '<S181>/Product7' */
  real_T Product_n4;                   /* '<S184>/Product' */
  real_T Product1_g;                   /* '<S184>/Product1' */
  real_T Product2_ox;                  /* '<S184>/Product2' */
  real_T Product3_in;                  /* '<S184>/Product3' */
  real_T Product4_fk;                  /* '<S184>/Product4' */
  real_T Product5_id;                  /* '<S184>/Product5' */
  real_T Sum_d0;                       /* '<S184>/Sum' */
  real_T Sum1_o;                       /* '<S184>/Sum1' */
  real_T Sum2_j;                       /* '<S184>/Sum2' */
  real_T Product1_o4[3];               /* '<S181>/Product1' */
  real_T TmpSignalConversionAtProduct2_n[3];/* '<S181>/Cross Product' */
  real_T Product2_ib[3];               /* '<S182>/Product2' */
  real_T Abs_ky;                       /* '<S131>/Abs' */
  real_T Sum_l4;                       /* '<S131>/Sum' */
  real_T DeadZone_ko;                  /* '<S131>/Dead Zone' */
  real_T Signx_l2;                     /* '<S131>/Sign x' */
  real_T Product_g0;                   /* '<S131>/Product' */
  real_T Gain2_l;                      /* '<S131>/Gain2' */
  real_T Signvx_ax;                    /* '<S131>/Sign vx' */
  real_T Stiffness_Force_k0;           /* '<S142>/Gain1' */
  real_T SprForce_ny;                  /* '<S118>/Product' */
  real_T Sign_kv;                      /* '<S142>/Sign' */
  real_T Damping_Force_Enable_o;       /* '<S142>/Abs' */
  real_T Saturation_dc;                /* '<S142>/Saturation' */
  real_T Damping_Force_l;              /* '<S142>/Gain2' */
  real_T Damping_Force_d2;             /* '<S142>/Product' */
  real_T DampForce_b;                  /* '<S118>/Product1' */
  real_T Sum_bz;                       /* '<S134>/Sum' */
  real_T TmpSignalConversionAtProduct_kh[3];
  real_T Gain_em[3];                   /* '<S134>/Gain' */
  real_T Product3_nd;                  /* '<S138>/Product3' */
  real_T Product5_mo;                  /* '<S133>/Product5' */
  real_T slipy_j;                      /* '<S138>/Sum1' */
  real_T MathFunction_gn;              /* '<S138>/Math Function' */
  real_T Product4_m;                   /* '<S138>/Product4' */
  real_T Product6_a;                   /* '<S133>/Product6' */
  real_T slipx_p;                      /* '<S138>/Sum2' */
  real_T MathFunction1_aw;             /* '<S138>/Math Function1' */
  real_T Sum3_dn;                      /* '<S138>/Sum3' */
  real_T Sqrt_o;                       /* '<S138>/Sqrt' */
  real_T CoefficientofFrictionvsVeloc_id;/* '<S140>/Coefficient of Friction vs Velocity' */
  real_T Product_mc;                   /* '<S140>/Product' */
  real_T Friction_Force_p;             /* '<S140>/Gain2' */
  real_T TrigonometricFunction_pg;     /* '<S138>/Trigonometric Function' */
  real_T TrigonometricFunction1_oc;    /* '<S133>/Trigonometric Function1' */
  real_T Product3_bw;                  /* '<S133>/Product3' */
  real_T TrigonometricFunction_lx;     /* '<S133>/Trigonometric Function' */
  real_T Product4_at;                  /* '<S133>/Product4' */
  real_T TmpSignalConversionAtProduct_au[3];
  real_T Gain_hg[3];                   /* '<S133>/Gain' */
  real_T FPla_j[3];                    /* '<S118>/Sum1' */
  real_T Product_mw;                   /* '<S132>/Product' */
  real_T Product1_oq;                  /* '<S132>/Product1' */
  real_T Product2_f;                   /* '<S132>/Product2' */
  real_T Product3_ax;                  /* '<S132>/Product3' */
  real_T Product4_ab;                  /* '<S132>/Product4' */
  real_T Product5_gg;                  /* '<S132>/Product5' */
  real_T Product7_c[3];                /* '<S133>/Product7' */
  real_T Product_ms;                   /* '<S136>/Product' */
  real_T Product1_kj;                  /* '<S136>/Product1' */
  real_T Product2_i1;                  /* '<S136>/Product2' */
  real_T Product3_ny;                  /* '<S136>/Product3' */
  real_T Product4_d1;                  /* '<S136>/Product4' */
  real_T Product5_i3;                  /* '<S136>/Product5' */
  real_T Sum_iw;                       /* '<S136>/Sum' */
  real_T Sum1_f;                       /* '<S136>/Sum1' */
  real_T Sum2_k;                       /* '<S136>/Sum2' */
  real_T Product1_e[3];                /* '<S133>/Product1' */
  real_T TmpSignalConversionAtProduct2_i[3];/* '<S133>/Cross Product' */
  real_T Product2_g[3];                /* '<S134>/Product2' */
  uint32_T DataTypeConversion_e;       /* '<S30>/Data Type Conversion' */
  uint32_T DataTypeConversion_g;       /* '<S32>/Data Type Conversion' */
  uint32_T DataTypeConversion_p5;      /* '<S31>/Data Type Conversion' */
  uint32_T DataTypeConversion_c;       /* '<S33>/Data Type Conversion' */
  uint32_T DataTypeConversion_f;       /* '<S41>/Data Type Conversion' */
  uint32_T DataTypeConversion_j;       /* '<S40>/Data Type Conversion' */
  uint32_T DataTypeConversion_d;       /* '<S39>/Data Type Conversion' */
  uint32_T DataTypeConversion_k;       /* '<S38>/Data Type Conversion' */
  uint32_T DataTypeConversion_aq;      /* '<S37>/Data Type Conversion' */
  uint32_T DataTypeConversion_ec;      /* '<S36>/Data Type Conversion' */
  uint32_T DataTypeConversion_a4;      /* '<S35>/Data Type Conversion' */
  uint32_T DataTypeConversion_dj;      /* '<S34>/Data Type Conversion' */
  uint8_T ASCIIEncode2[128];           /* '<S4>/ASCII Encode 2' */
  boolean_T Compare;                   /* '<S385>/Compare' */
  boolean_T Compare_n;                 /* '<S386>/Compare' */
  boolean_T LogicalOperator;           /* '<S379>/Logical Operator' */
  boolean_T Compare_o;                 /* '<S433>/Compare' */
  boolean_T Compare_m;                 /* '<S434>/Compare' */
  boolean_T LogicalOperator_a;         /* '<S427>/Logical Operator' */
  boolean_T Compare_l;                 /* '<S481>/Compare' */
  boolean_T Compare_g;                 /* '<S482>/Compare' */
  boolean_T LogicalOperator_l;         /* '<S475>/Logical Operator' */
  boolean_T Compare_b;                 /* '<S529>/Compare' */
  boolean_T Compare_f;                 /* '<S530>/Compare' */
  boolean_T LogicalOperator_e;         /* '<S523>/Logical Operator' */
  boolean_T Compare_n1;                /* '<S121>/Compare' */
  boolean_T Compare_k;                 /* '<S122>/Compare' */
  boolean_T LogicalOperator_n;         /* '<S115>/Logical Operator' */
  boolean_T Compare_nc;                /* '<S169>/Compare' */
  boolean_T Compare_j;                 /* '<S170>/Compare' */
  boolean_T LogicalOperator_k;         /* '<S163>/Logical Operator' */
  boolean_T Compare_p;                 /* '<S217>/Compare' */
  boolean_T Compare_a;                 /* '<S218>/Compare' */
  boolean_T LogicalOperator_aj;        /* '<S211>/Logical Operator' */
  boolean_T Compare_aq;                /* '<S265>/Compare' */
  boolean_T Compare_i;                 /* '<S266>/Compare' */
  boolean_T LogicalOperator_nt;        /* '<S259>/Logical Operator' */
  B_SwitchCaseActionSubsystem_C_T SwitchCaseActionSubsystem1;/* '<S4>/Switch Case Action Subsystem1' */
  B_SwitchCaseActionSubsystem_C_T SwitchCaseActionSubsystem;/* '<S4>/Switch Case Action Subsystem' */
} B_Copy_of_Robot_leg_3_0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_3_1_1_discrete[2];      /* '<S583>/INPUT_3_1_1' */
  real_T INPUT_2_1_1_discrete[2];      /* '<S583>/INPUT_2_1_1' */
  real_T INPUT_1_1_1_discrete[2];      /* '<S583>/INPUT_1_1_1' */
  real_T INPUT_6_1_1_discrete[2];      /* '<S583>/INPUT_6_1_1' */
  real_T INPUT_4_1_1_discrete[2];      /* '<S583>/INPUT_4_1_1' */
  real_T INPUT_5_1_1_discrete[2];      /* '<S583>/INPUT_5_1_1' */
  real_T INPUT_28_1_1_discrete[2];     /* '<S583>/INPUT_28_1_1' */
  real_T INPUT_25_1_1_discrete[2];     /* '<S583>/INPUT_25_1_1' */
  real_T INPUT_26_1_1_discrete[2];     /* '<S583>/INPUT_26_1_1' */
  real_T INPUT_24_1_1_discrete[2];     /* '<S583>/INPUT_24_1_1' */
  real_T INPUT_23_1_1_discrete[2];     /* '<S583>/INPUT_23_1_1' */
  real_T INPUT_27_1_1_discrete[2];     /* '<S583>/INPUT_27_1_1' */
  real_T INPUT_10_1_1_discrete[2];     /* '<S583>/INPUT_10_1_1' */
  real_T INPUT_10_1_2_discrete[2];     /* '<S583>/INPUT_10_1_2' */
  real_T INPUT_10_1_3_discrete[2];     /* '<S583>/INPUT_10_1_3' */
  real_T INPUT_9_1_1_discrete[2];      /* '<S583>/INPUT_9_1_1' */
  real_T INPUT_9_1_2_discrete[2];      /* '<S583>/INPUT_9_1_2' */
  real_T INPUT_9_1_3_discrete[2];      /* '<S583>/INPUT_9_1_3' */
  real_T INPUT_7_1_1_discrete[2];      /* '<S583>/INPUT_7_1_1' */
  real_T INPUT_7_1_2_discrete[2];      /* '<S583>/INPUT_7_1_2' */
  real_T INPUT_7_1_3_discrete[2];      /* '<S583>/INPUT_7_1_3' */
  real_T INPUT_8_1_1_discrete[2];      /* '<S583>/INPUT_8_1_1' */
  real_T INPUT_8_1_2_discrete[2];      /* '<S583>/INPUT_8_1_2' */
  real_T INPUT_8_1_3_discrete[2];      /* '<S583>/INPUT_8_1_3' */
  real_T INPUT_14_1_1_discrete[2];     /* '<S583>/INPUT_14_1_1' */
  real_T INPUT_14_1_2_discrete[2];     /* '<S583>/INPUT_14_1_2' */
  real_T INPUT_14_1_3_discrete[2];     /* '<S583>/INPUT_14_1_3' */
  real_T INPUT_13_1_1_discrete[2];     /* '<S583>/INPUT_13_1_1' */
  real_T INPUT_13_1_2_discrete[2];     /* '<S583>/INPUT_13_1_2' */
  real_T INPUT_13_1_3_discrete[2];     /* '<S583>/INPUT_13_1_3' */
  real_T INPUT_11_1_1_discrete[2];     /* '<S583>/INPUT_11_1_1' */
  real_T INPUT_11_1_2_discrete[2];     /* '<S583>/INPUT_11_1_2' */
  real_T INPUT_11_1_3_discrete[2];     /* '<S583>/INPUT_11_1_3' */
  real_T INPUT_12_1_1_discrete[2];     /* '<S583>/INPUT_12_1_1' */
  real_T INPUT_12_1_2_discrete[2];     /* '<S583>/INPUT_12_1_2' */
  real_T INPUT_12_1_3_discrete[2];     /* '<S583>/INPUT_12_1_3' */
  real_T INPUT_18_1_1_discrete[2];     /* '<S583>/INPUT_18_1_1' */
  real_T INPUT_18_1_2_discrete[2];     /* '<S583>/INPUT_18_1_2' */
  real_T INPUT_18_1_3_discrete[2];     /* '<S583>/INPUT_18_1_3' */
  real_T INPUT_17_1_1_discrete[2];     /* '<S583>/INPUT_17_1_1' */
  real_T INPUT_17_1_2_discrete[2];     /* '<S583>/INPUT_17_1_2' */
  real_T INPUT_17_1_3_discrete[2];     /* '<S583>/INPUT_17_1_3' */
  real_T INPUT_15_1_1_discrete[2];     /* '<S583>/INPUT_15_1_1' */
  real_T INPUT_15_1_2_discrete[2];     /* '<S583>/INPUT_15_1_2' */
  real_T INPUT_15_1_3_discrete[2];     /* '<S583>/INPUT_15_1_3' */
  real_T INPUT_16_1_1_discrete[2];     /* '<S583>/INPUT_16_1_1' */
  real_T INPUT_16_1_2_discrete[2];     /* '<S583>/INPUT_16_1_2' */
  real_T INPUT_16_1_3_discrete[2];     /* '<S583>/INPUT_16_1_3' */
  real_T INPUT_22_1_1_discrete[2];     /* '<S583>/INPUT_22_1_1' */
  real_T INPUT_22_1_2_discrete[2];     /* '<S583>/INPUT_22_1_2' */
  real_T INPUT_22_1_3_discrete[2];     /* '<S583>/INPUT_22_1_3' */
  real_T INPUT_21_1_1_discrete[2];     /* '<S583>/INPUT_21_1_1' */
  real_T INPUT_21_1_2_discrete[2];     /* '<S583>/INPUT_21_1_2' */
  real_T INPUT_21_1_3_discrete[2];     /* '<S583>/INPUT_21_1_3' */
  real_T INPUT_19_1_1_discrete[2];     /* '<S583>/INPUT_19_1_1' */
  real_T INPUT_19_1_2_discrete[2];     /* '<S583>/INPUT_19_1_2' */
  real_T INPUT_19_1_3_discrete[2];     /* '<S583>/INPUT_19_1_3' */
  real_T INPUT_20_1_1_discrete[2];     /* '<S583>/INPUT_20_1_1' */
  real_T INPUT_20_1_2_discrete[2];     /* '<S583>/INPUT_20_1_2' */
  real_T INPUT_20_1_3_discrete[2];     /* '<S583>/INPUT_20_1_3' */
  real_T INPUT_32_1_1_discrete[2];     /* '<S583>/INPUT_32_1_1' */
  real_T INPUT_32_1_2_discrete[2];     /* '<S583>/INPUT_32_1_2' */
  real_T INPUT_32_1_3_discrete[2];     /* '<S583>/INPUT_32_1_3' */
  real_T INPUT_31_1_1_discrete[2];     /* '<S583>/INPUT_31_1_1' */
  real_T INPUT_31_1_2_discrete[2];     /* '<S583>/INPUT_31_1_2' */
  real_T INPUT_31_1_3_discrete[2];     /* '<S583>/INPUT_31_1_3' */
  real_T INPUT_29_1_1_discrete[2];     /* '<S583>/INPUT_29_1_1' */
  real_T INPUT_29_1_2_discrete[2];     /* '<S583>/INPUT_29_1_2' */
  real_T INPUT_29_1_3_discrete[2];     /* '<S583>/INPUT_29_1_3' */
  real_T INPUT_30_1_1_discrete[2];     /* '<S583>/INPUT_30_1_1' */
  real_T INPUT_30_1_2_discrete[2];     /* '<S583>/INPUT_30_1_2' */
  real_T INPUT_30_1_3_discrete[2];     /* '<S583>/INPUT_30_1_3' */
  real_T INPUT_36_1_1_discrete[2];     /* '<S583>/INPUT_36_1_1' */
  real_T INPUT_36_1_2_discrete[2];     /* '<S583>/INPUT_36_1_2' */
  real_T INPUT_36_1_3_discrete[2];     /* '<S583>/INPUT_36_1_3' */
  real_T INPUT_35_1_1_discrete[2];     /* '<S583>/INPUT_35_1_1' */
  real_T INPUT_35_1_2_discrete[2];     /* '<S583>/INPUT_35_1_2' */
  real_T INPUT_35_1_3_discrete[2];     /* '<S583>/INPUT_35_1_3' */
  real_T INPUT_33_1_1_discrete[2];     /* '<S583>/INPUT_33_1_1' */
  real_T INPUT_33_1_2_discrete[2];     /* '<S583>/INPUT_33_1_2' */
  real_T INPUT_33_1_3_discrete[2];     /* '<S583>/INPUT_33_1_3' */
  real_T INPUT_34_1_1_discrete[2];     /* '<S583>/INPUT_34_1_1' */
  real_T INPUT_34_1_2_discrete[2];     /* '<S583>/INPUT_34_1_2' */
  real_T INPUT_34_1_3_discrete[2];     /* '<S583>/INPUT_34_1_3' */
  real_T INPUT_40_1_1_discrete[2];     /* '<S583>/INPUT_40_1_1' */
  real_T INPUT_40_1_2_discrete[2];     /* '<S583>/INPUT_40_1_2' */
  real_T INPUT_40_1_3_discrete[2];     /* '<S583>/INPUT_40_1_3' */
  real_T INPUT_39_1_1_discrete[2];     /* '<S583>/INPUT_39_1_1' */
  real_T INPUT_39_1_2_discrete[2];     /* '<S583>/INPUT_39_1_2' */
  real_T INPUT_39_1_3_discrete[2];     /* '<S583>/INPUT_39_1_3' */
  real_T INPUT_37_1_1_discrete[2];     /* '<S583>/INPUT_37_1_1' */
  real_T INPUT_37_1_2_discrete[2];     /* '<S583>/INPUT_37_1_2' */
  real_T INPUT_37_1_3_discrete[2];     /* '<S583>/INPUT_37_1_3' */
  real_T INPUT_38_1_1_discrete[2];     /* '<S583>/INPUT_38_1_1' */
  real_T INPUT_38_1_2_discrete[2];     /* '<S583>/INPUT_38_1_2' */
  real_T INPUT_38_1_3_discrete[2];     /* '<S583>/INPUT_38_1_3' */
  real_T INPUT_44_1_1_discrete[2];     /* '<S583>/INPUT_44_1_1' */
  real_T INPUT_44_1_2_discrete[2];     /* '<S583>/INPUT_44_1_2' */
  real_T INPUT_44_1_3_discrete[2];     /* '<S583>/INPUT_44_1_3' */
  real_T INPUT_43_1_1_discrete[2];     /* '<S583>/INPUT_43_1_1' */
  real_T INPUT_43_1_2_discrete[2];     /* '<S583>/INPUT_43_1_2' */
  real_T INPUT_43_1_3_discrete[2];     /* '<S583>/INPUT_43_1_3' */
  real_T INPUT_41_1_1_discrete[2];     /* '<S583>/INPUT_41_1_1' */
  real_T INPUT_41_1_2_discrete[2];     /* '<S583>/INPUT_41_1_2' */
  real_T INPUT_41_1_3_discrete[2];     /* '<S583>/INPUT_41_1_3' */
  real_T INPUT_42_1_1_discrete[2];     /* '<S583>/INPUT_42_1_1' */
  real_T INPUT_42_1_2_discrete[2];     /* '<S583>/INPUT_42_1_2' */
  real_T INPUT_42_1_3_discrete[2];     /* '<S583>/INPUT_42_1_3' */
  real_T Product1_DWORK1[9];           /* '<S541>/Product1' */
  real_T Product1_DWORK3[3];           /* '<S541>/Product1' */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[6144];
  } TransportDelay_RWORK;              /* '<S4>/Transport Delay' */

  struct {
    void *TUbufferPtrs[6];
  } TransportDelay_PWORK;              /* '<S4>/Transport Delay' */

  void* STATE_1_Simulator;             /* '<S583>/STATE_1' */
  void* STATE_1_SimulationData;        /* '<S583>/STATE_1' */
  void* STATE_1_DiagnosticManager;     /* '<S583>/STATE_1' */
  void* STATE_1_VariableLogger;        /* '<S583>/STATE_1' */
  void* STATE_1_ZeroCrossingLogger;    /* '<S583>/STATE_1' */
  void* STATE_1_SampleTimeIdx;         /* '<S583>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S583>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimulationData;     /* '<S583>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagnosticManager;  /* '<S583>/OUTPUT_1_0' */
  void* OUTPUT_1_0_VariableLogger;     /* '<S583>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZeroCrossingLogger; /* '<S583>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SampleTimeIdx;      /* '<S583>/OUTPUT_1_0' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void* OUTPUT_1_1_Simulator;          /* '<S583>/OUTPUT_1_1' */
  void* OUTPUT_1_1_SimulationData;     /* '<S583>/OUTPUT_1_1' */
  void* OUTPUT_1_1_DiagnosticManager;  /* '<S583>/OUTPUT_1_1' */
  void* OUTPUT_1_1_VariableLogger;     /* '<S583>/OUTPUT_1_1' */
  void* OUTPUT_1_1_ZeroCrossingLogger; /* '<S583>/OUTPUT_1_1' */
  void* OUTPUT_1_1_SampleTimeIdx;      /* '<S583>/OUTPUT_1_1' */
  struct {
    void *AQHandles[14];
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFor_;   /* synthesized block */

  struct {
    void *AQHandles[14];
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_c;   /* synthesized block */

  void *UDPConfigure_PWORK[5];         /* '<S4>/UDP Configure' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_b;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_d;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_g;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     /* '<S4>/Scope' */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_cj;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_b4;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_db;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_j;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_co;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_o;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_p;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_dg;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_bq;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_gw;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_oe;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_gi;   /* synthesized block */

  void *ASCIIEncode2_PWORK;            /* '<S4>/ASCII Encode 2' */
  void *UDPSend_PWORK;                 /* '<S4>/UDP Send' */
  void* SINK_1_Simulator;              /* '<S583>/SINK_1' */
  void* SINK_1_SimulationData;         /* '<S583>/SINK_1' */
  void* SINK_1_DiagnosticManager;      /* '<S583>/SINK_1' */
  void* SINK_1_VariableLogger;         /* '<S583>/SINK_1' */
  void* SINK_1_ZeroCrossingLogger;     /* '<S583>/SINK_1' */
  void* SINK_1_SampleTimeIdx;          /* '<S583>/SINK_1' */
  int32_T Product1_DWORK2[3];          /* '<S541>/Product1' */
  struct {
    int_T Tail[3];
    int_T Head[3];
    int_T Last[3];
    int_T CircularBufSize[3];
  } TransportDelay_IWORK;              /* '<S4>/Transport Delay' */

  int_T UDPConfigure_IWORK[6];         /* '<S4>/UDP Configure' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S26>/S-Function' */

  int_T UDPSend_IWORK[3];              /* '<S4>/UDP Send' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S4>/Switch Case' */
  int8_T If1_ActiveSubsystem;          /* '<S322>/If1' */
  int8_T If1_ActiveSubsystem_j;        /* '<S323>/If1' */
  int8_T If1_ActiveSubsystem_jw;       /* '<S324>/If1' */
  int8_T If1_ActiveSubsystem_m;        /* '<S325>/If1' */
  int8_T If1_ActiveSubsystem_p;        /* '<S58>/If1' */
  int8_T If1_ActiveSubsystem_i;        /* '<S59>/If1' */
  int8_T If1_ActiveSubsystem_o;        /* '<S60>/If1' */
  int8_T If1_ActiveSubsystem_e;        /* '<S61>/If1' */
  int8_T NoForce_SubsysRanBC;          /* '<S325>/No Force' */
  int8_T Forces_SubsysRanBC;           /* '<S325>/Forces' */
  int8_T NoForce_SubsysRanBC_p;        /* '<S324>/No Force' */
  int8_T Forces_SubsysRanBC_g;         /* '<S324>/Forces' */
  int8_T NoForce_SubsysRanBC_e;        /* '<S323>/No Force' */
  int8_T Forces_SubsysRanBC_b;         /* '<S323>/Forces' */
  int8_T NoForce_SubsysRanBC_f;        /* '<S322>/No Force' */
  int8_T Forces_SubsysRanBC_c;         /* '<S322>/Forces' */
  int8_T NoForce_SubsysRanBC_d;        /* '<S61>/No Force' */
  int8_T Forces_SubsysRanBC_o;         /* '<S61>/Forces' */
  int8_T NoForce_SubsysRanBC_i;        /* '<S60>/No Force' */
  int8_T Forces_SubsysRanBC_i;         /* '<S60>/Forces' */
  int8_T NoForce_SubsysRanBC_b;        /* '<S59>/No Force' */
  int8_T Forces_SubsysRanBC_l;         /* '<S59>/Forces' */
  int8_T NoForce_SubsysRanBC_is;       /* '<S58>/No Force' */
  int8_T Forces_SubsysRanBC_iy;        /* '<S58>/Forces' */
  boolean_T STATE_1_CallSimulatorOutput;/* '<S583>/STATE_1' */
  boolean_T OUTPUT_1_0_CallSimulatorOutput;/* '<S583>/OUTPUT_1_0' */
  boolean_T OUTPUT_1_1_CallSimulatorOutput;/* '<S583>/OUTPUT_1_1' */
  boolean_T SINK_1_CallSimulatorOutput;/* '<S583>/SINK_1' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem1;/* '<S4>/Switch Case Action Subsystem1' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem;/* '<S4>/Switch Case Action Subsystem' */
} DW_Copy_of_Robot_leg_3_0_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Copy_of_Robot_leg_3_0RobotLeft_[2];/* '<S583>/INPUT_3_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_e[2];/* '<S583>/INPUT_2_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_f[2];/* '<S583>/INPUT_1_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_d[2];/* '<S583>/INPUT_6_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_c[2];/* '<S583>/INPUT_4_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLe_cb[2];/* '<S583>/INPUT_5_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRight[2];/* '<S583>/INPUT_28_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_p[2];/* '<S583>/INPUT_25_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_n[2];/* '<S583>/INPUT_26_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_b[2];/* '<S583>/INPUT_24_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_j[2];/* '<S583>/INPUT_23_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_a[2];/* '<S583>/INPUT_27_1_1' */
  real_T Copy_of_Robot_leg_3_0x6_DOF_Joi[13];/* '<S583>/STATE_1' */
} X_Copy_of_Robot_leg_3_0_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Copy_of_Robot_leg_3_0RobotLeft_[2];/* '<S583>/INPUT_3_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_e[2];/* '<S583>/INPUT_2_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_f[2];/* '<S583>/INPUT_1_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_d[2];/* '<S583>/INPUT_6_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLef_c[2];/* '<S583>/INPUT_4_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotLe_cb[2];/* '<S583>/INPUT_5_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRight[2];/* '<S583>/INPUT_28_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_p[2];/* '<S583>/INPUT_25_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_n[2];/* '<S583>/INPUT_26_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_b[2];/* '<S583>/INPUT_24_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_j[2];/* '<S583>/INPUT_23_1_1' */
  real_T Copy_of_Robot_leg_3_0RobotRig_a[2];/* '<S583>/INPUT_27_1_1' */
  real_T Copy_of_Robot_leg_3_0x6_DOF_Joi[13];/* '<S583>/STATE_1' */
} XDot_Copy_of_Robot_leg_3_0_T;

/* State disabled  */
typedef struct {
  boolean_T Copy_of_Robot_leg_3_0RobotLeft_[2];/* '<S583>/INPUT_3_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotLef_e[2];/* '<S583>/INPUT_2_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotLef_f[2];/* '<S583>/INPUT_1_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotLef_d[2];/* '<S583>/INPUT_6_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotLef_c[2];/* '<S583>/INPUT_4_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotLe_cb[2];/* '<S583>/INPUT_5_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotRight[2];/* '<S583>/INPUT_28_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotRig_p[2];/* '<S583>/INPUT_25_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotRig_n[2];/* '<S583>/INPUT_26_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotRig_b[2];/* '<S583>/INPUT_24_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotRig_j[2];/* '<S583>/INPUT_23_1_1' */
  boolean_T Copy_of_Robot_leg_3_0RobotRig_a[2];/* '<S583>/INPUT_27_1_1' */
  boolean_T Copy_of_Robot_leg_3_0x6_DOF_Joi[13];/* '<S583>/STATE_1' */
} XDis_Copy_of_Robot_leg_3_0_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T w;                            /* '<Root>/w' */
  real_T x;                            /* '<Root>/x' */
  real_T z;                            /* '<Root>/z' */
  real_T measR[14];                    /* '<Root>/measR' */
  real_T measL[14];                    /* '<Root>/measL' */
} ExtY_Copy_of_Robot_leg_3_0_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Copy_of_Robot_leg_3_0_B
#define BlockIO                        B_Copy_of_Robot_leg_3_0_T
#define rtX                            Copy_of_Robot_leg_3_0_X
#define ContinuousStates               X_Copy_of_Robot_leg_3_0_T
#define rtXdot                         Copy_of_Robot_leg_3_0_XDot
#define StateDerivatives               XDot_Copy_of_Robot_leg_3_0_T
#define tXdis                          Copy_of_Robot_leg_3_0_XDis
#define StateDisabled                  XDis_Copy_of_Robot_leg_3_0_T
#define rtY                            Copy_of_Robot_leg_3_0_Y
#define ExternalOutputs                ExtY_Copy_of_Robot_leg_3_0_T
#define rtP                            Copy_of_Robot_leg_3_0_P
#define Parameters                     P_Copy_of_Robot_leg_3_0_T
#define rtDWork                        Copy_of_Robot_leg_3_0_DW
#define D_Work                         DW_Copy_of_Robot_leg_3_0_T

/* Parameters for system: '<S4>/Switch Case Action Subsystem' */
struct P_SwitchCaseActionSubsystem_C_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S42>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_Copy_of_Robot_leg_3_0_T_ {
  real_T left_abduction[40];           /* Variable: left_abduction
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T left_ankle[40];               /* Variable: left_ankle
                                        * Referenced by: '<S11>/Look-Up Table1'
                                        */
  real_T left_hip[40];                 /* Variable: left_hip
                                        * Referenced by: '<S12>/Look-Up Table1'
                                        */
  real_T left_knee[40];                /* Variable: left_knee
                                        * Referenced by: '<S13>/Look-Up Table1'
                                        */
  real_T left_knee_twist[40];          /* Variable: left_knee_twist
                                        * Referenced by: '<S10>/Look-Up Table1'
                                        */
  real_T left_rotation[40];            /* Variable: left_rotation
                                        * Referenced by: '<S14>/Look-Up Table1'
                                        */
  real_T left_theta_1[40];             /* Variable: left_theta_1
                                        * Referenced by: '<S574>/Look-Up Table1'
                                        */
  real_T left_theta_2[40];             /* Variable: left_theta_2
                                        * Referenced by: '<S575>/Look-Up Table1'
                                        */
  real_T left_theta_3[40];             /* Variable: left_theta_3
                                        * Referenced by: '<S572>/Look-Up Table1'
                                        */
  real_T left_theta_4[40];             /* Variable: left_theta_4
                                        * Referenced by: '<S573>/Look-Up Table1'
                                        */
  real_T left_theta_5[40];             /* Variable: left_theta_5
                                        * Referenced by: '<S571>/Look-Up Table1'
                                        */
  real_T left_theta_6[40];             /* Variable: left_theta_6
                                        * Referenced by: '<S576>/Look-Up Table1'
                                        */
  real_T right_abduction[40];          /* Variable: right_abduction
                                        * Referenced by: '<S18>/Look-Up Table1'
                                        */
  real_T right_ankle[40];              /* Variable: right_ankle
                                        * Referenced by: '<S20>/Look-Up Table1'
                                        */
  real_T right_hip[40];                /* Variable: right_hip
                                        * Referenced by: '<S21>/Look-Up Table1'
                                        */
  real_T right_knee[40];               /* Variable: right_knee
                                        * Referenced by: '<S22>/Look-Up Table1'
                                        */
  real_T right_knee_twist[40];         /* Variable: right_knee_twist
                                        * Referenced by: '<S19>/Look-Up Table1'
                                        */
  real_T right_rotation[40];           /* Variable: right_rotation
                                        * Referenced by: '<S23>/Look-Up Table1'
                                        */
  real_T right_theta_1[40];            /* Variable: right_theta_1
                                        * Referenced by: '<S580>/Look-Up Table1'
                                        */
  real_T right_theta_2[40];            /* Variable: right_theta_2
                                        * Referenced by: '<S581>/Look-Up Table1'
                                        */
  real_T right_theta_3[40];            /* Variable: right_theta_3
                                        * Referenced by: '<S578>/Look-Up Table1'
                                        */
  real_T right_theta_4[40];            /* Variable: right_theta_4
                                        * Referenced by: '<S579>/Look-Up Table1'
                                        */
  real_T right_theta_5[40];            /* Variable: right_theta_5
                                        * Referenced by: '<S577>/Look-Up Table1'
                                        */
  real_T right_theta_6[40];            /* Variable: right_theta_6
                                        * Referenced by: '<S582>/Look-Up Table1'
                                        */
  real_T SpheretoPlaneForce_b_contact; /* Mask Parameter: SpheretoPlaneForce_b_contact
                                        * Referenced by: '<S142>/Gain2'
                                        */
  real_T SpheretoPlaneForce1_b_contact;/* Mask Parameter: SpheretoPlaneForce1_b_contact
                                        * Referenced by: '<S190>/Gain2'
                                        */
  real_T SpheretoPlaneForce2_b_contact;/* Mask Parameter: SpheretoPlaneForce2_b_contact
                                        * Referenced by: '<S238>/Gain2'
                                        */
  real_T SpheretoPlaneForce3_b_contact;/* Mask Parameter: SpheretoPlaneForce3_b_contact
                                        * Referenced by: '<S286>/Gain2'
                                        */
  real_T SpheretoPlaneForce_b_contact_m;/* Mask Parameter: SpheretoPlaneForce_b_contact_m
                                         * Referenced by: '<S406>/Gain2'
                                         */
  real_T SpheretoPlaneForce1_b_contact_b;/* Mask Parameter: SpheretoPlaneForce1_b_contact_b
                                          * Referenced by: '<S454>/Gain2'
                                          */
  real_T SpheretoPlaneForce2_b_contact_j;/* Mask Parameter: SpheretoPlaneForce2_b_contact_j
                                          * Referenced by: '<S502>/Gain2'
                                          */
  real_T SpheretoPlaneForce3_b_contact_h;/* Mask Parameter: SpheretoPlaneForce3_b_contact_h
                                          * Referenced by: '<S550>/Gain2'
                                          */
  real_T SpheretoPlaneForce_k_contact; /* Mask Parameter: SpheretoPlaneForce_k_contact
                                        * Referenced by: '<S142>/Gain1'
                                        */
  real_T SpheretoPlaneForce1_k_contact;/* Mask Parameter: SpheretoPlaneForce1_k_contact
                                        * Referenced by: '<S190>/Gain1'
                                        */
  real_T SpheretoPlaneForce2_k_contact;/* Mask Parameter: SpheretoPlaneForce2_k_contact
                                        * Referenced by: '<S238>/Gain1'
                                        */
  real_T SpheretoPlaneForce3_k_contact;/* Mask Parameter: SpheretoPlaneForce3_k_contact
                                        * Referenced by: '<S286>/Gain1'
                                        */
  real_T SpheretoPlaneForce_k_contact_h;/* Mask Parameter: SpheretoPlaneForce_k_contact_h
                                         * Referenced by: '<S406>/Gain1'
                                         */
  real_T SpheretoPlaneForce1_k_contact_o;/* Mask Parameter: SpheretoPlaneForce1_k_contact_o
                                          * Referenced by: '<S454>/Gain1'
                                          */
  real_T SpheretoPlaneForce2_k_contact_d;/* Mask Parameter: SpheretoPlaneForce2_k_contact_d
                                          * Referenced by: '<S502>/Gain1'
                                          */
  real_T SpheretoPlaneForce3_k_contact_e;/* Mask Parameter: SpheretoPlaneForce3_k_contact_e
                                          * Referenced by: '<S550>/Gain1'
                                          */
  real_T SpheretoPlaneForce_plane_depth;/* Mask Parameter: SpheretoPlaneForce_plane_depth
                                         * Referenced by: '<S131>/Constant'
                                         */
  real_T SpheretoPlaneForce1_plane_depth;/* Mask Parameter: SpheretoPlaneForce1_plane_depth
                                          * Referenced by: '<S179>/Constant'
                                          */
  real_T SpheretoPlaneForce2_plane_depth;/* Mask Parameter: SpheretoPlaneForce2_plane_depth
                                          * Referenced by: '<S227>/Constant'
                                          */
  real_T SpheretoPlaneForce3_plane_depth;/* Mask Parameter: SpheretoPlaneForce3_plane_depth
                                          * Referenced by: '<S275>/Constant'
                                          */
  real_T SpheretoPlaneForce_plane_dept_p;/* Mask Parameter: SpheretoPlaneForce_plane_dept_p
                                          * Referenced by: '<S395>/Constant'
                                          */
  real_T SpheretoPlaneForce1_plane_dep_h;/* Mask Parameter: SpheretoPlaneForce1_plane_dep_h
                                          * Referenced by: '<S443>/Constant'
                                          */
  real_T SpheretoPlaneForce2_plane_dep_k;/* Mask Parameter: SpheretoPlaneForce2_plane_dep_k
                                          * Referenced by: '<S491>/Constant'
                                          */
  real_T SpheretoPlaneForce3_plane_dep_a;/* Mask Parameter: SpheretoPlaneForce3_plane_dep_a
                                          * Referenced by: '<S539>/Constant'
                                          */
  real_T SpheretoPlaneForce_plane_lenx;/* Mask Parameter: SpheretoPlaneForce_plane_lenx
                                        * Referenced by: '<S385>/Constant'
                                        */
  real_T SpheretoPlaneForce1_plane_lenx;/* Mask Parameter: SpheretoPlaneForce1_plane_lenx
                                         * Referenced by: '<S433>/Constant'
                                         */
  real_T SpheretoPlaneForce2_plane_lenx;/* Mask Parameter: SpheretoPlaneForce2_plane_lenx
                                         * Referenced by: '<S481>/Constant'
                                         */
  real_T SpheretoPlaneForce3_plane_lenx;/* Mask Parameter: SpheretoPlaneForce3_plane_lenx
                                         * Referenced by: '<S529>/Constant'
                                         */
  real_T SpheretoPlaneForce_plane_lenx_d;/* Mask Parameter: SpheretoPlaneForce_plane_lenx_d
                                          * Referenced by: '<S121>/Constant'
                                          */
  real_T SpheretoPlaneForce1_plane_len_m;/* Mask Parameter: SpheretoPlaneForce1_plane_len_m
                                          * Referenced by: '<S169>/Constant'
                                          */
  real_T SpheretoPlaneForce2_plane_len_b;/* Mask Parameter: SpheretoPlaneForce2_plane_len_b
                                          * Referenced by: '<S217>/Constant'
                                          */
  real_T SpheretoPlaneForce3_plane_len_p;/* Mask Parameter: SpheretoPlaneForce3_plane_len_p
                                          * Referenced by: '<S265>/Constant'
                                          */
  real_T SpheretoPlaneForce_plane_leny;/* Mask Parameter: SpheretoPlaneForce_plane_leny
                                        * Referenced by: '<S386>/Constant'
                                        */
  real_T SpheretoPlaneForce1_plane_leny;/* Mask Parameter: SpheretoPlaneForce1_plane_leny
                                         * Referenced by: '<S434>/Constant'
                                         */
  real_T SpheretoPlaneForce2_plane_leny;/* Mask Parameter: SpheretoPlaneForce2_plane_leny
                                         * Referenced by: '<S482>/Constant'
                                         */
  real_T SpheretoPlaneForce3_plane_leny;/* Mask Parameter: SpheretoPlaneForce3_plane_leny
                                         * Referenced by: '<S530>/Constant'
                                         */
  real_T SpheretoPlaneForce_plane_leny_n;/* Mask Parameter: SpheretoPlaneForce_plane_leny_n
                                          * Referenced by: '<S122>/Constant'
                                          */
  real_T SpheretoPlaneForce1_plane_len_d;/* Mask Parameter: SpheretoPlaneForce1_plane_len_d
                                          * Referenced by: '<S170>/Constant'
                                          */
  real_T SpheretoPlaneForce2_plane_len_p;/* Mask Parameter: SpheretoPlaneForce2_plane_len_p
                                          * Referenced by: '<S218>/Constant'
                                          */
  real_T SpheretoPlaneForce3_plane_len_c;/* Mask Parameter: SpheretoPlaneForce3_plane_len_c
                                          * Referenced by: '<S266>/Constant'
                                          */
  real_T SpheretoPlaneForce_sphere_rad;/* Mask Parameter: SpheretoPlaneForce_sphere_rad
                                        * Referenced by:
                                        *   '<S131>/Constant'
                                        *   '<S138>/Fx1'
                                        */
  real_T SpheretoPlaneForce1_sphere_rad;/* Mask Parameter: SpheretoPlaneForce1_sphere_rad
                                         * Referenced by:
                                         *   '<S179>/Constant'
                                         *   '<S186>/Fx1'
                                         */
  real_T SpheretoPlaneForce2_sphere_rad;/* Mask Parameter: SpheretoPlaneForce2_sphere_rad
                                         * Referenced by:
                                         *   '<S227>/Constant'
                                         *   '<S234>/Fx1'
                                         */
  real_T SpheretoPlaneForce3_sphere_rad;/* Mask Parameter: SpheretoPlaneForce3_sphere_rad
                                         * Referenced by:
                                         *   '<S275>/Constant'
                                         *   '<S282>/Fx1'
                                         */
  real_T SpheretoPlaneForce_sphere_rad_m;/* Mask Parameter: SpheretoPlaneForce_sphere_rad_m
                                          * Referenced by:
                                          *   '<S395>/Constant'
                                          *   '<S402>/Fx1'
                                          */
  real_T SpheretoPlaneForce1_sphere_ra_b;/* Mask Parameter: SpheretoPlaneForce1_sphere_ra_b
                                          * Referenced by:
                                          *   '<S443>/Constant'
                                          *   '<S450>/Fx1'
                                          */
  real_T SpheretoPlaneForce2_sphere_ra_p;/* Mask Parameter: SpheretoPlaneForce2_sphere_ra_p
                                          * Referenced by:
                                          *   '<S491>/Constant'
                                          *   '<S498>/Fx1'
                                          */
  real_T SpheretoPlaneForce3_sphere_ra_i;/* Mask Parameter: SpheretoPlaneForce3_sphere_ra_i
                                          * Referenced by:
                                          *   '<S539>/Constant'
                                          *   '<S546>/Fx1'
                                          */
  real_T Out_Y0;                       /* Computed Parameter: Out_Y0
                                        * Referenced by: '<S118>/Out'
                                        */
  real_T DeadZone_Start;               /* Expression: -inf
                                        * Referenced by: '<S131>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 0
                                        * Referenced by: '<S131>/Dead Zone'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S131>/Gain2'
                                        */
  real_T Fx_Value;                     /* Expression: 0
                                        * Referenced by: '<S134>/Fx'
                                        */
  real_T Saturation_UpperSat;          /* Expression: Inf
                                        * Referenced by: '<S142>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S142>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S134>/Gain'
                                        */
  real_T CoefficientofFrictionvsVelocity[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S140>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloci_l[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S140>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S140>/Gain2'
                                        */
  real_T Fx1_Value;                    /* Expression: 0
                                        * Referenced by: '<S133>/Fx1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<S133>/Gain'
                                        */
  real_T Fx2_Value[3];                 /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S133>/Fx2'
                                        */
  real_T Zeros_Value[12];              /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S119>/Zeros'
                                        */
  real_T Out_Y0_p;                     /* Computed Parameter: Out_Y0_p
                                        * Referenced by: '<S166>/Out'
                                        */
  real_T DeadZone_Start_b;             /* Expression: -inf
                                        * Referenced by: '<S179>/Dead Zone'
                                        */
  real_T DeadZone_End_a;               /* Expression: 0
                                        * Referenced by: '<S179>/Dead Zone'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: -1
                                        * Referenced by: '<S179>/Gain2'
                                        */
  real_T Fx_Value_c;                   /* Expression: 0
                                        * Referenced by: '<S182>/Fx'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: Inf
                                        * Referenced by: '<S190>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 0
                                        * Referenced by: '<S190>/Saturation'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
                                        * Referenced by: '<S182>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_k[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S188>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloci_j[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S188>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S188>/Gain2'
                                        */
  real_T Fx1_Value_l;                  /* Expression: 0
                                        * Referenced by: '<S181>/Fx1'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S181>/Gain'
                                        */
  real_T Fx2_Value_n[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S181>/Fx2'
                                        */
  real_T Zeros_Value_m[12];            /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S167>/Zeros'
                                        */
  real_T Out_Y0_d;                     /* Computed Parameter: Out_Y0_d
                                        * Referenced by: '<S214>/Out'
                                        */
  real_T DeadZone_Start_p;             /* Expression: -inf
                                        * Referenced by: '<S227>/Dead Zone'
                                        */
  real_T DeadZone_End_i;               /* Expression: 0
                                        * Referenced by: '<S227>/Dead Zone'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<S227>/Gain2'
                                        */
  real_T Fx_Value_j;                   /* Expression: 0
                                        * Referenced by: '<S230>/Fx'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: Inf
                                        * Referenced by: '<S238>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 0
                                        * Referenced by: '<S238>/Saturation'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S230>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_n[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S236>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloci_d[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S236>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S236>/Gain2'
                                        */
  real_T Fx1_Value_g;                  /* Expression: 0
                                        * Referenced by: '<S229>/Fx1'
                                        */
  real_T Gain_Gain_m4;                 /* Expression: -1
                                        * Referenced by: '<S229>/Gain'
                                        */
  real_T Fx2_Value_j[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S229>/Fx2'
                                        */
  real_T Zeros_Value_m2[12];           /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S215>/Zeros'
                                        */
  real_T Out_Y0_m;                     /* Computed Parameter: Out_Y0_m
                                        * Referenced by: '<S262>/Out'
                                        */
  real_T DeadZone_Start_a;             /* Expression: -inf
                                        * Referenced by: '<S275>/Dead Zone'
                                        */
  real_T DeadZone_End_l;               /* Expression: 0
                                        * Referenced by: '<S275>/Dead Zone'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: -1
                                        * Referenced by: '<S275>/Gain2'
                                        */
  real_T Fx_Value_p;                   /* Expression: 0
                                        * Referenced by: '<S278>/Fx'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: Inf
                                        * Referenced by: '<S286>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S286>/Saturation'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S278>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_p[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S284>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloci_a[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S284>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S284>/Gain2'
                                        */
  real_T Fx1_Value_f;                  /* Expression: 0
                                        * Referenced by: '<S277>/Fx1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S277>/Gain'
                                        */
  real_T Fx2_Value_i[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S277>/Fx2'
                                        */
  real_T Zeros_Value_m4[12];           /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S263>/Zeros'
                                        */
  real_T Out_Y0_n;                     /* Computed Parameter: Out_Y0_n
                                        * Referenced by: '<S382>/Out'
                                        */
  real_T DeadZone_Start_n;             /* Expression: -inf
                                        * Referenced by: '<S395>/Dead Zone'
                                        */
  real_T DeadZone_End_ln;              /* Expression: 0
                                        * Referenced by: '<S395>/Dead Zone'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S395>/Gain2'
                                        */
  real_T Fx_Value_o;                   /* Expression: 0
                                        * Referenced by: '<S398>/Fx'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: Inf
                                        * Referenced by: '<S406>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
                                        * Referenced by: '<S406>/Saturation'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S398>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_i[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S404>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloc_ao[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S404>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_c;                 /* Expression: 1
                                        * Referenced by: '<S404>/Gain2'
                                        */
  real_T Fx1_Value_c;                  /* Expression: 0
                                        * Referenced by: '<S397>/Fx1'
                                        */
  real_T Gain_Gain_mo;                 /* Expression: -1
                                        * Referenced by: '<S397>/Gain'
                                        */
  real_T Fx2_Value_o[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S397>/Fx2'
                                        */
  real_T Zeros_Value_h[12];            /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S383>/Zeros'
                                        */
  real_T Out_Y0_f;                     /* Computed Parameter: Out_Y0_f
                                        * Referenced by: '<S430>/Out'
                                        */
  real_T DeadZone_Start_i;             /* Expression: -inf
                                        * Referenced by: '<S443>/Dead Zone'
                                        */
  real_T DeadZone_End_m;               /* Expression: 0
                                        * Referenced by: '<S443>/Dead Zone'
                                        */
  real_T Gain2_Gain_f3;                /* Expression: -1
                                        * Referenced by: '<S443>/Gain2'
                                        */
  real_T Fx_Value_b;                   /* Expression: 0
                                        * Referenced by: '<S446>/Fx'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: Inf
                                        * Referenced by: '<S454>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0
                                        * Referenced by: '<S454>/Saturation'
                                        */
  real_T Gain_Gain_mj;                 /* Expression: -1
                                        * Referenced by: '<S446>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_m[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S452>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloc_mt[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S452>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_fy;                /* Expression: 1
                                        * Referenced by: '<S452>/Gain2'
                                        */
  real_T Fx1_Value_j;                  /* Expression: 0
                                        * Referenced by: '<S445>/Fx1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -1
                                        * Referenced by: '<S445>/Gain'
                                        */
  real_T Fx2_Value_h[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S445>/Fx2'
                                        */
  real_T Zeros_Value_c[12];            /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S431>/Zeros'
                                        */
  real_T Out_Y0_e;                     /* Computed Parameter: Out_Y0_e
                                        * Referenced by: '<S478>/Out'
                                        */
  real_T DeadZone_Start_n5;            /* Expression: -inf
                                        * Referenced by: '<S491>/Dead Zone'
                                        */
  real_T DeadZone_End_k;               /* Expression: 0
                                        * Referenced by: '<S491>/Dead Zone'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: -1
                                        * Referenced by: '<S491>/Gain2'
                                        */
  real_T Fx_Value_l;                   /* Expression: 0
                                        * Referenced by: '<S494>/Fx'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: Inf
                                        * Referenced by: '<S502>/Saturation'
                                        */
  real_T Saturation_LowerSat_g5;       /* Expression: 0
                                        * Referenced by: '<S502>/Saturation'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S494>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloc_nk[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S500>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloc_ab[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S500>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_f1;                /* Expression: 1
                                        * Referenced by: '<S500>/Gain2'
                                        */
  real_T Fx1_Value_k;                  /* Expression: 0
                                        * Referenced by: '<S493>/Fx1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S493>/Gain'
                                        */
  real_T Fx2_Value_ip[3];              /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S493>/Fx2'
                                        */
  real_T Zeros_Value_d[12];            /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S479>/Zeros'
                                        */
  real_T Out_Y0_d3;                    /* Computed Parameter: Out_Y0_d3
                                        * Referenced by: '<S526>/Out'
                                        */
  real_T DeadZone_Start_o;             /* Expression: -inf
                                        * Referenced by: '<S539>/Dead Zone'
                                        */
  real_T DeadZone_End_j;               /* Expression: 0
                                        * Referenced by: '<S539>/Dead Zone'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S539>/Gain2'
                                        */
  real_T Fx_Value_oe;                  /* Expression: 0
                                        * Referenced by: '<S542>/Fx'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: Inf
                                        * Referenced by: '<S550>/Saturation'
                                        */
  real_T Saturation_LowerSat_af;       /* Expression: 0
                                        * Referenced by: '<S550>/Saturation'
                                        */
  real_T Gain_Gain_ns;                 /* Expression: -1
                                        * Referenced by: '<S542>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloc_in[6];/* Expression: [-muk -muk -mus mus  muk muk]
                                             * Referenced by: '<S548>/Coefficient of Friction vs Velocity'
                                             */
  real_T CoefficientofFrictionvsVeloc_lt[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S548>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S548>/Gain2'
                                        */
  real_T Fx1_Value_o;                  /* Expression: 0
                                        * Referenced by: '<S541>/Fx1'
                                        */
  real_T Gain_Gain_jj;                 /* Expression: -1
                                        * Referenced by: '<S541>/Gain'
                                        */
  real_T Fx2_Value_he[3];              /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S541>/Fx2'
                                        */
  real_T Zeros_Value_du[12];           /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S527>/Zeros'
                                        */
  real_T Constant_Value;               /* Expression: period
                                        * Referenced by: '<S572>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[40];    /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S572>/Look-Up Table1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 50
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T TransportDelay_Delay;         /* Expression: 1
                                        * Referenced by: '<S4>/Transport Delay'
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S4>/Transport Delay'
                                        */
  real_T Constant_Value_l;             /* Expression: 33
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Gain2_Gain_ax;                /* Expression: pi/180
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T Gain5_Gain;                   /* Expression: 0
                                        * Referenced by: '<S15>/Gain5'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0
                                        * Referenced by: '<S15>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S15>/Gain3'
                                        */
  real_T Gain_Gain_ap;                 /* Expression: 0
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant8'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant7'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant6'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Gain2_Gain_aq;                /* Expression: pi/180
                                        * Referenced by: '<S24>/Gain2'
                                        */
  real_T Gain5_Gain_m;                 /* Expression: 0
                                        * Referenced by: '<S24>/Gain5'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: pi/180
                                        * Referenced by: '<S24>/Gain1'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: 0
                                        * Referenced by: '<S24>/Gain4'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: pi/180
                                        * Referenced by: '<S24>/Gain3'
                                        */
  real_T Gain_Gain_no;                 /* Expression: 0
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Constant_Value_a;             /* Expression: period
                                        * Referenced by: '<S574>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_l[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S574>/Look-Up Table1'
                                        */
  real_T Constant_Value_c;             /* Expression: period
                                        * Referenced by: '<S575>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_i[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S575>/Look-Up Table1'
                                        */
  real_T Constant_Value_i;             /* Expression: period
                                        * Referenced by: '<S571>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_f[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S571>/Look-Up Table1'
                                        */
  real_T Constant_Value_ah;            /* Expression: period
                                        * Referenced by: '<S573>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_n[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S573>/Look-Up Table1'
                                        */
  real_T Constant_Value_b;             /* Expression: period
                                        * Referenced by: '<S576>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_d[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S576>/Look-Up Table1'
                                        */
  real_T Constant_Value_k;             /* Expression: period
                                        * Referenced by: '<S577>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_k[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S577>/Look-Up Table1'
                                        */
  real_T Constant_Value_h;             /* Expression: period
                                        * Referenced by: '<S578>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_kg[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S578>/Look-Up Table1'
                                        */
  real_T Constant_Value_j;             /* Expression: period
                                        * Referenced by: '<S579>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_j[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S579>/Look-Up Table1'
                                        */
  real_T Constant_Value_cw;            /* Expression: period
                                        * Referenced by: '<S580>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_p[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S580>/Look-Up Table1'
                                        */
  real_T Constant_Value_o;             /* Expression: period
                                        * Referenced by: '<S581>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_m[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S581>/Look-Up Table1'
                                        */
  real_T Constant_Value_bu;            /* Expression: period
                                        * Referenced by: '<S582>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_b[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S582>/Look-Up Table1'
                                        */
  real_T GAIN_Gain;                    /* Expression: pm_unit('m', 'cm', 'linear')
                                        * Referenced by: '<S6>/GAIN'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 2
                                        * Referenced by: '<S379>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S379>/Gain1'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 2
                                        * Referenced by: '<S427>/Gain'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 2
                                        * Referenced by: '<S427>/Gain1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 2
                                        * Referenced by: '<S475>/Gain'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S475>/Gain1'
                                        */
  real_T Gain_Gain_dr;                 /* Expression: 2
                                        * Referenced by: '<S523>/Gain'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S523>/Gain1'
                                        */
  real_T GAIN_Gain_o;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S352>/GAIN'
                                        */
  real_T Gain_Gain_nz;                 /* Expression: 2
                                        * Referenced by: '<S115>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 2
                                        * Referenced by: '<S115>/Gain1'
                                        */
  real_T Merge_InitialOutput;          /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S58>/Merge'
                                        */
  real_T Gain_Gain_gs;                 /* Expression: 2
                                        * Referenced by: '<S163>/Gain'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S163>/Gain1'
                                        */
  real_T Merge_InitialOutput_n;        /* Computed Parameter: Merge_InitialOutput_n
                                        * Referenced by: '<S59>/Merge'
                                        */
  real_T Gain_Gain_gp;                 /* Expression: 2
                                        * Referenced by: '<S211>/Gain'
                                        */
  real_T Gain1_Gain_kc;                /* Expression: 2
                                        * Referenced by: '<S211>/Gain1'
                                        */
  real_T Merge_InitialOutput_d;        /* Computed Parameter: Merge_InitialOutput_d
                                        * Referenced by: '<S60>/Merge'
                                        */
  real_T Gain_Gain_a0;                 /* Expression: 2
                                        * Referenced by: '<S259>/Gain'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S259>/Gain1'
                                        */
  real_T Merge_InitialOutput_nd;       /* Computed Parameter: Merge_InitialOutput_nd
                                        * Referenced by: '<S61>/Merge'
                                        */
  real_T Merge_InitialOutput_k;        /* Computed Parameter: Merge_InitialOutput_k
                                        * Referenced by: '<S322>/Merge'
                                        */
  real_T Merge_InitialOutput_o;        /* Computed Parameter: Merge_InitialOutput_o
                                        * Referenced by: '<S323>/Merge'
                                        */
  real_T Merge_InitialOutput_m;        /* Computed Parameter: Merge_InitialOutput_m
                                        * Referenced by: '<S324>/Merge'
                                        */
  real_T Merge_InitialOutput_e;        /* Computed Parameter: Merge_InitialOutput_e
                                        * Referenced by: '<S325>/Merge'
                                        */
  real_T GAIN_Gain_h;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S346>/GAIN'
                                        */
  real_T GAIN_Gain_c;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S364>/GAIN'
                                        */
  real_T GAIN_Gain_p;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S358>/GAIN'
                                        */
  real_T GAIN_Gain_ci;                 /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S334>/GAIN'
                                        */
  real_T GAIN_Gain_k;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S370>/GAIN'
                                        */
  real_T GAIN_Gain_cu;                 /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S88>/GAIN'
                                        */
  real_T GAIN_Gain_hy;                 /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S82>/GAIN'
                                        */
  real_T GAIN_Gain_pv;                 /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S100>/GAIN'
                                        */
  real_T GAIN_Gain_e;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S94>/GAIN'
                                        */
  real_T GAIN_Gain_a;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S70>/GAIN'
                                        */
  real_T GAIN_Gain_m;                  /* Expression: pm_unit('rad', 'deg', 'linear')
                                        * Referenced by: '<S106>/GAIN'
                                        */
  real_T UDPConfigure_P1_Size[2];      /* Computed Parameter: UDPConfigure_P1_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P1[4];           /* Expression: ipAdd
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P2_Size[2];      /* Computed Parameter: UDPConfigure_P2_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P2[4];           /* Expression: snMask
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P3_Size[2];      /* Computed Parameter: UDPConfigure_P3_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P3[4];           /* Expression: gwAdd
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P4_Size[2];      /* Computed Parameter: UDPConfigure_P4_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P5_Size[2];      /* Computed Parameter: UDPConfigure_P5_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P5;              /* Expression: enableMulticast
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P6_Size[2];      /* Computed Parameter: UDPConfigure_P6_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P7_Size[2];      /* Computed Parameter: UDPConfigure_P7_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P8_Size[2];      /* Computed Parameter: UDPConfigure_P8_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P8;              /* Expression: PciBus
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P9_Size[2];      /* Computed Parameter: UDPConfigure_P9_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P9;              /* Expression: PciSlot
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P10_Size[2];     /* Computed Parameter: UDPConfigure_P10_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P10;             /* Expression: PciFunction
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P11_Size[2];     /* Computed Parameter: UDPConfigure_P11_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P11;             /* Expression: tune
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P12_Size[2];     /* Computed Parameter: UDPConfigure_P12_Size
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T UDPConfigure_P12;             /* Expression: 0
                                        * Referenced by: '<S4>/UDP Configure'
                                        */
  real_T GAIN_Gain_mq;                 /* Expression: pm_unit('1', 'deg', 'linear')
                                        * Referenced by: '<S307>/GAIN'
                                        */
  real_T Constant_Value_c0;            /* Expression: period
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_c[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T Constant_Value_ld;            /* Expression: period
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_pu[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S10>/Look-Up Table1'
                                        */
  real_T Constant_Value_ahx;           /* Expression: period
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_pc[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S11>/Look-Up Table1'
                                        */
  real_T Constant_Value_e;             /* Expression: period
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_cv[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S12>/Look-Up Table1'
                                        */
  real_T Constant_Value_ca;            /* Expression: period
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_m4[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S13>/Look-Up Table1'
                                        */
  real_T Constant_Value_ci;            /* Expression: period
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_cm[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S14>/Look-Up Table1'
                                        */
  real_T Constant_Value_ii;            /* Expression: period
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_bl[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S18>/Look-Up Table1'
                                        */
  real_T Constant_Value_n;             /* Expression: period
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_fq[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S19>/Look-Up Table1'
                                        */
  real_T Constant_Value_d;             /* Expression: period
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_dg[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S20>/Look-Up Table1'
                                        */
  real_T Constant_Value_de;            /* Expression: period
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_jd[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S21>/Look-Up Table1'
                                        */
  real_T Constant_Value_f;             /* Expression: period
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_g[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S22>/Look-Up Table1'
                                        */
  real_T Constant_Value_hw;            /* Expression: period
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_gn[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S23>/Look-Up Table1'
                                        */
  real_T Gain_Gain_gm;                 /* Expression: 11.2
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Constant_Value_ir;            /* Expression: 2036
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Gain_Gain_jt;                 /* Expression: 11.2
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Constant_Value_lc;            /* Expression: 2036
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 11.2
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 2036
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 11.2
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Constant_Value_jj;            /* Expression: 2036
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Gain_Gain_pn;                 /* Expression: 11.2
                                        * Referenced by: '<S41>/Gain'
                                        */
  real_T Constant_Value_ch;            /* Expression: 2036
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Gain_Gain_iz;                 /* Expression: 11.2
                                        * Referenced by: '<S40>/Gain'
                                        */
  real_T Constant_Value_k0;            /* Expression: 2036
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Gain_Gain_nu;                 /* Expression: 11.2
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Constant_Value_ih;            /* Expression: 2036
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Gain_Gain_dl;                 /* Expression: 11.2
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T Constant_Value_dx;            /* Expression: 2036
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Gain_Gain_nx;                 /* Expression: 11.2
                                        * Referenced by: '<S37>/Gain'
                                        */
  real_T Constant_Value_od;            /* Expression: 2036
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Gain_Gain_mo4;                /* Expression: 11.2
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T Constant_Value_pq;            /* Expression: 2036
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Gain_Gain_nu0;                /* Expression: 11.2
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Constant_Value_dr;            /* Expression: 2036
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Gain_Gain_nv;                 /* Expression: 11.2
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Constant_Value_mm;            /* Expression: 2036
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T ASCIIEncode2_P1_Size[2];      /* Computed Parameter: ASCIIEncode2_P1_Size
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P1[35];          /* Computed Parameter: ASCIIEncode2_P1
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P2_Size[2];      /* Computed Parameter: ASCIIEncode2_P2_Size
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P2;              /* Expression: maxlength
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P3_Size[2];      /* Computed Parameter: ASCIIEncode2_P3_Size
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P3;              /* Expression: nvars
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P4_Size[2];      /* Computed Parameter: ASCIIEncode2_P4_Size
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P4[12];          /* Expression: varids
                                        * Referenced by: '<S4>/ASCII Encode 2'
                                        */
  real_T Constant3_Value;              /* Expression: 59
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T UDPSend_P1_Size[2];           /* Computed Parameter: UDPSend_P1_Size
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P1[11];               /* Computed Parameter: UDPSend_P1
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P2_Size[2];           /* Computed Parameter: UDPSend_P2_Size
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P2;                   /* Expression: localPort
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P3_Size[2];           /* Computed Parameter: UDPSend_P3_Size
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P3[13];               /* Computed Parameter: UDPSend_P3
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P4_Size[2];           /* Computed Parameter: UDPSend_P4_Size
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P4;                   /* Expression: toPort
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P5_Size[2];           /* Computed Parameter: UDPSend_P5_Size
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P5;                   /* Expression: useHostTargetComm
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P6_Size[2];           /* Computed Parameter: UDPSend_P6_Size
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  real_T UDPSend_P6;                   /* Expression: sampleTime
                                        * Referenced by: '<S4>/UDP Send'
                                        */
  P_SwitchCaseActionSubsystem_C_T SwitchCaseActionSubsystem1;/* '<S4>/Switch Case Action Subsystem1' */
  P_SwitchCaseActionSubsystem_C_T SwitchCaseActionSubsystem;/* '<S4>/Switch Case Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_Robot_leg_3_0_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[3];
    SimStruct *childSFunctionPtrs[3];
    struct _ssBlkInfo2 blkInfo2[3];
    struct _ssSFcnModelMethods2 methods2[3];
    struct _ssSFcnModelMethods3 methods3[3];
    struct _ssSFcnModelMethods4 methods4[3];
    struct _ssStatesInfo2 statesInfo2[3];
    ssPeriodicStatesInfo periodicStatesInfo[3];
    struct _ssPortInfo2 inputOutputPortInfo2[3];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[12];
      struct _ssInPortUnit inputPortUnits[12];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[12];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      real_T const *UPtrs4[1];
      real_T const *UPtrs5[1];
      real_T const *UPtrs6[1];
      real_T const *UPtrs7[1];
      real_T const *UPtrs8[1];
      real_T const *UPtrs9[1];
      real_T const *UPtrs10[1];
      real_T const *UPtrs11[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn2;
  } NonInlinedSFcns;

  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[37];
  real_T odeF[3][37];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_P;

/* Block signals (default storage) */
extern B_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_B;

/* Continuous states (default storage) */
extern X_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_X;

/* Block states (default storage) */
extern DW_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Copy_of_Robot_leg_3_0_T Copy_of_Robot_leg_3_0_Y;

/* Model entry point functions */
extern void Copy_of_Robot_leg_3_0_initialize(void);
extern void Copy_of_Robot_leg_3_0_output(void);
extern void Copy_of_Robot_leg_3_0_update(void);
extern void Copy_of_Robot_leg_3_0_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Copy_of_Robot_leg_3_0_rtModel *Copy_of_Robot_leg_3_0(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  Copy_of_Robot_leg_3_0_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_Robot_leg_3_0_T *const Copy_of_Robot_leg_3_0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Copy_of_Robot_leg_3_0'
 * '<S1>'   : 'Copy_of_Robot_leg_3_0/PS-Simulink Converter'
 * '<S2>'   : 'Copy_of_Robot_leg_3_0/PS-Simulink Converter1'
 * '<S3>'   : 'Copy_of_Robot_leg_3_0/PS-Simulink Converter2'
 * '<S4>'   : 'Copy_of_Robot_leg_3_0/Robot'
 * '<S5>'   : 'Copy_of_Robot_leg_3_0/Solver Configuration'
 * '<S6>'   : 'Copy_of_Robot_leg_3_0/PS-Simulink Converter/EVAL_KEY'
 * '<S7>'   : 'Copy_of_Robot_leg_3_0/PS-Simulink Converter1/EVAL_KEY'
 * '<S8>'   : 'Copy_of_Robot_leg_3_0/PS-Simulink Converter2/EVAL_KEY'
 * '<S9>'   : 'Copy_of_Robot_leg_3_0/Robot/Left Abduction1'
 * '<S10>'  : 'Copy_of_Robot_leg_3_0/Robot/Left Ankle Twist1'
 * '<S11>'  : 'Copy_of_Robot_leg_3_0/Robot/Left Ankle1'
 * '<S12>'  : 'Copy_of_Robot_leg_3_0/Robot/Left Hip1'
 * '<S13>'  : 'Copy_of_Robot_leg_3_0/Robot/Left Knee1'
 * '<S14>'  : 'Copy_of_Robot_leg_3_0/Robot/Left Rotation1'
 * '<S15>'  : 'Copy_of_Robot_leg_3_0/Robot/Left Support Leg'
 * '<S16>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg'
 * '<S17>'  : 'Copy_of_Robot_leg_3_0/Robot/PS-Simulink Converter4'
 * '<S18>'  : 'Copy_of_Robot_leg_3_0/Robot/Right Abduction1'
 * '<S19>'  : 'Copy_of_Robot_leg_3_0/Robot/Right Ankle Twist1'
 * '<S20>'  : 'Copy_of_Robot_leg_3_0/Robot/Right Ankle1'
 * '<S21>'  : 'Copy_of_Robot_leg_3_0/Robot/Right Hip1'
 * '<S22>'  : 'Copy_of_Robot_leg_3_0/Robot/Right Knee1'
 * '<S23>'  : 'Copy_of_Robot_leg_3_0/Robot/Right Rotation1'
 * '<S24>'  : 'Copy_of_Robot_leg_3_0/Robot/Right Support Leg'
 * '<S25>'  : 'Copy_of_Robot_leg_3_0/Robot/Right_leg'
 * '<S26>'  : 'Copy_of_Robot_leg_3_0/Robot/Scope '
 * '<S27>'  : 'Copy_of_Robot_leg_3_0/Robot/Scope 3'
 * '<S28>'  : 'Copy_of_Robot_leg_3_0/Robot/Scope 4'
 * '<S29>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem'
 * '<S30>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem1'
 * '<S31>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem10'
 * '<S32>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem11'
 * '<S33>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem12'
 * '<S34>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem2'
 * '<S35>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem3'
 * '<S36>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem4'
 * '<S37>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem5'
 * '<S38>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem6'
 * '<S39>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem7'
 * '<S40>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem8'
 * '<S41>'  : 'Copy_of_Robot_leg_3_0/Robot/Subsystem9'
 * '<S42>'  : 'Copy_of_Robot_leg_3_0/Robot/Switch Case Action Subsystem'
 * '<S43>'  : 'Copy_of_Robot_leg_3_0/Robot/Switch Case Action Subsystem1'
 * '<S44>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Abduction Meas'
 * '<S45>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/All measurements'
 * '<S46>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Meas'
 * '<S47>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Twist Meas'
 * '<S48>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Contact Force Logging'
 * '<S49>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Hip Meas'
 * '<S50>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Knee Meas'
 * '<S51>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Rotation Meas'
 * '<S52>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter'
 * '<S53>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter1'
 * '<S54>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter2'
 * '<S55>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter3'
 * '<S56>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter4'
 * '<S57>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter5'
 * '<S58>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force'
 * '<S59>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1'
 * '<S60>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2'
 * '<S61>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3'
 * '<S62>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/left_abduction_RIGID'
 * '<S63>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/left_ankle_RIGID'
 * '<S64>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/left_flextion_RIGID'
 * '<S65>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/left_knee_RIGID'
 * '<S66>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/left_rotation_RIGID'
 * '<S67>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Abduction Meas/PS-Simulink Converter'
 * '<S68>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Abduction Meas/PS-Simulink Converter1'
 * '<S69>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Abduction Meas/PS-Simulink Converter2'
 * '<S70>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Abduction Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S71>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Abduction Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S72>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Abduction Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S73>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/All measurements/Extract Measurements'
 * '<S74>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/All measurements/Extract Measurements1'
 * '<S75>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/All measurements/Extract Measurements2'
 * '<S76>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/All measurements/Extract Measurements3'
 * '<S77>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/All measurements/Extract Measurements4'
 * '<S78>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/All measurements/Extract Measurements5'
 * '<S79>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Meas/PS-Simulink Converter'
 * '<S80>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Meas/PS-Simulink Converter1'
 * '<S81>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Meas/PS-Simulink Converter2'
 * '<S82>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S83>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S84>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S85>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Twist Meas/PS-Simulink Converter'
 * '<S86>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Twist Meas/PS-Simulink Converter1'
 * '<S87>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Twist Meas/PS-Simulink Converter2'
 * '<S88>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Twist Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S89>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Twist Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S90>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Ankle Twist Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S91>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Hip Meas/PS-Simulink Converter'
 * '<S92>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Hip Meas/PS-Simulink Converter1'
 * '<S93>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Hip Meas/PS-Simulink Converter2'
 * '<S94>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Hip Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S95>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Hip Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S96>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Hip Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S97>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Knee Meas/PS-Simulink Converter'
 * '<S98>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Knee Meas/PS-Simulink Converter1'
 * '<S99>'  : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Knee Meas/PS-Simulink Converter2'
 * '<S100>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Knee Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S101>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Knee Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S102>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Knee Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S103>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Rotation Meas/PS-Simulink Converter'
 * '<S104>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Rotation Meas/PS-Simulink Converter1'
 * '<S105>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Rotation Meas/PS-Simulink Converter2'
 * '<S106>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Rotation Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S107>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Rotation Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S108>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Rotation Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S109>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter/EVAL_KEY'
 * '<S110>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter1/EVAL_KEY'
 * '<S111>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter2/EVAL_KEY'
 * '<S112>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter3/EVAL_KEY'
 * '<S113>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter4/EVAL_KEY'
 * '<S114>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Simulink-PS Converter5/EVAL_KEY'
 * '<S115>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane'
 * '<S116>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux'
 * '<S117>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Enable Outputs'
 * '<S118>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces'
 * '<S119>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/No Force'
 * '<S120>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing'
 * '<S121>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc x-axis'
 * '<S122>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc y-axis'
 * '<S123>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter'
 * '<S124>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter1'
 * '<S125>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter2'
 * '<S126>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter6'
 * '<S127>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S128>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S129>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S130>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S131>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration'
 * '<S132>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product'
 * '<S133>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Ff'
 * '<S134>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Fn'
 * '<S135>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Force Law'
 * '<S136>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product'
 * '<S137>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Friction Law'
 * '<S138>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel'
 * '<S139>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Friction Law/None'
 * '<S140>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S141>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Custom'
 * '<S142>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Linear'
 * '<S143>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Nonlinear'
 * '<S144>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S145>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter'
 * '<S146>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter1'
 * '<S147>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter2'
 * '<S148>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter3'
 * '<S149>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter4'
 * '<S150>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter5'
 * '<S151>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter6'
 * '<S152>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter7'
 * '<S153>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter8'
 * '<S154>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S155>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S156>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S157>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S158>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S159>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S160>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S161>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S162>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S163>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane'
 * '<S164>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux'
 * '<S165>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Enable Outputs'
 * '<S166>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces'
 * '<S167>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/No Force'
 * '<S168>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing'
 * '<S169>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc x-axis'
 * '<S170>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc y-axis'
 * '<S171>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter'
 * '<S172>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter1'
 * '<S173>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter2'
 * '<S174>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter6'
 * '<S175>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S176>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S177>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S178>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S179>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration'
 * '<S180>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product'
 * '<S181>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Ff'
 * '<S182>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Fn'
 * '<S183>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law'
 * '<S184>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product'
 * '<S185>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Friction Law'
 * '<S186>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel'
 * '<S187>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/None'
 * '<S188>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S189>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Custom'
 * '<S190>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Linear'
 * '<S191>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Nonlinear'
 * '<S192>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S193>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter'
 * '<S194>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter1'
 * '<S195>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter2'
 * '<S196>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter3'
 * '<S197>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter4'
 * '<S198>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter5'
 * '<S199>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter6'
 * '<S200>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter7'
 * '<S201>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter8'
 * '<S202>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S203>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S204>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S205>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S206>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S207>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S208>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S209>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S210>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S211>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane'
 * '<S212>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux'
 * '<S213>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Enable Outputs'
 * '<S214>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces'
 * '<S215>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/No Force'
 * '<S216>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing'
 * '<S217>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc x-axis'
 * '<S218>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc y-axis'
 * '<S219>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter'
 * '<S220>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter1'
 * '<S221>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter2'
 * '<S222>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter6'
 * '<S223>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S224>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S225>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S226>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S227>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration'
 * '<S228>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product'
 * '<S229>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Ff'
 * '<S230>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Fn'
 * '<S231>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law'
 * '<S232>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product'
 * '<S233>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Friction Law'
 * '<S234>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel'
 * '<S235>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/None'
 * '<S236>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S237>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Custom'
 * '<S238>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Linear'
 * '<S239>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Nonlinear'
 * '<S240>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S241>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter'
 * '<S242>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter1'
 * '<S243>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter2'
 * '<S244>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter3'
 * '<S245>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter4'
 * '<S246>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter5'
 * '<S247>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter6'
 * '<S248>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter7'
 * '<S249>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter8'
 * '<S250>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S251>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S252>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S253>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S254>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S255>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S256>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S257>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S258>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S259>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane'
 * '<S260>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux'
 * '<S261>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Enable Outputs'
 * '<S262>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces'
 * '<S263>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/No Force'
 * '<S264>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing'
 * '<S265>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc x-axis'
 * '<S266>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc y-axis'
 * '<S267>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter'
 * '<S268>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter1'
 * '<S269>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter2'
 * '<S270>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter6'
 * '<S271>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S272>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S273>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S274>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S275>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration'
 * '<S276>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product'
 * '<S277>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Ff'
 * '<S278>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Fn'
 * '<S279>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law'
 * '<S280>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product'
 * '<S281>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Friction Law'
 * '<S282>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel'
 * '<S283>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/None'
 * '<S284>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S285>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Custom'
 * '<S286>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Linear'
 * '<S287>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Nonlinear'
 * '<S288>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S289>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter'
 * '<S290>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter1'
 * '<S291>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter2'
 * '<S292>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter3'
 * '<S293>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter4'
 * '<S294>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter5'
 * '<S295>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter6'
 * '<S296>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter7'
 * '<S297>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter8'
 * '<S298>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S299>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S300>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S301>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S302>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S303>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S304>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S305>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S306>' : 'Copy_of_Robot_leg_3_0/Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S307>' : 'Copy_of_Robot_leg_3_0/Robot/PS-Simulink Converter4/EVAL_KEY'
 * '<S308>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Abduction Meas'
 * '<S309>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/All measurements'
 * '<S310>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Meas'
 * '<S311>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Twist Meas'
 * '<S312>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Contact Force Logging'
 * '<S313>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Hip Meas'
 * '<S314>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Knee Meas'
 * '<S315>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Rotation Meas'
 * '<S316>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter'
 * '<S317>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter1'
 * '<S318>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter2'
 * '<S319>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter3'
 * '<S320>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter4'
 * '<S321>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter5'
 * '<S322>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force'
 * '<S323>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1'
 * '<S324>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2'
 * '<S325>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3'
 * '<S326>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/right_abduction_RIGID'
 * '<S327>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/right_ankle_RIGID'
 * '<S328>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/right_flextion_RIGID'
 * '<S329>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/right_knee_RIGID'
 * '<S330>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/right_rotation_RIGID'
 * '<S331>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Abduction Meas/PS-Simulink Converter'
 * '<S332>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Abduction Meas/PS-Simulink Converter1'
 * '<S333>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Abduction Meas/PS-Simulink Converter2'
 * '<S334>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Abduction Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S335>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Abduction Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S336>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Abduction Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S337>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/All measurements/Extract Measurements'
 * '<S338>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/All measurements/Extract Measurements1'
 * '<S339>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/All measurements/Extract Measurements2'
 * '<S340>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/All measurements/Extract Measurements3'
 * '<S341>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/All measurements/Extract Measurements4'
 * '<S342>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/All measurements/Extract Measurements5'
 * '<S343>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Meas/PS-Simulink Converter'
 * '<S344>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Meas/PS-Simulink Converter1'
 * '<S345>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Meas/PS-Simulink Converter2'
 * '<S346>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S347>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S348>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S349>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Twist Meas/PS-Simulink Converter'
 * '<S350>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Twist Meas/PS-Simulink Converter1'
 * '<S351>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Twist Meas/PS-Simulink Converter2'
 * '<S352>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Twist Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S353>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Twist Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S354>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Ankle Twist Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S355>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Hip Meas/PS-Simulink Converter'
 * '<S356>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Hip Meas/PS-Simulink Converter1'
 * '<S357>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Hip Meas/PS-Simulink Converter2'
 * '<S358>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Hip Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S359>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Hip Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S360>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Hip Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S361>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Knee Meas/PS-Simulink Converter'
 * '<S362>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Knee Meas/PS-Simulink Converter1'
 * '<S363>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Knee Meas/PS-Simulink Converter2'
 * '<S364>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Knee Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S365>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Knee Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S366>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Knee Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S367>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Rotation Meas/PS-Simulink Converter'
 * '<S368>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Rotation Meas/PS-Simulink Converter1'
 * '<S369>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Rotation Meas/PS-Simulink Converter2'
 * '<S370>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Rotation Meas/PS-Simulink Converter/EVAL_KEY'
 * '<S371>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Rotation Meas/PS-Simulink Converter1/EVAL_KEY'
 * '<S372>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Rotation Meas/PS-Simulink Converter2/EVAL_KEY'
 * '<S373>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter/EVAL_KEY'
 * '<S374>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter1/EVAL_KEY'
 * '<S375>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter2/EVAL_KEY'
 * '<S376>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter3/EVAL_KEY'
 * '<S377>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter4/EVAL_KEY'
 * '<S378>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Simulink-PS Converter5/EVAL_KEY'
 * '<S379>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane'
 * '<S380>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux'
 * '<S381>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Enable Outputs'
 * '<S382>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces'
 * '<S383>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/No Force'
 * '<S384>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing'
 * '<S385>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc x-axis'
 * '<S386>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc y-axis'
 * '<S387>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter'
 * '<S388>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter1'
 * '<S389>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter2'
 * '<S390>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter6'
 * '<S391>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S392>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S393>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S394>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S395>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration'
 * '<S396>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product'
 * '<S397>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Ff'
 * '<S398>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Fn'
 * '<S399>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Force Law'
 * '<S400>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product'
 * '<S401>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Friction Law'
 * '<S402>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel'
 * '<S403>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Friction Law/None'
 * '<S404>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S405>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Custom'
 * '<S406>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Linear'
 * '<S407>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Nonlinear'
 * '<S408>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S409>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter'
 * '<S410>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter1'
 * '<S411>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter2'
 * '<S412>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter3'
 * '<S413>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter4'
 * '<S414>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter5'
 * '<S415>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter6'
 * '<S416>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter7'
 * '<S417>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter8'
 * '<S418>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S419>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S420>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S421>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S422>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S423>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S424>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S425>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S426>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S427>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane'
 * '<S428>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux'
 * '<S429>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Enable Outputs'
 * '<S430>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces'
 * '<S431>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/No Force'
 * '<S432>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing'
 * '<S433>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc x-axis'
 * '<S434>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc y-axis'
 * '<S435>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter'
 * '<S436>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter1'
 * '<S437>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter2'
 * '<S438>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter6'
 * '<S439>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S440>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S441>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S442>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S443>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration'
 * '<S444>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product'
 * '<S445>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Ff'
 * '<S446>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Fn'
 * '<S447>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law'
 * '<S448>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product'
 * '<S449>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Friction Law'
 * '<S450>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel'
 * '<S451>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/None'
 * '<S452>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S453>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Custom'
 * '<S454>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Linear'
 * '<S455>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Nonlinear'
 * '<S456>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S457>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter'
 * '<S458>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter1'
 * '<S459>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter2'
 * '<S460>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter3'
 * '<S461>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter4'
 * '<S462>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter5'
 * '<S463>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter6'
 * '<S464>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter7'
 * '<S465>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter8'
 * '<S466>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S467>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S468>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S469>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S470>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S471>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S472>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S473>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S474>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S475>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane'
 * '<S476>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux'
 * '<S477>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Enable Outputs'
 * '<S478>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces'
 * '<S479>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/No Force'
 * '<S480>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing'
 * '<S481>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc x-axis'
 * '<S482>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc y-axis'
 * '<S483>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter'
 * '<S484>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter1'
 * '<S485>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter2'
 * '<S486>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter6'
 * '<S487>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S488>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S489>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S490>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S491>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration'
 * '<S492>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product'
 * '<S493>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Ff'
 * '<S494>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Fn'
 * '<S495>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law'
 * '<S496>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product'
 * '<S497>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Friction Law'
 * '<S498>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel'
 * '<S499>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/None'
 * '<S500>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S501>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Custom'
 * '<S502>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Linear'
 * '<S503>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Nonlinear'
 * '<S504>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S505>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter'
 * '<S506>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter1'
 * '<S507>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter2'
 * '<S508>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter3'
 * '<S509>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter4'
 * '<S510>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter5'
 * '<S511>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter6'
 * '<S512>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter7'
 * '<S513>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter8'
 * '<S514>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S515>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S516>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S517>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S518>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S519>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S520>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S521>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S522>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S523>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane'
 * '<S524>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux'
 * '<S525>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Enable Outputs'
 * '<S526>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces'
 * '<S527>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/No Force'
 * '<S528>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing'
 * '<S529>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc x-axis'
 * '<S530>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc y-axis'
 * '<S531>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter'
 * '<S532>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter1'
 * '<S533>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter2'
 * '<S534>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter6'
 * '<S535>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S536>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S537>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S538>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S539>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration'
 * '<S540>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product'
 * '<S541>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Ff'
 * '<S542>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Fn'
 * '<S543>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law'
 * '<S544>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product'
 * '<S545>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Friction Law'
 * '<S546>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel'
 * '<S547>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/None'
 * '<S548>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S549>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Custom'
 * '<S550>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Linear'
 * '<S551>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Nonlinear'
 * '<S552>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Nonlinear/Smoothstep'
 * '<S553>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter'
 * '<S554>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter1'
 * '<S555>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter2'
 * '<S556>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter3'
 * '<S557>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter4'
 * '<S558>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter5'
 * '<S559>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter6'
 * '<S560>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter7'
 * '<S561>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter8'
 * '<S562>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S563>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S564>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S565>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S566>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S567>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S568>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S569>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S570>' : 'Copy_of_Robot_leg_3_0/Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S571>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Left_Abduction_Motion'
 * '<S572>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Left_Ankle Motion'
 * '<S573>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Left_Ankle_Twist_Motion'
 * '<S574>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Left_Hip_Motion'
 * '<S575>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Left_Knee_Motion'
 * '<S576>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Left_Rotation_Motion'
 * '<S577>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Right_Abduction_Motion'
 * '<S578>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Right_Ankle_Motion'
 * '<S579>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Right_Ankle_Twist_Motion'
 * '<S580>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Right_Hip_Motion'
 * '<S581>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Right_Knee_Motion'
 * '<S582>' : 'Copy_of_Robot_leg_3_0/Robot/Subsystem/Right_Rotation_Motion'
 * '<S583>' : 'Copy_of_Robot_leg_3_0/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_Copy_of_Robot_leg_3_0_h_ */
