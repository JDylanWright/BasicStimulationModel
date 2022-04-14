/*
 * SimpleStim.h
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

#ifndef RTW_HEADER_SimpleStim_h_
#define RTW_HEADER_SimpleStim_h_
#include <cmath>
#include <cstring>
#include <types.h>
#include <net/packet.h>
#include <net/evtype.h>
#include <msglib.h>
#include <melody.h>
#include <net/event.h>
#include <xpctarget.h>
#include <net.h>
#include <errno.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "verify/verifyIntrf.h"
#include "SimpleStim_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "SimpleStim_cal.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Define constants for ChangeScheduleState() */
enum {
  SCHED_STATE_READY = 1,
  SCHED_STATE_SUSPEND = 2
};

/* Block signals for system '<S2>/set_delays' */
typedef struct {
  uint16_T delay[12];                  /* '<S2>/set_delays' */
} B_set_delays_SimpleStim_T;

/* Block signals (default storage) */
typedef struct {
  real_T DigitalClock;                 /* '<Root>/Digital Clock' */
  real_T DataStoreRead1;               /* '<Root>/Data Store Read1' */
  real_T DataStoreRead;                /* '<S4>/Data Store Read' */
  real_T stim_PARead[24];              /* '<S2>/stim_PA Read' */
  real_T u;                            /* '<S4>/ ' */
  real_T CheckLowerBound[24];          /* '<S4>/Check Lower Bound' */
  real_T CheckUpperBound[24];          /* '<S4>/Check Upper Bound' */
  real_T TmpSignalConversionAtLookupTabl[39];
  real_T DataStoreRead2;               /* '<Root>/Data Store Read2' */
  uint16_T stim_IPI;                   /* '<Root>/stim_IPI' */
  uint8_T DataStoreRead_f;             /* '<S5>/Data Store Read' */
  uint8_T StimPWRead[24];              /* '<S2>/Stim PW Read' */
  uint8_T u_f;                         /* '<S5>/ ' */
  uint8_T CheckLowerBound_h[24];       /* '<S5>/Check Lower Bound' */
  uint8_T CheckUpperBound_k[24];       /* '<S5>/Check Upper Bound' */
  uint8_T PWStimOnOff[24];             /* '<S2>/PW Stim On//Off' */
  uint8_T LookupTableDynamic[24];      /* '<S6>/Lookup Table Dynamic' */
  uint8_T PAStimOnOff[24];             /* '<S2>/PA Stim On//Off' */
  boolean_T GreaterThan1;              /* '<Root>/GreaterThan1' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
  boolean_T GreaterThan[24];           /* '<S5>/GreaterThan' */
  boolean_T LessThanOrEqual[24];       /* '<S5>/LessThanOrEqual' */
  boolean_T stim_CHRead[24];           /* '<S2>/stim_CH Read' */
  boolean_T GreaterThan_m[24];         /* '<S4>/GreaterThan' */
  boolean_T LessThanOrEqual_m[24];     /* '<S4>/LessThanOrEqual' */
  boolean_T TimeCheck;                 /* '<Root>/Time Check' */
  B_set_delays_SimpleStim_T sf_set_delays1;/* '<S2>/set_delays1' */
  B_set_delays_SimpleStim_T sf_set_delays;/* '<S2>/set_delays' */
} B_SimpleStim_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T HighPALim;                    /* '<Root>/HighPALim Memory' */
  real_T LowPALim;                     /* '<Root>/LowPALim Memory' */
  real_T stim_PA[24];                  /* '<Root>/snp_PA Memory' */
  real_T trial_delay;                  /* '<Root>/trial_delay Memory' */
  real_T trial_stop;                   /* '<Root>/trial_stop Memory' */
  uint16_T Stim_Delay[12];             /* '<S2>/Stim' */
  uint16_T Stim1_Delay[12];            /* '<S2>/Stim1' */
  uint16_T Schedule_Duration;          /* '<Root>/Schedule' */
  uint16_T stim_IPI;                   /* '<Root>/stim_IPI Memory' */
  int8_T Beep_SubsysRanBC;             /* '<Root>/Beep' */
  int8_T Beep_SubsysRanBC_h;           /* '<S1>/Beep' */
  uint8_T Stim_EventID[12];            /* '<S2>/Stim' */
  uint8_T Stim_PW[12];                 /* '<S2>/Stim' */
  uint8_T Stim_Amp[12];                /* '<S2>/Stim' */
  uint8_T Stim1_EventID[12];           /* '<S2>/Stim1' */
  uint8_T Stim1_PW[12];                /* '<S2>/Stim1' */
  uint8_T Stim1_Amp[12];               /* '<S2>/Stim1' */
  uint8_T HighPWLim;                   /* '<Root>/HighPWLim Memory' */
  uint8_T LowPWLim;                    /* '<Root>/LowPWLim Memory' */
  uint8_T stim_PW[24];                 /* '<Root>/stim_PW Memory' */
  boolean_T Stim_Created[12];          /* '<S2>/Stim' */
  boolean_T Stim1_Created[12];         /* '<S2>/Stim1' */
  boolean_T stim_CH[24];               /* '<Root>/stim_CH Memory' */
} DW_SimpleStim_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Beep_Trig_ZCE;            /* '<Root>/Beep' */
} PrevZCX_SimpleStim_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Stim'
   *   '<S2>/Stim1'
   */
  uint8_T pooled2[12];
} ConstP_SimpleStim_T;

/* Real-time Model Data Structure */
struct tag_RTM_SimpleStim_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern B_SimpleStim_T SimpleStim_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern DW_SimpleStim_T SimpleStim_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_SimpleStim_T SimpleStim_PrevZCX;

/* Constant parameters (default storage) */
extern const ConstP_SimpleStim_T SimpleStim_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void SimpleStim_initialize(void);
  extern void SimpleStim_step(void);
  extern void SimpleStim_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_SimpleStim_T *const SimpleStim_M;

#ifdef __cplusplus

}
#endif

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
 * '<Root>' : 'SimpleStim'
 * '<S1>'   : 'SimpleStim/Beep'
 * '<S2>'   : 'SimpleStim/Stim'
 * '<S3>'   : 'SimpleStim/Beep/Beep'
 * '<S4>'   : 'SimpleStim/Stim/Check Bounds PA'
 * '<S5>'   : 'SimpleStim/Stim/Check Bounds PW'
 * '<S6>'   : 'SimpleStim/Stim/mA mapping to simulink'
 * '<S7>'   : 'SimpleStim/Stim/set_delays'
 * '<S8>'   : 'SimpleStim/Stim/set_delays1'
 */
#endif                                 /* RTW_HEADER_SimpleStim_h_ */
