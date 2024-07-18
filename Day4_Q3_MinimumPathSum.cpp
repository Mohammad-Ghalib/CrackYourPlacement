class Solution {
public:

    int solve(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
        if(m<0 || n<0) return 1e9;
        if(m==0 && n==0) return grid[0][0];
        if(dp[m][n] != INT_MAX) return dp[m][n];

        int up = grid[m][n] + solve(grid, m-1, n, dp);
        int left = grid[m][n] + solve(grid, m, n-1, dp);

        return dp[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        return solve(grid, m-1, n-1, dp);
    }
};