#include "stdio.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int* rotate90(int input[3][3]) {
    int tmp;
    
    //Transpose the matrix.
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            tmp = input[i][j];
            input[i][j] = input[j][i];
            input[j][i] = tmp;
        }
    }
    
    //Reverse each array to get correct rotation.
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3/2; j++) {
            tmp = input[i][3 - j - 1];
            input[i][3 - j - 1] = input[i][j];
            input[i][j] = tmp;
        }
    }
       
    return *input;
}

int main() {

    int n = 3;
    
    //Sameple input matrix.
    int input[3][3] = {
        {1, 2 ,3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int (*result)[3] = rotate90(input);
    
    //Print the matrix.
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%i", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}