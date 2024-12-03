#include "day1.h"
#include "utils.h"

#include <fstream>       // std::ifstream
#include <iostream>      // std::cout
#include <sstream>       // std::stringstream
#include <string>        // std::string
#include <vector>        // std::vector
#include <bits/stdc++.h> // std::sort
#include <cmath>         // std::abs

std::string day1Part1(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        std::cerr << filename + " cannot not be opened for reading!\n";
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
        // std::cout << std::to_string(list1[i]) + " " + std::to_string(list2[i]) + " : " + std::to_string(distance) + "\n";
        distanceSum += distance;
    }

    return std::to_string(distanceSum);
}

std::string day1Part2(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        std::cerr << filename + " cannot not be opened for reading!\n";
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
    for (auto i{0u}; i < list1.size(); i++)
    {
        auto targetID = list1[i];

        auto count{0};
        for (auto j{0u}; j < list2.size(); j++)
        {
            auto id = list2[j];
            if (id == targetID)
                count++;
        }

        totalSimilarityScore += targetID * count;
    }

    return std::to_string(totalSimilarityScore);
}