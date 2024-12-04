#include "day3.h"
#include "utils.h"

#include <fstream>   // std::ifstream
#include <iostream>  // std::cout
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
        std::cerr << filename + " cannot not be opened for reading!\n";
        return "ERROR";
    }

    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        debugLog("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
        debugLog(line);

        auto searchIndex{0lu};
        while (true)
        {
            auto startingIndex = line.find("mul(", searchIndex);
            searchIndex++;

            if (startingIndex == std::string::npos)
                break;

            auto openingBracketIndex = line.find("(", startingIndex);

            auto commaIndex = line.find(",", startingIndex);
            if (commaIndex == std::string::npos)
                continue;

            auto firstDigitCount = commaIndex - openingBracketIndex - 1;
            if (firstDigitCount < 1 || firstDigitCount > 3)
                continue;

            auto closingBracketIndex = line.find(")", startingIndex);
            if (closingBracketIndex == std::string::npos)
                continue;

            auto secondDigitCount = closingBracketIndex - commaIndex - 1;
            if (secondDigitCount < 1 || secondDigitCount > 3)
                continue;

            debugLog("Found '(', ',', and ')' at indexes: " + std::to_string(openingBracketIndex) + ", " + std::to_string(commaIndex) + ", " + std::to_string(closingBracketIndex));
            // debugLog(std::to_string(secondDigitCount));
        }
    }

    return "TODO";
}

std::string day3Part2(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        std::cerr << filename + " cannot not be opened for reading!\n";
        return "ERROR";
    }

    return "TODO";
}
