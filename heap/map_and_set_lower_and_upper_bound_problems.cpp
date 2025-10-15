#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// works for map, set, multiset as they store data in ordered manner
	// std::map<Key,T,Compare,Allocator>::lower_bound
	// Returns an iterator pointing to the first element that is not less than key.
	// Returns an iterator pointing to the first element that compares not less than x.
	map<int, int> m;
	m[1] = 1;
	m[2] = 2;
	m[4] = 4;
	m[5] = 5;

	auto it = m.lower_bound(1);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl;

	it = m.lower_bound(3);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl;

	it = m.lower_bound(5);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl;

	it = m.lower_bound(6);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl; // although it gives ans, it's the WRONG answer. 
	// YOU MUST CHECK for m.end() for lower bounds and m.begin() when using upper bounds 

	cout << "\n\n";

	// std::map<Key,T,Compare,Allocator>::upper_bound
	// Returns an iterator pointing to the first element that is greater than key.
	// Returns an iterator pointing to the first element that compares greater than x.
	m.clear();

	m[1] = 1;
	m[2] = 2;
	m[4] = 4;
	m[5] = 5;

	it = m.upper_bound(1);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl;

	it = m.upper_bound(3);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl;

	it = m.upper_bound(5);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl;

	it = m.upper_bound(-1);
	cout << it->first << " - " << (it == m.end()) << " - " << (it == m.begin()) << endl; // although it gives ans, it's the WRONG answer. 

	return 0;
}