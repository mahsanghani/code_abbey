//
// Created by Ahsan Ghani on 2022-08-23.
//
#include "number.h"

Number::Number(int value) : m_wrapped_int(value)
{
}

std::ostream& operator<<(std::ostream& out , const Number& number){
    out << "Number : [" << number.m_wrapped_int << "]";
    return out;
}

Number::~Number()
{
}