class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int dp[100001][2][3];
        // memset(dp, -1, sizeof(dp));
        // return solve(prices, 0, 0, 2, dp);
        return iterative_space_optimized(prices);
    }

    int iterative_space_optimized(vector<int>& v) {
        // if you see prev and curr are depending on ind + 1, and ind + 2 
        // or something like that - you can space optimize your solution
        // removing entire dp matrix column

        vector<vector<int>> curr (2, vector<int> (3, 0));
        vector<vector<int>> after (2, vector<int> (3, 0));
        int n = v.size();

        // iterative code - just reverse the recurisve inputs
        for (int ind = n - 1; ind >= 0; --ind) {
            for (int bought = 1; bought >= 0; --bought) {
                for (int tx = 1; tx <= 2; ++tx) {
                    // tx = 0 is already computed in base case
                    if (!bought) {
                        int buy = -v[ind] + after[!bought][tx];
                        int notBuy = after[bought][tx];
                        curr[bought][tx] = max(buy, notBuy);
                    } else {
                        int sell = v[ind] + after[!bought][tx - 1];
                        int notSell = after[bought][tx];
                        curr[bought][tx] = max(sell, notSell);
                    }
                }
            }

            after = curr;
        }

        // how did we end up 0, 0, 2 in dp table.
        // check where your index (loop indexes) are ending up.
        // for n: n - 1 to 0 hence 0
        // for bought: 1 to 0 hence 0
        // for tx: 1 to 2 hence 2
        // understood😁�
        return after[0][2];
    }

    int iterative(vector<int>& v) {
        int dp[100001][2][3];
        memset(dp, 0, sizeof(dp));
        int n = v.size();

        // base cases tx = 0
        for (int ind = 0; ind < n + 1; ++ind) {
            for (int bought = 0; bought <= 1; ++bought) {
                dp[ind][bought][0] = 0;
            }
        }

        // base case ind == n
        for (int bought = 0; bought <= 1; ++bought) {
            for (int tx = 0; tx <= 2; ++tx) {
                dp[n][bought][tx] = 0;
            }
        }

        // iterative code - just reverse the recurisve inputs
        for (int ind = n - 1; ind >= 0; --ind) {
            for (int bought = 1; bought >= 0; --bought) {
                for (int tx = 1; tx <= 2; ++tx) {
                    // tx = 0 is already computed in base case
                    if (!bought) {
                        int buy = -v[ind] + dp[ind + 1][!bought][tx];
                        int notBuy = dp[ind + 1][bought][tx];
                        dp[ind][bought][tx] = max(buy, notBuy);
                    } else {
                        int sell = v[ind] + dp[ind + 1][!bought][tx - 1];
                        int notSell = dp[ind + 1][bought][tx];
                        dp[ind][bought][tx] = max(sell, notSell);
                    }
                }
            }
        }

        // how did we end up 0, 0, 2 in dp table.
        // check where your index (loop indexes) are ending up.
        // for n: n - 1 to 0 hence 0
        // for bought: 1 to 0 hence 0
        // for tx: 1 to 2 hence 2
        // understood😁�
        return dp[0][0][2];
    }

    int solve(vector<int>& v, int ind, int bought, int tx,
              int dp[100001][2][3]) {
        int n = v.size();
        if (ind == n || tx == 0)
            return dp[ind][bought][tx] = 0;
        if (dp[ind][bought][tx] != -1)
            return dp[ind][bought][tx];

        if (!bought) {
            int buy = -v[ind] + solve(v, ind + 1, !bought, tx, dp);
            int notBuy = solve(v, ind + 1, bought, tx, dp);
            return dp[ind][bought][tx] = max(buy, notBuy);
        }

        int sell = v[ind] + solve(v, ind + 1, !bought, tx - 1, dp);
        int notSell = solve(v, ind + 1, bought, tx, dp);
        return dp[ind][bought][tx] = max(sell, notSell);
    }
};