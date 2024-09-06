#include<stdio.h>
#include"../include/randomindex.h"
#include<assert.h>
#include"testrandom.h"

//gcc -I.. ../hash.c testhash.c -o testhash 


void testRandom()
{
    assert(randomIndex()==randomIndex());
    printf("The random functionality is working perfectly\n");

    
}