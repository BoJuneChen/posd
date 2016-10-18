#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <vector>

class ComboMedia;
class ShapeMedia;
class MediaVisitor {
public :
    virtual void visitShapeMedia(ShapeMedia *shapeMedia);
    virtual void visitComboMedia(ComboMedia *comboMedia);
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
#endif // MEDIA_H