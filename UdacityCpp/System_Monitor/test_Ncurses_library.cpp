//
// Created by Ahsan Ghani on 2022-10-29.
//
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

WINDOW *create_new_window(int height, int width, int start_y, int start_x);

int main() {

  usleep(1000);

  initscr();

  noecho();

  addch('H' | A_UNDERLINE);
  addch('E' | A_UNDERLINE);
  addch('L' | A_BOLD);
  addch('L' | A_BOLD);
  addch('O');
  addch('!');

  getch();

  endwin();

  return 0;
}