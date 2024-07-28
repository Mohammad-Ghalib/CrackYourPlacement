class Solution{
public:

    bool solve(int i, int sum, int arr[], vector<vector<int>>& dp){
        if(!sum) return true;
        if(i<0) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take=0, notTake = solve(i-1, sum, arr, dp);
        if(sum >= arr[i]) take = solve(i-1, sum-arr[i], arr, dp);
        
        return dp[i][sum] = take || notTake;
    }
    

    int equalPartition(int N, int arr[]){
        int sum=0;
        for(int i=0; i<N; i++) sum += arr[i];
        
        if(sum%2) return 0;
        vector<vector<int>> dp(N, vector<int>(sum/2+1,-1));
        
        return solve(N-1, sum/2, arr, dp);
    }
};