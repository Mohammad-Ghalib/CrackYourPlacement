class Solution {
    public:
    
    int dr[4] = {0,0,1,-1}, dc[4] = {-1,1,0,0};
    
    bool isValid(int r, int c, int n, int m){
        return r>=0 && c>=0 && r<n && c<m;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges=0, n=grid.size(), m=grid[0].size(), ans=0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) freshOranges++;
                else if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        
        if(freshOranges == 0) return ans;
        
        while(!q.empty() && freshOranges){
            int sz = q.size();
            ans++;
            
            for(int i=0; i<sz; i++){
                pair<int,int> cell = q.front();
                q.pop();
                
                int row = cell.first, col = cell.second;
                
                for(int j=0; j<4; j++){
                    int nr = row+dr[j], nc = col+dc[j];
                    if(isValid(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc] == 1){
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                        freshOranges--;
                    }
                }
            }
        }
        
        if(freshOranges > 0) return -1;
        return ans;
    }
};