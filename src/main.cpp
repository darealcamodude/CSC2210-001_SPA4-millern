//
// Created by millern on 3/26/2025.
//

#include "Map.h"
#include "Token.h"
#include "InventoryItem.h"

#include <iostream>
using namespace std;

void intro();
void displayHelp();
void displayActions();
void badEnd1();
void badEnd2();
void goodEnd();
void displayHints(Map* map);

int main() {
  intro(); bool playing = true; char action; srand(time(NULL)); int wumpusMove = 0;
  Map* map = new Map(rand() % 6, rand() % 6);
  while (playing) {
    displayActions(); cin >> action;
    switch (tolower(action)) {
      case 'w': case 'e': case 's': case 'n': { bool moved = map->move(action); if (moved) {
          char currentCellEnd = map->checkCurrentCell(); if (currentCellEnd == 'W') {
            badEnd1(); playing = false; break; } if (currentCellEnd == '#') {
              badEnd2(); playing = false; break; } if (currentCellEnd == '^') {
                cout << "You have gotten some more arrows. You now have " << map->getArrowSupply()
                << " arrows." << endl; } if (currentCellEnd == 'B') {
                  cout << "You have been taken away by a bat." << endl; map->batMove(); }} break; }
      case 'a':  if (!map->hasArrows()) { wumpusMove += 2;
        cout << "You have no arrows left." << endl; } else {
          cout << "Choose which direction to shoot:" << endl; cin >> action;
          if (map->shootArrow(action)) { goodEnd(); playing = false; } } break;
      case 'h':  displayHelp(); break;  case 'q':  playing = false; break;
      case 'm':  map->showMap(); break;  default: cout << "Invalid action." << endl; break;
    } if (wumpusMove > 0) { map->moveWumpus(); displayHints(map); }
  } delete map; return 0; }

void intro() {
  cout << "You have been summoned to hunt down a monster. "
          "You have no map of the dungeon you are in but you have 2 arrow of which you can shoot."
        << endl;
}

void displayHelp() {
  cout << "Help:" << endl;

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