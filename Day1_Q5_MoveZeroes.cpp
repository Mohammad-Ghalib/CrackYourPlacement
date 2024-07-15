class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st=0, curr=0, n=nums.size();

        while(curr < n){
            if(nums[curr]) swap(nums[curr++], nums[st++]);
            else curr++;
        }
    }
};