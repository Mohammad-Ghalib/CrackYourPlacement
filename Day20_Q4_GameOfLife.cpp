class Solution {
public:

    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }

    int liveCells(int r, int c, vector<vector<int>>& board){
        int m=board.size(), n=board[0].size(), nr, nc, cells=0;

        for(int dr=-1; dr<=1; dr++){
            for(int dc=-1; dc<=1; dc++){
                if(dr==0 && dc==0) continue;
                nr = r+dr, nc = c+dc;
                if(isValid(nr, nc, m, n) && (board[nr][nc]%5 != 0)) cells++; 
            }
        }

        return cells;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size(), live;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                live = liveCells(i, j, board);
                if(!board[i][j] && live==3) board[i][j] = 5;
                else if(board[i][j]){
                    if(live < 2) board[i][j] = 2;
                    else if(live==2 || live==3) board[i][j] = 3;
                    else if(live > 3) board[i][j] = 4;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] = board[i][j]%2;
            }
        }

    }
};