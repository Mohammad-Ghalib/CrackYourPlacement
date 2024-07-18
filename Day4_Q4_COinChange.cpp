class Solution {
public:

    int solve(vector<int>& coins, int amt, int i, vector<vector<int>>& dp){
        if(amt == 0) return 0;
        if(i<0) return 1e9;
        if(dp[i][amt] != INT_MAX) return dp[i][amt];

        int take = amt >= coins[i]? 1 + solve(coins, amt-coins[i], i, dp): 1e9;
        int notTake = solve(coins, amt, i-1, dp);

        return dp[i][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, INT_MAX));

        int ans = solve(coins, amount, n-1, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};