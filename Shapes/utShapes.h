#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include <vector>

const double epsilon = 0.000001;
// added this line
TEST (first, Rectangle) {
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(8,rect.area(),epsilon);
}

TEST (first, RectanglePerimeter) { //new
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(12,rect.perimeter(),epsilon);
}

TEST (sencond, Circle){
    Circle circ(0,0,10);
    DOUBLES_EQUAL(314,circ.area(),epsilon);
}

TEST (sencond, CirclePerimeter) { //new
    Circle circ(0,0,10);
    DOUBLES_EQUAL(62.8,circ.perimeter(),epsilon);
}

TEST (third, sumOfArea) {
    Rectangle r1(0,0,4,2);
    Rectangle r2(0,0,3,3);
    std::vector<Rectangle> rects;
    rects.push_back(r1);
    rects.push_back(r2);
    DOUBLES_EQUAL(17, sumOfArea(rects),epsilon);
}
TEST (fourth, sumOfArea) {
    std::vector<Rectangle> rects;
    DOUBLES_EQUAL(0, sumOfArea(rects),epsilon);
}
TEST (fifth, sumOfArea) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    std::vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    DOUBLES_EQUAL(322,sumOfArea(ss),epsilon);
}

TEST (sixth, TriangleArea){ //new
    Triangle tri(0,0,3,0,3,4); //use 3:4:5 triangle for simple test,because no point number
    DOUBLES_EQUAL(6,tri.area(),epsilon);
}
TEST (sixth, TrianglePerimeter){ //new
    Triangle tri(0,0,3,0,3,4); //use 3:4:5 triangle for simple test,because no point number
    DOUBLES_EQUAL(12,tri.perimeter(),epsilon);
}
TEST (seventh, sumOfPerimeter){ //new
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    Triangle tri(0,0,3,0,3,4);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    DOUBLES_EQUAL(86.8,sumOfPerimeter(shapes),epsilon);
}


#endif // UTSHAPES_H_INCLUDED
