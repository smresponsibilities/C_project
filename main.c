
#include <stdio.h>
#include <stdlib.h>
#include"randomindex.h"
#include"wordcheck.h"
#include<string.h>
#include<ctype.h>
#include "hash.h"

#define WORD_LENGTH 5
#define MAX_GUESSES 6
// Color macros
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_RESET "\033[0m"

void determineColors(  char *wordToGuess,   char *input, char colors[]) {
    int letterCount[26] = {0};
    int len = strlen(wordToGuess);

    // Count the occurrences of each letter in the word to guess
    for (int i = 0; i < len; i++) {
        letterCount[wordToGuess[i] - 'A']++;
    }

    // First pass: mark correct positions (green)
    for (int i = 0; i < len; i++) {
        if (input[i] == wordToGuess[i]) {
            colors[i] = 'G'; // Green for correct position
            letterCount[input[i] - 'A']--;
        } else {
            colors[i] = ' ';
        }
    }

    // Second pass: mark correct letters in wrong positions (yellow) and incorrect letters (red)
    for (int i = 0; i < len; i++) {
        if (colors[i] != 'G') {
            if (letterCount[input[i] - 'A'] > 0) {
                colors[i] = 'Y'; // Yellow for correct letter, wrong position
                letterCount[input[i] - 'A']--;
            } else {
                colors[i] = 'R'; // Red for incorrect letter
            }
        }
    }
}

void printColoredGuess(  char *guess,   char *colors) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (colors[i] == 'G') {
            printf(COLOR_GREEN "%c" COLOR_RESET, guess[i]); // Green
        } else if (colors[i] == 'Y') {
            printf(COLOR_YELLOW "%c" COLOR_RESET, guess[i]); // Yellow
        } else {
            printf(COLOR_RED "%c" COLOR_RESET, guess[i]); // Red
        }
    }
    printf("\n");
}

void updateAlphabetColors(  char *guess,   char *colors, char alphabetColors[]) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        char letter = guess[i];
        int index = letter - 'A';
        if (colors[i] == 'G') {
            alphabetColors[index] = 'G';
        } else if (colors[i] == 'Y' && alphabetColors[index] != 'G') {
            alphabetColors[index] = 'Y';
        } else if (colors[i] == 'R' && alphabetColors[index] != 'G' && alphabetColors[index] != 'Y') {
            alphabetColors[index] = 'R'; // Red for incorrect letter
        }
    }
}

void printAlphabetColors(  char alphabetColors[]) {
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        int index = letter - 'A';
        if (alphabetColors[index] == 'G') {
            printf(COLOR_GREEN "%c" COLOR_RESET " ", letter); // Green
        } else if (alphabetColors[index] == 'Y') {
            printf(COLOR_YELLOW "%c" COLOR_RESET " ", letter); // Yellow
        } else if (alphabetColors[index] == 'R') {
            printf(COLOR_RED "%c" COLOR_RESET " ", letter); // Red
        } else {
            printf("%c ", letter);
        }
    }
    printf("\n");
}


int main() {
    extern char *wordList[];
    extern int randomIndex();
    extern bool isAvailable[];

    char wordToGuess[WORD_LENGTH + 1];
    char *randomWord = wordList[randomIndex()];

    // Convert the random word to uppercase and assign to wordToGuess
    for (int i = 0; i < WORD_LENGTH; i++) {
        wordToGuess[i] = toupper(randomWord[i]);
    }
    wordToGuess[WORD_LENGTH] = '\0'; // Null-terminate the string

    printf("Word to guess: %s\n", wordToGuess);
    char input[1000];
    char fiveLetterStrings[MAX_GUESSES][WORD_LENGTH + 1];
    char colors[MAX_GUESSES][WORD_LENGTH + 1];
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
        if (strlen(input) != WORD_LENGTH) {
                        for (int j = 0; j <= i; j++) {
                printColoredGuess(fiveLetterStrings[j], colors[j]);
            }

            printAlphabetColors(alphabetColors);
            printf("Please enter a 5-letter word.\n");
            continue;
        }

        if  (isAvailable[hashfunction2(input)]==0){
            for (int j = 0; j <= i; j++) {
                printColoredGuess(fiveLetterStrings[j], colors[j]);
            }

            printAlphabetColors(alphabetColors);

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
            fiveLetterStrings[i][WORD_LENGTH] = '\0'; // Null-terminate the string

            determineColors(wordToGuess, fiveLetterStrings[i], colors[i]);
            updateAlphabetColors(fiveLetterStrings[i], colors[i], alphabetColors);

            // Print all previous guesses with colors
            for (int j = 0; j <= i; j++) {
                printColoredGuess(fiveLetterStrings[j], colors[j]);
            }

            // Print the alphabet with colors
            printAlphabetColors(alphabetColors);

            i++;
            if(result==2){
                printf("Congratulations! You have guessed the word.\n");
                break;
            } // Increment i after processing the current guess

            if (i == MAX_GUESSES) {
                break;
            }
        }
        printf("\n");
    } while (1);

    return 0;
}