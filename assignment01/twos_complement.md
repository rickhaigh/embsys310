# Why use two's complement to represent negative numbers?

Two's complement is the method used by most systems to represent negative numbers.  This is because two's complement lets us represent, add, subtract and multiply negative and positive numbers with simple hardware.  It eliminates the need to inspect the sign of the numbers.  Conversion from binary to two's complement is also easy: flip all the bits and add one.  Two's complement also includes just a single 0.

Three-bit signed integers
-------------------------
Decimal value|Two's-complement Representation
-------------|-------------------------------
0|000
1|001
2|010
3|011
−4|100
−3|101
−2|110
−1|111

https://en.wikipedia.org/wiki/Two%27s_complement