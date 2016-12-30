#ifndef CONCERTECOMMAND_H
#define CONCERTECOMMAND_H
#include "Command.h"
#include <vector>
#include "Media.h"

class ConcerteCommand : public Command
{
    public:
        ConcerteCommand(string desc, string name, std::vector<Media*> base)
            :descs(desc), names(name), mediaBase(base){};
        /*ConcerteCommand(std::vector<Media*> sBase,std::vector<Media*> *pBase)
            :saveMediaBase(sBase), pointMediaBase(pBase){}*/
        //virtual ~ConcerteCommand();
        void Execute();
        void Undo(){};
        void Redo(){};
    private:
        string descs;
        string names;
        std::vector<Media*> mediaBase;
        //std::vector<Media*> *pointMediaBase;
};

#endif // CONCERTECOMMAND_H
