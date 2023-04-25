/*
@problem implementation file for task 3
@author Beck Christensen
@starID rg6291gh
@duedate 1.23.2022
@instructor Jie Meichsner 
*/
#include <math.h>
#include <cstdio>
#include <iostream>
#include "newfraction2.h"

using namespace std;

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

fraction fraction::operator+(fraction& f) {
	int sum_num, sum_den;
	sum_num = numerator + f.get_numerator();
	sum_den = denominator * f.get_denominator();
	fraction sum(sum_num, sum_den);
	return sum;
}

fraction fraction::operator-(fraction& f) {
	int diff_num, diff_den;
	diff_num = numerator - f.get_numerator();
	diff_den = denominator * f.get_denominator();
	fraction diff(diff_num, diff_den);
	return diff;
}


fraction operator*(fraction& f1, fraction& f2) {
	int mult_num, mult_den;
	mult_num = f1.get_numerator() * f2.get_numerator();
	mult_den = f1.get_denominator() * f2.get_denominator();
	fraction mult(mult_num, mult_den);
	return mult;
}

fraction operator/(fraction& f1, fraction& f2) {
	int div_num, div_den;
	div_num = f1.get_numerator() * f2.get_denominator();
	div_den = f1.get_denominator() * f2.get_numerator();
	fraction div(div_num, div_den);
	return div;
}

ostream& operator <<(ostream& outs, const fraction& source)
    
    {
		outs << source.get_numerator( ) <<"/"<< source.get_denominator( );
		return outs;
    }

istream& operator >>(istream& ins, const fraction& target)
    {
		ins >> target.get_numerator()>> target.get_denominator();
		return ins;
    }