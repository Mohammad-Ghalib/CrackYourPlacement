class Solution {
public:

    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& rowL, vector<int>& upperD, vector<int>& lowerD){
                
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(!rowL[row] && !lowerD[row+col] && !upperD[n-1+col-row]){
                rowL[row] = 1, lowerD[row+col] = 1, upperD[n-1+col-row] = 1;
                board[row][col] = 'Q';

                solve(col+1, n, board, ans, rowL, upperD, lowerD);

                rowL[row] = 0, lowerD[row+col] = 0, upperD[n-1+col-row] = 0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        vector<int> row(n,0), upperD(2*n-1, 0), lowerD(2*n-1, 0);
        for(int i=0; i<n; i++) board[i] = s;
        solve(0, n, board, ans, row, upperD, lowerD);
        return ans;
    }
};