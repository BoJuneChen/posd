#ifndef DESCRIPTIONVISITOR_H
#define DESCRIPTIONVISITOR_H
#include <string>
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

class DescriptionVisitor : public MediaVisitor {
public:
    DescriptionVisitor ();
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm);
    void finishVisit();
    std::string getDescription() const;
private:
    std::string desc;
};
#endif // DESCRIPTIONVISITOR_H
