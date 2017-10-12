/*
    Made a assumption that the quesiton was talking about any duplicates and that
    it is a single word.
*/


#include "stdio.h"
#include <string.h>
#include <unistd.h>

char* remDupe(char input[]) {

    int length = strlen(input);

    char *result = input;
    
    //Return string if empty
    if(length == 0) {
        return result;
    }

    //Go through string and replace duplicates with space.
    for(int i = 0; i < length; i++) {
        for (int j = 0; j <= length - 1; j++) {
            if((input[i] == input[j]) && (i != j)) {
                input[j] = ' ';
            }
        }
    }
    
    //Go through array and move characters down.
    int count = 0;
    for(int i = 0; i < length; i++) {
        if(input[i] != ' ') {
            input[count] = input[i];
            count++;
        }
    }
    //Terminate string with null element at last moved location.
    input[count] = 0;

    return result;
}

int main(int argc, char **argv) {
    char *tmp = argv[1];

    //User input
    printf("User input: %s\n", remDupe(tmp));

    //Duplicate and duplicates are first and last elements
    char test1[] = "test";
    printf("Duplicate and duplicates are first and last elements: %s\n", remDupe(test1));

    //Multiple duplicates and in succesion.
    char test2[] = "aapbbwccd";
    printf("Multiple duplicates and in succesion: %s\n", remDupe(test2));

    //Empty string
    char test3[] = "";
    printf("Empty string: %s\n", remDupe(test3));

    return 0;
}