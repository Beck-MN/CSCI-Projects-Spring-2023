/*
@problem implementation file for task 2
@author Beck Christensen
@starID rg6291gh
@duedate 1.23.2022
@instructor Jie Meichsner 
*/
#include <math.h>
#include <cstdio>
#include "newfraction1.h"

fraction::fraction(int starting_num, int starting_den) {
	numerator = starting_num;
	denominator = starting_den;
}

void fraction::set_numerator(int new_num) {
	numerator = new_num;
}

void fraction::set_denominator(int new_den) {
	denominator = new_den;
}

void fraction::display( ) {
	printf("%d/%d\n",numerator,denominator);
}

fraction sum(fraction f1, fraction f2){
	int den = f1.get_denominator() * f2.get_denominator();
	int num = f1.get_numerator() + f2.get_numerator();
	return fraction(num,den);	
}

fraction diff(fraction f1, fraction f2){
	int den = f1.get_denominator() * f2.get_denominator();
	int num = f1.get_numerator() - f2.get_numerator();
	return fraction(num,den);	
}

fraction mult(fraction f1, fraction f2){
	int den = f1.get_denominator() * f2.get_denominator();
	int num = f1.get_numerator() * f2.get_numerator();
	return fraction(num,den);	
}
fraction div(fraction f1, fraction f2){
	int den = f1.get_denominator() * f2.get_numerator();
	int num = f1.get_numerator() * f2.get_denominator();
	return fraction(num,den);	
}