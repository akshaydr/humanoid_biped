/*
 * hil_tuning.h
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

#ifndef RTW_HEADER_hil_tuning_h_
#define RTW_HEADER_hil_tuning_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef hil_tuning_COMMON_INCLUDES_
# define hil_tuning_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* hil_tuning_COMMON_INCLUDES_ */

#include "hil_tuning_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

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
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
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
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
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
#define rtModel_hil_tuning             RT_MODEL_hil_tuning_T

/* Definition for use in the target main file */
#define hil_tuning_rtModel             RT_MODEL_hil_tuning_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals (default storage) */
typedef struct {
  real_T UDPReceive_o2;                /* '<Root>/UDP Receive' */
  real_T Clock;                        /* '<S1>/Clock' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T MathFunction;                 /* '<S1>/Math Function' */
  real_T LookUpTable1;                 /* '<S1>/Look-Up Table1' */
  real_T Output;                       /* '<S1>/Output' */
  real_T Clock_c;                      /* '<S2>/Clock' */
  real_T Sum_k;                        /* '<S2>/Sum' */
  real_T MathFunction_p;               /* '<S2>/Math Function' */
  real_T LookUpTable1_k;               /* '<S2>/Look-Up Table1' */
  real_T Output_a;                     /* '<S2>/Output' */
  real_T Clock_j;                      /* '<S3>/Clock' */
  real_T Sum_ks;                       /* '<S3>/Sum' */
  real_T MathFunction_l;               /* '<S3>/Math Function' */
  real_T LookUpTable1_j;               /* '<S3>/Look-Up Table1' */
  real_T Output_d;                     /* '<S3>/Output' */
  real_T Clock_h;                      /* '<S4>/Clock' */
  real_T Sum_m;                        /* '<S4>/Sum' */
  real_T MathFunction_a;               /* '<S4>/Math Function' */
  real_T LookUpTable1_jw;              /* '<S4>/Look-Up Table1' */
  real_T Output_i;                     /* '<S4>/Output' */
  real_T Clock_l;                      /* '<S5>/Clock' */
  real_T Sum_g;                        /* '<S5>/Sum' */
  real_T MathFunction_o;               /* '<S5>/Math Function' */
  real_T LookUpTable1_i;               /* '<S5>/Look-Up Table1' */
  real_T Output_o;                     /* '<S5>/Output' */
  real_T Clock_i;                      /* '<S6>/Clock' */
  real_T Sum_e;                        /* '<S6>/Sum' */
  real_T MathFunction_e;               /* '<S6>/Math Function' */
  real_T LookUpTable1_b;               /* '<S6>/Look-Up Table1' */
  real_T Output_iv;                    /* '<S6>/Output' */
  real_T Clock_f;                      /* '<S7>/Clock' */
  real_T Sum_j;                        /* '<S7>/Sum' */
  real_T MathFunction_f;               /* '<S7>/Math Function' */
  real_T LookUpTable1_o;               /* '<S7>/Look-Up Table1' */
  real_T Output_k;                     /* '<S7>/Output' */
  real_T Clock_p;                      /* '<S8>/Clock' */
  real_T Sum_l;                        /* '<S8>/Sum' */
  real_T MathFunction_d;               /* '<S8>/Math Function' */
  real_T LookUpTable1_m;               /* '<S8>/Look-Up Table1' */
  real_T Output_h;                     /* '<S8>/Output' */
  real_T Clock_fy;                     /* '<S9>/Clock' */
  real_T Sum_b;                        /* '<S9>/Sum' */
  real_T MathFunction_h;               /* '<S9>/Math Function' */
  real_T LookUpTable1_jt;              /* '<S9>/Look-Up Table1' */
  real_T Output_f;                     /* '<S9>/Output' */
  real_T Clock_io;                     /* '<S10>/Clock' */
  real_T Sum_kw;                       /* '<S10>/Sum' */
  real_T MathFunction_b;               /* '<S10>/Math Function' */
  real_T LookUpTable1_f;               /* '<S10>/Look-Up Table1' */
  real_T Output_i5;                    /* '<S10>/Output' */
  real_T Clock_l0;                     /* '<S11>/Clock' */
  real_T Sum_p;                        /* '<S11>/Sum' */
  real_T MathFunction_n;               /* '<S11>/Math Function' */
  real_T LookUpTable1_fg;              /* '<S11>/Look-Up Table1' */
  real_T Output_o4;                    /* '<S11>/Output' */
  real_T Clock_n;                      /* '<S12>/Clock' */
  real_T Sum_eg;                       /* '<S12>/Sum' */
  real_T MathFunction_i;               /* '<S12>/Math Function' */
  real_T LookUpTable1_p;               /* '<S12>/Look-Up Table1' */
  real_T Output_p;                     /* '<S12>/Output' */
  real_T Gain;                         /* '<S13>/Gain' */
  real_T Add;                          /* '<S13>/Add' */
  real_T Gain_g;                       /* '<S15>/Gain' */
  real_T Add_f;                        /* '<S15>/Add' */
  real_T Gain_m;                       /* '<S14>/Gain' */
  real_T Add_a;                        /* '<S14>/Add' */
  real_T Gain_f;                       /* '<S16>/Gain' */
  real_T Add_c;                        /* '<S16>/Add' */
  real_T Gain_j;                       /* '<S24>/Gain' */
  real_T Add_k;                        /* '<S24>/Add' */
  real_T Gain_my;                      /* '<S23>/Gain' */
  real_T Add_cb;                       /* '<S23>/Add' */
  real_T Gain_fl;                      /* '<S22>/Gain' */
  real_T Add_g;                        /* '<S22>/Add' */
  real_T Gain_c;                       /* '<S21>/Gain' */
  real_T Add_o;                        /* '<S21>/Add' */
  real_T Gain_e;                       /* '<S20>/Gain' */
  real_T Add_d;                        /* '<S20>/Add' */
  real_T Gain_k;                       /* '<S19>/Gain' */
  real_T Add_h;                        /* '<S19>/Add' */
  real_T Gain_d;                       /* '<S18>/Gain' */
  real_T Add_ca;                       /* '<S18>/Add' */
  real_T Gain_eb;                      /* '<S17>/Gain' */
  real_T Add_j;                        /* '<S17>/Add' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  uint32_T ASCIIDecode_o1;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o2;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o3;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o4;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o5;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o6;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o7;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o8;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o9;             /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o10;            /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o11;            /* '<Root>/ASCII Decode ' */
  uint32_T ASCIIDecode_o12;            /* '<Root>/ASCII Decode ' */
  uint32_T DataTypeConversion;         /* '<S13>/Data Type Conversion' */
  uint32_T DataTypeConversion_g;       /* '<S15>/Data Type Conversion' */
  uint32_T DataTypeConversion_e;       /* '<S14>/Data Type Conversion' */
  uint32_T DataTypeConversion_j;       /* '<S16>/Data Type Conversion' */
  uint32_T DataTypeConversion_i;       /* '<S24>/Data Type Conversion' */
  uint32_T DataTypeConversion_n;       /* '<S23>/Data Type Conversion' */
  uint32_T DataTypeConversion_a;       /* '<S22>/Data Type Conversion' */
  uint32_T DataTypeConversion_ji;      /* '<S21>/Data Type Conversion' */
  uint32_T DataTypeConversion_k;       /* '<S20>/Data Type Conversion' */
  uint32_T DataTypeConversion_o;       /* '<S19>/Data Type Conversion' */
  uint32_T DataTypeConversion_l;       /* '<S18>/Data Type Conversion' */
  uint32_T DataTypeConversion_b;       /* '<S17>/Data Type Conversion' */
  uint8_T UDPReceive_o1[128];          /* '<Root>/UDP Receive' */
  uint8_T ASCIIEncode2[128];           /* '<Root>/ASCII Encode 2' */
} B_hil_tuning_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  void *UDPConfigure_PWORK[5];         /* '<Root>/UDP Configure' */
  void *UDPReceive_PWORK[2];           /* '<Root>/UDP Receive' */
  void *ASCIIDecode_PWORK[2];          /* '<Root>/ASCII Decode ' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFor_;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_p;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_po;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_c;   /* synthesized block */

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
  } HiddenToAsyncQueue_InsertedF_pv;   /* synthesized block */

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
  } HiddenToAsyncQueue_InsertedFo_g;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_oe;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_gi;   /* synthesized block */

  void *ASCIIEncode2_PWORK;            /* '<Root>/ASCII Encode 2' */
  void *UDPSend_PWORK;                 /* '<Root>/UDP Send' */
  int_T UDPConfigure_IWORK[6];         /* '<Root>/UDP Configure' */
  int_T UDPReceive_IWORK[2];           /* '<Root>/UDP Receive' */
  int_T ASCIIDecode_IWORK[4];          /* '<Root>/ASCII Decode ' */
  int_T UDPSend_IWORK[3];              /* '<Root>/UDP Send' */
} DW_hil_tuning_T;

