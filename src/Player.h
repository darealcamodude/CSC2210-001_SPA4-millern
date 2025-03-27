//
// Created by millern on 3/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Token.h"
#include <string>

class Map;

class Player : public Token {

  public:
    Player();
    ~Player();
    char getToken() const override;
    std::string getHint() const override;

};



#endif //PLAYER_H
