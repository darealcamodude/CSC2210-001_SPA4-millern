//
// Created by millern on 3/26/2025.
//

#include "MapCell.h"
#include "Arrow.h"
#include "Player.h"
#include "Wumpus.h"
#include "Pit.h"
#include "Bat.h"
#include <typeinfo>
#include <iostream>

using namespace std;

MapCell::MapCell(Token* token) {
  if (token->getToken() == 'P') {
    this->token = new Token();
    playerInCell = true;
  } else if (token->getToken() == 'W') {
    this->token = new Token();
    wumpusInCell = true;
  } else {
    this->token = token;
    wumpusInCell = false;
    playerInCell = false;
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
  if (hasWumpus()) return 'W'; return token->getToken();
  //if (movingToken == NULL) return token->getToken(); else return token->getToken();
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
  Wumpus *wumpus = new Wumpus();
  string hint;
  if (hasWumpus()) hint = wumpus->getHint();
  else hint = token->getHint();
  delete wumpus;
  return hint;
}

int MapCell::takeArrows() {
  int arrows = token->getToken() == '^' ? dynamic_cast<Arrow*>(token)->getAmount() : 0;
  token = new Token();
  return arrows;
}

void MapCell::displayToken() {
  cout << "| Token: " << token->getToken() << " = ";
  if (typeid(token) == typeid(Arrow)) { cout << "Arrow";
  } else if (typeid(token) == typeid(Wumpus)) { cout << "Wumpus";
  } else if (typeid(token) == typeid(Player)) { cout << "Player";
  } else if (typeid(token) == typeid(Pit)) { cout << "Pit";
  } else if (typeid(token) == typeid(Bat)) { cout << "Bat";
  } else { cout << "token"; }
}
