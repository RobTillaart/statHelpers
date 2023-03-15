
[![Arduino CI](https://github.com/RobTillaart/statHelpers/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/statHelpers/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/statHelpers/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/statHelpers/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/statHelpers/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/statHelpers/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/statHelpers.svg?maxAge=3600)](https://github.com/RobTillaart/statHelpers/releases)


# statHelpers

Arduino library with a number of statistic helper functions.


## Description

This library contains functions that have the goal to help with 
basic statistical calculations like permutations, combinations,
and factorials.

It includes an experimental section for large numbers. 
Note that these are very computation (time) intensive so not suited for real time math :)

To print very large numbers - https://github.com/RobTillaart/PrintHelpers


## Interface

```cpp
#include "statHelpers.h"
```

### Permutation

Returns how many different ways one can choose a set of k elements from a set of n. 
The order does matter so (1, 2) is not equal to (2, 1). 
The limits mentioned is the n for which all k still work.

- **uint32_t permutations(n, k)** exact up to n = 12
- **uint64_t permutations64(n, k)** exact up to n = 20
- **double dpermutations(n, k)** not exact up to n = 34 (4 byte) or n = 170 (8 byte)

If you need a larger n but k is near 0 the functions will still work.
To which value of k the formulas work differs per value for n. 
No formula found, and build in an overflow detection takes overhead, so that is not done.


- **nextPermutation<Type>(array, size)** given an array of type T it finds the next permutation
of that array in a lexicographical way.  ABCD --> ABDC. 
Based upon // http://www.nayuki.io/page/next-lexicographical-permutation-algorithm although 
other same code examples exist.


### Factorial

- **uint32_t factorial(n)** exact up to n = 12.
- **uint64_t factorial64(n)** exact up to n = 20.  (Print 64 bit integers with my printHelpers)
- **double dfactorial(n)** not exact up to n = 34 (4 byte) or n = 170 (8 byte).
- **double stirling(n)** approximation function for factorial (right magnitude).
Constant run-time.

**dfactorial()** is quite accurate over the whole range.
**stirling()** is up to 3x faster for large n (> 100), 
but accuracy is less than the **dfactorial()**, see example.


### SemiFactorial

SemiFactorials are like factorials but skipping every other.

- **uint32_t semiFactorial(n)** exact up to 20!!
- **uint64_t semiFactorial64(n)** exact up to 33!!  (Print 64 bit integers with my printHelpers)
- **double dSemiFactorial(n)** not exact up to 56!! (4 byte) or 300!! (8 byte)

SemiFactorial are defined for
- **odd** values:  n x (n-2) x (n-4) ... x 1
- **even** values: n x (n-2) x (n-4) ... x 2


Notes:  
```n! = n!! x (n-1)!!``` this formula allows to calculate the value of n! indirectly


### Combinations

Returns how many different ways one can choose a set of k elements from a set of n. 
The order does **not** matter so (1, 2) is equal to (2, 1). 
The number of combinations grows fast so n is limited per function.
The limits mentioned is the n for which all k still work.

- **uint32_t combinations(n, k)**     n = 0 .. 30 (iterative version)
- **uint64_t combinations64(n, k)**   n = 0 .. 61 (iterative version)
- **uint32_t rcombinations(n, k)**    n = 0 .. 30 (recursive version, slightly slower)
- **uint64_t rcombinations64(n, k)**  n = 0 .. 61 (recursive version, slightly slower)
- **double dcombinations(n, k)**      n = 0 .. 125 (4bit)  n = 0 .. 1020 (8 bit) 

If you need a larger n but k is near 0 the functions will still work.
To which value of k the formulas work differs per value for n. 
No formula found, and build in an overflow detection takes overhead, so that is not done.


- **combPascal(n, k)** n = 0 .. 30 but due to double recursion per iteration it takes
time and a lot of it for larger values. Added for recreational purposes, limited tested.
Uses Pascal's triangle.


## Notes

- **perm1** is a sketch in the examples that shows a recursive permutation algorithm. 
It generates all permutations of a given char string and allows you to process every instance.
This sketch is added to this library as it fits in the context.


## Experimental 

#### 32 bit numbers

- **void bigFactorial(uint32_t n, double &mantissa, uint32_t &exponent)** 
returns a double mantissa between 0 and 10, and an integer exponent. 
- **void bigPermutation(uint32_t n, uint32_t k, double &mantissa, uint32_t &exponent)** 
returns a double mantissa between 0 and 10, and an integer exponent. 
- **void bigCombination(uint32_t n, uint32_t k, double &mantissa, uint32_t &exponent)** 
returns a double mantissa between 0 and 10, and an integer exponent. 

An experimental **bigFactorial(n)** calculation to get an idea of the big numbers. 
it can calculate factorials up to an exponent of 4294967295 max.  100.000.000! can be 
done in 38 minutes on an ESP32 at 240 MHz.  
Maximum value for n is **518678059! ==  2.1718890e4294967292** a number that took ~10 hours to calculate. 

An experimental **bigPermutation(n, k)** calculation, to handle big numbers too. 
Maximum value for n is **518678059** to have full range support. For small(er) 
values of k, n can even be much larger, but not larger than 4294967295 max.

An experimental **bigCombination(n, k)** calculation for big numbers. 
Not investigated what its maximum value is, but it should be higher than **518678059** as the number 
of combinations is always smaller than number of permutations.


#### 64 bit numbers- not investigated

To have support for huge numbers one could upgrade the code to use uint64_t as parameter and 
internally but calculating these values could take a lot of time, although **bigPermutations64(n, k)** 
and **bigCombinations64(n, k)** would work fast for small values of k. 

- **void bigFactorial64(uint64_t n, double &mantissa, uint64_t &exponent)** 
returns a double mantissa between 0 and 10, and an integer exponent.
- **void bigPermutation64(uint64_t n, uint64_t k, double &mantissa, uint64_t &exponent)** 
returns a double mantissa between 0 and 10, and an integer exponent.
- **void bigCombination64(uint64_t n, uint64_t k, double &mantissa, uint64_t &exponent)** 
returns a double mantissa between 0 and 10, and an integer exponent.

If someone has found the limits of these 64 bit versions, please let me know.


## Operation

See examples


## Future

#### Must

#### Should

- investigate valid range detection for a given (n, k) for combinations and permutations.
- Look for optimizations


#### Could

- investigate a bigFloat class to do math for permutations and combinations to substantially larger values.
- Look for ways to extend the scope
- **skipFactorial(uint32_t n, uint32_t skip)** == n x (n-skip) x (n -skip -skip) ... x S (depends on size of skip)
  - e.g. skipFactorial(12, 4) = 12 x 8 x 4.
  - skipFactorial(n, 2) == semiFactorial(n);


#### Wont

