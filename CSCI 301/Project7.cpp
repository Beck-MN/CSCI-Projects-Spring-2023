/*
@problem Main program for Bank Queue Simulation (Project 7)
@author Beck Christensen
@starID rg6291gh
@duedate 4.7.2023
@instructor Jie Meichsner 
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

/*
Represents a customer with arrival time and transaction time.
*/
class Customer {
public:
	/*
	Constructs a new customer object.
	@param arr_time The arrival time of the customer.
	@param trans_time The transaction time required for the customer.
	*/
    Customer(double arr_time, double trans_time) : arrival_time(arr_time), transaction_time(trans_time) {}
    double arrival_time;
    double transaction_time;
};

/*
Represents an event with event time, event type, and the customer involved in the event.
*/
class Event {
public:
	/*
	Constructs a new event object.
	@param time The time of the event.
	@param type The type of the event (arrival or departure).
	@param cust The customer involved in the event.
	*/
    Event(double time, char type, Customer* cust) : event_time(time), event_type(type), customer(cust) {}
    double event_time;
    char event_type;
    Customer* customer;
	/*
	Determines whether this event is less than another event.
	@param other The other event to compare to.
	@return True if this event is less than the other event, false otherwise.
	*/
    bool operator<(const Event& other) const {
        return event_time > other.event_time;
    }
	/*
	Determines whether this event is greater than another event.
	@param other The other event to compare to.
	@return True if this event is greater than the other event, false otherwise.
	*/	
    bool operator>(const Event& other) const {
        return event_time < other.event_time;
    }
	/*
	Determines whether this event is equal to another event.
	@param other The other event to compare to.
	@return True if this event is equal to the other event, false otherwise.
	*/
    bool operator==(const Event& other) const {
        return event_time == other.event_time;
    }
	/*
	Determines whether this event is not equal to another event.
	@param other The other event to compare to.
	@return True if this event is not equal to the other event, false otherwise.
	*/
    bool operator!=(const Event& other) const {
        return event_time != other.event_time;
    }
};

/*
A class representing a bank simulation.
*/
class BankSimulation {
public:
	/*
	Initializes a new instance of the BankSimulation class.
	*/
    BankSimulation() : current_time(0.0), num_customers(0), total_wait_time(0.0) {}
	/*
	Runs the bank simulation.
	@param input_file The name of the input file containing the customer data.
	*/
    void run(string input_file) {
        priority_queue<Event, vector<Event>, less<Event> > event_queue;
        ifstream infile(input_file.c_str());
        double arr_time, trans_time;
        while (infile >> arr_time >> trans_time) {
            Customer* customer = new Customer(arr_time, trans_time);
            event_queue.push(Event(arr_time, 'A', customer));
        }
        infile.close();
        while (!event_queue.empty()) {
            Event current_event = event_queue.top();
            event_queue.pop();
            current_time = current_event.event_time;
            if (current_event.event_type == 'A') { 
                handle_arrival(current_event, event_queue);
            } else {
                handle_departure(current_event);
            }
        }
        double avg_wait_time = total_wait_time / num_customers;
        cout << "Number of customers: " << num_customers << endl;
        cout << "Average waiting time: " << avg_wait_time << endl;
    }
private:
    double current_time;
    int num_customers;
    double total_wait_time;
    void handle_arrival(Event& arrival_event, priority_queue<Event, vector<Event>, less<Event> >& event_queue) {		    
        Customer* customer = arrival_event.customer;
		cout << "Processing an arrival event at time: " << current_time << endl;
        event_queue.push(Event(current_time + customer->transaction_time, 'D', customer));
    }
    void handle_departure(Event& departure_event) {
        Customer* customer = departure_event.customer;
        double wait_time = current_time - customer->arrival_time;
        total_wait_time += wait_time;
        num_customers++;
		cout << "Processing a departure event at time: " << current_time << endl;
        delete customer;
    }
};

int main() {
	
//Testing the Event class

	// Create some customers
    Customer* c1 = new Customer(1,5);
    Customer* c2 = new Customer(2,5);
    Customer* c3 = new Customer(3,4);

    // Create some events
    Event e1(5.0, 'A', c1);
    Event e2(3.0, 'D', c2);
    Event e3(4.0, 'A', c3);

    // Test the comparison operators
    cout << "e1 < e2: " << (e1 < e2) << " Answer: True(1)" << endl;
    cout << "e1 > e2: " << (e1 > e2) << " Answer: False(0)" << endl;
    cout << "e1 == e2: " << (e1 == e2) << " Answer: False(0)" << endl;
    cout << "e1 != e2: " << (e1 != e2) << " Answer: True(1)" << endl;

    cout << "e2 < e3: " << (e2 < e3) << " Answer: False(0)" << endl;
    cout << "e2 > e3: " << (e2 > e3) << " Answer: True(1)" << endl;
    cout << "e2 == e3: " << (e2 == e3) << " Answer: False(0)" << endl;
    cout << "e2 != e3: " << (e2 != e3) << " Answer: True(1)" << endl;

    cout << "e1 < e3: " << (e1 < e3) << " Answer: True(1)" << endl;
    cout << "e1 > e3: " << (e1 > e3) << " Answer: False(0)" << endl;
    cout << "e1 == e3: " << (e1 == e3) << " Answer: False(0)" << endl;
    cout << "e1 != e3: " << (e1 != e3) << " Answer: True(1)" << endl;
	
//Testing the main queue simulation

    BankSimulation simulation;	
    simulation.run("input.txt");
	
	
    return 0;
}
