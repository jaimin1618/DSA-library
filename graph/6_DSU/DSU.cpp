#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
	vector<int> parent;
	vector<int> rank;

public:

	DSU(int V) {
		parent = vector<int>(V);
		rank = vector<int>(V, 1); // rank 1 for all nodes

		for(int i = 0; i < V; ++i) {
			parent[i] = i; // nodes are parent of themselves initially
		}
	}

	int find(int node) {
		if(parent[node] == node)
			return node;

		// path compression - caching the parent
		return parent[node] = find(parent[node]);
	}

	int union_sets(int a, int b) {
		int leaderA = find(a);
		int leaderB = find(b);

		if(leaderA != leaderB) {
			if(rank[leaderA] > rank[leaderB]) {
				parent[leaderB] = leaderA;
				rank[leaderA] += rank[leaderB]; // survival of the fittest - union by rank
			} else {
				parent[leaderA] = leaderB;
				rank[leaderB] += rank[leaderA];
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	return 0;
}