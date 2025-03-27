//
// Created by millern on 3/26/2025.
//

#include "MapCell.h"
#include "Arrow.h"
#include <typeinfo>

using namespace std;

MapCell::MapCell(Token* token) {
  this->token = token;
}

MapCell::~MapCell() {
  delete northCell;
  delete southCell;
  delete eastCell;
  delete westCell;
  delete token;
}

char MapCell::getToken() {
  return token->getToken();
}

bool MapCell::hasArrow() const {
  return token->getToken() == '^';
}

bool MapCell::hasBat() const {
  return token->getToken() == 'B';
}

bool MapCell::hasWumpus() const {
  return token->getToken() == 'W';
}

bool MapCell::hasPit() const {
  return token->getToken() == '#';
}

bool MapCell::hasPlayer() const {
  return token->getToken() == 'P';
}

bool MapCell::hasNorthCell() const {
  return northCell != NULL;
}

bool MapCell::hasSouthCell() const {
  return southCell != NULL;
}

bool MapCell::hasEastCell() const {
  return eastCell != NULL;
}

bool MapCell::hasWestCell() const {
  return westCell != NULL;
}

MapCell* MapCell::getNorth() {
  return northCell;
}

MapCell* MapCell::getSouth() {
  return southCell;
}

MapCell* MapCell::getEast() {
  return eastCell;
}

MapCell* MapCell::getWest() {
  return westCell;
}

void MapCell::setNorth(MapCell* cell) {
  northCell = cell;
}

void MapCell::setSouth(MapCell* cell) {
  southCell = cell;
}

void MapCell::setEast(MapCell* cell) {
  eastCell = cell;
}

void MapCell::setWest(MapCell* cell) {
  westCell = cell;
}

string MapCell::getHint() {
  return token->getHint();
}

int MapCell::takeArrows() {
  return typeid(token) == typeid(Arrow) ? dynamic_cast<Arrow*>(token)->getAmount() : 0;
}
