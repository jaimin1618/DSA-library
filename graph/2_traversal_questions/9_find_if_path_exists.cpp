#include<bits/stdc++.h>
using namespace std;
// Pattern: Simple DFS / BFS traversal

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int source) {
	visited[source] = true;

	for(int& nbr: graph[source]) {
		if(!visited[nbr]) {
			dfs(graph, visited, nbr);
		}
	}
}

bool path_exists(vector<vector<int>>& graph, int source, int destination) {
	// try to traverse graph from source node and lastly check if destination is visited or not. 
	int nodes = graph.size();
	vector<bool> visited (nodes, false);

	// dfs
	dfs(graph, visited, source);

	// finally chec if destination is visited or not
	return visited[destination];
}

vector<vector<int>> make_graph(vector<vector<int>>& edges, int nodes) {
	int n = edges.size(); // number of nodes
	vector<vector<int>> graph(nodes); // considering 0 to n - 1 nodes

	for(int i = 0; i < n; ++i) {
		int a = edges[i][0], b = edges[i][1];
		// un-directed
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	return graph;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int source = 0, destination = 4;
	vector<vector<int>> g;

	// graph-1
	//  1 -- 0 -- 5
	// 		 |
	//  3 -- 2
	//  |
	// 	4
	vector<vector<int>> edges {
		{0, 1}, {0, 5}, {0, 2}, {2, 3}, {3, 4}
	};
	int nodes = 6;
	g = make_graph(edges, nodes);
	cout << "path exists: " << path_exists(g, source, destination) <<  endl;


	// graph-2
	//  1 -- 0 -- 5
	// 
	//  3 -- 2
	//  |
	// 	4 (disconnected component of graph)
	edges.assign({
		{0, 1}, {0, 5}, {2, 3}, {3, 4}
	});
	g = make_graph(edges, nodes);
	cout << "path exists: " << path_exists(g, source, destination) <<  endl;

	return 0;
}