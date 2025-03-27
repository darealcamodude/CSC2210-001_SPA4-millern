//
// Created by millern on 3/26/2025.
//

#ifndef ARROW_H
#define ARROW_H

#include "Token.h"
#include "InventoryItem.h"

class Arrow : public Token, public InventoryItem{
  public:
    Arrow(int startingQuantity);
    ~Arrow();

    int getAmount() override;
    void add(int amount) override;
    void sub(int amount) override;
    char getToken() const override;
};



#endif //ARROW_H
