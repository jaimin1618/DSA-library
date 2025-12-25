#include<bits/stdc++.h>
using namespace std;

// Designed / created cycle count algorithm for solving this.
// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// Another important thing to learn. 
// To connect all components of graph (V Vertices) you MUST HAVE V - 1 edges present in that graph 
// (in case you don't want to create new edges and only rearrange existing edges)
// And you can only rearrage edges of component that forms CYCLE --> 1 CYCLE can give you 1 EDGE for connecting components

void dfs(int source, int parent, vector<vector<int>>& g, vector<int>& visited, int& cycles) {
	visited[source] = 1;
	cout << source << endl;

	for(int& nbr: g[source]) {
		if(!visited[nbr]) {
			dfs(nbr, source, g, visited, cycles);
		} else {
			if(nbr != parent) {
				cout << "nbr: " << nbr << ", parent: " << parent << endl;
				cycles++;
			}
		}
	}
}

int count_cycles(int V, vector<vector<int>>& edges) {
	vector<vector<int>> g (V);

	for(auto& edge: edges) {
		// un-directed
		int u = edge[0], v = edge[1];
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int count_components = 0;
	int count_cycles = 0;
	vector<int> visited (V);

	for(int i = 0; i < V; ++i) {
		int source = i;

		if(!visited[source]) {
			dfs(source, -1, g, visited, count_cycles);
			count_components++;
		}
	}

	cout << "cycle count: "<< count_cycles << endl;
	cout << "component count: " << count_components << endl;
 
	return count_cycles;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int V;
	vector<vector<int>> edges;

	// graph - 1
	// 1 -- 0 -- 2  5 -- 6
	//      |            |
	//      3            7
	//      |
	//      4
	// V = 8;
	// edges = {
	// 	{0, 1}, {0, 2}, {0, 3}, {3, 4}, {5, 6}, {6, 7}
	// };
	// count_cycles(V, edges);

	// graph - 2
	// 0 -- 1 -- 2 -- 7 -- 8
	//      |         |    |
	//      3 -- 5    9 -- 10
	//      |    |
	//      4 -- 6
	// V = 11;
	// edges = {
	// 	{0, 1}, {1, 2}, {1, 3}, {3, 5}, {5, 6}, {6, 4}, {3, 4}, {2, 7}, {7, 8}, {8, 10}, {10, 9}, {9, 7}
	// };
	// count_cycles(V, edges);

	// graph - 3
	// 0 -- 1 -- 2 -- 7 -- 8
	//      |         |    |
	//      3 -- 5    9    10
	//      |    |
	//      4 -- 6
	V = 11;
	edges = {
		{0, 1}, {1, 2}, {1, 3}, {3, 5}, {5, 6}, {6, 4}, {3, 4}, {2, 7}, {7, 8}, {8, 10}, {9, 7}
	};
	count_cycles(V, edges);

	return 0;
}