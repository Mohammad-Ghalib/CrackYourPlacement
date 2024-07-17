class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0, n = nums.size();

        for(int i=0; i<n; i++){
            if(range < i) return false;
            range = max(range, i+nums[i]);
        }

        return true;
    }
};