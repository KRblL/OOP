#ifndef COMMAND_READER
#define COMMAND_READER

#include "ICommandReader.hpp"

class CommandReader: public ICommandReader
{
public:
    char readCommand() override;
};

#endif