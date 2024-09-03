#include<stdio.h>
#include<string.h>

int wordCheck(char *word, char *guess) {
    if (strlen(word) != strlen(guess)) {
        return 0;
    }
    for (int i = 0; i < 5 ; i++) {
        if (word[i] != guess[i]) {
            return 1;
        }
    }
    return 2;

}



int main() {
    printf("%d\n", wordCheck("hello", "hello"));
    printf("%d\n", wordCheck("hello", "hella"));
    printf("%d\n", wordCheck("hello", "hellaqqq"));;

    
    return 0;
}