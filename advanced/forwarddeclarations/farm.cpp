//
// Created by Ahsan Ghani on 2022-08-13.
//
#include "farm.h"
#include "dog.h"

Farm::Farm()
{
}

Farm::~Farm()
{
}


void Farm::use_dog(const Dog& dog_param){
    dog_param.print_info();
}
