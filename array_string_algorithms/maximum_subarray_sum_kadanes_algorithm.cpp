#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum_bruteforce(vector<int>& v) {
	int n = v.size();
	int mxSum = v[0];

	for(int i = 0; i < n; ++i) {
		int sum = 0;

		for(int j = i; j < n; ++j) {
			sum += v[j];
			mxSum = max(mxSum, sum);
		}
	}

	return mxSum;
}

// using Kadane's algorithm 
int maximumSubarraySum(vector<int>& v) {
	int n = v.size();
	int maxEnding = v[0];
	int maxSum = v[0];

	for(int i = 0; i < n; ++i) {
		maxEnding = max(maxEnding + v[i], v[i]);
		maxSum = max(maxSum, maxEnding);
	}

	return maxSum;
}

// Kandane's algorithm in other way
int maximumSubarraySummation(vector<int>& v) {
	int n = v.size();
	int sum = 0, maxSum = 0;

	for(int i = 0; i < n; ++i) {
		sum += v[i];
		if(v[i] > sum) sum = v[i];
		maxSum = max(maxSum, sum);
	}

	return maxSum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maximumSubarraySum_bruteforce(arr) << endl;
    cout << maximumSubarraySummation(arr) << endl;
	
	return 0;
}