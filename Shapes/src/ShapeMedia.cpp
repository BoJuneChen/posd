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

void ShapeMedia::accept(MediaVisitor * mediaVisitor) {
    mediaVisitor->visitShapeMedia(this);
}
string ShapeMedia::getType()const{
    return std::string("ShapeMedia");
}

string ShapeMedia::description(){
    return shape->description();
}
