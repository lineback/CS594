#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

template <class T>
class Vector{
private:
	int length;
	vector<T> data;
public:
	Vector() {length = 0;}
	Vector(int someLength) 
	{
		length = someLength;
		data.resize(length);
	}
	~Vector(){}

	T& operator[] (const int idx)
	{
		return data[idx];
	}
	Vector<T> operator+ (const Vector& other) 
	{
		if (length != other.length) 
		{
			cout << "Vectors must be the same length!" << endl;
			exit(0);
		}
		Vector<T> retVal(length);
		for(int i = 0; i < length; i++)
		{
			retVal.data[i] = data[i] + other.data[i];
		}
		return retVal;
	}
	int getLength()
	{
		return length;
	}
};

template<class T>
ostream& operator<<(ostream& output, Vector<T>& myVector){
	output << "[ ";
	for( int i = 0; i < myVector.getLength(); i++)
	{
		output << myVector[i] << " ";
	}
	output << "] ";
	return output;
}

int main()
{
	Vector<int> a(10);
	Vector<int> b(10);
	Vector<int> c;

	for(int i = 0; i < 10; i++){
		a[i] = i;
		b[i] = 2*i;
	}

	c = a + b;

	cout << "a     = " << a << endl;
	cout << "b     = " << b << endl;
	cout << "a + b = " << c << endl;
}
