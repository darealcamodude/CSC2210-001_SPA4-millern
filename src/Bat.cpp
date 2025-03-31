//
// Created by millern on 3/31/2025.
//

#include "Bat.h"

Bat::Bat() {

}

Bat::~Bat() {

}

char Bat::getToken() const{
  return 'B';
}

std::string Bat::getHint() const{
  return "You hear flapping.";
}