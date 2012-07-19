#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	virtual string speak() { return "I am a boring generic animal.";}
	virtual ~Animal(){}
};

class Human {
public:
	virtual string wereSpeak() { return "I am a were something!";}
	virtual ~Human(){}
};

class Beaver : public Animal, public Human {
public:
	string speak() { return  "I eat wood!!!"; }
	string wereSpeak() {return "I'm changing into a beavARRRRRRR!";}
};

class Marmot : public Animal, public Human {
public:
	string speak() { return "Obviously you are not a golfer!";}
	string wereSpeak() { return "There's a beverage here!";}
};

class AnotherAnimal : public Animal {
};
void whatDidYouSay(Animal *myAnimal)
{
	cout << myAnimal->speak() << endl;
}

void wereDidYouSay(Human *myHuman)
{
	cout << myHuman->wereSpeak() << endl;
}
int main()
{
	Beaver myBeaver;
	Marmot myMarmot;
	AnotherAnimal myGenericAnimal;

	whatDidYouSay(&myBeaver);
	whatDidYouSay(&myMarmot);
	whatDidYouSay(&myGenericAnimal);
	wereDidYouSay(&myBeaver);
	wereDidYouSay(&myMarmot);
	return 0;
}
