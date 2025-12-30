#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(int V, vector<vector<int>>& edgeList) {
	vector<vector<int>> dist(V, vector<int>(V + 1, INT_MAX));

	for(int i = 0; i < V; ++i) {
		for(int j = 0; j < V; ++j) {
			if(i == j) {
				dist[i][j] = 0;
			}
		}
	}

	for(auto& edge: edgeList) {
		int u = edge[0], v = edge[1], wt = edge[2];
		dist[u][v] = wt;
	}

	for(int k = 0; k < V; ++k) {
		// k ~ via node
		for(int i = 0; i < V; ++i) {
			for(int j = 0; j < V; ++j) {
				if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
					continue;

				int dist_through_k = dist[i][k] + dist[k][j];
				if(dist_through_k < dist[i][j])
					dist[i][j] = dist_through_k;
			}
		}
	}

	// After running the standard Floyd-Warshall algorithm
	for (int i = 0; i < V; i++) {
	    if (dist[i][i] < 0) {
	        // Negative cycle detected
	        return {{}}; 
	    }
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph
	// 0 -3-> 1
	// |      |   
	// 2      4
	// V      V
	// 2 -1-> 3

	int V = 4;
	vector<vector<int>> graph {
		{0, 1, 3},
		{0, 2, 2},
		{2, 3, 1},
		{1, 3, 4}
	}; // u, v, wt
	vector<vector<int>> dist = floydWarshall(V, graph);

	for(int i = 0; i < V; ++i) {
		for(int j = 0; j < V; ++j) {
			cout << "from " << i << " to " << j << ": " << (dist[i][j]==INT_MAX ? 1000 : dist[i][j]) << endl;
		}
		cout << endl;
	}
	

	return 0;
}