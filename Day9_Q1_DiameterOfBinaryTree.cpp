class Solution {
public:
    int findDiam(TreeNode* root, int& diam){
        if(!root) return 0;
        int lh = findDiam(root->left,  diam);
        int rh = findDiam(root->right, diam);

        diam = max(diam, lh+rh);
        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diam = INT_MIN;
        findDiam(root, diam);
        return diam;
    }
};