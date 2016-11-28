#include "MyDocument.h"

void MyDocument::openFile(const string name){
    file.open(name);
}

bool MyDocument::canOpenDocument(const string name){
    if(ifstream(name)) {
        return true;
    }
    else {
        return false;
    }
}

string MyDocument::readFile(){
    getline(file, shapeDescription);
    file.close();
    return shapeDescription;
}
