#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <vector>
#include <stdio.h>

const double epsilon = 0.000001;
// added this line
TEST (first, RectangleArea) {
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(8,rect.area(),epsilon);
}
TEST (first, CircleArea){
    Circle circ(0,0,10);
    DOUBLES_EQUAL(314,circ.area(),epsilon);
}
TEST (first, TriangleArea){ //new
    Triangle tri(0,0,3,0,3,4); //use 3:4:5 triangle for simple test,because no point number
    DOUBLES_EQUAL(6,tri.area(),epsilon);
}
TEST (sencond, RectanglePerimeter) { //new
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(12,rect.perimeter(),epsilon);
}
TEST (sencond, CirclePerimeter) { //new
    Circle circ(0,0,10);
    DOUBLES_EQUAL(62.8,circ.perimeter(),epsilon);
}
TEST (sencond, TrianglePerimeter){ //new
    Triangle tri(0,0,3,0,3,4); //use 3:4:5 triangle for simple test,because no point number
    DOUBLES_EQUAL(12,tri.perimeter(),epsilon);
}
TEST (sencond, IsTriangle){
    Triangle tri(3,0,0,0,3,4);
    CHECK_EQUAL(true,tri.isTriangle());
}
TEST (sencond, IsNotTriangle){
    Triangle tri(0,0,0,0,1,1);
    CHECK_EQUAL(false,tri.isTriangle());
}
TEST (third, sumOfArea) {
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    DOUBLES_EQUAL(322,sumOfArea(shapes),epsilon);
}
TEST (third, sumOfPerimeter){ //new
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    Triangle tri(0,0,3,0,3,4);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    DOUBLES_EQUAL(86.8,sumOfPerimeter(shapes),epsilon);
}
TEST (fourth, maxArea){
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    Triangle tri(0,0,3,0,3,4);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    CHECK(&circ==maxArea(shapes));
}

TEST (fourth, sortByDecreasingPerimeter){
    Rectangle rect(0,0,4,3); //14
    Circle circ(0,0,10); //62.8
    Triangle tri(0,0,3,0,3,4); //12

    Rectangle rect1(0,0,1,1); //4
    Rectangle rect2(0,0,3,2); //10
    Rectangle rect3(0,0,11,3); //28

    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);

    shapes.push_back(&rect1);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);

    shapes = sortByDecreasingPerimeter(shapes);
    /*
    DOUBLES_EQUAL(tri.perimeter(),shapes[0]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect.perimeter(),shapes[1]->perimeter(),epsilon);
    DOUBLES_EQUAL(circ.perimeter(),shapes[2]->perimeter(),epsilon);
    */
    DOUBLES_EQUAL(rect1.perimeter(),shapes[0]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect2.perimeter(),shapes[1]->perimeter(),epsilon);
    DOUBLES_EQUAL(tri.perimeter(),shapes[2]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect.perimeter(),shapes[3]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect3.perimeter(),shapes[4]->perimeter(),epsilon);
    DOUBLES_EQUAL(circ.perimeter(),shapes[5]->perimeter(),epsilon);

}
#endif // UTSHAPES_H_INCLUDED
