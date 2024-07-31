class Solution {
public:

    int solve(TreeNode* root, int& ans){
        if(!root) return 0;
        int leftSum = max(0,solve(root->left, ans));
        int rightSum = max(0,solve(root->right, ans));

        ans = max(ans, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum); 
    }

    int maxPathSum(TreeNode* root) {
        int ans=-1e9;
        solve(root, ans);
        return ans;
    }
};