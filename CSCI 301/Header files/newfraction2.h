/*
@ Header file for task 3
@author Beck Christensen
@starID rg6291gh
@duedate 1.23.2022
@instructor Jie Meichsner 
*/
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

using namespace std;

class fraction { 
	public:
		
		//contrusctor
		fraction(int starting_num = 0, int starting_den = 0);

		//functions
		void set_numerator(int numerator);
		void set_denominator(int denominator);
		int get_numerator() const { return numerator;}
		int get_denominator() const { return denominator;}
		void display();
		fraction operator+(fraction& f);
		fraction operator-(fraction& f);
		
	friend istream& operator >>(istream& ins, const fraction& target);
		
	private:
	
	int numerator;
	
	int denominator;

};

//nonmember funcitons
fraction operator*(fraction& f1, fraction& f2);
fraction operator/(fraction& f1, fraction& f2);
std::ostream& operator <<(std::ostream & outs, const fraction& source);

#endif