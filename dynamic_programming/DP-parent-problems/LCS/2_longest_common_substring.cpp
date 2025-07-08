#include<bits/stdc++.h>
using namespace std;

int longest_common_substring_length(string x, string y, int n, int m) {
	int dp[n + 1][m + 1];
	int mx = INT_MIN;

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < m + 1; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if(x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			    mx = max(mx, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	}
	
	return mx;
}

int longest_common_substring(string a, string b, int n, int m, int& ans) {
	if(n == 0 || m == 0)
		return 0;
	if(a[n - 1] != b[m - 1])
		return 0;

	int tmp = 1 + longest_common_substring(a, b, n - 1, m - 1, ans);
	ans = max(tmp, ans);
	return tmp;
}

int main() {
	string x = "abcde";
	string y = "abfce";
	cout << "Longest common substring: ";
	cout << longest_common_substring_length(x, y, x.size(), y.size()) << '\n';

	int ans = 0;
	longest_common_substring(x, y, x.size(), y.size(), ans);
	cout << ans << endl;


	return 0;
}