#include "ComboMediaBuilder.h"

void ComboMediaBuilder::buildComboMedia() {
    media = new ComboMedia;
}
void ComboMediaBuilder::buildShapeMedia(Shape * s) {
    if(!media)
        throw std::string("null point ex") ;
    media->add(new ShapeMedia(s));
}
void ComboMediaBuilder::addComboMedia(Media * cm){
    media->add(cm);
}
Media *ComboMediaBuilder::getMedia() {
    return media;
}
