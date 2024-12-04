#include "day1.h"
#include "utils.h"

#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include <fstream>   // std::ifstream
#include <sstream>   // std::stringstream
#include <string>    // std::string
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <cmath>     // std::abs

std::string day1Part1(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        fmt::print(stderr, "{} cannot be opened for reading!\n", filename);
        return "ERROR";
    }

    std::vector<int> list1{};
    std::vector<int> list2{};

    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        auto words = splitLineToIntListBySpaces(line);
        list1.push_back(words[0]);
        list2.push_back(words[1]);
    }

    // By default, sorts in ascending order
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    auto distanceSum{0};
    for (auto i{0u}; i < list1.size(); i++)
    {
        auto distance = std::abs(list1[i] - list2[i]);
        distanceSum += distance;
    }

    return std::to_string(distanceSum);
}

std::string day1Part2(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        fmt::print(stderr, "{} cannot be opened for reading!\n", filename);
        return "ERROR";
    }

    std::vector<int> list1{};
    std::vector<int> list2{};

    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        auto words = splitLineToWordsBySpaces(line);
        list1.push_back(std::stoi(words[0]));
        list2.push_back(std::stoi(words[1]));
    }

    auto totalSimilarityScore{0};
    for (auto targetID : list1)
    {
        auto count{0};
        for (auto id : list2)
        {
            if (id == targetID)
                count++;
        }

        totalSimilarityScore += targetID * count;
    }

    return std::to_string(totalSimilarityScore);
}
