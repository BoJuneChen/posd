#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H
#include "Media.h"

#include "ShapeMedia.h"
#include "ComboMedia.h"


class PerimeterVisitor : public MediaVisitor{

public:
    PerimeterVisitor();
    void visitComboMedia(ComboMedia *comboMedia);
    void visitShapeMedia(ShapeMedia *shapeMedia);
    double getTotalPerimeter () const;

private:
    double totalPerimeter;
};

#endif // PERIMETERVISITOR_H
