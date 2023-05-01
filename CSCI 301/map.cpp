//Beck Christensen, 4/30/2023, Sunday
//map function practice

#include <iostream>
#include <map>

using namespace std;

int main { 

//creat a map of strings to integers
map<string, int> map;

//Insert some values into the map
map["one"] = 1;
map["two"] = 2;
map["three"] = 3;

//get an iterator pointing to the first element in the map
map<string, int>::interator it = map.begin();

//iterate through map and print values
while (it != map.end()) {

	cout << "Key: " << it->first << ", Value: " << it->second << endl;
	++it;
}

return 0;
}