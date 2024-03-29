#pragma once
#include <vector>
#include <string>
#include <iostream>
enum Facelet {
    /*
                  |************|
                  |*u1**u2**u3*|
                  |************|
                  |*u4**u5**u6*|
                  |************|
                  |*u7**u8**u9*|
                  |************|
     |************|************|************|************|
     |*l1**l2**l3*|*f1**f2**f3*|*r1**r2**r3*|*b1**b2**b3*|
     |************|************|************|************|
     |*l4**l5**l6*|*f4**f5**f6*|*r4**r5**r6*|*b4**b5**b6*|
     |************|************|************|************|
     |*l7**l8**l9*|*f7**f8**f9*|*r7**r8**r9*|*b7**b8**b9*|
     |************|************|************|************|
                  |************|
                  |*d1**d2**d3*|
                  |************|
                  |*d4**d5**d6*|
                  |************|
                  |*d7**d8**d9*|
                  |************|
    */
    u1, u2, u3, u4, u5, u6, u7, u8, u9,
    r1, r2, r3, r4, r5, r6, r7, r8, r9,
    f1, f2, f3, f4, f5, f6, f7, f8, f9,
    d1, d2, d3, d4, d5, d6, d7, d8, d9,
    l1, l2, l3, l4, l5, l6, l7, l8, l9,
    b1, b2, b3, b4, b5, b6, b7, b8, b9
};
enum Color { U, R, F, D, L, B };
enum Corner { URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB, empty_corner = -1 };
enum Edge { UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR, empty_edge = -1 };
enum Move { U1, U2, U3, R1, R2, R3, F1, F2, F3, D1, D2, D3, L1, L2, L3, B1, B2, B3 };