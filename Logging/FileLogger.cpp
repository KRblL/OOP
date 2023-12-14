#include "FileLogger.hpp"

FileLogger::FileLogger() : output_file{"../Logging/logs"}
{
    if (!output_file.is_open())
        throw std::runtime_error("file open failure");
}

void FileLogger::getLog(const Message &message)
{
    output_file << message;
}

FileLogger::~FileLogger()
{
    output_file.close();
}