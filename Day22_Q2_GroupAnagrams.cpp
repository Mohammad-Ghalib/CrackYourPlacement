class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> m;

        for(auto it : strs){
            string s = it;
            sort(it.begin(), it.end());
            m[it].push_back(s);
        }

        for(auto it: m){
            ans.push_back(it.second);
        }

        return ans;
    }
};