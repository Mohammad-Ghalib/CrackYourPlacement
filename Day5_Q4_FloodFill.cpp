class Solution {
public:

    int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};

    bool isValid(int r, int c, int m, int n){
        return r>=0 && r<m && c>=0 && c<n;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;

        int stCl = image[sr][sc], m=image.size(), n=image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            int r = q.front().first, c =q.front().second;
            q.pop();
            image[r][c] = color;

            for(int i=0; i<4; i++){
                int nr=r+dr[i], nc=c+dc[i];

                if(isValid(nr, nc, m, n) && image[nr][nc] == stCl){
                    q.push({nr,nc});
                }
            }
        }

        return image;
    }
};