/* Include files */

#include "vexarmcortexlib_sfun.h"
#include "c7_vexarmcortexlib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "vexarmcortexlib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c7_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c7_IN_init                     ((uint8_T)1U)
#define c7_IN_wait                     ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void initialize_params_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance);
static void enable_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void disable_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void c7_update_debugger_state_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance);
static void ext_mode_exec_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance);
static void set_sim_state_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct *
  chartInstance, const mxArray *c7_st);
static void c7_set_sim_state_side_effects_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance);
static void finalize_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void sf_gateway_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void mdl_start_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void initSimStructsc7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static int32_T c7_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_b_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_b_output, const char_T *c7_identifier);
static real_T c7_c_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_d_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_vexarmcortexlib, const char_T
  *c7_identifier);
static uint8_T c7_e_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static const mxArray *c7_f_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_b_setSimStateSideEffectsInfo, const char_T
  *c7_identifier);
static const mxArray *c7_g_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance, int32_T c7_ssid);
static void c7_init_sf_message_store_memory(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc7_vexarmcortexlib(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  *chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_doSetSimStateSideEffects = 0U;
  chartInstance->c7_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c7_is_active_c7_vexarmcortexlib = 0U;
  *chartInstance->c7_is_c7_vexarmcortexlib = c7_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c7_output = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c7_output, 1U, 1U, 0U,
                          *chartInstance->c7_sfEvent, false);
  }
}

static void initialize_params_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance)
{
  real_T c7_d0;
  sf_mex_import_named("output0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c7_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_output0 = c7_d0;
}

static void enable_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance)
{
  uint32_T c7_prevAniVal;
  c7_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c7_is_active_c7_vexarmcortexlib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_c7_vexarmcortexlib == c7_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_c7_vexarmcortexlib == c7_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
  }

  _SFD_SET_ANIMATION(c7_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct *
  chartInstance)
{
  c7_update_debugger_state_c7_vexarmcortexlib(chartInstance);
}

static const mxArray *get_sim_state_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  uint8_T c7_c_hoistedGlobal;
  uint8_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(3, 1), false);
  c7_hoistedGlobal = *chartInstance->c7_output;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *chartInstance->c7_is_active_c7_vexarmcortexlib;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *chartInstance->c7_is_c7_vexarmcortexlib;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct *
  chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  c7_u = sf_mex_dup(c7_st);
  *chartInstance->c7_output = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("output", c7_u, 0)), "output");
  *chartInstance->c7_is_active_c7_vexarmcortexlib = c7_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c7_vexarmcortexlib",
       c7_u, 1)), "is_active_c7_vexarmcortexlib");
  *chartInstance->c7_is_c7_vexarmcortexlib = c7_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c7_vexarmcortexlib", c7_u, 2)),
    "is_c7_vexarmcortexlib");
  sf_mex_assign(&chartInstance->c7_setSimStateSideEffectsInfo,
                c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c7_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c7_u);
  chartInstance->c7_doSetSimStateSideEffects = 1U;
  c7_update_debugger_state_c7_vexarmcortexlib(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void c7_set_sim_state_side_effects_c7_vexarmcortexlib
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance)
{
  if (chartInstance->c7_doSetSimStateSideEffects != 0) {
    chartInstance->c7_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c7_setSimStateSideEffectsInfo);
}

static void sf_gateway_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  boolean_T c7_out;
  boolean_T c7_b_out;
  c7_set_sim_state_side_effects_c7_vexarmcortexlib(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_trigger, 0U, 1U, 0U,
                        *chartInstance->c7_sfEvent, false);
  *chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c7_sfEvent);
  if (*chartInstance->c7_is_active_c7_vexarmcortexlib == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_is_active_c7_vexarmcortexlib = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c7_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_output = chartInstance->c7_output0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c7_output, 1U, 5U, 0U,
                          *chartInstance->c7_sfEvent, false);
    *chartInstance->c7_is_c7_vexarmcortexlib = c7_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
  } else {
    switch (*chartInstance->c7_is_c7_vexarmcortexlib) {
     case c7_IN_init:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c7_sfEvent);
      c7_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
                  CV_RELATIONAL_EVAL(5U, 1U, 0, *chartInstance->c7_trigger, 0.0,
        -1, 1U, *chartInstance->c7_trigger != 0.0) != 0U,
                  *chartInstance->c7_sfEvent)) != 0);
      if (c7_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_output = (real_T)!(*chartInstance->c7_output != 0.0);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_output, 1U, 5U, 1U,
                              *chartInstance->c7_sfEvent, false);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_c7_vexarmcortexlib = c7_IN_wait;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     *chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c7_sfEvent);
      break;

     case c7_IN_wait:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c7_sfEvent);
      c7_b_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
        CV_RELATIONAL_EVAL(5U, 2U, 0, *chartInstance->c7_trigger, 0.0, -1, 0U,
                           *chartInstance->c7_trigger == 0.0) != 0U,
        *chartInstance->c7_sfEvent)) != 0);
      if (c7_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_c7_vexarmcortexlib = c7_IN_init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     *chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c7_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c7_is_c7_vexarmcortexlib = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_vexarmcortexlibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  c7_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc7_vexarmcortexlib(SFc7_vexarmcortexlibInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

const mxArray *sf_c7_vexarmcortexlib_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_vexarmcortexlibInstanceStruct *chartInstance;
  chartInstance = (SFc7_vexarmcortexlibInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i0, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_vexarmcortexlibInstanceStruct *chartInstance;
  chartInstance = (SFc7_vexarmcortexlibInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent), &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_vexarmcortexlibInstanceStruct *chartInstance;
  chartInstance = (SFc7_vexarmcortexlibInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_b_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_b_output, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_output),
    &c7_thisId);
  sf_mex_destroy(&c7_b_output);
  return c7_y;
}

static real_T c7_c_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d1;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d1, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_output;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_vexarmcortexlibInstanceStruct *chartInstance;
  chartInstance = (SFc7_vexarmcortexlibInstanceStruct *)chartInstanceVoid;
  c7_b_output = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_output),
    &c7_thisId);
  sf_mex_destroy(&c7_b_output);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_vexarmcortexlib, const char_T
  *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_vexarmcortexlib), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_vexarmcortexlib);
  return c7_y;
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static const mxArray *c7_f_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_b_setSimStateSideEffectsInfo, const char_T
  *c7_identifier)
{
  const mxArray *c7_y = NULL;
  emlrtMsgIdentifier c7_thisId;
  c7_y = NULL;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  sf_mex_assign(&c7_y, c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_setSimStateSideEffectsInfo), &c7_thisId), false);
  sf_mex_destroy(&c7_b_setSimStateSideEffectsInfo);
  return c7_y;
}

