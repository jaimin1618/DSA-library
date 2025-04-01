#include<bits/stdc++.h>
using namespace std;

/*======================================
Important question of Sliding window, 
it is difficult question of sliding window and, 
you would be able to approach sliding window hard question if you have solved this once.

Question,
ip,
s = "timetopractice";
t = "toc";
all the letters of t must be present in substring (window) of s and in same quantity or more quantiy (but not less)
find minimum window length of all those substrings 
======================================*/

string minWindowSubstring(string& s, string& t) {
	unordered_map<char, int> mp;

	for(auto& el: t)
		mp[el]++;

	int count = mp.size();
	int i = 0, j = 0, n = s.length();
	int start = -1, mn = INT_MAX;

	while(j < n) {
		if(mp.find(s[j]) != mp.end()) {
			mp[s[j]]--;
			if(mp[s[j]] == 0)
				count--;
		}

		if(count == 0) {
			while(count == 0) {
				if(j - i + 1 < mn) {
					mn = j - i + 1;
					start = i;
				}

				if(mp.find(s[i]) != mp.end()) {
					mp[s[i]]++;
					if(mp[s[i]] > 0) 
						++count;
				}

				++i;
			}
		}

		++j;
	}

	if(start == -1)
		return "";

	return s.substr(start, mn);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "timetopractice";
	string t = "toc";
	cout << minWindowSubstring(s, t) << '\n'; // 

	s = "TOTMTAPTAT";
	t = "TTA";
	cout << minWindowSubstring(s, t) << '\n';

	s = "ADOBECODEBANC";
	t = "ABC";
	cout << minWindowSubstring(s, t) << endl;

	s = "a";
	t = "a";
	cout << minWindowSubstring(s, t) << endl;

	s = "a";
	t = "aa";
	cout << minWindowSubstring(s, t) << endl;


	
	return 0;
}