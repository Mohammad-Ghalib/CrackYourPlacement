class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        dfs(root,low,high,sum);
        return sum;
    }

    void dfs(TreeNode* root, int low, int high, int &sum){
        if(!root) return;
        if(root->val > high){
            dfs(root->left,  low, high, sum);
        }
        else if(root->val < low){
            dfs(root->right, low, high, sum);
        }
        else{
            sum += root->val;
            dfs(root->left,  low, high, sum);
            dfs(root->right, low, high, sum);
        }
    }
};