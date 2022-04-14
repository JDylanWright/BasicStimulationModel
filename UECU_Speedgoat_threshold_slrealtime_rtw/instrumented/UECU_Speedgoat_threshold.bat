
call "%SLREALTIME_QNX_SP_ROOT%\qnx700\qnxsdp-env.bat"

cd .

if "%1"=="" (make  -f UECU_Speedgoat_threshold.mk all) else (make  -f UECU_Speedgoat_threshold.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1