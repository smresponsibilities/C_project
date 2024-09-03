
#include <stdio.h>
#include <stdlib.h>
#include"randomindex.h"
#include"wordcheck.h"
#include<string.h>
#include<ctype.h>
#include "hash.h"

int main(){


    printf("Random : %d\n", randomIndex());
    int result = 0;
    char input[10000];
    char * wordToGuess = wordList[randomIndex()];


    do {
        printf("Enter a word: ");
        scanf("%s", input);
        printf("%d\n", strlen(input));
        printf("%d\n", strlen(wordToGuess));
        printf("%s\n", wordToGuess);
        result = wordCheck(wordToGuess, input);
        printf("%d\n", result);
    } while (result != 2);

    return 0;
}