#include<bits/stdc++.h>
using namespace std;

// Euclidean Algorithm
int gcd(int a, int b) {
	while(a > 0 && b > 0) {
		if(a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}

	if(a == 0)
		return b;

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << gcd(20, 15) << endl; // 5

	// 20, 15 (a, b)
	// 20, 15 > 0
	// 20 > 15 so
	// a = 20 % 15 = 5
	// now a, b = 5, 15
	// 15 > 5 so
	// b = 15 % 5 = 0
	// a was alread 5
	// if b == 0 return a
		
	return 0;
}