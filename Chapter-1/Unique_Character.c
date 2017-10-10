#include "stdio.h"
#include <string.h>
#include <unistd.h>

// Is O(n^2) time and O(1) space
_Bool isUniqueN2(char *input) {
  //Iterate through alphabet
  for(char i = 'a'; i < 'z'; i++) {
    int count = 0;
    //Go through the string
    for(int j = 0; j < strlen(input); j++) {
      //If character is in string at position j increment counter
      if(input[j] == i) {
        count++;
      }
      //More then one of the same character
      if(count > 1) {
        return 0;
      }
    }
  }
  return 1;
}

// Is O(n) time and O(1) space
_Bool isUniqueN(char *input) {
    //Array to keep count of each character in alphabet
    char letters[25];
    memset(letters, 0, sizeof letters);
    
    //Loop through string
    for (int i = 0; i < strlen(input); i++) {
        //Char to 0 indexable int
        int val = (input[i] - '0') - 49;
        //If alphabet array has been hit before not unique
        if (letters[val] == 1) {
            return 0;
        } else {
            //Increment alphabet array for each hit
            letters[val] = 1;
        }
    }
}

int main(int argc, char **argv) {
  char* input = argv[1];

  printf(isUniqueN2(input) ? "true" : "false");
  printf("\n");
  printf(isUniqueN(input) ? "true" : "false");
  
  return 0;
}