#include<bits/stdc++.h>
using namespace std;

void print_graph(unordered_map<int, vector<int>>& graph) {
	for(auto& el: graph) {
		cout << "Node: " << el.first << ", Neighbors: ";
		for(auto& node: el.second) {
			cout << node << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	     (1)
	    /   \
	  (2)--(3)--(4)
	   |         |
	   └─-───────┘
    */
	vector<vector<int>> edgeList {
		{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}
	};

	// NOTE: in more than 90% times we will be using Adjacency list to represent graph
	// this is something new! 
	unordered_map<int, vector<int>> graph;

	for(int i = 0; i < edgeList.size(); ++i) {
		int a = edgeList[i][0], b = edgeList[i][1];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	print_graph(graph);

	// if graph is weighted - consider using pair<int, int> to store node and weight
	using pp = pair<int, int>;
	unordered_map<int, vector<pp>> g;
	// it will store "1" => [{2,3}, {1,2}] (each pair is {node, weight})
	
	return 0;
}