#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> t {4, 5, 5, 5, 7, 8, 9};
    cout << lower_bound(t.begin(), t.end(), 5) - t.begin() << endl; // checks for item (position) <= 5
    cout << upper_bound(t.begin(), t.end(), 5) - t.begin() << endl; // checks for > 5

    // Detailed confirmation and explanation on how lower_bound and upper_bound works.

    // lower_bound(begin, end, x)
    // → Returns the first position where x can be inserted without violating order.
    // → Effectively: first index where value >= x.

    // upper_bound(begin, end, x);
    // → Returns the first position where a value greater than x appears.
    // → Effectively: first index where value > x.

    // UTILITIES of lower bound and upper bound - 
    int firstPos = lower_bound(t.begin(), t.end(), 6) - t.begin();
    cout << firstPos << endl;
    // first index where value >= 5

    int afterLast = upper_bound(t.begin(), t.end(), 6) - t.begin();
    cout << afterLast << endl;
	// first index where value > 5

	int L = lower_bound(t.begin(), t.end(), 5) - t.begin();
	int R = upper_bound(t.begin(), t.end(), 5) - t.begin();
	int count = R - L;   // number of occurrences of 5

	// Get full range of item
	auto range = equal_range(t.begin(), t.end(), 5);
	L = range.first  - t.begin();  // first index of >= 5
	R = range.second - t.begin();  // first index of > 5
	count = R - L;

	return 0;
}