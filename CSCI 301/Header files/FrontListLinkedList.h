/*
@problem FrontList Implementation in an instance of LinkedList
@author Beck Christensen
@starID rg6291gh
@duedate 3.26.2023
@instructor Jie Meichsner 
*/
#pragma once
#include "FrontList.h"
#include "LinkedList.h"

template<class ItemType>
class FrontListLinkedList : public FrontList<ItemType> {
private:
    LinkedList<ItemType>* listPtr;

public:
    FrontListLinkedList();
    FrontListLinkedList(const FrontListLinkedList<ItemType>& otherList);
    virtual ~FrontListLinkedList();

    bool isEmpty() const;
    bool insert(const ItemType& newEntry);
    bool remove();
    ItemType retrieve() const;
    void clear();
};

template<class ItemType>
FrontListLinkedList<ItemType>::FrontListLinkedList() {
    listPtr = new LinkedList<ItemType>();
}

template<class ItemType>
FrontListLinkedList<ItemType>::FrontListLinkedList(const FrontListLinkedList<ItemType>& otherList) {
    listPtr = new LinkedList<ItemType>(*otherList.listPtr);
}

template<class ItemType>
FrontListLinkedList<ItemType>::~FrontListLinkedList() {
    clear();
    delete listPtr;
}

template<class ItemType>
bool FrontListLinkedList<ItemType>::isEmpty() const {
    return listPtr->isEmpty();
}

template<class ItemType>
bool FrontListLinkedList<ItemType>::insert(const ItemType& newEntry) {
    return listPtr->insert(1, newEntry);
}

template<class ItemType>
bool FrontListLinkedList<ItemType>::remove() {
    return listPtr->remove(1);
}

template<class ItemType>
ItemType FrontListLinkedList<ItemType>::retrieve() const {
    return listPtr->getEntry(1);
}

template<class ItemType>
void FrontListLinkedList<ItemType>::clear() {
    while (!isEmpty()) {
        remove();
    }
}