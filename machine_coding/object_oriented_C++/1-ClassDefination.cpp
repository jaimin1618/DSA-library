#include<bits/stdc++.h>
using namespace std;

// keep implementation outside of the class -- best practice;
// Further more - Class declaration line 8 to 13 in Car.h, Class defination line 16 to 22 in Car.cpp and finally you will have main.cpp file to run all these

// Class declaration	
class Car {
	string name;
public:
	void setName(string n);
	string getName();
};

// Class defination
void Car::setName(string n) {
	this->name = n;
}

string Car::getName() {
	return this->name;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Car *c = new Car();
	c->setName("BMW");
	cout << c->getName() << endl;

	return 0;
}