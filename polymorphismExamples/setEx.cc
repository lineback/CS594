#include <iostream>
#include <set>
using namespace std;
int main(){
	set<int> mySet;
	set<int>::iterator it;

	for(int i = 0; i < 10; i++){
		mySet.insert(i);
	}
	cout << "mySet contains: ";
	for(it = mySet.begin(); it != mySet.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	mySet.insert(10);
	cout << "After inserting 10 ..." << endl;
	for(it = mySet.begin(); it != mySet.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	mySet.insert(5);
	cout << "After inserting 5 ..." << endl;
	for(it = mySet.begin(); it != mySet.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	if( mySet.count(5)){
		cout << "5 is an element of the set." << endl;
	}
	else{
		cout << "5 is not an element of the set." << endl;
	}
	if( mySet.count(20)){
		cout << "20 is an element of th set." << endl;
	}
	else{
		cout << "20 is not an element of th set." << endl;
	}	return 0;
} 
	
