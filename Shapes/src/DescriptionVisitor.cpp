#include "DescriptionVisitor.h"

DescriptionVisitor::DescriptionVisitor (): desc(std::string("")) {}
void DescriptionVisitor::visitShapeMedia(ShapeMedia *sm){
    desc += sm->getShape()->description();
}
void DescriptionVisitor::visitComboMedia(ComboMedia *cm){
    desc += std::string("combo(");
}
void DescriptionVisitor::visitTextMedia(TextMedia *textMedia){
    desc +=textMedia->description();
}
void DescriptionVisitor::finishVisit(){
    desc += std::string(")");
}
std::string DescriptionVisitor::getDescription() const {
    return desc;
}
