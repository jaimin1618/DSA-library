#include<bits/stdc++.h>
using namespace std;
// Pattern: Level wise BFS traversal

// BFS - regular traversal
void bfs(vector<vector<int>>& graph) {
	int nodes = graph.size();
	queue<int> q;
	vector<bool> visited (nodes);

	q.push(0); // considering 0th node
	visited[0] = true;
	int size = 0;

	while(!q.empty()) {
		int item = q.front();
		q.pop();
		cout << item << " ";

		for(int& nbr: graph[item]) {
			if(!visited[nbr]) {
				visited[nbr] = true;
				q.push(nbr);
			}
		}
	}
}

// BFS - level by level traversal 
void bfs_level_traversal(vector<vector<int>>& graph) {
	int nodes = graph.size();
	queue<int> q;
	vector<bool> visited (nodes);

	q.push(0);
	visited[0] = true;
	int level = 0;

	while(!q.empty()) {
		int size = q.size();

		cout << "Level " << level << ": ";
		for(int i = 0; i < size; ++i) {
			int item = q.front();
			q.pop();

			// visit/process current node
			cout << item << " ";

			for(int& nbr: graph[item]) {
				if(!visited[nbr]) {
					visited[nbr] = true;
					q.push(nbr);
				}
			}
		}
		cout << endl;

		level++;
	}
}

vector<vector<int>> make_graph(vector<vector<int>>& edges, int nodes) {
	vector<vector<int>> g (nodes);

	for(auto& edge: edges) {
		int a = edge[0], b = edge[1];
		g[a].push_back(b);
		g[b].push_back(a);
	}

	return g;
}

class Solution {
public:
	vector<vector<int>> knightMoves {
		{-1, -2},
		{-1, 2},
		{1, -2},
		{1, 2},
		{-2, -1},
		{-2, 1},
		{2, -1},
		{2, 1}
	}; // knight movies

	bool isValidMove(int x, int y, int n) {
		if(x >= 0 && x < n && y >= 0 && y < n)
			return true;
		return false;
	}

	int solve(int sourceX, int sourceY, int destiX, int destiY, int n) {
		vector<vector<int>> visited (n, vector<int> (n)); // 8x8 visited matrix

		queue<pair<int, int>> q;
		q.push({sourceX, sourceY});
		visited[sourceX][sourceY] = 1;
		int level = 0;

		while(!q.empty()) {
			int size = q.size();

			for(int i = 0; i < size; ++i) {
				// visit the node
				pair<int, int> item = q.front();
				q.pop();

				if(item.first == destiX && item.second == destiY) {
					// answer
					return level;
				}

				for(auto& moves: knightMoves) {
					int x = item.first + moves[0], y = item.second + moves[1];

					// check if (x, y) is valid & is not visited
					if(isValidMove(x, y, n)) {
						visited[x][y] = 1;
						q.push({x, y});
					}
				}
			}

			level++;
		}
	}

	/**
	 * Function that moves from (sourceX, sourceY) to (destiX, destiY), n represents 8x8 chess board. 
	 */
	int minStepsToReachTarget(int sourceX, int sourceY, int destiX, int destiY, int n) {
		// update coordinates for converting chess board cell (x, y) to matrix -> X` = n - X, Y` = Y - 1
		return solve(n - sourceX, sourceY - 1, n - destiX, destiY - 1, n);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1 -- 0 -- 2
	//      | 
	//      3 -- 5
	//      |
	//      4
	vector<vector<int>> edges = {
		{0, 1}, {0, 2}, {0, 3}, {3, 4}, {3, 5}
	};
	int nodes = 6;
	vector<vector<int>> g = make_graph(edges, nodes);
	bfs_level_traversal(g);


	Solution s;
	int n = 8;
	int sourceX = 4, sourceY = 5;
	int destiX = 1, destiY = 1;
	cout << s.minStepsToReachTarget(sourceX, sourceY, destiX, destiY, n) << endl;

	return 0;
}