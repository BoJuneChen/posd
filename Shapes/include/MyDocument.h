#ifndef MYDOCUMENT_H
#define MYDOCUMENT_H

#include "Document.h"
#include <fstream>
#include <iostream>

using namespace std;

class MyDocument : public Document {

public:
    void openFile(const string name);
    bool canOpenDocument(const string name);
    string readFile();

private:
    string shapeDescription;
    ifstream file;
};

#endif // MYDOCUMENT_H
