#include <stdlib.h>
int t;
int* poly(int* A, int* B, int* C) {
    int z = 0;
    A = (A ? A : &z);
    B = (B ? B : &z);
    C = (C ? C : &z);
    t = ((*A) * (*A) * (*A) + (*B) * (*B) + (*C));
    return &t;
}