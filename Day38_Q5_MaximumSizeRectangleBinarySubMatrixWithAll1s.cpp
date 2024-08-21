class Solution{
private:
    void nextSmaller(int *arr, int n, vector<int> &next) {
        
        stack<int> s;
        s.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
            
        }
    }

    void prevSmaller(int *arr, int n, vector<int> &prev) {
        
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; i++) {
            
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }
    }

    int getMaxArea(int *arr, int n, vector<int> &next, vector<int> &prev) {
        
        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int len = arr[i];

            if (next[i] == -1) {
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1;
            int newArea = len * width;

            area = max(area, newArea);
        }

        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        if (n == 0 || m == 0) return 0;

        vector<int> next(m), prev(m);
        int area = INT_MIN;

        nextSmaller(M[0], m, next);
        prevSmaller(M[0], m, prev);
        
        area = getMaxArea(M[0], m, next, prev);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (M[i][j] != 0) {
                    M[i][j] = M[i][j] + M[i - 1][j];
                } 
                else {
                    M[i][j] = 0;
                }
            }
            
            nextSmaller(M[i], m, next);
            prevSmaller(M[i], m, prev);
            
            area = max(area, getMaxArea(M[i], m, next, prev));
        }

        return area;
    }

};