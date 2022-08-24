//
// Created by Ahsan Ghani on 2022-08-23.
//
#include <iostream>
#include "player.h"

int main(){

    Player p1("Basketball");
    p1.set_first_name("John");
    p1.set_last_name("Snow");
    std::cout << "player : " << p1 << std::endl;

    return 0;
}