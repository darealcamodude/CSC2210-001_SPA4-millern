//
// Created by millern on 3/26/2025.
//

#ifndef WUMPUS_H
#define WUMPUS_H

#include "Token.h"

class Wumpus : public Token {

  public:
    Wumpus();
    ~Wumpus();
    char getToken() const override;
    std::string getHint() const override;
};



#endif //WUMPUS_H
