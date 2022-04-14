#include "UECU_Speedgoat_threshold.h"

/* Storage class 'PageSwitching' */

/* Storage class 'PageSwitching' */
UECU_Speedgoat_thresho_cal_type UECU_Speedgoat_thresho_cal_impl = {
  /* Expression: 0:0.1:2
   * Referenced by: '<S6>/Constant1'
   */
  { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4, 0.5, 0.60000000000000009,
    0.70000000000000007, 0.8, 0.9, 1.0, 1.1, 1.2, 1.2999999999999998, 1.4, 1.5,
    1.6, 1.7, 1.8, 1.9, 2.0 },

  /* Expression: 2.2:0.2:5.6
   * Referenced by: '<S6>/Constant2'
   */
  { 2.2, 2.4000000000000004, 2.6, 2.8000000000000003, 3.0, 3.2,
    3.4000000000000004, 3.6000000000000005, 3.8000000000000003,
    3.9999999999999996, 4.1999999999999993, 4.3999999999999995, 4.6, 4.8, 5.0,
    5.1999999999999993, 5.3999999999999995, 5.6 },

  /* Expression: zeros(1,24)
   * Referenced by: '<Root>/snp_PA_in'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(1,24)
   * Referenced by: '<Root>/snp_PA Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/trial_delay_in'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/trial_stop_in'
   */
  10.0,

  /* Expression: 5.6
   * Referenced by: '<Root>/HighPALim Memory'
   */
  5.6,

  /* Expression: 0
   * Referenced by: '<Root>/LowPALim Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/trial_delay Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/trial_stop Memory'
   */
  0.0,

  /* Computed Parameter: Constant2_Value_n
   * Referenced by: '<S1>/Constant2'
   */
  200U,

  /* Computed Parameter: snp_IPI_in_Value
   * Referenced by: '<Root>/snp_IPI_in'
   */
  50U,

  /* Computed Parameter: snp_IPIMemory_InitialValue
   * Referenced by: '<Root>/snp_IPI Memory'
   */
  0U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S6>/Constant3'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U,
    17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U,
    32U, 33U, 34U, 35U, 36U, 37U, 38U },

  /* Computed Parameter: snp_PW_in_Value
   * Referenced by: '<Root>/snp_PW_in'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: snp_PWMemory_InitialValue
   * Referenced by: '<Root>/snp_PW Memory'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  60U,

  /* Computed Parameter: Constant1_Value_l
   * Referenced by: '<S1>/Constant1'
   */
  255U,

  /* Computed Parameter: HighPWLimMemory_InitialValue
   * Referenced by: '<Root>/HighPWLim Memory'
   */
  255U,

  /* Computed Parameter: LowPWLimMemory_InitialValue
   * Referenced by: '<Root>/LowPWLim Memory'
   */
  0U,

  /* Computed Parameter: snp_CH_in_Value
   * Referenced by: '<Root>/snp_CH_in'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Computed Parameter: snp_CHMemory_InitialValue
   * Referenced by: '<Root>/snp_CH Memory'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Computed Parameter: EnableBeep_Value
   * Referenced by: '<Root>/Enable Beep'
   */
  1
};

UECU_Speedgoat_thresho_cal_type *UECU_Speedgoat_threshold_cal =
  &UECU_Speedgoat_thresho_cal_impl;
