#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	deque<int> myDeque;
	deque<int>::iterator it;

	cout << "Length of myDeque = " << myDeque.size() << endl;

	for(int i = 0; i<10; i++){
		if(i%2 ==0) {myDeque.push_back(i);}
		else {myDeque.push_front(i);}
	}
	cout << "After pushing 10 elements … " << endl;
	cout << "Length of myDeque = " << myDeque.size() << endl;
	cout << "myDeque.front() = " << myDeque.front() << endl;
	cout << "myDeque.back() = " << myDeque.back() << endl;
	
	cout <<"myDeque contains :";
	for(it = myDeque.begin(); it < myDeque.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	sort(myDeque.begin(), myDeque.end());
	cout << "After sorting " << endl;

	cout <<"myDeque contains :";
	for(it = myDeque.begin(); it < myDeque.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	return 0;
}
