#include<stdio.h>
#include "../include/hash.h"
#include <assert.h>
#include "testhash.h"

//gcc -I.. ../hash.c testhash.c -o testhash 

void testHash() {
    hashfunction(wordList,isAvailable);
    int e=0;

    for (long long i = 0; i <=6999999; i++) {
        if (isAvailable[i])e++;
    }

    assert(e==9077);
    printf("The hash functionality is working perfectly\n");

    
}