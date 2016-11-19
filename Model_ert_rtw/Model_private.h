/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Model_private.h
 *
 * Code generated for Simulink model 'Model'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Nov 03 18:58:23 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Model_private_h_
#define RTW_HEADER_Model_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Model.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern real_T rt_roundd_snf(real_T u);

#include "API.h"
#include "API.h"

extern void motorSet(unsigned char ucMotor, int iSpeed);

#include "API.h"

extern void Model_Chart_Init(rtB_Chart_Model *localB, rtDW_Chart_Model *localDW);
extern void Model_Chart(real_T rtu_trigger, rtB_Chart_Model *localB,
  rtDW_Chart_Model *localDW, rtP_Chart_Model *localP);

#endif                                 /* RTW_HEADER_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
