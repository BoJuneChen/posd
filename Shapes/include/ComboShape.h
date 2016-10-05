#ifndef COMBOSHAPE_H
#define COMBOSHAPE_H

#include "Shapes.h"
#include <vector>

class ComboShape : public Shape
{
    public:
        ComboShape(std::vector<Shape*>& inputShapes);
        ~ComboShape();
        double area() const;
        double perimeter() const;
        void addShape(Shape* inputShape);
        void addShape(std::vector<Shape*>* inputShapes);
        void addShape(ComboShape* inputShapes);
        vector<Shape*> getShapes();
    private:
        vector<Shape*> shapes;
};

#endif // COMBOSHAPE_H
