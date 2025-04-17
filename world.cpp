#include "world.h"
#include <algorithm>
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
  this->turn = 0;

  start_color();
  init_pair(GREEN_COLOR, COLOR_WHITE, COLOR_GREEN);
  init_pair(RED_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(WHITE_COLOR, COLOR_BLACK, COLOR_WHITE);
  init_pair(BLUE_COLOR, COLOR_WHITE, COLOR_BLUE);
  init_pair(MAGENTA_COLOR, COLOR_WHITE, COLOR_MAGENTA);
}

void World::DrawWorld() { wrefresh(this->window); }

void World::DrawChar(char symbol, int color, int x, int y) {
  wattron(this->window, COLOR_PAIR(color));
  mvwaddch(this->window, y, x, symbol);
  wattroff(this->window, COLOR_PAIR(color));
}

void World::TakeATurn() {
  turn++;
  std::sort(organisms.begin(), organisms.end(), Organism::priority);
  for (Organism *org : organisms) {
    if (org->getInitiative() > -1) {
      org->action();
    }
  }
}

void World::AddOrganism(Organism *organism) { organisms.push_back(organism); }

Organism *World::GetOrganism(int x, int y) {
  if (x < 0 || x >= width || y < 0 || y >= height) {
    return nullptr;
  }
  for (Organism *org : organisms) {
    if (org->getX() == x && org->getY() == y) {
      return org;
    }
  }
  return nullptr;
}

World::~World() { delwin(this->window); }
