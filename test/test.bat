@echo off
setlocal

REM 
gcc -I.. ..\hash.c testhash.c -o testhash.exe
if %errorlevel% neq 0 (
    echo Compilation failed
    exit /b %errorlevel%
)

REM 
testhash.exe

endlocal