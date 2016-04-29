typedef struct gfTable {
    unsigned short *gflog;
    unsigned short *gfilog;

} gfTable;

struct gfTable setup_tables(int w);

int mult(int a, int b);

int divide(int a, int b);

int add(int a, int b);

int sub(int a, int b);

int takePower(int x, int n);

int toPos(int length, int a);