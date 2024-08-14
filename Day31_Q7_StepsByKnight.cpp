class Solution {
  public:
   
    bool Is_Valid(int i, int j, int n, vector<vector<bool>>& visited) {
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j]==false) return true;
        return false;
    }
    
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
        int Source_x = KnightPos[0]-1, Source_y = KnightPos[1]-1, Destiny_x = TargetPos[0]-1, Destiny_y = TargetPos[1]-1;
        int cnt = 0;

        if(Source_x == Destiny_x && Source_y == Destiny_y) return 0;
       
        queue<pair<int, int>>q;
        q.push({Source_x, Source_y});
        vector<vector<bool>>visited(N, vector<bool>(N, false));
        visited[Source_x][Source_y] = true;

        while(!q.empty()) {
            int q_size = q.size();
            cnt++;
            while(q_size != 0) {
                pair<int, int> val = q.front();
                q.pop();
               
                int x1 = val.first, y1 = val.second;
                
                int ax[8] = { 2,2, -1, 1, -2, -2, -1, 1};
                int ay[8] = { 1,-1, -2, -2, 1, -1, 2, 2};
                
                for(int i=0; i<8; i++) {
                    int x = ax[i]+x1, y = ay[i]+y1;
                   
                    if(x == Destiny_x && y == Destiny_y) return cnt;
                        
                    if(Is_Valid(x, y, N, visited)) {
                        visited[x][y] = true;
                        q.push({x, y});
                       
                    }
       
                }
               
                q_size--;
            }
               
        }
        return cnt;
   
    }
};