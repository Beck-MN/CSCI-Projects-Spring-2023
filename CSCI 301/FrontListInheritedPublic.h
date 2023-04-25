/*
@problem FrontList Implementation with public inheritance 
@author Beck Christensen
@starID rg6291gh
@duedate 3.26.2023
@instructor Jie Meichsner 
*/
#pragma once
#include "FrontList.h"
#include "LinkedList.h"

using namespace std;

template<class ItemType>
class FrontListInheritedPublic : public LinkedList<ItemType>, public FrontList<ItemType> {
public:
    FrontListInheritedPublic() : LinkedList<ItemType>() {}
    FrontListInheritedPublic(const FrontListInheritedPublic<ItemType>& otherList) : LinkedList<ItemType>(otherList) {}
    virtual ~FrontListInheritedPublic() {}

    bool insert(const ItemType& newEntry) override;
    bool remove() override;
    ItemType retrieve() const override;
    void clear() override;

    using LinkedList<ItemType>::insert;
    using LinkedList<ItemType>::remove;
    using LinkedList<ItemType>::replace;
};

template<class ItemType>
bool FrontListInheritedPublic<ItemType>::insert(const ItemType& newEntry) {
    return LinkedList<ItemType>::insert(1, newEntry);
}

template<class ItemType>
bool FrontListInheritedPublic<ItemType>::remove() {
    return LinkedList<ItemType>::remove(1);
}

template<class ItemType>
ItemType FrontListInheritedPublic<ItemType>::retrieve() const {
    return LinkedList<ItemType>::getEntry(1);
}

template<class ItemType>
void FrontListInheritedPublic<ItemType>::clear() {
    while (!LinkedList<ItemType>::isEmpty()) {
        LinkedList<ItemType>::remove(1);
    }
}