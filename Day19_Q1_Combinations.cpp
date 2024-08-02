class Solution {
public:

    void solve(int n, int k, vector<int>& temp, vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(n<1) return;

        temp.push_back(n);
        solve(n-1, k-1, temp, ans);
        temp.pop_back();
        solve(n-1, k,  temp, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(n ,k, temp, ans);
        return ans;
    }
};