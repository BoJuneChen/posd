#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "Rectangle.h"

class Text{
public:
    Text(Rectangle inputRect, string inputText);
    Rectangle getRectangle();
    string getText();
    double getRectangleArea();
    double getRectanglePerimeter();
    string getRectangleDescription();
private:
    Rectangle rect;
    string text;
};

#endif // TEXT_H
