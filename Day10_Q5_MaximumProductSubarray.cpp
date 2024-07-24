class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double prefix=1, suffix=1, ans=INT_MIN, n=nums.size();

        for(int i=0; i<n; i++){
            prefix *= (double)nums[i];
            suffix *= (double)nums[n-i-1];

            ans = max(ans, max(prefix, suffix));

            if(!prefix) prefix = 1;
            if(!suffix) suffix = 1;   
        }

        return (int)ans;
    }
};