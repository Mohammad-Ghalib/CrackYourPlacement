#define ll long long
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        ll st=0, en=m-1, ans=INT_MAX;
        while(en<n){
            ans = min(ans, a[en]-a[st]);
            st++, en++;
        }
        
        return ans;
    }   
};