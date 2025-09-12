#include<bits/stdc++.h>
using namespace std;

// print - 
void print_graph(unordered_map<int, vector<int>>& graph) {
	for(auto& nbr: graph) {
		cout << "Node: " << nbr.first << ", Neighbors: ";
		for(auto& neighbor: nbr.second) {
			cout << neighbor << " ";
		}
		cout << endl;
	}
}

// DFS - recursive algorithm
void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int node) {
	// No BC because it is already handled inside loop - if(!visited[node]) <-- BC

	// seems like pre-order traversal
	cout << node << " "; // pre-order
	visited[node] = true;

	for(int& nbr: graph[node]) {
		if(!visited[nbr]) {
			dfs(graph, visited, nbr);
		}
	}
	
	// post-order if processed here! 
	// cout << node << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph with 0 nbr
	//  1 -- 0 -- 5
	// 		 |
	//  3 -- 2
	//  |
	// 	4

	vector<vector<int>> edges {
		{0, 1}, {0, 5}, {0, 2}, {2, 3}, {3, 4}
	};

	int n = 6;
	unordered_map<int, vector<int>> graph;
	vector<bool> visited(n);

	for(int i = 0; i < edges.size(); ++i) {
		int a = edges[i][0], b = edges[i][1];
		// un-directed
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	print_graph(graph);

	cout << "DFS traversal: ";
	dfs(graph, visited, 0);
	cout << "\n\n";

	// another graph
	//  1 -- 0 -- 4 
	//  |
	//  2 -- 3
	//  |
	//  5
	edges.assign({
		{0, 4}, {0, 1}, {1, 2}, {2, 3}, {2, 5}
	});
	n = 6;
	graph.clear();
	visited.clear();
	visited = vector<bool>(n);

	for(int i = 0; i < edges.size(); ++i) {
		int a = edges[i][0], b = edges[i][1];
		// un-directed
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	print_graph(graph);

	cout << "DFS traversal: ";
	dfs(graph, visited, 0);
	cout << "\n\n";

	return 0;
}