#include<bits/stdc++.h>
using namespace std;
// Approch or solution: If in this directed graph there is cycle forming, then that node is not a safe node. 
// If there is not cycle for that `Source` node that means, it ends somewhere/terminal node. 

bool dfs(int source, vector<vector<int>>& g, vector<int>& visited, vector<int>& current_path) {
	// cout << source << " ";
	visited[source] = 1;
	current_path[source] = 1;

	for(auto& nbr: g[source]) {
		if(!visited[nbr]) {
			bool is_cycle = dfs(nbr, g, visited, current_path);
			if(is_cycle)
				return true;
			// you may exit - with base condition like if(cycle) return;
		} else {
			// if visited & in current path - it's a loop
			if(current_path[nbr] == 1) {
				return true;
			}
		}
	}

	current_path[source] = 0;
	return false;
}

vector<int> find_safe_nodes(int nodes, vector<vector<int>>& edges) {
	vector<int> safe_nodes;

	// make graph
	vector<vector<int>> g (nodes);
	for(auto& edge: edges) {
	// 	// directed graph
		g[edge[0]].push_back(edge[1]);
	}

	// apply dfs from each source to detect cycle
	vector<int> visited (nodes, 0), current_path (nodes, 0);

	for(int i = 0; i < nodes; ++i) {
		if(!visited[i]) {
			dfs(i, g, visited, current_path);
		}
	}

	// if node has never been in current path - we can get those nodes in safe_nodes;
	for(int i = 0; i < nodes; ++i) {
		if(current_path[i] == 0) {
			safe_nodes.push_back(i);
		}
	}

	return safe_nodes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph - 1
	vector<vector<int>> edges {
		{0, 1}, {0, 2}, {1, 3}, {1, 2}, {2, 5}, {3, 0}, {4, 5}
	};
	int nodes = 7;

	vector<int> safe_nodes = find_safe_nodes(nodes, edges);
	cout << "Safe nodes: ";
	for(auto& node: safe_nodes) {
		cout << node << " ";
	}
	cout << endl;

	// graph - 2
	edges = {
		{2, 1}, {1, 0}, {0, 3}, {3, 4}, {4, 1}
	};
	nodes = 5;
	safe_nodes = find_safe_nodes(nodes, edges);
	cout << "Safe nodes: ";
	for(auto& node: safe_nodes) {
		cout << node << " ";
	}
	cout << endl;


	return 0;
}