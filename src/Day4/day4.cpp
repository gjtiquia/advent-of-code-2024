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

    std::vector<std::vector<char>> charMatrix{};

    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        std::vector<char> row{};

        for (auto character : line)
            row.push_back(character);

        charMatrix.push_back(row);
    }

    auto width {charMatrix[0].size()};
    auto height {charMatrix.size()};

    fmt::print("Matrix initialized! x: {}, y: {}\n", width, height);


    // Horizontal
    // TODO : XMAS
    // TODO : SAMX
    
    
    auto xmasCount {0};
    auto samxCount {0};

    for (auto j {0}; j < height; j++)
    {
        auto row {charMatrix[j]};

	for (auto i{0}; i < width - 4; i++)
	{
        	if (row[i] == 'X' && row[i+1] == 'M' && row[i+2] == 'A' && row[i+3] == 'S')
			xmasCount++;

	}
    }


    fmt::print("x - XMAS: {}\n", xmasCount); 
    fmt::print("x - SAMX: {}\n", samxCount);

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
