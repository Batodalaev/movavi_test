#ifndef RECTANGLE_HH
#define RECTANGLE_HH
#pragma once
#include "IShape.hh"
#include <stdexcept>
namespace unit1{
    //Класс, наследник IShape, геометрическая фигура - прямоугольник. Хранит 2 поля - ширина и длина прямоугольника.
    class Rectangle : public IShape
    {
    public:
        double Area(); // return = width * height
        double GetWidth();
        double GetHeight();
        void SetWidth(double width) throw(std::invalid_argument);
        void SetHeight(double height) throw(std::invalid_argument);
        Rectangle(double width, double height) throw(std::invalid_argument);
        ~Rectangle();
    private:
        double width;
        double height;
        Rectangle();
    };
}
#endif RECTANGLE_HH