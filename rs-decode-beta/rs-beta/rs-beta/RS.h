#ifndef RS_H
#define RS_H

typedef struct GFTable {
	int gflog[256];
	int gfilog[256];
} GFTable;

typedef struct SigmaOmega {
	Polynomial* _sigma;
	Polynomial* _omega;
} SigmaOmega;

SigmaOmega* berlekamp_massey(Polynomial* syndrome, GFTable _GF);

#endif /* RS_H */