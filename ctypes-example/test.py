#!/usr/bin/python    
import numpy as np
import ctypes
from ctypes import *

# Load C functions into Python
# Make sure to compile test.c into a .so file first
# gcc -shared -fPIC test.c -o test.so

cdll.LoadLibrary("libc.so.6") # doctest: +LINUX                               
libc = CDLL("libc.so.6")     # doctest: +LINUX  
lib = ctypes.cdll['./test.so']     
fib = lib['fib']

print "Fib" ,fib(6)


qsortt = lib['qsortt']

pa = [5, 1, 7, 33, 99]
print pa

def cnv(a):
    rat = c_int * len(a)
    ra = rat()
    k=0
    for i in a:
            ra[k] = c_int(i)
            k += 1
    return ra
print "cnv(pa): " , cnv(pa)

for ci in pa:
        print ci,
print ""

# Allocate an array of double in Python using NumPy
ia = cnv(pa)
qsortt.restype = None

CMPFUNC = CFUNCTYPE(c_int, POINTER(c_int), POINTER(c_int))

def py_cmp_func(a,b):
	print "py_cmp_func", a[0], b[0]
	return a[0] - b[0]

cmp_func = CMPFUNC(py_cmp_func)

qsortt(ia, len(ia), sizeof(c_int), cmp_func)

for i in ia:
        print i,
