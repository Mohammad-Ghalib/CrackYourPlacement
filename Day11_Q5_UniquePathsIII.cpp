class Solution {
public:

    int dr[4] = {0,0,1,-1}, dc[4] = {-1,1,0,0};

    bool isValid(int r, int c, int m, int n){
        return r>=0 && r<m && c>=0 && c<n;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, int cells, int& ans){
        if( (!isValid(r,c,grid.size(), grid[0].size()) ) || grid[r][c] == -1) return;

        if(grid[r][c] == 2){
            if(cells == 0) ans += 1; 
            return;
        }
        
        grid[r][c] = -1;
        cells -= 1;

        for(int i=0; i<4; i++){
           dfs(r+dr[i], c+dc[i], grid, cells, ans);
        }

        grid[r][c] = 1;
        cells += 1;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty=0, si, sj, ans;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    si = i;
                    sj = j; 
                }
                if(grid[i][j] == 0) empty++;
            }
        }

        dfs(si, sj, grid, empty+1, ans);
        return ans;
    }
};