//
// Created by millern on 3/26/2025.
//

#include "Player.h"


Player::Player() {

}

Player::~Player() {

}

char Player::getToken() const {
  return 'P';
}

std::string Player::getHint() const {
  return "This is where you are";
}