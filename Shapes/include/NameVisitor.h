#ifndef NAMEVISITOR_H
#define NAMEVISITOR_H

#include <string>
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "TextMedia.h"

class NameVisitor : public MediaVisitor{

public:
    NameVisitor();
    void visitComboMedia(ComboMedia *comboMedia);
    void visitShapeMedia(ShapeMedia *shapeMedia);
    void visitTextMedia(TextMedia *textMedia);
    void finishVisit();
    std::string getNames () const;

private:
     std::string names;
};

#endif // NAMEVISITOR_H
