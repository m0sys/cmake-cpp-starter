// 010-TestCase.cpp
// And write tests in the same file:
#include "factorial/factorial.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Factorial of 0 is 1 (fail)", "[single-file]") { REQUIRE(factorial(0) == 1); }

TEST_CASE("Factorials of 1 and higher are computed (pass)", "[single-file]")
{
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3628800);
}

TEST_CASE("Factorials Debug of 1 and higher are computed (pass)", "[single-file]")
{
    REQUIRE(factorial_debug(1) == 1);
    REQUIRE(factorial_debug(2) == 2);
    REQUIRE(factorial_debug(3) == 6);
    REQUIRE(factorial_debug(10) == 3628800);
}
