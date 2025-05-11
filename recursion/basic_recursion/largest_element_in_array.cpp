#include<bits/stdc++.h>
using namespace std;

void largestElement(vector<int>& v, int& item, int n) {
	if(n == 0)
		return;

	if(v[n - 1] > item)
		item = v[n - 1];

	largestElement(v, item, n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int largest = INT_MIN;
	vector<int> v {1, 6, 3, 100, 8, 3, 9, 0, 2, 7, 5};
	int n = v.size();
	largestElement(v, largest, n);
	cout << largest << endl;

	
	return 0;
}