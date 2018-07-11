#ifndef SQUARE_CPP
#define SQUARE_CPP
#pragma once
#include "Square.hh"
namespace unit1{
    double Square::Area(){
        return side * side;
    }
    double Square::GetSide(){
        return side;
    }
    void Square::SetSide(double side) throw(std::invalid_argument){
        if(side < 0)
            throw std::invalid_argument("side must be nonnegative value");
        this->side = side;
    }
    Square::Square(double side) throw(std::invalid_argument){
        if(side < 0)
            throw std::invalid_argument("side must be nonnegative value");
        this->side = side;
    }
    Square::~Square(){
        side = 0;
    }
    Square::Square(){
        side = 0;
    }
}
#endif SQUARE_CPP