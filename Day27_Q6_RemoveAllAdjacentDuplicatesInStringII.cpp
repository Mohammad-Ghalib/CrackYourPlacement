class Solution {
public:

    string removeDuplicates(string s, int k) {

        stack<pair<char,int>> st;
        string ans;
        for(int i=s.size()-1;i>=0;i--){ 
            if(st.size() && st.top().first == s[i]){
                st.push({s[i],st.top().second+1});
            }
            else st.push({s[i],1});   
            
            if(st.size() && st.top().second == k){
                while(st.top().second != 1){
                    st.pop();
                }
                st.pop();
            }
        }
        while(st.size()){
            ans += st.top().first;
            st.pop();
        }
        return ans;
    }
};