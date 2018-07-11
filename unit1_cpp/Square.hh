#ifndef SQUARE_HH
#define SQUARE_HH
#pragma once
#include "IShape.hh"

namespace unit1{
    //Класс, наследник IShape, геометрическая фигура - квадрат. Хранит только 1 поле - длина стороны квадрата.
    class Square : public IShape
    {
    public:
        double Area(); // return = side * side
        double GetSide();
        void SetSide(double side);
        Square(double side);
        ~Square();
    private:
        double side;
        Square();
    };
}
#endif SQUARE_HH