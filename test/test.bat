@echo off
setlocal

REM 
gcc -I.. ../src/hash.c ../src/randomindex.c ../src/wordcheck.c ../src/color.c testcolor.c testwordcheck.c testhash.c testrandom.c maintest.c -o maintest 
if %errorlevel% neq 0 (
    echo Compilation failed
    exit /b %errorlevel%
)

REM 
maintest.exe

endlocal