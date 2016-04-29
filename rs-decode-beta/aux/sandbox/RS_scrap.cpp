// RS_Test.cpp : Defines the entry point for the console application.
// Author: Stephen Kimble

#include "stdafx.h"
#include "GF.h"
#include <iostream>
#include <string>
#include <vector>
#include <iso646.h>

/**
* Polynomial class, which takes in an array where the index is the power,
* and the value is the coefficient.
*/
class Polynomial
{
	int *_polynomial;
	//int *polyPointer;
	//int evaluator;
	int _n;

public:
	Polynomial(int coefficients[], int n) {
		_polynomial = (int *) malloc(n*sizeof(int));
		_n = n;
	}

	// if passed nothing, generate empty array
	Polynomial() {
	}

	int PolyEval(int x)
	{
		int sum;
		int power = 1;

		for (int i = sizeof(_polynomial); i >= 0; i--) {
			sum += _polynomial[i] * power;
			power = power * x;
		}
	}

	int *getPoly() { return _polynomial; }
	int size() { return _n; }
};

/**

*/
//Polynomial * Syndrome(Polynomial *data, int n, int k)
//{

    // perform a bit parity check. If 0 (they are the same), then the poly value is okay. If 
    // non-zero, proceed to B-M

    // calculation: S_i = r(x) evaluated over X=a^i = r(a^i)
	//init galois field?
    
    /* pasted-in python code: 
    s = [GF256int(0)] # s[0] is 0 (coefficient of z^0)
        for l in xrange(1, n-k+1):
            s.append( r.evaluate( GF256int(3)**l ) ) 

    sz = Polynomial( reversed( s ) )
    */
//    Polynomial syndrome = new Polynomial
//    for(int i = 0; i < n-k+1; i++) {
//    	syndrome._polynomial[i] = 
//    }

    /* pasted-in c code:
    for (i=1; i<=nn-kk; i++)
    { s[i] = 0 ;
      for (j=0; j<nn; j++)
        if (recd[j]!=-1)
          s[i] ^= alpha_to[(recd[j]+i*j)%nn] ;      // recd[j] in index form 
	*/
//}

/**

*/
int[] BM(Polynomial* syndrome, int s)
{
	int n = syndrome->size();
	int* sigma = (int *) malloc(n*sizeof(int));		// error locator polynomial
	int* omega = (int *) malloc(n*sizeof(int));		// error evaluator polynomial
	int* tao   = (int *) malloc(n*sizeof(int));
	int* gamma = (int *) malloc(n*sizeof(int));
	int* D;
	int* B;
	int d;					// delta, change from expected

	int* _syn = syndrome->getPoly();
	
	for (int i = 0; i < s; i++) {
		// compute sigma[i+1] and omega[i+1] on each iteration
		//d = ( (/*ONE + syndrome*/) * sigma[i]).get_coefficient(i+1);

		// sigma[i+1] <- sigma[i] - d * Z * tao[i]
		// omega[i+1] <- omega[i] - d * Z * gamma[i]

		// compute the next tao and gamma

		// if ( d || 2*D[i] > i+1) 

		// else if ( !(d) && 2*D[i] < i+1)

		// else if (2*D[i] == (i+1))
			// if (B[i] == 0)

			// else

		// else raise error
	}

}

/**
 * Wikipedia implementation for GF(2), not useful in practice, 
 * but useful pedagogical example.
 */
/*
int BM_wiki(int[] syndrome) {
	int n = array.size();
	
	int b[] = new int[n];
	int c[] = new int[n];
	int t[] = new int[n];
	b[0] = 1;
	c[0] = 1;

	int l = 0; int m = -1;

	for (int i = 0; i < n; i++) {
		int d = 0;
		for (int j = 0; j <= n; j++) {
			// this array is in fact the syndromes. Iteratively add (XOR)
			// the items together
			d ^= c[i] * array[n - i];
		}

		if (d == 1) {
			//copy array
			memcpy();
			int N_M = n - m;
			for (int j = 0; j < N - N_M; j++) {
				c[N_M + j] ^= b[j];
			}

			if (l <= n/2) {
				l = n + 1 - l;
				m = n;
				memcpy();
			}
		}
	}
}

*/

/**
* Chien's Search - compute error locations X_i
* If sigma(GF(l))=0, add GF(l)-1 to X_i
* not written yet...

void Chien(int sigma[])
{
	//Let alpha be a generator of GF(2^8)

	//Initialize X_i to the empty set

	//for l from 1 to 256
	//if sigma(alpha_l) = 0, add alpha^-1 to X_i.


	// for i 
}*/

/** 
* Naive implementation of Chien's search.
* Evaluate sigma at all points to find roots
*/
void Chien_naive(Polynomial sigma, vector<int> &x, vector<int> &j)
{
	for (int l = 1; l <= 256; l++) {
		if (sigma.PolyEval(pow(sigma.getE(), l)) == 0) {
			x.push_back(pow(sigma.getE(), -1));
			j.push_back(255 - l);
		}
	}
}

/**
* Compute error magnitudes using Forney's Formula.
*/
void Forney(Polynomial omega, vector<int> x, vector<int> &y, int s)
{
	int y_L;
	int x_j;
	int product = 1;

	for (int L = 0; L < sizeof(x); L++) {
		for (int x_L = 0; x_L < sizeof(x); x_L++) {
			y_L = pow(x_L, s);
			y_L = y_L * omega.PolyEval(Inv(x_L));
			y_L = y_L * Inv(x_L);

			for (int j_i = 0; j_i <= s; j_i++) {
				if (j_i == 1) {
					continue;
				}
				if (j_i < sizeof(x)) {
					x_j = x.at(j_i);
				}
				else {
					x_j = 0;
				}
				product = product * (x_L - x_j);
			}

			y_L = y_L * Inv(product);
			//y.push_back(y_L);
		}
	}
}

