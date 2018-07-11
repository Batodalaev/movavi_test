#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#pragma once
#include "Rectangle.hh"
namespace unit1{
    double Rectangle::Area(){
        return width * height;
    } 
    double Rectangle::GetWidth(){
        return width;
    }
    double Rectangle::GetHeight(){
        return height;
    }
    void Rectangle::SetWidth(double width) throw(std::invalid_argument){
        if(width < 0)
            throw std::invalid_argument("width must be nonnegative value");
        this->width = width;
    }
    void Rectangle::SetHeight(double height) throw(std::invalid_argument){
        if(height < 0)
            throw std::invalid_argument("height must be nonnegative value");
        this->height = height;
    }
    Rectangle::Rectangle(double width, double height) throw(std::invalid_argument){
        if(width < 0)
            throw std::invalid_argument("width must be nonnegative value");
        if(height < 0)
            throw std::invalid_argument("height must be nonnegative value");
        this->width = width;
        this->height = height;
    }
    Rectangle::~Rectangle(){
        width = 0;
        height = 0;
    }
    Rectangle::Rectangle(){
        width = 0;
        height = 0;
    }
}
#endif RECTANGLE_CPP
