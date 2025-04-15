#pragma once
#include <ncurses.h>

#define GREEN_COLOR 1
#define RED_COLOR 2
#define BLUE_COLOR 3
#define MAGENTA_COLOR 4
#define WHITE_COLOR 5

class World {
public:
  World(int, int);
  ~World();
  void DrawWorld();
  void StartSimulation();
  void TakeATurn();

private:
  int width;
  int height;
  WINDOW *window;
};
