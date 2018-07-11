#ifndef CIRCLE_HH
#define CIRCLE_HH
#pragma once
#include "IShape.hh"
//Класс, наследник IShape, геометрическая фигура - круг. Хранит 1 поле - радиус.
class Circle : public IShape
{
 public:
    double Area();// return radius * radius * GetPi()
    double GetPi(); // return 3.141592653589793
    double GetRadius();
    void SetRadius(double radius);
    Circle(double radius);
    ~Circle();
 private:
    double radius;
    Circle();
};
#endif CIRCLE_HH