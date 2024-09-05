
#include <stdio.h>
#include <stdlib.h>
#include"randomindex.h"
#include"wordcheck.h"
#include<string.h>
#include<ctype.h>
#include "hash.h"
#include "color.h"


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

    // Convert the random word to uppercase and assign to wordToGuess
    for (int i = 0; i < 5; i++) {
        wordToGuess[i] = toupper(randomWord[i]);
    }
    wordToGuess[5] = '\0'; // Null-terminate the string

    printf("Word to guess: %s\n", wordToGuess);
    char input[1000];
    char fiveLetterStrings[6][6];
    char colors[6][6];
    char alphabetColors[26] = {0}; // Initialize all to 0 (no color)
    int result;
    int i = 0;
    hashfunction(wordList, isAvailable);

    do {
        printf("Enter a word: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        // Remove newline character if present
        input[strcspn(input, "\n")] = '\0';

        // Check if the input length is exactly 5 characters
        if (strlen(input) != 5) {
                        for (int j = 0; j <= i; j++) {
                printColoredWord(fiveLetterStrings[j], colors[j]);
            }

            printAtoz(alphabetColors);
            printf("Please enter a 5-letter word.\n");
            continue;
        }

        if  (isAvailable[hashfunction2(input)]==0){
            for (int j = 0; j <= i; j++) {
                printColoredWord(fiveLetterStrings[j], colors[j]);
            }

            printAtoz(alphabetColors);

            printf("Word not in the dictionary\n");
            continue;
        }

        result = wordCheck(wordToGuess, input);
        printf("Result: %d\n", result);
        

        if (result != 0) {
            for (int k = 0; input[k] != '\0'; k++) {
                input[k] = toupper(input[k]);
            }
            printf("Result: %d\n", result);

            strcpy(fiveLetterStrings[i], input);
            fiveLetterStrings[i][5] = '\0'; // Null-terminate the string

             wordColoring(wordToGuess, fiveLetterStrings[i], colors[i]);
            updateAtozcolors(fiveLetterStrings[i], colors[i], alphabetColors);

            // Print all previous guesses with colors
            for (int j = 0; j <= i; j++) {
                printColoredWord(fiveLetterStrings[j], colors[j]);
            }

            // Print the alphabet with colors
            printAtoz(alphabetColors);

            i++;
            if(result==2){
                printf("Congratulations! You have guessed the word.\n");
                break;
            } // Increment i after processing the current guess

            if (i == 6) {
                break;
            }
        }
        printf("\n");
    } while (1);

    return 0;
}