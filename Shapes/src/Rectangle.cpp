#include "Rectangle.h"

Rectangle::Rectangle(double ulcx, double ulcy, double length, double width):
    x(ulcx),y(ulcy),l(length),w(width){}

double Rectangle::area() const {
    return l*w;
}
double Rectangle::perimeter() const {
    return (l+w)*2;
} //new
std::string Rectangle::description() const {
    std::stringstream ss;
    ss << "r(" << x << " " << y << " " << l << " " << w << ") ";
    return ss.str();
}
