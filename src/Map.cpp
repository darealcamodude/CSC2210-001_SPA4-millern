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
      std::cout << " " << cells[i][j]->getToken();
    }
    std::cout << std::endl;
  }
}

bool Map::move(char direction) {
  switch (tolower(direction)) {
    case 'w': if (currentCell->hasWestCell()) { currentCell = currentCell->getWest(); return true;
      } else return false;
    case 's': if (currentCell->hasSouthCell()) { currentCell = currentCell->getSouth(); return true;
    } else return false;
    case 'n': if (currentCell->hasNorthCell()) { currentCell = currentCell->getNorth(); return true;
    } else return false;
    case 'e': if (currentCell->hasEastCell()) { currentCell = currentCell->getEast(); return true;
    } else return false;
  }
  std::cout << "Invalid direction." << std::endl; return false;
}
