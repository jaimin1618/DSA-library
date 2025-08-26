#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int v[] {1, 2, 3};
	for(auto& el: v)
		cout << el << " ";

	int a = 1;
	int b = 2;
	int c = 3;
	int *ip[] = {&a, &b, &c};
	for(auto& el: ip) {
		cout << *el << endl;
	}

	return 0;
}