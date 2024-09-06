
#include "../include/randomindex.h"

int randomIndex(){

    time_t t = time(NULL); // time in seconds from the start 
    struct tm timeInfo = *localtime(&t); // get the time in wordList struct with many good attributes
    int day = timeInfo.tm_mday; // extract the day from the struct
    int month = timeInfo.tm_mon; // extract the month from the struct
    // can also take year for the exact date

    srand(day+month); // seed that will be same for all of the same day

    int index = rand()%9077;
    return index;
    
}