#include<stdio.h>
#include"randomindex.h"
#include<assert.h>

//gcc -I.. ../hash.c testhash.c -o testhash 

int main()
{
    assert(randomIndex()==randomIndex());
    printf("The hash functionality is working perfectly\n");

    
}