#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ComboShape.h"
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

const double epsilon = 0.000001;
// added this line
TEST (first, TestRectangleArea) {
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(8,rect.area(),epsilon);
}
TEST (first, TestCircleArea){
    Circle circ(0,0,10);
    DOUBLES_EQUAL(314,circ.area(),epsilon);
}
TEST (first, TestTriangleArea){
    Triangle tri(0,0,3,0,3,4); //use 3:4:5 triangle for simple test,because no point number
    DOUBLES_EQUAL(6,tri.area(),epsilon);
}
TEST (sencond, TestRectanglePerimeter) {
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(12,rect.perimeter(),epsilon);
}
TEST (sencond, TestCirclePerimeter) {
    Circle circ(0,0,10);
    DOUBLES_EQUAL(62.8,circ.perimeter(),epsilon);
}
TEST (sencond, TestTrianglePerimeter){
    Triangle tri(0,0,3,0,3,4); //use 3:4:5 triangle for simple test,because no point number
    DOUBLES_EQUAL(12,tri.perimeter(),epsilon);
}
TEST (sencond, TestIsTriangle){
    Triangle tri(3,0,0,0,3,4);
    CHECK_EQUAL(true,tri.isTriangle());
}
TEST (sencond, TestIsNotTriangle){
    Triangle tri(0,0,0,0,1,1);
    CHECK_EQUAL(false,tri.isTriangle());
}
TEST (sencond, TestIsNotTriangle_2){
    Triangle tri(0,0,1,1,3,3);
    CHECK_EQUAL(false,tri.isTriangle());
}
TEST (third, TestsumOfArea) {
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    DOUBLES_EQUAL(322,sumOfArea(shapes),epsilon);
}
TEST (third, TestsumOfPerimeter){
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    Triangle tri(0,0,3,0,3,4);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    DOUBLES_EQUAL(86.8,sumOfPerimeter(shapes),epsilon);
}
TEST (fourth, TestMaxArea){
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    Triangle tri(0,0,3,0,3,4);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    CHECK(&circ==maxArea(shapes));
}
TEST (fourth, TestSortByDecreasingPerimeter){
    Rectangle rect(0,0,4,3); //14 #3
    Circle circ(0,0,10); //62.8 #5
    Triangle tri(0,0,3,0,3,4); //12 #2
    Rectangle rect1(0,0,1,1); //4 #0
    Rectangle rect2(0,0,3,2); //10 #1
    Rectangle rect3(0,0,11,3); //28 #4

    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    shapes.push_back(&rect1);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);

    shapes = sortByDecreasingPerimeter(shapes);
    DOUBLES_EQUAL(rect1.perimeter(),shapes[0]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect2.perimeter(),shapes[1]->perimeter(),epsilon);
    DOUBLES_EQUAL(tri.perimeter(),shapes[2]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect.perimeter(),shapes[3]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect3.perimeter(),shapes[4]->perimeter(),epsilon);
    DOUBLES_EQUAL(circ.perimeter(),shapes[5]->perimeter(),epsilon);
}
TEST (fifth, TestRectangleName) {
    Rectangle rect(0,0,4,2);
    rect.setName("rect");
    CHECK(rect.getName()=="rect");
}
TEST (fifth, TestCircleName){
    Circle circ(0,0,10);
    circ.setName("circ");
    CHECK(circ.getName()=="circ");
}
TEST (fifth, TestTriangleName){
    Triangle tri(0,0,3,0,3,4); //use 3:4:5 triangle for simple test,because no point number
    tri.setName("tri");
    CHECK(tri.getName()=="tri");
}
TEST (sixth, TestComboShapeAdd){
    Rectangle rect(0,0,4,2); //area = 8
    Circle circ(0,0,10); //area = 314
    Triangle tri(0,0,3,0,3,4); //area = 6
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    //create a ComboShape with type: vector<Shape>*
    ComboShape combo(shapes); //now sumArea = 328
    DOUBLES_EQUAL(328,combo.area(),epsilon);
    Rectangle rect1(0,0,1,2); //area = 2
    //#1 addShape with type: Shape*
    combo.addShape(&rect1); //now sumArea = 330
    DOUBLES_EQUAL(330,combo.area(),epsilon);
    Circle circ1(0,0,1); //area = 3.14
    Triangle tri1(0,0,6,0,6,8); //area = 24
    std::vector<Shape *> shapes2;
    shapes2.push_back(&circ1);
    shapes2.push_back(&tri1);
    ComboShape combo2(shapes2);
    //#2 addShape with type: ComboShape*
    combo.addShape(&combo2); //now sumArea = 357.14
    DOUBLES_EQUAL(357.14,combo.area(),epsilon);
    //#3 addShape with type: vector<Shape>*
    combo.addShape(&shapes2); //now add 27.14 in sumArea, so sumArea should be 384.28
    DOUBLES_EQUAL(384.28,combo.area(),epsilon);
}
TEST (sixth,TestComboShapeArea){
    Rectangle rect(0,0,4,2); //area = 8
    Circle circ(0,0,10); //area = 314
    Triangle tri(0,0,3,0,3,4); //area = 6
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    ComboShape combo(shapes); //now sumArea = 328
    DOUBLES_EQUAL(328,combo.area(),epsilon);
    Rectangle rect1(0,0,1,2); //area = 2
    combo.addShape(&rect1); //now sumArea = 330
    DOUBLES_EQUAL(330,combo.area(),epsilon);
}
TEST (sixth,TestComboShapePerimeter){
    Rectangle rect(0,0,4,2); //perimeter = 12
    Circle circ(0,0,10); //perimeter = 62.8
    Triangle tri(0,0,3,0,3,4); //perimeter = 12
     std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    ComboShape combo(shapes);
    DOUBLES_EQUAL(86.8,combo.perimeter(),epsilon);
}
TEST (sixth,AreaWithCSmallAndRTall){
    Circle cSmall(2,1,1); //area = 3.14
    Rectangle rTall(1,10,2,8); //area = 16
    std::vector<Shape *> shapes;
    shapes.push_back(&cSmall);
    shapes.push_back(&rTall);
    ComboShape combo(shapes); //now sumArea = 19.14
    DOUBLES_EQUAL(19.14,combo.area(),epsilon);
}
TEST (sixth,PerimeterWithCSmallAndRTall){
    Circle cSmall(2,1,1); //perimeter 6.28
    Rectangle rTall(1,10,2,8); //perimeter 20
    std::vector<Shape *> shapes;
    shapes.push_back(&cSmall);
    shapes.push_back(&rTall);
    ComboShape combo(shapes); //now sumpPerimeter = 26.28
    DOUBLES_EQUAL(26.28,combo.perimeter(),epsilon);
}

#endif // UTSHAPES_H_INCLUDED
