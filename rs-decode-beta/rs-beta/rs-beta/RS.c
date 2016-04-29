#include "poly.h"
#include "gf.h"
#include "RS.h"
#include <stdio.h>
#include <stdlib.h>

/*Calculate syndrome polynomial based on received codeword r*/
/*
Polynomial* calcSyndromes(Polynomial* r, int alpha) {
	Polynomial* syndrome = makePoly(r->_n);
	for (int i = 0; i < r->_n; i++) {
		syndrome->_poly[i] = evalPoly(r, GFPow(GFInt(alpha), i));
		// s.append (r.evaluate (GF256int(3)**l))
		// s_r (x) = p(x)x^t
	}
}
*/

/*
SigmaOmega* berlekampMassey(Polynomial* syndrome, GFTable _GF) {

	int S = syndrome->_n;

	Polynomial* gamma = zeroPoly(n);
	Polynomial* temp = zeroPoly(n);
	gamma->_poly[0] = 1;
	for (int i = 0; i < NErasures; i++) {
		// copy gamma into temp

		int exp = _GF->gflog[]
		for (int j = 0; j < someSize; j++) {

		}
	}


	
	// int* sigma = (int *)malloc(S*sizeof(int));
	// int* omega = (int *)malloc(S*sizeof(int));
	// int* tau   = (int *)malloc(S*sizeof(int));
	// int* gamma = (int *)malloc(S*sizeof(int));
	

	Polynomial* sigma = makePoly(S);
	Polynomial* omega = makePoly(S);
	Polynomial* tao = makePoly(S);
	Polynomial* gamma = makePoly(S);
	Polynomial* delta;

	sigma->_poly[0] = 1;
	omega->_poly[0] = 1;
	tau->_poly[0]   = 1;
	gamma->_poly[0] = 0;

	// declare d, b
	D = // somearray?
	B = // somearray?


	for (int i = 0; i < n-k; i++) {
		// add one to syndrome, scale by sigma[i]
		// base case: sigma = 1
		// delta is then set to the next coefficient: e.g. base case -> syndrome[1] ^ 1
		// this can be made more efficient.
		delta = ( (ONE + syndrome) * sigma[i]).get_coefficient(i+1);

		delta = Polynomial(x0 = Delta);

		// Can now compute sigma[l+1] and omega[l+1] from
		# sigma[l], omega[l], tao[l], gamma[l], and Delta
		sigma.append( sigma[l] - Delta * Z * tao[l] )
		omega.append( omega[l] - Delta * Z * gamma[l] )

		if (Delta == ZeroPoly || (2 * D[i] > (i+1))) {
			# Rule A
            // D.append( D[i] )
            // B.append( B[i] )
            // tao.append( Z * tao[i] )
            // gamma.append( Z * gamma[i] )
		} else if (Delta != ZeroPoly && (2 * D[i] > i+1)) {
			# Rule B
            // D.append( i + 1 - D[i] )
            // B.append( 1 - B[i] )
            // tao.append( sigma[i] // Delta )
            // gamma.append( omega[i] // Delta )
		} else if (2 * D[i] == (i+1)) {
			if (B[i] == 0) {
				# Rule A (same as above)
                // D.append( D[i] )
                // B.append( B[i] )
                // tao.append( Z * tao[i] )
                // gamma.append( Z * gamma[i] )
			} else {
				# Rule B (same as above)
                // D.append( i + 1 - D[i] )
                // B.append( 1 - B[i] )
                // tao.append( sigma[i] // Delta )
                // gamma.append( omega[i] // Delta )
			}
		} else {
			// Cry and scream
		}

	}

	return sigma and omega
	SigmaOmega* val = (SigmaOmega *)malloc(sizeof(SigmaOmega));
	val->_sigma = // some sigma
	val->_omega = // some omega

	// Clean up values
	delPoly(sigma);
	delPoly(omega);
	delPoly(tao);
	delPoly(gamma);
	delPoly(delta);
	free(D);
	free(B);

	return val;
}

*/

int main () {
	setup_tables(67);
	printf ("Hello World!\n");
}