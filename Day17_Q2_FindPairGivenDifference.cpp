class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int lo=0, hi=1;
        
        while(lo<n && hi<n){
            if(lo==hi){
                hi++;
                continue;
            }
            if( (arr[hi] - arr[lo]) == x) return 1;
            if( (arr[hi] - arr[lo]) > x)  lo++;
            else hi++;
        }
        
        return -1;
    }
};