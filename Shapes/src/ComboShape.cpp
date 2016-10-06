#include "ComboShape.h"

ComboShape::ComboShape(std::vector<Shape*>& inputShapes):shapes(inputShapes){};
ComboShape::ComboShape(Shape* inputShape1,Shape* inputShape2){
    shapes.push_back(inputShape1);
    shapes.push_back(inputShape2);
}
double ComboShape::area()const {
    return sumOfArea(shapes);
}
double ComboShape::perimeter()const {
    return sumOfPerimeter(shapes);
}
void ComboShape::addShape(Shape* inputShape){
    shapes.push_back(inputShape);
}
void ComboShape::addShape(std::vector<Shape*>* inputShapes){
    shapes.insert(shapes.end(),inputShapes->begin(),inputShapes->end());
}
ComboShape::~ComboShape(){
}
