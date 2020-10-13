#include "__cf_motorcycle_model.h"
#ifndef RTW_HEADER_motorcycle_model_h_
#define RTW_HEADER_motorcycle_model_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef motorcycle_model_COMMON_INCLUDES_
#define motorcycle_model_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "motorcycle_model_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME motorcycle_model
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (15) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (52)   
#elif NCSTATES != 52
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T cp0ppvbbhm ; real_T f2bv4a4pox [ 13 ] ; real_T
jrd3qvs43k [ 13 ] ; real_T eo520ybntx [ 13 ] ; real_T c2cdlswd3o ; real_T
g1ydvsawaf ; real_T gzzkcchteh ; real_T jouoe1n5vx ; real_T av1aqzwqnf ;
real_T ar1tujojgx ; real_T erdq10rudk ; real_T oqfsbxli0j ; real_T ccaozxlshh
[ 3 ] ; real_T ff31rlfzs2 [ 3 ] ; real_T imnuhe3fbk [ 26 ] ; } B ; typedef
struct { struct { void * LoggedData ; } grwaeg41qx ; struct { void *
LoggedData ; } f5sktb3hgq ; struct { void * LoggedData [ 3 ] ; } efplwo0pid ;
struct { void * LoggedData [ 3 ] ; } e3gu0dxj4t ; struct { void * LoggedData
[ 4 ] ; } bxabf4r0a3 ; struct { void * LoggedData [ 3 ] ; } e51vgoqur1 ;
struct { void * LoggedData [ 3 ] ; } eqeprrxi0m ; struct { void * LoggedData
[ 3 ] ; } fspah5020b ; struct { void * LoggedData [ 4 ] ; } pq5qqhpmts ;
struct { void * LoggedData [ 3 ] ; } c4i2ya1w2k ; struct { void * TimePtr ;
void * DataPtr ; void * RSimInfoPtr ; } pncnv031ra ; struct { void * TimePtr
; void * DataPtr ; void * RSimInfoPtr ; } goekygpgcg ; struct { void *
LoggedData [ 4 ] ; } afelrz4ko4 ; struct { void * LoggedData [ 3 ] ; }
dbxx5o0sc3 ; struct { void * LoggedData [ 3 ] ; } ppgwajfcyg ; struct { void
* LoggedData [ 4 ] ; } khpvkydxgw ; struct { int_T PrevIndex ; } eu5q0vv44s ;
struct { int_T PrevIndex ; } dqax4j05oj ; boolean_T gj50vdt2d5 ; } DW ;
typedef struct { real_T me5fddqwzm [ 13 ] ; real_T oxmouqfknt [ 13 ] ; real_T
ebokkhvua4 [ 26 ] ; } X ; typedef struct { real_T me5fddqwzm [ 13 ] ; real_T
oxmouqfknt [ 13 ] ; real_T ebokkhvua4 [ 26 ] ; } XDot ; typedef struct {
boolean_T me5fddqwzm [ 13 ] ; boolean_T oxmouqfknt [ 13 ] ; boolean_T
ebokkhvua4 [ 26 ] ; } XDis ; typedef struct { real_T me5fddqwzm [ 13 ] ;
real_T oxmouqfknt [ 13 ] ; real_T ebokkhvua4 [ 26 ] ; } CStateAbsTol ;
typedef struct { real_T ghwxcapcay ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T tout [ 500
] ; real_T Integrator1_IC [ 13 ] ; real_T Integrator_IC [ 13 ] ; real_T
Constant_Value [ 62 ] ; real_T throttlebraketorqueinput_Time0 [ 500 ] ;
real_T throttlebraketorqueinput_Data0 [ 500 ] ; real_T steertorqueinput_Time0
[ 500 ] ; real_T steertorqueinput_Data0 [ 500 ] ; real_T Integrator2_IC [ 26
] ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ;
extern X rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * motorcycle_model_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
