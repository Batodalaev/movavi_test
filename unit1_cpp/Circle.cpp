#ifndef CIRCLE_CPP
#define CIRCLE_CPP
#pragma once
#include "Circle.hh"
#define _USE_MATH_DEFINES //for M_PI
#include <cmath> 

    double Circle::Area(){
        return radius * radius * GetPi();
    }
    double Circle::GetPi(){
        return M_PI;
        //return 3.14159265358979323846;
    }
    double Circle::GetRadius(){
        return radius;
    }
    void Circle::SetRadius(double radius){
        this->radius = radius;
    }
    Circle::Circle(double radius){
        this->radius = radius;
    }
    Circle::~Circle(){
        radius = 0;
    }

    Circle::Circle(){
        radius = 0;
    }

#endif CIRCLE_CPP