/* Backward compatible GRT Identifiers */
#define rtB                            hil_tuning_B
#define BlockIO                        B_hil_tuning_T
#define rtP                            hil_tuning_P
#define Parameters                     P_hil_tuning_T
#define rtDWork                        hil_tuning_DW
#define D_Work                         DW_hil_tuning_T

/* Parameters (default storage) */
struct P_hil_tuning_T_ {
  real_T left_abduction[40];           /* Variable: left_abduction
                                        * Referenced by: '<S1>/Look-Up Table1'
                                        */
  real_T left_ankle[40];               /* Variable: left_ankle
                                        * Referenced by: '<S3>/Look-Up Table1'
                                        */
  real_T left_hip[40];                 /* Variable: left_hip
                                        * Referenced by: '<S4>/Look-Up Table1'
                                        */
  real_T left_knee[40];                /* Variable: left_knee
                                        * Referenced by: '<S5>/Look-Up Table1'
                                        */
  real_T left_knee_twist[40];          /* Variable: left_knee_twist
                                        * Referenced by: '<S2>/Look-Up Table1'
                                        */
  real_T left_rotation[40];            /* Variable: left_rotation
                                        * Referenced by: '<S6>/Look-Up Table1'
                                        */
  real_T right_abduction[40];          /* Variable: right_abduction
                                        * Referenced by: '<S7>/Look-Up Table1'
                                        */
  real_T right_ankle[40];              /* Variable: right_ankle
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T right_hip[40];                /* Variable: right_hip
                                        * Referenced by: '<S10>/Look-Up Table1'
                                        */
  real_T right_knee[40];               /* Variable: right_knee
                                        * Referenced by: '<S11>/Look-Up Table1'
                                        */
  real_T right_knee_twist[40];         /* Variable: right_knee_twist
                                        * Referenced by: '<S8>/Look-Up Table1'
                                        */
  real_T right_rotation[40];           /* Variable: right_rotation
                                        * Referenced by: '<S12>/Look-Up Table1'
                                        */
  real_T UDPConfigure_P1_Size[2];      /* Computed Parameter: UDPConfigure_P1_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P1[4];           /* Expression: ipAdd
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P2_Size[2];      /* Computed Parameter: UDPConfigure_P2_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P2[4];           /* Expression: snMask
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P3_Size[2];      /* Computed Parameter: UDPConfigure_P3_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P3[4];           /* Expression: gwAdd
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P4_Size[2];      /* Computed Parameter: UDPConfigure_P4_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P5_Size[2];      /* Computed Parameter: UDPConfigure_P5_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P5;              /* Expression: enableMulticast
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P6_Size[2];      /* Computed Parameter: UDPConfigure_P6_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P7_Size[2];      /* Computed Parameter: UDPConfigure_P7_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P8_Size[2];      /* Computed Parameter: UDPConfigure_P8_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P8;              /* Expression: PciBus
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P9_Size[2];      /* Computed Parameter: UDPConfigure_P9_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P9;              /* Expression: PciSlot
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P10_Size[2];     /* Computed Parameter: UDPConfigure_P10_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P10;             /* Expression: PciFunction
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P11_Size[2];     /* Computed Parameter: UDPConfigure_P11_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P11;             /* Expression: tune
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P12_Size[2];     /* Computed Parameter: UDPConfigure_P12_Size
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPConfigure_P12;             /* Expression: 0
                                        * Referenced by: '<Root>/UDP Configure'
                                        */
  real_T UDPReceive_P1_Size[2];        /* Computed Parameter: UDPReceive_P1_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P1[11];            /* Computed Parameter: UDPReceive_P1
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P2_Size[2];        /* Computed Parameter: UDPReceive_P2_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P2;                /* Expression: localPort
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P3_Size[2];        /* Computed Parameter: UDPReceive_P3_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P3;                /* Expression: outWidth
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P4_Size[2];        /* Computed Parameter: UDPReceive_P4_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P4;                /* Expression: useHostTargetComm
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P5_Size[2];        /* Computed Parameter: UDPReceive_P5_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P5[13];            /* Computed Parameter: UDPReceive_P5
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P6_Size[2];        /* Computed Parameter: UDPReceive_P6_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P6;                /* Expression: maxUDPQueue
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P7_Size[2];        /* Computed Parameter: UDPReceive_P7_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P7;                /* Expression: rcvMulticast
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P8_Size[2];        /* Computed Parameter: UDPReceive_P8_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P9_Size[2];        /* Computed Parameter: UDPReceive_P9_Size
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T UDPReceive_P9;                /* Expression: sampleTime
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  real_T ASCIIDecode_P1_Size[2];       /* Computed Parameter: ASCIIDecode_P1_Size
                                        * Referenced by: '<Root>/ASCII Decode '
                                        */
  real_T ASCIIDecode_P1[35];           /* Computed Parameter: ASCIIDecode_P1
                                        * Referenced by: '<Root>/ASCII Decode '
                                        */
  real_T ASCIIDecode_P2_Size[2];       /* Computed Parameter: ASCIIDecode_P2_Size
                                        * Referenced by: '<Root>/ASCII Decode '
                                        */
  real_T ASCIIDecode_P2;               /* Expression: nvars
                                        * Referenced by: '<Root>/ASCII Decode '
                                        */
  real_T ASCIIDecode_P3_Size[2];       /* Computed Parameter: ASCIIDecode_P3_Size
                                        * Referenced by: '<Root>/ASCII Decode '
                                        */
  real_T ASCIIDecode_P3[12];           /* Expression: varids
                                        * Referenced by: '<Root>/ASCII Decode '
                                        */
  real_T Constant_Value;               /* Expression: period
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[40];    /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S1>/Look-Up Table1'
                                        */
  real_T Constant_Value_k;             /* Expression: period
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_n[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S2>/Look-Up Table1'
                                        */
  real_T Constant_Value_p;             /* Expression: period
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_d[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S3>/Look-Up Table1'
                                        */
  real_T Constant_Value_g;             /* Expression: period
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_l[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S4>/Look-Up Table1'
                                        */
  real_T Constant_Value_h;             /* Expression: period
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_g[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S5>/Look-Up Table1'
                                        */
  real_T Constant_Value_gs;            /* Expression: period
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_gm[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S6>/Look-Up Table1'
                                        */
  real_T Constant_Value_gsv;           /* Expression: period
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_nh[40]; /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S7>/Look-Up Table1'
                                        */
  real_T Constant_Value_a;             /* Expression: period
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_e[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S8>/Look-Up Table1'
                                        */
  real_T Constant_Value_f;             /* Expression: period
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_b[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T Constant_Value_kd;            /* Expression: period
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_k[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S10>/Look-Up Table1'
                                        */
  real_T Constant_Value_m;             /* Expression: period
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_h[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S11>/Look-Up Table1'
                                        */
  real_T Constant_Value_gd;            /* Expression: period
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_p[40];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S12>/Look-Up Table1'
                                        */
  real_T Gain_Gain;                    /* Expression: 11.2
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Constant_Value_b;             /* Expression: 2036
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T rotation_tune_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/rotation_tune'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 11.2
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 2036
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T abduction_tune_Value;         /* Expression: 0
                                        * Referenced by: '<Root>/abduction_tune'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 11.2
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant_Value_pf;            /* Expression: 2036
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 50
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T hip_tune_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/hip_tune'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 11.2
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 2036
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 28
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T knee_tune_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/knee_tune'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 11.2
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 2036
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 100
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T ankle_tune_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/ankle_tune'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 11.2
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Constant_Value_ij;            /* Expression: 2036
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T ankle_twist_tune_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/ankle_twist_tune'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 11.2
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T Constant_Value_d;             /* Expression: 2036
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 11.2
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Constant_Value_gdr;           /* Expression: 2036
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Gain_Gain_kd;                 /* Expression: 11.2
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T Constant_Value_pk;            /* Expression: 2036
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 50
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Gain_Gain_j0;                 /* Expression: 11.2
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant_Value_pr;            /* Expression: 2036
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant1_Value_gr;           /* Expression: 141
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Gain_Gain_jv;                 /* Expression: 11.2
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Constant_Value_mw;            /* Expression: 2036
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: 100
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Gain_Gain_au;                 /* Expression: 11.2
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Constant_Value_iy;            /* Expression: 2036
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T ASCIIEncode2_P1_Size[2];      /* Computed Parameter: ASCIIEncode2_P1_Size
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P1[35];          /* Computed Parameter: ASCIIEncode2_P1
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P2_Size[2];      /* Computed Parameter: ASCIIEncode2_P2_Size
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P2;              /* Expression: maxlength
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P3_Size[2];      /* Computed Parameter: ASCIIEncode2_P3_Size
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P3;              /* Expression: nvars
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P4_Size[2];      /* Computed Parameter: ASCIIEncode2_P4_Size
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T ASCIIEncode2_P4[12];          /* Expression: varids
                                        * Referenced by: '<Root>/ASCII Encode 2'
                                        */
  real_T Constant3_Value;              /* Expression: 59
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T UDPSend_P1_Size[2];           /* Computed Parameter: UDPSend_P1_Size
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P1[11];               /* Computed Parameter: UDPSend_P1
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P2_Size[2];           /* Computed Parameter: UDPSend_P2_Size
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P2;                   /* Expression: localPort
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P3_Size[2];           /* Computed Parameter: UDPSend_P3_Size
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P3[13];               /* Computed Parameter: UDPSend_P3
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P4_Size[2];           /* Computed Parameter: UDPSend_P4_Size
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P4;                   /* Expression: toPort
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P5_Size[2];           /* Computed Parameter: UDPSend_P5_Size
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P5;                   /* Expression: useHostTargetComm
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P6_Size[2];           /* Computed Parameter: UDPSend_P6_Size
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  real_T UDPSend_P6;                   /* Expression: sampleTime
                                        * Referenced by: '<Root>/UDP Send'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_hil_tuning_T {
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
    SimStruct childSFunctions[5];
    SimStruct *childSFunctionPtrs[5];
    struct _ssBlkInfo2 blkInfo2[5];
    struct _ssSFcnModelMethods2 methods2[5];
    struct _ssSFcnModelMethods3 methods3[5];
    struct _ssSFcnModelMethods4 methods4[5];
    struct _ssStatesInfo2 statesInfo2[5];
    ssPeriodicStatesInfo periodicStatesInfo[5];
    struct _ssPortInfo2 inputOutputPortInfo2[5];
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
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      struct _ssPortOutputs outputPortInfo[12];
      struct _ssOutPortUnit outputPortUnits[12];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[12];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn2;

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
    } Sfcn3;

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
    } Sfcn4;
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
extern P_hil_tuning_T hil_tuning_P;

/* Block signals (default storage) */
extern B_hil_tuning_T hil_tuning_B;

/* Block states (default storage) */
extern DW_hil_tuning_T hil_tuning_DW;

/*====================*
 * External functions *
 *====================*/
extern hil_tuning_rtModel *hil_tuning(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  hil_tuning_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_hil_tuning_T *const hil_tuning_M;

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
 * '<Root>' : 'hil_tuning'
 * '<S1>'   : 'hil_tuning/Left Abduction1'
 * '<S2>'   : 'hil_tuning/Left Ankle Twist1'
 * '<S3>'   : 'hil_tuning/Left Ankle1'
 * '<S4>'   : 'hil_tuning/Left Hip1'
 * '<S5>'   : 'hil_tuning/Left Knee1'
 * '<S6>'   : 'hil_tuning/Left Rotation1'
 * '<S7>'   : 'hil_tuning/Right Abduction1'
 * '<S8>'   : 'hil_tuning/Right Ankle Twist1'
 * '<S9>'   : 'hil_tuning/Right Ankle1'
 * '<S10>'  : 'hil_tuning/Right Hip1'
 * '<S11>'  : 'hil_tuning/Right Knee1'
 * '<S12>'  : 'hil_tuning/Right Rotation1'
 * '<S13>'  : 'hil_tuning/Subsystem1'
 * '<S14>'  : 'hil_tuning/Subsystem10'
 * '<S15>'  : 'hil_tuning/Subsystem11'
 * '<S16>'  : 'hil_tuning/Subsystem12'
 * '<S17>'  : 'hil_tuning/Subsystem2'
 * '<S18>'  : 'hil_tuning/Subsystem3'
 * '<S19>'  : 'hil_tuning/Subsystem4'
 * '<S20>'  : 'hil_tuning/Subsystem5'
 * '<S21>'  : 'hil_tuning/Subsystem6'
 * '<S22>'  : 'hil_tuning/Subsystem7'
 * '<S23>'  : 'hil_tuning/Subsystem8'
 * '<S24>'  : 'hil_tuning/Subsystem9'
 */
#endif                                 /* RTW_HEADER_hil_tuning_h_ */
