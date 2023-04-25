/*
@ Test program for task 2
@author Beck Christensen
@starID rg6291gh
@duedate 1.23.2022
@instructor Jie Meichsner 
*/

#include <cstdio>
#include "newfraction1.h"
using namespace std;

fraction sum(fraction f1, fraction f2);
fraction diff(fraction f1, fraction f2);
fraction mult(fraction f1, fraction f2);
fraction div(fraction f1, fraction f2);

int main() {
	
	fraction f1(0,0);
	fraction f2(0,0);
	
	printf("Please enter a numerator for f1:");
	int num;
	scanf("%d", &num);
	f1.set_numerator(num);
	printf("Please enter a denominator for f1:");
	scanf("%d", &num);
	f1.set_denominator(num);
	printf("Please enter a numerator for f2:");
	scanf("%d", &num);
	f2.set_numerator(num);
	printf("Please enter a denominator for f2:");
	scanf("%d", &num);
	f2.set_denominator(num);
	
	printf("f1 = ");
	f1.display();
	printf("f2 = ");
	f2.display();
	
	fraction f3 = sum(f1,f2);
	printf("f1 + f2 =");
	f3.display();
	f3 = diff(f1,f2);
	printf("f1 - f2 =");
	f3.display();
	f3 = mult(f1,f2);
	printf("f1 * f2 =");
	f3.display();
	f3 = div(f1,f2);
	printf("f1 / f2 =");
	f3.display();
	
	return 0;
}