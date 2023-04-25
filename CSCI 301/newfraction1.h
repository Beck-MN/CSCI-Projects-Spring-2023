/*
@ Header file for task 2
@author Beck Christensen
@starID rg6291gh
@duedate 1.23.2022
@instructor Jie Meichsner 
*/
#ifndef FRACTION_H
#define FRACTION_H

class fraction { 
	public:
		
		//contrusctor
		fraction(int starting_num = 0, int starting_den = 0);

		//functions
		void set_numerator(int numerator);
		void set_denominator(int denominator);
		int get_numerator() const {return numerator;}
		int get_denominator() const {return denominator;}
		void display();
		
	private:
	
	int numerator;
	
	int denominator;

};

//nonmember funcitons
fraction sum(fraction f1, fraction f2);
fraction diff(fraction f1, fraction f2);
fraction mult(fraction f1, fraction f2);
fraction div(fraction f1, fraction f2);

#endif