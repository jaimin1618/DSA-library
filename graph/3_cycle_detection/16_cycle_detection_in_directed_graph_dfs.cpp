#include<bits/stdc++.h>
using namespace std;
// Apporach & concept of -- keep track of current part (or nodes in current path)
// backtrack from current path if no cycle found

void dfs(int source, vector<vector<int>>& g, vector<int>& visited, vector<int>& current_path, bool& ans) {
	// process current
	cout << source << " ";
	visited[source] = 1; // keep visited[source]=1 HERE ONLY!
	current_path[source] = 1; // add currently visiting node into current path

	for(auto& nbr: g[source]) {
		if(!visited[nbr]) {
			dfs(nbr, g, visited, current_path, ans);
		} else {
			// if visited and also in the current_path - it's a cycle
			if(current_path[nbr] == 1) {
				ans = true;
			}
		}
	}

	current_path[source] = 0; // backtrack 
}

bool cycle_in_directed_graph_dfs(int nodes, vector<vector<int>>& edges) {
	vector<vector<int>> g (nodes);

	for(auto& edge: edges) {
		// directed graph
		g[edge[0]].push_back(edge[1]);
	}

	vector<int> visited (nodes, 0);
	vector<int> current_path (nodes, 0); 
	// tracks current path - you may also use map/set. 
	// This is only for 0-(n - 1) nodes
	bool ans = false; // if cycle is there or not

	for(int i = 0; i < nodes; ++i) {
		if(!visited[i]) {
			dfs(i, g, visited, current_path, ans);
		}

		if(ans)
			break;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph - 1 (No cycle)
	// 0 --> 1
	// |     |
	// |     |
	// V     V
	// 3 <-- 2
	vector<vector<int>> edges {
		{0, 1}, {1, 2}, {2, 3}, {0, 3}
	};
	int nodes = 4;
	cout << "cycle: " << cycle_in_directed_graph_dfs(nodes, edges) << endl;

	// graph - 2 (cycle)
	// 0 --> 1
	// ^     |
	// |     |
	// |     V
	// 3 <-- 2
	edges = {
		{0, 1}, {1, 2}, {2, 3}, {3, 0}
	};
	nodes = 4;
	cout << "cycle: " << cycle_in_directed_graph_dfs(nodes, edges) << endl;


	return 0;
}