#ifndef SQUARE_CPP
#define SQUARE_CPP
#pragma once
#include "Square.hh"

double Square::Area(){
    return side * side;
}
double Square::GetSide(){
    return side;
}
void Square::SetSide(double side){
    this->side = side;
}
Square::Square(double side){
    this->side = side;
}
Square::~Square(){
    side = 0;
}
Square::Square(){
    side = 0;
}
#endif SQUARE_CPP