
#define FIRST_HASH 46106600
#define SECOND_HASH 6999999
#include "hash.h"

// simple function to calculate the power of a number
unsigned long long power(int base, int exp) {

    unsigned long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;

}

// hash function to hash the words in the wordList
void hashfunction(char** wordList, bool isAvailable[]) {

    unsigned long long hashValues[9077];
    for (int i = 0; i < 9077; i++) {
        unsigned long long midResult = 0;
        int len = strlen(wordList[i]);
        for (int j = 0; j < len; j++) {
            midResult += (wordList[i][j] * power(26, j)) % FIRST_HASH;
            // major hash function tailored by trial and error
        }
        
        // doing modulus to decrease the size of the hash value
        hashValues[i] = midResult % FIRST_HASH;

        // making the boolean value true as there is no collision
        isAvailable[hashValues[i] % SECOND_HASH]= true;

    }

}


int hashfunction2( char* word) {
    unsigned long long midResult = 0;
    int len = strlen(word);
    for (int j = 0; j < len; j++) {
        midResult += (tolower(word[j]) * power(26, j)) % FIRST_HASH;
        // major hash function tailored by trial and error
    }
    
    // doing modulus to decrease the size of the hash value
    unsigned long long hashValue = midResult % FIRST_HASH;

    // making the boolean value true as there is no collision
return (hashValue % SECOND_HASH);


}





    //  char *wordList[9077] = {
    // "aalii",
    // "aalst",
    // "aalto",
    // "aarau",
    // "aaron",
    // "aarti",
    // "abaca",
    // "aback",
    // "abaco",
    // "abaft",
    // "abamp",
    // "abase",
    // "abash",
    // "abate",
    // "abaya",
    // "abbai",
    // "abbas",
    // "abbed",
    // "abbey",
    // "abbie",
    // "abbot",
    // "abdon",
    // "abeam",
    // "abele",
    // "abhor",
    // "abide",
    // "abihu",
    // "abled",
    // "abmho",
    // "abner",
    // "abode",
    // "abohm",
    // "aboil",
    // "aboon",
    // "abort",
    // "about",
    // "above",
    // "abram",
    // "abrin",
    // "abuja",
    // "abuna",
    // "abuse",
    // "abuzz",
    // "abysm",
    // "abyss",
    // "abzug",
    // "accad",
    // "accra",
    // "acerb",
    // "achan",
    // "acidy",
    // "ackee",
    // "acker",
    // "ackey",
    // "acock",
    // "acold",
    // "acoma",
    // "acorn",
    // "acral",
    // "acred",
    // "acrid",
    // "acron",
    // "acrux",
    // "actin",
    // "actis",
    // "acton",
    // "actor",
    // "actra",
    // "acuff",
    // "acute",
    // "adage",
    // "adama",
    // "adami",
    // "adams",
    // "adana",
    // "adapt",
    // "addax",
    // "adder",
    // "addie",
    // "addio",
    // "addle",
    // "adeem",
    // "adele",
    // "adeni",
    // "adept",
    // "adhan",
    // "adieu",
    // "adige",
    // "adios",
    // "adlai",
    // "adler",
    // "admah",
    // "adman",
    // "admin",
    // "admit",
    // "admix",
    // "adnah",
    // "adobe",
    // "adobo",
    // "adolf",
    // "adopt",
    // "adore",
    // "adorn",
    // "adour",
    // "adowa",
    // "adown",
    // "adoze",
    // "adret",
    // "adsum",
