#include<bits/stdc++.h>
using namespace std;

void swapSort(vector<int>& v) {
	int n = v.size();

	for(int i = 0; i < n; ++i) {
		while(v[i] != v[v[i] - 1]) {
			swap(v[i], v[v[i] - 1]);
		}
	}
}

tuple<int, int> swapSortSolution(vector<int>& v) { 
	const int n = v.size();
	swapSort(v); // apply swap sort on array
	tuple<int, int> ans; // duplicate, missing

	// find duplicates / missing after swap sort
	for(int i = 0; i < n; ++i) {
		if(v[i] != i + 1) {
			ans = make_tuple(v[i], i + 1);
			break;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// disclaimer: If given array is "const" / "read-only" array then you
	// cannot perform swap sort without new O(N) extra space
	// so, no point of doing this method if const vector<int>& v given

	// for that you will need to use bit manipulation or math or other solutions
	vector<int> v {2, 1, 2, 3, 5, 4, 7};
	 (v);
	for(auto& el: v)
		cout << el << ' ';
	cout << "\n";

	tuple<int, int> result = swapSortSolution(v);
	cout << "duplicate: " << get<0>(result) << ", missing: " << get<1>(result);
	 // << ", " << "missing: " << result<1> << endl;



	return 0;
}