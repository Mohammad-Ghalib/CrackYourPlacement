class Solution {
public:

    int solve(TreeNode* root, bool isLeft){
        if(!root) return 0;
        if(!root->left && !root->right){
            if(isLeft) return root->val;
            return 0;
        }

        return solve(root->left, true) + solve(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return solve(root, false);
    }
};