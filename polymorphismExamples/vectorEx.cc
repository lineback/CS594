#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> myVector;
	cout << "Length of myVector = " << myVector.size() << endl;
	cout << "Capacity of myVector = " << myVector.capacity() << endl;
	myVector.resize(100);
	cout << "After resizing … " << endl;
	cout << "Length of myVector = " << myVector.size() << endl;
	cout << "Capacity of myVector = " << myVector.capacity() << endl;
	for(int i = 0; i<100; i++){
		myVector.push_back(i);
		if(i%10 == 0){
			cout << "After pushing " << i + 1 << "  elements … " << endl;
			cout << "Length of myVector = " << myVector.size() << endl;
			cout << "Capacity of myVector = " << myVector.capacity() << endl;
		}
	}
	cout << "After pushing 100 elements … " << endl;
	cout << "Length of myVector = " << myVector.size() << endl;
	cout << "Capacity of myVector = " << myVector.capacity() << endl;
	cout << "myVector[99] = " << myVector[99] << endl;
	cout << "myVector[109] = " << myVector[109] << endl; 
	for(int i = 0; i<90; i++){
		myVector.pop_back();
	}
	cout << "After popping 90 elements … " << endl;
	cout << "Length of myVector = " << myVector.size() << endl;
	cout << "Capacity of myVector = " << myVector.capacity() << endl;
	return 0;
}
