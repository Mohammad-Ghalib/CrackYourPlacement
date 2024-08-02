class Solution {
public:

    void solve(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(ind < 0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(ind-1, nums, temp, ans);
        temp.pop_back();

        int i=ind-1;
        while(i>=0 && nums[i] == nums[ind]) i--;
        solve(i, nums, temp, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        solve(n-1, nums, temp, ans);
        return ans;
    }
};