#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <vector>
#include "Shapes.h"

class ComboMedia;
class ShapeMedia;

class MediaVisitor {
public :
    virtual void visitShapeMedia(ShapeMedia *shapeMedia);
    virtual void visitComboMedia(ComboMedia *comboMedia);
    virtual void finishVisit();
};

class Media {
public :
    virtual double area() const = 0 ;
    virtual double perimeter() const = 0 ;
    virtual void accept(MediaVisitor * mediaVisitor) = 0;
    virtual void add(Media * m) {
        throw std::string("Illegal: add on media");
    }
};

class MediaBuilder{
public:
    virtual void buildComboMedia() = 0;
    virtual void buildShapeMedia(Shape * s) = 0;
    virtual Media *getMedia()= 0;
};
#endif // MEDIA_H
