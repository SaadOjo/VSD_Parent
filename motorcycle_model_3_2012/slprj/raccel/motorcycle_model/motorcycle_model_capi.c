#include "__cf_motorcycle_model.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "motorcycle_model_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "motorcycle_model.h"
#include "motorcycle_model_capi.h"
#include "motorcycle_model_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"motorcycle_model/Clock" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 1 , TARGET_STRING ( "motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 2 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"Flr" ) , 3 , 0 , 0 , 0 , 0 } , { 3 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"Ftr" ) , 4 , 0 , 0 , 0 , 0 } , { 4 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"Flf" ) , 5 , 0 , 0 , 0 , 0 } , { 5 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"Ftf" ) , 6 , 0 , 0 , 0 , 0 } , { 6 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"vlr" ) , 7 , 0 , 0 , 0 , 0 } , { 7 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"vtr" ) , 8 , 0 , 0 , 0 , 0 } , { 8 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"vlf" ) , 9 , 0 , 0 , 0 , 0 } , { 9 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING (
"vtf" ) , 10 , 0 , 0 , 0 , 0 } , { 10 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING ( ""
) , 11 , 0 , 2 , 0 , 0 } , { 11 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING ( ""
) , 12 , 0 , 2 , 0 , 0 } , { 12 , 1 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/M\\(Q-Cq)" ) , TARGET_STRING ( ""
) , 14 , 0 , 3 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/Integrator" ) , TARGET_STRING (
"qd" ) , 0 , 0 , 1 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/Integrator1" ) , TARGET_STRING (
"q" ) , 0 , 0 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 ,
0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 15 ,
TARGET_STRING ( "motorcycle_model/steer torque input" ) , TARGET_STRING (
"Time0" ) , 0 , 4 , 0 } , { 16 , TARGET_STRING (
"motorcycle_model/steer torque input" ) , TARGET_STRING ( "Data0" ) , 0 , 4 ,
0 } , { 17 , TARGET_STRING ( "motorcycle_model/throttle//brake torque input"
) , TARGET_STRING ( "Time0" ) , 0 , 4 , 0 } , { 18 , TARGET_STRING (
"motorcycle_model/throttle//brake torque input" ) , TARGET_STRING ( "Data0" )
, 0 , 4 , 0 } , { 19 , TARGET_STRING ( "motorcycle_model/Subsystem/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 20 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 21 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 22 , TARGET_STRING (
"motorcycle_model/Subsystem/simulink model/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 7 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 }
} ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 23 ,
TARGET_STRING ( "tout" ) , 0 , 4 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . cp0ppvbbhm , & rtB . eo520ybntx [
0 ] , & rtB . c2cdlswd3o , & rtB . g1ydvsawaf , & rtB . gzzkcchteh , & rtB .
jouoe1n5vx , & rtB . av1aqzwqnf , & rtB . ar1tujojgx , & rtB . erdq10rudk , &
rtB . oqfsbxli0j , & rtB . ccaozxlshh [ 0 ] , & rtB . ff31rlfzs2 [ 0 ] , &
rtB . imnuhe3fbk [ 0 ] , & rtB . jrd3qvs43k [ 0 ] , & rtB . f2bv4a4pox [ 0 ]
, & rtP . steertorqueinput_Time0 [ 0 ] , & rtP . steertorqueinput_Data0 [ 0 ]
, & rtP . throttlebraketorqueinput_Time0 [ 0 ] , & rtP .
throttlebraketorqueinput_Data0 [ 0 ] , & rtP . Constant_Value [ 0 ] , & rtP .
Integrator_IC [ 0 ] , & rtP . Integrator1_IC [ 0 ] , & rtP . Integrator2_IC [
0 ] , & rtP . tout [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { (
NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 13 , 1 , 3 , 1 , 26 , 1 , 500 ,
1 , 62 , 1 , 1 , 13 , 1 , 26 } ; static const real_T rtcapiStoredFloats [ ] =
{ 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 0 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 15 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 8 ,
rtModelParameters , 1 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2747836835U , 2016987222U , 2843745027U , 3167016773U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo *
motorcycle_model_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void motorcycle_model_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( (
* rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void motorcycle_model_host_InitializeDataMapInfo (
motorcycle_model_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
