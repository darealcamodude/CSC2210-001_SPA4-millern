//
// Created by millern on 3/26/2025.
//

#include "MapCell.h"
#include "Arrow.h"
#include "Player.h"
#include "Wumpus.h"
#include <typeinfo>

using namespace std;

MapCell::MapCell(Token* token) {
  if (typeid(token) == typeid(Player)) {
    this->token = new Token();
    moveIntoCell();
  } else if (typeid(token) == typeid(Wumpus)) {
    this->token = new Token();
    moveWumpusIn();
  } else {
    this->token = token;
  }
}

MapCell::~MapCell() {
  delete northCell;
  delete southCell;
  delete eastCell;
  delete westCell;
  delete token;
}

void MapCell::moveWumpusIn() {
  wumpusInCell = true;
}

void MapCell::moveWumpusOut() {
  wumpusInCell = false;
}

void MapCell::moveOutOfCell() {
  playerInCell = false;
}

void MapCell::moveIntoCell() {
  playerInCell = true;
}

char MapCell::getToken() {
  return hasWumpus() ? 'W' : hasPlayer() ? 'P' : token->getToken();
}

bool MapCell::hasArrow() const {
  return token->getToken() == '^';
}

bool MapCell::hasBat() const {
  return token->getToken() == 'B';
}

bool MapCell::hasWumpus() const {
  return wumpusInCell;
}

bool MapCell::hasPit() const {
  return token->getToken() == '#';
}

bool MapCell::hasPlayer() const {
  return playerInCell;
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
  int arrows = typeid(token) == typeid(Arrow) ? dynamic_cast<Arrow*>(token)->getAmount() : 0;
  token = new Token();
  return arrows;
}
