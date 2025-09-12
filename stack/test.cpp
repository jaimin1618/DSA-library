#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& g) {
    int nodes = g.size();
    vector<int> visited (nodes);
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int f = q.front();
        q.pop();

        // process
        cout << f << " ";
        // visited[f] = 1;

        for(int& nbr: g[f]) {
            if(!visited[nbr]) {
                // V this - visited[nbr] = 1 MUST be here and not when we process.
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // graph - 1 
    //    0
    //   / \
    //  /   \
    // 1 --- 2
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}
    };
    int nodes = 3;

    vector<vector<int>> g (3, vector<int>());
    for(auto& edge: edges) {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    bfs(g);

    return 0;
}