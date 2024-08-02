class Solution {
public:

    void solve(int ind, vector<int>& perm, int& ans){
        if(ind == perm.size()){
            ans++;
            return;
        }

        for(int i=ind; i<perm.size(); i++){
            if( (perm[i]%(ind+1) == 0) || ((ind+1)%perm[i] == 0) ){
                swap(perm[i], perm[ind]);
                solve(ind+1, perm, ans);
                swap(perm[i], perm[ind]);
            }
        }
    }

    int countArrangement(int n) {
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            nums[i] = i+1;
        }

        int ans=0;

        solve(0, nums, ans);
        return ans;
    }
};