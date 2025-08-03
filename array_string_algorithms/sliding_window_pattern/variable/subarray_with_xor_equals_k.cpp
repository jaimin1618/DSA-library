#include<bits/stdc++.h>
using namespace std;

// theory
// v: {4, 2, 2, 6, 4}
// for above vector v, => (XOR of items from 0, i) XOR (XOR of items from i + 1 to n - 1) = (XOR of items from 0 to n - 1)
// always remember that.

int subarrayXORCount(vector<int>& v, int k) {
	// we will utilise hashmap based sliding window if check if xor with provided count occured previously
	int n = v.size();
	unordered_map<int, int> mp;
	int prefixXOR = 0;
	int count = 0;

	for(int i = 0; i < n; ++i) {
		prefixXOR ^= v[i];

		count += mp[prefixXOR ^ k];

		if(prefixXOR == k)
			count++;

		mp[prefixXOR]++;
	}

	return count;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> test {4, 2, 2, 6, 4};
	int k = 6;
	cout << subarrayXORCount(test, k) << endl; // expected: 4

	test.assign({5, 6, 7, 8, 9});
	k = 5;
	cout << subarrayXORCount(test, k) << endl; // expected: 2

	return 0;
}