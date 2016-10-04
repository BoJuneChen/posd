#include "Shapes.h"

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
