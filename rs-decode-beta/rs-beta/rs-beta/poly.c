#include "poly.h"
#include "gf.h"
#include <stdio.h>
#include <stdlib.h>

void deletePoly(Polynomial* poly) {
	free (poly->_poly);
	free (poly);
}

/*return empty polynomial
Polynomial* makePoly(int* poly, int n) {
	// how to declare polynomial? Perhaps replicate brownan functionality?
	Polynomial* poly = (Polynomial *)malloc(sizeof(Polynomial));
	poly->_poly = (int *)malloc(n*sizeof(int));

	return poly;
}*/

/*make a polynomial*/
Polynomial* makePoly(int n) {
	// zero = (int *)malloc(n*sizeof(int));
	Polynomial* poly = (Polynomial *)malloc(sizeof(Polynomial));
	poly->_poly = (int *)malloc(n*sizeof(int));
/*
	for(int i = 0; i < n; i++) {
		poly->_poly[i] = 0;
	}
*/
	return poly;
}

Polynomial* initPoly(int* x, int n) {
	Polynomial* poly = makePoly(n);
	for (int i = 0; i < n; i++) {
		poly->_poly[i] = x[i];
	}

	// won't need the array anymore, free it
	free(x);
	return poly;
}

void delPoly(Polynomial* a) {
	free(a->_poly);
	free(a);
}

Polynomial* zeroPoly(int n) {
	Polynomial* poly = makePoly(n);
	for (int i = 0; i < n; i++) {
		poly->_poly[i] = 0;
	}

	return poly;
}

/*Increment a polynomial by one*/
Polynomial* incPoly(Polynomial* a) {
	Polynomial* sum = makePoly(a->_n);
	sum = copyPoly(sum, a);
	// Add one. I *could* use the GF addition function, but is it really necessary?
	sum->_poly[0] ^= 1;

	return sum;
}

/*add two polynomials together, store in a*/
Polynomial* addPoly(Polynomial* a, Polynomial* b) {
	
	if (a->_n == b->_n) {
		for (int i = 0; i < a->_n; i++) {
			a->_poly[i] ^= b->_poly[i];
		}
	}

	return a;
}

Polynomial* multPoly(Polynomial* a, Polynomial* b) {
	// This MAXDEG variable is probably wrong, what should it be?
	int MAXDEG = a->_n * 2;
	Polynomial* product = makePoly(a->_n * 2);
	int* temp = (int *) malloc((a->_n * 2) * sizeof(int));
	// int* y = (int *) malloc((a->_n * 2) * sizeof(int));

	for (int i = 0; i < (MAXDEG*2); i++) {
		product->_poly[i] = 0;
	}

	for (int i = 0; i < MAXDEG; i++) {
		for (int j = MAXDEG; j < (MAXDEG*2); j++) {
			temp[j] = 0;
		}

		for (int j = 0; j < MAXDEG; j++) { 
			// temp[j] = GFMul(b->_poly[j], a->_poly[i]);
			temp[j] = mult(b->_poly[j], a->_poly[i]);
		}

		for (int j = (MAXDEG*2)-1; j >= i; j--) {
			temp[j] = temp[j-i];
		}

		for (int j = 0; j < (MAXDEG*2); j++) {
			temp[j] = 0;
		}

		for(int j = 0; j < (MAXDEG*2); j++) {
			product->_poly[j] ^= temp[j];
		}
	}
}

Polynomial* evalPoly(Polynomial* a, int x) {
	int* s = (int *)malloc(sizeof(int)*a->_n);
	for (int i = 0; i < a->_n; i++) {
		s[i] = mult(a->_poly[i], x);
	}

	return initPoly(s, a->_n);
}

Polynomial* shiftPoly(Polynomial* a) {

	for (int i = a->_n - 1; i > 0; i--) {
		a->_poly[i] = a->_poly[i-1];
	}
	a->_poly[0] = 0;

	return a;
}

Polynomial* scalePoly(Polynomial* a, int x) {
	Polynomial* result = makePoly(a->_n);
	for (int i = 0; i < a->_n; i++) {
		result->_poly[i] = mult(a->_poly[i], x); 
	}

	return result;
}

/*Copy polynomial b into a*/
Polynomial* copyPoly(Polynomial* a, Polynomial* b) {
	for(int i = 0; i < a->_n; i++) {
		a->_poly[i] = b->_poly[i];
	}

	return a;
}