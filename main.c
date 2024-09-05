
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
    char fiveLetterStrings[5][6];
    int i = 0;


    do {
        printf("Enter a word: ");
        scanf("%s", input);
        // printf("%d\n", strlen(input));
        // printf("%d\n", strlen(wordToGuess));
        // printf("%s\n", wordToGuess);
        result = wordCheck(wordToGuess, input);
        if (result != 0) {

            for (int k = 0; input[k] != '\0'; k++) {
                input[k] = toupper(input[k]);
            }
            
            strcpy(fiveLetterStrings[i], input);
            i++;
        }

    for (int j = 0; j < i; j++) {
        printf("%s\n", fiveLetterStrings[j]);
    }
    if (i == 5) {
        break;
    }
    printf("\n");

    } while (result != 2 && i < 5);

    return 0;
}