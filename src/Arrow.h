//
// Created by millern on 3/26/2025.
//

#ifndef ARROW_H
#define ARROW_H

#include "Token.h"
//#include "InventoryItem.h"

class Arrow : public Token{
  public:
    Arrow(int startingQuantity);
    ~Arrow();

    int getAmount();
    void add(int amount);
    void sub(int amount);
    char getToken() const override;

    private:
      int quantity;
};



#endif //ARROW_H
