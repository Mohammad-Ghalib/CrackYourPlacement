class Solution {
public:
    vector<int> dr={1,0,-1,0};
    vector<int> dc={0,1,0,-1};

    bool isValid(int r, int c, int n, int m) {
        return (r>=0 && r<n && c>=0 && c<m);
    }

    bool solve(int r, int c, int idx, vector<vector<char>> &board, string &word, 
        vector<vector<vector<int>>> &dp, vector<vector<bool>> &vis) {
        int n=board.size(), m=board[0].size();

        if(idx==word.length()-1) {
            return word[idx]==board[r][c];
        }

        vis[r][c]=true;

        if(word[idx] != board[r][c]) {
            vis[r][c]=false;
            return false;
        }

        if(dp[r][c][idx] == 1) return dp[r][c][idx];

        for(int i=0; i<4; i++) {
            int nr = r+dr[i], nc = c+dc[i];
            if(isValid(nr, nc, n, m) && !vis[nr][nc]) {
                bool temp = solve(nr, nc, idx+1, board, word, dp, vis);
                if(temp) return dp[nr][nc][idx] = true;
                vis[nr][nc]=false;
            }
        }   

        vis[r][c]=false;
        return dp[r][c][idx] = false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size(), len = word.length();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (len, -1)));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==word[0]) {
                    bool temp = solve(i, j, 0, board, word, dp, vis);
                    if(temp) return true;
                }
            }
        }

        return false;
    }
};