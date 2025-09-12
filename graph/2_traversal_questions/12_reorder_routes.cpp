#include<bits/stdc++.h>
using namespace std;
// Pattern: Directed/Un-directed graph mix. Forward and Backword edges for graph. 

void dfs(int source, vector<vector<int>>& forward_nbrs, vector<vector<int>>& backword_nbrs, vector<int>& visited, int& ans) {
	// visting current node
	visited[source] = 1;

	// forward neighbours direction needs to be changed
	for(int& nbr: forward_nbrs[source]) {
		if(!visited[nbr]) {
			ans++;
			dfs(nbr, forward_nbrs, backword_nbrs, visited, ans);
		}
	}

	for(int& nbr: backword_nbrs[source]) {
		if(!visited[nbr]) {
			dfs(nbr, forward_nbrs, backword_nbrs, visited, ans);
		}
	}
}

int min_reorder_routes(int nodes, vector<vector<int>>& edges) {
	vector<vector<int>> forward_nbrs (nodes), backword_nbrs (nodes);
	vector<int> visited (nodes);

	/**
	 * If there is A --> B is edge or connection
	 * in forward_nbrs we are keeping A --> B 
	 * in backword_nbrs we are keeping B --> A (Required to visit un-traversable nodes)
	 */

	for(auto& edge: edges) {
		int a = edge[0], b = edge[1];

		// !important
		forward_nbrs[a].push_back(b);
		backword_nbrs[b].push_back(a);
	}

	int ans = 0;
	int sourceNode = 0;
	dfs(sourceNode, forward_nbrs, backword_nbrs, visited, ans);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// Graph - with tree like structure (no cycles)
	// 2 --> 3 <-- 1 <-- 0 <-- 4 --> 5 
	int nodes = 6;
	vector<vector<int>> edges {
		{2, 3},
		{1, 3},
		{0, 1},
		{4, 0},
		{4, 5}
	}; // directed! 

	cout << min_reorder_routes(nodes, edges) << endl;

	return 0;
}