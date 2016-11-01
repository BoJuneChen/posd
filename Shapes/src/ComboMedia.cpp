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
    mediaVisitor->visitComboMedia(this);
    for (Media *m: media)
        m->accept(mediaVisitor);
    mediaVisitor->finishVisit();
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

string ComboMedia::getType()const{
    return std::string("ComboMedia");
}
string ComboMedia::description(){
    return std::string("Combo");
}
void ComboMedia::removeMedia(Media* m){
    int counter = 0;
    for (Media *targetMedia: media){
        if(targetMedia->getType() == std::string("ComboMedia")){
            targetMedia->removeMedia(m);
        }
        else{
            if(targetMedia->description().compare(m->description())==0){
                media.erase(media.begin()+counter);
            }
        }
        counter ++;
    }
}