static const mxArray *c7_g_emlrt_marshallIn(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  const mxArray *c7_y = NULL;
  (void)chartInstance;
  (void)c7_parentId;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_duplicatearraysafe(&c7_u), false);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc7_vexarmcortexlibInstanceStruct *chartInstance, int32_T c7_ssid)
{
  (void)chartInstance;
  (void)c7_ssid;
  return NULL;
}

static void c7_init_sf_message_store_memory(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_vexarmcortexlibInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c7_is_active_c7_vexarmcortexlib = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_is_c7_vexarmcortexlib = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_trigger = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_output = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c7_vexarmcortexlib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3768217174U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(864180567U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2584752546U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1834703835U);
}

mxArray* sf_c7_vexarmcortexlib_get_post_codegen_info(void);
mxArray *sf_c7_vexarmcortexlib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NlBJ7vhaiLukhkNgJn8duE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c7_vexarmcortexlib_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_vexarmcortexlib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_vexarmcortexlib_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("ext_mode");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c7_vexarmcortexlib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_vexarmcortexlib_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c7_vexarmcortexlib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"output\",},{M[8],M[0],T\"is_active_c7_vexarmcortexlib\",},{M[9],M[0],T\"is_c7_vexarmcortexlib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_vexarmcortexlib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc7_vexarmcortexlibInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_vexarmcortexlibInstanceStruct *chartInstance =
      (SFc7_vexarmcortexlibInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _vexarmcortexlibMachineNumber_,
           7,
           2,
           3,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_vexarmcortexlibMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_vexarmcortexlibMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _vexarmcortexlibMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"trigger");
          _SFD_SET_DATA_PROPS(1,2,0,1,"output");
          _SFD_SET_DATA_PROPS(2,10,0,0,"output0");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 11 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 11 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(2,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _vexarmcortexlibMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_vexarmcortexlibInstanceStruct *chartInstance =
      (SFc7_vexarmcortexlibInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c7_trigger);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c7_output);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c7_output0);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "skRnir5ngp6bj22onSjFGXF";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_vexarmcortexlib_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 7, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c7_vexarmcortexlib(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar);
  initialize_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_vexarmcortexlib(void *chartInstanceVar)
{
  enable_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_vexarmcortexlib(void *chartInstanceVar)
{
  disable_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_vexarmcortexlib(void *chartInstanceVar)
{
  sf_gateway_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c7_vexarmcortexlib(void *chartInstanceVar)
{
  ext_mode_exec_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_vexarmcortexlib(SimStruct* S)
{
  return get_sim_state_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_vexarmcortexlib(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c7_vexarmcortexlib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_vexarmcortexlibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_vexarmcortexlib_optimization_info();
    }

    finalize_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_vexarmcortexlib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_vexarmcortexlib((SFc7_vexarmcortexlibInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

mxArray *sf_c7_vexarmcortexlib_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c7_vexarmcortexlib\",T\"is_active_c7_vexarmcortexlib\"},{T\"is_c7_vexarmcortexlib\",T\"is_c7_vexarmcortexlib\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"int32\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3669324118U, 1617907009U, 85413298U,
    2233336200U };

  return checksum;
}

static void mdlSetWorkWidths_c7_vexarmcortexlib(SimStruct *S)
{
  /* Actual parameters from chart:
     output0
   */
  const char_T *rtParamNames[] = { "output0" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for output0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_vexarmcortexlib_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 7);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4116445319U));
  ssSetChecksum1(S,(1439647349U));
  ssSetChecksum2(S,(1052390166U));
  ssSetChecksum3(S,(951223070U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_vexarmcortexlib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c7_vexarmcortexlib(SimStruct *S)
{
  SFc7_vexarmcortexlibInstanceStruct *chartInstance;
  chartInstance = (SFc7_vexarmcortexlibInstanceStruct *)utMalloc(sizeof
    (SFc7_vexarmcortexlibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_vexarmcortexlibInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_vexarmcortexlib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_vexarmcortexlib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_vexarmcortexlib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_vexarmcortexlib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_vexarmcortexlib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_vexarmcortexlib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_vexarmcortexlib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_vexarmcortexlib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_vexarmcortexlib;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_vexarmcortexlib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_vexarmcortexlib;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c7_vexarmcortexlib;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c7_vexarmcortexlib(chartInstance);
}

void c7_vexarmcortexlib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_vexarmcortexlib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_vexarmcortexlib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_vexarmcortexlib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_vexarmcortexlib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
