#include<bits/stdc++.h>
using namespace std;

// recursive solution - doesn't handle duplicates
void permutation(string ip, string op) {
	if(ip == "") {
		cout << op << endl;
		return;
	}

	int n = ip.length();

	for(int i = 0; i < n; ++i) {
		// sign of BT - number of choices large. For each item, we are making choice.

		// Important! - This temp strings ip1, and op1 are important as, 
		// you are erase and reading string at the same time. 
		string ip1 = ip.substr(0, i) + ip.substr(i + 1);
		string op1 = op + ip[i];

		permutation(ip1, op1);
	}
}

// recursive solution - with controlled recursion & branch cut
void permutationImproved(string ip, string op) {
	if(ip == "") {
		cout << op << endl;
		return;
	}

	int n = ip.size();
	set<char> included;

	for(int i = 0; i < n; ++i) {
		if(included.find(ip[i]) == included.end()) {
			included.insert(ip[i]);

			string ip1 = ip.substr(0, i) + ip.substr(i + 1);
			string op1 = op + ip[i];

			permutationImproved(ip1, op1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "aac";
	permutationImproved(s, "");

	return 0;
}