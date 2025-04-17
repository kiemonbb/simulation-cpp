#include "animal.h"
#include <cstdlib>
#include <typeinfo>

void Animal::move() {
  int move = rand() % 4;
  while (!setPosition(getX() + moves[move][0], getY() + moves[move][1])) {
    move++;
    move %= 4;
  }
}

void Animal::action() {
  ageOrganism();
  move();
}

void Animal::collision(Organism *org) {
  if (this == org) {
    return;
  } else if (typeid(*this) == typeid(*org)) {
    // TODO => implement reproduction
  } else if (runsAway() || org->runsAway()) {
    return;
  } else if (this->strength >= org->getStrength()) {
    org->kill();
  } else if (this->strength < org->getStrength()) {
    this->kill();
  }
}
