#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& stalls, int minDistance, int cows) {
	int n = stalls.size();
	int cnt = 1;
	int prev = stalls[0];

	// 0, 3, 4, 7, 9, 10
	for(int i = 1; i < n; ++i) {
		int dis = stalls[i] - prev;

		if(dis >= minDistance) {
			cnt++;
			prev = stalls[i];
		}
	}

	return cnt >= cows;
}

int aggresive_cows(vector<int>& stalls, int cows) {
	int n = stalls.size();

	// sort the stalls -
	sort(stalls.begin(), stalls.end());

	// get min distance and maximum distance between two stalls 
	int low = 1, high = max(stalls.begin(), stalls.end()) - min(stalls.begin(), stalls.end());
	for(int i = 1; i < n; ++i) {
		int dis = stalls[i] - stalls[i - 1];
		low = min(dis, low);
		high = max(dis, high);
	}

	int ans = INT_MAX;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		bool check = isValid(stalls, mid, cows);

		if(check) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> stalls {4, 2, 1, 3, 6};
	int cows = 2;
	cout << aggresive_cows(stalls, cows) << endl;

	return 0;
}