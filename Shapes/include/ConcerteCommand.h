#ifndef CONCERTECOMMAND_H
#define CONCERTECOMMAND_H
#include "Command.h"
#include <vector>
#include <iostream>
#include "Media.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComboMedia.h"
#include "ShapeMedia.h"
#include "ComboMediaBuilder.h"
#include <string>
#include <cstring>
#include <stack>

class ConcerteCommand : public Command
{
    public:
        ConcerteCommand(string desc, string name, std::vector<Media*> *base, std::vector<int> sizes)
            :descs(desc), names(name), mediaBase(base),comboSizes(sizes){};
        /*ConcerteCommand(std::vector<Media*> sBase,std::vector<Media*> *pBase)
            :saveMediaBase(sBase), pointMediaBase(pBase){}*/
        //virtual ~ConcerteCommand();
        void Execute();
        void Undo();
        void Redo();
    private:
        bool IsMediaNameExist(string name);
        void Concerte();
        void Analyze(std::stack<MediaBuilder*> *mb, string content, std::vector<char*> name);
        vector<double> getValues(string content, int startPosition, int endPosition);
        string descs;
        string names;
        std::vector<Media*> *mediaBase;
        std::vector<int> comboSizes;
        //std::vector<Media*> *pointMediaBase;
};

#endif // CONCERTECOMMAND_H
