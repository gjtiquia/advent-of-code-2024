#include "day3.h"
#include "utils.h"

#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include <fstream>   // std::ifstreams
#include <sstream>   // std::stringstream
#include <string>    // std::string
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <cmath>     // std::abs

std::string day3Part1(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        fmt::print(stderr, "{} cannot be opened for reading!\n", filename);
        return "ERROR";
    }

    auto productSum{0};

    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        auto searchIndex{0lu};
        while (true)
        {
            auto startingIndex = line.find("mul(", searchIndex);
            if (startingIndex == std::string::npos)
                break;

            searchIndex = startingIndex + 1;

            auto openingBracketIndex = line.find("(", startingIndex);

            auto commaIndex = line.find(",", startingIndex);
            if (commaIndex == std::string::npos)
                continue;

            auto firstDigitStartIndex = openingBracketIndex + 1;
            auto firstDigitLength = commaIndex - firstDigitStartIndex;
            if (firstDigitLength < 1 || firstDigitLength > 3)
                continue;

            auto closingBracketIndex = line.find(")", startingIndex);
            if (closingBracketIndex == std::string::npos)
                continue;

            auto secondDigitStartIndex = commaIndex + 1;
            auto secondDigitLength = closingBracketIndex - secondDigitStartIndex;
            if (secondDigitLength < 1 || secondDigitLength > 3)
                continue;

            auto firstDigit = std::stoi(line.substr(firstDigitStartIndex, firstDigitLength));
            auto secondDigit = std::stoi(line.substr(secondDigitStartIndex, secondDigitLength));
            auto product = firstDigit * secondDigit;

            productSum += product;
        }
    }

    return std::to_string(productSum);
}

std::string day3Part2(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        fmt::print(stderr, "{} cannot be opened for reading!\n", filename);
        return "ERROR";
    }

    auto productSum{0};
    auto isEnabled{true};

    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        auto searchIndex{0lu};
        while (true)
        {
            auto startingIndex = line.find("mul(", searchIndex);
            if (startingIndex == std::string::npos)
                break;

            if (isEnabled)
            {
                auto dontIndex = line.find("don't()", searchIndex);
                if (dontIndex != std::string::npos && dontIndex < startingIndex)
                {
                    isEnabled = false;
                    searchIndex = dontIndex + 1;
                    continue;
                }
            }
            else
            {
                auto doIndex = line.find("do()", searchIndex);
                if (doIndex == std::string::npos)
                    break;

                if (doIndex < startingIndex)
                {
                    isEnabled = true;
                }
                else
                {
                    searchIndex = doIndex;
                    continue;
                }
            }

            searchIndex = startingIndex + 1;

            auto openingBracketIndex = line.find("(", startingIndex);

            auto commaIndex = line.find(",", startingIndex);
            if (commaIndex == std::string::npos)
                continue;

            auto firstDigitStartIndex = openingBracketIndex + 1;
            auto firstDigitLength = commaIndex - firstDigitStartIndex;
            if (firstDigitLength < 1 || firstDigitLength > 3)
                continue;

            auto closingBracketIndex = line.find(")", startingIndex);
            if (closingBracketIndex == std::string::npos)
                continue;

            auto secondDigitStartIndex = commaIndex + 1;
            auto secondDigitLength = closingBracketIndex - secondDigitStartIndex;
            if (secondDigitLength < 1 || secondDigitLength > 3)
                continue;

            auto firstDigit = std::stoi(line.substr(firstDigitStartIndex, firstDigitLength));
            auto secondDigit = std::stoi(line.substr(secondDigitStartIndex, secondDigitLength));
            auto product = firstDigit * secondDigit;

            productSum += product;
        }
    }

    return std::to_string(productSum);
}
