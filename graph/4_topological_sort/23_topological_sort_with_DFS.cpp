#include<bits/stdc++.h>
using namespace std;
// remember - this algorithm doesn't cover CYCLIC graph  - if there is cycle you need to modify algorithm
// for that.

deque<int> dq; // you may also utilise stack, list or vector (need to reverse);
// dfs method to topological sort graph items
void dfs(int source, vector<vector<int>>& g, vector<int>& visited) {
    visited[source] = 1;

    for (auto& nbr : g[source]) {
        if (!visited[nbr]) {
            dfs(nbr, g, visited);
        }
    }

    dq.push_front(source);
}

vector<int> topologicalSortDFS(int V, vector<vector<int>>& edges) {
	vector<vector<int>> g(V);
	vector<int> visited(V, 0);

    for (auto& edge : edges) {
        int a = edge[0], b = edge[1];
        g[a].push_back(b);
    }

	for (int i = 0; i < V; ++i) {
		int source = i;
		dfs(source, g, visited);
	}

	vector<int> res (dq.begin(), dq.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int V = 4;
	vector<vector<int>> edges {{1,0},{2,0},{3,1},{3,2}};
	vector<int> sortedGraph = topologicalSortDFS(V, edges);

	cout << "sorted graph: ";
	for(auto& item: sortedGraph)
		cout << item << " ";
	cout << endl;
	
	

	return 0;
}