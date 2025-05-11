#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
	if(n == 1 || n == 2)
		return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci_iter(int n) {
	int fb[n + 1];
	fb[0] = 0;
	fb[1] = 1;
	fb[2] = 1;

	for(int i = 2; i <= n; ++i) {
		fb[i] = fb[i - 1] + fb[i - 2];
	}

	return fb[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1, 1, 2, 3, 5, 8, 13...
	for(int i = 1; i <= 10; ++i)
		cout << fibonacci(i) << endl;

	cout << fibonacci_iter(10) << endl;
	return 0;
}