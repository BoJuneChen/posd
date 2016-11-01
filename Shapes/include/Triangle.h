#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shapes.h"
#include <string>
#include <sstream>

class Triangle : public Shape{ //new

public:
    Triangle(double pointAX,double pointAY,double pointBX,double pointBY,double pointCX,double pointCY);
    double area() const ;
    double perimeter() const;
    bool isTriangle() const;
    bool checkEqual(double lineA ,double lineB) const;
    std::string description() const ;
private:
    double ax,ay,bx,by,cx,cy;
    double lineAB,lineBC,lineCA;
    double const EPSILON = 0.00001;
};


#endif // TRIANGLE_H
