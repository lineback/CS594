#include <iostream>
#include <cmath>
using namespace std;

struct Complex
{
	float re, im;
	Complex(){}
	Complex( float r, float i ) : re(r), im(i) {}
	Complex operator+ (const Complex& other) {
		return Complex(re+other.re, im + other.im);
	}
	Complex operator* (const Complex& other) {
		return Complex(re*other.re - im*other.im, im*other.re + re*other.im);
	}
	bool operator < (const Complex& other) const{
		return sqrt(re*re+im*im) < sqrt(other.re*other.re + other.im*other.im);
	}
	bool operator > (const Complex& other) const{
		return sqrt(re*re+im*im) > sqrt(other.re*other.re + other.im*other.im);
	}
	
};
ostream& operator<<(ostream& output, Complex& myComplex){
	output << myComplex.re  << " + " << myComplex.im <<"i ";
	return output;
}

int main(){
	Complex 
		a(1.0, 0), 
		b(0.0, 1.0), 
		c, 
		d;
	   
	c = (a + b);
	d = (b * c);

	cout << "a = " << a << endl 
		 << "b = " << b << endl
		 << "a + b = " << c << endl
		 << "a * c = " << d << endl
		 << "a < c = " << (a < c) << endl;
	
	return 0;
}
