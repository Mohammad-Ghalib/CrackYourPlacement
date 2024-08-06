class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int> st;

        for(int i=0; i<n; i++){

            if(tokens[i]=="+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long int n1 = st.top();
                st.pop();
                long long int n2 = st.top();
                st.pop();

                if(tokens[i] == "+") st.push(n2+n1);
                else if(tokens[i] == "-") st.push(n2-n1);
                else if(tokens[i] == "*") st.push(n2*n1);
                else st.push(n2/n1);
            }
            else{
                st.push(stol(tokens[i]));
            }
        }

        return st.top();
    }
};