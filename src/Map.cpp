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
#include <ctime>
#include <iostream>

Map::Map(int startX, int startY) {
  MapCell* cell; srand(time(NULL)); bool wumpusGenerated = false;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (i == startX && j == startY) {
        cell = new MapCell(new Player());
        currentCell = cell;
      } else {
        int num = rand() % (wumpusGenerated ? 3 : 4);
        switch (num) {
          case 0: cell = new MapCell(new Token()); break;
          case 1: cell = new MapCell(new Arrow((rand() % 2) + 1)); break;
          case 2: cell = new MapCell(new Pit()); break;
          case 3: cell = new MapCell(new Wumpus()); break;
        }
      }
      cells[i][j] = cell;
    }
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (j > 0) cells[i][j]->setNorth(cells[i][j-1]);
      if (i < 5) cells[i][j]->setEast(cells[i+1][j]);
      if (j < 5) cells[i][j]->setSouth(cells[i][j+1]);
      if (i > 0) cells[i][j]->setWest(cells[i-1][j]);
    }
  }
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
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << " " << cells[i][j]->hasPlayer() ? 'P' : cells[i][j]->getToken();
    } std::cout << std::endl;
  }
}

bool Map::move(char direction) {
  bool moved = false; currentCell->moveOutOfCell();
  switch (tolower(direction)) {
    case 'w': if (currentCell->hasWestCell()) { currentCell = currentCell->getWest();
        moved = true; } break;
    case 's': if (currentCell->hasSouthCell()) { currentCell = currentCell->getSouth();
        moved = true; } break;
    case 'n': if (currentCell->hasNorthCell()) { currentCell = currentCell->getNorth();
        moved = true; } break;
    case 'e': if (currentCell->hasEastCell()) { currentCell = currentCell->getEast();
        moved = true; } break;
    default: std::cout << "Invalid direction." << std::endl; break;
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
    } if (currentCell->hasWumpus()) { index++; } index--;
  }
}
