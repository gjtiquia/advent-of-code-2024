#include "day1.h"
#include "day2.h"
#include "day3.h"

#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include <iostream>

int main()
{
    fmt::print("===== ADVENT OF CODE 2024 =====\n");

    fmt::print("Day 1 Part 1: {}\n", day1Part1("./src/Day1/input.txt"));
    fmt::print("Day 1 Part 2: {}\n", day1Part2("./src/Day1/input.txt"));

    fmt::print("Day 2 Part 1: {}\n", day2Part1("./src/Day2/input.txt"));
    fmt::print("Day 2 Part 2: {}\n", day2Part2("./src/Day2/input.txt"));

    fmt::print("Day 3 Part 1: {}\n", day3Part1("./src/Day3/input.txt"));
    fmt::print("Day 3 Part 2: {}\n", day3Part2("./src/Day3/input.txt"));

    fmt::print("=============================== \n");
    return 0;
}
