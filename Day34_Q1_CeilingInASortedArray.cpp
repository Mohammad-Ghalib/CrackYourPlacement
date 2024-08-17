class Solution {
  public:

    int findFloor(vector<long long> &v, long long n, long long x) {
        int ans=-1, low = 0, high = n-1, mid;
        
        while(low <= high){
            mid = low + (high-low)/2;
            if(v[mid] <= x){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return ans;
    }
};
