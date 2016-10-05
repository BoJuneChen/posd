#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shapes.h"

double const PI = 3.14; //new

class Circle : public Shape {

public:
    Circle(double centerX,double centerY,double radius);
    double area() const ; //modify
    double perimeter() const ; //new

private:

    double cx,cy,r;

};

#endif // CIRCLE_H
