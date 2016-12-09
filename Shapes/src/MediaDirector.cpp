#include "MediaDirector.h"
#include "Media.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComboMediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

vector<double> MediaDirector::getValues(string content, int startPosition, int endPosition){
    vector<double> outputValues;
    double value;
    string desc = content.substr(startPosition + 2, endPosition - (startPosition + 2)); //2 means the shape title to first value's distance
    stringstream valueString(desc);
    while(valueString >> value) {
        outputValues.push_back(value);
        //cout << value << endl;
    }
    return outputValues;
}

void MediaDirector::setMediaBuilder(std::stack<MediaBuilder*> *mbs){
    mb = mbs;
}

void MediaDirector::concrete(string content){
    for(unsigned int i = 0; i < content.length(); i++){
        if(content[i] == 'c'){
            if(content[i+1] == 'o' && content[i+2] == 'm' && content[i+3] == 'b' && content[i+4] == 'o'){
                mb -> push(new ComboMediaBuilder());
                mb -> top() -> buildComboMedia();
            }
            else if(content[i+1] == '('){
                 int endPosition = content.find_first_of(')', i);
                 vector<double> value = getValues(content, i, endPosition);
                 i = endPosition;
                 Circle* circle = new Circle(value[0], value[1], value[2]);
                 mb -> top() -> buildShapeMedia(circle);
            }
        }
        else if(content[i] == 'r'){
            int endPosition = content.find_first_of(')', i);
            vector<double> value = getValues(content, i, endPosition);
            i = endPosition;
            Rectangle* rectangle = new Rectangle(value[0], value[1], value[2], value[3]);
            mb -> top() -> buildShapeMedia(rectangle);
        }
        else if(content[i] == 't'){
            int endPosition = content.find_first_of(')', i);
            vector<double> value = getValues(content, i, endPosition);
            i = endPosition;
            Triangle* triangle = new Triangle(value[0], value[1], value[2], value[3], value[4], value[5]);
            mb -> top() -> buildShapeMedia(triangle);
        }
        else if(content[i] == ')'){
            if(mb -> size() > 1){
                Media *combo = mb -> top() -> getMedia();
                mb -> pop();
                ComboMediaBuilder* topCombo = dynamic_cast<ComboMediaBuilder*> (mb -> top());
                topCombo -> addComboMedia(combo);
            }
        }
    }
}
