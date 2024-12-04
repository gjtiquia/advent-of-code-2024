#pragma once

#include <string> // std::string
#include <vector> // std::vector

std::vector<std::string> splitLineToWordsBySpaces(std::string line);
std::vector<int> splitLineToIntListBySpaces(std::string line);

void debugLog(std::string message);