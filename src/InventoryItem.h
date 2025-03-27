//
// Created by millern on 3/26/2025.
//

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

class InventoryItem {
  public:
    virtual ~InventoryItem();
    virtual int getAmount() = 0;
    virtual void add(int amount) = 0;
    virtual void sub(int amount) = 0;
};

#endif //INVENTORYITEM_H
