#include "day4.h"
#include "utils.h"

#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include <fstream>   // std::ifstreams
#include <sstream>   // std::stringstream
#include <string>    // std::string
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <cmath>     // std::abs

std::string day4Part1(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        fmt::print(stderr, "{} cannot be opened for reading!\n", filename);
        return "ERROR";
    }

    return "TODO";
}

std::string day4Part2(std::string filename)
{
    std::ifstream inputFileStream{filename};
    if (!inputFileStream)
    {
        fmt::print(stderr, "{} cannot be opened for reading!\n", filename);
        return "ERROR";
    }

    return "TODO";
}
