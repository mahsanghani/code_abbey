//
// Created by Ahsan Ghani on 2022-08-15.
//
#include <cmath>
#include "point.h"

double Point::length() const{
    return sqrt(pow(m_x - 0, 2) +  pow(m_y - 0, 2) * 1.0);
}