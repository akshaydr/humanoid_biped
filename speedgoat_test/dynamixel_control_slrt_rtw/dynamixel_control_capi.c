/*
 * dynamixel_control_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "dynamixel_control".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Thu Feb  7 10:44:48 2019
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "dynamixel_control_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "dynamixel_control.h"
#include "dynamixel_control_capi.h"
#include "dynamixel_control_private.h"
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
  { 0, 0, TARGET_STRING("Constant32"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("ASCII Encode "),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 2, 0, TARGET_STRING("Baseboard Serial/Rate Transition"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 3, 0, TARGET_STRING("Baseboard Serial/Rate Transition1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 4, 0, TARGET_STRING("Baseboard Serial/Rate Transition2"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 5, 0, TARGET_STRING("Baseboard Serial/Rate Transition3"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 6, 0, TARGET_STRING("Baseboard Serial/FIFO read 1"),
    TARGET_STRING(""), 0, 3, 2, 0, 0 },

  { 7, 0, TARGET_STRING("Baseboard Serial/FIFO read 2"),
    TARGET_STRING(""), 0, 3, 3, 0, 2 },

  { 8, 0, TARGET_STRING("Baseboard Serial/FIFO write 1/p1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 9, 0, TARGET_STRING("Baseboard Serial/FIFO write 1/p2"),
    TARGET_STRING(""), 1, 4, 0, 0, 0 },

  { 10, 0, TARGET_STRING("Baseboard Serial/FIFO write 2/p1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 11, 0, TARGET_STRING("Baseboard Serial/FIFO write 2/p2"),
    TARGET_STRING(""), 1, 4, 0, 0, 0 },

  { 12, 5, TARGET_STRING("Baseboard Serial/RS232 ISR/Read Int Status FC1"),
    TARGET_STRING(""), 0, 5, 0, 0, 1 },

  { 13, 1, TARGET_STRING("Baseboard Serial/RS232 ISR/Receive 1/FIFO write 1"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 14, 1, TARGET_STRING("Baseboard Serial/RS232 ISR/Receive 1/Read HW FIFO1"),
    TARGET_STRING(""), 0, 5, 4, 0, 1 },

  { 15, 2, TARGET_STRING("Baseboard Serial/RS232 ISR/Receive 2/FIFO write 2"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 16, 2, TARGET_STRING("Baseboard Serial/RS232 ISR/Receive 2/Read HW FIFO2"),
    TARGET_STRING(""), 0, 5, 4, 0, 1 },

  { 17, 3, TARGET_STRING("Baseboard Serial/RS232 ISR/Transmit 1/FIFO read 1/p1"),
    TARGET_STRING(""), 0, 5, 5, 0, 1 },

  { 18, 3, TARGET_STRING("Baseboard Serial/RS232 ISR/Transmit 1/FIFO read 1/p2"),
    TARGET_STRING(""), 1, 5, 0, 0, 1 },

  { 19, 4, TARGET_STRING("Baseboard Serial/RS232 ISR/Transmit 2/FIFO read 2/p1"),
    TARGET_STRING(""), 0, 5, 5, 0, 1 },

  { 20, 4, TARGET_STRING("Baseboard Serial/RS232 ISR/Transmit 2/FIFO read 2/p2"),
    TARGET_STRING(""), 1, 5, 0, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 21, TARGET_STRING("Constant32"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 22, TARGET_STRING("ASCII Encode "),
    TARGET_STRING("P1"), 0, 6, 0 },

  { 23, TARGET_STRING("ASCII Encode "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 24, TARGET_STRING("ASCII Encode "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 25, TARGET_STRING("ASCII Encode "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 26, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 27, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 28, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 29, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 30, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 31, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 32, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 33, TARGET_STRING("Baseboard Serial/Setup1"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 34, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 35, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 36, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 37, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 38, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 39, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 40, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 41, TARGET_STRING("Baseboard Serial/Setup2"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 42, TARGET_STRING("Baseboard Serial/RS232 ISR/Receive 1/Constant"),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 43, TARGET_STRING("Baseboard Serial/RS232 ISR/Receive 2/Constant"),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 44, TARGET_STRING("Baseboard Serial/RS232 ISR/Transmit 1/Constant1"),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 45, TARGET_STRING("Baseboard Serial/RS232 ISR/Transmit 2/Constant2"),
    TARGET_STRING("Value"), 5, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &dynamixel_control_B.Constant32,     /* 0: Signal */
  &dynamixel_control_B.ASCIIEncode[0], /* 1: Signal */
  &dynamixel_control_B.RateTransition, /* 2: Signal */
  &dynamixel_control_B.RateTransition1,/* 3: Signal */
  &dynamixel_control_B.RateTransition2,/* 4: Signal */
  &dynamixel_control_B.RateTransition3,/* 5: Signal */
  &dynamixel_control_B.FIFOread1[0],   /* 6: Signal */
  &dynamixel_control_B.FIFOread2[0],   /* 7: Signal */
  &dynamixel_control_B.FIFOwrite1_o1,  /* 8: Signal */
  &dynamixel_control_B.FIFOwrite1_o2,  /* 9: Signal */
  &dynamixel_control_B.FIFOwrite2_o1,  /* 10: Signal */
  &dynamixel_control_B.FIFOwrite2_o2,  /* 11: Signal */
  &dynamixel_control_B.ReadIntStatusFC1_o2,/* 12: Signal */
  &dynamixel_control_B.FIFOwrite1,     /* 13: Signal */
  &dynamixel_control_B.ReadHWFIFO1[0], /* 14: Signal */
  &dynamixel_control_B.FIFOwrite2,     /* 15: Signal */
  &dynamixel_control_B.ReadHWFIFO2[0], /* 16: Signal */
  &dynamixel_control_B.FIFOread1_o1[0],/* 17: Signal */
  &dynamixel_control_B.FIFOread1_o2,   /* 18: Signal */
  &dynamixel_control_B.FIFOread2_o1[0],/* 19: Signal */
  &dynamixel_control_B.FIFOread2_o2,   /* 20: Signal */
  &dynamixel_control_P.Constant32_Value,/* 21: Block Parameter */
  &dynamixel_control_P.ASCIIEncode_P1[0],/* 22: Block Parameter */
  &dynamixel_control_P.ASCIIEncode_P2, /* 23: Block Parameter */
  &dynamixel_control_P.ASCIIEncode_P3, /* 24: Block Parameter */
  &dynamixel_control_P.ASCIIEncode_P4, /* 25: Block Parameter */
  &dynamixel_control_P.Setup1_P1,      /* 26: Block Parameter */
  &dynamixel_control_P.Setup1_P2,      /* 27: Block Parameter */
  &dynamixel_control_P.Setup1_P3,      /* 28: Block Parameter */
  &dynamixel_control_P.Setup1_P4,      /* 29: Block Parameter */
  &dynamixel_control_P.Setup1_P5,      /* 30: Block Parameter */
  &dynamixel_control_P.Setup1_P6,      /* 31: Block Parameter */
  &dynamixel_control_P.Setup1_P7,      /* 32: Block Parameter */
  &dynamixel_control_P.Setup1_P8,      /* 33: Block Parameter */
  &dynamixel_control_P.Setup2_P1,      /* 34: Block Parameter */
  &dynamixel_control_P.Setup2_P2,      /* 35: Block Parameter */
  &dynamixel_control_P.Setup2_P3,      /* 36: Block Parameter */
  &dynamixel_control_P.Setup2_P4,      /* 37: Block Parameter */
  &dynamixel_control_P.Setup2_P5,      /* 38: Block Parameter */
  &dynamixel_control_P.Setup2_P6,      /* 39: Block Parameter */
  &dynamixel_control_P.Setup2_P7,      /* 40: Block Parameter */
  &dynamixel_control_P.Setup2_P8,      /* 41: Block Parameter */
  &dynamixel_control_P.Constant_Value, /* 42: Block Parameter */
  &dynamixel_control_P.Constant_Value_e,/* 43: Block Parameter */
  &dynamixel_control_P.Constant1_Value,/* 44: Block Parameter */
  &dynamixel_control_P.Constant2_Value,/* 45: Block Parameter */
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

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "numeric", "serialfifoptr", 0, 0, sizeof(serialfifoptr), SS_STRUCT, 0, 0 },

  { "unsigned short", "uint16_T", 0, 0, sizeof(uint16_T), SS_UINT16, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
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

  { rtwCAPI_VECTOR, 12, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  128,                                 /* 2 */
  1,                                   /* 3 */
  2049,                                /* 4 */
  1,                                   /* 5 */
  1025,                                /* 6 */
  1,                                   /* 7 */
  65,                                  /* 8 */
  1,                                   /* 9 */
  61,                                  /* 10 */
  1,                                   /* 11 */
  1,                                   /* 12 */
  15                                   /* 13 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, -1.0, -2.0, 0.01
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
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[3],
    2, 0 },

  { (const void *) &rtcapiStoredFloats[4], (const void *) &rtcapiStoredFloats[1],
    1, 0 }
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
  { rtBlockSignals, 21,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 25,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2645101477U,
    1656564060U,
    1750581578U,
    1164347166U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  dynamixel_control_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void dynamixel_control_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(dynamixel_control_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(dynamixel_control_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(dynamixel_control_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(dynamixel_control_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(dynamixel_control_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  dynamixel_control_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(dynamixel_control_M);
  dynamixel_control_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_dynamixel_control_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(dynamixel_control_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(dynamixel_control_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(dynamixel_control_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void dynamixel_control_host_InitializeDataMapInfo
    (dynamixel_control_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: dynamixel_control_capi.c */
