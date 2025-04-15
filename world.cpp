#include "world.h"
#include <ncurses.h>

World::World(int width, int height) {
  initscr();
  cbreak();
  curs_set(0);
  noecho();

  WINDOW *window = newwin(height, width, 0, 0);
  box(window, 0, 0);
  this->window = window;
  this->width = width;
  this->height = height;

  start_color();
  init_pair(GREEN_COLOR, COLOR_WHITE, COLOR_GREEN);
  init_pair(RED_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(WHITE_COLOR, COLOR_BLACK, COLOR_WHITE);
  init_pair(BLUE_COLOR, COLOR_WHITE, COLOR_BLUE);
  init_pair(MAGENTA_COLOR, COLOR_WHITE, COLOR_MAGENTA);
}

void World::DrawWorld() { wrefresh(this->window); }

World::~World() { delwin(this->window); }
