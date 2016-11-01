#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H

#include "Media.h"
#include "Text.h"

class TextMedia : public Media{
public:
    TextMedia(Text *inputText);
    Text* getText();
    Rectangle getRectangle();
    string getTextString();
    string description();
    double area() const;
    double perimeter() const;
    void accept(MediaVisitor* mediaVisitor);
    string getType()const ;
private:
    Text *text;
};

#endif // TEXTMEDIA_H
