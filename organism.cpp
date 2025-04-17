#include "organism.h"
#include "world.h"

Organism::Organism(int x, int y, int strength, int initiative, World *world,
                   int color, char symbol, std::string name) {
  this->world = world;
  this->x = x;
  this->y = y;
  this->strength = strength;
  this->initiative = initiative;
  this->age = 0;
  this->color = color;
  this->symbol = symbol;
  this->name = name;
  world->AddOrganism(this);
}
void Organism::draw() { world->DrawChar(symbol, color, y, x); }

int Organism::getX() const { return x; }
int Organism::getY() const { return y; }
int Organism::getInitiative() const { return initiative; }
int Organism::getStrength() const { return strength; }
int Organism::getAge() const { return age; }

bool Organism::setPosition(int newX, int newY) {
  if (x < 0 || x > world->getWidth() || y < 0 || y > world->getHeight()) {
    return false;
  }
  Organism *org = world->GetOrganism(newX, newY);
  x = newX;
  y = newY;
  if (org != nullptr) {
    this->collision(org);
  }
  return true;
}

void Organism::kill() {
  x = -1;
  y = -1;
  strength = -1;
  initiative = -1;
}

bool Organism::runsAway() { return false; }

bool Organism::priority(Organism *a, Organism *b) {
  if (a->getInitiative() > b->getInitiative()) {
    return true;
  } else if (a->getInitiative() < b->getInitiative()) {
    return false;
  } else {
    return a->getAge() > b->getAge() ? true : false;
  }
}

void Organism::ageOrganism() { age++; }

void Organism::setInitiative(int initiative) { initiative = initiative; }
void Organism::setStrength(int strength) { strength = strength; }

bool Organism::isSameSpecies(Organism *org) {
  return (org->name == name) ? true : false;
}
