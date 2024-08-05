class Solution {
public:

    int ans;

    void solve(TreeNode* root, int& k){
        if(!root) return;

        solve(root->left, k);
        
        if(--k == 0){
            ans = root->val;
            return;
        }

        solve(root->right, k);

    }

    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        return ans;
    }
};