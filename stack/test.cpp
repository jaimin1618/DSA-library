class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(grid, n, m);
    }

    int solve(vector<vector<int>>& grid, int n, int m) {
        if(n = 1 && m == 1)
            return grid[n - 1][m - 1];
        if(n == 0 || m == 0)
            return INT_MAX - 201;
        
        int moveUp = grid[n - 1][m - 1] + solve(grid, n - 1, m);
        int moveLeft = grid[n - 1][m - 1] + solve(grid, n, m - 1);
        return min(moveUp, moveLeft);
    }
};