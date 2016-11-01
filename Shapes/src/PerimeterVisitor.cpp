#include "PerimeterVisitor.h"

PerimeterVisitor::PerimeterVisitor():
    totalPerimeter(0){}

void PerimeterVisitor::visitComboMedia(ComboMedia *comboMedia){
    //do nothing
}
void PerimeterVisitor::visitShapeMedia(ShapeMedia *shapeMedia){
    totalPerimeter+=shapeMedia->perimeter();
}
void PerimeterVisitor::visitTextMedia(TextMedia *textMedia){
    totalPerimeter+=textMedia->perimeter();
}
double PerimeterVisitor::getTotalPerimeter () const{
    return totalPerimeter;
}

