/*
 * dynamixel_control.c
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

#include "rt_logging_mmi.h"
#include "dynamixel_control_capi.h"
#include "dynamixel_control.h"
#include "dynamixel_control_private.h"

const uint8_T dynamixel_control_U8GND = 0U;/* uint8_T ground */

/* Block signals (default storage) */
B_dynamixel_control_T dynamixel_control_B;

/* Block states (default storage) */
DW_dynamixel_control_T dynamixel_control_DW;

/* Real-time model */
RT_MODEL_dynamixel_control_T dynamixel_control_M_;
RT_MODEL_dynamixel_control_T *const dynamixel_control_M = &dynamixel_control_M_;

/* xPC Target Async Interrupt Block '<S1>/IRQ Source' */
void xPCISR1(void)
{
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(dynamixel_control_DW.Receive1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(dynamixel_control_DW.Transmit1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(dynamixel_control_DW.Receive2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(dynamixel_control_DW.Transmit2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(dynamixel_control_DW.RS232ISR_SubsysRanBC);

    /* RateTransition: '<S1>/Rate Transition' */
    dynamixel_control_B.RateTransition = dynamixel_control_B.FIFOwrite1_o1;

    /* RateTransition: '<S1>/Rate Transition2' */
    dynamixel_control_B.RateTransition2 = dynamixel_control_B.FIFOwrite2_o1;

    /* S-Function (xpcinterrupt): '<S1>/IRQ Source' */
    dynamixel_control_RS232ISR();

    /* End of Outputs for S-Function (xpcinterrupt): '<S1>/IRQ Source' */
  }

  xpceDAQUpdateTimeStamp(2, (((dynamixel_control_M->Timing.clockTick2+
    dynamixel_control_M->Timing.clockTickH2* 4294967296.0)) * 0.001));
  xpceDAQPostEvent(2);
}

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(dynamixel_control_M, 1);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called in the model base rate function.
 * It maintains SampleHit information to allow scheduling
 * of the subrates from the base rate function.
 */
void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (dynamixel_control_M->Timing.TaskCounters.TID[1])++;
  if ((dynamixel_control_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    dynamixel_control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Start for function-call system: '<S1>/RS232 ISR' */
void dynamixel_co_RS232ISR_Start(void)
{
  /* Start for S-Function (iquerybase): '<S7>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S7>/Receive 1'
   */
  /* Start for function-call system: '<S7>/Receive 1' */

  /* Start for S-Function (serreadbase): '<S8>/Read HW FIFO1' incorporates:
   *  Constant: '<S8>/Constant'
   */

  /* S-Function Block: <S8>/Read HW FIFO1 (serreadbase) */
  {
    int count = 0;

    // Flush the hardware fifo on startup.
    while (xpcInpB( (unsigned short)(1016 + LSR) ) & LSRDR ) {
      // Read and discard the data.
      xpcInpB( (unsigned short)(1016 + DATA) );
      if (count++ > 1000 ) {
        static char msg[50];
        sprintf( msg, "A UART at address 0x%x is not responding", 1016 );

        // No baseboard UART has that large a hardware fifo!
        rtmSetErrorStatus(dynamixel_control_M, msg);
        return;
      }
    }
  }

  /* Start for S-Function (fifowrite): '<S8>/FIFO write 1' */
  dynamixel_control_DW.FIFOwrite1_IWORK_c[0] = 1024;/* fifo size */
  dynamixel_control_DW.FIFOwrite1_IWORK_c[1] = 2;/* fifo type */
  dynamixel_control_DW.FIFOwrite1_IWORK_c[2] = 65;/* inport width */

  /* allocate memory for FIFO */
  dynamixel_control_DW.FIFOwrite1_PWORK_h[0] = malloc(4 * (1024 + 3));
  if (dynamixel_control_DW.FIFOwrite1_PWORK_h[0] == NULL) {
    rtmSetErrorStatus(dynamixel_control_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  dynamixel_control_DW.FIFOwrite1_PWORK_h[1] = &dynamixel_control_B.ReadHWFIFO1
    [0];

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOwrite1_PWORK_h[2] = &dynamixel_control_B.FIFOwrite1;
  dynamixel_control_DW.FIFOwrite1_PWORK_h[3] = NULL;

  {
    /* Initialize the fifo */
    int *fifo = dynamixel_control_DW.FIFOwrite1_PWORK_h[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &dynamixel_control_B.FIFOwrite1;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (iquerybase): '<S7>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S7>/Transmit 1'
   */
  /* Start for function-call system: '<S7>/Transmit 1' */

  /* Start for S-Function (fiforead): '<S10>/FIFO read 1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  dynamixel_control_DW.FIFOread1_IWORK_m[0] = 60;/* Max to read */
  dynamixel_control_DW.FIFOread1_IWORK_m[1] = 1;/* Min to read */
  dynamixel_control_DW.FIFOread1_IWORK_m[2] = 0;/* Use delimiter? */
  dynamixel_control_DW.FIFOread1_IWORK_m[3] = 13;/* delimiter */
  dynamixel_control_DW.FIFOread1_IWORK_m[4] = 2;/* FIFO type */

  /* Input pointer(s) */
  dynamixel_control_DW.FIFOread1_PWORK_c[0] =
    &dynamixel_control_B.RateTransition;
  dynamixel_control_DW.FIFOread1_PWORK_c[1] =
    &dynamixel_control_B.ReadIntStatusFC1_o2;
  dynamixel_control_DW.FIFOread1_PWORK_c[2] =
    &dynamixel_control_P.Constant1_Value;

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOread1_PWORK_c[3] = &dynamixel_control_B.FIFOread1_o1
    [0];
  dynamixel_control_DW.FIFOread1_PWORK_c[4] = &dynamixel_control_B.FIFOread1_o2;

  /* Start for S-Function (iquerybase): '<S7>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S7>/Receive 2'
   */
  /* Start for function-call system: '<S7>/Receive 2' */

  /* Start for S-Function (fifowrite): '<S9>/FIFO write 2' */
  dynamixel_control_DW.FIFOwrite2_IWORK_g[0] = 1024;/* fifo size */
  dynamixel_control_DW.FIFOwrite2_IWORK_g[1] = 2;/* fifo type */
  dynamixel_control_DW.FIFOwrite2_IWORK_g[2] = 65;/* inport width */

  /* allocate memory for FIFO */
  dynamixel_control_DW.FIFOwrite2_PWORK_a[0] = malloc(4 * (1024 + 3));
  if (dynamixel_control_DW.FIFOwrite2_PWORK_a[0] == NULL) {
    rtmSetErrorStatus(dynamixel_control_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  dynamixel_control_DW.FIFOwrite2_PWORK_a[1] = &dynamixel_control_B.ReadHWFIFO2
    [0];

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOwrite2_PWORK_a[2] = &dynamixel_control_B.FIFOwrite2;
  dynamixel_control_DW.FIFOwrite2_PWORK_a[3] = NULL;

  {
    /* Initialize the fifo */
    int *fifo = dynamixel_control_DW.FIFOwrite2_PWORK_a[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &dynamixel_control_B.FIFOwrite2;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (iquerybase): '<S7>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S7>/Transmit 2'
   */

  /* Start for function-call system: '<S7>/Transmit 2' */

  /* Start for S-Function (fiforead): '<S11>/FIFO read 2' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  dynamixel_control_DW.FIFOread2_IWORK_p[0] = 60;/* Max to read */
  dynamixel_control_DW.FIFOread2_IWORK_p[1] = 1;/* Min to read */
  dynamixel_control_DW.FIFOread2_IWORK_p[2] = 0;/* Use delimiter? */
  dynamixel_control_DW.FIFOread2_IWORK_p[3] = 13;/* delimiter */
  dynamixel_control_DW.FIFOread2_IWORK_p[4] = 2;/* FIFO type */

  /* Input pointer(s) */
  dynamixel_control_DW.FIFOread2_PWORK_p[0] =
    &dynamixel_control_B.RateTransition2;
  dynamixel_control_DW.FIFOread2_PWORK_p[1] =
    &dynamixel_control_B.ReadIntStatusFC1_o2;
  dynamixel_control_DW.FIFOread2_PWORK_p[2] =
    &dynamixel_control_P.Constant2_Value;

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOread2_PWORK_p[3] = &dynamixel_control_B.FIFOread2_o1
    [0];
  dynamixel_control_DW.FIFOread2_PWORK_p[4] = &dynamixel_control_B.FIFOread2_o2;

  /* End of Start for S-Function (iquerybase): '<S7>/Read Int Status FC1' */
}

/* Output and update for function-call system: '<S1>/RS232 ISR' */
void dynamixel_control_RS232ISR(void)
{
  rtw_xpc_mutex_take(dynamixel_control_M->Timing.semIdForTask2);
  dynamixel_control_M->Timing.clockTick2 =
    dynamixel_control_M->Timing.rtmClockTickBuf2;
  dynamixel_control_M->Timing.clockTickH2 =
    dynamixel_control_M->Timing.rtmBufClockTickBufH2;
  rtw_xpc_mutex_give(dynamixel_control_M->Timing.semIdForTask2);

  /* S-Function (iquerybase): '<S7>/Read Int Status FC1' */
  {
    /* S-Function Block: <S7>/Read Int Status FC1 (iquerybase) */
    int base[2] = { (int)1016, (int)0 };

    uint32_T port, max;
    volatile int iir;                  // local interrupt register, per uart
    for (port = 0 ; port < 2 ; port++ ) {
      if (base[port] == 0 ) {
        continue;
      }

      iir = xpcInpB( (unsigned short)(base[port] + IIR) ) & 0xff;

      //printf("lint = 0x%x\n", iir );
      if ((iir & (IIRFEBL | IIR64) ) == (IIRFEBL | IIR64) )
        max = 60;
      else if ((iir & (IIRFEBL | IIR64) ) == IIRFEBL )
        max = 15;
      else
        max = 1;
      *(&dynamixel_control_B.ReadIntStatusFC1_o2) = max;
      iir &= IIRREASON;
      while (iir != 1 )                // Service all reasons
      {
        switch ( iir )
        {
         case 1:                       // No interrupt on this UART
          break;

         case 4:                       // received data available
         case 6:                       // receiver line status, overrun etc.
         case 0xc:                     // character timeout
          //printf("%1xa", base[i]>>8);
          // All three are receive interrupts
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S7>/Receive 1' */

            /* S-Function (serreadbase): '<S8>/Read HW FIFO1' incorporates:
             *  Constant: '<S8>/Constant'
             */
            {
              /* S-Function Block: <S8>/Read HW FIFO1 (serreadbase) */
              int status = 0;
              int count = 0;

              // While there is data in the fifo, read it, also read error status.
              // Cap the read length to the interrupt point in 64 byte fifo mode.
              while (((status = xpcInpB( (unsigned short)(1016 + LSR) ) & 0xff )
                      & LSRDR) && (count < 56) ) {
                int c;
                int masked;
                count++;
                c = xpcInpB( (unsigned short)(1016 + DATA) ) & 0xff;// read character
                masked = status & (LSROE | LSRPE | LSRFE | LSRBI);
                ((int_T *)&dynamixel_control_B.ReadHWFIFO1[0])[count] = (masked <<
                  8) | c;
              }

              ((int_T *)&dynamixel_control_B.ReadHWFIFO1[0])[0] = count;
            }

            /* S-Function (fifowrite): '<S8>/FIFO write 1' */
            {
              const char *err;
              static char msg[100];
              err = fifowrite(dynamixel_control_DW.FIFOwrite1_PWORK_h[0],
                              dynamixel_control_DW.FIFOwrite1_PWORK_h[1],
                              &dynamixel_control_DW.FIFOwrite1_PWORK_h[2],
                              &dynamixel_control_DW.FIFOwrite1_IWORK_c[0]);
              if (err) {
                if (strncmp("FIFO", err, 4)) {
                  rtmSetErrorStatus(dynamixel_control_M, err);
                } else {
                  int n = strlen(err);
                  strcpy(msg, err);
                  strncpy(msg + n, "RCV channel 1, IRQ 4", 99 - n);
                  rtmSetErrorStatus(dynamixel_control_M, msg);
                }
              }
            }

            dynamixel_control_DW.Receive1_SubsysRanBC = 4;
            break;
          }
          break;

         case 2:                       // Transmitter holding register empty
          //printf("%1xb", base[i]>>8);
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S7>/Transmit 1' */

            /* S-Function (fiforead): '<S10>/FIFO read 1' incorporates:
             *  Constant: '<S10>/Constant1'
             */
            {
              void **iPtrs = &dynamixel_control_DW.FIFOread1_PWORK_c[0];
              void **oPtrs = &dynamixel_control_DW.FIFOread1_PWORK_c[3];
              fiforead(iPtrs, oPtrs, &dynamixel_control_DW.FIFOread1_IWORK_m[0]);
            }

            /* S-Function (serwritebase): '<S10>/Write HW FIFO1' */
            {
              /* S-Function Block: <S10>/Write HW FIFO1 (serwritebase) */
              int_T *IPtr = (int_T *)&dynamixel_control_B.FIFOread1_o1[0];
              if (dynamixel_control_B.FIFOread1_o2 > 0 ) {
                // On entry, verify that the transmitter holding register is empty
                // so we can stuff all that came from the software fifo into the
                // hardware fifo.  Assume that the software fifo has a max read
                // parameter that fits with the hardware fifo mode setting.
                if (IPtr[0] == 0 ) {
                  // No data, turn off the transmitter empty interrupt and leave
                  TBTakeSpinFast( slrtSerialLock );
                  int ier = xpcInpB( (unsigned short)(1016 + IER) ) & 0xff;
                  xpcOutpB( (unsigned short)(1016 + IER), (uint8_T)(ier &
                            ~IERXMT) );
                  TBGiveSpinFast( slrtSerialLock );
                } else if (xpcInpB( (unsigned short)(1016 + LSR) ) & LSRTHRE ) {
                  int i;

                  // Copy all the data from the input vector to the HW fifo.
                  // The fifo read block MUST have the correct max read value
                  // for the fifo mode.
                  for (i = 0 ; i < IPtr[0] ; i++ ) {
                    xpcOutpB( (ushort_T)(1016 + DATA), (uint8_T)(IPtr[i+1] &
                              0xff) );
                  }
                } else {
                  rtmSetErrorStatus(dynamixel_control_M,
                                    "Attempted write to hardware fifo that isn't empty");
                  return;
                }
              }
            }

            dynamixel_control_DW.Transmit1_SubsysRanBC = 4;
            break;
          }
          break;

         case 0:
          // Modem status change
          break;
        }

        // Read IIR again to see if we're done with this UART
        iir = xpcInpB( (unsigned short)(base[port] + IIR) ) & IIRREASON;
      }
    }
  }

  /* End of Outputs for S-Function (iquerybase): '<S7>/Read Int Status FC1' */
  dynamixel_control_DW.RS232ISR_SubsysRanBC = 4;
}

/* Termination for function-call system: '<S1>/RS232 ISR' */
void dynamixel_con_RS232ISR_Term(void)
{
  /* Terminate for S-Function (iquerybase): '<S7>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S7>/Receive 1'
   */
  /* Termination for function-call system: '<S7>/Receive 1' */

  /* Terminate for S-Function (fifowrite): '<S8>/FIFO write 1' */

  /* Free fifo memory */
  if (dynamixel_control_DW.FIFOwrite1_PWORK_h[0]) {
    free(dynamixel_control_DW.FIFOwrite1_PWORK_h[0]);
  }

  /* Terminate for S-Function (iquerybase): '<S7>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S7>/Receive 2'
   */

  /* Termination for function-call system: '<S7>/Receive 2' */

  /* Terminate for S-Function (fifowrite): '<S9>/FIFO write 2' */

  /* Free fifo memory */
  if (dynamixel_control_DW.FIFOwrite2_PWORK_a[0]) {
    free(dynamixel_control_DW.FIFOwrite2_PWORK_a[0]);
  }

  /* End of Terminate for S-Function (iquerybase): '<S7>/Read Int Status FC1' */
}

/* Model output function for TID0 */
static void dynamixel_control_output0(void) /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_scheduler();
  }

  /* Constant: '<Root>/Constant32' */
  dynamixel_control_B.Constant32 = dynamixel_control_P.Constant32_Value;

  /* S-Function (asciiencode): '<Root>/ASCII Encode ' */

  /* Level2 S-Function Block: '<Root>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (fifowrite): '<S1>/FIFO write 1' */
  {
    const char *err;
    static char msg[100];
    err = fifowrite(dynamixel_control_DW.FIFOwrite1_PWORK[0],
                    dynamixel_control_DW.FIFOwrite1_PWORK[1],
                    &dynamixel_control_DW.FIFOwrite1_PWORK[2],
                    &dynamixel_control_DW.FIFOwrite1_IWORK[0]);
    if (err) {
      if (strncmp("FIFO", err, 4)) {
        rtmSetErrorStatus(dynamixel_control_M, err);
      } else {
        int n = strlen(err);
        strcpy(msg, err);
        strncpy(msg + n, "XMT channel 1, IRQ 4", 99 - n);
        rtmSetErrorStatus(dynamixel_control_M, msg);
      }
    }
  }

  /* S-Function (sertxenablebase): '<S1>/Enable TX 1' */

  /* S-Function Block: <S1>/Enable TX 1 (sertxenablebase) */
  if (dynamixel_control_B.FIFOwrite1_o2 == 1 ) {
    TBTakeSpinFast( slrtSerialLock );
    uint8_T reg = (uint8_T)xpcInpB( (unsigned short)(1016 + IER) ) & 0xff;
    xpcOutpB( (unsigned short)(1016 + IER), (uint8_T)(reg & ~IERXMT) );
    reg |= IERXMT;
    xpcOutpB( (unsigned short)(1016 + IER), reg );
    TBGiveSpinFast( slrtSerialLock );
  }

  /* S-Function (fifowrite): '<S1>/FIFO write 2' */
  {
    const char *err;
    static char msg[100];
    err = fifowrite(dynamixel_control_DW.FIFOwrite2_PWORK[0],
                    dynamixel_control_DW.FIFOwrite2_PWORK[1],
                    &dynamixel_control_DW.FIFOwrite2_PWORK[2],
                    &dynamixel_control_DW.FIFOwrite2_IWORK[0]);
    if (err) {
      if (strncmp("FIFO", err, 4)) {
        rtmSetErrorStatus(dynamixel_control_M, err);
      } else {
        int n = strlen(err);
        strcpy(msg, err);
        strncpy(msg + n, "XMT channel 2, IRQ 4", 99 - n);
        rtmSetErrorStatus(dynamixel_control_M, msg);
      }
    }
  }

  /* RateTransition: '<S1>/Rate Transition1' */
  dynamixel_control_B.RateTransition1 = dynamixel_control_B.FIFOwrite1;

  /* S-Function (fiforead): '<S1>/FIFO read 1' */
  {
    void **iPtrs = &dynamixel_control_DW.FIFOread1_PWORK[0];
    void **oPtrs = &dynamixel_control_DW.FIFOread1_PWORK[3];
    fiforead(iPtrs, oPtrs, &dynamixel_control_DW.FIFOread1_IWORK[0]);
  }

  /* S-Function (sersetupbase): '<S1>/Setup1' */

  /* Level2 S-Function Block: '<S1>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sersetupbase): '<S1>/Setup2' */

  /* Level2 S-Function Block: '<S1>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }
}

/* Model update function for TID0 */
static void dynamixel_control_update0(void) /* Sample time: [0.001s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++dynamixel_control_M->Timing.clockTick0)) {
    ++dynamixel_control_M->Timing.clockTickH0;
  }

  dynamixel_control_M->Timing.t[0] = dynamixel_control_M->Timing.clockTick0 *
    dynamixel_control_M->Timing.stepSize0 +
    dynamixel_control_M->Timing.clockTickH0 *
    dynamixel_control_M->Timing.stepSize0 * 4294967296.0;
  rtw_xpc_mutex_take(dynamixel_control_M->Timing.semIdForTask2);
  dynamixel_control_M->Timing.rtmClockTickBuf2 =
    dynamixel_control_M->Timing.clockTick0;
  dynamixel_control_M->Timing.rtmBufClockTickBufH2 =
    dynamixel_control_M->Timing.clockTickH0;
  rtw_xpc_mutex_give(dynamixel_control_M->Timing.semIdForTask2);
}

/* Model output function for TID1 */
static void dynamixel_control_output1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* RateTransition: '<S1>/Rate Transition3' */
  dynamixel_control_B.RateTransition3 = dynamixel_control_B.FIFOwrite2;

  /* S-Function (fiforead): '<S1>/FIFO read 2' */
  {
    void **iPtrs = &dynamixel_control_DW.FIFOread2_PWORK[0];
    void **oPtrs = &dynamixel_control_DW.FIFOread2_PWORK[3];
    fiforead(iPtrs, oPtrs, &dynamixel_control_DW.FIFOread2_IWORK[0]);
  }
}

/* Model update function for TID1 */
static void dynamixel_control_update1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++dynamixel_control_M->Timing.clockTick1)) {
    ++dynamixel_control_M->Timing.clockTickH1;
  }

  dynamixel_control_M->Timing.t[1] = dynamixel_control_M->Timing.clockTick1 *
    dynamixel_control_M->Timing.stepSize1 +
    dynamixel_control_M->Timing.clockTickH1 *
    dynamixel_control_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
static void dynamixel_control_output(int_T tid)
{
  switch (tid) {
   case 0 :
    dynamixel_control_output0();
    break;

   case 1 :
    dynamixel_control_output1();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
static void dynamixel_control_update(int_T tid)
{
  switch (tid) {
   case 0 :
    dynamixel_control_update0();
    break;

   case 1 :
    dynamixel_control_update1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
static void dynamixel_control_initialize(void)
{
  /* Start for Constant: '<Root>/Constant32' */
  dynamixel_control_B.Constant32 = dynamixel_control_P.Constant32_Value;

  /* Start for S-Function (asciiencode): '<Root>/ASCII Encode ' */
  /* Level2 S-Function Block: '<Root>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (fifowrite): '<S1>/FIFO write 1' */
  dynamixel_control_DW.FIFOwrite1_IWORK[0] = 1024;/* fifo size */
  dynamixel_control_DW.FIFOwrite1_IWORK[1] = 6;/* fifo type */
  dynamixel_control_DW.FIFOwrite1_IWORK[2] = 128;/* inport width */

  /* allocate memory for FIFO */
  dynamixel_control_DW.FIFOwrite1_PWORK[0] = malloc(4 * (1024 + 3));
  if (dynamixel_control_DW.FIFOwrite1_PWORK[0] == NULL) {
    rtmSetErrorStatus(dynamixel_control_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  dynamixel_control_DW.FIFOwrite1_PWORK[1] = &dynamixel_control_B.ASCIIEncode[0];

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOwrite1_PWORK[2] = &dynamixel_control_B.FIFOwrite1_o1;
  dynamixel_control_DW.FIFOwrite1_PWORK[3] = &dynamixel_control_B.FIFOwrite1_o2;

  {
    /* Initialize the fifo */
    int *fifo = dynamixel_control_DW.FIFOwrite1_PWORK[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &dynamixel_control_B.FIFOwrite1_o1;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (fifowrite): '<S1>/FIFO write 2' */
  dynamixel_control_DW.FIFOwrite2_IWORK[0] = 1024;/* fifo size */
  dynamixel_control_DW.FIFOwrite2_IWORK[1] = 6;/* fifo type */
  dynamixel_control_DW.FIFOwrite2_IWORK[2] = 1;/* inport width */

  /* allocate memory for FIFO */
  dynamixel_control_DW.FIFOwrite2_PWORK[0] = malloc(4 * (1024 + 3));
  if (dynamixel_control_DW.FIFOwrite2_PWORK[0] == NULL) {
    rtmSetErrorStatus(dynamixel_control_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  dynamixel_control_DW.FIFOwrite2_PWORK[1] = (uint8_T*)&dynamixel_control_U8GND;

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOwrite2_PWORK[2] = &dynamixel_control_B.FIFOwrite2_o1;
  dynamixel_control_DW.FIFOwrite2_PWORK[3] = &dynamixel_control_B.FIFOwrite2_o2;

  {
    /* Initialize the fifo */
    int *fifo = dynamixel_control_DW.FIFOwrite2_PWORK[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &dynamixel_control_B.FIFOwrite2_o1;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (xpcinterrupt): '<S1>/IRQ Source' incorporates:
   *  SubSystem: '<S1>/RS232 ISR'
   */
  dynamixel_co_RS232ISR_Start();

  /* End of Start for S-Function (xpcinterrupt): '<S1>/IRQ Source' */

  /* Start for S-Function (fiforead): '<S1>/FIFO read 1' */
  dynamixel_control_DW.FIFOread1_IWORK[0] = 2048;/* Max to read */
  dynamixel_control_DW.FIFOread1_IWORK[1] = 1;/* Min to read */
  dynamixel_control_DW.FIFOread1_IWORK[2] = 0;/* Use delimiter? */
  dynamixel_control_DW.FIFOread1_IWORK[3] = 13;/* delimiter */
  dynamixel_control_DW.FIFOread1_IWORK[4] = 4;/* FIFO type */

  /* Input pointer(s) */
  dynamixel_control_DW.FIFOread1_PWORK[0] = &dynamixel_control_B.RateTransition1;
  dynamixel_control_DW.FIFOread1_PWORK[1] = NULL;
  dynamixel_control_DW.FIFOread1_PWORK[2] = NULL;

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOread1_PWORK[3] = &dynamixel_control_B.FIFOread1[0];
  dynamixel_control_DW.FIFOread1_PWORK[4] = NULL;

  /* Start for S-Function (fiforead): '<S1>/FIFO read 2' */
  dynamixel_control_DW.FIFOread2_IWORK[0] = 1024;/* Max to read */
  dynamixel_control_DW.FIFOread2_IWORK[1] = 1;/* Min to read */
  dynamixel_control_DW.FIFOread2_IWORK[2] = 1;/* Use delimiter? */
  dynamixel_control_DW.FIFOread2_IWORK[3] = 13;/* delimiter */
  dynamixel_control_DW.FIFOread2_IWORK[4] = 4;/* FIFO type */

  /* Input pointer(s) */
  dynamixel_control_DW.FIFOread2_PWORK[0] = &dynamixel_control_B.RateTransition3;
  dynamixel_control_DW.FIFOread2_PWORK[1] = NULL;
  dynamixel_control_DW.FIFOread2_PWORK[2] = NULL;

  /* Output pointer(s) */
  dynamixel_control_DW.FIFOread2_PWORK[3] = &dynamixel_control_B.FIFOread2[0];
  dynamixel_control_DW.FIFOread2_PWORK[4] = NULL;

  /* Start for S-Function (sersetupbase): '<S1>/Setup1' */
  /* Level2 S-Function Block: '<S1>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sersetupbase): '<S1>/Setup2' */
  /* Level2 S-Function Block: '<S1>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* user code (Start function Trailer) */
  {
    uint8_T irq = 4;

    /* For an ISA board, save the given address in the struct. */
    xpcDev_1.BaseAddress[0] = 0;

    /* connect ISR system: IRQ 4 */
    if (xpceRegisterISR( irq, xPCISR1,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        0,
                        &xpcDev_1) == -1) {
      static uint8_T ermsg[100];
      sprintf( ermsg, "ISR registration failed for Interrupt %d ISA board at 0.",
              irq );
      rtmSetErrorStatus(dynamixel_control_M, ermsg);
      return;
    }
  }

  xpcOutpB( 0xA0, 0x20 );
  xpcOutpB( 0x20, 0x20 );
  rtw_xpc_mutex_create(&dynamixel_control_M->Timing.semIdForTask2);
}

/* Model terminate function */
static void dynamixel_control_terminate(void)
{
  /* user code (Terminate function Header) */

  /* disable interrupt for IRQ 4 */
  xpceDeRegisterISR( &xpcDev_1 );
  rtw_xpc_mutex_delete(dynamixel_control_M->Timing.semIdForTask2);

  /* Terminate for S-Function (asciiencode): '<Root>/ASCII Encode ' */
  /* Level2 S-Function Block: '<Root>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (fifowrite): '<S1>/FIFO write 1' */

  /* Free fifo memory */
  if (dynamixel_control_DW.FIFOwrite1_PWORK[0]) {
    free(dynamixel_control_DW.FIFOwrite1_PWORK[0]);
  }

  /* Terminate for S-Function (fifowrite): '<S1>/FIFO write 2' */

  /* Free fifo memory */
  if (dynamixel_control_DW.FIFOwrite2_PWORK[0]) {
    free(dynamixel_control_DW.FIFOwrite2_PWORK[0]);
  }

  /* Terminate for S-Function (xpcinterrupt): '<S1>/IRQ Source' incorporates:
   *  SubSystem: '<S1>/RS232 ISR'
   */
  dynamixel_con_RS232ISR_Term();

  /* End of Terminate for S-Function (xpcinterrupt): '<S1>/IRQ Source' */

  /* Terminate for S-Function (sersetupbase): '<S1>/Setup1' */
  /* Level2 S-Function Block: '<S1>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sersetupbase): '<S1>/Setup2' */
  /* Level2 S-Function Block: '<S1>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = dynamixel_control_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  dynamixel_control_output(tid);
}

void MdlUpdate(int_T tid)
{
  dynamixel_control_update(tid);
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
  dynamixel_control_initialize();
}

void MdlTerminate(void)
{
  dynamixel_control_terminate();
}

/* Registration function */
RT_MODEL_dynamixel_control_T *dynamixel_control(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)dynamixel_control_M, 0,
                sizeof(RT_MODEL_dynamixel_control_T));
  rtsiSetSolverName(&dynamixel_control_M->solverInfo,"FixedStepDiscrete");
  dynamixel_control_M->solverInfoPtr = (&dynamixel_control_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = dynamixel_control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    dynamixel_control_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    dynamixel_control_M->Timing.sampleTimes =
      (&dynamixel_control_M->Timing.sampleTimesArray[0]);
    dynamixel_control_M->Timing.offsetTimes =
      (&dynamixel_control_M->Timing.offsetTimesArray[0]);

    /* task periods */
    dynamixel_control_M->Timing.sampleTimes[0] = (0.001);
    dynamixel_control_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    dynamixel_control_M->Timing.offsetTimes[0] = (0.0);
    dynamixel_control_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(dynamixel_control_M, &dynamixel_control_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = dynamixel_control_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      dynamixel_control_M->Timing.perTaskSampleHitsArray;
    dynamixel_control_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    dynamixel_control_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(dynamixel_control_M, -1);
  dynamixel_control_M->Timing.stepSize0 = 0.001;
  dynamixel_control_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    dynamixel_control_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(dynamixel_control_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(dynamixel_control_M->rtwLogInfo, (NULL));
    rtliSetLogT(dynamixel_control_M->rtwLogInfo, "tout");
    rtliSetLogX(dynamixel_control_M->rtwLogInfo, "");
    rtliSetLogXFinal(dynamixel_control_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(dynamixel_control_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(dynamixel_control_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(dynamixel_control_M->rtwLogInfo, 0);
    rtliSetLogDecimation(dynamixel_control_M->rtwLogInfo, 1);
    rtliSetLogY(dynamixel_control_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(dynamixel_control_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(dynamixel_control_M->rtwLogInfo, (NULL));
  }

  dynamixel_control_M->solverInfoPtr = (&dynamixel_control_M->solverInfo);
  dynamixel_control_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&dynamixel_control_M->solverInfo, 0.001);
  rtsiSetSolverMode(&dynamixel_control_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  dynamixel_control_M->blockIO = ((void *) &dynamixel_control_B);
  (void) memset(((void *) &dynamixel_control_B), 0,
                sizeof(B_dynamixel_control_T));

  {
    dynamixel_control_B.FIFOwrite1_o1 = serialfifoground;
    dynamixel_control_B.FIFOwrite2_o1 = serialfifoground;
    dynamixel_control_B.RateTransition = serialfifoground;
    dynamixel_control_B.RateTransition2 = serialfifoground;
    dynamixel_control_B.RateTransition1 = serialfifoground;
    dynamixel_control_B.RateTransition3 = serialfifoground;
    dynamixel_control_B.FIFOwrite2 = serialfifoground;
    dynamixel_control_B.FIFOwrite1 = serialfifoground;
  }

  /* parameters */
  dynamixel_control_M->defaultParam = ((real_T *)&dynamixel_control_P);

  /* states (dwork) */
  dynamixel_control_M->dwork = ((void *) &dynamixel_control_DW);
  (void) memset((void *)&dynamixel_control_DW, 0,
                sizeof(DW_dynamixel_control_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  dynamixel_control_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &dynamixel_control_M->NonInlinedSFcns.sfcnInfo;
    dynamixel_control_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(dynamixel_control_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &dynamixel_control_M->Sizes.numSampTimes);
    dynamixel_control_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (dynamixel_control_M)[0]);
    dynamixel_control_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (dynamixel_control_M)[1]);
    dynamixel_control_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (dynamixel_control_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,dynamixel_control_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(dynamixel_control_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(dynamixel_control_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (dynamixel_control_M));
    rtssSetStepSizePtr(sfcnInfo, &dynamixel_control_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(dynamixel_control_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &dynamixel_control_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &dynamixel_control_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &dynamixel_control_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &dynamixel_control_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &dynamixel_control_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &dynamixel_control_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &dynamixel_control_M->solverInfoPtr);
  }

  dynamixel_control_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&dynamixel_control_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  3*sizeof(SimStruct));
    dynamixel_control_M->childSfunctions =
      (&dynamixel_control_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    dynamixel_control_M->childSfunctions[0] =
      (&dynamixel_control_M->NonInlinedSFcns.childSFunctions[0]);
    dynamixel_control_M->childSfunctions[1] =
      (&dynamixel_control_M->NonInlinedSFcns.childSFunctions[1]);
    dynamixel_control_M->childSfunctions[2] =
      (&dynamixel_control_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: dynamixel_control/<Root>/ASCII Encode  (asciiencode) */
    {
      SimStruct *rts = dynamixel_control_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = dynamixel_control_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = dynamixel_control_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = dynamixel_control_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &dynamixel_control_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &dynamixel_control_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, dynamixel_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &dynamixel_control_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &dynamixel_control_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &dynamixel_control_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &dynamixel_control_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &dynamixel_control_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &dynamixel_control_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &dynamixel_control_B.Constant32;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 128);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            dynamixel_control_B.ASCIIEncode));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Encode ");
      ssSetPath(rts, "dynamixel_control/ASCII Encode ");
      ssSetRTModel(rts,dynamixel_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)dynamixel_control_P.ASCIIEncode_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)dynamixel_control_P.ASCIIEncode_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)dynamixel_control_P.ASCIIEncode_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)dynamixel_control_P.ASCIIEncode_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &dynamixel_control_DW.ASCIIEncode_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &dynamixel_control_DW.ASCIIEncode_PWORK);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: dynamixel_control/<S1>/Setup1 (sersetupbase) */
    {
      SimStruct *rts = dynamixel_control_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = dynamixel_control_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = dynamixel_control_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = dynamixel_control_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &dynamixel_control_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &dynamixel_control_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, dynamixel_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &dynamixel_control_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &dynamixel_control_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &dynamixel_control_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &dynamixel_control_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &dynamixel_control_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* path info */
      ssSetModelName(rts, "Setup1");
      ssSetPath(rts, "dynamixel_control/Baseboard Serial/Setup1");
      ssSetRTModel(rts,dynamixel_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)dynamixel_control_P.Setup1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)dynamixel_control_P.Setup1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)dynamixel_control_P.Setup1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)dynamixel_control_P.Setup1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)dynamixel_control_P.Setup1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)dynamixel_control_P.Setup1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)dynamixel_control_P.Setup1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)dynamixel_control_P.Setup1_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &dynamixel_control_DW.Setup1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &dynamixel_control_DW.Setup1_IWORK[0]);
      }

      /* registration */
      sersetupbase(rts);
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

    /* Level2 S-Function Block: dynamixel_control/<S1>/Setup2 (sersetupbase) */
    {
      SimStruct *rts = dynamixel_control_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = dynamixel_control_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = dynamixel_control_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = dynamixel_control_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &dynamixel_control_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &dynamixel_control_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, dynamixel_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &dynamixel_control_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &dynamixel_control_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &dynamixel_control_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &dynamixel_control_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &dynamixel_control_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* path info */
      ssSetModelName(rts, "Setup2");
      ssSetPath(rts, "dynamixel_control/Baseboard Serial/Setup2");
      ssSetRTModel(rts,dynamixel_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)dynamixel_control_P.Setup2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)dynamixel_control_P.Setup2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)dynamixel_control_P.Setup2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)dynamixel_control_P.Setup2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)dynamixel_control_P.Setup2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)dynamixel_control_P.Setup2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)dynamixel_control_P.Setup2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)dynamixel_control_P.Setup2_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &dynamixel_control_DW.Setup2_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &dynamixel_control_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &dynamixel_control_DW.Setup2_IWORK[0]);
      }

      /* registration */
      sersetupbase(rts);
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
  }

  /* Initialize Sizes */
  dynamixel_control_M->Sizes.numContStates = (0);/* Number of continuous states */
  dynamixel_control_M->Sizes.numY = (0);/* Number of model outputs */
  dynamixel_control_M->Sizes.numU = (0);/* Number of model inputs */
  dynamixel_control_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  dynamixel_control_M->Sizes.numSampTimes = (2);/* Number of sample times */
  dynamixel_control_M->Sizes.numBlocks = (34);/* Number of blocks */
  dynamixel_control_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  dynamixel_control_M->Sizes.numBlockPrms = (79);/* Sum of parameter "widths" */
  return dynamixel_control_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
