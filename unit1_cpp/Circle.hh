#ifndef CIRCLE_HH
#define CIRCLE_HH
#pragma once
#include "IShape.hh"
#include <stdexcept>
namespace unit1{
//Класс, наследник IShape, геометрическая фигура - круг. Хранит 1 поле - радиус.
class Circle : public IShape
{
    public:
        double Area();// return radius * radius * Pi
        double GetRadius();
        void SetRadius(double radius) throw(std::invalid_argument);
        Circle(double radius) throw(std::invalid_argument);
        ~Circle();
        const double Pi = 3.14159265358979323846;
    private:
        double radius;
        Circle();
    };
}
#endif CIRCLE_HH