//
//rs-decode
//
//  Created by Samir Dahmani on 3/11/14.
//  Copyright (c) 2014 Samir Dahmani. All rights reserved.
//

#include <stdio.h>
#import <stdlib.h>

#include "linear_alg.h"
#include "gf.h"


int *xorMatrices(int **f, int *d, int len) {
    int sum;

    //initialize empty matrix fd
    int **fd;
    fd = (int **) malloc(sizeof(int *) * len);
    for (int i = 0; i < len; ++i) {
        *(fd + i) = (int *) malloc(sizeof(int) * len);
    }

    int *abc;
    abc = malloc(sizeof(int) * len);
    int *c = malloc(sizeof(int) * len);


    for (int i = 0; i < len; i++) {


        for (int j = 0; j < len; j++) {

            fd[i][j] = mult(f[i][j], (d[j]));
            abc[j] = fd[i][j];

            if (j == 0) {
                sum = abc[j];

            } else {
                sum ^= abc[j];
            }
        }
        c[i] = sum;
        // printVector(c, len);
    }


    return c;

}


int *vectorE(int n, int *D, int *C) {

    int *E;
    int count = 0;

    E = malloc(sizeof(int) * 2 * n);

    for (int i = 0; i < n; ++i) {

        E[i] = D[i];

    }

    for (int ii = n; ii < 2 * n; ++ii) {

        E[ii] = C[count];
        count++;

    }

    return E;


}

int **matrixA(int n) {

    int **A = initEmptyMatrix(2 * n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                A[i][j] = 1;
                //            printf("%d ",id[i][0]);
            }
            else {
                A[i][j] = 0;
//                printf("%d ",id[i][j]);
            }
        }
//        printf("\n");
    }
    int count = 0;

    for (int i = n; i < 2 * n; ++i) {

        for (int j = 1; j < n + 1; ++j) {
            // printf("%d\n",count);




            A[i][j - 1] = takePower(j, count);

            //  printf("%d^%d\n", j, count);


        }
        count++;

    }


    return A;


}

// computes x^n over the galois field


int **APrime(int *l, int **A, int n) {

    int count = n - 1;

    int **A_prime = initEmptyMatrix(n, n);

    int i = 2 * n - 1;
    count = sizeof(l) / sizeof(l[0]);

    int increment = n - 1;
    //printf("e_prime %d\n ", E_prime);
    while (i >= 0) {

//        printf("l[increment] %d\t i %d\t increment %d\t E[i]%d count %d\n", l[increment], i, increment, E[i], count);

        if ((i != l[increment]) && (count >= 0)) {

            for (int col = 0; col < 3; col++) {

                A_prime[count][col] = A[i][col];

                //printf("l[increment] %d\t i %d\t increment %d\t A[i][col] %d\t count %d\n", l[increment], i, increment, A[i][col], count);
            }


            if (increment > 0) {
                increment--;
                count--;
            }


        }


        i--;


    }


    return A_prime;

}

int *EPrime(int *l, int *E, int n) {

    int count = n - 1;

    int *E_prime = malloc(sizeof(int) * n);

    int i = 5;
    count = 2;

    int increment = n - 1;
    //printf("e_prime %d\n ", E_prime);
    while (i >= 0) {

//        printf("l[increment] %d\t i %d\t increment %d\t E[i]%d count %d\n", l[increment], i, increment, E[i], count);

        if ((i != l[increment]) && (count >= 0)) {


            E_prime[count] = E[i];


            if (increment > 0) {
                increment--;
                count--;
            }


        }


        i--;


    }


    return E_prime;

}


void compute() {

    setup_tables(4);

    int n = 3;
    int **F = genVandermonde(n);
    int *C;


    int *D = malloc(sizeof(int) * n);
    *D = 3;
    *(D + 1) = 1;
    *(D + 2) = 9;
    int **A;
    int **A_prime;
    int *E;
    int *E_prime;

    int **A_prime_inv;



    int *D_recovered = malloc(sizeof(int) * n);

    //inject errors
    int *l = malloc(sizeof(int) * n);
    *(l + 0) = 1;
    *(l + 1) = 2;
    *(l + 2) = 5;



    //create FD = C

    C = xorMatrices(F, D, n);


    printVector(C, n);

//    now create Matrix A


    A = matrixA(n);
    printMatrix(A, 2 * n, n);
    A_prime = APrime(l, A, n);
    printf("A_prime:\n");
    printMatrix(A_prime, n, n);

    E = vectorE(n, D, C);

    printf("---------\n");
    printVector(E, 2 * n);


    E_prime = EPrime(l, E, n);
    printf("solution: ");
    printVector(E_prime, n);

    int matrix[25][25];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            matrix[i][j] = A_prime[i][j];
            printf("%d | ", matrix[i][j]);
        }
        printf("\n");


    }
    A_prime_inv = invertMatrix(matrix, n);
//    printMatrix(A_prime_inv, 3, 3);

    D_recovered = xorMatrices(A_prime_inv, E_prime, n);

    printf("system recovered\n");
    printVector(D_recovered, n);


}


int main(void) {


    compute();








    //printMatrix(F, len);
    //printMatrix(D, len);
//    int matrix[25][25] = {{1, 0, 0}, {1, 1, 1}, {1, 2, 3}};

//    int **inv;


    return 0;

}
