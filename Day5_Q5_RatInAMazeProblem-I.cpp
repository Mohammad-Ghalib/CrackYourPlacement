class Solution {
  public:
  
    int dr[4] = {1,0,0,-1}, dc[4] = {0,-1,1,0}; 
    
    bool isValid(int r, int c, int n){
        return r>=0 && r<n && c>=0 && c<n;
    }
    
    void dfs(int r, int c, int n, vector<vector<int>> &mat, 
        vector<vector<int>> &vis, string s, vector<string>& ans){
        
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        
        for(int i=0; i<4; i++){
            int nr=r+dr[i], nc=c+dc[i];
            
            if(isValid(nr, nc, n) && mat[nr][nc] == 1 && !vis[nr][nc]){
                switch(i){
                    case 0: s += 'D'; break;
                    case 1: s += 'L'; break;
                    case 2: s += 'R'; break;
                    case 3: s += 'U'; break;
                }
                
                vis[nr][nc] = 1;
                dfs(nr, nc, n, mat, vis, s, ans);
                vis[nr][nc] = 0;
                s.pop_back();
            }
        }
        
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        
        if(!mat[0][0] || !mat[n-1][n-1]) return {};
        
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<string> ans;
        string s;
        
        vis[0][0] = 1;
        dfs(0, 0, n, mat, vis, s, ans);
        
        return ans;
    }
};