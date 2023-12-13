#ifndef FILE_LOGGER
#define FILE_LOGGER

#include "ILogger.hpp"
#include <fstream>
#include <iostream>

class FileLogger : public Logger
{
    std::ofstream output_file;
public:
    FileLogger();
    void getLog(const Message &message) override;
    ~FileLogger();
};

#endif