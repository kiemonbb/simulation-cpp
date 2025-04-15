#pragma once
#include <ncurses.h>

class World {
public:
  World(int, int);
  void DrawWorld();
  void TakeATurn();

private:
  int width;
  int height;
  WINDOW *screen;
};
