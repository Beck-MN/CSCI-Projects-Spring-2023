/*
@problem implementation file for task 1
@author Beck Christensen
@starID rg6291gh
@duedate 1.23.2022
@instructor Jie Meichsner 
*/
#include <cstdio>
#include "fraction.h"

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
	printf("Your fraction is: %d/%d\n",numerator,denominator);
}