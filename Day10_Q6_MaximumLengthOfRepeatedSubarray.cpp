class Solution {
public:

    int solve(vector<int>& a, vector<int>& b, int i, int j, int& ans, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int curr=0; 

        if(a[i] == b[j]) curr = 1 + solve(a, b, i-1, j-1, ans, dp);

        solve(a, b, i, j-1, ans, dp);
        solve(a, b, i-1, j, ans, dp);

        ans = max(ans, curr);

        return dp[i][j] = curr;

    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0, m=nums1.size(), n=nums2.size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        solve(nums1, nums2, m-1, n-1, ans, dp);
        return ans;
    }
};