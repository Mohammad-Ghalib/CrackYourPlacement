# define mod 100000

class Solution {
public:

    static bool same(string &org,string &p,int i){
        return p.substr(i,org.size())==org;
    }
    
    vector <int> search(string text, string pattern){
        
        int curhash=0,orghash=0, len = text.size();
        vector<int> ans;
        
        for(int i=0;i<len;i++){
            curhash=((pattern[i]-'a')+curhash)%mod;
            orghash=(orghash+(text[i]-'a'))%mod;
        }
        
        if(curhash==orghash){
            if(same(text,pattern,0)){
                ans.push_back(1);
            }
        }
        
        for(int i=text.size(),j=0;i<pattern.size();i++,j++){
            curhash = (curhash-pattern[j])%mod;
            curhash = (curhash+pattern[i])%mod;
            
            if(curhash==orghash){
                if(same(text,pattern,j+1)){
                    ans.push_back(j+2);
                }
            }
        }
        
        return ans;
    }
     
};