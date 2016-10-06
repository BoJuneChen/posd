#include "Shapes.h"
#include <stdio.h>

string Shape::getName(){
    return name;
}

void Shape::setName(string shapeName){
    name = shapeName;
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

Shape* maxArea(std::vector<Shape *> shapes){
    Shape* nowMaxArea = shapes[0];
    for (Shape *s: shapes){
        if(s->area() > nowMaxArea->area()){
            nowMaxArea = s;
        }
    }
    return nowMaxArea;
}

void sortByDecreasingPerimeter(std::vector<Shape *> &shapes){
    int i=0,j=0;
    int length=shapes.size();
    Shape* temp;
    for(i=0;i<length;i++) {
        for(j=i+1;j<length;j++) {
            if (shapes[i]->perimeter() > shapes[j]->perimeter()){
                temp=shapes[i];
                shapes[i]=shapes[j];
                shapes[j]=temp;
            }
        }
    }
}

