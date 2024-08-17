class Solution {
public:

    int numTrees(int n, vector<int> &memo) {
        if (n <= 1) return 1;

        if (!memo[n]){
            for (int i = 1; i <= n; i++){
                memo[n] += numTrees(i - 1, memo) * numTrees(n - i, memo);
            }
        }
        return memo[n];
    }

    int numTrees(int n) {
        vector<int> memo(20);
        return numTrees(n, memo);
    }
};