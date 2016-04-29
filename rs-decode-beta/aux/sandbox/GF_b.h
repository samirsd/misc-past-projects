#ifndef GF_H
#define GF_H

typedef struct GFTable {
	int gflog[256];
	int gfilog[256];
} GFTable;

extern GFTable* _table;

int GFAdd(int a, int b);
int GFSub(int a, int b);
int GFMul(int a, int b);
int GFInv(int a);
int GFDiv(int a, int b);
void generateGF(unsigned int primPoly);
void printTable(GFTable* table);

#endif /* GF_H */