//Beck Christensen, 4/30/2023, Sunday
//map function practice

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() { 

//creat a map of strings to integers
map<string, int> m;

//Insert some values into the map
m["one"] = 1;
m["two"] = 2;
m["three"] = 3;

//get an iterator pointing to the first element in the map
map<string,int>::iterator it = m.begin();

//iterate through map and print values
while (it != m.end()) {

	cout << "Key: " << it->first << ", Value: " << it->second << endl;
	++it;
}

return 0;
}