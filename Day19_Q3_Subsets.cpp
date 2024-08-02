class Solution {
public:

    void solve(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(ind<0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(ind-1, nums, temp, ans);
        temp.pop_back();
        solve(ind-1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();

        solve(n-1, nums, temp, ans);
        return ans;
    }
};