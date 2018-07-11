#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#pragma once
#include "Rectangle.hh"

    double Rectangle::Area(){
        return width * height;
    } 
    double Rectangle::GetWidth(){
        return width;
    }
    double Rectangle::GetHeight(){
        return height;
    }
    void Rectangle::SetWidth(double width){
        this->width = width;
    }
    void Rectangle::SetHeight(double height){
        this->height = height;
    }
    Rectangle::Rectangle(double width, double height){
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

#endif RECTANGLE_CPP
