#import <stdlib.h>
#include <stdio.h>

#include "gf.h"

int **initEmptyMatrix(int m, int n) {

    int **matrix_pp;
    matrix_pp = (int **) malloc(sizeof(int *) * m);

    for (int i = 0; i < m; i++) {
        *(matrix_pp + i) = malloc(sizeof(int) * n);
    }


    return matrix_pp;
}

void printMatrix(int **pp, int m, int n) {

    for (int i = 0; i < m; ++i) {

        for (int j = 0; j < n; ++j) {

            printf("%d ", pp[i][j]);
        }
        printf("\n");
    }

}

void printVector(int *p, int len) {

    for (int i = 0; i < len; ++i) {
        printf("%d ", p[i]);
    }
    printf("\n");
}


int **toDblPointerInv(int in[25][25], int len) {


    int **out = initEmptyMatrix(len, len);

    for (int i = 0; i < len; i++) {
        for (int j = len; j < 2 * len; j++)
            out[i][j - len] = in[i][j];

    }

    return out;
}


int **invertMatrix(int matrix[25][25], int len) {

    int ratio, a;
    int i, j, k;

    for (i = 0; i < len; i++) {
        for (j = len; j < 2 * len; j++) {
            if (i == (j - len))
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (i != j) {
                ratio = divide(matrix[j][i], matrix[i][i]);
                for (k = 0; k < 2 * len; k++) {
                    matrix[j][k] = sub(matrix[j][k], mult(ratio, matrix[i][k]));
                }
            }
        }
    }
    for (i = 0; i < len; i++) {
        a = matrix[i][i];
        for (j = 0; j < 2 * len; j++) {
            matrix[i][j] = divide(matrix[i][j], a);
        }
    }

//    printf("The inverse matrix is: \n");
//    for (i = 0; i < len; i++) {
//        for (j = len; j < 2 * len; j++) {
//            printf("%d", matrix[i][j]);
//            printf("\t");
//        }
//        printf("\n");
//    }

    int **copy_2_ptr;
    copy_2_ptr = toDblPointerInv(matrix, len);


    return copy_2_ptr;
}

int **genVandermonde(int len) {

    int **V = initEmptyMatrix(len, len);

    for (int i = 0; i < len; ++i) {
        for (int j = 1; j < len + 1; ++j) {

            V[i][j - 1] = takePower(j, i);

//            printf("%d^%d\n", j, i);


        }


    }

    return V;
}
