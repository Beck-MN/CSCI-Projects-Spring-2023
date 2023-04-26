/*
@problem header file for the Item class
@author Beck Christensen
@starID rg6291gh
@duedate 2.6.2022
@instructor Jie Meichsner 
*/

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item {
	
	public:
		
		//default constructor
		Item();
		
		//constructor
		Item(string name, double price, int num);
		
		//member funtions
		string getName() { return nameOfItem; };
		void setName(string name);
		double getPrice() { return unitPrice; };
		void setPrice(double price);
		int getQuantity() { return numOfItem; };
		void setQuantity(int num);
		
		//Operator funtions
		bool operator == (const Item &a);
		friend istream& operator >> (istream& ins, Item& target);
		friend ostream& operator << (ostream& outs, Item& source);
		
	private:
	
	//data members
	string nameOfItem;
	double unitPrice;
	int numOfItem;
	
};

#endif