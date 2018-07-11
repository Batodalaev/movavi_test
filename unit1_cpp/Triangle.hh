#ifndef TRIANGLE_HH
#define TRIANGLE_HH
#pragma once
#include "IShape.hh"
//Класс, наследник IShape, геометрическая фигура - треугольник. Хранит 3 поля - стороны A,B и C.
class Triangle : public IShape
{
 public:
    double Area(); //double p = Perimeter()/2.0  //return sqrt(p*(p-a)*(p-b)*(p-c)) //формула Герона
    double Perimeter(); // return sideA+sideB+sideC
    double GetSideA();
    void SetSideA(double sideA);
    double GetSideB();
    void SetSideB(double sideB);
    double GetSideC();
    void SetSideC(double sideC);
    Triangle(double sideA, double sideB, double sideC);
    ~Triangle();
 private:
    double sideA;
    double sideB;
    double sideC;
    Triangle();
};
#endif TRIANGLE_HH