#include <iostream>
#include <vector>
using namespace std;

struct primeGenerator {
private:
	vector<int> primes;
	bool isPrime(int num){
		for(int i = 0; i < primes.size(); i++){
			if(num%primes[i] == 0) {return false;}
		}
		return true;
	}
public:
	primeGenerator() {}
	int operator() () {
		if (primes.size() == 0){
			primes.push_back(2);
			return 2;
		}
		int candPrime = primes.back() + 1;
		while(!isPrime(candPrime)){
			candPrime++;
		}
		primes.push_back(candPrime);
		return (candPrime);
	}
};

int main(){
	primeGenerator pg;
	for(int i = 0; i < 10; i++){
		cout << pg() << endl;
	}
	return 0;
}
