@echo off
setlocal

REM 
gcc -I.. ../hash.c ../randomindex.c testhash.c testrandom.c maintest.c -o maintest 
if %errorlevel% neq 0 (
    echo Compilation failed
    exit /b %errorlevel%
)

REM 
maintest.exe

endlocal