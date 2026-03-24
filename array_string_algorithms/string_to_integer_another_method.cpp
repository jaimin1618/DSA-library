#include<bits/stdc++.h>
using namespace std;

// you know the simple method using k and pow(10, k) -> but that will not work in some cases
// when you need to check if digit is more than required - (crossing INT_MAX, INT_MIN)

int known_method(string s) {
	// REMEMBER or use this only - it is worth it and easy to understand. 
	int n = s.length();
	int k = 1;
	int num = 0;
	bool neg = false;

	for(int i = n - 1; i >= 0; --i) {
	    int digit = s[i] - '0';

	    long long temp = digit * k;

	    if(temp > INT_MAX || num + temp > INT_MAX) {
	    	// important part, you are going out of range 
	        return neg ? INT_MIN : INT_MAX;
	    }

	    num += temp;
	    k *= 10; // DO NOT USE pow(10, k) --> complications of converting double to integer
	}

	return num;
}

int another_method(string s) {
	int n = s.length();
	long long num = 0;
	bool neg = false;

	for(int i = 0; i < n; ++i) {
		int digit = s[i] - '0';

		if(num > (INT_MAX - digit) / 10) {
			// important - 
			return neg ? INT_MIN : INT_MAX;
		}

		num = num * 10 + digit;
	}

	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << known_method("123") << endl;
	cout << another_method("123") << endl;
	

	return 0;
}