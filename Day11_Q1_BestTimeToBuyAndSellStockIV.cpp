class Solution {
public:

    int solve(int i, int k, bool buy, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i>=prices.size() || k==0) return 0;
        if(dp[i][k-1][buy] != -1) return dp[i][k-1][buy];

        int take=0, notTake=0;

        if(buy){
            take = solve(i+1, k, false, prices, dp) - prices[i];
            notTake = solve(i+1, k, buy, prices, dp);
        }
        else{
            take = solve(i+1, k-1, true, prices, dp) + prices[i];
            notTake = solve(i+1, k, buy, prices, dp);
        }

        return dp[i][k-1][buy] = max(take, notTake);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2, -1)));
        return solve(0, k, true, prices, dp);
    }
};