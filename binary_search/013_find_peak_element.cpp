#include<bits/stdc++.h>
using namespace std;

int peak_element(vector<int>& v) {
	// I will try to explain it more simply. 
	// What we are essentially doing is going in the direction of the rising slope (by choosing the element which is greater than current). 
	// How does that guarantee the result? Think about it, there are 2 possibilities. 
	// a) rising slope has to keep rising till end of the array 
	// b) rising slope will encounter a lesser element and go down.
	// In both scenarios, we will have an answer. 
	// In,
	// a) the answer is the end element because we take the boundary as -INFINITY 
	// b) the answer is the largest element before the slope falls. Hope this makes things clearer

	/**
	 * - Find and return index of Peak Element
	 * - What is Peak element, Peak element means element that is greater than both of its neighbours
	 * - there can be multiple peak elements, return any
	 * - last elements are considered peak element if they are greater than their one neighbour
	 */
	
	int n = v.size();
	int i = 0, j = n - 1, mid;

	while(i <= j) {
		mid = i + (j - i) / 2;

		if(mid > 0 && mid < n - 1) {
			if(v[mid] > v[mid - 1] && v[mid] > v[mid + 1]) {
				return mid;
			} else if(v[mid + 1] > v[mid]) {
				i = mid + 1;
			} else if(v[mid - 1] > v[mid]) {
				j = mid - 1; 
			}
		} else if(mid == 0) {
			if(v[mid] > v[mid + 1]) {
				return mid;
			} else {
				return mid + 1;
			}
		} else if(mid == n - 1) {
			if(v[mid] > v[mid - 1]) {
				return mid;
			} else {
				return mid - 1;
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 2, 100, 20, 5, 10, 20, 15}; // unsorted element 
	cout << peak_element(v) << endl;

	return 0;
}