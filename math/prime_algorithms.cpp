#include<bits/stdc++.h>
using namespace std;

// sieve's algorithm to check if number if prime or not. 
// Complexity
// Time complexity: (O(n \log \log n)) — optimized for checking primes.
// Space complexity: (O(n)) — storing the sieve array.


// count primes strictly less than num.
int countPrimes(int num) {
	vector<int> primes (num, 1);
	primes[0] = primes[1] = 0;

	int i = 2;

	while(i * i < num) {
		if(primes[i]) {
			for(int j = i * i; j < num; j += i) {
				primes[j] = 0;
			}
		}

		++i;
	}

	int sum = 0;

	for(auto& el: primes)
		sum += el;

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num = 10;
	cout << countPrimes(num) << endl;

	return 0;
}