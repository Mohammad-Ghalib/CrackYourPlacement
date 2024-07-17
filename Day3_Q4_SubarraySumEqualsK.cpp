class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int currSum=0, ans=0, n=nums.size();

        for(int i=0; i<n; i++){
            currSum += nums[i];
            if(currSum == k) ans++;

            if(mp[currSum-k]) ans += mp[currSum-k];

            mp[currSum]++;
        }

        return ans;
    }
};