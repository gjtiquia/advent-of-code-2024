#include <fstream>       // std::ifstream
#include <iostream>      // std::cout
#include <sstream>       // std::stringstream
#include <string>        // std::string
#include <vector>        // std::vector
#include <bits/stdc++.h> // std::sort
#include <cmath>         // std::abs

// TODO : refactor this🤔 i want implementation details at the bottom of the code, and i want same file declaration
std::vector<std::string> splitLineToWordsBySpaces(std::string line);

int main()
{
    // const std::string FILENAME = "./Day1/part1Example.txt";
    const std::string FILENAME = "./Day1/input.txt";

    std::ifstream inputFileStream{FILENAME};
    if (!inputFileStream)
    {
        std::cerr << FILENAME + " cannot not be opened for reading!\n";
        return 1;
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

    // By default, sorts in ascending order
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int distanceSum{0};
    for (ulong i{0}; i < list1.size(); i++)
    {
        int distance = std::abs(list1[i] - list2[i]);
        std::cout << std::to_string(list1[i]) + " " + std::to_string(list2[i]) + " : " + std::to_string(distance) + "\n";

        distanceSum += distance;
    }

    std::cout << std::to_string(distanceSum) + "\n";
    return 0;
}

std::vector<std::string> splitLineToWordsBySpaces(std::string line)
{
    std::vector<std::string> words{};

    std::stringstream stringstream{line};
    std::string word{};
    while (stringstream >> word)
        words.push_back(word);

    return words;
}