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

using namespace std;

class GeometryController
{
    public:
        GeometryController();
        //virtual ~GeometryController();
        void ExecuteCommand(string command);

    private:
        Media* GetMediaByName(string name);
        void DefineNewMedia(std::vector<char*>);
        void AddMediaToCombo(std::vector<char*> command);
        void Show();
        void GetArea(string name);
        void GetPerimeter(string name);
        void DeleteMediaByName(string name);
        void DeleteMediaFromCombo(std::vector<char*> command);
        void SaveFile(std::vector<char*> command);

        std::vector<Media* > mediaBase;
};

#endif // GEOMETRYCONTROLLER_H
