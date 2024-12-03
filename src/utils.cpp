#include "utils.h"

#include <sstream> // std::stringstream
#include <string>  // std::string
#include <vector>  // std::vector

std::vector<std::string> splitLineToWordsBySpaces(std::string line)
{
    std::vector<std::string> words{};

    std::stringstream stringstream{line};
    std::string word{};
    while (stringstream >> word)
        words.push_back(word);

    return words;
}