/**
* Galois Field operations for GF(2^8).
* \TODO improve error handling, additional functionality
*/

#include "GF_b.h"
#include <stdio.h>
#include <stdlib.h>

void printTable (GFTable* table);

/*
 * make sure that generateGF is run before any of these operations are attepted
*/
int GFAdd(int a, int b) {
	return (a ^ b);
}

int GFSub(int a, int b) {
	return GFAdd(a, b);
}

int GFMul(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	unsigned int x = _table->gflog[a];
	unsigned int y = _table->gflog[b];
	return _table->gfilog[(x + y) % 256];
}

int GFInv(int a) {
	return _table->gfilog[255 - _table->gflog[a]];
}

int GFDiv(int a, int b) {
	return GFMul(a, GFInv(b));
}

/*
 * Generate a GF for a primitive polynomial. Example primpoly int: 67, or 1000011; x^6 + x + 1
 */
void generateGF(unsigned int primPoly) {
	int b;
	int x_to_w = 1 << 6;
	b = 1;

	// generate GF elements based on primPoly integer. 
	for (int lg = 0; lg < 64; lg++) {
		// std::cout << b << ", ";
		printf ("%d, ", b);
		_table->gflog[b] = lg;
		_table->gfilog[lg] = b;
		b = b << 1;
		//std::cout << b << ": ";
		if (b & x_to_w) {
			b = b ^ primPoly;
		}
	}
	_table->gflog[0] = 0;

	printTable (_table);
}


void printTable (GFTable* table) {
	// std::cout << std::endl << "GF Log:" << std::endl << "[";
	printf ("\nGF Log:\n[");
	for (int i = 0; i < 64; i++) {
		// std::cout << table.gflog[i] << ", ";
		printf ("%d, ", table->gflog[i]);
	}
	// std::cout << "]" << std::endl;
	printf ("]\n");

	// std::cout << "Exp Log:" << std::endl;
	printf("Exp Log:\n");
	for (int i = 0; i < 64; i++) {
		// std::cout << table.gfilog[i] << ", ";
		printf ("%d, ", table->gfilog[i]);
	}
	// std::cout << "]" << std::endl;
	printf ("]\n");
}