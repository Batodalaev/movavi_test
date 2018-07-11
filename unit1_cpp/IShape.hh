#ifndef ISHAPE_HH
#define ISHAPE_HH
#pragma once
//Интерфейс, который наследуют все геометрические фигуры в проекте. Имеет метод для получения площади фигуры.

class IShape 
{
 public:
    virtual double Area() = 0; //Расчет площади, каждый наследник реализует его по своему.
};
#endif ISHAPE_HH