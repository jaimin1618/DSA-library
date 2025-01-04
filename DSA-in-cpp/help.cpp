#include<bits/stdc++.h>
using namespace std;

// string to integer, double, float conversion methods
int stringToNumber(string s) {
	return stoi(s);
}

double stringToNumberImproved(string s) {
	stringstream ss(s);
	double num;
	ss >> num;
	return num;
}
// --- X ---

// get substring of string
// use s.substr(1, n - 2) for removing first & last character


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// stringToNumber
	cout << stringToNumber("100") + 10 << '\n';
	cout << stringToNumberImproved("100.5") + 10 << '\n';

	cout << ('9'-'0') + 10 << endl;

	string s = "jaimin";
	cout << s.substr(1, 4) << endl;

	string k = "()";
	cout << k.substr(1, 0) << endl;
	
	return 0;
}