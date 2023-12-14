#include "ConfigReader.hpp"

ConfigReader::ConfigReader(const std::string &filename) : input_file{filename}
{
    if(!input_file.is_open())
        throw std::runtime_error("file open failure");
}

bool ConfigReader::checkCommand(std::string cmd)
{
    return (cmd == "UP" || cmd == "DOWN" || cmd == "LEFT" || cmd == "RIGHT" || cmd == "QUIT");
}

std::unordered_map<char, std::string> ConfigReader::readConfig()
{
    std::unordered_map<char, std::string> dict;
    std::set<std::string> cmds;

    for (std::string line; std::getline(input_file, line); ) 
    {
        size_t eq_pos = line.find("=");
        if (eq_pos != 1)
            throw std::invalid_argument("Incorrectly formed string in the config " + line);

        //std::cout << line[0] << std::endl;
        char key = tolower(line[0]);
        if (dict.contains(key))
            throw std::invalid_argument("Button already assigned " + std::string {key});
        //std::cout << key << "\n";
        std::string value = line.substr(eq_pos + 1);
        std::transform(value.begin(), value.end(), value.begin(), ::toupper);
        if (!checkCommand(value))
            throw std::invalid_argument("Unknown command in the config: " + value);

        if (cmds.contains(value))
            throw std::invalid_argument("Command already assigned " + value);
        cmds.insert(value);
        //std::cout << value << '\n';
        dict[key] = value;
    }
    if (dict.size() != static_cast<int>(Commands::COUNT))
        throw std::invalid_argument("Too few commands in the config");
    return dict;
}

/*std::unordered_map<std::string, char> ConfigReader::readConfig()
{
    std::unordered_map<std::string, char> dict;
    std::set<char> cmds;
    for (std::string line; std::getline(input_file, line); ) 
    {
        size_t eq_pos = line.find("=");
        if (eq_pos == std::string::npos)
            throw std::invalid_argument("Incorrectly formed string in the config " + line);

        std::string key = line.substr(0, eq_pos);
        std::transform(key.begin(), key.end(), key.begin(), ::toupper);
        //std::cout << key + "\n";
        if (!checkCommand(key))
            throw std::invalid_argument("Unknown command in the config: " + key);

        if (dict.contains(key))
            throw std::invalid_argument("Command already assigned " + key);

        char value = tolower(line.substr(eq_pos + 1)[0]);
        if (cmds.contains(value))
            throw std::invalid_argument("Button already assigned " + std::string {value});
        cmds.insert(value);
        //std::cout << value << '\n';
        dict[key] = value; 
    }
    if (dict.size() != static_cast<int>(Commands::COUNT))
        throw std::invalid_argument("Too few commands in the config");
    return dict;
}*/

ConfigReader::~ConfigReader()
{
    input_file.close();
}