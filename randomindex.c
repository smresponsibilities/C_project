
#include "randomindex.h"
#include <stdlib.h>
#include <time.h>


int randomIndex(){
    time_t t = time(NULL); // time in seconds from the start 
    struct tm timeInfo = *localtime(&t); // get the time in a struct with many good attributes
    int day = timeInfo.tm_mday; // extract the day from the struct
    int month = timeInfo.tm_mon; // extract the month from the struct
    // can also take year for the exact date

    srand(day+month); 
    int index = rand()%10 +1;
    return index ;
    
}