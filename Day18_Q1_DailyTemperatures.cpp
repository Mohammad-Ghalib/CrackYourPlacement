class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        if(n==1) return {};

        stack<pair<int,int>> st;
        vector<int> ans(n,0);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first <= temperatures[i]) st.pop();
            if(!st.empty()) ans[i] = st.top().second - i;
            st.push({temperatures[i], i});
        }

        return ans;
    }
};