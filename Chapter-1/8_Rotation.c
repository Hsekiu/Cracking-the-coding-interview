#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Return is input has a string substring as a substring.
_Bool isSubstring(char *input, char* substring) {
    if(strstr(input, substring) != NULL) {
        return 1;
    }
    
    return 0;
}

_Bool isRotation(char *substring, char* input) {
    _Bool result = 0;

    char *tmp = malloc(strlen(input) * 2 + 1);

    //If input and substring are not equal can't be rotation.
    if((strlen(input) == strlen(substring)) && (strlen(input) > 0)) {

        //Create a new string = input + input;
        strcpy(tmp, input);
        strcat(tmp, input);


        if(isSubstring(tmp, substring)) {
            result = 1;
        }
    }

    free(tmp);

    return result;
}

int main(int argc, char **argv) {
    char* substring = argv[1];
    char* input = argv[2];

    //If not input return false.
    if(substring == NULL || input == NULL) {
        printf("false");
    } else {
        printf(isRotation(substring, input) ? "true" : "false");
    }
    
    return 0;
}