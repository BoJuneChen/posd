#ifndef SHAPEMEDIA_H
#define SHAPEMEDIA_H
#include "Media.h"
#include "Shapes.h"
#include <string>

class ShapeMedia : public Media {

private:
    Shape* shape ;
    //string name;
public :
    ShapeMedia( Shape* s );
    void accept(MediaVisitor * mediaVisitor); //For hw#3 problem 2,3
    double area() const; //For hw#3 problem 1
    double perimeter() const; //For hw#3 problem 1
    Shape * getShape() const;
    string description();
    string getType()const;
    void setName(string inputName){
        shape->setName(inputName);
    }
    string getName(){
        return shape->getName();
    }
    //void removeMedia(Media * m){};
};
#endif // SHAPEMEDIA_H
