
call "%SLREALTIME_QNX_SP_ROOT%\qnx700\qnxsdp-env.bat"

cd .

if "%1"=="" (make  -f SimpleStim.mk all) else (make  -f SimpleStim.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1