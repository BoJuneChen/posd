#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <vector>
#include "Shapes.h"

class ComboMedia;
class ShapeMedia;
class TextMedia;

class MediaVisitor {
public :
    virtual void visitShapeMedia(ShapeMedia *shapeMedia);
    virtual void visitComboMedia(ComboMedia *comboMedia);
    virtual void visitTextMedia(TextMedia *textMedia);
    virtual void finishVisit();
};

class Media {
public :
    virtual double area() const=0;
    virtual double perimeter() const=0;
    virtual void accept(MediaVisitor * mediaVisitor)=0;
    virtual void add(Media * m) {
        throw std::string("Illegal: add on media");
    }
    virtual string getType() const ;
    virtual void removeMedia(Media * m){
        throw std::string("Illegal: remove on media");
    }
    virtual string description();
    virtual void setName(string inputName);
    virtual string getName();
    virtual int getSize();
protected:
    //std::string name;
};

class MediaBuilder{
public:
    virtual void buildComboMedia() = 0;
    virtual void buildShapeMedia(Shape * s) = 0;
    virtual Media *getMedia()= 0;
};
#endif // MEDIA_H
