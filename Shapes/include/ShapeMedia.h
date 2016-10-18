#ifndef SHAPEMEDIA_H
#define SHAPEMEDIA_H
#include "Media.h"
#include "Shapes.h"

class ShapeMedia : public Media {

private:
    Shape* shape ;

public :
    ShapeMedia( Shape* s );
    void accept(MediaVisitor * mediaVisitor); //For hw#3 problem 2,3
    double area() const; //For hw#3 problem 1
    double perimeter() const; //For hw#3 problem 1
    Shape * getShape() const;
};
#endif // SHAPEMEDIA_H
