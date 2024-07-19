class Solution {
public:

    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};

    bool isValid(int r, int c, int m, int n){
        return r>=0 && r<m && c>=0 && c<n;
    }

    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;

        for(int i=0; i<4; i++){
            int nr = r+dr[i], nc = c+dc[i];
            if(isValid(nr, nc, grid.size(), grid[0].size()) && grid[nr][nc] == '1' && !vis[nr][nc]){
                dfs(nr, nc, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size(), n=grid[0].size(), ans=0;
        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};