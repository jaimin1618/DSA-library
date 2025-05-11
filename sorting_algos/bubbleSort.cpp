#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> & v) {
	int n = v.size();

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(v[j] < v[i]) {
				swap(v[i], v[j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {5, 1, 3, 4, 2};
	bubbleSort(v);

	for(auto& el: v)
		cout << el << ' ';
	
	return 0;
}