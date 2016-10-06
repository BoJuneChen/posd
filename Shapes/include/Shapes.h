#ifndef SHAPES_H
#define SHAPES_H

#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Shape {

public:
    virtual double area() const = 0;
    virtual double perimeter () const = 0; //new
    string getName();
    void setName(string shapeName);
private:
    string name;
};

double sumOfArea(std::vector<Shape *> shapes);
double sumOfPerimeter(std::vector<Shape *> shapes);
Shape* maxArea(std::vector<Shape *> shapes);
std::vector<Shape *> sortByDecreasingPerimeter(std::vector<Shape *> shapes);
#endif // SHAPES_H_INCLUDED
