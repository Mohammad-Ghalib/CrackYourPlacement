class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m2;
        for(int i=0; i<t.size(); i++){
            m2[t[i]]++;
        }

        int left=0, right=0, n=s.size(), count=m2.size(), ans=INT_MAX, st=0;

        while(right < n){
            if(m2.find(s[right]) != m2.end() ){
                m2[s[right]]--;
                if(m2[s[right]] == 0) count--;
            }

            if(count == 0){
                while(count == 0){
                    if(m2.find(s[left]) != m2.end()){
                        if(m2[s[left]] == 0) count++;
                        m2[s[left]]++;
                    }          
                    left++;
                }
                if(ans > right-left+1){
                    ans = right-left+1;
                    st=left;
                }
            }
            right++;
        }

        return ans==INT_MAX? "": s.substr(st-1, ans+1);

    }
};