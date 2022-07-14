#include "coffee/coffee.h"
#include "spdlog/spdlog.h"
#include <fmt/core.h>
#include <iostream>
#include <vector>

int main()
{
    using std::vector;
    std::cout << "Hello, World!\n";
    coffee();
    fmt::print("Hello, World from FMT!\n");
    spdlog::info("Welcome from SPDLOG");

    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    fmt::print("[");
    for (auto& it : v)
        fmt::print("{}, ", it);
    fmt::print("]\n");
}
