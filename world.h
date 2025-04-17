#pragma once
#include "organism.h"
#include <list>
#include <ncurses.h>
#include <vector>

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
  void DrawChar(char symbol, int color, int y, int x);
  void StartSimulation();
  void TakeATurn();

  void AddOrganism(Organism *organism);
  Organism * GetOrganism(int x,int y);

  int getTurn();
  int getWidth();
  int getHeight();

private:
  int width, turn, height;
  WINDOW *window;
  std::vector<Organism*> organisms;
};
