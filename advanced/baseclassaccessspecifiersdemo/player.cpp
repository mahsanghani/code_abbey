//
// Created by Ahsan Ghani on 2022-08-25.
//
#include "person.h"
#include "player.h"
#include <iostream>

Player::Player()
{
}

std::ostream& operator<<(std::ostream& out, const Player& player){
    out << "Player[Full name : " << player.get_full_name() <<
        ",age : " << player.get_age() <<
        ",address : " << player.get_address() << "]";
    return out;
}

Player::~Player()
{
}