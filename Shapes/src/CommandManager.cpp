#include "CommandManager.h"
#include <iostream>
CommandManager::CommandManager(){/*Please implement it*/

}
void CommandManager::ExecuteCMD(Command *cmd){/*Please implement it*/
    undocmds.push(cmd);
    cmd->Execute();
    while(!redocmds.empty()){
        redocmds.pop();
    }
    //std::cout << undocmds.size();
}
void CommandManager::RedoCMD(){/*Please implement it*/

    Command *temp;
    temp = redocmds.top();
    undocmds.push(temp);
    redocmds.pop();
    redocmds.top()->Redo();
}
void CommandManager::UndoCMD(){/*Please implement it*/

    Command *temp;
    temp = undocmds.top();
    redocmds.push(temp);
    undocmds.pop();
    undocmds.top()->Undo();
}
