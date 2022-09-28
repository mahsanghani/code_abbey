//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <cmath>
#include <iostream>

using namespace std;

class Sphere {
public:
  Sphere(double radius);
  double getVolume();

private:
  double radius_;
};

Sphere::Sphere(double radius) : radius_(radius) {}

double Sphere::getVolume() { return M_PI * 4 / 3 * pow(radius_, 3); }

int main() {
  Sphere s(5);
  cout << s.getVolume() << endl;
}