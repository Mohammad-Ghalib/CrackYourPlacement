class Solution {
public:
    int minDeletions(string s) {
        
        map<char, int> m;
        vector<int> v;
        int ans=0;
        
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        
        for(auto it = m.begin(); it != m.end(); it++){
            v.push_back(it->second);
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        int f = v[0];
        
        for(int i=0; i<v.size(); i++){
            if(v[i] > f){
                if(f>0) ans += v[i]-f;
                else ans += v[i];
            }
            
            f = min(f-1, v[i]-1);
        }
        
        return ans;
        
    }
};