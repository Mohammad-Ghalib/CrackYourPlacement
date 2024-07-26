class Solution {
  public:
    
    bool isValid(int r, int c, int n, int m){
        return r>=0 && r<n && c>=0 && c<m;
    }
    
    void dfs(int r, int c, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int nr = r+i, nc = c+j;
                if(isValid(nr, nc, n, m) && !vis[nr][nc] && (grid[nr][nc] == '1')){
                    dfs(nr, nc, n, m, grid, vis);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), islands=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( (grid[i][j] == '1') && !vis[i][j]){
                    dfs(i, j, n, m, grid, vis);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};