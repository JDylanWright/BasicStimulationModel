/*
 * SimpleStim.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SimpleStim".
 *
 * Model version              : 1.7
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C++ source code generated on : Thu Mar 31 18:20:51 2022
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SimpleStim.h"
#include "SimpleStim_private.h"

/* Block signals (default storage) */
B_SimpleStim_T SimpleStim_B;

/* Block states (default storage) */
DW_SimpleStim_T SimpleStim_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_SimpleStim_T SimpleStim_PrevZCX;

/* Real-time model */
RT_MODEL_SimpleStim_T SimpleStim_M_ = RT_MODEL_SimpleStim_T();
RT_MODEL_SimpleStim_T *const SimpleStim_M = &SimpleStim_M_;
static const char rcs1[] =
  "$Id: ueculib.tlc 1.34 2011/11/21 19:10:30Z fes-tvrabec Rel $";
static const char rcs2[] =
  "$Id: tonebeep.tlc 1.13 2006/02/10 19:30:21Z sct Rel $";
static const char rcs3[] = "$Id: stim_s.tlc 1.23 2007/11/14 21:56:40Z sct Rel $";
static const char rcs4[] =
  "$Id: schedule.tlc 1.20 2007/11/08 15:06:14Z sct Rel $";
static const char rcs5[] =
  "$Id: uecuxpc.tlc 1.12 2011/11/21 19:11:33Z fes-tvrabec Rel $";
u_char sid[NUM_SID];
u_char syncsig[NUM_SYNC];

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup Utility LookUp_U8_real_T */
void LookUp_U8_real_T(uint8_T *pY, const uint8_T *pYData, real_T u, const real_T
                      *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = static_cast<real_T>(pYData[iLeft]);
      yRghtCast = static_cast<real_T>(pYData[iRght]);
      yLeftCast += lambda * ( yRghtCast - yLeftCast );

      {
        real_T rtb_dbl_tmp;
        rtb_dbl_tmp = std::floor(yLeftCast);
        if (rtIsNaN(rtb_dbl_tmp) || rtIsInf(rtb_dbl_tmp)) {
          rtb_dbl_tmp = 0.0;
        } else {
          rtb_dbl_tmp = std::fmod(rtb_dbl_tmp, 256.0);
        }

        (*pY) = rtb_dbl_tmp < 0.0 ? static_cast<uint8_T>(static_cast<int8_T>(-
          static_cast<int8_T>(static_cast<uint8_T>(-rtb_dbl_tmp)))) :
          static_cast<uint8_T>(rtb_dbl_tmp);
      }
    }
  }
}

/*
 * In order to generate Sync messages for synchronous schedules,
 * it is necessary to intercept calls to the MdlOutputs function.
 * This is done by generating our own MdlOutputs, then using a
 * #define to rename the MdlOutputs function generated by RTW.
 * Thus, the system's main function just knows it's calling
 * MdlOutputs, and through sleight of hand we get our function
 * called first, then we chain
 */

/*
 *	In the newest version of Simulink, MdlOutputs reverts to MdlOutpus for
 *	standalone applications, but is called <modelname>_step for simulink realtime.
 *	All calls to MdlOutputs now include tid, but is ignored for single rate
 *	systems. Pass 0 as necessary.
 */
void uecuOriginalMdlOutputs(void);
void SimpleStim_step(void)
{
  uecuOriginalMdlOutputs();
}

#define SimpleStim_step                uecuOriginalMdlOutputs

/*
 * Output and update for atomic system:
 *    '<S2>/set_delays'
 *    '<S2>/set_delays1'
 */
