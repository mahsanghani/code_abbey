//
// Created by Ahsan Ghani on 2022-09-16.
//
#include <iostream>

using namespace std;

int main() {
  enum class Colour { white, black, blue, red };

  Colour my_colour = Colour::blue;

  if (my_colour == Colour::red) {
    cout << "The colour of my car is red!" << endl;
  } else {
    cout << "The colour of my car is not red!" << endl;
  }

  enum class Direction { kUp, kDown, kLeft, kRight };

  Direction a = Direction::kUp;

  switch (a) {
  case Direction::kUp:
    cout << "Going Up!" << endl;
    break;
  case Direction::kDown:
    cout << "Going Down!" << endl;
    break;
  case Direction::kLeft:
    cout << "Going Left!" << endl;
    break;
  case Direction::kRight:
    cout << "Going Right!" << endl;
    break;
  }
}