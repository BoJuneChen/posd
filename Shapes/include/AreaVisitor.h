#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "TextMedia.h"

class AreaVisitor : public MediaVisitor{

public:
    AreaVisitor();
    void visitComboMedia(ComboMedia *comboMedia);
    void visitShapeMedia(ShapeMedia *shapeMedia);
    void visitTextMedia(TextMedia *textMedia);
    void finishVisit(){};
    double getTotalArea () const;

private:
    double totalArea;
};

#endif // AREAVISITOR_H
