#include "ShapeMediaBuilder.h"

void ShapeMediaBuilder::buildComboMedia(){
    //do nothing
}
void ShapeMediaBuilder::buildShapeMedia(Shape * s){
    media = new ShapeMedia(s);
}
Media* ShapeMediaBuilder::getMedia(){
    return media;
}
