#include<bits/stdc++.h>
using namespace std;

void place_element(vector<int>& v, int k, vector<bool>& visited, int element, int index) {
	if(!visited[index]) {
		visited[index] = true;

		int nextIndex = (index + k) % n;
		int el = v[nextIndex];

		v[nextIndex] = v[index];
		place_element(v, k, nextIndex);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	vector<int> v {1,2,3,4,5,6,7};
				//{1,2,3,1,5,6,7};
	int n = v.size();
	vector<bool> visited(n, false);
	place_element(v, 3, 0);
	// 0, 3, 6, 2, 5, 1, 4, 0

	// 1, 2, 3, 4, 5 | k = 3
	// 5, 4, 3, 2, 1 
	// 3, 4, 5, 2, 1
	// 3, 4, 5, 1, 2 => 3, 4, 5, 1, 2


	
	return 0;
}