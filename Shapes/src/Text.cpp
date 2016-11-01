#include "Text.h"

Text::Text(Rectangle inputRect, string inputText):
    rect(inputRect),text(inputText){}

Rectangle Text::getRectangle(){
    return rect;
}
string Text::getText(){
    return text;
}
double Text::getRectangleArea(){
    return rect.area();
}
double Text::getRectanglePerimeter(){
    return rect.perimeter();
}
string Text::getRectangleDescription(){
    return rect.description();
}
