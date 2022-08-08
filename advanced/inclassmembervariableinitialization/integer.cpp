//
// Created by Ahsan Ghani on 2022-08-08.
//
#include <iostream>
#include "integer.h"

Integer::Integer(int value) : inner_int(value)
{
    std::cout << "Constructor for Integer " << inner_int << " called" << std::endl;
}

Integer::~Integer()
{
}