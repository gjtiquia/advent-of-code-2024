#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::string FILENAME = "./Day1/input.txt";

    std::ifstream inputFileStream{FILENAME};
    if (!inputFileStream)
    {
        std::cerr << FILENAME + " cannot not be opened for reading!\n";
        return 1;
    }

    std::vector<std::string> lines{};
    std::string line{};
    while (std::getline(inputFileStream, line))
    {
        lines.push_back(line);
    }

    // TODO : just for testing vectors, should optimize lol, could do per line operation on the while loop above
    for (u_long i{0}; i < lines.size(); i++)
    {
        std::cout << std::to_string(i) + ": " + lines[i] + "\n";
    }

    return 0;
}
