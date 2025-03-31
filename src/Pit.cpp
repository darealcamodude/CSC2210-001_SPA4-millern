//
// Created by millern on 3/26/2025.
//

#include "Pit.h"

Pit::Pit() {

}

Pit::~Pit() {

}

char Pit::getToken() const {
  return '#';
}

std::string Pit::getHint() const {
  return "You feel a draft.";
}