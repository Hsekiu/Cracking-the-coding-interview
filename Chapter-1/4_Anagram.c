#include "stdio.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int* getDict(char input[]) {
    //Allocate int array to heap
    int *dict = malloc(26*sizeof(int));
    
    //Count the number of letters and increment each in dict when it appears.
    for(int i = 0; i < strlen(input); i++) {
        int pos = (input[i] - '0') - 49;
        dict[pos]++;
    }
    
    return dict;
}

_Bool isAnagram(char input1[], char input2[]) {
    int *dict1 = getDict(input1);
    int *dict2 = getDict(input2);
    
    int length1 = strlen(input1);
    int length2 = strlen(input2);
    
    _Bool result = 1;

    //Check if string lengths are equal.
    if(length1 == length2) {
        //If equal then go through and compare the amount of letters.
        for(int i = 0; i < length1; i++) {
            //Number of letters don't match thus can't be a anagram.
            if(dict1[i] != dict2[i]) {
                result = 0;
                break;
            }
        }
    } else {
        result = 0;
    }
    
    //Free memory
    free(dict1);
    free(dict2);
    
    return result;
}

int main(int argc, char **argv) {
    char *input1 = argv[1];
    char *input2 = argv[2];

    printf(isAnagram(input1, input2) ? "true" : "false");

    return 0;
}
