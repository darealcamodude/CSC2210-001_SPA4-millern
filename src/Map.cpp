//
// Created by millern on 3/26/2025.
//

#include "Map.h"

#include <string>
#include "Player.h"
#include "MapCell.h"
#include "Wumpus.h"
#include "Token.h"
#include "Arrow.h"
#include "Pit.h"
#include "Bat.h"
#include <ctime>
#include <iostream>
using namespace std;

Map::Map(int startX, int startY, int wumpusX, int wumpusY) {
  MapCell* cell; srand(time(0)); int num;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (j == startX && i == startY) {
        cell = new MapCell(new Player());
        currentCell = cell;
      } else if (j == wumpusX && i == wumpusY) {
        cell = new MapCell(new Wumpus());
        wumpusCell = cell;
      } else {
        num = rand() % 4;
        switch (num) {
          case 0: cell = new MapCell(new Token()); break;
          case 1: cell = new MapCell(new Arrow((rand() % 2) + 1)); break;
          case 2: cell = new MapCell(new Pit()); break;
          case 3: cell = new MapCell(new Bat()); break;
        }
      }
      //cout << cell->getToken(); cell->displayToken();
      cells[j][i] = cell;
    }
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (i > 0) cells[j][i]->setNorth(cells[j][i-1]);
      if (j < 5) cells[j][i]->setEast(cells[j+1][i]);
      if (i < 5) cells[j][i]->setSouth(cells[j][i+1]);
      if (j > 0) cells[j][i]->setWest(cells[j-1][i]);
    }
  }

  arrowSupply = new Arrow(2);
}

Map::~Map() {
  delete currentCell;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      delete cells[i][j];
    }
  }
}

void Map::showMap() {
  cout << "Map Key:" << endl <<"| Arrrow: ^ | Pit: # | Player: P | Wumpus: W | Empty: . |" << endl;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      cout << " " << cells[i][j]->getToken();
    } cout << endl;
  }
}

bool Map::move(char direction) {
  bool moved = false; currentCell->moveOutOfCell();
  switch (tolower(direction)) {
    case 'w': if (currentCell->hasWestCell()) { currentCell = currentCell->getWest();
        moved = true; } else cout << "You hit a wall" << endl; break;
    case 's': if (currentCell->hasSouthCell()) { currentCell = currentCell->getSouth();
        moved = true; } else cout << "You hit a wall" << endl; break;
    case 'n': if (currentCell->hasNorthCell()) { currentCell = currentCell->getNorth();
        moved = true; } else cout << "You hit a wall" << endl; break;
    case 'e': if (currentCell->hasEastCell()) { currentCell = currentCell->getEast();
        moved = true; } else cout << "You hit a wall" << endl; break;
    default: cout << "Invalid direction." << endl; break;
  }
  currentCell->moveIntoCell(); return moved;
}

bool Map::shootArrow(char direction) {
  MapCell* cellCheck = currentCell; bool hitWumpus = false; arrowSupply->sub(1);
  switch (tolower(direction)) {
    case 'w': while (cellCheck->hasWestCell() && !hitWumpus) { cellCheck = cellCheck->getWest();
        hitWumpus = cellCheck->hasWumpus(); } break;
    case 'e': while (cellCheck->hasEastCell() && !hitWumpus) { cellCheck = cellCheck->getEast();
      hitWumpus = cellCheck->hasWumpus(); } break;
    case 'n': while (cellCheck->hasNorthCell() && !hitWumpus) { cellCheck = cellCheck->getNorth();
      hitWumpus = cellCheck->hasWumpus(); } break;
    case 's': while (cellCheck->hasSouthCell() && !hitWumpus) { cellCheck = cellCheck->getSouth();
      hitWumpus = cellCheck->hasWumpus(); } break;
  }
  return hitWumpus;
}

char Map::checkCurrentCell() {
  char token; if (currentCell->getToken() == '^') {
    arrowSupply->add(currentCell->takeArrows()); token = '^'; }
  else token = currentCell->getToken(); return token;
}

bool Map::hasArrows() {
  return arrowSupply->getAmount() > 0;
}

int Map::getArrowSupply() {
  return arrowSupply->getAmount();
}

void Map::batMove() {
  int num; int index = (rand() % 6) + 2;
  while (index > 0) {
    num = rand() % 4; switch (num) {
      case 0: if (currentCell->hasWestCell()) currentCell = currentCell->getWest();
        else index++; break;
      case 1: if (currentCell->hasNorthCell()) currentCell = currentCell->getNorth();
        else index++; break;
      case 2: if (currentCell->hasEastCell()) currentCell = currentCell->getEast();
        else index++; break;
      case 3: if (currentCell->hasSouthCell()) currentCell = currentCell->getSouth();
        else index++; break;
    } if (currentCell->hasWumpus() || currentCell->hasPit()) { index++; } index--;
  }
}

void Map::moveWumpus() {
  int num = (rand() % 4); wumpusCell->moveWumpusOut();
  switch (num) {
    case 0: if (wumpusCell->hasNorthCell()) wumpusCell = wumpusCell->getNorth(); break;
    case 1: if (wumpusCell->hasEastCell()) wumpusCell = wumpusCell->getEast(); break;
    case 2: if (wumpusCell->hasSouthCell()) wumpusCell = wumpusCell->getSouth(); break;
    case 3: if (wumpusCell->hasWestCell()) wumpusCell = wumpusCell->getWest(); break;
  }
  wumpusCell->moveWumpusIn();
}

void checkSideHelp(char direction, MapCell* currentCheckCell) {
  MapCell* checkCell = NULL;
  switch (tolower(direction)) {
    case 'n': if (currentCheckCell->hasNorthCell()) checkCell = currentCheckCell->getNorth(); break;
    case 'e': if (currentCheckCell->hasEastCell()) checkCell = currentCheckCell->getEast(); break;
    case 's': if (currentCheckCell->hasSouthCell()) checkCell = currentCheckCell->getSouth(); break;
    case 'w': if (currentCheckCell->hasWestCell()) checkCell = currentCheckCell->getWest(); break;
  }
  if (checkCell != NULL && checkCell->hasBat()) {
    cout << checkCell->getHint() << endl;
  }
}

void Map::checkSide(char direction) {
  MapCell* checkCell = NULL;
  switch (tolower(direction)) {
    case 'n': if (currentCell->hasNorthCell()) checkCell = currentCell->getNorth(); break;
    case 'e': if (currentCell->hasEastCell()) checkCell = currentCell->getEast(); break;
    case 's': if (currentCell->hasSouthCell()) checkCell = currentCell->getSouth(); break;
    case 'w': if (currentCell->hasWestCell()) checkCell = currentCell->getWest(); break;
  }
  if (checkCell !=  NULL) {
    checkSideHelp('n', checkCell); checkSideHelp('s', checkCell);
    checkSideHelp('e', checkCell); checkSideHelp('w', checkCell);
    cout << checkCell->getHint() << endl;
  } return;
}
