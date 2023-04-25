/*
@ Test program for task 1
@author Beck Christensen
@starID rg6291gh
@duedate 1.23.2022
@instructor Jie Meichsner 
*/

#include <cstdio>
#include "fraction.h"
using namespace std;



int main() {
	
	fraction f(0,0);
	
	printf("Please enter a numerator:");
	int num;
	scanf("%d", &num);
	f.set_numerator(num);
	
	printf("Please enter a denominator:");
	scanf("%d", &num);
	f.set_denominator(num);
	
	printf("Your numerator is: %d\n", f.get_numerator());
	printf("Your denominator is: %d\n", f.get_denominator());
	f.display();
	
	return 0;
}