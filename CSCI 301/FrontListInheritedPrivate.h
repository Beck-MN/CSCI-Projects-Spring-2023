/*
@problem FrontList Implementation with private inheritance 
@author Beck Christensen
@starID rg6291gh
@duedate 3.26.2023
@instructor Jie Meichsner 
*/
#pragma once
#include "FrontList.h"
#include "LinkedList.h"

template<class ItemType>
class FrontListInheritedPrivate : private LinkedList<ItemType>, public FrontList<ItemType> {
public:
    FrontListInheritedPrivate() : LinkedList<ItemType>() {}
    FrontListInheritedPrivate(const FrontListInheritedPrivate<ItemType>& otherList) : LinkedList<ItemType>(otherList) {}
    virtual ~FrontListInheritedPrivate() {}

    bool insert(const ItemType& newEntry) override {
        LinkedList<ItemType>::insert(1, newEntry);
        return true;
    }

    bool remove() override {
        if (LinkedList<ItemType>::getLength() > 0) {
            LinkedList<ItemType>::remove(1);
            return true;
        }
        else {
            return false;
        }
    }

    ItemType retrieve() const override {
        return LinkedList<ItemType>::getEntry(1);
    }

    void clear() override {
        LinkedList<ItemType>::clear();
    }
};
