#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){
	
	map<string, int> myMap;
	map<string, int>::iterator it;

	myMap["Jim"] = 100;
	myMap["Jane"] = 99;
	myMap["Steve"] = 52;
	myMap["Rene"] = 100;
	cout << "myMap contains: {";
	for(it = myMap.begin(); it != myMap.end(); it++){
		cout << " " << it->first << ":" << it->second;
	}
	cout << " }" << endl;
	if( myMap.count("Jim")){
		cout << "\"Jim\" is an element of the map." << endl;
	}
	else{
		cout << "\"Jim\" is not an element of the map." << endl;
	}
	if( myMap.count("Bob")){
		cout << "\"Bob\" is an element of th map." << endl;
	}
	else{
		cout << "\"Bob\" is not an element of th map." << endl;
	}
	return 0;
} 
	