void SimpleStim_set_delays(const uint8_T rtu_PW[12], const uint8_T rtu_PA[12],
  B_set_delays_SimpleStim_T *localB)
{
  int32_T L;
  int32_T i;
  int32_T trueCount;
  int8_T y_data[12];
  uint8_T PWA[12];
  uint8_T d_data[12];

  /* MATLAB Function 'Stim/set_delays': '<S7>:1' */
  /* '<S7>:1:3' */
  trueCount = 0;
  for (L = 0; L < 12; L++) {
    i = static_cast<int32_T>(static_cast<uint32_T>(rtu_PW[L]) * rtu_PA[L]);
    if (static_cast<uint32_T>(i) > 255U) {
      i = 255;
    }

    PWA[L] = static_cast<uint8_T>(i);
    i = static_cast<int32_T>(static_cast<uint32_T>(rtu_PW[L]) * rtu_PA[L]);
    if (static_cast<uint32_T>(i) > 255U) {
      i = 255;
    }

    if (i != 0) {
      /* '<S7>:1:4' */
      trueCount++;
    }
  }

  /* '<S7>:1:4' */
  L = trueCount;

  /* '<S7>:1:5' */
  if (L < 1) {
    trueCount = 0;
  } else {
    trueCount = static_cast<int8_T>(L);
    L = static_cast<int8_T>(L) - 1;
    for (i = 0; i <= L; i++) {
      y_data[i] = static_cast<int8_T>(i + 1);
    }
  }

  L = trueCount - 1;
  for (i = 0; i <= L; i++) {
    d_data[i] = static_cast<uint8_T>(y_data[i]);
  }

  trueCount = 0;
  for (L = 0; L < 12; L++) {
    i = static_cast<int32_T>(static_cast<uint32_T>(rtu_PW[L]) * rtu_PA[L]);
    if (static_cast<uint32_T>(i) > 255U) {
      i = 255;
    }

    if (i != 0) {
      /* '<S7>:1:6' */
      PWA[L] = d_data[trueCount];
      trueCount++;
    }
  }

  /* '<S7>:1:7' */
  for (i = 0; i < 12; i++) {
    localB->delay[i] = PWA[i];
  }
}

