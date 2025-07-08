#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& v, int k) {
	int n = v.size();
	unordered_map<int, int> preSumMap;
	int sum = 0, maxLen = 0;

	for(int i = 0; i < n; ++i) {
		//calculate the prefix sum till index i:
		sum += v[i];

		// if the sum = k, update the maxLen:
		if(sum == k) {
			maxLen = max(maxLen, i + 1);
		}

		// calculate the sum for remaining part i.e. x-k:
		int remain = sum - k;

		// check for subarray sum equals k
		if(preSumMap.find(remain) != preSumMap.end()) {
			int len = i - preSumMap[remain];
			maxLen = max(maxLen, len);
		}

		// update map with current sum
		if(preSumMap.find(sum) == preSumMap.end()) {
			preSumMap[sum] = i;
		}
	}

	return maxLen;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {2,3,5,1,9};
	int k = 10;
	cout << longestSubarrayWithSumK(v, k) << endl; // 3

	return 0;
}