#ifndef POLY_H
#define POLY_H

/* declare polynomial data structure */
typedef struct Polynomial {
	int *_poly;
	int _n;
} Polynomial;

Polynomial* makePoly(int n);
Polynomial* initPoly(int* x, int n);
void 		deletePoly(Polynomial* a);
Polynomial* zeroPoly(int n);
Polynomial* incPoly(Polynomial* a);
Polynomial* addPoly(Polynomial* a, Polynomial* b);
Polynomial* multPoly(Polynomial* a, Polynomial* b);
Polynomial* evalPoly(Polynomial* a, int x);
Polynomial* shiftPoly(Polynomial* a);
Polynomial* scalePoly(Polynomial* a, int x);
Polynomial* copyPoly(Polynomial* a, Polynomial* b);

#endif /* POLY_H */