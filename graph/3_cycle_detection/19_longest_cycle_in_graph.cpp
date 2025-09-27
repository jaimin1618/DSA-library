#include<bits/stdc++.h>
using namespace std;

void dfs(int source, vector<vector<int>>& g, vector<int>& visited, vector<int>& current_path, int& mark, int& ans) {
	cout << source << " ";
	visited[source] = 1;
	current_path[source] = mark;
	mark++;

	for(auto& nbr: g[source]) {
		if(!visited[nbr]) {
			dfs(nbr, g, visited, current_path);
		} else {

		}
	}

	current_path[]
}

int longest_cycle(int V, vector<vector<int>>& graph) {
	vector<int> visited (V, 0); 
	set<int> current_path;
	// keep track of 0 -> 3 (0 is in current path & 3 is it's 3rd node in path)

	int ans = 0;
	int mark = 1;

	for(int i = 0; i < V; ++i) {
		if(!visited[i]) {
			dfs(i, g, visited, current_path, mark, ans);
		}
	}

	return ans;
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