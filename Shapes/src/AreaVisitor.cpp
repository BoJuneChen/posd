#include "AreaVisitor.h"
AreaVisitor::AreaVisitor():
    totalArea(0){}

void AreaVisitor::visitComboMedia(ComboMedia *comboMedia){
    //do nothing
}
void AreaVisitor::visitShapeMedia(ShapeMedia *shapeMedia){
    totalArea += shapeMedia->area();
}
void AreaVisitor::visitTextMedia(TextMedia *textMedia){
    totalArea += textMedia->area();
}
double AreaVisitor::getTotalArea() const{
    return totalArea;
}
