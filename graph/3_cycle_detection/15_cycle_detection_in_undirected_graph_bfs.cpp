#include<bits/stdc++.h>
using namespace std;

bool bfs(int source, vector<vector<int>>& g, vector<int>& visited, vector<int>& parent) {
	queue<int> q;
	q.push(source);
	visited[source] = 1;

	while(!q.empty()) {
		int f = q.front();

		// process current
		cout << f << " ";
		q.pop();

		for(auto& nbr: g[f]) {
			if(!visited[nbr]) {
				visited[nbr] = 1;
				parent[nbr] = f;
				q.push(nbr);
			} else {
				if(parent[f] != nbr)
					return true;
			}
		}
	}

	return false;
}

bool cycle_exists_bfs(int nodes, vector<vector<int>>& edges) {
	// make graph
	vector<vector<int>> g;
	for(auto& edge: edges) {
		g[edge[0]].push_back(edge[1]);
		g[edge[1]].push_back(edge[0]);
	}

	// apply BFS 
	vector<int> visited (nodes, 0), parent (nodes, -1);
	bool loop = false;

	for(int i = 0; i < nodes; ++i) {
		if(!visited[i]) {
			loop = bfs(i, g, visited, parent);
			if(loop)
				break;
		}
	}

	return loop;
}

// Another way to detect cycle using queue<pair<int, int>> q
bool detect(int src, vector<int> adj[], int vis[]) {
  vis[src] = 1; 
  // store <source node, parent node>
  queue<pair<int,int>> q; 
  q.push({src, -1}); 
  // traverse until queue is not empty
  
  while(!q.empty()) {
      int node = q.front().first; 
      int parent = q.front().second; 
      q.pop(); 
      
      // go to all adjacent nodes
      for(auto adjacentNode: adj[node]) {
          // if adjacent node is unvisited
          if(!vis[adjacentNode]) {
              vis[adjacentNode] = 1; 
              q.push({adjacentNode, node}); 
          }
          // if adjacent node is visited and is not it's own parent node
          else if(parent != adjacentNode) {
              // yes it is a cycle
              return true; 
          }
      }
  }
  // there's no cycle
  return false; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "Jaimin" << endl;

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
	cout << "Cycle exists: " << cycle_exists_bfs(nodes, edges) << endl;

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
	// cout << "Cycle exists: " << cycle_exists_bfs(nodes, edges) << endl;

	return 0;
}