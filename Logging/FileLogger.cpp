#include "FileLogger.hpp"

FileLogger::FileLogger() : output_file{"../Logging/logs"}
{
    if (!output_file.is_open())
        throw std::runtime_error("file open failure");
}

void FileLogger::getLog(const Message &message)
{
    std::cout << "HERE\n";
    output_file << message.getMessage();
}

FileLogger::~FileLogger()
{
    if (output_file.is_open())
        std::cout << "OPEN\n";
    output_file.close();
    if (!output_file.is_open())
        std::cout << "CLOSED\n";
}