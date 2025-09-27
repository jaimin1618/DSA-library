#include<bits/stdc++.h>
using namespace std;

// string to integer, double, float conversion methods
int stringToNumber(string s) {
	return stoi(s);
}

double stringToNumberImproved(string s) {
 // consider ss as std::cin to easily understand.
 // to get streaming number you first need to read it.
 // cin >> num;
 // just like that ss >> num; data is read. 
	stringstream ss(s);
	double num;
	ss >> num;
	return num;
}
// --- X ---

// get substring of string
// use s.substr(1, n - 2) for removing first & last character
// --- X ---

// lower & upper bound of element in an array - using STL
int getItemCount(vector<int>& v, int key) {
	// lower_bound(v.begin(), v.end(), key); -> returns pointer to first occurrence of element
	// upper_bound(v.begin(), v.end(), key); -> returns pointer to last occurrence of element
	vector<int>::iterator lb = lower_bound(v.begin(), v.end(), key);
	vector<int>::iterator ub = upper_bound(v.begin(), v.end(), key);
	return distance(lb, ub);
}

void getMinMaxValues() {
	vector<int> v {2, 5, 1, 4, 3};
	int nums[] {2, 5, 3, 1, 4};
	int n = 5;

	cout << *max_element(v.begin(), v.end()) << endl;
	cout << *min_element(v.begin(), v.end()) << endl;
	cout << *max_element(nums, nums + n) << endl;
	cout << *min_element(nums, nums + n) << endl;
	cout << max({10, 20, 50}) << endl;
	cout << min({10, 20, 50}) << endl;
}

void printDoubleWithKPrecision() {
	// let's say your answer is double ans = 0.3;
	// but problem statement added to print answer till 9 decimal points
	// we use fixed and setprecision(9) for that. 
	double ans = 0.3;
	cout << fixed << setprecision(9);
	cout << ans << endl;


    // Print double with fixed precision (e.g., 9 decimal places)
    cout << fixed << setprecision(9) << ans << endl; // Output: 0.300000000

    // Align text using setw, left/right alignment
    cout << setw(10) << left << "Name" << setw(10) << right << 123 << endl;

    // Fill empty spaces with custom character
    cout << setfill('-') << setw(15) << "Test" << endl;

    string s = "123";

	// Convert string → integer
	int num = stoi(s);

	// Convert integer → string
	string s2 = to_string(num);

	// Convert to uppercase
	string str = "hello";
	transform(str.begin(), str.end(), str.begin(), ::toupper); // "HELLO"
	cout << str << endl;

	// Remove all spaces from string
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	cout << str << endl;

	cout << __gcd(12, 18) << endl;  // Greatest Common Divisor → 6
	
}

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

	vector<int> v {2, 3, 10, 10, 10, 20, 30};
	// cout << "occurrences: " 
	cout << getItemCount(v, 10) << endl;

	getMinMaxValues();

	printDoubleWithKPrecision();
	
	return 0;
}