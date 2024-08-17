class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){

        queue<pair<int,int>>q;
        
        for(int i=0; i<n; i++){
            if(mat[i][0]=='O'){
                mat[i][0]='1';
                q.push({i,0});
            }
            if(mat[i][m-1]=='O'){
                mat[i][m-1]='1';
                q.push({i,m-1});
            }
        }
        
        for(int i=1; i<m-1; i++){
            if(mat[0][i]=='O'){
                mat[0][i]='1';
                q.push({0,i});
            }
            if(mat[n-1][i]=='O'){
                mat[n-1][i]='1';
                q.push({n-1,i});
            }
        }
        
        int disr[4]={-1,0,1,0};
        int disc[4]={0,1,0,-1};
    
        while(!q.empty()){
            auto node = q.front();q.pop();
            int row = node.first;
            int col = node.second;
            mat[row][col]='1';
            for(int i=0; i<4; i++){
                int nrow = row + disr[i];
                int ncol = col + disc[i];
               
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                }
            }
        }
       
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j]=='O') mat[i][j]='X';
                if(mat[i][j]=='1')mat[i][j]='O';
            }
        }
       
        return mat;
    }
};