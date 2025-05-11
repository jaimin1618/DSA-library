#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
	if(n == 1)
		return 1;

	return n * factorial(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << factorial(3) << endl; // 6
	cout << factorial(5) << endl; // 120
	cout << factorial(10) << endl; // 36,28,800

	
	return 0;
}