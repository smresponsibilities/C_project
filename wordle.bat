@echo off
REM
gcc wordle.c src\randomindex.c src\wordcheck.c src\hash.c src\color.c -Iinclude -o wordle.exe -lm

REM
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
)

REM 
wordle.exe