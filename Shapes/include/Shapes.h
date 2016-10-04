#ifndef SHAPES_H
#define SHAPES_H

#include <vector>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter () const = 0; //new
};

double sumOfArea(std::vector<Shape *> shapes);
double sumOfPerimeter (std::vector<Shape *> shapes);

#endif // SHAPES_H_INCLUDED
