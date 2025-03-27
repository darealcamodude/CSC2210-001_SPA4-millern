//
// Created by millern on 3/26/2025.
//

#include "Arrow.h"

Arrow::Arrow(int startingQuantity) {
  quantity = startingQuantity;
}

Arrow::~Arrow() {

}

int Arrow::getAmount() {
  return quantity;
}

void Arrow::add(int amount) {
  quantity += amount;
}

void Arrow::sub(int amount) {
  quantity -= amount;
}

char Arrow::getToken() const {
  return '^';
}
