#include "ComboMedia.h"

ComboMedia::ComboMedia(){}
ComboMedia::ComboMedia( std::vector<Media*> m ) : media(m) {}

double ComboMedia::area( ) const{
    double total =0;
    for (Media *m: media)
        total += m->area();
    return total;
}

void ComboMedia::accept(MediaVisitor *mediaVisitor) {
    for (Media *m: media)
        m->accept(mediaVisitor);
    mediaVisitor->visitComboMedia(this);
}

double ComboMedia::perimeter() const{
    double total =0;
    for (Media *m: media)
        total += m->perimeter();
    return total;
}

void ComboMedia::add (Media *m){
    media.push_back(m);
}
