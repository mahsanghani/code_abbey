//
// Created by Ahsan Ghani on 2022-08-13.
//
#include <iostream>

#include "dog.h"
#include "farm.h"

int main(){

    Dog dog1("Fluffy");

    Farm farm1;
    farm1.use_dog(dog1);


    return 0;
}