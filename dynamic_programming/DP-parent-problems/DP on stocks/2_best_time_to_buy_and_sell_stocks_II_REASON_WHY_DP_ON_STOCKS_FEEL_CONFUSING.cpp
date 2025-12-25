#include<bits/stdc++.h>
using namespace std;

// Approach
// Now I understood why solve(v, n) - method which is not using ind not working
// on DP on stocks problems.
// Main concern is YOU have to BUY FIRST! before SELL 
// Run the base cases [], [1], [7], and you will understand the issue. 

// otherwise, approach is simple - if not bought, buy and then take sell decision.

int solve(vector<int>& v, int n, int sold) {
	if(n == 0)
		return 0;

	if(!sold) {
		int sell = v[n - 1] + solve(v, n - 1, !sold);
		int notSell = solve(v, n - 1, sold);
		return max(sell, notSell);
	}

	int buy = solve(v, n - 1, sold) - v[n - 1];
	int notBuy = solve(v, n - 1, !sold);
	return max(buy, notBuy);
}

int maxProfit(vector<int>& prices) {
	int n = prices.size();
    return solve(prices, n, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> t {7};
	cout << maxProfit(t) << endl;

	t.assign({1});
	cout << maxProfit(t) << endl;


	return 0;
}