/*
@problem implementation file for the Item class
@author Beck Christensen
@starID rg6291gh
@duedate 2.6.2022
@instructor Jie Meichsner 
*/

#include <string>
#include <iostream>
#include "item.h"

using namespace std;

//constructor
Item::Item(string name, double price, int num) {
	
	nameOfItem = name;
	unitPrice = price;
	numOfItem = num;
}

//member functions
void Item::setName(string name) {
	nameOfItem = name;
}
void Item::setPrice(double price) {
	unitPrice = price;
}
void Item::setQuantity(int num) {
	numOfItem = num;
}

//operator functions
bool Item::operator == (const Item &a) {
	return (nameOfItem == a.getName()) 
			&& 
		   (unitPrice == a.getPrice());
}

/* istream& operator >> (istream& ins, Item& target) {
	ins >> target.getPrice() >> target.getQuantity();
	return ins;
} */

ostream& operator << (ostream& outs, Item& source) {
	outs << source.getName() << " $" << source.getPrice() 
		 << " " << source.getQuantity() << "\n";
	return outs;
}