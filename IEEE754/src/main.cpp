#include <iostream>
#include <cstdint>
#include <cmath>

// 16  bit    Half Precision
// 32  bit    Single Precision
// 64  bit    Double Precision
// 128 bit    Quadruple Precision
// 256 bit    Octuple Precision

// 16-bit System
// [ 0 | 0 0 0 0 0 | 0 0 0 0 0 0 0 0 0 0 ]
//  ─┬─  ────┬────   ─────────┬──────────
//  Sign  Exponent         Mantissa

// Bits:  0   1  2  3  4  5  6   7  8  9  10 11 12 13 14 15
// Type:  S   E  E  E  E  E  E   M  M  M  M  M  M  M  M  M

int main(int argc, char const* argv[]) {
    std::cout << "Hello, IEEE-754!\n";

    return 0;
}
