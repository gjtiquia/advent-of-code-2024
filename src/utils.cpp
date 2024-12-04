#include "utils.h"

#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string
#include <vector>   // std::vector

std::vector<std::string> splitLineToWordsBySpaces(std::string line)
{
    std::vector<std::string> words{};

    std::stringstream stringstream{line};
    std::string word{};
    while (stringstream >> word)
        words.push_back(word);

    return words;
}

std::vector<int> splitLineToIntListBySpaces(std::string line)
{
    std::vector<int> intList{};

    std::stringstream stringstream{line};
    std::string word{};
    while (stringstream >> word)
        intList.push_back(std::stoi(word));

    return intList;
}

void debugLog(std::string message)
{
    std::cout << message + "\n";
}