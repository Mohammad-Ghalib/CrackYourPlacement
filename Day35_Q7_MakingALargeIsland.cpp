class Solution {

    int idx=2;
    unordered_map<int,int> mp;
    vector<pair<int,int>> direction{{1,0},{-1,0},{0,1},{0,-1}};
    int area = 0;

    void dfs(int i,int j,vector<vector<int>> &grid) {

        if(i<0 or i>=size(grid) or j<0 or j>=size(grid) or grid[i][j]!=1) return;

        mp[idx]++;
        grid[i][j]=idx;

        for(auto dir:direction) {
            dfs(i+dir.first,j+dir.second,grid);
        }
    }

    void markAllTheConnectedComponents(vector<vector<int>>& grid) {
        int n=size(grid);
        mp.clear();
        idx=2;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    dfs(i,j,grid);
                    area=max(area,mp[idx]);
                    idx++;
                }
            }
        }
    }

    void findMaxArea(vector<vector<int>>& grid) {
        int n=size(grid);
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    q.push({i,j});
                }
            }
        }

        auto isValid = [&](int i,int j){
            return (i>=0 and i<n and j>=0 and j<n and grid[i][j]!=0);
        };

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;
            
            unordered_set<int> vis;
            int curr = 0;
            for(auto dir:direction) {
                int newi = i+dir.first;
                int newj = j+dir.second;
                
                if(isValid(newi,newj) and !vis.count(grid[newi][newj])) {
                    vis.insert(grid[newi][newj]);
                    curr += mp[grid[newi][newj]];
                }
            }
            area = max(curr+1,area);
        }
    }


public:
    int largestIsland(vector<vector<int>>& grid) {
        markAllTheConnectedComponents(grid);
        findMaxArea(grid);
        return area;
    }
};