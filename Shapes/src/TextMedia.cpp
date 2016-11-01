#include "TextMedia.h"

TextMedia::TextMedia(Text *inputText):
    text(inputText){}

Text* TextMedia::getText(){
    return text;
}
Rectangle TextMedia::getRectangle(){
    return text->getRectangle();
}
string TextMedia::getTextString(){
    return text->getText();
}
string TextMedia::description(){
    return text->getRectangleDescription();
}
double TextMedia::area()const{
    return text->getRectangleArea();
}
double TextMedia::perimeter()const{
    return text->getRectanglePerimeter();
}
void TextMedia::accept(MediaVisitor* mediaVisitor){
    mediaVisitor->visitTextMedia(this);
}
string TextMedia::getType()const{
    return std::string("TextMedia");
}
