#include<bits/stdc++.h>
using namespace std;

// IMPORTANT POINT: 
// Current path != cycle length
// that's important to notice in this question. 

// global variable to save answer
int longestCycleLen = 0;

bool dfs(int tag, int source, vector<int>& visited, vector<int>& currentPath, vector<vector<int>>& g) {
	tag++;
	visited[source] = 1;
	currentPath[source] = tag; // tag current node

	for(auto& nbr: g[source]) {
		if(!visited[nbr]) {
			bool cycle = dfs(tag, nbr, visited, currentPath, g);
			if(cycle)
				return true;
		} else {
			if(currentPath[nbr] != 0) {
				int currentCycleLen = currentPath[source] - currentPath[nbr] + 1;
				longestCycleLen = max(longestCycleLen, currentCycleLen);
				return true;
			}
		}
	}

	return false;
}

int longest_cycle(int V, vector<vector<int>>& graph) {
	vector<int> visited (V, 0), currentPath (V, 0);

	for(int i = 0; i < V; ++i) {
		if(!visited[i]) {
			int sourceNode = i;
			dfs(0, sourceNode, visited, currentPath, graph);
		}
	}

	return longestCycleLen;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph - 1
	//              4
	//           /  ^
	//          /   |
	//         <    |
	// 1 ---> 3 ---> 2
	//       ^
	//       |
	//       | 
	//       0
	// Here in inputs they - there is at most one outgoing edge from node i to some other node j
	// that has been provided in inputs
	vector<int> edges = {3, 3, 4, 2, 3};
	int nodes = edges.size();
	// above edges list creates folowing Adjacency list
	// 0 -> 3
	// 1 -> 3
	// 2 -> 4
	// 3 -> 2
	// 4 -> 3 
	// int ans = longest_cycle(nodes, edges); // if there is no cycle return -1

	// let's make adjacency list and then solve the question
	vector<vector<int>> g (nodes);
	for(int i = 0; i < nodes; ++i) {
		g[i].push_back(edges[i]);
	}
	int ans = longest_cycle(nodes, g);
	cout << "longest cycle: " << ans << endl;


	return 0;
}