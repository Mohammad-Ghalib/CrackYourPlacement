class Solution {
public:

    bool isValid(int r, int c, char a, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[r][i] == a) return false;
            if(board[i][c] == a) return false;
            if(board[3*(r/3) + i/3][3*(c/3)+i%3] == a) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char a='1'; a<='9'; a++){
                        if(isValid(i, j, a, board)){
                            board[i][j] = a;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};