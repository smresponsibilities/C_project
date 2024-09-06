#include <assert.h>
#include <string.h>
#include "../include/color.h"
#include <stdio.h>
#include "testcolor.h"

void testWordColoring() {
    char colors[6] = {0};


    memset(colors, 0, sizeof(colors)); 
    wordColoring("GRAPE", "GREEN", colors);
    assert(strcmp(colors, "GGYRR") == 0);
    
    memset(colors, 0, sizeof(colors)); 
    wordColoring("GRAPE", "LEMON", colors);
    assert(strcmp(colors, "RYRRR") == 0);
    
    memset(colors, 0, sizeof(colors)); 
    wordColoring("GRAPE", "ADEPT", colors);
    assert(strcmp(colors, "YRYGR") == 0);
    printf("The word coloring functionality is working perfectly\n");

}


// void testUpdateAtozcolors() {
//     char alphabetColors[26] = {0};
//     char colors[6] = {0};
//     wordColoring("GRAPE", "GRAPE", colors);
    
//     updateAtozcolors("GRAPE", "GRAPE", alphabetColors);
//         for (int i = 0; i < 26; i++) {
//         if (alphabetColors[i] != '') {

//         printf("%c%d", alphabetColors[i],i);
//     }}
//     printf("\n");

//     printf("\n");
//     assert(alphabetColors['G' - 'A'] == 'G');
//     printf("%c\n", alphabetColors['R' - 'A']);
//     assert(alphabetColors['R' - 'A'] == 'R');
//     printf("%c\n", alphabetColors['A' - 'A']);
//     assert(alphabetColors['A' - 'A'] == 'A');
//     assert(alphabetColors['P' - 'A'] == 'P');
//     assert(alphabetColors['E' - 'A'] == 'E');





// }



// int main() {
//     testWordColoring();

//     // testUpdateAtozcolors();

//     printf("The color updating functionality is working\n");
//     return 0;
// }