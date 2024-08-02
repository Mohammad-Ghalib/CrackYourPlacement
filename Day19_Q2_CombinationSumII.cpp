class Solution {
public:

    void solve(int ind, int tar, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        if(ind<0) return;

        if(nums[ind] <= tar){
            temp.push_back(nums[ind]);
            solve(ind-1, tar-nums[ind], nums, temp, ans);
            temp.pop_back();

            int i=ind-1;

            while(i>=0 && (nums[i] == nums[ind]) ) i--;
            solve(i, tar, nums, temp, ans);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n = candidates.size();

        sort(candidates.begin(), candidates.end(), greater<int>());
        solve(n-1, target, candidates, temp, ans);
        return ans;
    }
};