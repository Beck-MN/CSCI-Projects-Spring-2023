/*
@problem main file for project 2
@author Beck Christensen
@starID rg6291gh
@duedate 2.6.2022
@instructor Jie Meichsner 
*/

#include "item.h"
#include "ShoppingCart.h"

#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	
	
	char cont = 'y';
	string name;
	int mod;
	int q;
	double price;
	ShoppingCart<Item> cart;
	
	printf("Welcome to becks shopping center.\n");
	printf("Enter the item as the following order:\n");
	printf("name unitPrice quantity\n");
	while(cont == 'y') {
		scanf("%s %lf %d", &name, &price, &q);
		Item newItem(name,price,q);
		cart.add(newItem);
		printf("do you want to continue y/n?\n");
		scanf("%c", &cont);
	}
	
	printf("do you want to modify your ordery/n?\n");
	scanf("%c", &cont);
	while(cont == 'y') {
		printf("Enter 1: add, 2: remove, 3: change quantity\n");
		scanf("%d", &mod);
		if(mod == 1) {
			printf("Enter the item as the following order:\n");
			printf("name unitPrice quantity\n");
			scanf("%s %lf %d", &name, &price, &q);
			Item newItem(name,price,q);
			cart.add(newItem);
		}
		if(mod == 2) {
			printf("Enter the item as the following order:\n");
			printf("name unitPrice quantity\n");
			scanf("%s %lf %d", &name, &price, &q);
			Item newItem(name,price,q);
			cart.remove(newItem);
		}
		if(mod == 3) {
			printf("Enter the item as the following order:\n");
			printf("name unitPrice quantity\n");
			scanf("%s %lf %d", &name, &price, &q);
			Item newItem(name,price,q);
			printf("Enter new quantity:");
			int newQ;
			scanf("%d",&newQ);
			Item n(name,price,newQ);
			cart.add(n);
			cart.remove(newItem);
		}
		printf("do you want to modify your ordery/n?\n");
		scanf("%c", &cont);
	}
	
	
	return 0;
}