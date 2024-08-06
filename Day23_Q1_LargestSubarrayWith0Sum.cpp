class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        
        map<int, int> mp;
        int sum=0, ans=0;
        
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum==0) ans = i+1;
            else{
                if(mp.find(sum) != mp.end()) ans = max(ans, i-mp[sum]);
                else mp[sum] = i;
            }
        }
        
        return ans;
    }
};