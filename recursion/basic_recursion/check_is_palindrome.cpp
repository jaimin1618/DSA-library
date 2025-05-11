#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s, int begin, int end) {
	if(begin <= end) {
		if(s[begin] != s[end])
			return false;
		palindrome(s, begin + 1, end - 1);
	}

	return true;
}

bool palindrome(string s, int index) {
	if(index >= s.length() / 2)
		return true;

	if(s[index] != s[s.length() - index - 1])
		return false;

	return palindrome(s, index + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "ABACABA";
	int begin = 0, end = s.length() - 1;
	cout << palindrome(s, begin, end) << endl;

	s = "ABACAB";
	begin = 0, end = s.length() - 1;
	cout << palindrome(s, begin, end) << endl;

	s = "ABACABA";
	cout << palindrome(s, 0) << endl;

	
	return 0;
}