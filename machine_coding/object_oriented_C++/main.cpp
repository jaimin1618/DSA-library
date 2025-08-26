#include<bits/stdc++.h>
using namespace std;

class Car {
	string name;
public: 
	void setName(const string& n) { name = n; }
	string getName() const { return name; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Car a = Car();
	a.setName("Toyota");
	cout << a.getName() << endl;

	Car b = a; // Copy constructor is called
	a.setName("Honda"); // Changing 'a' does not affect 'b'
	cout << b.getName() << endl; // Should still print "Toyota"
	cout << a.getName() << endl; // Should print "Honda"
	

	Car *c = new Car(); // Using dynamic memory allocation
	c->setName("Ford");
	cout << c->getName() << endl; // Should print "Ford"

	Car *d = new Car(); // Copy constructor is called
	d = c; // Now 'd' points to the same object as 'c'
	c->setName("Chevrolet"); // Changing 'c' affects 'd' since they point to the same object
	cout << d->getName() << endl; // Should print "Chevrolet"
	cout << c->getName() << endl; // Should also print "Chevrolet"
	
	return 0;
}