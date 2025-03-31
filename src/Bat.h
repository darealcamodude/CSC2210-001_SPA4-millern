//
// Created by millern on 3/31/2025.
//

#ifndef BAT_H
#define BAT_H

#include "Token.h"

class Bat : public Token{
  public:
    Bat();
    ~Bat();
    char getToken() const override;
    std::string getHint() const override;

};



#endif //BAT_H
