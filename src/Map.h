//
// Created by millern on 3/26/2025.
//

#ifndef MAP_H
#define MAP_H

class MapCell;


class Map {

  public:
    Map(int startX, int startY);
    ~Map();
    void showMap();
    bool move(char direction);

    private:
      MapCell* currentCell;
      MapCell *cells[6][6];
};



#endif //MAP_H
