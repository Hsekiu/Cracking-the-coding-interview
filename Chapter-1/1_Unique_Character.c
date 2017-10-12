#include "stdio.h"
#include <string.h>
#include <unistd.h>

_Bool isUniqueN2(char *input) {
  //Loop through letters.
  for(char i = 'a'; i < 'z'; i++) {
    int count = 0;
    //For each letter check if it appears in string.
    for(int j = 0; j < strlen(input); j++) {
      if(input[j] == i) {
        count++;
      }
      //If count is above 1 string is not unique.
      if(count > 1) {
        return 0;
      }
    }
  }
  return 1;
}

_Bool isUniqueN(char *input) {
    //Create array to hold alphabet to hold the number of times it appears.
    char letters[25];
    memset(letters, 0, sizeof letters);
    
    //Go through string and add each occurence to letter array.
    for (int i = 0; i < strlen(input); i++) {
        int val = (input[i] - '0') - 49;
        //If letter in array is 1 then not unique string.
        if (letters[val] == 1) {
            return 0;
        } else {
            letters[val] = 1;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
  char* input = argv[1];

  printf(isUniqueN2(input) ? "true" : "false");
  printf("\n");
  printf(isUniqueN(input) ? "true" : "false");
  
  return 0;
}