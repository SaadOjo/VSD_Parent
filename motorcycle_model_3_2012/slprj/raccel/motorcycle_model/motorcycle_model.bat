@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\VCVARSALL.BAT " amd64

call  "\\SAAD-PC\D$\Program Files\MATLAB\R2018b\bin\win64\checkMATLABRootForDriveMap.exe" "\\SAAD-PC\D$\Program Files\MATLAB\R2018b"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n

cd .
nmake -f motorcycle_model.mk MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  MODELLIB=motorcycle_modellib.lib RSIM_SOLVER_SELECTION=2 EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 MODELREF_TARGET_TYPE=NONE ISPROTECTINGMODEL=NOTPROTECTING OPTS="-DTGTCONN -DEXT_MODE -DON_TARGET_WAIT_FOR_START=0"
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
