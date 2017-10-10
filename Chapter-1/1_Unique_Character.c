#include "stdio.h"
#include <string.h>
#include <unistd.h>

_Bool isUniqueN2(char *input) {
  for(char i = 'a'; i < 'z'; i++) {
    int count = 0;
    for(int j = 0; j < strlen(input); j++) {
      if(input[j] == i) {
        count++;
      }
      if(count > 1) {
        return 0;
      }
    }
  }
  return 1;
}

_Bool isUniqueN(char *input) {
    char letters[25];
    memset(letters, 0, sizeof letters);
    
    for (int i = 0; i < strlen(input); i++) {
        int val = (input[i] - '0') - 49;
        if (letters[val] == 1) {
            return 0;
        } else {
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