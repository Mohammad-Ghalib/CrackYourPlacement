class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int st=0, n=nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[st] != nums[i]){
                st++;
                nums[st] = nums[i];
            }
        }
        
        return st+1;
    }
};