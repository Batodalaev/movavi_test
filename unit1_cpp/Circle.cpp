#ifndef CIRCLE_CPP
#define CIRCLE_CPP
#pragma once
#include "Circle.hh"
#define _USE_MATH_DEFINES //for M_PI
#include <cmath> 
namespace unit1{
    double Circle::Area(){
        return radius * radius * GetPi();
    }
    double Circle::GetPi(){
        return 3.14159265358979323846;
        //return M_PI;
    }
    double Circle::GetRadius(){
        return radius;
    }
    void Circle::SetRadius(double radius) throw(std::invalid_argument){
        if(radius < 0)
            throw std::invalid_argument("radius must be nonnegative value");
        this->radius = radius;
    }
    Circle::Circle(double radius) throw(std::invalid_argument){
        if(radius < 0)
            throw std::invalid_argument("radius must be nonnegative value");
        this->radius = radius;
    }
    Circle::~Circle(){
        radius = 0;
    }

    Circle::Circle(){
        radius = 0;
    }
}
#endif CIRCLE_CPP