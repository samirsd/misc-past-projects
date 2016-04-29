#include <stdio.h>
#import <stdlib.h>
#include <stdbool.h>


#include "gf.h"


int w = 4;

#define NW (1 << w)

unsigned int prim_poly_4 = 023;
unsigned int prim_poly_8 = 0435;
unsigned int prim_poly_16 = 0210013;
//unsigned short *gflog, *gfilog;

struct gfTable GF;




struct gfTable setup_tables(int w) {



    unsigned int b, log, x_to_w, prim_poly;
    switch (w) {
        case 4:
            prim_poly = prim_poly_4;
            break;
        case 8:
            prim_poly = prim_poly_8;
            break;
        case 16:
            prim_poly = prim_poly_16;
            break;
        default:
            return GF;
    }
    x_to_w = 1 << w;
    GF.gflog = (unsigned short *) malloc(sizeof(unsigned short) * x_to_w);
    GF.gfilog = (unsigned short *) malloc(sizeof(unsigned short) * x_to_w);
    b = 1;
    for (log = 0; log < x_to_w - 1; log++) {
        GF.gflog[b] = (unsigned short) log;
        GF.gfilog[log] = (unsigned short) b;
        b = b << 1;
        if (b & x_to_w) b = b ^ prim_poly;
    }
    int **pp = (int **) malloc(sizeof(int *) * 2);


    return GF;
}

/* In other words, NW equals 2 to the w-th power */
int mult(int a, int b) {
    int sum_log;
    if (a == 0 || b == 0) return 0;
    sum_log = GF.gflog[a] + GF.gflog[b];
    if (sum_log >= NW - 1) sum_log -= NW - 1;
    return GF.gfilog[sum_log];
}

int divide(int a, int b) {
    int diff_log;
    if (a == 0) return 0;
    if (b == 0) return -1;
    diff_log = GF.gflog[a] - GF.gflog[b];
    if (diff_log < 0) diff_log += NW - 1;
    return GF.gfilog[diff_log];
}

int add(int a, int b) {
    return (a ^ b);
}

int sub(int a, int b) {
    return a ^ b;
}

//x^n
int takePower(int x, int n) {
    int aux = 1;
    while (n > 0) {
        if (n & 1) {
            aux = mult(aux, x);
            if (n == 1) return aux;
        }
        x = mult(x, x);
        n /= 2;
    }
    return aux;
}


int toPos(int length, int a) {
    return length - 1 - GF.gflog[a];
}