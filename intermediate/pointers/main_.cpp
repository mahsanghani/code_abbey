//
// Created by Ahsan Ghani on 2022-07-31.
//
#include <iostream>
#include "cylinder.h"
using namespace std;

int main(){

    Cylinder cylinder1(10,10);

    cylinder1.volume();

    //Managing a stack object through pointers
    Cylinder* p_cylinder1 = &cylinder1;

    //cout << "volume : " << (*p_cylinder1).volume() << endl;
    cout << "volume : " << p_cylinder1->volume() << endl;

    //Create a cylinder heap object through the new operator
    Cylinder* p_cylinder2 = new Cylinder(100,2); // Heap

    cout << "volume(clylinder2) : " << p_cylinder2->volume() << endl;
    cout << "base_rad(cylinder2) : " << p_cylinder2->get_base_radius() << endl;

    delete p_cylinder2;

    return 0;
}