#include "stdio.h"
#include <string.h>
#include <unistd.h>


char* reverse(char *input) {
    //Temp var to hold for switching characters
    char temp;
    int length = strlen(input)-1;
    int start, end;
    //Loop through string going towards center and switching characters
    for(start = 0, end = length; start < end; start++, end--) {
        temp = input[start];
        input[start] = input[end];
        input[end] = temp;
    }
    
    return input;
}

int main(int argc, char **argv) {
    char *input = argv[1];
    
    printf("%s", reverse(input));

    return 0;
}