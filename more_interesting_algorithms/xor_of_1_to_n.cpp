#include<bits/stdc++.h>
using namespace std;

// document: https://www.geeksforgeeks.org/calculate-xor-1-n/
int computeXOR(int n){
	// If n is a multiple of 4
	if (n % 4 == 0)
		return n;

	// If n%4 gives remainder 1
	if (n % 4 == 1)
		return 1;

	// If n%4 gives remainder 2
	if (n % 4 == 2)
		return n + 1;

	// If n%4 gives remainder 3
	if(n % 4 == 3)
		return 0;
}

// ANOTHER property of XOR is => x ^ 0 = x & x ^ x = 0
// in other words XOR of x with itself always result in 0

// Q: https://www.geeksforgeeks.org/find-xor-of-numbers-from-the-range-l-r/
int getRangeXOR(int l, int r) {
	return computeXOR(r) ^ computeXOR(l - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x = 5;
	cout << (x ^ x) << endl;
	cout << (x ^ 0) << endl;
	cout << getRangeXOR(3, 5) << endl;


	return 0;
}