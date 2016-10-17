#ifndef SHAPEMEDIA_H
#define SHAPEMEDIA_H
#include "Media.h"
#include "Shapes.h"

class ShapeMedia : public Media {

private:
    Shape* shape ;

public :
    ShapeMedia( Shape* s );
    virtual void accept(Visitor * dv) {
        dv->visitShapeMedia(this);
    }
    double area() const;
    double perimeter() const;
    Shape * getShape() const;
};
#endif // SHAPEMEDIA_H
