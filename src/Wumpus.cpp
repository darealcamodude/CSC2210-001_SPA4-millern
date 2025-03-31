//
// Created by millern on 3/26/2025.
//

#include "Wumpus.h"

Wumpus::Wumpus() {

}

Wumpus::~Wumpus() {

}

char Wumpus::getToken() const {
  return 'W';
}

std::string Wumpus::getHint() const {
  return "You hear grumbling.";
}