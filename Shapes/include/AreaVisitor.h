#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

class AreaVisitor : public MediaVisitor{

public:
    AreaVisitor();
    void visitComboMedia(ComboMedia *comboMedia);
    void visitShapeMedia(ShapeMedia *shapeMedia);
    void finishVisit(){};
    double getTotalArea () const;

private:
    double totalArea;
};

#endif // AREAVISITOR_H
