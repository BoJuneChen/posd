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
#include <iostream>
#include "ComboMedia.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "ShapeMediaBuilder.h"
#include "ComboMediaBuilder.h"
#include <stack>
#include "Text.h"
#include "TextMedia.h"
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
TEST (sencond, TestRectanglePerimeter){
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(12,rect.perimeter(),epsilon);
}
TEST (sencond, TestCirclePerimeter){
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
TEST (third, TestSumOfArea){
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    DOUBLES_EQUAL(322,sumOfArea(shapes),epsilon);
}
TEST (third, TestSumOfPerimeter){
    Rectangle rect(0,0,4,2);    //perimeter = 12
    Circle circ(0,0,10);        //perimeter = 62.8
    Triangle tri(0,0,3,0,3,4);  //perimeter = 12
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);     //sumPerimeter = 86.8
    DOUBLES_EQUAL(86.8,sumOfPerimeter(shapes),epsilon);
}
TEST (fourth, TestMaxArea){
    Rectangle rect(0,0,4,2);    //area = 8
    Circle circ(0,0,10);        //area = 314 (max)
    Triangle tri(0,0,3,0,3,4);  //area = 6
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    CHECK(&circ == maxArea(shapes));
}
TEST (fourth, TestSortByDecreasingPerimeter){
    Rectangle rect(0,0,4,3);    //perimeter = 14    #3
    Circle circ(0,0,10);        //perimeter = 62.8  #5
    Triangle tri(0,0,3,0,3,4);  //perimeter = 12    #2
    Rectangle rect1(0,0,1,1);   //perimeter = 4     #0
    Rectangle rect2(0,0,3,2);   //perimeter = 10    #1
    Rectangle rect3(0,0,11,3);  //perimeter = 28    #4

    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    shapes.push_back(&rect1);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);

    sortByDecreasingPerimeter(shapes);
    DOUBLES_EQUAL(rect1.perimeter() ,shapes[0]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect2.perimeter() ,shapes[1]->perimeter(),epsilon);
    DOUBLES_EQUAL(tri.perimeter()   ,shapes[2]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect.perimeter()  ,shapes[3]->perimeter(),epsilon);
    DOUBLES_EQUAL(rect3.perimeter() ,shapes[4]->perimeter(),epsilon);
    DOUBLES_EQUAL(circ.perimeter()  ,shapes[5]->perimeter(),epsilon);
}
TEST (fifth, TestRectangleName){
    Rectangle rect(0,0,4,2);
    rect.setName("rect");
    CHECK(rect.getName() == "rect");
}
TEST (fifth, TestCircleName){
    Circle circ(0,0,10);
    circ.setName("circ");
    CHECK(circ.getName() == "circ");
}
TEST (fifth, TestTriangleName){
    Triangle tri(0,0,3,0,3,4);
    tri.setName("tri");
    CHECK(tri.getName() == "tri");
}
TEST (sixth, TestComboShapeConsturctor){
    Rectangle rect(0,0,4,2);    //area = 8
    Circle circ(0,0,10);        //area = 314
    //create a ComboShape with type: (Shape*, Shape*)
    ComboShape combo(&rect,&circ); //now sumArea = 328
    DOUBLES_EQUAL(322,combo.area(),epsilon);
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    //create a ComboShape with type: (vector<Shape*>)
    ComboShape combo2(shapes);  //now sumArea = 328
    DOUBLES_EQUAL(322,combo2.area(),epsilon);
}
TEST (sixth, TestComboShapeAdd){
    Rectangle rect(0,0,4,2);    //area = 8
    Circle circ(0,0,10);        //area = 314
    Triangle tri(0,0,3,0,3,4);  //area = 6
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    //create a ComboShape with type: (vector<Shape>*)
    ComboShape combo(shapes);   //now sumArea = 328
    DOUBLES_EQUAL(328,combo.area(),epsilon);
    Rectangle rect1(0,0,1,2);   //area = 2
    //#1 addShape with type: (Shape*)
    combo.addShape(&rect1);     //now sumArea = 330
    DOUBLES_EQUAL(330,combo.area(),epsilon);
    Circle circ1(0,0,1);        //area = 3.14
    Triangle tri1(0,0,6,0,6,8); //area = 24
    std::vector<Shape *> shapes2;
    shapes2.push_back(&circ1);
    shapes2.push_back(&tri1);
    ComboShape combo2(shapes2);
    //#2 addShape with type: (ComboShape*)
    combo.addShape(&combo2);    //now sumArea = 357.14
    DOUBLES_EQUAL(357.14,combo.area(),epsilon);
    //#3 addShape with type: (vector<Shape>*)
    combo.addShape(&shapes2);   //now add 27.14 in sumArea, so sumArea should be 384.28
    DOUBLES_EQUAL(384.28,combo.area(),epsilon);
}
TEST (sixth, TestComboShapeArea){
    Rectangle rect(0,0,4,2);    //area = 8
    Circle circ(0,0,10);        //area = 314
    Triangle tri(0,0,3,0,3,4);  //area = 6
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    ComboShape combo(shapes);   //now sumArea = 328
    DOUBLES_EQUAL(328,combo.area(),epsilon);
    Rectangle rect1(0,0,1,2);   //area = 2
    combo.addShape(&rect1);     //now sumArea = 330
    DOUBLES_EQUAL(330,combo.area(),epsilon);
}
TEST (sixth, TestComboShapePerimeter){
    Rectangle rect(0,0,4,2);    //perimeter = 12
    Circle circ(0,0,10);        //perimeter = 62.8
    Triangle tri(0,0,3,0,3,4);  //perimeter = 12
    std::vector<Shape *> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circ);
    shapes.push_back(&tri);
    ComboShape combo(shapes);   //now sumPerimeter = 86.8
    DOUBLES_EQUAL(86.8,combo.perimeter(),epsilon);
}
TEST (sixth, TestAreaWithCSmallAndRTall){
    Circle cSmall(2,1,1);       //area = 3.14
    Rectangle rTall(1,10,2,8);  //area = 16
    ComboShape comboExclamation(&cSmall,&rTall);    //now sumArea = 19.14
    DOUBLES_EQUAL(19.14,comboExclamation.area(),epsilon);
}
TEST (sixth, TestPerimeterWithCSmallAndRTall){
    Circle cSmall(2,1,1);       //perimeter = 6.28
    Rectangle rTall(1,10,2,8);  //perimeter = 20
    ComboShape comboExclamation(&cSmall,&rTall);    //now sumPerimeter = 26.28
    DOUBLES_EQUAL(26.28,comboExclamation.perimeter(),epsilon);
}
TEST (seventh, TestRegularHexagon){ //HW3 problem 1
    Triangle leftTriangle   (0, 0, -1, 1.732, 0, 3.464); //(pointAX,pointAY,pointBX,pointBY,pointCX,pointCY)
    Rectangle middleRectangle(0, 3.464, 2, 3.464) ; //(lfX,lfY,L,W)
    Triangle rightTriangle  (2, 0,  3, 1.732, 2, 3.464);
    ShapeMedia leftTriangleMedia(&leftTriangle);
    ShapeMedia middleRectangleMedia(&middleRectangle);
    ShapeMedia rightTriangleMedia(&rightTriangle);
    DOUBLES_EQUAL(1.732,leftTriangleMedia.area(),epsilon);
    DOUBLES_EQUAL(1.732,rightTriangleMedia.area(),epsilon);
    DOUBLES_EQUAL(6.928,middleRectangleMedia.area(),epsilon);

    DOUBLES_EQUAL(7.463912,leftTriangleMedia.perimeter(),epsilon);
    DOUBLES_EQUAL(7.463912,rightTriangleMedia.perimeter(),epsilon);
    DOUBLES_EQUAL(10.928,middleRectangleMedia.perimeter(),epsilon);

    std::vector<Media *> mediaVector;
    mediaVector.push_back(&middleRectangleMedia);
    ComboMedia combo(mediaVector);
    combo.add(&leftTriangleMedia);
    combo.add(&rightTriangleMedia);

    DOUBLES_EQUAL(10.392,combo.area(),epsilon);
    DOUBLES_EQUAL(25.855824,combo.perimeter(),epsilon);
}
TEST (senenth, TestAreaVisitor){ //HW3 problem 2
    AreaVisitor areaVisitor;
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    Triangle tri(0,0,3,0,3,4);  //area = 6
    ShapeMedia rectMedia(&rect);
    ShapeMedia circMedia(&circ);
    ShapeMedia triMedia(&tri);
    std::vector<Media *> mediaVector;
    mediaVector.push_back(&rectMedia);
    ComboMedia combo(mediaVector);
    combo.add(&circMedia);
    combo.add(&triMedia);
    combo.accept(&areaVisitor);
    DOUBLES_EQUAL(328,areaVisitor.getTotalArea(),epsilon);
}
TEST (senenth, TestPerimeterVisitor){ //HW3 problem 3
    PerimeterVisitor perimeterVisitor;
    Rectangle rect(0,0,4,2);    //perimeter = 12
    Circle circ(0,0,10);        //perimeter = 62.8
    Triangle tri(0,0,3,0,3,4);  //perimeter = 12
    ShapeMedia rectMedia(&rect);
    ShapeMedia circMedia(&circ);
    ShapeMedia triMedia(&tri);
    std::vector<Media *> mediaVector;
    mediaVector.push_back(&rectMedia);
    ComboMedia combo(mediaVector);
    combo.add(&circMedia);
    combo.add(&triMedia);
    combo.accept(&perimeterVisitor);
    DOUBLES_EQUAL(86.8,perimeterVisitor.getTotalPerimeter(),epsilon);
}
TEST (seventh, TestVisitorsWithHexagon){ //HW3 problem 1 2 3
    AreaVisitor areaVisitor;
    PerimeterVisitor perimeterVisitor;
    Triangle leftTriangle   (0, 0, -1, 1.732, 0, 3.464); //use problem 1's hexagon
    Rectangle middleRectangle(0, 3.464, 2, 3.464) ;
    Triangle rightTriangle  (2, 0,  3, 1.732, 2, 3.464);
    ShapeMedia leftTriangleMedia(&leftTriangle);
    ShapeMedia middleRectangleMedia(&middleRectangle);
    ShapeMedia rightTriangleMedia(&rightTriangle);

    std::vector<Media *> mediaVector;
    mediaVector.push_back(&middleRectangleMedia);
    ComboMedia combo(mediaVector);
    combo.add(&leftTriangleMedia); //r+t
    std::vector<Media *> mediaVector2;
    mediaVector2.push_back(&combo);
    ComboMedia combo2(mediaVector2);
    combo2.add(&rightTriangleMedia); //combo+t
    combo2.accept(&areaVisitor);
    combo2.accept(&perimeterVisitor);
    DOUBLES_EQUAL(10.392,areaVisitor.getTotalArea(),epsilon);
    DOUBLES_EQUAL(25.855824,perimeterVisitor.getTotalPerimeter(),epsilon);
}
TEST (eighth, TestBuildCircleShapeMedia){ //HW4 problem 1
    ShapeMediaBuilder smb;
    Circle c(0,0,5);
    smb.buildShapeMedia(&c);
    DOUBLES_EQUAL(78.5,smb.getMedia()->area(),epsilon);
}
TEST (eighth, TestShapeMediaDescriptionVisitor){
    Rectangle r1(0,0,4,2);
    ShapeMedia sR1(&r1) ;
    DescriptionVisitor dv;
    sR1.accept(&dv);
    CHECK(std::string("r(0 0 4 2) ") == dv.getDescription());
}
TEST (eighth, TestComboMediaDescriptionVisitor){
    Rectangle r1(0,0,4,2);
    Circle r2(0,0,10);
    ShapeMedia sR1( &r1 ) ;
    ShapeMedia sR2( &r2 ) ;
    std::vector<Media *> ss{&sR1,&sR2};
    ComboMedia cm(ss);
    DescriptionVisitor dv;
    cm.accept(&dv);
    //std::cout<<  dv.getDescription() << std::endl;
    CHECK(std::string("combo(r(0 0 4 2) c(0 0 10) )") == dv.getDescription());
}
TEST (eighth, TestBuildTheHouse){ //HW4 problem 2
    stack<ComboMediaBuilder*> mbs;
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    Rectangle r1(10,0,15,5);
    mbs.top()->buildShapeMedia(&r1);
    Circle c(12,5,2);
    mbs.top()->buildShapeMedia(&c);

    Media *combo1 = mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->addComboMedia(combo1);
    Rectangle r2(0,0,25,20);
    mbs.top()->buildShapeMedia(&r2);

    Media *combo2 = mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->addComboMedia(combo2);
    Triangle t(0,20,16,32,25,20);
    mbs.top()->buildShapeMedia(&t);

    DescriptionVisitor dv;
    mbs.top()->getMedia()->accept(&dv);
    //std::cout << dv.getDescription() << std::endl;

    string desc("combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )");
    CHECK(desc == dv.getDescription());
    //FAIL("0");
}
TEST (eighth, TestTextMedia){ //HW4 problem 3
    Rectangle boundingBox(0,0,4,2);
    string messageText = "bounding Box";
    Text text(boundingBox,messageText);
    CHECK(messageText == text.getText());
    DOUBLES_EQUAL(8,text.getRectangleArea(),epsilon);
    TextMedia tm(&text);
    AreaVisitor av;
    tm.accept(&av);
    DOUBLES_EQUAL(8,av.getTotalArea(),epsilon);
}
TEST (eighth, TestRemoveMedia1){
    Rectangle rect(0,0,4,2);
    Circle circ(0,0,10);
    Triangle tri(0,0,3,0,3,4);
    ShapeMedia rectMedia(&rect);
    ShapeMedia circMedia(&circ);
    ShapeMedia triMedia(&tri);
    std::vector<Media *> mediaVector;
    mediaVector.push_back(&rectMedia);
    ComboMedia combo(mediaVector);
    combo.add(&circMedia);
    combo.add(&triMedia);
    DescriptionVisitor dv;
    combo.accept(&dv);
    //std::cout << dv.getDescription() << std::endl;
    string desc = "combo(r(0 0 4 2) c(0 0 10) t(0 0 3 0 3 4) )";
    CHECK( desc == dv.getDescription());
    combo.removeMedia(&triMedia);
    DescriptionVisitor dv2;
    combo.accept(&dv2);
    //std::cout << dv2.getDescription() << std::endl;
    string desc2 = "combo(r(0 0 4 2) c(0 0 10) )";
    CHECK( desc2 == dv2.getDescription());
}
TEST (eighth, TestRemoveMedia2){
     stack<ComboMediaBuilder*> mbs;
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    Rectangle r1(10,0,15,5);
    mbs.top()->buildShapeMedia(&r1);
    Circle c(12,5,2);
    mbs.top()->buildShapeMedia(&c);

    Media *combo1 = mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->addComboMedia(combo1);
    Rectangle r2(0,0,25,20);
    mbs.top()->buildShapeMedia(&r2);

    Media *combo2 = mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->addComboMedia(combo2);
    Triangle t(0,20,16,32,25,20);
    mbs.top()->buildShapeMedia(&t);

    DescriptionVisitor dv;
    mbs.top()->getMedia()->accept(&dv);
    //std::cout << dv.getDescription() << std::endl;

    string desc("combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )");
    CHECK(desc == dv.getDescription());
    ShapeMedia sMR2(&r2);
    mbs.top()->getMedia()->removeMedia(&sMR2);
    DescriptionVisitor dv2;
    mbs.top()->getMedia()->accept(&dv2);
    //std::cout << dv2.getDescription() << std::endl;
    string desc2("combo(combo(combo(r(10 0 15 5) c(12 5 2) ))t(0 20 16 32 25 20) )");
    CHECK(desc2 == dv2.getDescription());
}
#endif // UTSHAPES_H_INCLUDED
