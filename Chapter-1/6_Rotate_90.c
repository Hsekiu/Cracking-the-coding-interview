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
    
    //Test input matrix.
    int input[3][3] = {
        {1, 2 ,3},
        {4, 5, 6},
        {7, 8, 9}
    };

    //Allocate 2d array to heap and set it to test matrix.
    int (*arr)[3] = malloc(sizeof *arr * 3);
    arr = input;

    rotate90(arr);

    //Print the matrix.
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%i", arr[i][j]);
        }
        printf("\n");
    }

    //Free 2d matrix from heap.
    free(arr);

    return 0;
}