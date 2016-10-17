#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <vector>

class ComboMedia;
class ShapeMedia;
class Visitor {
public :
    virtual void visitShapeMedia(ShapeMedia *shapeMedia);
    virtual void visitComboMedia(ComboMedia *comboMedia);
    //virtual void visitMedia(Media *media);
};

//class Visitor

class Media {
public :
    virtual double area() const = 0 ;
    virtual double perimeter() const = 0 ;
    virtual void accept(Visitor * Visitor) = 0;
    virtual void add(Media * m) {
        throw std::string("Illegal: add on media");
    }
};


/*
class AreaVisitor {
public:
    DescriptionVisitor (): desc(std::string("")) {}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm);
    std::string getDescription() const {return desc;}
private:
    std::string desc;
};
class PerimeterVisitor {
public:
    DescriptionVisitor (): desc(std::string("")) {}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm);
    std::string getDescription() const {return desc;}
private:
    std::string desc;
};
*/
#endif // MEDIA_H
