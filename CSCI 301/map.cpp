//Beck Christensen, 4/30/2023, Sunday
//map function practice

#include <iostream>
#include <map>

using namespace std;

int main { 

map<string, int> map;

map["one"] = 1;
map["two"] = 2;
map["three"] = 3;

map<string, int>::interator it = map.begin();

while (it != map.end()) {

	cout << "Key: " << it->first << ", Value: " << it->second << endl;
	++it;
}

return 0;
}