#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "wordcheck.h"
#include "hash.h"
// #include "capitalize.h"


// validate that the given string is an alphabet
int checkAlpha(char *str) {

    if (str == NULL || str[0] == '\0') {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;

}

// simple check to see if the word is correct or invalid or partially correct
int wordCheck(char *word, char *guess) {

    if (((guess) == NULL) || (checkAlpha(guess)==0)  || (strlen(word) != strlen(guess))) {
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
//     hashfunction(wordList, isAvailable);

//     printf("%d\n", isAvailable[hashfunction2("hello")]);

//     // printf("%d\n", wordCheck("hEllo", "hello"));
//     // printf("%d\n", wordCheck("hello", "hello"));
//     // printf("%d\n", wordCheck("hello", "hellA"));
//     // printf("%d\n", wordCheck("hello", "hellaqqq"));
//     // printf("%d\n", wordCheck("hello", "\0"));
//     // printf("%d\n", wordCheck("hello", ""));
//     // printf("%d\n", wordCheck("hello", NULL));
//     // printf("%d\n", wordCheck("hello", "hell1"));
//     // printf("%d\n", wordCheck("hello", "hell "));
    
//     return 0;
// }