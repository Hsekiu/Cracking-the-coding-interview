#include <stdlib.h>
#include <stdio.h>

int* zeroMatrix(int input[3][3]) {
    int rows[3];
    int columns[3];
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(input[i][j] == 0) {
                rows[i] = 1;
                columns[i] = 1;
            }
        }
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if((rows[i] == 1) || (columns[j] == 1)) {
                input[i][j] = 0;
            }
        }
    }
    
    return *input;
}

int main() {

    int n = 3;
    int m = 3;
    //int (*arr)[n] = malloc(sizeof *arr * m);
    int input[3][3] = {
        {1, 2 ,3},
        {4, 0, 5},
        {6, 7, 8}
    };
    
    int (*arr)[3] = malloc(sizeof *arr * 3);
    arr = input;

    zeroMatrix(arr);
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%i", arr[i][j]);
        }
        printf("\n");
    }
    
    free(arr);

    return 0;
}