#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shapes.h"
#include <string>
#include <sstream>

double const PI = 3.14; //new

class Circle : public Shape {

public:
    Circle(double centerX,double centerY,double radius);
    double area() const ; //modify
    double perimeter() const ; //new
    std::string description() const;

    double cx,cy,r;

};

#endif // CIRCLE_H
