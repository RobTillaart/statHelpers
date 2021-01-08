#pragma once
//
//    FILE: statHelpers.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: Arduino library with a number of statistic helper functions.
//    DATE: 2020-07-01
//     URL: https://github.com/RobTillaart/statHelpers


#include "Arduino.h"


///////////////////////////////////////////////////////////////////////////
//
// PERMUTATIONS
//

uint32_t permutations(uint8_t n, uint8_t k)
{
  uint32_t rv = 1;
  for (uint8_t i = n; i > (n - k); i--) rv *= i;
  return rv;
}


uint64_t permutations64(uint8_t n, uint8_t k)
{
  uint64_t rv = 1;
  for (uint8_t i = n; i > (n - k); i--) rv *= i;
  return rv;
}


double dpermutations(uint8_t n, uint8_t k)
{
  double rv = 1;
  for (uint8_t i = n; i > (n - k); i--) rv *= i;
  return rv;
}


/*
http://wordaligned.org/articles/next-permutation snippet

As an example consider finding the next permutation of:

8342666411
The longest monotonically decreasing tail is 666411, and the corresponding head is 8342.

8342 666411
666411 is, by definition, reverse-ordered, and cannot be increased by permuting its elements. To find the next permutation, we must increase the head; a matter of finding the smallest tail element larger than the head’s final 2.

8342 666411
Walking back from the end of tail, the first element greater than 2 is 4.

8342  666411
Swap the 2 and the 4

8344 666211
Since head has increased, we now have a greater permutation. To reduce to the next permutation, we reverse tail, putting it into increasing order.

8344 112666
Join the head and tail back together. The permutation one greater than 8342666411 is 8344112666.
*/


// http://www.nayuki.io/page/next-lexicographical-permutation-algorithm

// b = nextPermutation<char>(array, 100);
template <typename T>
bool nextPermutation(T * array,  uint16_t size)
{
  // Find longest non-increasing suffix
  int i = size - 1;
  while (i > 0 && array[i - 1] >= array[i]) i--;
  // Now i is the head index of the suffix

  // Are we at the last permutation already?
  if (i <= 0) return false;

  // Let array[i - 1] be the pivot
  // Find rightmost element that exceeds the pivot
  int j = size - 1;
  while (array[j] <= array[i - 1])
    j--;
  // Now the value array[j] will become the new pivot
  // Assertion: j >= i

  // Swap the pivot with j
  T temp = array[i - 1];
  array[i - 1] = array[j];
  array[j] = temp;

  // Reverse the suffix
  j = size - 1;
  while (i < j)
  {
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    i++;
    j--;
  }
  return true;
}


///////////////////////////////////////////////////////////////////////////
//
// FACTORIAL
// 

// exact ==> 12!
uint32_t factorial(uint8_t n)
{
  uint32_t f = 1;
  for (int i = 2; i <= n; i++) f *= i;
  return f;
}


// exact ==> 20!
uint64_t factorial64(uint8_t n)
{
  uint64_t f = 1;
  for (int i = 2; i <= n; i++) f *= i;
  return f;
}


// float  => 34!
// double => 170!
double dfactorial(uint8_t n)
{
  double f = 1;
  for (int i = 2; i <= n; i++) f *= i;
  return f;
}


// striling is an approximation function for factorial(n).
// float  => 26!
// double => 143!
double stirling(uint8_t n)
{
  double v = exp(-n) * pow(n, n) * sqrt(TWO_PI * n);
  return v;
}


///////////////////////////////////////////////////////////////////////////
//
// COMBINATIONS
// 

// works for n = 0..30 for all k
uint32_t combinations(uint16_t n, uint16_t k)
{
  if ((k == 0) || (k == n)) return 1;
  if (k < (n-k)) k = n - k; // symmetry
  uint32_t rv = n;
  uint8_t p = 2;
  for (uint8_t i = n-1; i > k; i--)
  {
    // if ((0xFFFFFFFF / i) < rv) return 0;
    rv = (rv * i) / p;
    p++;
  }
  return rv;
}


// works for n = 0..61 for all k
uint64_t combinations64(uint16_t n, uint16_t k)
{
  if ((k == 0) || (k == n)) return 1;
  if (k < (n-k)) k = n - k; // symmetry
  uint64_t rv = n;
  uint8_t p = 2;
  for (uint8_t i = n-1; i > k; i--)
  {

    rv = (rv * i) / p;
    p++;
  }
  return rv;
}


// experimental - not exact but allows large values
// float  (4 bits) works till n = 125    for all k
// double (8 bits) works till n = 1020   for all k
double dcombinations(uint16_t n, uint16_t k)
{
  if ((k == 0) || (k == n)) return 1;
  if (k < (n-k)) k = n - k; // symmetry
  double rv = n;
  uint16_t p = 2;
  for (uint16_t i = n-1; i > k; i--)
  {

    rv = (rv * i) / p;
    p++;
  }
  return rv;
}


// recursive (mind your stack)
// works for n = 0..30 for all k
uint32_t rcombinations(uint16_t n, uint16_t k)
{
  if (k > (n-k)) k = n - k; // symmetry
  if (k == 0) return 1;
  return (n * rcombinations(n - 1, k - 1)) / k;
}


// recursive
// works for n = 0..61 for all k
uint64_t rcombinations64(uint16_t n, uint16_t k)
{
  if (k > (n-k)) k = n - k; // symmetry
  if (k == 0) return 1;
  return (n * rcombinations64(n - 1, k - 1)) / k;
}


// very slow recursive way by means of Pascals triangle.
// works for n = 0..30 for all k  (but takes a lot of time)
uint32_t combPascal(uint16_t n, uint16_t k)
{
  if (k > (n-k)) k = n - k; // symmetry
  if (k > n ) return 0;
  if (k == 0) return 1;
  if (n < 2) return 1;
  uint32_t rv = combPascal(n-1, k-1);
  rv += combPascal(n-1, k);
  return rv;
}

// -- END OF FILE -- 
