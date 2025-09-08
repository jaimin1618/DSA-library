#include<bits/stdc++.h>
using namespace std;

void solve(string& s, int start, vector<string>& res) {
	if(start == s.length() - 1) {
		res.push_back(s);
		return;
	}

	set<char> swapped;

	for(int i = start; i < s.length(); ++i) {
		if(swapped.find(s[i]) == swapped.end()) {
			swap(s[i], s[start]);
			solve(s, i + 1, res);
			swap(s[i], s[start]);
		}		
	}
}

vector<string> find_permutation(string ip) {
	vector<string> v;

	int start = 0;
	solve(ip, start, v);

	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "abc";
	vector<string> res = find_permutation(s);
	for(auto& el: res)
		cout << el << " ";

	return 0;
}