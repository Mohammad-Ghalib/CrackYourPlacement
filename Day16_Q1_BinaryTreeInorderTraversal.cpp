class Solution {
public:
    
    void solve(TreeNode* root, vector<int>& inorder){
        if(!root) return;
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        solve(root, inorder);
        return inorder;
    }
};