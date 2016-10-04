#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shapes.h"

class Rectangle : public Shape {
public:
    Rectangle(double ulcx, double ulcy, double length, double width);
    double area() const;
    double perimeter() const;
private:
    double x,y,l,w;
};
#endif // RECTANGLE_H
