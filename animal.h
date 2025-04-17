#pragma once
#include "organism.h"

class World;

class Animal : public Organism {
public:
  void move();
  void action() override;
  void collision(Organism *org) override;
};
