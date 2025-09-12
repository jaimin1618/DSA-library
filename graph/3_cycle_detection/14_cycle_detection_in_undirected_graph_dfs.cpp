#include<bits/stdc++.h>
using namespace std;
// Pattern: Cycle detection in un-directed graphs is simple, 
// Just use BFS/DFS and visited[] and you will be able to detect cycles in un-directed graphs. 
// For un-directed graphs cycle detection is 
// "If you visit node that is not a PARENT node, 
// and it has been already visited that node previously and it's a cycle."

bool dfs(int& source, int& parent, vector<vector<int>>& g, vector<int>& visited) {
	visited[source] = 1;

	// process current node - just to check if it continues after loop if we add BC 
	cout << source << " ";

	for(int& nbr: g[source]) {
		if(!visited[nbr]) {
			return dfs(nbr, source, g, visited);
		} else {
			// condition to be added for checking loop - if node is visited & it's not parent node
			if(nbr != parent) {
				// you may also add BC - on start to check if loop is encountered or not. 
				return true;
			}
		}
	}

	return false;
}

bool cycle_exists_dfs(int nodes, vector<vector<int>>& edges) {
	vector<vector<int>> g (nodes);

	for(auto& edge: edges) {
		// un-directed
		g[edge[0]].push_back(edge[1]);
		g[edge[1]].push_back(edge[0]);
	}

	bool loop = false;
	vector<int> visited (nodes);

	for(int i = 0; i < nodes; ++i) {
		int source = i;

		if(!visited[source]) {
			int parent = -1;
			loop = dfs(source, parent, g, visited);	
		}

		if(loop)
			break;
	}

	return loop;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph - 1
	// 1 -- 0 -- 2  5 -- 6
	//      |            |
	//      3            7
	//      |
	//      4
	int nodes = 8;
	vector<vector<int>> edges = {
		{0, 1}, {0, 2}, {0, 3}, {3, 4}, {5, 6}, {6, 7}
	};
	cout << "Cycle exists: " << cycle_exists_dfs(nodes, edges) << endl;

	// graph - 2
	// 0 -- 1 -- 2 -- 7 -- 8
	//      |         |    |
	//      3 -- 5    9 -- 10
	//      |    |
	//      4 -- 6
	nodes = 11;
	edges = {
		{0, 1}, {1, 2}, {1, 3}, {3, 5}, {5, 6}, {6, 4}, {3, 4}, {2, 7}, {7, 8}, {8, 10}, {10, 9}, {9, 7}
	};
	cout << "Cycle exists: " << cycle_exists_dfs(nodes, edges) << endl;

	return 0;
}