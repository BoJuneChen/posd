#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H
#include "Command.h"
#include <stack>
#include <string>

class CommandManager
{
    public:
        CommandManager();
   		void ExecuteCMD(Command *cmd);
   		void RedoCMD();
   		void UndoCMD();
    private:
        std::stack<Command*> undocmds;
        std::stack<Command*> redocmds;
};

#endif // COMMANDMANAGER_H
