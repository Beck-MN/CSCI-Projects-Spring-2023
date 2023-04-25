/*
@problem implementation file for DLB class
@author Beck Christensen
@starID rg6291gh
@duedate 3/2/2023
@instructor Jie Meichsner 
*/

#include "Node.h"
#include "DoublyLinkedBag.h"
#include <vector>
#include <string>
#define NULL 0

using namespace std;

template <typename ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag()
{
head = NULL;
tail = NULL;
count = 0;

}

template <typename ItemType>
vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const
{
vector<ItemType> v ;
Node<ItemType>* curr = head;
while(curr != NULL)
{
v.push_back(curr->getItem());
curr = curr->getNext();
}
return v;
}

template <typename ItemType>
bool DoublyLinkedBag<ItemType>::contains(ItemType item)
{
Node<ItemType>* curr = head;
while(curr != NULL)
{
if(curr->getItem() == item) {
return true;
}
curr = curr->getNext();
}
return false;
}

template <typename ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(ItemType item)
{
Node<ItemType>* curr = head;
int total = 0;
while(curr != NULL)
{
if(curr->getItem() == item) {
total++;
curr = curr->getNext();
}
}
return total;
}

template <typename ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
return count;
}

template <typename ItemType>
bool DoublyLinkedBag<ItemType>::add(ItemType item)
{
Node<ItemType>* n = new Node<ItemType>(item, tail);
tail = n;
if(head == NULL) {
head = n;
}
count++;
return true;

}

template <typename ItemType>
bool DoublyLinkedBag<ItemType>::remove(ItemType item)
{
Node<ItemType>* curr =head;
while(curr != NULL)
{
if(curr->getItem() == item) {
break;
}
curr = curr->getNext();
}
if(curr == NULL) {
return false;
}
else
{
Node<ItemType>* prev = curr->getPrevious();

if(curr == head) { //deleteing head node
head = curr->getNext();
}
else {
prev->setNext(curr->getNext());
}
if(head == NULL) { //delete the only single item in bag
tail = NULL;

delete curr;
count--;
return true;
}
}
}

template <typename ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty()
{
return count == 0;
}

template <typename ItemType>
void DoublyLinkedBag<ItemType>::clear()
{
if(head == NULL) {
	return;
}
Node<ItemType>* curr = head;
while(curr != NULL)
{
Node<ItemType>* next = curr->getNext();
delete curr;
curr = next;
}
head = NULL;
tail = NULL;
count = 0;
}