//
// Created by millern on 3/26/2025.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
  public:
    virtual ~Token();
    virtual char getToken() const;
    virtual std::string getHint() const;

};

#endif //TOKEN_H
