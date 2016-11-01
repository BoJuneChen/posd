#include "Triangle.h"

Triangle::Triangle(double pointAX,double pointAY,double pointBX,double pointBY,double pointCX,double pointCY):
    ax(pointAX),ay(pointAY),bx(pointBX),by(pointBY),cx(pointCX),cy(pointCY){
    lineAB = sqrt(pow(ax - bx,2.0) + pow(ay - by,2.0));
    lineBC = sqrt(pow(bx - cx,2.0) + pow(by - cy,2.0));
    lineCA = sqrt(pow(cx - ax,2.0) + pow(cy - ay,2.0));
}

double Triangle::area() const {
    double s = (lineAB + lineBC + lineCA)/2;
    return sqrt(s * (s - lineAB) * (s - lineBC) * (s - lineCA));
}

double Triangle::perimeter() const {
    return lineAB + lineBC + lineCA;
}

bool Triangle::isTriangle() const {
    if(lineAB + lineBC < lineCA || checkEqual(lineAB + lineBC , lineCA)){
        return false;
    }
    if(lineBC + lineCA < lineAB || checkEqual(lineBC + lineCA , lineAB)){
        return false;
    }
    if(lineCA + lineAB < lineBC || checkEqual(lineCA + lineAB , lineBC)){
        return false;
    }
    return true;
}

bool Triangle::checkEqual(double lineA ,double lineB) const{
    return fabs(lineA - lineB) < EPSILON;
}

std::string Triangle::description() const {
    std::stringstream ss;
    ss << "t(" << ax << " " << ay << " " << bx << " " << by << " " << cx << " " << cy << ") ";
    return ss.str();
}
