#ifndef COMBOMEDIA_H
#define COMBOMEDIA_H
#include "Media.h"

class ComboMedia : public Media {

private:
    std::vector<Media*> media;

public:
    ComboMedia() ;
    ComboMedia( std::vector<Media*> m ) ;
    double area() const; //For hw#3 problem 1
    double perimeter() const; //For hw#3 problem 1
    void accept(MediaVisitor *mediaVisitor); //For hw#3 problem 2,3
    void add (Media *m); //For hw#3 problem 2,3
};

#endif // COMBOMEDIA_H
