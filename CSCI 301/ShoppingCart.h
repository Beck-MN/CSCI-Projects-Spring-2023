/*
@problem header file for the shoppingCart class
@author Beck Christensen
@starID rg6291gh
@duedate 2.6.2022
@instructor Jie Meichsner 
*/
 #ifndef _SHOPPING_CART_H
    #define _SHOPPING_CART_H
    
    #include "Bag.h"
    #include "item.h"
    
    #include <iostream>
    #include <iomanip>
    
    using namespace std;
    
    template <class ItemType>
    class ShoppingCart : public Bag<ItemType> {
    private:
        double totalPrice;
    public:
	
		//functions
        ShoppingCart();
        double getTotalPrice();
        bool add(ItemType &newItemType);
        bool remove(ItemType &anItemType);
    
    };



#endif