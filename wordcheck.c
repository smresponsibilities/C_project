#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
// #include "capitalize.h"

int wordCheck(char *word, char *guess) {
    if (((guess) == NULL) || (strlen(word) != strlen(guess))) {
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (tolower((unsigned char)word[i]) != tolower((unsigned char)guess[i])) {
            return 1;
        }
    }
    return 2;

}



// int main() {
//     printf("%d\n", wordCheck("hEllo", "hello"));
//     printf("%d\n", wordCheck("hello", "hellA"));
//     printf("%d\n", wordCheck("hello", "hellaqqq"));
//     printf("%d\n", wordCheck("hello", "\0"));
//     printf("%d\n", wordCheck("hello", ""));
//     printf("%d\n", wordCheck("hello", NULL));
    
//     return 0;
// }