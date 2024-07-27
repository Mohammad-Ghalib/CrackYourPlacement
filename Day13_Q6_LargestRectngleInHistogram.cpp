class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), ans=0;
        vector<int> leftSmallInd(n), rightSmallInd(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) leftSmallInd[i] = 0;
            else leftSmallInd[i] = st.top() + 1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) rightSmallInd[i] = n-1;
            else rightSmallInd[i] = st.top() - 1;
            st.push(i);

            ans = max(ans, (rightSmallInd[i] - leftSmallInd[i] + 1)* heights[i]); 
        }

        return ans;
    }
};