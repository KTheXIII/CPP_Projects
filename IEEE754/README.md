# IEEE754

16-bit Half Precision

32-bit Single Precision

64-bit Double Precision

128-bit Quadruple Precision

256-bit Octuple Precision

```
16-bit System
[ 0 | 0 0 0 0 0 | 0 0 0 0 0 0 0 0 0 0 ]
  ┬   ────┬────   ─────────┬─────────  
 Sign  Exponent         Mantissa       
```

## Convert

Convert 45.45 to IEEE-754 single-precision format

Left side of the decimal separator

45 → binary

```
0x2D
0b101101
```

Right side of the decimal separator

0.45 → binary

```
0.45 ⋅ 2 = 0.9
0.90 ⋅ 2 = 1.8
0.80 ⋅ 2 = 1.6
0.60 ⋅ 2 = 1.2
0.20 ⋅ 2 = 0.4
0.40 ⋅ 2 = 0.8

0b011100
```

Combine the two

```
          Gonna be repeating
         ┌───
101101.011100

```

Turn it into scientific notation

```
                  Exponent
         ────     ┴
1.01101011100 ⋅ 2^5
  ─────┬─────  
    Mantisa
```

IEEE-754 values value

```
S = 0
E = 5      ────
m = 01101011100
```

IEEE-754 single precision 32-bit bit field

```
[ S | Exponent (8) | mantisa (23) ]
      └	biased
```

Add the 127 to number 5

```
E = 5 => 132 => (1000 0100)
```

```
S  E          m
0  1000 0100  01101011100110011001100
```