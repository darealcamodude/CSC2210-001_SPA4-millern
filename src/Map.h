//
// Created by millern on 3/26/2025.
//

#ifndef MAP_H
#define MAP_H

class MapCell;
class Arrow;


class Map {

  public:
    Map(int startX, int startY);
    ~Map();
    void showMap();
    bool move(char direction);
    bool shootArrow(char direction);
    char checkCurrentCell();
    bool hasArrows();
    int getArrowSupply();
    void batMove();
    void moveWumpus();
    void checkSide(char direction);

    private:
      MapCell* currentCell;
      MapCell* wumpusCell;
      MapCell *cells[6][6];
      Arrow *arrowSupply;
};



#endif //MAP_H
