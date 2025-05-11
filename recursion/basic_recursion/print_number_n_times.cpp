#include<bits/stdc++.h>
using namespace std;

void printNTimes(int num, int n) {
	if(n == 0)
		return;

	cout << num << endl;
	printNTimes(num, n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	printNTimes(100, 5);

	
	return 0;
}