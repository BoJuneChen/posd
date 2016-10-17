#include "ShapeMedia.h"

ShapeMedia::ShapeMedia( Shape* s ): shape(s) {}

double ShapeMedia::area() const{
    return shape->area() ;
}

double ShapeMedia::perimeter() const{
    return shape->perimeter();
}

Shape * ShapeMedia::getShape()const{
    return shape;
}