/* Model step function */
void SimpleStim_step(void)
{
  int32_T i;
  boolean_T zcEvent;

  /* Reset subsysRan breadcrumbs */
  srClearBC(SimpleStim_DW.Beep_SubsysRanBC_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(SimpleStim_DW.Beep_SubsysRanBC);

  /* DataStoreWrite: '<Root>/stim_IPI Write' incorporates:
   *  Constant: '<Root>/stim_IPI_in'
   */
  SimpleStim_DW.stim_IPI = SimpleStim_cal->stim_IPI_in_Value;

  /* DataStoreWrite: '<Root>/stim_PA Write' incorporates:
   *  Constant: '<Root>/stim_PA_in'
   */
  std::memcpy(&SimpleStim_DW.stim_PA[0], &SimpleStim_cal->stim_PA_in_Value[0],
              24U * sizeof(real_T));
  for (i = 0; i < 24; i++) {
    /* DataStoreWrite: '<Root>/stim_CH Write' incorporates:
     *  Constant: '<Root>/stim_CH_in'
     */
    SimpleStim_DW.stim_CH[i] = SimpleStim_cal->stim_CH_in_Value[i];

    /* DataStoreWrite: '<Root>/stim_PW_Write' incorporates:
     *  Constant: '<Root>/stim_PW_in'
     */
    SimpleStim_DW.stim_PW[i] = SimpleStim_cal->stim_PW_in_Value[i];
  }

  /* DataStoreWrite: '<Root>/trial_delay Write' incorporates:
   *  Constant: '<Root>/trial_delay_in'
   */
  SimpleStim_DW.trial_delay = SimpleStim_cal->trial_delay_in_Value;

  /* DataStoreWrite: '<Root>/trial_stop Write' incorporates:
   *  Constant: '<Root>/trial_stop_in'
   */
  SimpleStim_DW.trial_stop = SimpleStim_cal->trial_stop_in_Value;

  /* DigitalClock: '<Root>/Digital Clock' */
  SimpleStim_B.DigitalClock = (((SimpleStim_M->Timing.clockTick1+
    SimpleStim_M->Timing.clockTickH1* 4294967296.0)) * 0.001);

  /* DataStoreRead: '<Root>/Data Store Read1' */
  SimpleStim_B.DataStoreRead1 = SimpleStim_DW.trial_delay;

  /* RelationalOperator: '<Root>/GreaterThan1' */
  SimpleStim_B.GreaterThan1 = (SimpleStim_B.DigitalClock >
    SimpleStim_B.DataStoreRead1);

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Beep State'
   */
  SimpleStim_B.LogicalOperator = (SimpleStim_B.GreaterThan1 &&
    (SimpleStim_cal->BeepState_Value != 0.0));

  /* Outputs for Triggered SubSystem: '<Root>/Beep' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  zcEvent = (SimpleStim_B.LogicalOperator && (SimpleStim_PrevZCX.Beep_Trig_ZCE
              != POS_ZCSIG));
  if (zcEvent) {
    /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/Beep'
     */
    /* S-Function (tonebeep): '<S3>/S-Function' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     */
    {
      struct MelodyNote n[4];
      n[0].note = NOTE_CLEAR;          /* Interrupt anything already playing */
      n[0].dur = 0;
      n[1].note = NOTE_ADDR;           /* Select the system module */
      n[1].dur = 11;
      n[2].note = NOTE_VOL;            /* Select the volume */
      n[2].dur = SimpleStim_cal->Constant1_Value_n;
      n[3].note = SimpleStim_cal->Constant_Value_f;/* Play the beep */
      n[3].dur = SimpleStim_cal->Constant2_Value;
      if (n[3].note < 128) {
        if (melody(0, n, sizeof(n) / sizeof(n[0]))) {
          rtmSetErrorStatus(SimpleStim_M, uerror("melody", __FILE__, __LINE__));
          return;
        }
      }
    }

    SimpleStim_DW.Beep_SubsysRanBC_h = 4;

    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */
    SimpleStim_DW.Beep_SubsysRanBC = 4;
  }

  SimpleStim_PrevZCX.Beep_Trig_ZCE = SimpleStim_B.LogicalOperator;

  /* End of Outputs for SubSystem: '<Root>/Beep' */

  /* DataStoreRead: '<S5>/Data Store Read' */
  SimpleStim_B.DataStoreRead_f = SimpleStim_DW.HighPWLim;

  /* DataStoreRead: '<S5>/ ' */
  SimpleStim_B.u_f = SimpleStim_DW.LowPWLim;
  for (i = 0; i < 24; i++) {
    /* DataStoreRead: '<S2>/Stim PW Read' */
    SimpleStim_B.StimPWRead[i] = SimpleStim_DW.stim_PW[i];

    /* RelationalOperator: '<S5>/GreaterThan' */
    SimpleStim_B.GreaterThan[i] = (SimpleStim_B.StimPWRead[i] >=
      SimpleStim_B.u_f);

    /* Switch: '<S5>/Check Lower Bound' */
    if (SimpleStim_B.GreaterThan[i]) {
      /* Switch: '<S5>/Check Lower Bound' */
      SimpleStim_B.CheckLowerBound_h[i] = SimpleStim_B.StimPWRead[i];
    } else {
      /* Switch: '<S5>/Check Lower Bound' */
      SimpleStim_B.CheckLowerBound_h[i] = SimpleStim_B.u_f;
    }

    /* End of Switch: '<S5>/Check Lower Bound' */

    /* RelationalOperator: '<S5>/LessThanOrEqual' */
    SimpleStim_B.LessThanOrEqual[i] = (SimpleStim_B.DataStoreRead_f <=
      SimpleStim_B.CheckLowerBound_h[i]);

    /* Switch: '<S5>/Check Upper Bound' */
    if (SimpleStim_B.LessThanOrEqual[i]) {
      /* Switch: '<S5>/Check Upper Bound' */
      SimpleStim_B.CheckUpperBound_k[i] = SimpleStim_B.DataStoreRead_f;
    } else {
      /* Switch: '<S5>/Check Upper Bound' */
      SimpleStim_B.CheckUpperBound_k[i] = SimpleStim_B.CheckLowerBound_h[i];
    }

    /* End of Switch: '<S5>/Check Upper Bound' */

    /* DataStoreRead: '<S2>/stim_CH Read' */
    SimpleStim_B.stim_CHRead[i] = SimpleStim_DW.stim_CH[i];
  }

  for (i = 0; i < 24; i++) {
    /* Product: '<S2>/PW Stim On//Off' */
    SimpleStim_B.PWStimOnOff[i] = static_cast<uint8_T>(SimpleStim_B.GreaterThan1
      ? SimpleStim_B.stim_CHRead[i] ? static_cast<int32_T>
      (SimpleStim_B.CheckUpperBound_k[i]) : 0 : 0);
  }

  /* DataStoreRead: '<S4>/Data Store Read' */
  SimpleStim_B.DataStoreRead = SimpleStim_DW.HighPALim;

  /* DataStoreRead: '<S4>/ ' */
  SimpleStim_B.u = SimpleStim_DW.LowPALim;
  for (i = 0; i < 24; i++) {
    /* DataStoreRead: '<S2>/stim_PA Read' */
    SimpleStim_B.stim_PARead[i] = SimpleStim_DW.stim_PA[i];

    /* RelationalOperator: '<S4>/GreaterThan' */
    SimpleStim_B.GreaterThan_m[i] = (SimpleStim_B.stim_PARead[i] >=
      SimpleStim_B.u);

    /* Switch: '<S4>/Check Lower Bound' */
    if (SimpleStim_B.GreaterThan_m[i]) {
      /* Switch: '<S4>/Check Lower Bound' */
      SimpleStim_B.CheckLowerBound[i] = SimpleStim_B.stim_PARead[i];
    } else {
      /* Switch: '<S4>/Check Lower Bound' */
      SimpleStim_B.CheckLowerBound[i] = SimpleStim_B.u;
    }

    /* End of Switch: '<S4>/Check Lower Bound' */

    /* RelationalOperator: '<S4>/LessThanOrEqual' */
    SimpleStim_B.LessThanOrEqual_m[i] = (SimpleStim_B.DataStoreRead <=
      SimpleStim_B.CheckLowerBound[i]);
  }

  for (i = 0; i < 24; i++) {
    /* Switch: '<S4>/Check Upper Bound' */
    if (SimpleStim_B.LessThanOrEqual_m[i]) {
      /* Switch: '<S4>/Check Upper Bound' */
      SimpleStim_B.CheckUpperBound[i] = SimpleStim_B.DataStoreRead;
    } else {
      /* Switch: '<S4>/Check Upper Bound' */
      SimpleStim_B.CheckUpperBound[i] = SimpleStim_B.CheckLowerBound[i];
    }

    /* End of Switch: '<S4>/Check Upper Bound' */
  }

  /* SignalConversion generated from: '<S6>/Lookup Table Dynamic' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  std::memcpy(&SimpleStim_B.TmpSignalConversionAtLookupTabl[0],
              &SimpleStim_cal->Constant_Value[0], 21U * sizeof(real_T));
  std::memcpy(&SimpleStim_B.TmpSignalConversionAtLookupTabl[21],
              &SimpleStim_cal->Constant1_Value[0], 18U * sizeof(real_T));

  /* S-Function (sfix_look1_dyn): '<S6>/Lookup Table Dynamic' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  /* Dynamic Look-Up Table Block: '<S6>/Lookup Table Dynamic'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Integer        U8
   * Output0 Data Type:  Integer        U8
   * Lookup Method: Linear_Endpoint
   *
   */
  {
    int_T i1;
    const real_T *u0 = &SimpleStim_B.CheckUpperBound[0];
    uint8_T *y0 = &SimpleStim_B.LookupTableDynamic[0];
    for (i1=0; i1 < 24; i1++) {
      LookUp_U8_real_T( &(y0[i1]), &SimpleStim_cal->Constant3_Value[0], u0[i1],
                       &SimpleStim_B.TmpSignalConversionAtLookupTabl[0], 38U);
    }
  }

  for (i = 0; i < 24; i++) {
    /* Product: '<S2>/PA Stim On//Off' */
    SimpleStim_B.PAStimOnOff[i] = static_cast<uint8_T>(SimpleStim_B.GreaterThan1
      ? SimpleStim_B.stim_CHRead[i] ? static_cast<int32_T>
      (SimpleStim_B.LookupTableDynamic[i]) : 0 : 0);
  }

  /* MATLAB Function: '<S2>/set_delays' */
  SimpleStim_set_delays(&SimpleStim_B.PWStimOnOff[0], &SimpleStim_B.PAStimOnOff
                        [0], &SimpleStim_B.sf_set_delays);

  /* S-Function (stim_s): '<S2>/Stim' */
  {
    struct StimEvent ev;
    ev.reserved = 0;

    {
      int_T i1;
      const uint8_T *u0 = &SimpleStim_B.PWStimOnOff[0];
      const uint8_T *u1 = &SimpleStim_B.PAStimOnOff[0];
      const uint16_T *u2 = &SimpleStim_B.sf_set_delays.delay[0];
      const uint8_T *p_Channels = SimpleStim_ConstP.pooled2;
      uint8_T *dw_EventID = &SimpleStim_DW.Stim_EventID[0];
      boolean_T *dw_Created = &SimpleStim_DW.Stim_Created[0];
      uint8_T *dw_PW = &SimpleStim_DW.Stim_PW[0];
      uint8_T *dw_Amp = &SimpleStim_DW.Stim_Amp[0];
      uint16_T *dw_Delay = &SimpleStim_DW.Stim_Delay[0];
      for (i1=0; i1 < 12; i1++) {
        ev.pw = u0[i1];
        ev.amp = u1[i1];
        if (dw_Created[i1]) {
          if (ev.pw != dw_PW[i1] || ev.amp != dw_Amp[i1]) {
            if (change_event_params(1, dw_EventID[i1], &ev, sizeof(ev)) < 0) {
              rtmSetErrorStatus(SimpleStim_M, uerror("change_event_params",
                __FILE__, __LINE__));
              return;
            }
          }

          if (u2[i1] != dw_Delay[i1]) {
            if (change_event_sched(1, dw_EventID[i1], sid[0], u2[i1], 100) < 0)
            {
              rtmSetErrorStatus(SimpleStim_M, uerror("change_event_sched",
                __FILE__, __LINE__));
              return;
            }
          }
        } else {
          int e;
          dw_EventID[i1] = e = create_event(1, sid[0], u2[i1], 100, et_StimEvent,
            (0 << 6) + (p_Channels[i1]), &ev, sizeof(ev));
          if (e < 0) {
            rtmSetErrorStatus(SimpleStim_M, uerror("create_event", __FILE__,
              __LINE__));
            return;
          }

          dw_Created[i1] = 1;
        }

        dw_PW[i1] = ev.pw;
        dw_Amp[i1] = ev.amp;
        dw_Delay[i1] = u2[i1];
      }
    }
  }

  /* MATLAB Function: '<S2>/set_delays1' */
  SimpleStim_set_delays(&SimpleStim_B.PWStimOnOff[12],
                        &SimpleStim_B.PAStimOnOff[12],
                        &SimpleStim_B.sf_set_delays1);

  /* S-Function (stim_s): '<S2>/Stim1' */
  {
    struct StimEvent ev;
    ev.reserved = 0;

    {
      int_T i1;
      const uint8_T *u0 = &SimpleStim_B.PWStimOnOff[12];
      const uint8_T *u1 = &SimpleStim_B.PAStimOnOff[12];
      const uint16_T *u2 = &SimpleStim_B.sf_set_delays1.delay[0];
      const uint8_T *p_Channels = SimpleStim_ConstP.pooled2;
      uint8_T *dw_EventID = &SimpleStim_DW.Stim1_EventID[0];
      boolean_T *dw_Created = &SimpleStim_DW.Stim1_Created[0];
      uint8_T *dw_PW = &SimpleStim_DW.Stim1_PW[0];
      uint8_T *dw_Amp = &SimpleStim_DW.Stim1_Amp[0];
      uint16_T *dw_Delay = &SimpleStim_DW.Stim1_Delay[0];
      for (i1=0; i1 < 12; i1++) {
        ev.pw = u0[i1];
        ev.amp = u1[i1];
        if (dw_Created[i1]) {
          if (ev.pw != dw_PW[i1] || ev.amp != dw_Amp[i1]) {
            if (change_event_params(2, dw_EventID[i1], &ev, sizeof(ev)) < 0) {
              rtmSetErrorStatus(SimpleStim_M, uerror("change_event_params",
                __FILE__, __LINE__));
              return;
            }
          }

          if (u2[i1] != dw_Delay[i1]) {
            if (change_event_sched(2, dw_EventID[i1], sid[1], u2[i1], 100) < 0)
            {
              rtmSetErrorStatus(SimpleStim_M, uerror("change_event_sched",
                __FILE__, __LINE__));
              return;
            }
          }
        } else {
          int e;
          dw_EventID[i1] = e = create_event(2, sid[1], u2[i1], 100, et_StimEvent,
            (0 << 6) + (p_Channels[i1]), &ev, sizeof(ev));
          if (e < 0) {
            rtmSetErrorStatus(SimpleStim_M, uerror("create_event", __FILE__,
              __LINE__));
            return;
          }

          dw_Created[i1] = 1;
        }

        dw_PW[i1] = ev.pw;
        dw_Amp[i1] = ev.amp;
        dw_Delay[i1] = u2[i1];
      }
    }
  }

  /* DataStoreRead: '<Root>/Data Store Read2' */
  SimpleStim_B.DataStoreRead2 = SimpleStim_DW.trial_stop;

  /* RelationalOperator: '<Root>/Time Check' */
  SimpleStim_B.TimeCheck = (SimpleStim_B.DigitalClock >
    SimpleStim_B.DataStoreRead2);

  /* Stop: '<Root>/Stop Simulation' */
  if (SimpleStim_B.TimeCheck) {
    rtmSetStopRequested(SimpleStim_M, 1);
  }

  /* End of Stop: '<Root>/Stop Simulation' */

  /* DataStoreRead: '<Root>/stim_IPI' */
  SimpleStim_B.stim_IPI = SimpleStim_DW.stim_IPI;

  /* S-Function (schedule): '<Root>/Schedule' */
  /*
   * About '<Root>/Schedule':
   *   Schedule name: schedule1
   */
  {
    u_short dur;
    dur = SimpleStim_B.stim_IPI;
    if (dur != SimpleStim_DW.Schedule_Duration) {
      /* Change the schedule time */
      if (change_schedule(1, sid[0], syncsig[0], dur) < 0) {/* schedule1 */
        rtmSetErrorStatus(SimpleStim_M, uerror("change_schedule", __FILE__,
          __LINE__));
        return;
      }

      if (change_schedule(2, sid[1], syncsig[0], dur) < 0) {/* schedule1 */
        rtmSetErrorStatus(SimpleStim_M, uerror("change_schedule", __FILE__,
          __LINE__));
        return;
      }

      if (SimpleStim_DW.Schedule_Duration == 0) {
        /* Start the schedule running */
        if (sync(1, syncsig[0]) < 0) { /* schedule1 */
          rtmSetErrorStatus(SimpleStim_M, uerror("sync", __FILE__, __LINE__));
          return;
        }

        if (sync(2, syncsig[0]) < 0) { /* schedule1 */
          rtmSetErrorStatus(SimpleStim_M, uerror("sync", __FILE__, __LINE__));
          return;
        }
      }

      SimpleStim_DW.Schedule_Duration = dur;
    }
  }

  /* S-Function (uecuxpc): '<Root>/xPC-UECU Config' */
  uecu_poll();

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SimpleStim_M->Timing.clockTick0)) {
    ++SimpleStim_M->Timing.clockTickH0;
  }

  SimpleStim_M->Timing.t[0] = SimpleStim_M->Timing.clockTick0 *
    SimpleStim_M->Timing.stepSize0 + SimpleStim_M->Timing.clockTickH0 *
    SimpleStim_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    SimpleStim_M->Timing.clockTick1++;
    if (!SimpleStim_M->Timing.clockTick1) {
      SimpleStim_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void SimpleStim_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SimpleStim_M->solverInfo,
                          &SimpleStim_M->Timing.simTimeStep);
    rtsiSetTPtr(&SimpleStim_M->solverInfo, &rtmGetTPtr(SimpleStim_M));
    rtsiSetStepSizePtr(&SimpleStim_M->solverInfo,
                       &SimpleStim_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&SimpleStim_M->solverInfo, (&rtmGetErrorStatus
      (SimpleStim_M)));
    rtsiSetRTModelPtr(&SimpleStim_M->solverInfo, SimpleStim_M);
  }

  rtsiSetSimTimeStep(&SimpleStim_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&SimpleStim_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(SimpleStim_M, &SimpleStim_M->Timing.tArray[0]);
  SimpleStim_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&SimpleStim_B)), 0,
                     sizeof(B_SimpleStim_T));

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&SimpleStim_DW), 0,
                     sizeof(DW_SimpleStim_T));

  {
    int32_T i;

    /* user code (Start function Body) */

    /* S-Function Block: <Root>/xPC-UECU Config (uecuxpc) */
    if (uecu_init(128, 2, 1, 1)) {
      rtmSetErrorStatus(SimpleStim_M, "Unable to initialize RS-232 port");
      return;
    }

    /*
     * Create all schedules needed by this model.
     */
    if (!xpcIsModelInit()) {
      syncsig[0] = new_sync_signal();  /* schedule1 */

      {
        int tmp;
        sid[0] = tmp = create_schedule(1, syncsig[0], 0);/* schedule1, address 1 */
        if (tmp < 0) {
          rtmSetErrorStatus(SimpleStim_M, uerror("create_schedule", __FILE__,
            __LINE__));
          return;
        }

        sid[1] = tmp = create_schedule(2, syncsig[0], 0);/* schedule1, address 2 */
        if (tmp < 0) {
          rtmSetErrorStatus(SimpleStim_M, uerror("create_schedule", __FILE__,
            __LINE__));
          return;
        }
      }
    }

    /* Start for S-Function (stim_s): '<S2>/Stim' */
    {
      int_T i1;
      uint8_T *dw_EventID = &SimpleStim_DW.Stim_EventID[0];
      boolean_T *dw_Created = &SimpleStim_DW.Stim_Created[0];
      uint8_T *dw_PW = &SimpleStim_DW.Stim_PW[0];
      uint8_T *dw_Amp = &SimpleStim_DW.Stim_Amp[0];
      uint16_T *dw_Delay = &SimpleStim_DW.Stim_Delay[0];
      for (i1=0; i1 < 12; i1++) {
        dw_Created[i1] = 0;
      }
    }

    /* Start for S-Function (stim_s): '<S2>/Stim1' */
    {
      int_T i1;
      uint8_T *dw_EventID = &SimpleStim_DW.Stim1_EventID[0];
      boolean_T *dw_Created = &SimpleStim_DW.Stim1_Created[0];
      uint8_T *dw_PW = &SimpleStim_DW.Stim1_PW[0];
      uint8_T *dw_Amp = &SimpleStim_DW.Stim1_Amp[0];
      uint16_T *dw_Delay = &SimpleStim_DW.Stim1_Delay[0];
      for (i1=0; i1 < 12; i1++) {
        dw_Created[i1] = 0;
      }
    }

    /* Start for DataStoreMemory: '<Root>/HighPALim Memory' */
    SimpleStim_DW.HighPALim = SimpleStim_cal->HighPALimMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/HighPWLim Memory' */
    SimpleStim_DW.HighPWLim = SimpleStim_cal->HighPWLimMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/LowPALim Memory' */
    SimpleStim_DW.LowPALim = SimpleStim_cal->LowPALimMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/LowPWLim Memory' */
    SimpleStim_DW.LowPWLim = SimpleStim_cal->LowPWLimMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/stim_IPI Memory' */
    SimpleStim_DW.stim_IPI = SimpleStim_cal->stim_IPIMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/snp_PA Memory' */
    std::memcpy(&SimpleStim_DW.stim_PA[0],
                &SimpleStim_cal->snp_PAMemory_InitialValue[0], 24U * sizeof
                (real_T));
    for (i = 0; i < 24; i++) {
      /* Start for DataStoreMemory: '<Root>/stim_CH Memory' */
      SimpleStim_DW.stim_CH[i] = SimpleStim_cal->stim_CHMemory_InitialValue[i];

      /* Start for DataStoreMemory: '<Root>/stim_PW Memory' */
      SimpleStim_DW.stim_PW[i] = SimpleStim_cal->stim_PWMemory_InitialValue[i];
    }

    /* End of Start for DataStoreMemory: '<Root>/snp_PA Memory' */

    /* Start for DataStoreMemory: '<Root>/trial_delay Memory' */
    SimpleStim_DW.trial_delay = SimpleStim_cal->trial_delayMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/trial_stop Memory' */
    SimpleStim_DW.trial_stop = SimpleStim_cal->trial_stopMemory_InitialValue;
  }

  SimpleStim_PrevZCX.Beep_Trig_ZCE = POS_ZCSIG;

  /* Enable for S-Function (schedule): '<Root>/Schedule' */
  /* Level2 S-Function Block: '<Root>/Schedule' (schedule) */

  /* S-Function Block: <Root>/Schedule (schedule) */
  if (!xpcIsModelInit()) {
    if (change_schedule_state(1, sid[0], SCHED_STATE_READY) < 0) {/* schedule1 */
      rtmSetErrorStatus(SimpleStim_M, uerror("change_schedule_state", __FILE__,
        __LINE__));
      return;
    }

    if (change_schedule_state(2, sid[1], SCHED_STATE_READY) < 0) {/* schedule1 */
      rtmSetErrorStatus(SimpleStim_M, uerror("change_schedule_state", __FILE__,
        __LINE__));
      return;
    }
  }

  SimpleStim_DW.Schedule_Duration = 0; /* Force a Sync later */
}

/* Model terminate function */
void SimpleStim_terminate(void)
{
  /* Terminate for S-Function (schedule): '<Root>/Schedule' */

  /* S-Function Block: <Root>/Schedule (schedule) */
  if (!xpcIsModelInit()) {
    if (delete_schedule(1, sid[0]) < 0) {/* schedule1 */
      rtmSetErrorStatus(SimpleStim_M, uerror("delete_schedule", __FILE__,
        __LINE__));
      return;
    }

    if (delete_schedule(2, sid[1]) < 0) {/* schedule1 */
      rtmSetErrorStatus(SimpleStim_M, uerror("delete_schedule", __FILE__,
        __LINE__));
      return;
    }
  }

  /* user code (Terminate function Trailer) */

  /* S-Function Block: <Root>/xPC-UECU Config (uecuxpc) */
  uecu_shutdown();
}