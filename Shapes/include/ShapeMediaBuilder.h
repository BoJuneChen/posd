#ifndef SHAPEMEDIABUILDER_H
#define SHAPEMEDIABUILDER_H
#include "Media.h"
#include "ShapeMedia.h"

class ShapeMediaBuilder : public MediaBuilder {
public:
    void buildComboMedia();
    void buildShapeMedia(Shape * s);
    Media *getMedia();
private:
    Media *media;
};

#endif // SHAPEMEDIABUILDER_H
