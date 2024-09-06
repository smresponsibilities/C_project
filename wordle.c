
#include <stdio.h>
#include <stdlib.h>
#include"include/randomindex.h"
#include"include/wordcheck.h"
#include<string.h>
#include<ctype.h>
#include "include/hash.h"
#include "include/color.h"


#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_RESET "\033[0m"


int main() {
    extern char *wordList[];
    extern int randomIndex();
    extern bool isAvailable[];

    char wordToGuess[6];
    char *randomWord = wordList[randomIndex()];


    for (int i = 0; i < 5; i++) {
        wordToGuess[i] = toupper(randomWord[i]);
    }
    wordToGuess[5] = '\0';


    char input[1000];
    char fiveLetterStrings[6][6];
    char colors[6][6];
    char alphabetColors[26] = {0};
    int result;
    int i = 0;

    hashfunction(wordList, isAvailable);

    printf("Welcome to Wordle!\n");
    printf("About Wordle, it is a word guessing game. There is a single word to guess for the whole day.\n");
    printf("You have 6 tries to guess a 5 letter word. We also provide you the hints to make it easier for you to guess the word.\n");  
    printf("The hints are as follows: \n");
    printf(COLOR_GREEN "Green" COLOR_RESET ": The letter is present in the word and is in the correct position." "\n");
    printf(COLOR_YELLOW "Yellow" COLOR_RESET": The letter is present in the word but is not in the correct position.\n");
    printf(COLOR_RED "Red" COLOR_RESET": The letter is not present in the word.\n");
    printf("Also to make it more easier for you, we will also color the characters of alphabets you have used.\n");


    printf("\n");

    do {
        printf("Enter a 5 letter word: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error while getting input.\n");
            continue;
        }


        input[strcspn(input, "\n")] = '\0';

        printf("\n");


        if (strlen(input) != 5) {
            for (int j = 0; j <= i-1; j++) {
                printColoredWord(fiveLetterStrings[j], colors[j]);
            }
            printf("Number of tries still left: %d\n", 5-i);
            printf("\n");

            
            printf("Please enter an appropriate word containing 5 letters.\n");
            printf("\n");
            printAtoz(alphabetColors);
            printf("\n");
            continue;
        }

        if  (isAvailable[hashfunction2(input)]==0){
            for (int j = 0; j <= i-1; j++) {
                printColoredWord(fiveLetterStrings[j], colors[j]);
            }

            
            printf("Number of tries still left: %d\n", 5-i);
            printf("\n");
            printf("Word is not present in our dictionary.\n");
            printf("\n");
            printAtoz(alphabetColors);
            printf("\n");
            
            continue;
        }

        result = wordCheck(wordToGuess, input);

        

        if (result != 0) {
            for (int k = 0; input[k] != '\0'; k++) {
                input[k] = toupper(input[k]);
            }
            printf("Number of tries left: %d\n", 5-i);
            printf("\n");

            strcpy(fiveLetterStrings[i], input);
            fiveLetterStrings[i][5] = '\0'; // Null-terminate the string

            wordColoring(wordToGuess, fiveLetterStrings[i], colors[i]);
            updateAtozcolors(fiveLetterStrings[i], colors[i], alphabetColors);


            for (int j = 0; j <= i; j++) {
                printColoredWord(fiveLetterStrings[j], colors[j]);
            }

            printf("\n");
            printAtoz(alphabetColors);

            i++;
            if(result==2){
                printf("Congratulations! You have guessed the word.\n");
                break;
            } 

            if (i == 6) {
                printf("You have unfornately run out of tries. Maybe play again to guess the word.\n", wordToGuess);
                break;
            }
        }
        printf("\n");
    } while (1);

    return 0;
}