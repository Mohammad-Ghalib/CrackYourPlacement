class Solution {
  public:
  
    void solve(int ind, vector<int> &arr, set<vector<int>>& ans){
        if(ind == arr.size()){
            ans.insert(arr);
            return;
        }
        
        for(int i=ind; i<arr.size(); i++){
            swap(arr[i], arr[ind]);
            solve(ind+1, arr, ans);
            swap(arr[i], arr[ind]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        solve(0, arr, ans);
        
        vector<vector<int>> temp(ans.begin(), ans.end());
        return temp;
    }
};