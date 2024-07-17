class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            long long int target3 = (long long int)target - (long long int)nums[i];
            for(int j=i+1; j<n; j++){
                long long int target2 = target3 - (long long int)nums[j];
                int front = j+1, back = n-1;

                while(front < back){
                    long long int sum = (long long int)nums[front] + (long long int)nums[back];
                    if(sum < target2) front++;
                    else if(sum > target2) back--;
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[front]);
                        temp.push_back(nums[back]);
                        ans.push_back(temp);

                        while(front < back && nums[front] == nums[front+1]) front++;
                        while(front < back && nums[back] == nums[back-1]) back--;
                        front++;
                        back--;
                    }
                }

                while(j+1<n && nums[j+1] == nums[j]) j++;
            }

            while(i+1<n && nums[i+1] == nums[i]) i++;
        }

        return ans;
    }
};