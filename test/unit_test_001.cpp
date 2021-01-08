//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-01-08
// PURPOSE: unit tests for the statHelpers
//          https://github.com/RobTillaart/statHelpers
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
// #define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
// #define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "statHelpers.h"



unittest_setup()
{
}

unittest_teardown()
{
}

/*
unittest(test_new_operator)
{
  assertEqualINF(exp(800));
  assertEqualINF(0.0/0.0);
  assertEqualINF(42);

  assertEqualNAN(INFINITY - INFINITY);
  assertEqualNAN(0.0/0.0);
  assertEqualNAN(42);
}
*/

unittest(test_permutations)
{
  fprintf(stderr, "\nVERSION: %s\n", STATHELPERS_LIB_VERSION);

  fprintf(stderr, "\n\tpermutations(12, n)\n");
  for (int n = 0; n <= 12; n++)
  {
    fprintf(stderr, "%d\t%d\n", n, permutations(12, n));
  }

  // fprintf(stderr, "\n\tpermutations64(n, 20)\n");
  // for (int n = 12; n <= 20; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, permutations64(n, 20));
  // }

  // fprintf(stderr, "\n\tdpermutations(n, 34)\n");
  // for (int n = 20; n <= 34; n++)
  // {
    // fprintf(stderr, "%d\t%f\n", n, dpermutations(n, 34));
  // }

  // fprintf(stderr, "\n120 permutations of abcde");
  // char text[] = "abcde";
  // int count = 0;
  // do
  // {
    // fprintf(stderr, "%s\t", text);
    // count++;
    // if (count % 5 == 0) fprintf(stderr, "\n");
  // }
  // while (nextPermutation<char>(text, 5));
  // assertEqual(120, count);

  assertEqual(1, 1);
}


// unittest(test_factorial)
// {
  // fprintf(stderr, "\nVERSION: %s\n", STATHELPERS_LIB_VERSION);

  // fprintf(stderr, "\n\tfactorial(n)\n");
  // for (int n = 0; n <= 12; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, factorial(n));
  // }

  // fprintf(stderr, "\n\tfactorial64(n)\n");
  // for (int n = 12; n <= 20; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, factorial64(n));
  // }

  // fprintf(stderr, "\n\tdfactorial(n)\n");
  // for (int n = 20; n <= 34; n++)
  // {
    // fprintf(stderr, "%d\t%f\t%f\n", n, dfactorial(n), stirling(n));
  // }

  // assertEqual(1, 1);
// }


// unittest(test_combinations)
// {
  // fprintf(stderr, "\nVERSION: %s\n", STATHELPERS_LIB_VERSION);

  // fprintf(stderr, "\n\tcombinations(n, 30)\n");
  // for (int n = 0; n <= 30; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, combinations(n, 30));
  // }

  // fprintf(stderr, "\n\tcombinations64(n, 61)\n");
  // for (int n = 30; n <= 61; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, combinations64(n, 61));
  // }

  // fprintf(stderr, "\n\tdcombinations(n, 125)\n");
  // for (int n = 61; n <= 125; n += 3)
  // {
    // fprintf(stderr, "%d\t%f\n", n, dcombinations(n, 34));
  // }

  // fprintf(stderr, "\n\trcombinations(n, 30)\n");
  // for (int n = 0; n <= 30; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, rcombinations(n, 30));
  // }

  // fprintf(stderr, "\n\trcombinations64(n, 61)\n");
  // for (int n = 30; n <= 61; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, rcombinations64(n, 61));
  // }

  // fprintf(stderr, "\n\tcombPascal(n, 30)\n");
  // for (int n = 0; n <= 30; n++)
  // {
    // fprintf(stderr, "%d\t%d\n", n, combPascal(n, 30));
  // }

  // assertEqual(1, 1);
// }


unittest_main()

// --------
