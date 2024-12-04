#include "day1.h"
#include "day2.h"
#include "day3.h"
#include <iostream>

int main()
{
    std::cout << "===== ADVENT OF CODE 2024 ===== \n";

    std::cout << "Day 1 Part 1: " + day1Part1("./src/Day1/input.txt") + "\n";
    std::cout << "Day 1 Part 2: " + day1Part2("./src/Day1/input.txt") + "\n";

    std::cout << "Day 2 Part 1: " + day2Part1("./src/Day2/input.txt") + "\n";
    std::cout << "Day 2 Part 2: " + day2Part2("./src/Day2/input.txt") + "\n";

    std::cout << "Day 3 Part 1: " + day3Part1("./src/Day3/input.txt") + "\n";
    std::cout << "Day 3 Part 2: " + day3Part2("./src/Day3/input.txt") + "\n";

    std::cout << "=============================== \n";
    return 0;
}
