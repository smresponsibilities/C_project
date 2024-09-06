
#include <stdio.h>
#include <stdlib.h>
#include"../include/randomindex.h"
#include"../include/wordcheck.h"
#include<string.h>
#include<ctype.h>
#include "../include/hash.h"
#include "../include/color.h"


#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_NEUTRAL "\033[0m"

void  wordColoring( char *wordToGuess, char *input, char colors[]) {
    int letterCount[26] = {0};
    int len = strlen(wordToGuess);

    for (int i = 0; i < len; i++) {
        letterCount[wordToGuess[i] - 'A']++;
    }

    for (int i = 0; i < len; i++) {
        if (input[i] == wordToGuess[i]) {
            colors[i] = 'G'; // Green for correct position
            letterCount[input[i] - 'A']--;
        } else {
            colors[i] = ' ';
        }
    }


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

void printColoredWord( char *guess, char *colors) {
    for (int i = 0; i < 5; i++) {
        if (colors[i] == 'G') {
            printf(COLOR_GREEN "%c" COLOR_NEUTRAL, guess[i]); // Green
        } else if (colors[i] == 'Y') {
            printf(COLOR_YELLOW "%c" COLOR_NEUTRAL, guess[i]); // Yellow
        } else {
            printf(COLOR_RED "%c" COLOR_NEUTRAL, guess[i]); // Red
        }
    }
    printf("\n");
}

void updateAtozcolors( char *guess, char *colors, char alphabetColors[]) {
    for (int i = 0; i < 5; i++) {
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

void printAtoz( char alphabetColors[]) {
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        int index = letter - 'A';
        if (alphabetColors[index] == 'G') {
            printf(COLOR_GREEN "%c" COLOR_NEUTRAL " ", letter); // Green
        } else if (alphabetColors[index] == 'Y') {
            printf(COLOR_YELLOW "%c" COLOR_NEUTRAL " ", letter); // Yellow
        } else if (alphabetColors[index] == 'R') {
            printf(COLOR_RED "%c" COLOR_NEUTRAL " ", letter); // Red
        } else {
            printf("%c ", letter);
        }
    }
    printf("\n");
}