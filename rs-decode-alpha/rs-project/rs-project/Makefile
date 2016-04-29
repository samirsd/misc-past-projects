SRCS=rs_alpha.c linear_alg.c gf.c

# This should be modified on a Windows O.S. to reflect the right extension.
OFILES= rs_alpha.o linear_alg.o gf.o

# Names of the compiler  / linker
CC=cc
LD=cc
# The 'CFLAGS' is a Makefile variable holding the arguments to the compiler. 
# In this case, we ask the compiler to 
# (1) only compile, not link (-c)
# (2) generate debug information (-g)
# Similarly, the 'LFLAGS' is a variable holding options for the linker and we
# ask to include debug information.

CFLAGS=-c -g -std=c11 $(INC)
LFLAGS=-g 

all: rs
	@echo "Done!"

rs: $(OFILES)
	$(CC) $(LFLAGS) $(OFILES) -o $@

rs_alpha.o : rs_alpha.c gf.h linear_alg.h
	$(CC) $(CFLAGS) $< -o $@

linear_alg.o : linear_alg.c linear_alg.h gf.h
	$(CC) $(CFLAGS) $< -o $@

gf.o : gf.c gf.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OFILES) rs
