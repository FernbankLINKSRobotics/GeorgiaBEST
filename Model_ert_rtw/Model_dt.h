/*
 * Model_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Model".
 *
 * Model version              : 1.15
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Nov 03 18:58:23 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Model_B.DataTypeConversion1), 0, 0, 5 },

  { (char_T *)(&Model_B.DataTypeConversion), 6, 0, 8 },

  { (char_T *)(&Model_B.sfun_JoystickDigital), 8, 0, 6 },

  { (char_T *)(&Model_B.sf_Chart_l.output), 0, 0, 1 },

  { (char_T *)(&Model_B.sf_Chart_i.output), 0, 0, 1 },

  { (char_T *)(&Model_B.sf_Chart.output), 0, 0, 1 }
  ,

  { (char_T *)(&Model_DWork.sf_Chart_l.sfEvent), 6, 0, 1 },

  { (char_T *)(&Model_DWork.sf_Chart_l.is_active_c7_vexarmcortexlib), 3, 0, 2 },

  { (char_T *)(&Model_DWork.sf_Chart_i.sfEvent), 6, 0, 1 },

  { (char_T *)(&Model_DWork.sf_Chart_i.is_active_c7_vexarmcortexlib), 3, 0, 2 },

  { (char_T *)(&Model_DWork.sf_Chart.sfEvent), 6, 0, 1 },

  { (char_T *)(&Model_DWork.sf_Chart.is_active_c7_vexarmcortexlib), 3, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Model_P.Constant1_Value), 0, 0, 31 },

  { (char_T *)(&Model_P.sf_Chart_l.Chart_output0), 0, 0, 1 },

  { (char_T *)(&Model_P.sf_Chart_i.Chart_output0), 0, 0, 1 },

  { (char_T *)(&Model_P.sf_Chart.Chart_output0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] Model_dt.h */
