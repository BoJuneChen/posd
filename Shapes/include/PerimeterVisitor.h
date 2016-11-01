#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H
#include "Media.h"

#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "TextMedia.h"

class PerimeterVisitor : public MediaVisitor{

public:
    PerimeterVisitor();
    void visitComboMedia(ComboMedia *comboMedia);
    void visitShapeMedia(ShapeMedia *shapeMedia);
    void visitTextMedia(TextMedia *textMedia);
    void finishVisit(){};
    double getTotalPerimeter () const;

private:
    double totalPerimeter;
};

#endif // PERIMETERVISITOR_H
