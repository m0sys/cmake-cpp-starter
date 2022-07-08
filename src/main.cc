#include "coffee/coffee.h"
#include "spdlog/spdlog.h"
#include <fmt/core.h>
#include <iostream>

int main()
{
    std::cout << "Hello, World!\n";
    coffee();
    fmt::print("Hello, World from FMT!\n");
    spdlog::info("Welcome from SPDLOG");
}
