#include<bits/stdc++.h>
using namespace std;

class Car {
    string name;
public:
    void setName(const string& n) { name = n; }
    string getName() { return name; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    Car a;
    a.setName("BMW");
    cout << a.getName() << endl; 

    const Car b = a; // b is a constant object of Car   
    // b.setName("Audi"); // This line would cause a compilation error because b is const => which means variable b will not change object values. 
    // Still string getName() { return name; } should work because it does not modify the object.
    // And for that we need to make getName() const function.

    // update the getName function to be const like this => string getName() const { return name; }

	
	return 0;
}