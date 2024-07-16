class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> remainder;
        int currSum=0, n=nums.size(), rem, ans=0;

        remainder[0] = 1;

        for(int i=0; i<n; i++){
            currSum += nums[i];

            rem = currSum%k;
            if(rem<0) rem += k;

            ans += remainder[rem];
            remainder[rem]++;
        }

        return ans;
    }
};