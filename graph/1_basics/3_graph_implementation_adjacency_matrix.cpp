#include<bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>>& graph) {
	int n = graph.size();

	for(int i = 1; i < n; ++i) {
		cout << "Node: " << i << ", Neighbors: ";
		for(int j = 1; j < n; ++j) {
			if(graph[i][j] == 1) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	     (1)
	    ↙   ↘
	  (2) → (3) → (4)
	   ↑           |
	   └─-─────────┘
    */
    // OR
	/*
	     (1)
	    /   \
	  (2)--(3)--(4)
	   |         |
	   └─-───────┘
    */
	vector<vector<int>> edges {
		{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}
	};

	// we have 4 vertex 1,2,3,4 
	// so we create n=5 matrix/adj-matrix and IGNORE the 0th row and col
	int n = 5; 
	vector<vector<int>> adjacency_matrix(5, vector<int>(5, 0));

	for(int i = 0; i < edges.size(); ++i) {
		int  a = edges[i][0], b = edges[i][1];
		// un-directed graph
		adjacency_matrix[a][b] = 1;
		adjacency_matrix[b][a] = 1;
	}

	print_graph(adjacency_matrix);
	cout << endl;

	return 0;
}