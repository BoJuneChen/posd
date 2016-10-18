#include "AreaVisitor.h"
AreaVisitor::AreaVisitor():
    totalArea(0){}

void AreaVisitor::visitComboMedia(ComboMedia *comboMedia){
    //do nothing
}
void AreaVisitor::visitShapeMedia(ShapeMedia *shapeMedia){
    totalArea += shapeMedia->area();
}
double AreaVisitor::getTotalArea() const{
    return totalArea;
}
