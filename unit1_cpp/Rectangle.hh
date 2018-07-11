#ifndef RECTANGLE_HH
#define RECTANGLE_HH
#pragma once
#include "IShape.hh"
namespace unit1{
    //Класс, наследник IShape, геометрическая фигура - прямоугольник. Хранит 2 поля - ширина и длина прямоугольника.
    class Rectangle : public IShape
    {
    public:
        double Area(); // return = width * height
        double GetWidth();
        double GetHeight();
        void SetWidth(double width);
        void SetHeight(double height);
        Rectangle(double width, double height);
        ~Rectangle();
    private:
        double width;
        double height;
        Rectangle();
    };
}
#endif RECTANGLE_HH