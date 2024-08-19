class Solution {
    public:
    
    int evaluatePostfix(string S) {
        stack<int>st;
        
        for(int i=0; i<S.length(); i++){
            if(S[i]>='0' and S[i]<='9'){
               st.push(S[i]-'0');
            }
            else {
                int a= st.top();
                st.pop();
                int b=st.top();
                st.pop();
               
                switch(S[i]){
                    case '+': st.push(b+a);
                    break;
                    
                    case '-': st.push(b-a);
                    break;
                    
                    case '*': st.push(b*a);
                    break;
                    
                    case '/': st.push(b/a);
                    break;
                }
               
            }
        }
        return st.top();
    }
};