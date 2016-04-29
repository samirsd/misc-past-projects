#import <stdlib.h>
#include <stdio.h>
#import <stdbool.h>
#include "gf.h"

#define rs_correction -2;

gfTable g;
int gf_size = 63;

int chienSearch(int pos[], int n /* data length*/, int σ_order, int sigma[]) {
    g = setup_tables(4);

    int last = sigma[1];
    if (σ_order == 1) {

        if (g.gflog[last] >= n) {
            return rs_correction;
        }
        pos[0] = last;
        return 0;
    }

    int posIdx = σ_order - 1;        // error location for storing index
    for (int i = 0; i < n; i++) {

        int z = gf_size - i;                    // scalar z = 1 / α ^ i
        int wk = 1;
        for (int j = 1; j <= σ_order; j++) {
            wk ^= mult(sigma[j], (z * j) % gf_size);
        }
        if (wk == 0) {
            int pv = takePower(pv, i);
            last ^= pv;
            pos[posIdx--] = pv;
            if (posIdx == 0) {
                
                if (g.gflog[last] >= n) {
                    return rs_correction;
                }
                pos[0] = last;
                return 0;
            }
        }
    }
    return rs_correction;

}

void doForney(int data[], int length, int σ_order, int pos[], int sigma[], int omega[]) {


    for (int i = 0; i < σ_order; i++) {
        int ps = pos[i];
        int zlog = gf_size - g.gflog[ps];
    
        int ov = omega[0];
        for (int j = 1; j < σ_order; j++) {
            ov ^= mult(omega[j], (zlog * j) % gf_size);               }

      
        int dv = sigma[1];
        for (int j = 2; j < σ_order; j += 2) {
            dv ^= mult(sigma[j + 1], (zlog * j) % gf_size);
        }

        data[toPos(length, ps)] ^= mult(ps, divide(ov, dv));
    }
}








