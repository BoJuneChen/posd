#ifndef COMBOMEDIA_H
#define COMBOMEDIA_H
#include "Media.h"

class ComboMedia : public Media {

private:
    std::vector<Media*> media;

public:
    ComboMedia() ;
    ComboMedia( std::vector<Media*> m ) ;
    double area() const;
    double perimeter() const;
    void accept(Visitor *visitor) {
        for (Media *m: media)
            m->accept(visitor);
        visitor->visitComboMedia(this);
    }
    void add (Media *m);

};

#endif // COMBOMEDIA_H
