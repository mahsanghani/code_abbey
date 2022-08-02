//
// Created by Ahsan Ghani on 2022-08-01.
//
#include <iostream>
using namespace std;

class Dog{
public :
    string m_name;
};

struct Cat
{
public :
    string m_name;
};

struct Point{
    double x;
    double y;
};

void print_point(const Point& point){
    cout << "Point [ x: " << point.x << ", y : " << point.y << "]" << endl;
}


int main(){
    Dog dog1;
    Cat cat1;

    dog1.m_name = "Fluffy"; // Compiler error
    cat1.m_name = "Juny";
    cout << dog1.m_name << endl;
    cout << cat1.m_name << endl;

    Point point1;
    point1.x = 10;
    point1.y = 55.5;

    print_point(point1);

    point1.x = 40.4;
    point1.y = 2.7;
    print_point(point1);
    return 0;
}