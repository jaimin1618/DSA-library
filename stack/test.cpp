class Solution {
    vector<vector<int>> moves{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        // In first look 👁️😄 within 3 seconds of problem readin
        // Figured it's a BFS problem.

        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> sources;
        int mn = INT_MAX;
        bool no_rotten_oranges = true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    no_rotten_oranges = false;

                    int level = -1;
                    bfs(i, j, grid, level);
                    bool check = check_no_fresh_oranges(grid);

                    if (check) {
                        return level;
                    }
                }
            }
        }

        bool check = check_no_fresh_oranges(grid);
        if (!check)
            return -1;

        if (no_rotten_oranges) {
            return 0;
        }

        return mn == INT_MAX ? -1 : mn;
    }

    void bfs(int source_x, int source_y, vector<vector<int>>& g, int& level) {
        int m = g.size();
        int n = g[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        q.push({source_x, source_y});
        visited[source_x][source_y] = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                pair<int, int> f = q.front();
                q.pop();

                // check neigbours of front (x, y)
                for (auto& move : moves) {
                    int x = f.first + move[0], y = f.second + move[1];

                    if (valid_move(x, y, m, n) && visited[x][y] == 0 &&
                        g[x][y] == 1) {
                        visited[x][y] = 1;
                        g[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }

            level++;
        }
    }

    bool check_no_fresh_oranges(vector<vector<int>>& g) {
        for (auto& row : g) {
            for (auto& el : row) {
                if (el == 1) {
                    return false;
                }
            }
        }

        return true;
    }

    bool valid_move(int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return true;
    }
};