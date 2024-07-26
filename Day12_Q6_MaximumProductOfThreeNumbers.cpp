class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(); 
        if(nums[n-3] > 0){
            if(nums[1] >= 0) return nums[n-1]*nums[n-2]*nums[n-3];
            return max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]);
        }
        else if(nums[n-1] > 0){
            return nums[0]*nums[1]*nums[n-1];
        }

        return nums[n-1]*nums[n-2]*nums[n-3];
    }
};