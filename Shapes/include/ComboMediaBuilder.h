#ifndef COMBOMEDIABUILDER_H
#define COMBOMEDIABUILDER_H
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

class ComboMediaBuilder: public MediaBuilder {
public:
    void buildComboMedia();
    void buildShapeMedia(Shape * s);
    void addComboMedia(Media * cm);
    Media *getMedia();
private:
    Media *media;
};
#endif // COMBOMEDIABUILDER_H
