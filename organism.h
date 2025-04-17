#pragma once

#include <string>

class World;

class Organism {
protected:
  int strength, initiative, x, y, age;
  char symbol;
  int color;
  World *world;
  std::string name;
  const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
  Organism(int x, int y, int strength, int initiative, World *world, int color,
           char symbol, std::string name);
  virtual void action() = 0;
  virtual void collision(Organism *org) = 0;
  virtual void draw();

  bool isSameSpecies(Organism *org);
  void ageOrganism();
  void kill();
  bool runsAway();
  static bool priority(Organism *a, Organism *b);

  // GETTERS
  int getX() const;
  int getY() const;
  int getInitiative() const;
  int getStrength() const;
  int getAge() const;

  // SETTERS
  void setInitiative(int);
  void setStrength(int);
  bool setPosition(int x, int y);
};
