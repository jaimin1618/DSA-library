#include<bits/stdc++.h>
using namespace std;

// problem link: https://leetcode.com/problems/path-with-minimum-effort/description/
// problem link: https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

int minimumEffortPath(vector<vector<int>>& heights) {
	vector<vector<int>> moves {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	int n = heights.size(), m = heights[0].size();
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // minH
	vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

	pq.push({0, 0, 0});
	dist[0][0] = 0;

	while(!pq.empty()) {
		auto front = pq.top();
		pq.pop();

		int dist_of_parent = front[0], x = front[1], y = front[2];

		for(auto& move: moves) {
			int nx = x + move[0], ny = y + move[1];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			int effort = abs(heights[x][y] - heights[nx][ny]);
			int new_dist_of_nbr = max(dist_of_parent, effort); // ~ equivalent to parent_dist + wt

			if(new_dist_of_nbr < dist[nx][ny]) {
				dist[nx][ny] = new_dist_of_nbr;
				pq.push({dist[nx][ny], nx, ny});
			}
		}
	}

	return dist[n - 1][m - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> heights {
		{1, 2, 2},
		{3, 8, 2},
		{5, 3, 5}
	};

	// move from top-left to bottom-right node
	cout << minimumEffortPath(heights) << endl;
		

	return 0;
}