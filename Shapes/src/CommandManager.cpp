#include "CommandManager.h"
#include <iostream>
CommandManager::CommandManager(){/*Please implement it*/
    while(!redocmds.empty()){
        redocmds.pop();
    }
    while(!undocmds.empty()){
        undocmds.pop();
    }
}
void CommandManager::ExecuteCMD(Command *cmd){/*Please implement it*/
    undocmds.push(cmd);
    //cmd->Execute();
    while(!redocmds.empty()){
        redocmds.pop();
    }
    //std::cout << undocmds.size();
}
void CommandManager::RedoCMD(){/*Please implement it*/
    if(redocmds.size()>0){
        Command *temp;
        temp = redocmds.top();
        undocmds.push(temp);
        redocmds.pop();
        undocmds.top()->Redo();
    }
    else{
        std::cout << "Nothing can redo" <<std::endl;
    }
}
void CommandManager::UndoCMD(){/*Please implement it*/
    //std::cout<< "under Undo" <<std::endl;
    //std::cout<< undocmds.size() <<std::endl;
    if(undocmds.size()>1){
        Command *temp;
        //std::cout<< "Undo step1" <<std::endl;
        temp = undocmds.top();
        //std::cout<< "Undo step2" <<std::endl;
        redocmds.push(temp);
        //std::cout<< "Undo step3" <<std::endl;
        undocmds.pop();
        undocmds.top()->Undo();
    }
    else{
        std::cout << "Nothing can undo" <<std::endl;
    }
}
