//
// Created by millern on 3/26/2025.
//

#ifndef MAPCELL_H
#define MAPCELL_H

#include <string>

#include "Token.h"

class MapCell {

  public:
    MapCell(Token* token);
    ~MapCell();
    char getToken();
    bool hasArrow() const;
    bool hasWumpus() const;
    bool hasBat() const;
    bool hasPit() const;
    bool hasPlayer() const;

    void displayToken();

    void moveIntoCell();
    void moveOutOfCell();
    void moveWumpusIn();
    void moveWumpusOut();
    bool hasNorthCell() const;
    MapCell* getNorth();
    void setNorth(MapCell* cell);
    bool hasSouthCell() const;
    MapCell* getSouth();
    void setSouth(MapCell* cell);
    bool hasEastCell() const;
    MapCell* getEast();
    void setEast(MapCell* cell);
    bool hasWestCell() const;
    MapCell* getWest();
    void setWest(MapCell* cell);
    std::string getHint();
    int takeArrows();

  private:
    Token* token;
    Token* movingToken;
    bool playerInCell, wumpusInCell;
    MapCell* northCell;
    MapCell* southCell;
    MapCell* eastCell;
    MapCell* westCell;
};



#endif //MAPCELL_H
