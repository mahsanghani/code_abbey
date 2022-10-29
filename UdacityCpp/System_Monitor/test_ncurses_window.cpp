//
// Created by Ahsan Ghani on 2022-10-29.
//
#include <ncurses.h>

int main() {
  initscr();

  WINDOW *win = newwin(20, 20, 0, 0);
  box(win, '|', '-');

  refresh();
  wrefresh(win);

  getch();
  endwin();
  delwin(win);

  return 0;
}