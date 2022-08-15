//
// Created by Ahsan Ghani on 2022-08-15.
//
#include <iostream>
#include "point.h"
#include "car.h"

int main(){


    Point p1(10,10,10);
    Car c1("red",200.0);

    p1 = c1;

    std::cout << "p1 : " << p1 << std::endl;


    return 0;
}