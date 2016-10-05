#include "ComboShape.h"

ComboShape::ComboShape(std::vector<Shape*>& inputShapes):shapes(inputShapes){};

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
void ComboShape::addShape(ComboShape* inputShapes){
    vector<Shape*> temp = inputShapes->getShapes();
    shapes.insert(shapes.end(),temp.begin(),temp.end());
}
vector<Shape*> ComboShape::getShapes(){
    return shapes;
}
ComboShape::~ComboShape(){
}
