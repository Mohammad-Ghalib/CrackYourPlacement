class Solution {
public:

    bool isPal(int st, int en, string s){
        while(st <= en){
            if(s[st++] != s[en--]) return false;
        }
        return true;
    }

    void solve(int ind, string s, vector<string>& temp, vector<vector<string>>& ans){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPal(ind, i, s)){
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};