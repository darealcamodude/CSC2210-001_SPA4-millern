//
// Created by millern on 3/26/2025.
//

#ifndef MAP_H
#define MAP_H

class MapCell;


class Map {

  public:
    Map(int startX, int startY);
    void setup();
    void tearDown();
    bool move(char direction);

    private:
      MapCell* currentCell;
};



#endif //MAP_H
