#ifndef __c4_data_h__
#define __c4_data_h__
#ifdef __has_include
#if __has_include(<time.h>)
#include <time.h>
#else
#error Cannot find header file <time.h> for imported type time_t.\
 Supply the missing header file or turn on Simulation Target -> Generate typedefs\
 for imported bus and enumeration types.
#endif

#else
#include <time.h>
#endif

/* Forward Declarations */
#ifndef typedef_c4_sxaDueAh1f53T9ESYg9Uc4E
#define typedef_c4_sxaDueAh1f53T9ESYg9Uc4E

typedef struct c4_tag_sxaDueAh1f53T9ESYg9Uc4E c4_sxaDueAh1f53T9ESYg9Uc4E;

#endif                                 /* typedef_c4_sxaDueAh1f53T9ESYg9Uc4E */

#ifndef typedef_c4_cell_0
#define typedef_c4_cell_0

typedef struct c4_tag_n3SDPft8LycMqfcEsfJVBB c4_cell_0;

#endif                                 /* typedef_c4_cell_0 */

#ifndef typedef_c4_s_wvzWMLKjXp7EJVnnMvwbTC
#define typedef_c4_s_wvzWMLKjXp7EJVnnMvwbTC

typedef struct c4_tag_wvzWMLKjXp7EJVnnMvwbTC c4_s_wvzWMLKjXp7EJVnnMvwbTC;

#endif                                 /* typedef_c4_s_wvzWMLKjXp7EJVnnMvwbTC */

/* Type Definitions */
#ifndef struct_c4_tag_sxaDueAh1f53T9ESYg9Uc4E
#define struct_c4_tag_sxaDueAh1f53T9ESYg9Uc4E

struct c4_tag_sxaDueAh1f53T9ESYg9Uc4E
{
  real_T tm_min;
  real_T tm_sec;
  real_T tm_hour;
  real_T tm_mday;
  real_T tm_mon;
  real_T tm_year;
};

#endif                                 /* struct_c4_tag_sxaDueAh1f53T9ESYg9Uc4E */

#ifndef typedef_c4_sxaDueAh1f53T9ESYg9Uc4E
#define typedef_c4_sxaDueAh1f53T9ESYg9Uc4E

typedef struct c4_tag_sxaDueAh1f53T9ESYg9Uc4E c4_sxaDueAh1f53T9ESYg9Uc4E;

#endif                                 /* typedef_c4_sxaDueAh1f53T9ESYg9Uc4E */

#ifndef struct_c4_tag_n3SDPft8LycMqfcEsfJVBB
#define struct_c4_tag_n3SDPft8LycMqfcEsfJVBB

struct c4_tag_n3SDPft8LycMqfcEsfJVBB
{
  char_T f1[6];
  char_T f2[6];
  char_T f3[7];
  char_T f4[7];
  char_T f5[6];
  char_T f6[7];
};

#endif                                 /* struct_c4_tag_n3SDPft8LycMqfcEsfJVBB */

#ifndef typedef_c4_cell_0
#define typedef_c4_cell_0

typedef struct c4_tag_n3SDPft8LycMqfcEsfJVBB c4_cell_0;

#endif                                 /* typedef_c4_cell_0 */

#ifndef struct_c4_tag_wvzWMLKjXp7EJVnnMvwbTC
#define struct_c4_tag_wvzWMLKjXp7EJVnnMvwbTC

struct c4_tag_wvzWMLKjXp7EJVnnMvwbTC
{
  c4_cell_0 _data;
};

#endif                                 /* struct_c4_tag_wvzWMLKjXp7EJVnnMvwbTC */

#ifndef typedef_c4_s_wvzWMLKjXp7EJVnnMvwbTC
#define typedef_c4_s_wvzWMLKjXp7EJVnnMvwbTC

typedef struct c4_tag_wvzWMLKjXp7EJVnnMvwbTC c4_s_wvzWMLKjXp7EJVnnMvwbTC;

#endif                                 /* typedef_c4_s_wvzWMLKjXp7EJVnnMvwbTC */

#ifndef typedef_SFc4_dataInstanceStruct
#define typedef_SFc4_dataInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_data;
  uint8_T c4_JITStateAnimation[1];
  uint8_T c4_JITTransitionAnimation[1];
  int32_T c4_IsDebuggerActive;
  int32_T c4_IsSequenceViewerPresent;
  int32_T c4_SequenceViewerOptimization;
  int32_T c4_IsHeatMapPresent;
  void *c4_RuntimeVar;
  uint32_T c4_seed;
  boolean_T c4_seed_not_empty;
  uint32_T c4_method;
  boolean_T c4_method_not_empty;
  uint32_T c4_state[625];
  boolean_T c4_state_not_empty;
  uint32_T c4_b_state[2];
  boolean_T c4_b_state_not_empty;
  uint32_T c4_c_state;
  boolean_T c4_c_state_not_empty;
  uint32_T c4_b_method;
  boolean_T c4_b_method_not_empty;
  uint32_T c4_d_state[2];
  boolean_T c4_d_state_not_empty;
  uint32_T c4_mlFcnLineNumber;
  void *c4_fcnDataPtrs[6];
  char_T *c4_dataNames[6];
  uint32_T c4_numFcnVars;
  uint32_T c4_ssIds[6];
  uint32_T c4_statuses[6];
  void *c4_outMexFcns[6];
  void *c4_inMexFcns[6];
  real_T (*c4_a_address)[70];
  int32_T c4__index;
  boolean_T c4_dsmdiag_a;
  real_T (*c4__indexb_address)[70];
  int32_T c4_b__index;
  boolean_T c4_dsmdiag_b;
  real_T (*c4__indexf_address)[70];
  int32_T c4_c__index;
  boolean_T c4_dsmdiag_f;
  CovrtStateflowInstance *c4_covrtInstance;
  void *c4_fEmlrtCtx;
  real_T *c4_t;
  real_T (*c4_q)[7];
  real_T (*c4_qd)[7];
  real_T (*c4_qdd)[7];
} SFc4_dataInstanceStruct;

#endif                                 /* typedef_SFc4_dataInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_data_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_data_get_check_sum(mxArray *plhs[]);
extern void c4_data_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
