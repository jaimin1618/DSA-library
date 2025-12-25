#include<bits/stdc++.h>
using namespace std;

// Approach:
// Keep track of minimum value before that day
// different between current - previous minimum element is profit

int maxProfit(vector<int>& prices) {
	int mx = 0;
	int n = prices.size();
	int mini = prices[0];

	for(int i = 1; i < n; ++i) {
		int profit = prices[i] - mini;
		mx = max(profit, mx);
		mini = min(mini, prices[i]);
	}

	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> t {7,1,5,3,6,4};
	cout << maxProfit(t) << endl; // 5

	t.assign({7,6,4,3,1});
	cout << maxProfit(t) << endl; // 0
	

	return 0;
}