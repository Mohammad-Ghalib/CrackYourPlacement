class Solution {
public:

    void solve(int open, int close, string op, vector<string>& ans){

        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }

        if(open > 0){
            op += '(';
            solve(open-1, close, op, ans);
            op.pop_back();
        }

        if(close > open){
            op += ')';
            solve(open, close-1, op, ans);
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n, close = n;
        string op = "";

        solve(open, close, op, ans);
        return ans;
    }
};