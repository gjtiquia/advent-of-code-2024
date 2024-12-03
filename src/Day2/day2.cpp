#include "day2.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>

std::string day2Part1(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        std::cerr << filename + " cannot not be opened for reading!\n";
        return "ERROR";
    }

    auto safeReportCount{0};

    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        auto isReportSafe{true};

        // We assume levelList.size() > 1
        auto levelList = splitLineToIntListBySpaces(line);

        auto firstLevel{levelList[0]};
        auto secondLevel{levelList[1]};
        auto isFirsLevelIncreasing{firstLevel < secondLevel};

        for (auto i{1u}; i < levelList.size(); i++)
        {
            auto previousLevel{levelList[i - 1]};
            auto currentLevel{levelList[i]};

            auto isPreviousLevelIncreasing{previousLevel < currentLevel};
            if (isPreviousLevelIncreasing != isFirsLevelIncreasing)
            {
                isReportSafe = false;
                break;
            }

            auto difference{std::abs(previousLevel - currentLevel)};
            if (difference < 1 || difference > 3)
            {
                isReportSafe = false;
                break;
            }
        }

        if (isReportSafe)
            safeReportCount++;
    }

    return std::to_string(safeReportCount);
}

std::string day2Part2(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        std::cerr << filename + " cannot not be opened for reading!\n";
        return "ERROR";
    }

    return "TODO";
}