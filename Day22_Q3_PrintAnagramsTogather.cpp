class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string, vector<string>> mp;
        string s;
        
        for(int i=0; i<string_list.size(); i++){
            s = string_list[i];
            sort(s.begin(), s.end());
            mp[s].push_back(string_list[i]);
        }
        
        vector<vector<string>> ans;
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};