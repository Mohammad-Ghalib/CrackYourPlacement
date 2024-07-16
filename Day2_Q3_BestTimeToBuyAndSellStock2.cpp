class Solution {
public:
    int solve(vector<int>& p, int ind, int buy, vector<vector<int>>& dp){
        if(ind >= p.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        int buySt=0, sellSt=0, doNoth=0;
        if(!buy) buySt = solve(p, ind+1, 1, dp) - p[ind];
        else sellSt = solve(p, ind+1, 0, dp) + p[ind];
        doNoth = solve(p, ind+1, buy, dp); 

        return dp[ind][buy] = max(buySt, max(sellSt, doNoth));
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(prices, 0, 0, dp);   
    }
};