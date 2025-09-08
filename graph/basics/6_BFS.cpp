#include<bits/stdc++.h>
using namespace std;

// print - 
void print_graph(unordered_map<int, vector<int>>& graph) {
	for(auto& nbr: graph) {
		cout << "Node: " << nbr.first << ", Neighbors: ";
		for(auto& neighbor: nbr.second) {
			cout << neighbor << " ";
		}
		cout << endl;
	}
}

// BFS - 
// Note: This algorithm does't visit disconnected components from source node
void bfs(unordered_map<int, vector<int>>& graph) {
	int n = graph.size();
	queue<int> q;
	vector<bool> visited(n);

	// source node from where you want to start traverse
	q.push(0);
	visited[0] = true;

	while(!q.empty()) {
		int f = q.front();

		// process current node
		cout << f << " ";
		q.pop();

		// push neighboring nodes if not processed
		for(int& nbr: graph[f]) {
			if(!visited[nbr]) {
				visited[nbr] = true;
				q.push(nbr);
			}
		}
	}
}

void bfs_traversal(unordered_map<int, vector<int>>& graph, vector<int>& visited, int& source) {
	// why? 
	// because in above algorithm disconnected graph components from source node
	// will not be visited

	// to visit entire graph in BFS manner - you will have to check from each node
	// or apply bfs() from each not visited nodes
	// if(!visited[node])
	//     bfs(source: node)
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// graph-1
	//  1 -- 0 -- 5
	// 		 |
	//  3 -- 2
	//  |
	// 	4

	vector<vector<int>> edges {
		{0, 1}, {0, 5}, {0, 2}, {2, 3}, {3, 4}
	};

	unordered_map<int, vector<int>> graph;

	for(int i = 0; i < edges.size(); ++i) {
		int a = edges[i][0], b = edges[i][1];
		// un-directed
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	print_graph(graph);

	cout << "BFS traversal: ";
	bfs(graph);
	cout << "\n\n";
	
	// graph-2
	//  1 -- 0 -- 5
	// 
	//  3 -- 2
	//  |
	// 	4 (disconnected component of graph)

	edges.assign({
		{0, 1}, {0, 5}, {2, 3}, {3, 4}
	});

	graph.clear();

	for(int i = 0; i < edges.size(); ++i) {
		int a = edges[i][0], b = edges[i][1];
		// un-directed
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	print_graph(graph);

	return 0;
}