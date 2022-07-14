#include "factorial.h"
#include <spdlog/spdlog.h>

int factorial(int num)
{
    // return number <= 1 ? number : factorial(number - 1) * number; // fail
    return num <= 1 ? 1 : factorial(num - 1) * num; // pass
}

int factorial_debug(int num)
{
    // return number <= 1 ? number : factorial(number - 1) * number; // fail
    spdlog::info("num: {}", num);
    return num <= 1 ? 1 : factorial(num - 1) * num; // pass
}
