class Solution{
  public:
  
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        long long int pro=1, c0=0, pos;
        for(int i=0; i<n; i++){
            if(!nums[i]){
                c0++;
                pos = i;
            } 
            else pro *= nums[i];
        }
        
        vector<long long int> ans(n,0);
        if(c0>1) return ans;
        if(c0==1){
            ans[pos] = pro;
            return ans;
        }
        
        for(int i=0; i<n; i++){
            ans[i] = pro/nums[i];
        }
        
        return ans;
        
    }
};