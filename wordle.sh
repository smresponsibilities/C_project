#!/bin/bash

gcc wordle.c src/randomindex.c src/wordcheck.c src/hash.c src/color.c -Iinclude -o wordle -lm

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

./wordle