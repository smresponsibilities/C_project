#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 5
#define MAX_GUESSES 6

// Color macros
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_RESET "\033[0m"

void determineColors(const char *wordToGuess, const char *input, char colors[]) {
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

void printColoredGuess(const char *guess, const char *colors) {
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

void updateAlphabetColors(const char *guess, const char *colors, char alphabetColors[]) {
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

void printAlphabetColors(const char alphabetColors[]) {
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
    const char *wordToGuess = "ALOFT"; // Example word for the day
    char guesses[MAX_GUESSES][WORD_LENGTH + 1];
    char colors[MAX_GUESSES][WORD_LENGTH + 1];
    char alphabetColors[26] = {0}; // Initialize all to 0 (no color)
    int guessCount = 0;

    while (guessCount < MAX_GUESSES) {
        printf("Enter your guess (%d/%d): ", guessCount + 1, MAX_GUESSES);
        scanf("%5s", guesses[guessCount]);

        // Convert input to uppercase
        for (int i = 0; i < WORD_LENGTH; i++) {
            guesses[guessCount][i] = toupper(guesses[guessCount][i]);
        }
        guesses[guessCount][WORD_LENGTH] = '\0'; // Null-terminate the string

        determineColors(wordToGuess, guesses[guessCount], colors[guessCount]);
        updateAlphabetColors(guesses[guessCount], colors[guessCount], alphabetColors);

        // Print all previous guesses with colors
        for (int i = 0; i <= guessCount; i++) {
            printColoredGuess(guesses[i], colors[i]);
        }

        // Print the alphabet with colors
        printAlphabetColors(alphabetColors);

        if (strcmp(guesses[guessCount], wordToGuess) == 0) {
            printf("Correct guess: ");
            printColoredGuess(guesses[guessCount], colors[guessCount]);
            printf("Correct!\n");
            break;
        }

        guessCount++;
    }

    if (guessCount == MAX_GUESSES) {
        printf("You've used all your guesses. The word was: %s\n", wordToGuess);
    }

    return 0;
}