//
// Created by millern on 3/26/2025.
//

#include "Map.h"
#include "Token.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Bat.h"

#include <iostream>
using namespace std;

void intro();
void displayHelp();
void displayActions();
void badEnd1();
void badEnd2();
void goodEnd();
void displayHints(Map* map);
bool moveCheck(Map* map);

int main() {
  intro(); bool playing = true; char action; srand(time(NULL)); int wumpusMove = 0;
  /*int pX = rand() % 6; int pY = rand() % 6; int wX, wY;
  do { wX = rand() % 6;  wY = rand() % 6;
  } while (wX == pX && wY == pY);*/
  int pX = 0; int pY = 0; int wX = 5; int wY = 5;
  Map* map = new Map(pX, pY, wX, wY);
  while (playing) {
    displayHints(map); displayActions(); cin >> action;
    switch (tolower(action)) {
      case 'w': case 'e': case 's': case 'n': {
        bool moved = map->move(action); if (moved) {
          playing = moveCheck(map); } break;}
        case 'a':  if (!map->hasArrows()) { wumpusMove += 2;
          cout << "You have no arrows left." << endl; } else {
            cout << "Choose which direction to shoot:" << endl; cin >> action;
            if (map->shootArrow(action)) { goodEnd(); playing = false; } } break;
        case 'h':  displayHelp(); break;  case 'q':  playing = false; break;
        case 'm':  map->showMap(); break;  default: cout << "Invalid action." << endl; break;
      } if (wumpusMove > 0) { map->moveWumpus(); }
    } delete map; return 0; }

void intro() {
  cout << "You have been summoned to hunt down a monster. "
          "You have no map of the dungeon you are in but you have 2 arrow of which you can shoot."
        << endl;
}

void displayHelp() {
  Pit *pit = new Pit(); Wumpus *wumpus = new Wumpus(); Bat *bat = new Bat();
  cout << "Help:" << endl;
  cout << "Pit 1 cell away: " << pit->getHint() << endl;
  cout << "Wumpus 1 cell away: " << wumpus->getHint() << endl;
  cout << "Bat 2 cells away: " << bat->getHint() << endl;
  delete pit; delete wumpus; delete bat;
}

void displayActions() {
  cout << "Actions: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit:" << endl;
}

void badEnd1() {
  cout << "You have been eaten by the Wumpus." << endl;
}

void badEnd2() {
  cout << "You have fallen into a pit." << endl;
}

void goodEnd() {
  cout << "You have shot down the Wumpus and returned home safely. "
          "Everyone will be safe for now." << endl;
}

void displayHints(Map* map) {
  map->checkSide('n'); map->checkSide('e'); map->checkSide('s'); map->checkSide('w');
}

bool moveCheck(Map *map) {
    char currentCellEnd = map->checkCurrentCell();
  if (currentCellEnd == 'W') {
    badEnd1(); return false;
  } if (currentCellEnd == '#') {
        badEnd2(); return false;
  } if (currentCellEnd == '^') {
          cout << "You have gotten some more arrows. You now have " << map->getArrowSupply()
          << " arrows." << endl;
  } if (currentCellEnd == 'B') {
            cout << "You have been taken away by a bat." << endl; map->batMove();
  } return true;
}