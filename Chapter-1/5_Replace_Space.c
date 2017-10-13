#include "stdio.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char* remSpace(char input[]) {
    int count = 0;
    
    //Get length of string including new 3 char "%20".
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            count += 3;
        } else {
            count++;
        }
    }
    
    //Allocate memeory for new string.
    char *result = malloc(sizeof(char) * count);

    int pos = 0;
    //Go through string and build result by replacing each occurence.
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            result[pos] = '%';
            result[pos+1] = '2';
            result[pos+2] = '0';
            pos += 3;
        } else {
            result[pos] = input[i];
            pos++;
        }
    }
    
    //Add terminating character to string.
    result[pos] = 0;
    
    return result;
}

int main(int argc, char **argv) {
    char *input = argv[1];

    char *result = remSpace(input);
    printf("%s", result);
    free(result);

    return 0;
}