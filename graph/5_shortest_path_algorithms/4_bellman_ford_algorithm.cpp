#include<bits/stdc++.h>
using namespace std;

// use case
// Find Shortest path from source and detect negative weight cycles in weighted directed/undirected graph.
// graph may/may not have negative edges. 
// Time complexity: O(E*V) ~ O(N^2)

// Alogrithm is pretty simple. 
// Relax all the edges V - 1 times (V = Nodes / vertex count)
// Relation is; A ---wt---> B
// if(dist[A] + wt < dist[B]) then dist[B] = dist[A] + wt

// To check cycle, run the relaxation Vth time, 1 time only after V - 1 times.
// If any value is updated --> that means negative weight cycle is present in graph

vector<int> bellmanFord(int V, vector<vector<int>>& edgeList, int src) {
	vector<int> dist(V, INT_MAX);

	// put dist of source from source = 0 (necessary to run algorithm)
	dist[src] = 0;

	// relax each edge V - 1 times
	for(int i = 1; i <= V - 1; ++i) {
		for(auto& edge: edgeList) {

			// this is entire algorithm
			int u = edge[0], v = edge[1], wt = edge[2];
			if(dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}

		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph
	// 0 --> 1
	// |     |
	// V     V
	// 2 --> 3

	int V = 4;
	vector<vector<int>> edgeList {
		{0, 1, 3},
		{0, 2, 2},
		{2, 3, 1},
		{1, 3, 4}
	}; // u, v, wt
	int src = 0;
	vector<int> dist = bellmanFord(V, edgeList, src);

	for(int i = 0; i < V; ++i) {
		cout << "Minimum distance of " << i << " from source " << src << " is: " << dist[i] << endl;
	}

	return 0;
}