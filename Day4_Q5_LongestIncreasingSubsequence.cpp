class Solution {
public:

    int solve(vector<int>& nums, int pi, int i, vector<vector<int>>& dp){
        if(i<0) return 0;
        if(dp[pi+1][i] != -1) return dp[pi+1][i];

        int take=0, notTake;
        if(pi == -1 || nums[i] < nums[pi]){
            take = 1 + solve(nums, i, i-1, dp);
        }

        notTake = solve(nums, pi, i-1, dp);

        return dp[pi+1][i] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n, -1));

        return solve(nums, -1, n-1, dp);
    }
};