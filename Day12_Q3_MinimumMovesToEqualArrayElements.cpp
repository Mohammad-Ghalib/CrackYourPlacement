class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int sum=0, n = nums.size(), a, ans=0, m =n/2;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) ans += abs(nums[i] - nums[m]);
        
        return ans;
        
    }
};