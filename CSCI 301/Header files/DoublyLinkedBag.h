/*
@problem header file for DLB class
@author Beck Christensen
@starID rg6291gh
@duedate 3/2/2023
@instructor Jie Meichsner 
*/
#ifndef DOUBLYLINKEDBAG_H_
#define DOUBLYLINKEDBAG_H_
#include "Node.h"
#include <vector>
#include <string>

using namespace std;

template <typename ItemType>
class DoublyLinkedBag
{
private:
Node<ItemType> *head, *tail;
int count;
public:
DoublyLinkedBag();
vector<ItemType> toVector() const;
bool contains(ItemType item);
int getFrequencyOf(ItemType item);
int getCurrentSize() const;
bool add(ItemType item);
bool remove(ItemType item);
bool isEmpty();
void clear();

};

#endif