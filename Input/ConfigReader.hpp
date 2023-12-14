#ifndef FILE_WRAPPER
#define FILE_WRAPPER

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>

enum class Commands {UP, DOWN, LEFT, RIGHT, QUIT, COUNT};

class ConfigReader
{
    std::ifstream input_file;
    bool checkCommand(std::string cmd);
public:
    ConfigReader(const std::string &filename);
    //std::unordered_map<std::string, char> readConfig();
    std::unordered_map<char, std::string> readConfig();
    ~ConfigReader();
};

#endif