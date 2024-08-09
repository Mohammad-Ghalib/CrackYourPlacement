class Solution {
public:
    bool check(vector<int>& nums, int m, int curr){
        int i=-1, n = nums.size(), count=1, sum=0;
        
        while(++i<n && count<=m){
            if(sum+nums[i] <= curr) sum += nums[i];  
            else sum=nums[i], count++;
        }
		
        return count<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int e=0,s=0,mid,ans;
        for(auto x : nums){
			e += x;
			s=max(s,x);
		}	
        ans = e; 
        
        while(s<=e){
            mid = s + (e-s)/2;
            
            if(check(nums,m,mid)){
                ans = min(ans,mid);
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};