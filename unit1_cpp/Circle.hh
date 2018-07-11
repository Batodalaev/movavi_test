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
        double Area();// return radius * radius * GetPi()
        double GetPi(); // return 3.141592653589793
        double GetRadius();
        void SetRadius(double radius) throw(std::invalid_argument);
        Circle(double radius) throw(std::invalid_argument);
        ~Circle();
    private:
        double radius;
        Circle();
    };
}
#endif CIRCLE_HH