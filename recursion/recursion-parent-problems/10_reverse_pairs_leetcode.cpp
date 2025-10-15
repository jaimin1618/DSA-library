#include<bits/stdc++.h>
using namespace std;
// REAL DEAL HARD question on leetcode - explains how multiple concepts can be applied to solve 
// bigger problems. 

int count_left_item_bigger_than_right_items(vector<int>& A, int i, int j, int p, int q) {
	// 2,4,3,5,1
	// 2,3,4 | 1,5
	int inversion_count = 0;

	while(p <= q && i <= j) {
		if(A[i] > A[p] * 2) {
			inversion_count += j - i + 1;
			++p;
		} else {
			++i;
		}
	}

	return inversion_count;
}

void merge_sorted_vector(vector<int>& A, int start, int end, int& ans) {
	// two "sorted" A, B vector -> merge them as well counter inversions for them
	int mid = start + (end - start) / 2;

	// merge Array from start to mid, and mid + end
	int n = A.size();
	vector<int> merged (end - start + 1);

	// count inversion between sorted Arrays, as we can wait for merging sorted Arrays no issue
	ans += count_left_item_bigger_than_right_items(A, start, mid, mid + 1, end);

	// i goes from start to mid
	// j goes from mid + 1 to end
	// k goes from start to end
	int i = start, j = mid + 1, k = 0;
	while(k <= end && i <= mid && j <= end) {
		if(A[i] < A[j]) {
			merged[k] = A[i];
			++i;
		} else {
			merged[k] = A[j];
			++j;
		}
		++k;
	}

	while(i <= mid) {
		merged[k] = A[i];
		++i;
		++k;
	}

	while(j <= end) {
		merged[k] = A[j];
		++j;
		++k;
	}

	// append merged vector into A (main array)
	k = 0;
	for(int t = start; t <= end; ++t) {
		A[t] = merged[k];
		++k;
	}
}

void merge_sort(vector<int>& A, int start, int end, int& ans) {
	if(start < end) {
		int mid = start + (end - start) / 2;
		merge_sort(A, start, mid, ans);
		merge_sort(A, mid + 1, end, ans);
		merge_sorted_vector(A, start, end, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {9, 5, 4, 2};
	int ans = 0;
	merge_sort(v, 0, v.size() - 1, ans);

	cout << ans << endl;

	vector<int> t {1, 2, 3, 1, 3};
	cout << count_left_item_bigger_than_right_items(t, 0, 2, 3, 4) << endl;





	return 0;
}