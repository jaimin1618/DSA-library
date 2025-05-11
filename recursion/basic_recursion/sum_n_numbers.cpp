#include<bits/stdc++.h>
using namespace std;

int sumNumbers(int n) {
	if(n == 0)
		return 0;

	return n + sumNumbers(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int sum = sumNumbers(10); // 45
	cout << sum << endl;

	sum = sumNumbers(5); // 45
	cout << sum << endl;
	
	return 0;
}