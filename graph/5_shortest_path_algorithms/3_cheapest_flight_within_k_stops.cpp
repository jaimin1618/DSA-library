#include<bits/stdc++.h>
using namespace std;
// Important problem - requires to understand how Dijkstra actually works interally. 
// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

int cheapestFlightPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	// graph
	vector<vector<pair<int, int>>> graph(n);

	for(auto& flight: flights) {
		// u, v, w
		graph[flight[0]].push_back({flight[1], flight[2]});
	}

	queue<vector<int>> q; // {stops, node, dist}
	vector<int> dist(n, INT_MAX);

	dist[src] = 0;
	q.push({0, src, 0});

	while(!q.empty()) {
		auto f = q.front();
		q.pop();

		int stops = f[0];
		int node = f[1];
		int dist_of_parent = f[2];

		if(stops > k)
			continue;

		for(auto& nbr: graph[node]) {
			int nbrNode = nbr.first;
			int edgeWt = nbr.second;

			if(dist_of_parent + edgeWt < dist[nbrNode] && stops <= k) {
				dist[nbrNode] = dist_of_parent + edgeWt;
				q.push({stops + 1, nbrNode, dist[nbrNode]});
			}
		}
	}


	if(dist[dst] == INT_MAX)
		return -1;

	return dist[dst];	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 4;

	vector<vector<int>> flights {
		{0, 1, 100},
		{1, 2, 100}, 
		{2, 0, 100},
		{1, 3, 600},
		{2, 3, 200}
	};

	int src = 0;
	int dst = 3;
	int k = 1;

	cout << cheapestFlightPrice(n, flights, src, dst, k) << endl;
 
	return 0;
}