//
// Created by Ahsan Ghani on 2022-07-31.
//
#include <iostream>
using namespace std;

const double PI {3.1415926535897932384626433832795};

class Cylinder {
public :
    //Functions (methods)
    double volume(){
        return PI * base_radius * base_radius * height;
    }

public :
    //Member variables
    double base_radius{1};
    double height{1};
};


int main(){

    Cylinder cylinder1; // Objects
    cout << "volume : " << cylinder1.volume() << endl;

    //Change the member variables
    cylinder1.base_radius = 10;
    cylinder1.height = 3;

    cout << "volume : " << cylinder1.volume() << endl;

    cylinder1.height =8;

    cout << "volume : " << cylinder1.volume() << endl;

    return 0;
}