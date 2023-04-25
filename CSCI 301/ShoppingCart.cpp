/*
@problem implementation file for the shoppingCart class
@author Beck Christensen
@starID rg6291gh
@duedate 2.6.2022
@instructor Jie Meichsner 
*/

#include "ShoppingCart.h"
    
    using namespace std;
    
    // Default Constructor
    template <class ItemType>
    ShoppingCart<ItemType>::ShoppingCart() {
        totalPrice = 0;
    }
    
    template <class ItemType>
    bool ShoppingCart<ItemType>::add(ItemType &newItemType) {
    
        bool added = Bag<ItemType>::add(newItemType);
    
        totalPrice = totalPrice + (newItemType.getQuantity() * newItemType.getPrice());
    
        return added;
    }
    
    template <class ItemType>
    bool ShoppingCart<ItemType>::remove(ItemType &anItemType) {
    
        bool removed = Bag<ItemType>::remove(anItemType);
    
        totalPrice = totalPrice - (anItemType.getQuantity() * anItemType.getPrice());
    
        return removed;
    }
    
    template <class ItemType>
    double ShoppingCart<ItemType>::getTotalPrice() {
        return totalPrice;
    }
