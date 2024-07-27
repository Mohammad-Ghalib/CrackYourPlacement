class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp="", ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(temp != "") st.push(temp);
                temp = "";
            }
            else temp += s[i];
        }
        if(temp != "") st.push(temp);

        while(!st.empty()){
            ans += st.top();
            st.pop();
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};