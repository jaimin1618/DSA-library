#include<bits/stdc++.h>
using namespace std;

// Approach
// Now I understood why solve(v, n) - method which is not using ind not working
// on DP on stocks problems.
// Main concern is YOU have to BUY FIRST! before SELL 
// Run the base cases [], [1], [7], and you will understand the issue. 

// otherwise, approach is simple - if not bought, buy and then take sell decision.

int solve(vector<int>& v, int ind, int buy) {
	int n = v.size();

	if(ind == n)
		return 0;

	if(buy) {
		int buy = -v[ind] + solve(v, ind + 1, !buy);
		int notBuy = solve(v, ind + 1, buy); 
		// [], [1], [7] cases are handled because of this returning 0 against -7, -1
		// because of that, if you want to use (v, n) regular DP for these problems 
		// you will need to apply -ve sign when SELL and +ve when BUY
		return max(buy, notBuy);
	}

	int sell = v[ind] + solve(v, ind + 1, !buy);
	int notSell = solve(v, ind + 1, buy);
	return max(sell, notSell);
}

int maxProfit(vector<int>& prices) {
	return solve(prices, 0, 1);
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