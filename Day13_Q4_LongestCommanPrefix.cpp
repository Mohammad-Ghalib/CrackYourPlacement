class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
        
        if(strs[0].size() == 0) return "";
        string ans = "", a = strs[0], b = strs[strs.size()-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]) break;
            ans += a[i];
        }
        
        return  ans;
    }
};