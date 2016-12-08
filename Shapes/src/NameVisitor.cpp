#include "NameVisitor.h"

NameVisitor::NameVisitor (): names(std::string("")) {}
void NameVisitor::visitShapeMedia(ShapeMedia *sm){
    names += sm->getName();
    names += std::string(" ");
}
void NameVisitor::visitComboMedia(ComboMedia *cm){
    names += cm->getName();
    names += std::string("{");
}
void NameVisitor::visitTextMedia(TextMedia *textMedia){
    names +=textMedia->getName();
}
void NameVisitor::finishVisit(){
    names += std::string("}");
}
std::string NameVisitor::getNames() const {
    return names;
}
