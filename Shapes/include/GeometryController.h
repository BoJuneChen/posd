#ifndef GEOMETRYCONTROLLER_H
#define GEOMETRYCONTROLLER_H
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ostream>
#include <fstream>
#include <stack>
#include "Media.h"
#include "Shapes.h"
#include "ComboMedia.h"
#include "ShapeMedia.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "DescriptionVisitor.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "NameVisitor.h"
#include "ComboMediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "Command.h"
#include "ConcerteCommand.h"
#include "CommandManager.h"

using namespace std;

class GeometryController
{
    public:
        GeometryController();
        void ExecuteCommand(string command);
        void DisplayCommandIndex();
        string GetResult();
        string GetComboMediaDes(string comboName);
    private:
        string GetDescs();
        string GetNames();
        std::vector<int> GetComboSize();
        string result="";
        Media* GetMediaByName(string name);
        void DefineNewMedia(std::vector<char*>);
        void AddMediaToCombo(std::vector<char*> command);
        void Show();
        void GetArea(string name); //done
        void GetPerimeter(string name); //done
        void DeleteMediaByName(string name);
        void DeleteMediaFromCombo(string comboName, string deleteName);
        void DeleteMediaFromCombo(std::vector<char*> command);
        void SaveFile(std::vector<char*> command);
        void LoadFromFile(std::vector<char*> command);
        void Concrete(std::stack<MediaBuilder *> *mb, string content,std::vector<char*> name);
        std::vector<double> getValues(string content, int startPosition, int endPosition);
        std::vector<Media* > mediaBase;
        CommandManager cmdManager;
};

#endif // GEOMETRYCONTROLLER_H
