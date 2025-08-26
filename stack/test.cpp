#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> getPalTable(string& s) {
    int n = s.length();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    // Step 1: Precompute palindrome table
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len <= 2) isPal[i][j] = true;
                else isPal[i][j] = isPal[i+1][j-1];
            }
        }
    }

    return isPal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "aabbaac";
    vector<vector<bool>> dp = getPalTable(s);
    int n = s.length();

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(dp[i][j]) {
                cout << s.substr(i, j - i + 1) << endl;
            }
        }
    }


    return 0;
}