class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=0;

        for(int i=0; i<nums.size(); i++){
            if(!count){
                element = nums[i];
            }

            if(nums[i] == element) count++;
            else count--;
        }

        return element;
    }
};