#include "__cf_motorcycle_model.h"
#include "rt_logging_mmi.h"
#include "motorcycle_model_capi.h"
#include <math.h>
#include "motorcycle_model.h"
#include "motorcycle_model_private.h"
#include "motorcycle_model_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 2 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.2 (R2018b) 24-May-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\motorcycle_model\\motorcycle_model_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static void p0b5byzq3l ( const real_T a [ 9 ] , real_T y [ 9 ] )
; static void p0b5byzq3lx ( const real_T a [ 3 ] , real_T y [ 3 ] ) ; static
void fnncsruavj ( real_T x [ 169 ] ) ; static real_T k4sacqjg3c ( const
real_T x [ 3 ] ) ; static real_T aaaovno5g3 ( const real_T a [ 3 ] , const
real_T b [ 3 ] ) ; static void jk0otd1dqr ( const real_T a [ 3 ] , const
real_T b [ 3 ] , real_T c [ 3 ] ) ; static void jy5yzijuif ( real_T A [ 169 ]
, int32_T ipiv [ 13 ] , int32_T * info ) ; static void dqlqqdeg5m ( const
real_T A [ 169 ] , real_T B_p [ 13 ] ) ; static void p0b5byzq3l ( const
real_T a [ 9 ] , real_T y [ 9 ] ) { int32_T k ; for ( k = 0 ; k < 9 ; k ++ )
{ y [ k ] = a [ k ] * a [ k ] ; } } static void p0b5byzq3lx ( const real_T a
[ 3 ] , real_T y [ 3 ] ) { y [ 0 ] = a [ 0 ] * a [ 0 ] ; y [ 1 ] = a [ 1 ] *
a [ 1 ] ; y [ 2 ] = a [ 2 ] * a [ 2 ] ; } static void fnncsruavj ( real_T x [
169 ] ) { int32_T istart ; int32_T j ; int32_T i ; istart = 1 ; for ( j = 0 ;
j < 13 ; j ++ ) { for ( i = istart ; i < 14 ; i ++ ) { x [ ( i + 13 * j ) - 1
] = 0.0 ; } istart ++ ; } } static real_T k4sacqjg3c ( const real_T x [ 3 ] )
{ real_T y ; real_T scale ; real_T absxk ; real_T t ; scale =
3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( x [ 0 ] ) ; if ( absxk
> 3.3121686421112381E-170 ) { y = 1.0 ; scale = absxk ; } else { t = absxk /
3.3121686421112381E-170 ; y = t * t ; } absxk = muDoubleScalarAbs ( x [ 1 ] )
; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0 ; scale =
absxk ; } else { t = absxk / scale ; y += t * t ; } absxk = muDoubleScalarAbs
( x [ 2 ] ) ; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0
; scale = absxk ; } else { t = absxk / scale ; y += t * t ; } return scale *
muDoubleScalarSqrt ( y ) ; } static real_T aaaovno5g3 ( const real_T a [ 3 ]
, const real_T b [ 3 ] ) { return ( a [ 0 ] * b [ 0 ] + a [ 1 ] * b [ 1 ] ) +
a [ 2 ] * b [ 2 ] ; } static void jk0otd1dqr ( const real_T a [ 3 ] , const
real_T b [ 3 ] , real_T c [ 3 ] ) { c [ 0 ] = a [ 1 ] * b [ 2 ] - a [ 2 ] * b
[ 1 ] ; c [ 1 ] = a [ 2 ] * b [ 0 ] - a [ 0 ] * b [ 2 ] ; c [ 2 ] = a [ 0 ] *
b [ 1 ] - a [ 1 ] * b [ 0 ] ; } static void jy5yzijuif ( real_T A [ 169 ] ,
int32_T ipiv [ 13 ] , int32_T * info ) { int32_T j ; int32_T c ; int32_T ix ;
real_T smax ; real_T s ; int32_T k ; int32_T iy ; int32_T c_ix ; int32_T d ;
int32_T ijA ; for ( j = 0 ; j < 13 ; j ++ ) { ipiv [ j ] = 1 + j ; } * info =
0 ; for ( j = 0 ; j < 12 ; j ++ ) { c = j * 14 ; iy = 0 ; ix = c ; smax =
muDoubleScalarAbs ( A [ c ] ) ; for ( k = 2 ; k <= 13 - j ; k ++ ) { ix ++ ;
s = muDoubleScalarAbs ( A [ ix ] ) ; if ( s > smax ) { iy = k - 1 ; smax = s
; } } if ( A [ c + iy ] != 0.0 ) { if ( iy != 0 ) { ipiv [ j ] = ( j + iy ) +
1 ; ix = j ; iy += j ; for ( k = 0 ; k < 13 ; k ++ ) { smax = A [ ix ] ; A [
ix ] = A [ iy ] ; A [ iy ] = smax ; ix += 13 ; iy += 13 ; } } iy = ( c - j )
+ 13 ; for ( ix = c + 1 ; ix < iy ; ix ++ ) { A [ ix ] /= A [ c ] ; } } else
{ * info = j + 1 ; } iy = c ; ix = c + 13 ; for ( k = 0 ; k <= 11 - j ; k ++
) { if ( A [ ix ] != 0.0 ) { smax = - A [ ix ] ; c_ix = c + 1 ; d = ( iy - j
) + 26 ; for ( ijA = 14 + iy ; ijA < d ; ijA ++ ) { A [ ijA ] += A [ c_ix ] *
smax ; c_ix ++ ; } } ix += 13 ; iy += 13 ; } } if ( ( * info == 0 ) && ( ! (
A [ 168 ] != 0.0 ) ) ) { * info = 13 ; } } static void dqlqqdeg5m ( const
real_T A [ 169 ] , real_T B_p [ 13 ] ) { real_T temp ; real_T b_A [ 169 ] ;
int32_T ipiv [ 13 ] ; int32_T info ; int32_T kAcol ; int32_T i ; memcpy ( &
b_A [ 0 ] , & A [ 0 ] , 169U * sizeof ( real_T ) ) ; jy5yzijuif ( b_A , ipiv
, & info ) ; for ( info = 0 ; info < 12 ; info ++ ) { if ( info + 1 != ipiv [
info ] ) { temp = B_p [ info ] ; B_p [ info ] = B_p [ ipiv [ info ] - 1 ] ;
B_p [ ipiv [ info ] - 1 ] = temp ; } } for ( info = 0 ; info < 13 ; info ++ )
{ kAcol = 13 * info ; if ( B_p [ info ] != 0.0 ) { for ( i = info + 1 ; i + 1
< 14 ; i ++ ) { B_p [ i ] -= b_A [ i + kAcol ] * B_p [ info ] ; } } } for (
info = 12 ; info >= 0 ; info -- ) { kAcol = 13 * info ; if ( B_p [ info ] !=
0.0 ) { B_p [ info ] /= b_A [ info + kAcol ] ; for ( i = 0 ; i < info ; i ++
) { B_p [ i ] -= b_A [ i + kAcol ] * B_p [ info ] ; } } } } void
MdlInitialize ( void ) { memcpy ( & rtX . me5fddqwzm [ 0 ] , & rtP .
Integrator1_IC [ 0 ] , 13U * sizeof ( real_T ) ) ; memcpy ( & rtX .
oxmouqfknt [ 0 ] , & rtP . Integrator_IC [ 0 ] , 13U * sizeof ( real_T ) ) ;
memcpy ( & rtX . ebokkhvua4 [ 0 ] , & rtP . Integrator2_IC [ 0 ] , 26U *
sizeof ( real_T ) ) ; } void MdlStart ( void ) { { void * * slioCatalogueAddr
= rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { int_T dimensions [ 1 ] = { 13 } ;
rtDW . grwaeg41qx . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "q" , SS_DOUBLE , 0 , 0 , 0 , 13 , 1 , dimensions , NO_LOGVALDIMS , (
NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW . grwaeg41qx . LoggedData
== ( NULL ) ) return ; } { int_T dimensions [ 1 ] = { 13 } ; rtDW .
f5sktb3hgq . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "qd" , SS_DOUBLE , 0 , 0 , 0 , 13 , 1 , dimensions , NO_LOGVALDIMS , (
NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW . f5sktb3hgq . LoggedData
== ( NULL ) ) return ; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = (
FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) {
ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "[tout u(:,1)]" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . throttlebraketorqueinput_Data0 ; fromwksInfo ->
nDataPoints = 500 ; fromwksInfo -> time = ( double * ) rtP .
throttlebraketorqueinput_Time0 ; rtDW . pncnv031ra . TimePtr = fromwksInfo ->
time ; rtDW . pncnv031ra . DataPtr = fromwksInfo -> data ; rtDW . pncnv031ra
. RSimInfoPtr = fromwksInfo ; } rtDW . eu5q0vv44s . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "[tout u(:,2)]" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . steertorqueinput_Data0 ; fromwksInfo ->
nDataPoints = 500 ; fromwksInfo -> time = ( double * ) rtP .
steertorqueinput_Time0 ; rtDW . goekygpgcg . TimePtr = fromwksInfo -> time ;
rtDW . goekygpgcg . DataPtr = fromwksInfo -> data ; rtDW . goekygpgcg .
RSimInfoPtr = fromwksInfo ; } rtDW . dqax4j05oj . PrevIndex = 0 ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T hwel15ulxt ;
real_T a3ncz0odn1 ; real_T s0 ; real_T c0 ; real_T s1 ; real_T c1 ; real_T s2
; real_T c2 ; real_T s4 ; real_T c4 ; real_T s5 ; real_T c5 ; real_T s6 ;
real_T c6 ; real_T s7 ; real_T c7 ; real_T R0 [ 9 ] ; real_T R1 [ 9 ] ;
real_T R2 [ 9 ] ; real_T R4 [ 9 ] ; real_T R5 [ 9 ] ; real_T R6 [ 9 ] ;
real_T R7 [ 9 ] ; real_T sa ; real_T sb ; real_T sc ; real_T sd ; real_T se ;
real_T sf ; real_T sg ; real_T si ; real_T sj ; real_T sk ; real_T sm ;
real_T sn ; real_T so ; real_T sp ; real_T M [ 169 ] ; real_T v1 [ 3 ] ;
real_T v2 [ 3 ] ; real_T c_a ; real_T d_a ; real_T g_a ; real_T q_a ; static
const int8_T b_b [ 169 ] = { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
1 } ; static const int8_T c_b [ 3 ] = { 0 , 0 , 1 } ; static const int8_T
bb_a [ 3 ] = { 1 , 1 , 0 } ; real_T f [ 169 ] ; int32_T i ; real_T v1_p [ 3 ]
; real_T R2_p [ 3 ] ; real_T s0_p [ 9 ] ; real_T R1_p [ 3 ] ; real_T R2_e [ 3
] ; real_T s2_p [ 9 ] ; real_T R6_p [ 3 ] ; real_T R5_p [ 3 ] ; real_T R6_e [
3 ] ; real_T s6_p [ 9 ] ; real_T s7_p [ 9 ] ; real_T s7_e [ 3 ] ; real_T R1_e
[ 3 ] ; real_T s0_e [ 3 ] ; real_T R0_p [ 3 ] ; real_T R0_e [ 3 ] ; real_T
s4_p [ 3 ] ; real_T R4_p [ 3 ] ; real_T R4_e [ 3 ] ; real_T R0_i [ 3 ] ;
real_T M_p [ 169 ] ; real_T tmp [ 13 ] ; real_T tmp_p [ 13 ] ; real_T tmp_e [
13 ] ; real_T tmp_i [ 13 ] ; real_T tmp_m [ 13 ] ; real_T tmp_g [ 13 ] ;
real_T tmp_j [ 13 ] ; real_T s4_e [ 13 ] ; real_T c4_p [ 13 ] ; real_T c0_p [
13 ] ; real_T s0_i [ 13 ] ; real_T tmp_f [ 13 ] ; real_T tmp_c [ 13 ] ;
int32_T i_p ; real_T R0_m ; real_T hxhenfzed1_idx_0 ; real_T hxhenfzed1_idx_1
; real_T s_idx_33 ; real_T s_idx_0 ; real_T s_idx_1 ; real_T s_idx_2 ; real_T
s_idx_3 ; real_T s_idx_4 ; real_T s_idx_5 ; real_T s_idx_6 ; real_T s_idx_7 ;
real_T s_idx_8 ; real_T s_idx_11 ; real_T s_idx_12 ; real_T s_idx_13 ; real_T
s_idx_14 ; real_T s_idx_15 ; real_T s_idx_16 ; real_T s_idx_18 ; real_T
s_idx_19 ; real_T s_idx_20 ; real_T s_idx_21 ; real_T s_idx_22 ; real_T
s_idx_23 ; real_T s_idx_24 ; real_T s_idx_25 ; real_T s_idx_26 ; real_T
s_idx_27 ; real_T s_idx_30 ; real_T s_idx_31 ; real_T s_idx_32 ; real_T
r0d_idx_0 ; real_T r0d_idx_1 ; real_T r7d_idx_0 ; real_T r7d_idx_1 ; real_T
T1_idx_2 ; real_T T1_idx_0 ; real_T T1_idx_1 ; real_T T3_idx_2 ; real_T
T3_idx_0 ; real_T T3_idx_1 ; rtB . cp0ppvbbhm = ssGetT ( rtS ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
gj50vdt2d5 = ( rtB . cp0ppvbbhm >= rtP . tout [ 499 ] ) ; } if ( rtDW .
gj50vdt2d5 ) { ssSetStopRequested ( rtS , 1 ) ; } } memcpy ( & rtB .
f2bv4a4pox [ 0 ] , & rtX . me5fddqwzm [ 0 ] , 13U * sizeof ( real_T ) ) ; if
( ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS )
-> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . grwaeg41qx . LoggedData ) , & rtB . f2bv4a4pox [ 0 ] , 0
) ; } } } memcpy ( & rtB . jrd3qvs43k [ 0 ] , & rtX . oxmouqfknt [ 0 ] , 13U
* sizeof ( real_T ) ) ; if ( ssGetLogOutput ( rtS ) ) { { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . f5sktb3hgq
. LoggedData ) , & rtB . jrd3qvs43k [ 0 ] , 0 ) ; } } } { real_T *
pDataValues = ( real_T * ) rtDW . pncnv031ra . DataPtr ; real_T * pTimeValues
= ( real_T * ) rtDW . pncnv031ra . TimePtr ; int_T currTimeIndex = rtDW .
eu5q0vv44s . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >=
pTimeValues [ 499 ] ) { hwel15ulxt = pDataValues [ 499 ] ; } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
pncnv031ra . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . eu5q0vv44s .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { hwel15ulxt = pDataValues [ currTimeIndex ] ; } else { hwel15ulxt =
pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2
- t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; hwel15ulxt = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } } { real_T * pDataValues = ( real_T * ) rtDW
. goekygpgcg . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
goekygpgcg . TimePtr ; int_T currTimeIndex = rtDW . dqax4j05oj . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 499 ] ) {
a3ncz0odn1 = pDataValues [ 499 ] ; } else { int numPoints , lastPoint ;
FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . goekygpgcg . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . dqax4j05oj . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { a3ncz0odn1 =
pDataValues [ currTimeIndex ] ; } else { a3ncz0odn1 = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; a3ncz0odn1 = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } } s0 = muDoubleScalarSin ( rtX . ebokkhvua4
[ 16 ] ) ; c0 = muDoubleScalarCos ( rtX . ebokkhvua4 [ 16 ] ) ; s1 =
muDoubleScalarSin ( rtX . ebokkhvua4 [ 17 ] ) ; c1 = muDoubleScalarCos ( rtX
. ebokkhvua4 [ 17 ] ) ; s2 = muDoubleScalarSin ( rtX . ebokkhvua4 [ 18 ] ) ;
c2 = muDoubleScalarCos ( rtX . ebokkhvua4 [ 18 ] ) ; s4 = muDoubleScalarSin (
rtX . ebokkhvua4 [ 19 ] ) ; c4 = muDoubleScalarCos ( rtX . ebokkhvua4 [ 19 ]
) ; s5 = muDoubleScalarSin ( rtX . ebokkhvua4 [ 20 ] ) ; c5 =
muDoubleScalarCos ( rtX . ebokkhvua4 [ 20 ] ) ; s6 = muDoubleScalarSin ( rtX
. ebokkhvua4 [ 21 ] ) ; c6 = muDoubleScalarCos ( rtX . ebokkhvua4 [ 21 ] ) ;
s7 = muDoubleScalarSin ( rtX . ebokkhvua4 [ 22 ] ) ; c7 = muDoubleScalarCos (
rtX . ebokkhvua4 [ 22 ] ) ; R0 [ 0 ] = c0 ; R0 [ 3 ] = - s0 ; R0 [ 6 ] = 0.0
; R0 [ 1 ] = s0 ; R0 [ 4 ] = c0 ; R0 [ 7 ] = 0.0 ; R1 [ 1 ] = 0.0 ; R1 [ 4 ]
= c1 ; R1 [ 7 ] = - s1 ; R1 [ 2 ] = 0.0 ; R1 [ 5 ] = s1 ; R1 [ 8 ] = c1 ; R2
[ 0 ] = c2 ; R2 [ 3 ] = 0.0 ; R2 [ 6 ] = s2 ; R2 [ 2 ] = - s2 ; R2 [ 5 ] =
0.0 ; R2 [ 8 ] = c2 ; R4 [ 0 ] = c4 ; R4 [ 3 ] = - s4 ; R4 [ 6 ] = 0.0 ; R4 [
1 ] = s4 ; R4 [ 4 ] = c4 ; R4 [ 7 ] = 0.0 ; R5 [ 1 ] = 0.0 ; R5 [ 4 ] = c5 ;
R5 [ 7 ] = - s5 ; R5 [ 2 ] = 0.0 ; R5 [ 5 ] = s5 ; R5 [ 8 ] = c5 ; R6 [ 0 ] =
c6 ; R6 [ 3 ] = 0.0 ; R6 [ 6 ] = s6 ; R6 [ 2 ] = - s6 ; R6 [ 5 ] = 0.0 ; R6 [
8 ] = c6 ; R7 [ 0 ] = c7 ; R7 [ 3 ] = 0.0 ; R7 [ 6 ] = s7 ; R0 [ 2 ] = 0.0 ;
R1 [ 0 ] = 1.0 ; R2 [ 1 ] = 0.0 ; R4 [ 2 ] = 0.0 ; R5 [ 0 ] = 1.0 ; R6 [ 1 ]
= 0.0 ; R7 [ 1 ] = 0.0 ; R0 [ 5 ] = 0.0 ; R1 [ 3 ] = 0.0 ; R2 [ 4 ] = 1.0 ;
R4 [ 5 ] = 0.0 ; R5 [ 3 ] = 0.0 ; R6 [ 4 ] = 1.0 ; R7 [ 4 ] = 1.0 ; R0 [ 8 ]
= 1.0 ; R1 [ 6 ] = 0.0 ; R2 [ 7 ] = 0.0 ; R4 [ 8 ] = 1.0 ; R5 [ 6 ] = 0.0 ;
R6 [ 7 ] = 0.0 ; R7 [ 7 ] = 0.0 ; R7 [ 2 ] = - s7 ; R7 [ 5 ] = 0.0 ; R7 [ 8 ]
= c7 ; sa = ( rtP . Constant_Value [ 24 ] - rtP . Constant_Value [ 22 ] ) *
rtP . Constant_Value [ 23 ] - ( rtP . Constant_Value [ 2 ] + rtP .
Constant_Value [ 11 ] ) * rtP . Constant_Value [ 22 ] ; sb = rtP .
Constant_Value [ 23 ] * rtP . Constant_Value [ 25 ] ; sc = ( rtP .
Constant_Value [ 12 ] - rtP . Constant_Value [ 10 ] ) * rtP . Constant_Value
[ 11 ] - rtP . Constant_Value [ 2 ] * rtP . Constant_Value [ 10 ] ; sd = ( (
rtP . Constant_Value [ 29 ] + rtP . Constant_Value [ 35 ] ) * rtP .
Constant_Value [ 34 ] + rtP . Constant_Value [ 30 ] * rtP . Constant_Value [
31 ] ) + rtP . Constant_Value [ 48 ] * rtP . Constant_Value [ 29 ] ; se = rtP
. Constant_Value [ 30 ] * rtP . Constant_Value [ 32 ] + rtP . Constant_Value
[ 34 ] * rtP . Constant_Value [ 36 ] ; sf = - rtP . Constant_Value [ 34 ] -
rtP . Constant_Value [ 48 ] ; si = rtP . Constant_Value [ 12 ] - rtP .
Constant_Value [ 10 ] ; sg = ( rtP . Constant_Value [ 10 ] * rtP .
Constant_Value [ 10 ] * rtP . Constant_Value [ 2 ] + si * si * rtP .
Constant_Value [ 11 ] ) + rtP . Constant_Value [ 13 ] ; si = 2.0 * rtP .
Constant_Value [ 34 ] * rtP . Constant_Value [ 36 ] ; sk = rtP .
Constant_Value [ 29 ] + rtP . Constant_Value [ 35 ] ; sj = ( ( ( ( rtP .
Constant_Value [ 31 ] * rtP . Constant_Value [ 31 ] + rtP . Constant_Value [
32 ] * rtP . Constant_Value [ 32 ] ) * rtP . Constant_Value [ 30 ] + ( sk *
sk + rtP . Constant_Value [ 36 ] * rtP . Constant_Value [ 36 ] ) * rtP .
Constant_Value [ 34 ] ) + rtP . Constant_Value [ 33 ] ) + rtP .
Constant_Value [ 37 ] ) + rtP . Constant_Value [ 29 ] * rtP . Constant_Value
[ 29 ] * rtP . Constant_Value [ 48 ] ; sk = ( rtP . Constant_Value [ 29 ] +
rtP . Constant_Value [ 35 ] ) * rtP . Constant_Value [ 34 ] + rtP .
Constant_Value [ 48 ] * rtP . Constant_Value [ 29 ] ; c_a = - rtP .
Constant_Value [ 22 ] + rtP . Constant_Value [ 24 ] ; sm = ( ( rtP .
Constant_Value [ 10 ] - rtP . Constant_Value [ 12 ] ) * rtP . Constant_Value
[ 11 ] + rtP . Constant_Value [ 2 ] * rtP . Constant_Value [ 10 ] ) * rtP .
Constant_Value [ 22 ] ; sn = ( ( ( ( rtP . Constant_Value [ 2 ] + rtP .
Constant_Value [ 11 ] ) + rtP . Constant_Value [ 23 ] ) * rtP .
Constant_Value [ 22 ] - 2.0 * rtP . Constant_Value [ 23 ] * rtP .
Constant_Value [ 24 ] ) * rtP . Constant_Value [ 22 ] + ( rtP .
Constant_Value [ 25 ] * rtP . Constant_Value [ 25 ] + rtP . Constant_Value [
24 ] * rtP . Constant_Value [ 24 ] ) * rtP . Constant_Value [ 23 ] ) + rtP .
Constant_Value [ 26 ] ; so = rtP . Constant_Value [ 22 ] * sc ; sp = ( ( rtP
. Constant_Value [ 37 ] - rtP . Constant_Value [ 37 ] ) + rtP .
Constant_Value [ 33 ] ) - rtP . Constant_Value [ 33 ] ; d_a = ( ( ( ( rtP .
Constant_Value [ 2 ] + rtP . Constant_Value [ 11 ] ) + rtP . Constant_Value [
23 ] ) + rtP . Constant_Value [ 30 ] ) + rtP . Constant_Value [ 34 ] ) + rtP
. Constant_Value [ 48 ] ; for ( i = 0 ; i < 169 ; i ++ ) { M [ i ] = d_a * (
real_T ) b_b [ i ] ; } s0_p [ 0 ] = - s0 ; s0_p [ 3 ] = - c0 ; s0_p [ 6 ] =
0.0 ; s0_p [ 1 ] = c0 ; s0_p [ 4 ] = - s0 ; s0_p [ 7 ] = 0.0 ; for ( i = 0 ;
i < 3 ; i ++ ) { R2_p [ i ] = ( R2 [ i + 6 ] * sb + R2 [ i ] * sa ) + ( R7 [
i + 6 ] * 0.0 + R7 [ i ] * sc ) ; s0_p [ 2 + 3 * i ] = 0.0 ; } s7_p [ 1 ] =
0.0 ; s7_p [ 4 ] = - s1 ; s7_p [ 7 ] = - c1 ; s7_p [ 2 ] = 0.0 ; s7_p [ 5 ] =
c1 ; s7_p [ 8 ] = - s1 ; for ( i = 0 ; i < 3 ; i ++ ) { s7_p [ 3 * i ] = 0.0
; R2_e [ i ] = ( R2 [ i + 6 ] * sb + R2 [ i ] * sa ) + ( R7 [ i + 6 ] * 0.0 +
R7 [ i ] * sc ) ; R1_p [ i ] = R1 [ i + 6 ] * R2_p [ 2 ] + ( R1 [ i + 3 ] *
R2_p [ 1 ] + R1 [ i ] * R2_p [ 0 ] ) ; } s2_p [ 0 ] = - s2 ; s2_p [ 3 ] = 0.0
; s2_p [ 6 ] = c2 ; for ( i = 0 ; i < 3 ; i ++ ) { s2_p [ 1 + 3 * i ] = 0.0 ;
v1_p [ i ] = s7_p [ i + 6 ] * R2_e [ 2 ] + ( s7_p [ i + 3 ] * R2_e [ 1 ] +
0.0 * R2_e [ 0 ] ) ; } s2_p [ 2 ] = - c2 ; s2_p [ 5 ] = 0.0 ; s2_p [ 8 ] = -
s2 ; for ( i = 0 ; i < 3 ; i ++ ) { R2_e [ i ] = s2_p [ i + 6 ] * sb + s2_p [
i ] * sa ; } d_a = sf * rtX . ebokkhvua4 [ 23 ] + se ; s2_p [ 0 ] = - s4 ;
s2_p [ 3 ] = - c4 ; s2_p [ 6 ] = 0.0 ; s2_p [ 1 ] = c4 ; s2_p [ 4 ] = - s4 ;
s2_p [ 7 ] = 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) { s2_p [ 2 + 3 * i ] = 0.0 ;
R2_p [ i ] = R1 [ i + 6 ] * R2_e [ 2 ] + ( R1 [ i + 3 ] * R2_e [ 1 ] + R1 [ i
] * R2_e [ 0 ] ) ; R6_p [ i ] = R6 [ i + 6 ] * d_a + R6 [ i ] * sd ; } d_a =
sf * rtX . ebokkhvua4 [ 23 ] + se ; s7_p [ 1 ] = 0.0 ; s7_p [ 4 ] = - s5 ;
s7_p [ 7 ] = - c5 ; s7_p [ 2 ] = 0.0 ; s7_p [ 5 ] = c5 ; s7_p [ 8 ] = - s5 ;
for ( i = 0 ; i < 3 ; i ++ ) { s7_p [ 3 * i ] = 0.0 ; R5_p [ i ] = R5 [ i + 6
] * R6_p [ 2 ] + ( R5 [ i + 3 ] * R6_p [ 1 ] + R5 [ i ] * R6_p [ 0 ] ) ; R6_e
[ i ] = R6 [ i + 6 ] * d_a + R6 [ i ] * sd ; } s6_p [ 0 ] = - s6 ; s6_p [ 3 ]
= 0.0 ; s6_p [ 6 ] = c6 ; for ( i = 0 ; i < 3 ; i ++ ) { s6_p [ 1 + 3 * i ] =
0.0 ; R2_e [ i ] = s7_p [ i + 6 ] * R6_e [ 2 ] + ( s7_p [ i + 3 ] * R6_e [ 1
] + 0.0 * R6_e [ 0 ] ) ; } s6_p [ 2 ] = - c6 ; s6_p [ 5 ] = 0.0 ; s6_p [ 8 ]
= - s6 ; d_a = sf * rtX . ebokkhvua4 [ 23 ] + se ; for ( i = 0 ; i < 3 ; i ++
) { R6_p [ i ] = s6_p [ i + 6 ] * d_a + s6_p [ i ] * sd ; } s7_p [ 0 ] = - s7
; s7_p [ 3 ] = 0.0 ; s7_p [ 6 ] = c7 ; for ( i = 0 ; i < 3 ; i ++ ) { s7_p [
1 + 3 * i ] = 0.0 ; R6_e [ i ] = R5 [ i + 6 ] * R6_p [ 2 ] + ( R5 [ i + 3 ] *
R6_p [ 1 ] + R5 [ i ] * R6_p [ 0 ] ) ; } s7_p [ 2 ] = - c7 ; s7_p [ 5 ] = 0.0
; s7_p [ 8 ] = - s7 ; for ( i = 0 ; i < 3 ; i ++ ) { s7_e [ i ] = s7_p [ i +
6 ] * 0.0 + s7_p [ i ] * sc ; } for ( i = 0 ; i < 3 ; i ++ ) { R1_e [ i ] =
R1 [ i + 6 ] * s7_e [ 2 ] + ( R1 [ i + 3 ] * s7_e [ 1 ] + R1 [ i ] * s7_e [ 0
] ) ; R6_p [ i ] = R6 [ i + 6 ] * sf + R6 [ i ] * 0.0 ; } for ( i = 0 ; i < 3
; i ++ ) { d_a = R4 [ i + 3 ] ; R0_m = R0 [ i + 3 ] ; s_idx_0 = R0_m * v1_p [
1 ] + R0 [ i ] * v1_p [ 0 ] ; s_idx_1 = R0_m * R2_p [ 1 ] + R0 [ i ] * R2_p [
0 ] ; s_idx_2 = d_a * R2_e [ 1 ] + R4 [ i ] * R2_e [ 0 ] ; s_idx_3 = d_a *
R6_e [ 1 ] + R4 [ i ] * R6_e [ 0 ] ; s_idx_4 = R0_m * R1_e [ 1 ] + R0 [ i ] *
R1_e [ 0 ] ; d_a = R4 [ i + 6 ] ; R0_m = R0 [ i + 6 ] ; s_idx_0 += R0_m *
v1_p [ 2 ] ; s_idx_1 += R0_m * R2_p [ 2 ] ; s_idx_2 += d_a * R2_e [ 2 ] ;
s_idx_3 += d_a * R6_e [ 2 ] ; s_idx_4 += R0_m * R1_e [ 2 ] ; s7_e [ i ] = R5
[ i + 6 ] * R6_p [ 2 ] + ( R5 [ i + 3 ] * R6_p [ 1 ] + R5 [ i ] * R6_p [ 0 ]
) ; s0_e [ i ] = 0.0 * R1_p [ 2 ] + ( s0_p [ i + 3 ] * R1_p [ 1 ] + s0_p [ i
] * R1_p [ 0 ] ) ; R0_p [ i ] = s_idx_0 ; R0_e [ i ] = s_idx_1 ; s4_p [ i ] =
0.0 * R5_p [ 2 ] + ( s2_p [ i + 3 ] * R5_p [ 1 ] + s2_p [ i ] * R5_p [ 0 ] )
; R4_p [ i ] = s_idx_2 ; R4_e [ i ] = s_idx_3 ; R0_i [ i ] = s_idx_4 ; }
p0b5byzq3l ( R1 , s7_p ) ; for ( i = 0 ; i < 3 ; i ++ ) { M [ 39 + i ] = s0_e
[ i ] ; M [ 52 + i ] = R0_p [ i ] ; M [ 65 + i ] = R0_e [ i ] ; M [ 78 + i ]
= s4_p [ i ] ; M [ 91 + i ] = R4_p [ i ] ; M [ 104 + i ] = R4_e [ i ] ; M [
117 + i ] = R0_i [ i ] ; M [ 130 + i ] = R4 [ i + 6 ] * s7_e [ 2 ] + ( R4 [ i
+ 3 ] * s7_e [ 1 ] + R4 [ i ] * s7_e [ 0 ] ) ; R2_p [ i ] = ( R2 [ i + 6 ] *
0.0 + R2 [ i ] * - rtP . Constant_Value [ 22 ] ) + ( R7 [ i + 6 ] * 0.0 + R7
[ i ] * - rtP . Constant_Value [ 10 ] ) ; } p0b5byzq3lx ( R2_p , v1_p ) ; d_a
= - rtP . Constant_Value [ 10 ] + rtP . Constant_Value [ 12 ] ; for ( i = 0 ;
i < 3 ; i ++ ) { R2_p [ i ] = ( R2 [ i + 6 ] * 0.0 + R2 [ i ] * - rtP .
Constant_Value [ 22 ] ) + ( R7 [ i + 6 ] * 0.0 + R7 [ i ] * d_a ) ; }
p0b5byzq3lx ( R2_p , R2_e ) ; d_a = - rtP . Constant_Value [ 22 ] + rtP .
Constant_Value [ 24 ] ; for ( i = 0 ; i < 3 ; i ++ ) { R2_p [ i ] = R2 [ i +
6 ] * rtP . Constant_Value [ 25 ] + R2 [ i ] * d_a ; } p0b5byzq3lx ( R2_p ,
R1_p ) ; R0_m = 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) { R0_m += ( ( rtP .
Constant_Value [ 2 ] * v1_p [ i ] + rtP . Constant_Value [ 11 ] * R2_e [ i ]
) + rtP . Constant_Value [ 23 ] * R1_p [ i ] ) * ( s7_p [ 3 * i + 2 ] * 0.0 +
( s7_p [ 3 * i + 1 ] + s7_p [ 3 * i ] ) ) ; } M [ 42 ] = ( ( ( ( ( ( ( rtP .
Constant_Value [ 4 ] - rtP . Constant_Value [ 3 ] ) + rtP . Constant_Value [
13 ] ) - rtP . Constant_Value [ 13 ] ) + rtP . Constant_Value [ 26 ] ) - rtP
. Constant_Value [ 26 ] ) + c7 * c7 * ( rtP . Constant_Value [ 13 ] - rtP .
Constant_Value [ 13 ] ) ) + c2 * c2 * ( rtP . Constant_Value [ 26 ] - rtP .
Constant_Value [ 26 ] ) ) * ( c1 * c1 ) + ( ( ( R0_m + rtP . Constant_Value [
26 ] ) + rtP . Constant_Value [ 13 ] ) + rtP . Constant_Value [ 3 ] ) ; M [
55 ] = ( ( ( ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 * rtP .
Constant_Value [ 10 ] ) + c7 * rtP . Constant_Value [ 12 ] ) * rtP .
Constant_Value [ 11 ] * ( ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) - s7 * rtP . Constant_Value [ 12 ] ) + ( - c2 * rtP .
Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ] ) * rtP .
Constant_Value [ 2 ] * ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) ) + ( ( - c2 * rtP . Constant_Value [ 22 ] + c2 * rtP
. Constant_Value [ 24 ] ) + s2 * rtP . Constant_Value [ 25 ] ) * rtP .
Constant_Value [ 23 ] * ( ( s2 * rtP . Constant_Value [ 22 ] - s2 * rtP .
Constant_Value [ 24 ] ) + c2 * rtP . Constant_Value [ 25 ] ) ) * - c1 + c1 *
s7 * c7 * ( rtP . Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) ) +
c1 * s2 * c2 * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] )
; M [ 68 ] = ( sn - muDoubleScalarCos ( rtX . ebokkhvua4 [ 18 ] - rtX .
ebokkhvua4 [ 22 ] ) * so ) * s1 ; M [ 120 ] = ( muDoubleScalarCos ( rtX .
ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * sm + sg ) * s1 ; M [ 146 ] =
rtP . Constant_Value [ 3 ] * s1 ; d_a = s2 * rtP . Constant_Value [ 22 ] + s7
* rtP . Constant_Value [ 10 ] ; R0_m = s2 * rtP . Constant_Value [ 22 ] - ( -
rtP . Constant_Value [ 10 ] + rtP . Constant_Value [ 12 ] ) * s7 ; g_a = ( -
rtP . Constant_Value [ 22 ] + rtP . Constant_Value [ 24 ] ) * - s2 + c2 * rtP
. Constant_Value [ 25 ] ; M [ 56 ] = ( ( ( ( ( ( d_a * d_a * rtP .
Constant_Value [ 2 ] + R0_m * R0_m * rtP . Constant_Value [ 11 ] ) + g_a *
g_a * rtP . Constant_Value [ 23 ] ) + c7 * c7 * ( rtP . Constant_Value [ 13 ]
- rtP . Constant_Value [ 13 ] ) ) + c2 * c2 * ( rtP . Constant_Value [ 26 ] -
rtP . Constant_Value [ 26 ] ) ) + rtP . Constant_Value [ 26 ] ) + rtP .
Constant_Value [ 13 ] ) + rtP . Constant_Value [ 4 ] ; M [ 70 ] = ( ( c_a *
c_a + rtP . Constant_Value [ 25 ] * rtP . Constant_Value [ 25 ] ) * rtP .
Constant_Value [ 23 ] + ( rtP . Constant_Value [ 2 ] + rtP . Constant_Value [
11 ] ) * ( rtP . Constant_Value [ 22 ] * rtP . Constant_Value [ 22 ] ) ) +
rtP . Constant_Value [ 26 ] ; M [ 122 ] = muDoubleScalarCos ( rtX .
ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * sm ; p0b5byzq3l ( R5 , s7_p )
; for ( i = 0 ; i < 3 ; i ++ ) { R6_p [ i ] = R6 [ i + 6 ] * rtP .
Constant_Value [ 32 ] + R6 [ i ] * rtP . Constant_Value [ 31 ] ; }
p0b5byzq3lx ( R6_p , v1_p ) ; d_a = rtP . Constant_Value [ 29 ] + rtP .
Constant_Value [ 35 ] ; c_a = - rtX . ebokkhvua4 [ 23 ] + rtP .
Constant_Value [ 36 ] ; for ( i = 0 ; i < 3 ; i ++ ) { R6_p [ i ] = R6 [ i +
6 ] * c_a + R6 [ i ] * d_a ; } p0b5byzq3lx ( R6_p , R2_e ) ; for ( i = 0 ; i
< 3 ; i ++ ) { R6_p [ i ] = R6 [ i + 6 ] * - rtX . ebokkhvua4 [ 23 ] + R6 [ i
] * rtP . Constant_Value [ 29 ] ; } p0b5byzq3lx ( R6_p , R1_p ) ; d_a = ( rtP
. Constant_Value [ 30 ] * v1_p [ 0 ] + rtP . Constant_Value [ 34 ] * R2_e [ 0
] ) + rtP . Constant_Value [ 48 ] * R1_p [ 0 ] ; s_idx_0 = ( rtP .
Constant_Value [ 30 ] * v1_p [ 1 ] + rtP . Constant_Value [ 34 ] * R2_e [ 1 ]
) + rtP . Constant_Value [ 48 ] * R1_p [ 1 ] ; c_a = ( rtP . Constant_Value [
30 ] * v1_p [ 2 ] + rtP . Constant_Value [ 34 ] * R2_e [ 2 ] ) + rtP .
Constant_Value [ 48 ] * R1_p [ 2 ] ; R0_m = 0.0 ; for ( i = 0 ; i < 3 ; i ++
) { R0_m += ( real_T ) bb_a [ i ] * ( s7_p [ i + 6 ] * c_a + ( s7_p [ i + 3 ]
* s_idx_0 + s7_p [ i ] * d_a ) ) ; } M [ 84 ] = ( ( ( ( ( ( rtP .
Constant_Value [ 50 ] - rtP . Constant_Value [ 49 ] ) + rtP . Constant_Value
[ 37 ] ) - rtP . Constant_Value [ 37 ] ) + rtP . Constant_Value [ 33 ] ) -
rtP . Constant_Value [ 33 ] ) + c6 * c6 * sp ) * ( c5 * c5 ) + ( ( ( R0_m +
rtP . Constant_Value [ 49 ] ) + rtP . Constant_Value [ 37 ] ) + rtP .
Constant_Value [ 33 ] ) ; c_a = rtP . Constant_Value [ 36 ] - rtX .
ebokkhvua4 [ 23 ] ; d_a = rtP . Constant_Value [ 29 ] + rtP . Constant_Value
[ 35 ] ; M [ 97 ] = ( ( ( ( rtP . Constant_Value [ 32 ] * rtP .
Constant_Value [ 32 ] - rtP . Constant_Value [ 31 ] * rtP . Constant_Value [
31 ] ) * rtP . Constant_Value [ 30 ] + ( c_a * c_a - d_a * d_a ) * rtP .
Constant_Value [ 34 ] ) + ( rtX . ebokkhvua4 [ 23 ] * rtX . ebokkhvua4 [ 23 ]
- rtP . Constant_Value [ 29 ] * rtP . Constant_Value [ 29 ] ) * rtP .
Constant_Value [ 48 ] ) * ( c6 * s6 ) + ( ( ( rtP . Constant_Value [ 29 ] +
rtP . Constant_Value [ 35 ] ) * rtP . Constant_Value [ 34 ] * ( rtP .
Constant_Value [ 36 ] - rtX . ebokkhvua4 [ 23 ] ) + rtP . Constant_Value [ 30
] * rtP . Constant_Value [ 31 ] * rtP . Constant_Value [ 32 ] ) - rtP .
Constant_Value [ 48 ] * rtP . Constant_Value [ 29 ] * rtX . ebokkhvua4 [ 23 ]
) * muDoubleScalarCos ( 2.0 * rtX . ebokkhvua4 [ 21 ] ) ) * - c5 + c5 * s6 *
c6 * sp ; M [ 110 ] = ( ( sj - rtX . ebokkhvua4 [ 23 ] * rtX . ebokkhvua4 [
23 ] * sf ) - si * rtX . ebokkhvua4 [ 23 ] ) * s5 ; M [ 136 ] = s5 * sk ; M [
162 ] = rtP . Constant_Value [ 49 ] * s5 ; c_a = c6 * rtP . Constant_Value [
32 ] - s6 * rtP . Constant_Value [ 31 ] ; d_a = ( rtP . Constant_Value [ 29 ]
+ rtP . Constant_Value [ 35 ] ) * - s6 + ( rtP . Constant_Value [ 36 ] - rtX
. ebokkhvua4 [ 23 ] ) * c6 ; R0_m = - s6 * rtP . Constant_Value [ 29 ] - c6 *
rtX . ebokkhvua4 [ 23 ] ; M [ 98 ] = ( ( ( ( ( c_a * c_a * rtP .
Constant_Value [ 30 ] + d_a * d_a * rtP . Constant_Value [ 34 ] ) + R0_m *
R0_m * rtP . Constant_Value [ 48 ] ) - c6 * c6 * sp ) + rtP . Constant_Value
[ 33 ] ) + rtP . Constant_Value [ 37 ] ) + rtP . Constant_Value [ 50 ] ; M [
112 ] = ( sj - rtX . ebokkhvua4 [ 23 ] * rtX . ebokkhvua4 [ 23 ] * sf ) - si
* rtX . ebokkhvua4 [ 23 ] ; M [ 138 ] = ( rtP . Constant_Value [ 29 ] + rtP .
Constant_Value [ 35 ] ) * rtP . Constant_Value [ 34 ] + rtP . Constant_Value
[ 48 ] * rtP . Constant_Value [ 29 ] ; M [ 126 ] = sg ; M [ 140 ] = - sf ; M
[ 154 ] = rtP . Constant_Value [ 3 ] ; M [ 168 ] = rtP . Constant_Value [ 49
] ; memcpy ( & f [ 0 ] , & M [ 0 ] , 169U * sizeof ( real_T ) ) ; fnncsruavj
( f ) ; for ( i = 0 ; i < 13 ; i ++ ) { for ( i_p = 0 ; i_p < 13 ; i_p ++ ) {
M_p [ i_p + 13 * i ] = M [ 13 * i_p + i ] + f [ 13 * i + i_p ] ; } } memcpy (
& M [ 0 ] , & M_p [ 0 ] , 169U * sizeof ( real_T ) ) ; c_a = - rtX .
ebokkhvua4 [ 23 ] + rtP . Constant_Value [ 36 ] ; d_a = rtP . Constant_Value
[ 29 ] + rtP . Constant_Value [ 35 ] ; R0_m = - rtX . ebokkhvua4 [ 23 ] + rtP
. Constant_Value [ 36 ] ; g_a = rtP . Constant_Value [ 29 ] + rtP .
Constant_Value [ 35 ] ; q_a = - rtX . ebokkhvua4 [ 23 ] + rtP .
Constant_Value [ 36 ] ; hxhenfzed1_idx_1 = rtP . Constant_Value [ 29 ] + rtP
. Constant_Value [ 35 ] ; s_idx_23 = - s6 * rtP . Constant_Value [ 31 ] + c6
* rtP . Constant_Value [ 32 ] ; s_idx_24 = ( rtP . Constant_Value [ 29 ] +
rtP . Constant_Value [ 35 ] ) * - s6 + ( - rtX . ebokkhvua4 [ 23 ] + rtP .
Constant_Value [ 36 ] ) * c6 ; s_idx_25 = - s6 * rtP . Constant_Value [ 29 ]
- c6 * rtX . ebokkhvua4 [ 23 ] ; s_idx_30 = ( s2 * rtP . Constant_Value [ 22
] - s2 * rtP . Constant_Value [ 24 ] ) + c2 * rtP . Constant_Value [ 25 ] ;
s_idx_32 = s2 * rtP . Constant_Value [ 22 ] + s7 * rtP . Constant_Value [ 10
] ; s_idx_33 = s2 * rtP . Constant_Value [ 22 ] - ( - rtP . Constant_Value [
10 ] + rtP . Constant_Value [ 12 ] ) * s7 ; r0d_idx_0 = ( - rtP .
Constant_Value [ 22 ] + rtP . Constant_Value [ 24 ] ) * - s2 + c2 * rtP .
Constant_Value [ 25 ] ; s_idx_0 = ( - s6 * rtP . Constant_Value [ 29 ] - c6 *
rtX . ebokkhvua4 [ 23 ] ) * rtP . Constant_Value [ 48 ] * c6 ; s_idx_1 = (
rtP . Constant_Value [ 29 ] + rtP . Constant_Value [ 35 ] ) * - s6 + ( - rtX
. ebokkhvua4 [ 23 ] + rtP . Constant_Value [ 36 ] ) * c6 ; s_idx_2 = ( ( (
2.0 * rtX . ebokkhvua4 [ 23 ] - 2.0 * rtP . Constant_Value [ 36 ] ) * rtP .
Constant_Value [ 34 ] + 2.0 * rtP . Constant_Value [ 48 ] * rtX . ebokkhvua4
[ 23 ] ) * ( c6 * s6 ) + ( ( rtP . Constant_Value [ 29 ] + rtP .
Constant_Value [ 35 ] ) * - rtP . Constant_Value [ 34 ] - rtP .
Constant_Value [ 48 ] * rtP . Constant_Value [ 29 ] ) * muDoubleScalarCos (
2.0 * rtX . ebokkhvua4 [ 21 ] ) ) * c5 ; s_idx_3 = ( rtP . Constant_Value [
29 ] + rtP . Constant_Value [ 35 ] ) * c6 + ( - rtX . ebokkhvua4 [ 23 ] + rtP
. Constant_Value [ 36 ] ) * s6 ; s_idx_4 = muDoubleScalarSin ( rtX .
ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * s1 * sm ; s_idx_5 =
muDoubleScalarSin ( rtX . ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * s1
* so ; s_idx_6 = s2 * rtP . Constant_Value [ 22 ] - ( - rtP . Constant_Value
[ 10 ] + rtP . Constant_Value [ 12 ] ) * s7 ; s_idx_7 = ( s2 * rtP .
Constant_Value [ 22 ] + s7 * rtP . Constant_Value [ 10 ] ) * rtP .
Constant_Value [ 2 ] * c7 * rtP . Constant_Value [ 10 ] ; s_idx_8 = (
muDoubleScalarCos ( rtX . ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * sm
+ sg ) * c1 ; s_idx_11 = ( ( ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 *
rtP . Constant_Value [ 10 ] ) * rtP . Constant_Value [ 2 ] * c7 * rtP .
Constant_Value [ 10 ] + rtP . Constant_Value [ 2 ] * s7 * rtP .
Constant_Value [ 10 ] * ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) ) + ( s7 * rtP . Constant_Value [ 10 ] - s7 * rtP .
Constant_Value [ 12 ] ) * rtP . Constant_Value [ 11 ] * ( ( s2 * rtP .
Constant_Value [ 22 ] + s7 * rtP . Constant_Value [ 10 ] ) - s7 * rtP .
Constant_Value [ 12 ] ) ) + ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 * rtP
. Constant_Value [ 10 ] ) + c7 * rtP . Constant_Value [ 12 ] ) * rtP .
Constant_Value [ 11 ] * ( c7 * rtP . Constant_Value [ 10 ] - c7 * rtP .
Constant_Value [ 12 ] ) ) * c1 ; s_idx_12 = ( - rtP . Constant_Value [ 10 ] +
rtP . Constant_Value [ 12 ] ) * c7 + - c2 * rtP . Constant_Value [ 22 ] ;
s_idx_13 = ( - s6 * rtP . Constant_Value [ 29 ] - c6 * rtX . ebokkhvua4 [ 23
] ) * rtP . Constant_Value [ 48 ] * ( - c6 * rtP . Constant_Value [ 29 ] + s6
* rtX . ebokkhvua4 [ 23 ] ) ; s_idx_14 = ( ( rtP . Constant_Value [ 29 ] +
rtP . Constant_Value [ 35 ] ) * - s6 + ( - rtX . ebokkhvua4 [ 23 ] + rtP .
Constant_Value [ 36 ] ) * c6 ) * rtP . Constant_Value [ 34 ] * ( ( rtP .
Constant_Value [ 29 ] + rtP . Constant_Value [ 35 ] ) * - c6 - ( - rtX .
ebokkhvua4 [ 23 ] + rtP . Constant_Value [ 36 ] ) * s6 ) ; s_idx_15 = ( - s6
* rtP . Constant_Value [ 31 ] + c6 * rtP . Constant_Value [ 32 ] ) * rtP .
Constant_Value [ 30 ] * ( - c6 * rtP . Constant_Value [ 31 ] - s6 * rtP .
Constant_Value [ 32 ] ) ; s_idx_16 = ( ( sj - rtX . ebokkhvua4 [ 23 ] * rtX .
ebokkhvua4 [ 23 ] * sf ) - si * rtX . ebokkhvua4 [ 23 ] ) * c5 ; s_idx_18 = (
( rtP . Constant_Value [ 32 ] * rtP . Constant_Value [ 32 ] - rtP .
Constant_Value [ 31 ] * rtP . Constant_Value [ 31 ] ) * rtP . Constant_Value
[ 30 ] + ( c_a * c_a - d_a * d_a ) * rtP . Constant_Value [ 34 ] ) + ( rtX .
ebokkhvua4 [ 23 ] * rtX . ebokkhvua4 [ 23 ] - rtP . Constant_Value [ 29 ] *
rtP . Constant_Value [ 29 ] ) * rtP . Constant_Value [ 48 ] ; s_idx_19 = ( (
( ( ( rtP . Constant_Value [ 32 ] * rtP . Constant_Value [ 32 ] - rtP .
Constant_Value [ 31 ] * rtP . Constant_Value [ 31 ] ) * rtP . Constant_Value
[ 30 ] + ( R0_m * R0_m - g_a * g_a ) * rtP . Constant_Value [ 34 ] ) + ( rtX
. ebokkhvua4 [ 23 ] * rtX . ebokkhvua4 [ 23 ] - rtP . Constant_Value [ 29 ] *
rtP . Constant_Value [ 29 ] ) * rtP . Constant_Value [ 48 ] ) * - ( s6 * s6 )
+ ( ( ( rtP . Constant_Value [ 32 ] * rtP . Constant_Value [ 32 ] - rtP .
Constant_Value [ 31 ] * rtP . Constant_Value [ 31 ] ) * rtP . Constant_Value
[ 30 ] + ( q_a * q_a - hxhenfzed1_idx_1 * hxhenfzed1_idx_1 ) * rtP .
Constant_Value [ 34 ] ) + ( rtX . ebokkhvua4 [ 23 ] * rtX . ebokkhvua4 [ 23 ]
- rtP . Constant_Value [ 29 ] * rtP . Constant_Value [ 29 ] ) * rtP .
Constant_Value [ 48 ] ) * ( c6 * c6 ) ) - ( ( ( rtP . Constant_Value [ 29 ] +
rtP . Constant_Value [ 35 ] ) * rtP . Constant_Value [ 34 ] * ( - rtX .
ebokkhvua4 [ 23 ] + rtP . Constant_Value [ 36 ] ) + rtP . Constant_Value [ 30
] * rtP . Constant_Value [ 31 ] * rtP . Constant_Value [ 32 ] ) - rtP .
Constant_Value [ 48 ] * rtP . Constant_Value [ 29 ] * rtX . ebokkhvua4 [ 23 ]
) * ( muDoubleScalarSin ( 2.0 * rtX . ebokkhvua4 [ 21 ] ) * 2.0 ) ) * c5 ;
s_idx_20 = - c6 * sd - ( sf * rtX . ebokkhvua4 [ 23 ] + se ) * s6 ; s_idx_21
= ( sf * rtX . ebokkhvua4 [ 23 ] + se ) * c6 + - s6 * sd ; s_idx_22 = ( ( ( (
( ( rtP . Constant_Value [ 50 ] - rtP . Constant_Value [ 49 ] ) + rtP .
Constant_Value [ 37 ] ) - rtP . Constant_Value [ 37 ] ) + rtP .
Constant_Value [ 33 ] ) - rtP . Constant_Value [ 33 ] ) + c6 * c6 * sp ) * c5
* s5 ; s_idx_23 = ( ( s_idx_23 * s_idx_23 * rtP . Constant_Value [ 30 ] +
s_idx_24 * s_idx_24 * rtP . Constant_Value [ 34 ] ) + s_idx_25 * s_idx_25 *
rtP . Constant_Value [ 48 ] ) * s5 * c5 ; s_idx_24 = ( - rtP . Constant_Value
[ 22 ] + rtP . Constant_Value [ 24 ] ) * - s2 + c2 * rtP . Constant_Value [
25 ] ; s_idx_25 = ( ( - rtP . Constant_Value [ 22 ] + rtP . Constant_Value [
24 ] ) * - s2 + c2 * rtP . Constant_Value [ 25 ] ) * rtP . Constant_Value [
23 ] * ( ( - rtP . Constant_Value [ 22 ] + rtP . Constant_Value [ 24 ] ) * -
c2 - s2 * rtP . Constant_Value [ 25 ] ) ; s_idx_26 = ( s2 * rtP .
Constant_Value [ 22 ] + s7 * rtP . Constant_Value [ 10 ] ) * rtP .
Constant_Value [ 2 ] * c2 * rtP . Constant_Value [ 22 ] ; s_idx_27 = ( sn -
muDoubleScalarCos ( rtX . ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * so
) * c1 ; s_idx_30 = ( ( ( ( ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 * rtP
. Constant_Value [ 10 ] ) * rtP . Constant_Value [ 2 ] * c2 * rtP .
Constant_Value [ 22 ] + rtP . Constant_Value [ 2 ] * s2 * rtP .
Constant_Value [ 22 ] * ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) ) + ( ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) - s7 * rtP . Constant_Value [ 12 ] ) * ( rtP .
Constant_Value [ 11 ] * s2 * rtP . Constant_Value [ 22 ] ) ) + ( ( - c2 * rtP
. Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ] ) + c7 * rtP .
Constant_Value [ 12 ] ) * rtP . Constant_Value [ 11 ] * c2 * rtP .
Constant_Value [ 22 ] ) + s_idx_30 * s_idx_30 * rtP . Constant_Value [ 23 ] )
+ ( ( - c2 * rtP . Constant_Value [ 22 ] + c2 * rtP . Constant_Value [ 24 ] )
+ s2 * rtP . Constant_Value [ 25 ] ) * rtP . Constant_Value [ 23 ] * ( ( c2 *
rtP . Constant_Value [ 22 ] - c2 * rtP . Constant_Value [ 24 ] ) - s2 * rtP .
Constant_Value [ 25 ] ) ) * c1 ; s_idx_31 = ( ( ( ( ( ( ( rtP .
Constant_Value [ 4 ] - rtP . Constant_Value [ 3 ] ) + rtP . Constant_Value [
13 ] ) - rtP . Constant_Value [ 13 ] ) + rtP . Constant_Value [ 26 ] ) - rtP
. Constant_Value [ 26 ] ) + c7 * c7 * ( rtP . Constant_Value [ 13 ] - rtP .
Constant_Value [ 13 ] ) ) + c2 * c2 * ( rtP . Constant_Value [ 26 ] - rtP .
Constant_Value [ 26 ] ) ) * c1 * s1 ; s_idx_32 = ( ( s_idx_32 * s_idx_32 *
rtP . Constant_Value [ 2 ] + s_idx_33 * s_idx_33 * rtP . Constant_Value [ 11
] ) + r0d_idx_0 * r0d_idx_0 * rtP . Constant_Value [ 23 ] ) * s1 * c1 ;
s_idx_33 = ( - s2 * sa + c2 * sb ) - s7 * sc ; r0d_idx_0 = ( ( ( ( ( ( - c2 *
rtP . Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ] ) * - s0 - ( -
c1 * s1 * rtP . Constant_Value [ 0 ] - ( ( ( s2 * rtP . Constant_Value [ 22 ]
+ s7 * rtP . Constant_Value [ 10 ] ) - rtP . Constant_Value [ 1 ] ) - c1 *
rtP . Constant_Value [ 0 ] ) * s1 ) * c0 ) * rtX . ebokkhvua4 [ 3 ] + rtX .
ebokkhvua4 [ 0 ] ) + ( ( ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) - rtP . Constant_Value [ 1 ] ) - c1 * rtP .
Constant_Value [ 0 ] ) * ( s0 * c1 ) * rtX . ebokkhvua4 [ 4 ] ) + ( s0 * s1 *
c2 * rtP . Constant_Value [ 22 ] + c0 * s2 * rtP . Constant_Value [ 22 ] ) *
rtX . ebokkhvua4 [ 5 ] ) + ( s0 * s1 * c7 * rtP . Constant_Value [ 10 ] + c0
* s7 * rtP . Constant_Value [ 10 ] ) * rtX . ebokkhvua4 [ 9 ] ) + ( - rtP .
Constant_Value [ 1 ] - c1 * rtP . Constant_Value [ 0 ] ) * c0 * rtX .
ebokkhvua4 [ 11 ] ; r0d_idx_1 = ( ( ( ( ( ( - c2 * rtP . Constant_Value [ 22
] - c7 * rtP . Constant_Value [ 10 ] ) * c0 - ( - c1 * s1 * rtP .
Constant_Value [ 0 ] - ( ( ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) - rtP . Constant_Value [ 1 ] ) - c1 * rtP .
Constant_Value [ 0 ] ) * s1 ) * s0 ) * rtX . ebokkhvua4 [ 3 ] + rtX .
ebokkhvua4 [ 1 ] ) - ( ( ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) - rtP . Constant_Value [ 1 ] ) - c1 * rtP .
Constant_Value [ 0 ] ) * ( c0 * c1 ) * rtX . ebokkhvua4 [ 4 ] ) + ( s0 * s2 *
rtP . Constant_Value [ 22 ] - c0 * s1 * c2 * rtP . Constant_Value [ 22 ] ) *
rtX . ebokkhvua4 [ 5 ] ) + ( s0 * s7 * rtP . Constant_Value [ 10 ] - c0 * s1
* c7 * rtP . Constant_Value [ 10 ] ) * rtX . ebokkhvua4 [ 9 ] ) + ( - rtP .
Constant_Value [ 1 ] - c1 * rtP . Constant_Value [ 0 ] ) * s0 * rtX .
ebokkhvua4 [ 11 ] ; r7d_idx_0 = ( ( ( ( ( ( c6 * rtP . Constant_Value [ 29 ]
- s6 * rtX . ebokkhvua4 [ 23 ] ) * - s4 - ( - c5 * s5 * rtP . Constant_Value
[ 46 ] - ( ( ( - s6 * rtP . Constant_Value [ 29 ] - c6 * rtX . ebokkhvua4 [
23 ] ) - rtP . Constant_Value [ 47 ] ) - c5 * rtP . Constant_Value [ 46 ] ) *
s5 ) * c4 ) * rtX . ebokkhvua4 [ 6 ] + rtX . ebokkhvua4 [ 0 ] ) + ( ( ( - s6
* rtP . Constant_Value [ 29 ] - c6 * rtX . ebokkhvua4 [ 23 ] ) - rtP .
Constant_Value [ 47 ] ) - c5 * rtP . Constant_Value [ 46 ] ) * ( s4 * c5 ) *
rtX . ebokkhvua4 [ 7 ] ) + ( ( - s6 * rtP . Constant_Value [ 29 ] - c6 * rtX
. ebokkhvua4 [ 23 ] ) * c4 + ( - c6 * rtP . Constant_Value [ 29 ] + s6 * rtX
. ebokkhvua4 [ 23 ] ) * ( s4 * s5 ) ) * rtX . ebokkhvua4 [ 8 ] ) + ( - c4 *
s6 - muDoubleScalarSin ( rtX . ebokkhvua4 [ 19 ] ) * s5 * c6 ) * rtX .
ebokkhvua4 [ 10 ] ) + ( - rtP . Constant_Value [ 47 ] - c5 * rtP .
Constant_Value [ 46 ] ) * c4 * rtX . ebokkhvua4 [ 12 ] ; r7d_idx_1 = ( ( ( (
( ( c6 * rtP . Constant_Value [ 29 ] - s6 * rtX . ebokkhvua4 [ 23 ] ) * c4 -
( - c5 * s5 * rtP . Constant_Value [ 46 ] - ( ( ( - s6 * rtP . Constant_Value
[ 29 ] - c6 * rtX . ebokkhvua4 [ 23 ] ) - rtP . Constant_Value [ 47 ] ) - c5
* rtP . Constant_Value [ 46 ] ) * s5 ) * s4 ) * rtX . ebokkhvua4 [ 6 ] + rtX
. ebokkhvua4 [ 1 ] ) - ( ( ( - s6 * rtP . Constant_Value [ 29 ] - c6 * rtX .
ebokkhvua4 [ 23 ] ) - rtP . Constant_Value [ 47 ] ) - c5 * rtP .
Constant_Value [ 46 ] ) * ( c4 * c5 ) * rtX . ebokkhvua4 [ 7 ] ) + ( ( - s6 *
rtP . Constant_Value [ 29 ] - c6 * rtX . ebokkhvua4 [ 23 ] ) * s4 - ( - c6 *
rtP . Constant_Value [ 29 ] + s6 * rtX . ebokkhvua4 [ 23 ] ) * ( c4 * s5 ) )
* rtX . ebokkhvua4 [ 8 ] ) + ( c4 * s5 * c6 + - s4 * s6 ) * rtX . ebokkhvua4
[ 10 ] ) + ( - rtP . Constant_Value [ 47 ] - c5 * rtP . Constant_Value [ 46 ]
) * s4 * rtX . ebokkhvua4 [ 12 ] ; rtB . ccaozxlshh [ 0 ] = 0.0 ; rtB .
ccaozxlshh [ 1 ] = 0.0 ; rtB . ccaozxlshh [ 2 ] = ( ( ( s2 * rtP .
Constant_Value [ 22 ] + s7 * rtP . Constant_Value [ 10 ] ) - rtP .
Constant_Value [ 1 ] ) * c1 + rtX . ebokkhvua4 [ 15 ] ) - rtP .
Constant_Value [ 0 ] ; rtB . ff31rlfzs2 [ 0 ] = 0.0 ; rtB . ff31rlfzs2 [ 1 ]
= 0.0 ; rtB . ff31rlfzs2 [ 2 ] = ( rtX . ebokkhvua4 [ 15 ] - ( ( s6 * rtP .
Constant_Value [ 29 ] + c6 * rtX . ebokkhvua4 [ 23 ] ) + rtP . Constant_Value
[ 47 ] ) * c5 ) - rtP . Constant_Value [ 46 ] ; for ( i = 0 ; i < 3 ; i ++ )
{ for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { R7 [ i_p + 3 * i ] = 0.0 ; R7 [ i_p +
3 * i ] += R2 [ 3 * i ] * R1 [ i_p ] ; R7 [ i_p + 3 * i ] += R2 [ 3 * i + 1 ]
* R1 [ i_p + 3 ] ; R7 [ i_p + 3 * i ] += R2 [ 3 * i + 2 ] * R1 [ i_p + 6 ] ;
} } for ( i = 0 ; i < 3 ; i ++ ) { v1 [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 3 ;
i_p ++ ) { R1 [ i + 3 * i_p ] = 0.0 ; R1 [ i + 3 * i_p ] += R7 [ 3 * i_p ] *
R0 [ i ] ; R1 [ i + 3 * i_p ] += R7 [ 3 * i_p + 1 ] * R0 [ i + 3 ] ; R1 [ i +
3 * i_p ] += R7 [ 3 * i_p + 2 ] * R0 [ i + 6 ] ; R2 [ i + 3 * i_p ] = 0.0 ;
R2 [ i + 3 * i_p ] += R5 [ 3 * i_p ] * R4 [ i ] ; R2 [ i + 3 * i_p ] += R5 [
3 * i_p + 1 ] * R4 [ i + 3 ] ; R2 [ i + 3 * i_p ] += R5 [ 3 * i_p + 2 ] * R4
[ i + 6 ] ; v1 [ i ] += R1 [ 3 * i_p + i ] * ( real_T ) c_b [ i_p ] ; } v2 [
i ] = 0.0 ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { s0_p [ i + 3 * i_p ] = 0.0 ;
s0_p [ i + 3 * i_p ] += R6 [ 3 * i_p ] * R2 [ i ] ; s0_p [ i + 3 * i_p ] +=
R6 [ 3 * i_p + 1 ] * R2 [ i + 3 ] ; s0_p [ i + 3 * i_p ] += R6 [ 3 * i_p + 2
] * R2 [ i + 6 ] ; v2 [ i ] += s0_p [ 3 * i_p + i ] * ( real_T ) c_b [ i_p ]
; } v1_p [ i ] = v1 [ i ] + v2 [ i ] ; } T3_idx_2 = k4sacqjg3c ( v1_p ) ; sg
= ( ( rtX . ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) - - 0.2 ) * rtP .
Constant_Value [ 19 ] + ( rtX . ebokkhvua4 [ 5 ] - rtX . ebokkhvua4 [ 9 ] ) *
rtP . Constant_Value [ 15 ] ; sj = ( real_T ) ( hwel15ulxt > 0.0 ) *
hwel15ulxt ; sn = ( real_T ) ( hwel15ulxt < 0.0 ) * hwel15ulxt ; c_a =
muDoubleScalarMax ( ( - rtP . Constant_Value [ 7 ] * rtB . ccaozxlshh [ 2 ] -
( ( ( rtX . ebokkhvua4 [ 2 ] - ( ( ( s2 * rtP . Constant_Value [ 22 ] + s7 *
rtP . Constant_Value [ 10 ] ) - rtP . Constant_Value [ 1 ] ) - c1 * rtP .
Constant_Value [ 0 ] ) * s1 * rtX . ebokkhvua4 [ 4 ] ) + c1 * c2 * rtP .
Constant_Value [ 22 ] * rtX . ebokkhvua4 [ 5 ] ) + c1 * c7 * rtP .
Constant_Value [ 10 ] * rtX . ebokkhvua4 [ 9 ] ) * rtP . Constant_Value [ 8 ]
) * ( real_T ) ( rtB . ccaozxlshh [ 2 ] < 0.0 ) , 0.0 ) ; d_a =
muDoubleScalarMax ( ( - rtP . Constant_Value [ 7 ] * rtB . ff31rlfzs2 [ 2 ] -
( ( ( rtX . ebokkhvua4 [ 2 ] - ( ( ( - s6 * rtP . Constant_Value [ 29 ] - c6
* rtX . ebokkhvua4 [ 23 ] ) - rtP . Constant_Value [ 47 ] ) - c5 * rtP .
Constant_Value [ 46 ] ) * s5 * rtX . ebokkhvua4 [ 7 ] ) + ( - c6 * rtP .
Constant_Value [ 29 ] + s6 * rtX . ebokkhvua4 [ 23 ] ) * c5 * rtX .
ebokkhvua4 [ 8 ] ) - c5 * c6 * rtX . ebokkhvua4 [ 10 ] ) * rtP .
Constant_Value [ 8 ] ) * ( real_T ) ( rtB . ff31rlfzs2 [ 2 ] < 0.0 ) , 0.0 )
; R0_m = ( 1.5707963267948966 - aaaovno5g3 ( v1 , v2 ) ) * rtP .
Constant_Value [ 27 ] ; jk0otd1dqr ( v1 , v2 , v1_p ) ; T3_idx_0 = ( v1 [ 0 ]
+ v2 [ 0 ] ) * - a3ncz0odn1 / T3_idx_2 ; T1_idx_0 = R0_m * v1_p [ 0 ] ;
T3_idx_1 = ( v1 [ 1 ] + v2 [ 1 ] ) * - a3ncz0odn1 / T3_idx_2 ; T1_idx_1 =
R0_m * v1_p [ 1 ] ; T3_idx_2 = ( v1 [ 2 ] + v2 [ 2 ] ) * - a3ncz0odn1 /
T3_idx_2 ; T1_idx_2 = R0_m * v1_p [ 2 ] ; R0_m = muDoubleScalarPower (
muDoubleScalarPower ( r0d_idx_0 * r0d_idx_0 + r0d_idx_1 * r0d_idx_1 , 4.0 ) +
1.0 , 0.125 ) ; g_a = r0d_idx_0 * r0d_idx_0 + r0d_idx_1 * r0d_idx_1 ; g_a *=
g_a ; hxhenfzed1_idx_0 = ( r0d_idx_0 / ( g_a + 1.0 ) + r0d_idx_0 / R0_m ) * -
c_a ; hxhenfzed1_idx_1 = ( r0d_idx_1 / ( g_a + 1.0 ) + r0d_idx_1 / R0_m ) * -
c_a ; R0_m = c0 * hxhenfzed1_idx_0 + s0 * hxhenfzed1_idx_1 ; g_a = - s0 *
hxhenfzed1_idx_0 + c0 * hxhenfzed1_idx_1 ; q_a = muDoubleScalarPower (
muDoubleScalarPower ( r7d_idx_0 * r7d_idx_0 + r7d_idx_1 * r7d_idx_1 , 4.0 ) +
1.0 , 0.125 ) ; hxhenfzed1_idx_1 = r7d_idx_0 * r7d_idx_0 + r7d_idx_1 *
r7d_idx_1 ; hxhenfzed1_idx_1 *= hxhenfzed1_idx_1 ; hxhenfzed1_idx_0 = (
r7d_idx_0 / ( hxhenfzed1_idx_1 + 1.0 ) + r7d_idx_0 / q_a ) * - d_a ;
hxhenfzed1_idx_1 = ( r7d_idx_1 / ( hxhenfzed1_idx_1 + 1.0 ) + r7d_idx_1 / q_a
) * - d_a ; q_a = c4 * hxhenfzed1_idx_0 + s4 * hxhenfzed1_idx_1 ;
hxhenfzed1_idx_1 = - s4 * hxhenfzed1_idx_0 + c4 * hxhenfzed1_idx_1 ; tmp [ 0
] = - 0.0 ; tmp [ 1 ] = - 0.0 ; tmp [ 2 ] = ( ( ( ( ( rtP . Constant_Value [
2 ] + rtP . Constant_Value [ 11 ] ) + rtP . Constant_Value [ 23 ] ) + rtP .
Constant_Value [ 30 ] ) + rtP . Constant_Value [ 34 ] ) + rtP .
Constant_Value [ 48 ] ) * - 9.81 ; tmp [ 3 ] = - 0.0 ; tmp [ 4 ] = ( ( ( s2 *
rtP . Constant_Value [ 22 ] + s7 * rtP . Constant_Value [ 10 ] ) * ( - rtP .
Constant_Value [ 2 ] * s1 ) - ( s2 * rtP . Constant_Value [ 22 ] - ( - rtP .
Constant_Value [ 10 ] + rtP . Constant_Value [ 12 ] ) * s7 ) * ( rtP .
Constant_Value [ 11 ] * s1 ) ) - ( ( - rtP . Constant_Value [ 22 ] + rtP .
Constant_Value [ 24 ] ) * - s2 + c2 * rtP . Constant_Value [ 25 ] ) * ( rtP .
Constant_Value [ 23 ] * s1 ) ) * - 9.81 ; tmp [ 5 ] = ( ( rtP .
Constant_Value [ 2 ] + rtP . Constant_Value [ 11 ] ) * c1 * c2 * rtP .
Constant_Value [ 22 ] + ( ( - rtP . Constant_Value [ 22 ] + rtP .
Constant_Value [ 24 ] ) * - c2 - s2 * rtP . Constant_Value [ 25 ] ) * ( rtP .
Constant_Value [ 23 ] * c1 ) ) * - 9.81 ; tmp [ 6 ] = - 0.0 ; tmp [ 7 ] = ( (
( - s6 * rtP . Constant_Value [ 31 ] + c6 * rtP . Constant_Value [ 32 ] ) * (
- rtP . Constant_Value [ 30 ] * s5 ) - ( ( rtP . Constant_Value [ 29 ] + rtP
. Constant_Value [ 35 ] ) * - s6 + ( - rtX . ebokkhvua4 [ 23 ] + rtP .
Constant_Value [ 36 ] ) * c6 ) * ( rtP . Constant_Value [ 34 ] * s5 ) ) - ( -
s6 * rtP . Constant_Value [ 29 ] - c6 * rtX . ebokkhvua4 [ 23 ] ) * ( rtP .
Constant_Value [ 48 ] * s5 ) ) * - 9.81 ; tmp [ 8 ] = ( ( ( ( rtP .
Constant_Value [ 29 ] + rtP . Constant_Value [ 35 ] ) * - c6 - ( - rtX .
ebokkhvua4 [ 23 ] + rtP . Constant_Value [ 36 ] ) * s6 ) * ( rtP .
Constant_Value [ 34 ] * c5 ) + ( - c6 * rtP . Constant_Value [ 31 ] - s6 *
rtP . Constant_Value [ 32 ] ) * ( rtP . Constant_Value [ 30 ] * c5 ) ) + ( -
c6 * rtP . Constant_Value [ 29 ] + s6 * rtX . ebokkhvua4 [ 23 ] ) * ( rtP .
Constant_Value [ 48 ] * c5 ) ) * - 9.81 ; tmp [ 9 ] = ( rtP . Constant_Value
[ 2 ] * c1 * c7 * rtP . Constant_Value [ 10 ] - rtP . Constant_Value [ 11 ] *
c1 * c7 * ( - rtP . Constant_Value [ 10 ] + rtP . Constant_Value [ 12 ] ) ) *
- 9.81 ; tmp [ 10 ] = c5 * c6 * sf * - 9.81 ; tmp [ 11 ] = - 0.0 ; tmp [ 12 ]
= - 0.0 ; tmp_p [ 0 ] = 0.0 ; tmp_p [ 1 ] = 0.0 ; tmp_p [ 2 ] = 0.0 ; tmp_p [
3 ] = 0.0 ; tmp_p [ 4 ] = 0.0 ; tmp_p [ 5 ] = 0.0 ; tmp_p [ 6 ] = 0.0 ; tmp_p
[ 7 ] = 0.0 ; tmp_p [ 8 ] = 0.0 ; tmp_p [ 9 ] = 0.0 ; tmp_p [ 10 ] = - ( ( (
( ( rtX . ebokkhvua4 [ 23 ] - rtP . Constant_Value [ 40 ] ) * rtP .
Constant_Value [ 43 ] + rtP . Constant_Value [ 41 ] * rtX . ebokkhvua4 [ 10 ]
* ( real_T ) ( rtX . ebokkhvua4 [ 10 ] < 0.0 ) ) + rtP . Constant_Value [ 42
] * rtX . ebokkhvua4 [ 10 ] * ( real_T ) ( rtX . ebokkhvua4 [ 10 ] > 0.0 ) )
- ( real_T ) ( rtX . ebokkhvua4 [ 23 ] < rtP . Constant_Value [ 39 ] ) * rtP
. Constant_Value [ 27 ] ) + ( real_T ) ( rtX . ebokkhvua4 [ 23 ] > rtP .
Constant_Value [ 38 ] ) * rtP . Constant_Value [ 27 ] ) ; tmp_p [ 11 ] = 0.0
; tmp_p [ 12 ] = 0.0 ; tmp_e [ 0 ] = 0.0 ; tmp_e [ 1 ] = 0.0 ; tmp_e [ 2 ] =
0.0 ; tmp_e [ 3 ] = 0.0 ; tmp_e [ 4 ] = 0.0 ; tmp_e [ 5 ] = - sg ; tmp_e [ 6
] = 0.0 ; tmp_e [ 7 ] = 0.0 ; tmp_e [ 8 ] = 0.0 ; tmp_e [ 9 ] = sg ; tmp_e [
10 ] = 0.0 ; tmp_e [ 11 ] = 0.0 ; tmp_e [ 12 ] = 0.0 ; tmp_i [ 0 ] = 0.0 *
c_a ; tmp_i [ 1 ] = 0.0 * c_a ; tmp_i [ 2 ] = c_a ; tmp_i [ 3 ] = 0.0 * c_a ;
tmp_i [ 4 ] = ( ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) - rtP . Constant_Value [ 1 ] ) * - s1 * c_a ; tmp_i [
5 ] = c1 * c2 * rtP . Constant_Value [ 22 ] * c_a ; tmp_i [ 6 ] = 0.0 * c_a ;
tmp_i [ 7 ] = 0.0 * c_a ; tmp_i [ 8 ] = 0.0 * c_a ; tmp_i [ 9 ] = c1 * c7 *
rtP . Constant_Value [ 10 ] * c_a ; tmp_i [ 10 ] = 0.0 * c_a ; tmp_i [ 11 ] =
0.0 * c_a ; tmp_i [ 12 ] = 0.0 * c_a ; tmp_m [ 0 ] = 0.0 * d_a ; tmp_m [ 1 ]
= 0.0 * d_a ; tmp_m [ 2 ] = d_a ; tmp_m [ 3 ] = 0.0 * d_a ; tmp_m [ 4 ] = 0.0
* d_a ; tmp_m [ 5 ] = 0.0 * d_a ; tmp_m [ 6 ] = 0.0 * d_a ; tmp_m [ 7 ] = ( (
s6 * rtP . Constant_Value [ 29 ] + c6 * rtX . ebokkhvua4 [ 23 ] ) + rtP .
Constant_Value [ 47 ] ) * s5 * d_a ; tmp_m [ 8 ] = ( s6 * rtX . ebokkhvua4 [
23 ] - c6 * rtP . Constant_Value [ 29 ] ) * c5 * d_a ; tmp_m [ 9 ] = 0.0 *
d_a ; tmp_m [ 10 ] = - c5 * c6 * d_a ; tmp_m [ 11 ] = 0.0 * d_a ; tmp_m [ 12
] = 0.0 * d_a ; tmp_g [ 0 ] = 0.0 ; tmp_g [ 1 ] = 0.0 ; tmp_g [ 2 ] = 0.0 ;
tmp_g [ 3 ] = T1_idx_2 ; tmp_g [ 4 ] = c0 * T1_idx_0 + s0 * T1_idx_1 ; tmp_g
[ 5 ] = ( - s0 * c1 * T1_idx_0 + c0 * c1 * T1_idx_1 ) + s1 * T1_idx_2 ; tmp_g
[ 6 ] = - T1_idx_2 ; tmp_g [ 7 ] = - c4 * T1_idx_0 - s4 * T1_idx_1 ; tmp_g [
8 ] = ( s4 * c5 * T1_idx_0 - c4 * c5 * T1_idx_1 ) - s5 * T1_idx_2 ; tmp_g [ 9
] = 0.0 ; tmp_g [ 10 ] = 0.0 ; tmp_g [ 11 ] = 0.0 ; tmp_g [ 12 ] = 0.0 ;
tmp_j [ 0 ] = 0.0 ; tmp_j [ 1 ] = 0.0 ; tmp_j [ 2 ] = 0.0 ; tmp_j [ 3 ] =
T3_idx_2 ; tmp_j [ 4 ] = c0 * T3_idx_0 + s0 * T3_idx_1 ; tmp_j [ 5 ] = ( - s0
* c1 * T3_idx_0 + c0 * c1 * T3_idx_1 ) + s1 * T3_idx_2 ; tmp_j [ 6 ] = -
T3_idx_2 ; tmp_j [ 7 ] = - c4 * T3_idx_0 - s4 * T3_idx_1 ; tmp_j [ 8 ] = ( s4
* c5 * T3_idx_0 - c4 * c5 * T3_idx_1 ) - s5 * T3_idx_2 ; tmp_j [ 9 ] = 0.0 ;
tmp_j [ 10 ] = 0.0 ; tmp_j [ 11 ] = 0.0 ; tmp_j [ 12 ] = 0.0 ; s4_e [ 0 ] = -
s4 * hxhenfzed1_idx_1 ; s4_e [ 1 ] = c4 * hxhenfzed1_idx_1 ; s4_e [ 2 ] = 0.0
* hxhenfzed1_idx_1 ; s4_e [ 3 ] = 0.0 * hxhenfzed1_idx_1 ; s4_e [ 4 ] = 0.0 *
hxhenfzed1_idx_1 ; s4_e [ 5 ] = 0.0 * hxhenfzed1_idx_1 ; s4_e [ 6 ] = ( c6 *
rtP . Constant_Value [ 29 ] - s6 * rtX . ebokkhvua4 [ 23 ] ) *
hxhenfzed1_idx_1 ; s4_e [ 7 ] = ( ( ( s6 * rtP . Constant_Value [ 29 ] + c6 *
rtX . ebokkhvua4 [ 23 ] ) + rtP . Constant_Value [ 47 ] ) * c5 + rtP .
Constant_Value [ 46 ] ) * hxhenfzed1_idx_1 ; s4_e [ 8 ] = ( c6 * rtP .
Constant_Value [ 29 ] - s6 * rtX . ebokkhvua4 [ 23 ] ) * s5 *
hxhenfzed1_idx_1 ; s4_e [ 9 ] = 0.0 * hxhenfzed1_idx_1 ; s4_e [ 10 ] = s5 *
c6 * hxhenfzed1_idx_1 ; s4_e [ 11 ] = 0.0 * hxhenfzed1_idx_1 ; s4_e [ 12 ] =
0.0 * hxhenfzed1_idx_1 ; c4_p [ 0 ] = c4 * q_a ; c4_p [ 1 ] = s4 * q_a ; c4_p
[ 2 ] = 0.0 * q_a ; c4_p [ 3 ] = 0.0 * q_a ; c4_p [ 4 ] = 0.0 * q_a ; c4_p [
5 ] = 0.0 * q_a ; c4_p [ 6 ] = ( ( s6 * rtP . Constant_Value [ 29 ] + c6 *
rtX . ebokkhvua4 [ 23 ] ) + rtP . Constant_Value [ 47 ] ) * - s5 * q_a ; c4_p
[ 7 ] = 0.0 * q_a ; c4_p [ 8 ] = ( - s6 * rtP . Constant_Value [ 29 ] - c6 *
rtX . ebokkhvua4 [ 23 ] ) * q_a ; c4_p [ 9 ] = 0.0 * q_a ; c4_p [ 10 ] = - s6
* q_a ; c4_p [ 11 ] = 0.0 * q_a ; c4_p [ 12 ] = ( - c5 * rtP . Constant_Value
[ 46 ] - rtP . Constant_Value [ 47 ] ) * q_a ; c0_p [ 0 ] = c0 * R0_m ; c0_p
[ 1 ] = s0 * R0_m ; c0_p [ 2 ] = 0.0 * R0_m ; c0_p [ 3 ] = ( ( - s2 * rtP .
Constant_Value [ 22 ] - s7 * rtP . Constant_Value [ 10 ] ) + rtP .
Constant_Value [ 1 ] ) * - s1 * R0_m ; c0_p [ 4 ] = 0.0 * R0_m ; c0_p [ 5 ] =
s2 * rtP . Constant_Value [ 22 ] * R0_m ; c0_p [ 6 ] = 0.0 * R0_m ; c0_p [ 7
] = 0.0 * R0_m ; c0_p [ 8 ] = 0.0 * R0_m ; c0_p [ 9 ] = s7 * rtP .
Constant_Value [ 10 ] * R0_m ; c0_p [ 10 ] = 0.0 * R0_m ; c0_p [ 11 ] = ( -
c1 * rtP . Constant_Value [ 0 ] - rtP . Constant_Value [ 1 ] ) * R0_m ; c0_p
[ 12 ] = 0.0 * R0_m ; s0_i [ 0 ] = - s0 * g_a ; s0_i [ 1 ] = c0 * g_a ; s0_i
[ 2 ] = 0.0 * g_a ; s0_i [ 3 ] = ( - c2 * rtP . Constant_Value [ 22 ] - c7 *
rtP . Constant_Value [ 10 ] ) * g_a ; s0_i [ 4 ] = ( ( ( rtP . Constant_Value
[ 1 ] - s2 * rtP . Constant_Value [ 22 ] ) - s7 * rtP . Constant_Value [ 10 ]
) * c1 + rtP . Constant_Value [ 0 ] ) * g_a ; s0_i [ 5 ] = - s1 * c2 * rtP .
Constant_Value [ 22 ] * g_a ; s0_i [ 6 ] = 0.0 * g_a ; s0_i [ 7 ] = 0.0 * g_a
; s0_i [ 8 ] = 0.0 * g_a ; s0_i [ 9 ] = - s1 * c7 * rtP . Constant_Value [ 10
] * g_a ; s0_i [ 10 ] = 0.0 * g_a ; s0_i [ 11 ] = 0.0 * g_a ; s0_i [ 12 ] =
0.0 * g_a ; tmp_f [ 0 ] = 0.0 ; tmp_f [ 1 ] = 0.0 ; tmp_f [ 2 ] = 0.0 ; tmp_f
[ 3 ] = 0.0 ; tmp_f [ 4 ] = 0.0 ; tmp_f [ 5 ] = 0.0 ; tmp_f [ 6 ] = 0.0 ;
tmp_f [ 7 ] = 0.0 ; tmp_f [ 8 ] = - sn ; tmp_f [ 9 ] = 0.0 ; tmp_f [ 10 ] =
0.0 ; tmp_f [ 11 ] = 0.0 ; tmp_f [ 12 ] = sn ; tmp_c [ 0 ] = 0.0 ; tmp_c [ 1
] = 0.0 ; tmp_c [ 2 ] = 0.0 ; tmp_c [ 3 ] = 0.0 ; tmp_c [ 4 ] = 0.0 ; tmp_c [
5 ] = 0.0 ; tmp_c [ 6 ] = 0.0 ; tmp_c [ 7 ] = 0.0 ; tmp_c [ 8 ] = 0.0 ; tmp_c
[ 9 ] = - sj ; tmp_c [ 10 ] = 0.0 ; tmp_c [ 11 ] = sj ; tmp_c [ 12 ] = 0.0 ;
f [ 0 ] = 0.0 ; f [ 13 ] = 0.0 ; f [ 26 ] = 0.0 ; f [ 39 ] = ( ( ( ( ( c2 *
sa + s2 * sb ) + c7 * sc ) * - c0 - s0 * s1 * s_idx_33 ) * rtX . ebokkhvua4 [
3 ] + c0 * c1 * s_idx_33 * rtX . ebokkhvua4 [ 4 ] ) + ( ( - s2 * sa + c2 * sb
) * - s0 + ( - c2 * sa - s2 * sb ) * ( c0 * s1 ) ) * rtX . ebokkhvua4 [ 5 ] )
+ ( s0 * s7 * sc - c0 * s1 * c7 * sc ) * rtX . ebokkhvua4 [ 9 ] ; f [ 52 ] =
( ( c0 * c1 * s_idx_33 * rtX . ebokkhvua4 [ 3 ] - s0 * s1 * s_idx_33 * rtX .
ebokkhvua4 [ 4 ] ) + ( - c2 * sa - s2 * sb ) * ( s0 * c1 ) * rtX . ebokkhvua4
[ 5 ] ) - s0 * c1 * c7 * sc * rtX . ebokkhvua4 [ 9 ] ; f [ 65 ] = ( ( ( - s2
* sa + c2 * sb ) * - s0 + ( - c2 * sa - s2 * sb ) * ( c0 * s1 ) ) * rtX .
ebokkhvua4 [ 3 ] + ( - c2 * sa - s2 * sb ) * ( s0 * c1 ) * rtX . ebokkhvua4 [
4 ] ) + ( ( - c2 * sa - s2 * sb ) * c0 + ( s2 * sa - c2 * sb ) * ( s0 * s1 )
) * rtX . ebokkhvua4 [ 5 ] ; f [ 78 ] = ( ( ( ( ( sf * rtX . ebokkhvua4 [ 23
] + se ) * s6 + c6 * sd ) * - c4 - s4 * s5 * s_idx_21 ) * rtX . ebokkhvua4 [
6 ] + c4 * c5 * s_idx_21 * rtX . ebokkhvua4 [ 7 ] ) + ( c4 * s5 * s_idx_20 +
- s4 * s_idx_21 ) * rtX . ebokkhvua4 [ 8 ] ) + ( c4 * s5 * c6 * sf + - s4 *
s6 * sf ) * rtX . ebokkhvua4 [ 10 ] ; f [ 91 ] = ( ( c4 * c5 * s_idx_21 * rtX
. ebokkhvua4 [ 6 ] - s4 * s5 * s_idx_21 * rtX . ebokkhvua4 [ 7 ] ) + s4 * c5
* s_idx_20 * rtX . ebokkhvua4 [ 8 ] ) + s4 * c5 * c6 * sf * rtX . ebokkhvua4
[ 10 ] ; f [ 104 ] = ( ( ( s6 * sd - ( sf * rtX . ebokkhvua4 [ 23 ] + se ) *
c6 ) * ( s4 * s5 ) + c4 * s_idx_20 ) * rtX . ebokkhvua4 [ 8 ] + ( ( c4 * s5 *
s_idx_20 + - s4 * s_idx_21 ) * rtX . ebokkhvua4 [ 6 ] + s4 * c5 * s_idx_20 *
rtX . ebokkhvua4 [ 7 ] ) ) + ( c4 * c6 * sf - s4 * s5 * s6 * sf ) * rtX .
ebokkhvua4 [ 10 ] ; f [ 117 ] = ( ( s0 * s7 * sc - c0 * s1 * c7 * sc ) * rtX
. ebokkhvua4 [ 3 ] - s0 * c1 * c7 * sc * rtX . ebokkhvua4 [ 4 ] ) + ( s0 * s1
* s7 * sc + - c0 * c7 * sc ) * rtX . ebokkhvua4 [ 9 ] ; f [ 130 ] = ( ( c4 *
s5 * c6 * sf + - s4 * s6 * sf ) * rtX . ebokkhvua4 [ 6 ] + s4 * c5 * c6 * sf
* rtX . ebokkhvua4 [ 7 ] ) + ( c4 * c6 * sf - s4 * s5 * s6 * sf ) * rtX .
ebokkhvua4 [ 8 ] ; f [ 143 ] = 0.0 ; f [ 156 ] = 0.0 ; f [ 1 ] = 0.0 ; f [ 14
] = 0.0 ; f [ 27 ] = 0.0 ; f [ 40 ] = ( ( ( ( ( c2 * sa + s2 * sb ) + c7 * sc
) * - s0 + c0 * s1 * s_idx_33 ) * rtX . ebokkhvua4 [ 3 ] + s0 * c1 * s_idx_33
* rtX . ebokkhvua4 [ 4 ] ) + ( ( - s2 * sa + c2 * sb ) * c0 + ( - c2 * sa -
s2 * sb ) * ( s0 * s1 ) ) * rtX . ebokkhvua4 [ 5 ] ) + ( - c0 * s7 * sc - s0
* s1 * c7 * sc ) * rtX . ebokkhvua4 [ 9 ] ; f [ 53 ] = ( ( s0 * c1 * s_idx_33
* rtX . ebokkhvua4 [ 3 ] + c0 * s1 * s_idx_33 * rtX . ebokkhvua4 [ 4 ] ) - (
- c2 * sa - s2 * sb ) * ( c0 * c1 ) * rtX . ebokkhvua4 [ 5 ] ) + c0 * c1 * c7
* sc * rtX . ebokkhvua4 [ 9 ] ; f [ 66 ] = ( ( ( - s2 * sa + c2 * sb ) * c0 +
( - c2 * sa - s2 * sb ) * ( s0 * s1 ) ) * rtX . ebokkhvua4 [ 3 ] - ( - c2 *
sa - s2 * sb ) * ( c0 * c1 ) * rtX . ebokkhvua4 [ 4 ] ) + ( ( - c2 * sa - s2
* sb ) * s0 - ( s2 * sa - c2 * sb ) * ( c0 * s1 ) ) * rtX . ebokkhvua4 [ 5 ]
; f [ 79 ] = ( ( ( ( ( sf * rtX . ebokkhvua4 [ 23 ] + se ) * s6 + c6 * sd ) *
- s4 + c4 * s5 * s_idx_21 ) * rtX . ebokkhvua4 [ 6 ] + s4 * c5 * s_idx_21 *
rtX . ebokkhvua4 [ 7 ] ) + ( s4 * s5 * s_idx_20 + c4 * s_idx_21 ) * rtX .
ebokkhvua4 [ 8 ] ) + ( s4 * s5 * c6 * sf + c4 * s6 * sf ) * rtX . ebokkhvua4
[ 10 ] ; f [ 92 ] = ( ( s4 * c5 * s_idx_21 * rtX . ebokkhvua4 [ 6 ] + c4 * s5
* s_idx_21 * rtX . ebokkhvua4 [ 7 ] ) - c4 * c5 * s_idx_20 * rtX . ebokkhvua4
[ 8 ] ) - c4 * c5 * c6 * sf * rtX . ebokkhvua4 [ 10 ] ; f [ 105 ] = ( ( s4 *
s_idx_20 - ( s6 * sd - ( sf * rtX . ebokkhvua4 [ 23 ] + se ) * c6 ) * ( c4 *
s5 ) ) * rtX . ebokkhvua4 [ 8 ] + ( ( s4 * s5 * s_idx_20 + c4 * s_idx_21 ) *
rtX . ebokkhvua4 [ 6 ] - c4 * c5 * s_idx_20 * rtX . ebokkhvua4 [ 7 ] ) ) + (
c4 * s5 * s6 * sf + s4 * c6 * sf ) * rtX . ebokkhvua4 [ 10 ] ; f [ 118 ] = (
( - c0 * s7 * sc - s0 * s1 * c7 * sc ) * rtX . ebokkhvua4 [ 3 ] + c0 * c1 *
c7 * sc * rtX . ebokkhvua4 [ 4 ] ) + ( - s0 * c7 * sc - c0 * s1 * s7 * sc ) *
rtX . ebokkhvua4 [ 9 ] ; f [ 131 ] = ( ( s4 * s5 * c6 * sf + c4 * s6 * sf ) *
rtX . ebokkhvua4 [ 6 ] - c4 * c5 * c6 * sf * rtX . ebokkhvua4 [ 7 ] ) + ( c4
* s5 * s6 * sf + s4 * c6 * sf ) * rtX . ebokkhvua4 [ 8 ] ; f [ 144 ] = 0.0 ;
f [ 157 ] = 0.0 ; f [ 2 ] = 0.0 ; f [ 15 ] = 0.0 ; f [ 28 ] = 0.0 ; f [ 41 ]
= 0.0 ; f [ 54 ] = ( - c1 * s_idx_33 * rtX . ebokkhvua4 [ 4 ] - ( - c2 * sa -
s2 * sb ) * s1 * rtX . ebokkhvua4 [ 5 ] ) + s1 * c7 * sc * rtX . ebokkhvua4 [
9 ] ; f [ 67 ] = ( - c2 * sa - s2 * sb ) * - s1 * rtX . ebokkhvua4 [ 4 ] + (
s2 * sa - c2 * sb ) * c1 * rtX . ebokkhvua4 [ 5 ] ; f [ 80 ] = 0.0 ; f [ 93 ]
= ( - c5 * s_idx_21 * rtX . ebokkhvua4 [ 7 ] - s5 * s_idx_20 * rtX .
ebokkhvua4 [ 8 ] ) - s5 * c6 * sf * rtX . ebokkhvua4 [ 10 ] ; f [ 106 ] = ( (
s6 * sd - ( sf * rtX . ebokkhvua4 [ 23 ] + se ) * c6 ) * c5 * rtX .
ebokkhvua4 [ 8 ] + - s5 * s_idx_20 * rtX . ebokkhvua4 [ 7 ] ) - c5 * s6 * sf
* rtX . ebokkhvua4 [ 10 ] ; f [ 119 ] = s1 * c7 * sc * rtX . ebokkhvua4 [ 4 ]
+ c1 * s7 * sc * rtX . ebokkhvua4 [ 9 ] ; f [ 132 ] = - s5 * c6 * sf * rtX .
ebokkhvua4 [ 7 ] - c5 * s6 * sf * rtX . ebokkhvua4 [ 8 ] ; f [ 145 ] = 0.0 ;
f [ 158 ] = 0.0 ; f [ 3 ] = 0.0 ; f [ 16 ] = 0.0 ; f [ 29 ] = 0.0 ; f [ 42 ]
= ( ( ( ( ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 * rtP . Constant_Value
[ 10 ] ) * rtP . Constant_Value [ 2 ] * s2 * rtP . Constant_Value [ 22 ] +
rtP . Constant_Value [ 11 ] * s_idx_12 * s2 * rtP . Constant_Value [ 22 ] ) +
( ( - rtP . Constant_Value [ 22 ] + rtP . Constant_Value [ 24 ] ) * c2 + s2 *
rtP . Constant_Value [ 25 ] ) * rtP . Constant_Value [ 23 ] * s_idx_24 ) + (
( 2.0 * rtP . Constant_Value [ 11 ] * s_idx_6 * c2 * rtP . Constant_Value [
22 ] + 2.0 * s_idx_26 ) + 2.0 * s_idx_25 ) * ( s1 * s1 * 0.5 ) ) - c1 * c1 *
c2 * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) * s2 ) *
rtX . ebokkhvua4 [ 5 ] + ( s_idx_32 - s_idx_31 ) * rtX . ebokkhvua4 [ 4 ] ) +
( ( ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ]
) * rtP . Constant_Value [ 2 ] * s7 * rtP . Constant_Value [ 10 ] - rtP .
Constant_Value [ 11 ] * s_idx_12 * s7 * ( - rtP . Constant_Value [ 10 ] + rtP
. Constant_Value [ 12 ] ) ) + ( 2.0 * s_idx_7 - 2.0 * rtP . Constant_Value [
11 ] * s_idx_6 * c7 * ( - rtP . Constant_Value [ 10 ] + rtP . Constant_Value
[ 12 ] ) ) * ( s1 * s1 * 0.5 ) ) - c1 * c1 * c7 * ( rtP . Constant_Value [ 13
] - rtP . Constant_Value [ 13 ] ) * s7 ) * rtX . ebokkhvua4 [ 9 ] ; f [ 55 ]
= ( ( ( ( ( ( ( ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 * rtP .
Constant_Value [ 10 ] ) + c7 * rtP . Constant_Value [ 12 ] ) * rtP .
Constant_Value [ 11 ] * ( ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) - s7 * rtP . Constant_Value [ 12 ] ) + ( - c2 * rtP .
Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ] ) * rtP .
Constant_Value [ 2 ] * ( s2 * rtP . Constant_Value [ 22 ] + s7 * rtP .
Constant_Value [ 10 ] ) ) + ( ( - c2 * rtP . Constant_Value [ 22 ] + c2 * rtP
. Constant_Value [ 24 ] ) + s2 * rtP . Constant_Value [ 25 ] ) * rtP .
Constant_Value [ 23 ] * ( ( s2 * rtP . Constant_Value [ 22 ] - s2 * rtP .
Constant_Value [ 24 ] ) + c2 * rtP . Constant_Value [ 25 ] ) ) * s1 - s1 * s7
* c7 * ( rtP . Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) ) - s1 *
s2 * c2 * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) ) *
rtX . ebokkhvua4 [ 4 ] + ( s_idx_32 - s_idx_31 ) * rtX . ebokkhvua4 [ 3 ] ) +
( ( 0.5 * c1 * ( c2 * c2 ) * ( rtP . Constant_Value [ 26 ] - rtP .
Constant_Value [ 26 ] ) + ( 0.5 * s_idx_27 - 0.5 * s_idx_30 ) ) - 0.5 * c1 *
( s2 * s2 ) * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) )
* rtX . ebokkhvua4 [ 5 ] ) + ( ( 0.5 * c1 * ( c7 * c7 ) * ( rtP .
Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) + ( 0.5 * s_idx_8 - 0.5
* s_idx_11 ) ) - 0.5 * c1 * ( s7 * s7 ) * ( rtP . Constant_Value [ 13 ] - rtP
. Constant_Value [ 13 ] ) ) * rtX . ebokkhvua4 [ 9 ] ) + 0.5 * rtP .
Constant_Value [ 3 ] * c1 * rtX . ebokkhvua4 [ 11 ] ; f [ 68 ] = ( ( ( ( ( (
( - c2 * rtP . Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ] ) *
rtP . Constant_Value [ 2 ] * s2 * rtP . Constant_Value [ 22 ] + rtP .
Constant_Value [ 11 ] * s_idx_12 * s2 * rtP . Constant_Value [ 22 ] ) + ( ( -
rtP . Constant_Value [ 22 ] + rtP . Constant_Value [ 24 ] ) * c2 + s2 * rtP .
Constant_Value [ 25 ] ) * rtP . Constant_Value [ 23 ] * s_idx_24 ) + ( ( 2.0
* rtP . Constant_Value [ 11 ] * s_idx_6 * c2 * rtP . Constant_Value [ 22 ] +
2.0 * s_idx_26 ) + 2.0 * s_idx_25 ) * ( s1 * s1 * 0.5 ) ) - c1 * c1 * c2 * (
rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) * s2 ) * rtX .
ebokkhvua4 [ 3 ] + ( ( 0.5 * c1 * ( c2 * c2 ) * ( rtP . Constant_Value [ 26 ]
- rtP . Constant_Value [ 26 ] ) + ( 0.5 * s_idx_27 - 0.5 * s_idx_30 ) ) - 0.5
* c1 * ( s2 * s2 ) * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [
26 ] ) ) * rtX . ebokkhvua4 [ 4 ] ) + muDoubleScalarSin ( rtX . ebokkhvua4 [
18 ] - rtX . ebokkhvua4 [ 22 ] ) * s1 * so * rtX . ebokkhvua4 [ 5 ] ) + ( -
0.5 * s_idx_4 - 0.5 * s_idx_5 ) * rtX . ebokkhvua4 [ 9 ] ; f [ 81 ] = 0.0 ; f
[ 94 ] = 0.0 ; f [ 107 ] = 0.0 ; f [ 120 ] = ( ( ( ( ( ( - c2 * rtP .
Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ] ) * rtP .
Constant_Value [ 2 ] * s7 * rtP . Constant_Value [ 10 ] - rtP .
Constant_Value [ 11 ] * s_idx_12 * s7 * ( - rtP . Constant_Value [ 10 ] + rtP
. Constant_Value [ 12 ] ) ) + ( 2.0 * s_idx_7 - 2.0 * rtP . Constant_Value [
11 ] * s_idx_6 * c7 * ( - rtP . Constant_Value [ 10 ] + rtP . Constant_Value
[ 12 ] ) ) * ( s1 * s1 * 0.5 ) ) - c1 * c1 * c7 * ( rtP . Constant_Value [ 13
] - rtP . Constant_Value [ 13 ] ) * s7 ) * rtX . ebokkhvua4 [ 3 ] + ( ( 0.5 *
c1 * ( c7 * c7 ) * ( rtP . Constant_Value [ 13 ] - rtP . Constant_Value [ 13
] ) + ( 0.5 * s_idx_8 - 0.5 * s_idx_11 ) ) - 0.5 * c1 * ( s7 * s7 ) * ( rtP .
Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) ) * rtX . ebokkhvua4 [
4 ] ) + ( - 0.5 * s_idx_4 - 0.5 * s_idx_5 ) * rtX . ebokkhvua4 [ 5 ] ) +
muDoubleScalarSin ( rtX . ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * s1
* sm * rtX . ebokkhvua4 [ 9 ] ; f [ 133 ] = 0.0 ; f [ 146 ] = 0.5 * rtP .
Constant_Value [ 3 ] * c1 * rtX . ebokkhvua4 [ 4 ] ; f [ 159 ] = 0.0 ; f [ 4
] = 0.0 ; f [ 17 ] = 0.0 ; f [ 30 ] = 0.0 ; f [ 43 ] = ( ( ( ( ( 0.5 * c1 * (
c2 * c2 ) * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) + -
0.5 * s_idx_30 ) - 0.5 * c1 * ( s2 * s2 ) * ( rtP . Constant_Value [ 26 ] -
rtP . Constant_Value [ 26 ] ) ) - 0.5 * s_idx_27 ) * rtX . ebokkhvua4 [ 5 ] +
( - s_idx_32 + s_idx_31 ) * rtX . ebokkhvua4 [ 3 ] ) + ( ( ( 0.5 * c1 * ( c7
* c7 ) * ( rtP . Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) + -
0.5 * s_idx_11 ) - 0.5 * c1 * ( s7 * s7 ) * ( rtP . Constant_Value [ 13 ] -
rtP . Constant_Value [ 13 ] ) ) - 0.5 * s_idx_8 ) * rtX . ebokkhvua4 [ 9 ] )
- 0.5 * rtP . Constant_Value [ 3 ] * c1 * rtX . ebokkhvua4 [ 11 ] ; f [ 56 ]
= ( ( ( rtP . Constant_Value [ 11 ] * s_idx_6 * c2 * rtP . Constant_Value [
22 ] + s_idx_26 ) + s_idx_25 ) - ( rtP . Constant_Value [ 26 ] - rtP .
Constant_Value [ 26 ] ) * c2 * s2 ) * rtX . ebokkhvua4 [ 5 ] + ( ( s_idx_7 -
rtP . Constant_Value [ 11 ] * s_idx_6 * c7 * ( - rtP . Constant_Value [ 10 ]
+ rtP . Constant_Value [ 12 ] ) ) - ( rtP . Constant_Value [ 13 ] - rtP .
Constant_Value [ 13 ] ) * c7 * s7 ) * rtX . ebokkhvua4 [ 9 ] ; f [ 69 ] = ( (
( 0.5 * c1 * ( c2 * c2 ) * ( rtP . Constant_Value [ 26 ] - rtP .
Constant_Value [ 26 ] ) + - 0.5 * s_idx_30 ) - 0.5 * c1 * ( s2 * s2 ) * ( rtP
. Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) ) - 0.5 * s_idx_27 )
* rtX . ebokkhvua4 [ 3 ] + ( ( ( rtP . Constant_Value [ 11 ] * s_idx_6 * c2 *
rtP . Constant_Value [ 22 ] + s_idx_26 ) + s_idx_25 ) - ( rtP .
Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) * c2 * s2 ) * rtX .
ebokkhvua4 [ 4 ] ; f [ 82 ] = 0.0 ; f [ 95 ] = 0.0 ; f [ 108 ] = 0.0 ; f [
121 ] = ( ( ( 0.5 * c1 * ( c7 * c7 ) * ( rtP . Constant_Value [ 13 ] - rtP .
Constant_Value [ 13 ] ) + - 0.5 * s_idx_11 ) - 0.5 * c1 * ( s7 * s7 ) * ( rtP
. Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) ) - 0.5 * s_idx_8 ) *
rtX . ebokkhvua4 [ 3 ] + ( ( s_idx_7 - rtP . Constant_Value [ 11 ] * s_idx_6
* c7 * ( - rtP . Constant_Value [ 10 ] + rtP . Constant_Value [ 12 ] ) ) - (
rtP . Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) * c7 * s7 ) * rtX
. ebokkhvua4 [ 4 ] ; f [ 134 ] = 0.0 ; f [ 147 ] = - 0.5 * rtP .
Constant_Value [ 3 ] * c1 * rtX . ebokkhvua4 [ 3 ] ; f [ 160 ] = 0.0 ; f [ 5
] = 0.0 ; f [ 18 ] = 0.0 ; f [ 31 ] = 0.0 ; f [ 44 ] = ( ( ( ( ( ( - c2 * rtP
. Constant_Value [ 22 ] - c7 * rtP . Constant_Value [ 10 ] ) * - rtP .
Constant_Value [ 2 ] * s2 * rtP . Constant_Value [ 22 ] - rtP .
Constant_Value [ 11 ] * s_idx_12 * s2 * rtP . Constant_Value [ 22 ] ) - ( ( -
rtP . Constant_Value [ 22 ] + rtP . Constant_Value [ 24 ] ) * c2 + s2 * rtP .
Constant_Value [ 25 ] ) * rtP . Constant_Value [ 23 ] * s_idx_24 ) - ( ( 2.0
* rtP . Constant_Value [ 11 ] * s_idx_6 * c2 * rtP . Constant_Value [ 22 ] +
2.0 * s_idx_26 ) + 2.0 * s_idx_25 ) * ( s1 * s1 * 0.5 ) ) + c1 * c1 * c2 * (
rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) * s2 ) * rtX .
ebokkhvua4 [ 3 ] + ( ( ( 0.5 * s_idx_27 + 0.5 * s_idx_30 ) - 0.5 * c1 * ( c2
* c2 ) * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) ) +
0.5 * c1 * ( s2 * s2 ) * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value
[ 26 ] ) ) * rtX . ebokkhvua4 [ 4 ] ) + ( - 0.5 * s_idx_5 + 0.5 * s_idx_4 ) *
rtX . ebokkhvua4 [ 9 ] ; f [ 57 ] = ( ( ( - s_idx_26 - rtP . Constant_Value [
11 ] * s_idx_6 * c2 * rtP . Constant_Value [ 22 ] ) - s_idx_25 ) + ( rtP .
Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) * c2 * s2 ) * rtX .
ebokkhvua4 [ 4 ] + ( ( ( 0.5 * s_idx_27 + 0.5 * s_idx_30 ) - 0.5 * c1 * ( c2
* c2 ) * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value [ 26 ] ) ) +
0.5 * c1 * ( s2 * s2 ) * ( rtP . Constant_Value [ 26 ] - rtP . Constant_Value
[ 26 ] ) ) * rtX . ebokkhvua4 [ 3 ] ; f [ 70 ] = 0.0 ; f [ 83 ] = 0.0 ; f [
96 ] = 0.0 ; f [ 109 ] = 0.0 ; f [ 122 ] = ( - 0.5 * s_idx_5 + 0.5 * s_idx_4
) * rtX . ebokkhvua4 [ 3 ] + muDoubleScalarSin ( rtX . ebokkhvua4 [ 18 ] -
rtX . ebokkhvua4 [ 22 ] ) * sm * rtX . ebokkhvua4 [ 9 ] ; f [ 135 ] = 0.0 ; f
[ 148 ] = 0.0 ; f [ 161 ] = 0.0 ; f [ 6 ] = 0.0 ; f [ 19 ] = 0.0 ; f [ 32 ] =
0.0 ; f [ 45 ] = 0.0 ; f [ 58 ] = 0.0 ; f [ 71 ] = 0.0 ; f [ 84 ] = ( ( ( ( (
( c6 * rtP . Constant_Value [ 31 ] + s6 * rtP . Constant_Value [ 32 ] ) * rtP
. Constant_Value [ 30 ] * ( - s6 * rtP . Constant_Value [ 31 ] + c6 * rtP .
Constant_Value [ 32 ] ) + rtP . Constant_Value [ 34 ] * s_idx_3 * s_idx_1 ) +
( c6 * rtP . Constant_Value [ 29 ] - s6 * rtX . ebokkhvua4 [ 23 ] ) * rtP .
Constant_Value [ 48 ] * ( - s6 * rtP . Constant_Value [ 29 ] - c6 * rtX .
ebokkhvua4 [ 23 ] ) ) + ( ( 2.0 * s_idx_15 + 2.0 * s_idx_14 ) + 2.0 *
s_idx_13 ) * ( s5 * s5 * 0.5 ) ) - c5 * c5 * c6 * sp * s6 ) * rtX .
ebokkhvua4 [ 8 ] + ( s_idx_23 - s_idx_22 ) * rtX . ebokkhvua4 [ 7 ] ) + ( ( -
rtP . Constant_Value [ 34 ] * s_idx_3 * s6 - ( c6 * rtP . Constant_Value [ 29
] - s6 * rtX . ebokkhvua4 [ 23 ] ) * rtP . Constant_Value [ 48 ] * s6 ) + ( -
2.0 * rtP . Constant_Value [ 34 ] * s_idx_1 * c6 - 2.0 * s_idx_0 ) * ( s5 *
s5 * 0.5 ) ) * rtX . ebokkhvua4 [ 10 ] ; f [ 97 ] = ( ( ( ( ( ( ( ( rtP .
Constant_Value [ 29 ] + rtP . Constant_Value [ 35 ] ) * rtP . Constant_Value
[ 34 ] * ( - rtX . ebokkhvua4 [ 23 ] + rtP . Constant_Value [ 36 ] ) + rtP .
Constant_Value [ 30 ] * rtP . Constant_Value [ 31 ] * rtP . Constant_Value [
32 ] ) - rtP . Constant_Value [ 48 ] * rtP . Constant_Value [ 29 ] * rtX .
ebokkhvua4 [ 23 ] ) * muDoubleScalarCos ( 2.0 * rtX . ebokkhvua4 [ 21 ] ) +
c6 * s6 * s_idx_18 ) * s5 - s5 * s6 * c6 * sp ) * rtX . ebokkhvua4 [ 7 ] + (
s_idx_23 - s_idx_22 ) * rtX . ebokkhvua4 [ 6 ] ) + ( ( 0.5 * c5 * ( c6 * c6 )
* sp + ( 0.5 * s_idx_16 - 0.5 * s_idx_19 ) ) - 0.5 * c5 * ( s6 * s6 ) * sp )
* rtX . ebokkhvua4 [ 8 ] ) + ( 0.5 * c5 * sk - 0.5 * s_idx_2 ) * rtX .
ebokkhvua4 [ 10 ] ) + 0.5 * rtP . Constant_Value [ 49 ] * c5 * rtX .
ebokkhvua4 [ 12 ] ; f [ 110 ] = ( ( ( ( ( ( c6 * rtP . Constant_Value [ 31 ]
+ s6 * rtP . Constant_Value [ 32 ] ) * rtP . Constant_Value [ 30 ] * ( - s6 *
rtP . Constant_Value [ 31 ] + c6 * rtP . Constant_Value [ 32 ] ) + rtP .
Constant_Value [ 34 ] * s_idx_3 * s_idx_1 ) + ( c6 * rtP . Constant_Value [
29 ] - s6 * rtX . ebokkhvua4 [ 23 ] ) * rtP . Constant_Value [ 48 ] * ( - s6
* rtP . Constant_Value [ 29 ] - c6 * rtX . ebokkhvua4 [ 23 ] ) ) + ( ( 2.0 *
s_idx_15 + 2.0 * s_idx_14 ) + 2.0 * s_idx_13 ) * ( s5 * s5 * 0.5 ) ) - c5 *
c5 * c6 * sp * s6 ) * rtX . ebokkhvua4 [ 6 ] + ( ( 0.5 * c5 * ( c6 * c6 ) *
sp + ( 0.5 * s_idx_16 - 0.5 * s_idx_19 ) ) - 0.5 * c5 * ( s6 * s6 ) * sp ) *
rtX . ebokkhvua4 [ 7 ] ) + ( - 2.0 * sf * rtX . ebokkhvua4 [ 23 ] - si ) * (
0.5 * s5 ) * rtX . ebokkhvua4 [ 10 ] ; f [ 123 ] = 0.0 ; f [ 136 ] = ( ( ( -
rtP . Constant_Value [ 34 ] * s_idx_3 * s6 - ( c6 * rtP . Constant_Value [ 29
] - s6 * rtX . ebokkhvua4 [ 23 ] ) * rtP . Constant_Value [ 48 ] * s6 ) + ( -
2.0 * rtP . Constant_Value [ 34 ] * s_idx_1 * c6 - 2.0 * s_idx_0 ) * ( s5 *
s5 * 0.5 ) ) * rtX . ebokkhvua4 [ 6 ] + ( 0.5 * c5 * sk - 0.5 * s_idx_2 ) *
rtX . ebokkhvua4 [ 7 ] ) + ( - 2.0 * sf * rtX . ebokkhvua4 [ 23 ] - si ) * (
0.5 * s5 ) * rtX . ebokkhvua4 [ 8 ] ; f [ 149 ] = 0.0 ; f [ 162 ] = 0.5 * rtP
. Constant_Value [ 49 ] * c5 * rtX . ebokkhvua4 [ 7 ] ; f [ 7 ] = 0.0 ; f [
20 ] = 0.0 ; f [ 33 ] = 0.0 ; f [ 46 ] = 0.0 ; f [ 59 ] = 0.0 ; f [ 72 ] =
0.0 ; f [ 85 ] = ( ( ( ( ( 0.5 * c5 * ( c6 * c6 ) * sp + - 0.5 * s_idx_19 ) -
0.5 * c5 * ( s6 * s6 ) * sp ) - 0.5 * s_idx_16 ) * rtX . ebokkhvua4 [ 8 ] + (
- s_idx_23 + s_idx_22 ) * rtX . ebokkhvua4 [ 6 ] ) + ( - 0.5 * s_idx_2 - 0.5
* c5 * sk ) * rtX . ebokkhvua4 [ 10 ] ) - 0.5 * rtP . Constant_Value [ 49 ] *
c5 * rtX . ebokkhvua4 [ 12 ] ; f [ 98 ] = ( ( ( s_idx_15 + s_idx_14 ) +
s_idx_13 ) + c6 * sp * s6 ) * rtX . ebokkhvua4 [ 8 ] + ( - rtP .
Constant_Value [ 34 ] * s_idx_1 * c6 - s_idx_0 ) * rtX . ebokkhvua4 [ 10 ] ;
f [ 111 ] = ( ( ( 0.5 * c5 * ( c6 * c6 ) * sp + - 0.5 * s_idx_19 ) - 0.5 * c5
* ( s6 * s6 ) * sp ) - 0.5 * s_idx_16 ) * rtX . ebokkhvua4 [ 6 ] + ( ( (
s_idx_15 + s_idx_14 ) + s_idx_13 ) + c6 * sp * s6 ) * rtX . ebokkhvua4 [ 7 ]
; f [ 124 ] = 0.0 ; f [ 137 ] = ( - 0.5 * s_idx_2 - 0.5 * c5 * sk ) * rtX .
ebokkhvua4 [ 6 ] + ( - rtP . Constant_Value [ 34 ] * s_idx_1 * c6 - s_idx_0 )
* rtX . ebokkhvua4 [ 7 ] ; f [ 150 ] = 0.0 ; f [ 163 ] = - 0.5 * rtP .
Constant_Value [ 49 ] * c5 * rtX . ebokkhvua4 [ 6 ] ; f [ 8 ] = 0.0 ; f [ 21
] = 0.0 ; f [ 34 ] = 0.0 ; f [ 47 ] = 0.0 ; f [ 60 ] = 0.0 ; f [ 73 ] = 0.0 ;
f [ 86 ] = ( ( ( ( ( ( c6 * rtP . Constant_Value [ 31 ] + s6 * rtP .
Constant_Value [ 32 ] ) * - rtP . Constant_Value [ 30 ] * ( - s6 * rtP .
Constant_Value [ 31 ] + c6 * rtP . Constant_Value [ 32 ] ) - rtP .
Constant_Value [ 34 ] * s_idx_3 * s_idx_1 ) - ( c6 * rtP . Constant_Value [
29 ] - s6 * rtX . ebokkhvua4 [ 23 ] ) * rtP . Constant_Value [ 48 ] * ( - s6
* rtP . Constant_Value [ 29 ] - c6 * rtX . ebokkhvua4 [ 23 ] ) ) - ( ( 2.0 *
s_idx_15 + 2.0 * s_idx_14 ) + 2.0 * s_idx_13 ) * ( s5 * s5 * 0.5 ) ) + c5 *
c5 * c6 * sp * s6 ) * rtX . ebokkhvua4 [ 6 ] + ( ( ( 0.5 * s_idx_16 + 0.5 *
s_idx_19 ) - 0.5 * c5 * ( c6 * c6 ) * sp ) + 0.5 * c5 * ( s6 * s6 ) * sp ) *
rtX . ebokkhvua4 [ 7 ] ) + ( - 2.0 * sf * rtX . ebokkhvua4 [ 23 ] - si ) * (
0.5 * s5 ) * rtX . ebokkhvua4 [ 10 ] ; f [ 99 ] = ( ( ( 0.5 * s_idx_16 + 0.5
* s_idx_19 ) - 0.5 * c5 * ( c6 * c6 ) * sp ) + 0.5 * c5 * ( s6 * s6 ) * sp )
* rtX . ebokkhvua4 [ 6 ] + ( ( ( - s_idx_15 - s_idx_14 ) - s_idx_13 ) - c6 *
sp * s6 ) * rtX . ebokkhvua4 [ 7 ] ; f [ 112 ] = ( - sf * rtX . ebokkhvua4 [
23 ] - 0.5 * si ) * rtX . ebokkhvua4 [ 10 ] ; f [ 125 ] = 0.0 ; f [ 138 ] = (
- 2.0 * sf * rtX . ebokkhvua4 [ 23 ] - si ) * ( 0.5 * s5 ) * rtX . ebokkhvua4
[ 6 ] + ( - sf * rtX . ebokkhvua4 [ 23 ] - 0.5 * si ) * rtX . ebokkhvua4 [ 8
] ; f [ 151 ] = 0.0 ; f [ 164 ] = 0.0 ; f [ 9 ] = 0.0 ; f [ 22 ] = 0.0 ; f [
35 ] = 0.0 ; f [ 48 ] = ( ( ( ( ( - c2 * rtP . Constant_Value [ 22 ] - c7 *
rtP . Constant_Value [ 10 ] ) * - rtP . Constant_Value [ 2 ] * s7 * rtP .
Constant_Value [ 10 ] + rtP . Constant_Value [ 11 ] * s_idx_12 * s7 * ( - rtP
. Constant_Value [ 10 ] + rtP . Constant_Value [ 12 ] ) ) - ( 2.0 * s_idx_7 -
2.0 * rtP . Constant_Value [ 11 ] * s_idx_6 * c7 * ( - rtP . Constant_Value [
10 ] + rtP . Constant_Value [ 12 ] ) ) * ( s1 * s1 * 0.5 ) ) + c1 * c1 * c7 *
( rtP . Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) * s7 ) * rtX .
ebokkhvua4 [ 3 ] + ( ( ( 0.5 * s_idx_8 + 0.5 * s_idx_11 ) - 0.5 * c1 * ( c7 *
c7 ) * ( rtP . Constant_Value [ 13 ] - rtP . Constant_Value [ 13 ] ) ) + 0.5
* c1 * ( s7 * s7 ) * ( rtP . Constant_Value [ 13 ] - rtP . Constant_Value [
13 ] ) ) * rtX . ebokkhvua4 [ 4 ] ) + ( - 0.5 * s_idx_4 + 0.5 * s_idx_5 ) *
rtX . ebokkhvua4 [ 5 ] ; f [ 61 ] = ( ( ( 0.5 * s_idx_8 + 0.5 * s_idx_11 ) -
0.5 * c1 * ( c7 * c7 ) * ( rtP . Constant_Value [ 13 ] - rtP . Constant_Value
[ 13 ] ) ) + 0.5 * c1 * ( s7 * s7 ) * ( rtP . Constant_Value [ 13 ] - rtP .
Constant_Value [ 13 ] ) ) * rtX . ebokkhvua4 [ 3 ] + ( ( rtP . Constant_Value
[ 11 ] * s_idx_6 * c7 * ( - rtP . Constant_Value [ 10 ] + rtP .
Constant_Value [ 12 ] ) + - s_idx_7 ) + ( rtP . Constant_Value [ 13 ] - rtP .
Constant_Value [ 13 ] ) * c7 * s7 ) * rtX . ebokkhvua4 [ 4 ] ; f [ 74 ] = ( -
0.5 * s_idx_4 + 0.5 * s_idx_5 ) * rtX . ebokkhvua4 [ 3 ] - muDoubleScalarSin
( rtX . ebokkhvua4 [ 18 ] - rtX . ebokkhvua4 [ 22 ] ) * sm * rtX . ebokkhvua4
[ 5 ] ; f [ 87 ] = 0.0 ; f [ 100 ] = 0.0 ; f [ 113 ] = 0.0 ; f [ 126 ] = 0.0
; f [ 139 ] = 0.0 ; f [ 152 ] = 0.0 ; f [ 165 ] = 0.0 ; f [ 10 ] = 0.0 ; f [
23 ] = 0.0 ; f [ 36 ] = 0.0 ; f [ 49 ] = 0.0 ; f [ 62 ] = 0.0 ; f [ 75 ] =
0.0 ; f [ 88 ] = ( ( ( ( c6 * rtP . Constant_Value [ 29 ] - s6 * rtX .
ebokkhvua4 [ 23 ] ) * rtP . Constant_Value [ 48 ] * s6 + rtP . Constant_Value
[ 34 ] * s_idx_3 * s6 ) - ( - 2.0 * rtP . Constant_Value [ 34 ] * s_idx_1 *
c6 - 2.0 * s_idx_0 ) * ( s5 * s5 * 0.5 ) ) * rtX . ebokkhvua4 [ 6 ] + ( 0.5 *
c5 * sk + 0.5 * s_idx_2 ) * rtX . ebokkhvua4 [ 7 ] ) - ( - 2.0 * sf * rtX .
ebokkhvua4 [ 23 ] - si ) * ( 0.5 * s5 ) * rtX . ebokkhvua4 [ 8 ] ; f [ 101 ]
= ( 0.5 * c5 * sk + 0.5 * s_idx_2 ) * rtX . ebokkhvua4 [ 6 ] + ( rtP .
Constant_Value [ 34 ] * s_idx_1 * c6 + s_idx_0 ) * rtX . ebokkhvua4 [ 7 ] ; f
[ 114 ] = ( - 2.0 * sf * rtX . ebokkhvua4 [ 23 ] - si ) * ( - 0.5 * s5 ) *
rtX . ebokkhvua4 [ 6 ] + ( sf * rtX . ebokkhvua4 [ 23 ] + 0.5 * si ) * rtX .
ebokkhvua4 [ 8 ] ; f [ 127 ] = 0.0 ; f [ 140 ] = 0.0 ; f [ 153 ] = 0.0 ; f [
166 ] = 0.0 ; f [ 11 ] = 0.0 ; f [ 24 ] = 0.0 ; f [ 37 ] = 0.0 ; f [ 50 ] =
0.5 * rtP . Constant_Value [ 3 ] * c1 * rtX . ebokkhvua4 [ 4 ] ; f [ 63 ] =
0.5 * rtP . Constant_Value [ 3 ] * c1 * rtX . ebokkhvua4 [ 3 ] ; f [ 76 ] =
0.0 ; f [ 89 ] = 0.0 ; f [ 102 ] = 0.0 ; f [ 115 ] = 0.0 ; f [ 128 ] = 0.0 ;
f [ 141 ] = 0.0 ; f [ 154 ] = 0.0 ; f [ 167 ] = 0.0 ; f [ 12 ] = 0.0 ; f [ 25
] = 0.0 ; f [ 38 ] = 0.0 ; f [ 51 ] = 0.0 ; f [ 64 ] = 0.0 ; f [ 77 ] = 0.0 ;
f [ 90 ] = 0.5 * rtP . Constant_Value [ 49 ] * c5 * rtX . ebokkhvua4 [ 7 ] ;
f [ 103 ] = 0.5 * rtP . Constant_Value [ 49 ] * c5 * rtX . ebokkhvua4 [ 6 ] ;
f [ 116 ] = 0.0 ; f [ 129 ] = 0.0 ; f [ 142 ] = 0.0 ; f [ 155 ] = 0.0 ; f [
168 ] = 0.0 ; for ( i = 0 ; i < 13 ; i ++ ) { T3_idx_2 = 0.0 ; for ( i_p = 0
; i_p < 13 ; i_p ++ ) { T3_idx_2 += f [ 13 * i_p + i ] * rtX . ebokkhvua4 [
i_p ] ; } rtB . eo520ybntx [ i ] = ( ( ( ( ( ( ( ( ( ( ( ( tmp [ i ] + tmp_p
[ i ] ) + tmp_e [ i ] ) + tmp_i [ i ] ) + tmp_m [ i ] ) + tmp_g [ i ] ) +
tmp_j [ i ] ) + s4_e [ i ] ) + c4_p [ i ] ) + c0_p [ i ] ) + s0_i [ i ] ) +
tmp_f [ i ] ) + tmp_c [ i ] ) - T3_idx_2 ; } dqlqqdeg5m ( M , rtB .
eo520ybntx ) ; rtB . c2cdlswd3o = R0_m ; rtB . g1ydvsawaf = g_a ; rtB .
gzzkcchteh = q_a ; rtB . jouoe1n5vx = hxhenfzed1_idx_1 ; rtB . av1aqzwqnf = (
c0 * r0d_idx_0 + s0 * r0d_idx_1 ) + 0.01 ; rtB . ar1tujojgx = - s0 *
r0d_idx_0 + c0 * r0d_idx_1 ; rtB . erdq10rudk = ( c4 * r7d_idx_0 + s4 *
r7d_idx_1 ) + 0.01 ; rtB . oqfsbxli0j = - s4 * r7d_idx_0 + c4 * r7d_idx_1 ;
for ( i = 0 ; i < 13 ; i ++ ) { rtB . imnuhe3fbk [ i ] = rtB . eo520ybntx [ i
] ; rtB . imnuhe3fbk [ i + 13 ] = rtX . ebokkhvua4 [ i ] ; } UNUSED_PARAMETER
( tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; memcpy ( & _rtXdot -> me5fddqwzm [ 0 ] , & rtB . jrd3qvs43k [ 0 ] ,
13U * sizeof ( real_T ) ) ; memcpy ( & _rtXdot -> oxmouqfknt [ 0 ] , & rtB .
eo520ybntx [ 0 ] , 13U * sizeof ( real_T ) ) ; memcpy ( & _rtXdot ->
ebokkhvua4 [ 0 ] , & rtB . imnuhe3fbk [ 0 ] , 26U * sizeof ( real_T ) ) ; }
void MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV *
_rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV
-> ghwxcapcay = rtB . cp0ppvbbhm - rtP . tout [ 499 ] ; } void MdlTerminate (
void ) { rt_FREE ( rtDW . pncnv031ra . RSimInfoPtr ) ; rt_FREE ( rtDW .
goekygpgcg . RSimInfoPtr ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void *
* slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 52 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 27 ) ; ssSetNumBlockIO ( rtS , 15 ) ;
ssSetNumBlockParams ( rtS , 2614 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.001 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2747836835U ) ;
ssSetChecksumVal ( rtS , 1 , 2016987222U ) ; ssSetChecksumVal ( rtS , 2 ,
2843745027U ) ; ssSetChecksumVal ( rtS , 3 , 3167016773U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; { int32_T i ; for ( i = 0 ; i < 13 ; i ++ ) { rtB .
f2bv4a4pox [ i ] = 0.0 ; } for ( i = 0 ; i < 13 ; i ++ ) { rtB . jrd3qvs43k [
i ] = 0.0 ; } for ( i = 0 ; i < 13 ; i ++ ) { rtB . eo520ybntx [ i ] = 0.0 ;
} for ( i = 0 ; i < 26 ; i ++ ) { rtB . imnuhe3fbk [ i ] = 0.0 ; } rtB .
cp0ppvbbhm = 0.0 ; rtB . c2cdlswd3o = 0.0 ; rtB . g1ydvsawaf = 0.0 ; rtB .
gzzkcchteh = 0.0 ; rtB . jouoe1n5vx = 0.0 ; rtB . av1aqzwqnf = 0.0 ; rtB .
ar1tujojgx = 0.0 ; rtB . erdq10rudk = 0.0 ; rtB . oqfsbxli0j = 0.0 ; rtB .
ccaozxlshh [ 0 ] = 0.0 ; rtB . ccaozxlshh [ 1 ] = 0.0 ; rtB . ccaozxlshh [ 2
] = 0.0 ; rtB . ff31rlfzs2 [ 0 ] = 0.0 ; rtB . ff31rlfzs2 [ 1 ] = 0.0 ; rtB .
ff31rlfzs2 [ 2 ] = 0.0 ; } } { real_T * x = ( real_T * ) & rtX ;
ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X
) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ;
( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo
dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 15 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } motorcycle_model_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"motorcycle_model" ) ; ssSetPath ( rtS , "motorcycle_model" ) ; ssSetTStart (
rtS , 0.0 ) ; ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 13 , 13 , 26 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 13 , 13 , 26 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"motorcycle_model/Subsystem/simulink model/Integrator1" ,
"motorcycle_model/Subsystem/simulink model/Integrator" ,
"motorcycle_model/Subsystem/simulink model/Integrator2" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 3 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 3 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . me5fddqwzm [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . oxmouqfknt [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ebokkhvua4 [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 52 ] ; static
real_T absTol [ 52 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6
, 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 52 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static uint8_T
zcAttributes [ 1 ] = { ( ZC_EVENT_ALL ) } ; static real_T outputTimes [ 201 ]
= { 0.0 , 0.05 , 0.1 , 0.15000000000000002 , 0.2 , 0.25 , 0.30000000000000004
, 0.35000000000000003 , 0.4 , 0.45 , 0.5 , 0.55 , 0.60000000000000009 , 0.65
, 0.70000000000000007 , 0.75 , 0.8 , 0.85000000000000009 , 0.9 ,
0.95000000000000007 , 1.0 , 1.05 , 1.1 , 1.1500000000000001 ,
1.2000000000000002 , 1.25 , 1.3 , 1.35 , 1.4000000000000001 ,
1.4500000000000002 , 1.5 , 1.55 , 1.6 , 1.6500000000000001 ,
1.7000000000000002 , 1.75 , 1.8 , 1.85 , 1.9000000000000001 ,
1.9500000000000002 , 2.0 , 2.0500000000000003 , 2.1 , 2.15 , 2.2 , 2.25 ,
2.3000000000000003 , 2.35 , 2.4000000000000004 , 2.45 , 2.5 ,
2.5500000000000003 , 2.6 , 2.6500000000000004 , 2.7 , 2.75 ,
2.8000000000000003 , 2.85 , 2.9000000000000004 , 2.95 , 3.0 ,
3.0500000000000003 , 3.1 , 3.1500000000000004 , 3.2 , 3.25 ,
3.3000000000000003 , 3.35 , 3.4000000000000004 , 3.45 , 3.5 ,
3.5500000000000003 , 3.6 , 3.6500000000000004 , 3.7 , 3.75 ,
3.8000000000000003 , 3.85 , 3.9000000000000004 , 3.95 , 4.0 , 4.05 ,
4.1000000000000005 , 4.15 , 4.2 , 4.25 , 4.3 , 4.3500000000000005 , 4.4 ,
4.45 , 4.5 , 4.55 , 4.6000000000000005 , 4.65 , 4.7 , 4.75 ,
4.8000000000000007 , 4.8500000000000005 , 4.9 , 4.95 , 5.0 , 5.05 , 5.1 ,
5.1499999999999995 , 5.1999999999999993 , 5.25 , 5.3 , 5.35 ,
5.3999999999999995 , 5.45 , 5.5 , 5.55 , 5.6 , 5.6499999999999995 , 5.7 ,
5.75 , 5.8 , 5.85 , 5.8999999999999995 , 5.95 , 6.0 , 6.05 , 6.1 , 6.15 ,
6.1999999999999993 , 6.25 , 6.3 , 6.35 , 6.4 , 6.4499999999999993 , 6.5 ,
6.55 , 6.6 , 6.65 , 6.6999999999999993 , 6.75 , 6.8 , 6.85 , 6.9 ,
6.9499999999999993 , 7.0 , 7.05 , 7.1 , 7.15 , 7.1999999999999993 , 7.25 ,
7.3 , 7.35 , 7.4 , 7.4499999999999993 , 7.5 , 7.55 , 7.6 , 7.65 ,
7.6999999999999993 , 7.75 , 7.8 , 7.85 , 7.9 , 7.9499999999999993 , 8.0 ,
8.05 , 8.1 , 8.15 , 8.2 , 8.25 , 8.3 , 8.35 , 8.4 , 8.45 , 8.5 , 8.55 , 8.6 ,
8.65 , 8.7 , 8.75 , 8.8 , 8.85 , 8.9 , 8.95 , 9.0 , 9.05 , 9.1 , 9.15 , 9.2 ,
9.25 , 9.3 , 9.35 , 9.4 , 9.45 , 9.5 , 9.55 , 9.6 , 9.65 , 9.7 , 9.75 , 9.8 ,
9.85 , 9.9 , 9.95 , 10.0 } ; ssSetSolverRelTol ( rtS , 0.001 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.001 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , outputTimes )
; ssSetNumOutputTimes ( rtS , 201 ) ; ssSetOutputTimesOnly ( rtS , 1 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver (
rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 1 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 1 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2747836835U ) ; ssSetChecksumVal ( rtS , 1 ,
2016987222U ) ; ssSetChecksumVal ( rtS , 2 , 2843745027U ) ; ssSetChecksumVal
( rtS , 3 , 3167016773U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 2 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
