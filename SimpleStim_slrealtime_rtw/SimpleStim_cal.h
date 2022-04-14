#ifndef RTW_HEADER_SimpleStim_cal_h_
#define RTW_HEADER_SimpleStim_cal_h_
#include "rtwtypes.h"
#include "SimpleStim_types.h"

/* Storage class 'PageSwitching', for system '<Root>' */
typedef struct {
  real_T stim_PA_in_Value[24];         /* Expression: zeros(1,24)
                                        * Referenced by: '<Root>/stim_PA_in'
                                        */
  real_T Constant_Value[21];           /* Expression: 0:0.1:2
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value[18];          /* Expression: 2.2:0.2:5.6
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T snp_PAMemory_InitialValue[24];/* Expression: zeros(1,24)
                                        * Referenced by: '<Root>/snp_PA Memory'
                                        */
  real_T trial_delay_in_Value;         /* Expression: 0
                                        * Referenced by: '<Root>/trial_delay_in'
                                        */
  real_T trial_stop_in_Value;          /* Expression: 10
                                        * Referenced by: '<Root>/trial_stop_in'
                                        */
  real_T BeepState_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Beep State'
                                        */
  real_T HighPALimMemory_InitialValue; /* Expression: 5.6
                                        * Referenced by: '<Root>/HighPALim Memory'
                                        */
  real_T LowPALimMemory_InitialValue;  /* Expression: 0
                                        * Referenced by: '<Root>/LowPALim Memory'
                                        */
  real_T trial_delayMemory_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/trial_delay Memory'
                                         */
  real_T trial_stopMemory_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/trial_stop Memory'
                                        */
  uint16_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint16_T stim_IPI_in_Value;          /* Computed Parameter: stim_IPI_in_Value
                                        * Referenced by: '<Root>/stim_IPI_in'
                                        */
  uint16_T stim_IPIMemory_InitialValue;
                              /* Computed Parameter: stim_IPIMemory_InitialValue
                               * Referenced by: '<Root>/stim_IPI Memory'
                               */
  uint8_T stim_PW_in_Value[24];        /* Computed Parameter: stim_PW_in_Value
                                        * Referenced by: '<Root>/stim_PW_in'
                                        */
  uint8_T Constant3_Value[39];         /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S6>/Constant3'
                                        */
  uint8_T stim_PWMemory_InitialValue[24];
                               /* Computed Parameter: stim_PWMemory_InitialValue
                                * Referenced by: '<Root>/stim_PW Memory'
                                */
  uint8_T Constant_Value_f;            /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T Constant1_Value_n;           /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T HighPWLimMemory_InitialValue;
                             /* Computed Parameter: HighPWLimMemory_InitialValue
                              * Referenced by: '<Root>/HighPWLim Memory'
                              */
  uint8_T LowPWLimMemory_InitialValue;
                              /* Computed Parameter: LowPWLimMemory_InitialValue
                               * Referenced by: '<Root>/LowPWLim Memory'
                               */
  boolean_T stim_CH_in_Value[24];      /* Computed Parameter: stim_CH_in_Value
                                        * Referenced by: '<Root>/stim_CH_in'
                                        */
  boolean_T stim_CHMemory_InitialValue[24];
                               /* Computed Parameter: stim_CHMemory_InitialValue
                                * Referenced by: '<Root>/stim_CH Memory'
                                */
} SimpleStim_cal_type;

/* Storage class 'PageSwitching' */

/* Storage class 'PageSwitching' */
extern SimpleStim_cal_type SimpleStim_cal_impl;
extern SimpleStim_cal_type *SimpleStim_cal;

#endif                                 /* RTW_HEADER_SimpleStim_cal_h_ */
