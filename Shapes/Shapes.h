#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <vector>
#include <cmath>
double const PI = 3.14; //new

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter () const = 0; //new
};
class Rectangle : public Shape {
public:
    Rectangle(double ulcx, double ulcy, double length, double width):
        x(ulcx),y(ulcy),l(length),w(width){}
    double area() const {return l*w;}
    double perimeter() const {return (l+w)*2;} //new
private:
    double x,y,l,w;
};

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius){}
    double area()const {return PI*r*r;} //modify
    double perimeter() const {return 2*PI*r;} //new
private:
    double cx,cy,r;
};

class Triangle : public Shape{ //new
public:
    Triangle(double pointAX,double pointAY,double pointBX,double pointBY,double pointCX,double pointCY):
        ax(pointAX),ay(pointAY),bx(pointBX),by(pointBY),cx(pointCX),cy(pointCY){
        lineAB = sqrt(pow(ax-bx,2.0) + pow(ay-by,2.0));
        lineBC = sqrt(pow(bx-cx,2.0) + pow(by-cy,2.0));
        lineCA = sqrt(pow(cx-ax,2.0) + pow(cy-ay,2.0));
        }
    double area() const {
        double s = (lineAB+lineBC+lineCA)/2;
        return sqrt(s*(s-lineAB)*(s-lineBC)*(s-lineCA));
    }
    double perimeter() const {
        return lineAB+lineBC+lineCA;
    }
private:
    double ax,ay,bx,by,cx,cy;
    double lineAB,lineBC,lineCA;
};

double sumOfArea(std::vector<Rectangle> rects) {
    double total =0;
    for (Rectangle r: rects)
        total += r.area();
    return total;
}

double sumOfArea(std::vector<Shape *> shapes) { //modify
    double total =0;
    for (Shape *s: shapes)
        total += s->area();
    return total;
}

double sumOfPerimeter (std::vector<Shape *> shapes){
    double total =0;
    for (Shape *s: shapes)
        total += s->perimeter();
    return total;
}
#endif // SHAPES_H_INCLUDED
