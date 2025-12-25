#include<bits/stdc++.h>
using namespace std;

// Kahn's alogrithm - for topological sort
vector<int> topologicalSortBFS(int V, vector<vector<int>>& edges) {
    vector<vector<int>> g(V);

    // step #1 - calculate indegree
    vector<int> indegree(V, 0);

    for (auto& edge : edges) {
        int a = edge[0], b = edge[1];
        g[a].push_back(b);
        indegree[b]++;
    }

    // step #2 - push nodes with 0 indegree into queue
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // save the result
    vector<int> res;

    // step #3 - while (!q.empty()) and reduce indegree of neighbours
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        res.push_back(front);

        for (auto& nbr : g[front]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    // verify - DAG, by checking indegree count of all nodes
    // all indegrees should be zero 0 if graph is DAG
    // else not zero
    for (int i = 0; i < V; ++i) {
        if (indegree[i] != 0) {
            return {};
        }
    }

    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph - 
	// 1 --> 0
	// ^     ^
	// |     |
	// 3 --> 2
	// Check in graph 3 has 0 prerequisites (or dependency) and 0 has highest dependencies
	int V = 4;
	vector<vector<int>> edges {{1,0},{2,0},{3,1},{3,2}};
	vector<int> sortedGraph = topologicalSortBFS(V, edges);

	for(auto& item: sortedGraph)
		cout << item << " ";
	cout << endl;
	

	return 0;
}