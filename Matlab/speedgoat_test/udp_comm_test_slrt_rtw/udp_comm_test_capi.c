/*
 * udp_comm_test_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "udp_comm_test_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "udp_comm_test.h"
#include "udp_comm_test_capi.h"
#include "udp_comm_test_private.h"
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
  { 0, 0, TARGET_STRING("Constant3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("ASCII Decode /p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 2, 0, TARGET_STRING("ASCII Decode /p2"),
    TARGET_STRING(""), 1, 1, 0, 0, 0 },

  { 3, 0, TARGET_STRING("ASCII Decode /p3"),
    TARGET_STRING(""), 2, 1, 0, 0, 0 },

  { 4, 0, TARGET_STRING("ASCII Decode /p4"),
    TARGET_STRING(""), 3, 1, 0, 0, 0 },

  { 5, 0, TARGET_STRING("ASCII Decode /p5"),
    TARGET_STRING(""), 4, 1, 0, 0, 0 },

  { 6, 0, TARGET_STRING("ASCII Decode /p6"),
    TARGET_STRING(""), 5, 1, 0, 0, 0 },

  { 7, 0, TARGET_STRING("ASCII Decode /p7"),
    TARGET_STRING(""), 6, 1, 0, 0, 0 },

  { 8, 0, TARGET_STRING("ASCII Decode /p8"),
    TARGET_STRING(""), 7, 1, 0, 0, 0 },

  { 9, 0, TARGET_STRING("ASCII Decode /p9"),
    TARGET_STRING(""), 8, 1, 0, 0, 0 },

  { 10, 0, TARGET_STRING("ASCII Decode /p10"),
    TARGET_STRING(""), 9, 1, 0, 0, 0 },

  { 11, 0, TARGET_STRING("ASCII Decode /p11"),
    TARGET_STRING(""), 10, 1, 0, 0, 0 },

  { 12, 0, TARGET_STRING("ASCII Decode /p12"),
    TARGET_STRING(""), 11, 1, 0, 0, 0 },

  { 13, 0, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 14, 0, TARGET_STRING("UDP Receive/p1"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 15, 0, TARGET_STRING("UDP Receive/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 17, 0, TARGET_STRING("2"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 18, 0, TARGET_STRING("3"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 19, 0, TARGET_STRING("4"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 20, 0, TARGET_STRING("5"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 21, 0, TARGET_STRING("6"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 22, 0, TARGET_STRING("Add1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 23, 0, TARGET_STRING("Add2"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 24, 0, TARGET_STRING("Add3"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 25, 0, TARGET_STRING("Add4"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 26, 0, TARGET_STRING("Add5"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 27, 0, TARGET_STRING("Add6"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 28, TARGET_STRING("Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 29, TARGET_STRING("abduction_tune"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 30, TARGET_STRING("ankle_tune"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 31, TARGET_STRING("ankle_twist_tune"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 32, TARGET_STRING("hip_tune"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 33, TARGET_STRING("knee_tune"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 34, TARGET_STRING("left_abduction2 "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 35, TARGET_STRING("left_ankle2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 36, TARGET_STRING("left_ankle_twist2 "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 37, TARGET_STRING("left_hip2 "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 38, TARGET_STRING("left_knee2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 39, TARGET_STRING("left_rotation2 "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 40, TARGET_STRING("right_abduction2 "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 41, TARGET_STRING("right_annkle2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 42, TARGET_STRING("right_annkle_twist2 "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 43, TARGET_STRING("right_hip2 "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 44, TARGET_STRING("right_knee2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 45, TARGET_STRING("right_rotation2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 46, TARGET_STRING("rotation_tune"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 47, TARGET_STRING("ASCII Decode "),
    TARGET_STRING("P1"), 0, 2, 0 },

  { 48, TARGET_STRING("ASCII Decode "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 49, TARGET_STRING("ASCII Decode "),
    TARGET_STRING("P3"), 0, 3, 0 },

  { 50, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P1"), 0, 2, 0 },

  { 51, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 52, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 53, TARGET_STRING("ASCII Encode 2"),
    TARGET_STRING("P4"), 0, 3, 0 },

  { 54, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P1"), 0, 4, 0 },

  { 55, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P2"), 0, 4, 0 },

  { 56, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P3"), 0, 4, 0 },

  { 57, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 58, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 59, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 60, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 61, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 62, TARGET_STRING("UDP Configure"),
    TARGET_STRING("P12"), 0, 0, 0 },

  { 63, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P1"), 0, 5, 0 },

  { 64, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 65, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 66, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 67, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P5"), 0, 6, 0 },

  { 68, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 69, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 70, TARGET_STRING("UDP Receive"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 71, TARGET_STRING("UDP Send"),
    TARGET_STRING("P1"), 0, 5, 0 },

  { 72, TARGET_STRING("UDP Send"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 73, TARGET_STRING("UDP Send"),
    TARGET_STRING("P3"), 0, 6, 0 },

  { 74, TARGET_STRING("UDP Send"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 75, TARGET_STRING("UDP Send"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 76, TARGET_STRING("UDP Send"),
    TARGET_STRING("P6"), 0, 0, 0 },

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
  &udp_comm_test_B.Constant3,          /* 0: Signal */
  &udp_comm_test_B.ASCIIDecode_o1,     /* 1: Signal */
  &udp_comm_test_B.ASCIIDecode_o2,     /* 2: Signal */
  &udp_comm_test_B.ASCIIDecode_o3,     /* 3: Signal */
  &udp_comm_test_B.ASCIIDecode_o4,     /* 4: Signal */
  &udp_comm_test_B.ASCIIDecode_o5,     /* 5: Signal */
  &udp_comm_test_B.ASCIIDecode_o6,     /* 6: Signal */
  &udp_comm_test_B.ASCIIDecode_o7,     /* 7: Signal */
  &udp_comm_test_B.ASCIIDecode_o8,     /* 8: Signal */
  &udp_comm_test_B.ASCIIDecode_o9,     /* 9: Signal */
  &udp_comm_test_B.ASCIIDecode_o10,    /* 10: Signal */
  &udp_comm_test_B.ASCIIDecode_o11,    /* 11: Signal */
  &udp_comm_test_B.ASCIIDecode_o12,    /* 12: Signal */
  &udp_comm_test_B.ASCIIEncode2[0],    /* 13: Signal */
  &udp_comm_test_B.UDPReceive_o1[0],   /* 14: Signal */
  &udp_comm_test_B.UDPReceive_o2,      /* 15: Signal */
  &udp_comm_test_B.u,                  /* 16: Signal */
  &udp_comm_test_B.u_j,                /* 17: Signal */
  &udp_comm_test_B.u_k,                /* 18: Signal */
  &udp_comm_test_B.u_d,                /* 19: Signal */
  &udp_comm_test_B.u_h,                /* 20: Signal */
  &udp_comm_test_B.u_o,                /* 21: Signal */
  &udp_comm_test_B.Add1,               /* 22: Signal */
  &udp_comm_test_B.Add2,               /* 23: Signal */
  &udp_comm_test_B.Add3,               /* 24: Signal */
  &udp_comm_test_B.Add4,               /* 25: Signal */
  &udp_comm_test_B.Add5,               /* 26: Signal */
  &udp_comm_test_B.Add6,               /* 27: Signal */
  &udp_comm_test_P.Constant3_Value,    /* 28: Block Parameter */
  &udp_comm_test_P.abduction_tune_Value,/* 29: Block Parameter */
  &udp_comm_test_P.ankle_tune_Value,   /* 30: Block Parameter */
  &udp_comm_test_P.ankle_twist_tune_Value,/* 31: Block Parameter */
  &udp_comm_test_P.hip_tune_Value,     /* 32: Block Parameter */
  &udp_comm_test_P.knee_tune_Value,    /* 33: Block Parameter */
  &udp_comm_test_P.left_abduction2_Value,/* 34: Block Parameter */
  &udp_comm_test_P.left_ankle2_Value,  /* 35: Block Parameter */
  &udp_comm_test_P.left_ankle_twist2_Value,/* 36: Block Parameter */
  &udp_comm_test_P.left_hip2_Value,    /* 37: Block Parameter */
  &udp_comm_test_P.left_knee2_Value,   /* 38: Block Parameter */
  &udp_comm_test_P.left_rotation2_Value,/* 39: Block Parameter */
  &udp_comm_test_P.right_abduction2_Value,/* 40: Block Parameter */
  &udp_comm_test_P.right_annkle2_Value,/* 41: Block Parameter */
  &udp_comm_test_P.right_annkle_twist2_Value,/* 42: Block Parameter */
  &udp_comm_test_P.right_hip2_Value,   /* 43: Block Parameter */
  &udp_comm_test_P.right_knee2_Value,  /* 44: Block Parameter */
  &udp_comm_test_P.right_rotation2_Value,/* 45: Block Parameter */
  &udp_comm_test_P.rotation_tune_Value,/* 46: Block Parameter */
  &udp_comm_test_P.ASCIIDecode_P1[0],  /* 47: Block Parameter */
  &udp_comm_test_P.ASCIIDecode_P2,     /* 48: Block Parameter */
  &udp_comm_test_P.ASCIIDecode_P3[0],  /* 49: Block Parameter */
  &udp_comm_test_P.ASCIIEncode2_P1[0], /* 50: Block Parameter */
  &udp_comm_test_P.ASCIIEncode2_P2,    /* 51: Block Parameter */
  &udp_comm_test_P.ASCIIEncode2_P3,    /* 52: Block Parameter */
  &udp_comm_test_P.ASCIIEncode2_P4[0], /* 53: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P1[0], /* 54: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P2[0], /* 55: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P3[0], /* 56: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P5,    /* 57: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P8,    /* 58: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P9,    /* 59: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P10,   /* 60: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P11,   /* 61: Block Parameter */
  &udp_comm_test_P.UDPConfigure_P12,   /* 62: Block Parameter */
  &udp_comm_test_P.UDPReceive_P1[0],   /* 63: Block Parameter */
  &udp_comm_test_P.UDPReceive_P2,      /* 64: Block Parameter */
  &udp_comm_test_P.UDPReceive_P3,      /* 65: Block Parameter */
  &udp_comm_test_P.UDPReceive_P4,      /* 66: Block Parameter */
  &udp_comm_test_P.UDPReceive_P5[0],   /* 67: Block Parameter */
  &udp_comm_test_P.UDPReceive_P6,      /* 68: Block Parameter */
  &udp_comm_test_P.UDPReceive_P7,      /* 69: Block Parameter */
  &udp_comm_test_P.UDPReceive_P9,      /* 70: Block Parameter */
  &udp_comm_test_P.UDPSend_P1[0],      /* 71: Block Parameter */
  &udp_comm_test_P.UDPSend_P2,         /* 72: Block Parameter */
  &udp_comm_test_P.UDPSend_P3[0],      /* 73: Block Parameter */
  &udp_comm_test_P.UDPSend_P4,         /* 74: Block Parameter */
  &udp_comm_test_P.UDPSend_P5,         /* 75: Block Parameter */
  &udp_comm_test_P.UDPSend_P6,         /* 76: Block Parameter */
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

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0 }
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
  1,                                   /* 4 */
  35,                                  /* 5 */
  1,                                   /* 6 */
  12,                                  /* 7 */
  1,                                   /* 8 */
  4,                                   /* 9 */
  1,                                   /* 10 */
  11,                                  /* 11 */
  1,                                   /* 12 */
  13                                   /* 13 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
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
    0, 0 }
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
  { rtBlockSignals, 28,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 49,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1816938990U,
    577526203U,
    1396031396U,
    2659695068U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  udp_comm_test_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void udp_comm_test_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(udp_comm_test_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(udp_comm_test_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(udp_comm_test_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(udp_comm_test_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(udp_comm_test_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  udp_comm_test_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (udp_comm_test_M);
  udp_comm_test_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_udp_comm_test_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(udp_comm_test_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(udp_comm_test_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(udp_comm_test_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void udp_comm_test_host_InitializeDataMapInfo(udp_comm_test_host_DataMapInfo_T
    *dataMap, const char *path)
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

/* EOF: udp_comm_test_capi.c */
