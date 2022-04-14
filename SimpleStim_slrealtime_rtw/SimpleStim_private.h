/*
 * SimpleStim_private.h
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

#ifndef RTW_HEADER_SimpleStim_private_h_
#define RTW_HEADER_SimpleStim_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "SimpleStim.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#define NUM_SID                        2
#define NUM_SYNC                       1

extern u_char sid[NUM_SID];
extern u_char syncsig[NUM_SYNC];
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi);
void LookUp_U8_real_T(uint8_T *pY, const uint8_T *pYData, real_T u, const real_T
                      *pUData, uint32_T iHi);
extern void SimpleStim_set_delays(const uint8_T rtu_PW[12], const uint8_T
  rtu_PA[12], B_set_delays_SimpleStim_T *localB);

#endif                                 /* RTW_HEADER_SimpleStim_private_h_ */
