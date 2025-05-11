#include<bits/stdc++.h>
using namespace std;

void print1ToN(int n) {
	if(n == 0)
		return;

	print1ToN(n - 1);
	cout << n << ' ';
}

void printNTo1(int n) {
	if(n == 0)
		return;

	cout << n << ' ';
	printNTo1(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	print1ToN(10);
	cout << endl;
	printNTo1(10);



	
	return 0;
}