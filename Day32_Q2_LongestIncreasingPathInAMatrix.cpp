class Solution {
public:

    int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    int dr[4] = {-1,1,0,0}, dc[4] = {0,0,1,-1};

    vector<vector<int> > dp;
    int maxPath, n, m;

    int solve(vector<vector<int>>& mat, int r, int c){
        if(dp[r][c]) return dp[r][c];
        dp[r][c] = 1;

        for(int i = 0; i < 4; i++){ 
            int nr = r+dr[i] , nc = c+dc[i];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m || mat[nr][nc] <= mat[r][c]) continue;

            dp[r][c] = max(dp[r][c], 1 + solve(mat, nr, nc));
        }         
        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        dp.resize(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                maxPath = max(maxPath, solve(matrix, i, j));
            }
        }        

        return maxPath;
    }

};