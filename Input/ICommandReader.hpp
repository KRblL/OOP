#ifndef ICOMMAND_READER
#define ICOMMAND_READER

class ICommandReader
{
public:
    virtual char readCommand() = 0;
};

#endif