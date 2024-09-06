#include <stdio.h>
#include <assert.h>
#include "wordcheck.h"
#include "testwordcheck.h"


void testCheckAlpha() {
    assert(checkAlpha("hello") == 1);
    assert(checkAlpha("Hello") == 1);
    assert(checkAlpha("HELLO") == 1);
    assert(checkAlpha("hello123") == 0);
    assert(checkAlpha("hello world") == 0);
    assert(checkAlpha("") == 0);
    assert(checkAlpha(NULL) == 0);
    printf("The alphabet validating functionality is working perfectly\n");
}

void testWordCheck() {
    assert(wordCheck("hello", "hello") == 2);
    assert(wordCheck("hello", "hEllo") == 2);
    assert(wordCheck("hello", "hella") == 1);
    assert(wordCheck("hello", "hell") == 0);
    assert(wordCheck("hello", "helloo") == 0);
    assert(wordCheck("hello", "hell1") == 0);
    assert(wordCheck("hello", "hell ") == 0);
    assert(wordCheck("hello", "") == 0);
    assert(wordCheck("hello", NULL) == 0);
    printf("The simple word check functionality is working perfectly\n");
}


// int main() {
//     testCheckAlpha();
//     testWordCheck();
//     return 0;
// }