#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shapes.h"

class Triangle : public Shape{ //new
public:
    Triangle(double pointAX,double pointAY,double pointBX,double pointBY,double pointCX,double pointCY);
    double area() const ;
    double perimeter() const;
    bool isTriangle() const;
private:
    double ax,ay,bx,by,cx,cy;
    double lineAB,lineBC,lineCA;
};
#endif // TRIANGLE_H
