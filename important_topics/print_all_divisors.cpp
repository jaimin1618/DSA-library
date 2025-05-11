#include<bits/stdc++.h>
using namespace std;

vector<int> getAllDivisors(int n) {
	vector<int> v;

	for(int i = 1; i <= sqrt(n); ++i) {
		if(n % i == 0) {
			v.push_back(i);

			if(n / i != i) {
				v.push_back(n / i);
			}
		}
	}

	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v = getAllDivisors(36);
	// 1, 2, 3, 4, 6, 9, 12, 18, 36
	for(auto& el: v)
		cout << el << ' ';

	
	return 0;
}