#include<bits/stdc++.h>
using namespace std;

// map based solution to handle negative numbers 
int solve(vector<int>& v, int target) {
	int n = v.size();
	int sum = 0;
	unordered_map<int, int> mp;
	int ans = 0;

	for(int i = 0; i < n; ++i) {
		sum += v[i];

		if(sum == target) {
			// i + 1 is window till current element
			ans = max(ans, i + 1);	
		}

		// 1,2,3, 4, 5 | k = 7
		// 1,3,6,10,15

		int remain = sum - target;
		if(mp.find(remain) != mp.end()) {
			int len = i - mp[remain];
			ans = max(ans, len);
		}

		if(mp.find(sum) == mp.end()) {
			mp[sum] = i;
		}
	}

	return ans;
}

/**
 * return the size of longest sub-array, 
 * whose element sum = K
 */
int longestSumarrayOfSum(vector<int>& v, int target) {
	const int n = v.size();
	int i = 0, j = 0;
	int mxLen = INT_MIN;
	int sum = 0;

	while(j < n) {
		sum += v[j];

		if(sum == target) {
			int windowSize = j - i + 1;
			mxLen = max(mxLen, windowSize);
			++j;
		} else if(sum < target) {
			++j;
		} else if(sum > target) {
			while(sum > target) {
				sum -= v[i];
				++i;
			}
			++j;
		}
	}

	return mxLen;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {4, 1, 1, 1, 2, 3, 5};
	int targetSum = 5;
	cout << longestSumarrayOfSum(v, targetSum) << '\n';
	cout << solve(v, targetSum) << '\n';

	v.assign({-5, 8, -14, 2, 4, 12});
	targetSum = -12; 
	cout << longestSumarrayOfSum(v, targetSum) << '\n'; // FAILs because algorithm didn't expect negative values
	cout << solve(v, targetSum) << '\n'; // FAILs because algorithm didn't expect negative values

	
	return 0;
}