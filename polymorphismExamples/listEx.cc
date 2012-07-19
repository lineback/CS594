#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
	list<int> myList;
	list<int>::iterator it;
	vector<int> myVector(5, 10);
	cout << "Length of myList = " << myList.size() << endl;

	for(int i = 0; i<10; i++){
		if(i%2 ==0) {myList.push_back(i);}
		else {myList.push_front(i);}
	}
	cout << "After pushing 10 elements … " << endl;
	cout << "Length of myList = " << myList.size() << endl;
   	
	cout <<"myList contains :";
	for(it = myList.begin(); it != myList.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	it = myList.begin();
	it++; // point to second element 
	myList.insert(it, 300);
	cout <<"myList contains :";
	for(it = myList.begin(); it != myList.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	// it now points to the last element
	it = myList.begin(); it++; it++; // set it to the third element
	myList.insert(it, 2, 400);	
	cout <<"myList contains :";
	for(it = myList.begin(); it !=  myList.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	// iterator now points to the end
	it--;  // go back one
	myList.insert(it, myVector.begin(), myVector.end());
	cout <<"myList contains :";
	for(it = myList.begin(); it != myList.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
 	myList.sort();
	cout << "After sorting " << endl;
	cout <<"myList contains :";
	for(it = myList.begin(); it != myList.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	return 0;
}
