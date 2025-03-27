//
// Created by millern on 3/26/2025.
//

#ifndef PIT_H
#define PIT_H

#include "Token.h"

class Pit : public Token {

  public:
    Pit();
    ~Pit();
    char getToken() const override;
    std::string getHint() const override;
};



#endif //PIT_H
