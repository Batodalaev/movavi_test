#ifndef TRIANGLE_CPP
#define TRIANGLE_CPP
#pragma once
#include "Triangle.hh"
#include <cmath>
namespace unit1{
    double Triangle::Area(){
        double p = Perimeter()/2.0;//полупериметр.
        return sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));//формула Герона
    }
    double Triangle::Perimeter(){
        return sideA+sideB+sideC;
    }
    double Triangle::GetSideA(){
        return sideA;
    }
    void Triangle::SetSideA(double sideA){
        this->sideA = sideA;
    }
    double Triangle::GetSideB(){
        return sideB;
    }
    void Triangle::SetSideB(double sideB){
        this->sideB = sideB;
    }
    double Triangle::GetSideC(){
        return sideC;
    }
    void Triangle::SetSideC(double sideC){
        this->sideC = sideC;
    }
    Triangle::Triangle(double sideA, double sideB, double sideC){
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
    }
    Triangle::~Triangle(){
        this->sideA = 0;
        this->sideB = 0;
        this->sideC = 0;
    }
    Triangle::Triangle(){
        this->sideA = 0;
        this->sideB = 0;
        this->sideC = 0;
    }
}
#endif TRIANGLE_CPP