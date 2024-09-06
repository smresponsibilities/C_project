#include <stdio.h>
#include "testhash.h"
#include "testrandom.h"
#include "testwordcheck.h"
// gcc -I.. ../hash.c testhash.c  maintest.c -o testhash 
// gcc -I.. ../hash.c ../randomindex.c testhash.c testrandom.c maintest.c -o maintest 

int main() {

    testHash();
    testRandom();
    testCheckAlpha();    
    testWordCheck();


    return 0;
}