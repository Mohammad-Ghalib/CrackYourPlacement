class Solution {
public:

    typedef long long int ll;

    bool isValid(TreeNode* root, ll mini, ll maxi){
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) return false;

        return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};