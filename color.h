#ifndef COLOR_H
#define COLOR_H


void  wordColoring( char *wordToGuess, char *input, char colors[]);
void printColoredWord( char *guess, char *colors);
void updateAtozcolors( char *guess,   char *colors, char alphabetColors[]);
void printAtoz( char alphabetColors[]);



#endif // COLOR_H