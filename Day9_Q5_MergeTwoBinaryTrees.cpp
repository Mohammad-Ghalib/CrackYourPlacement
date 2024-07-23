class Solution {
public:

    void merge(TreeNode* r1, TreeNode* r2, TreeNode* par1, TreeNode* par2, bool isLeft){
        if(!r2) return;
        if(!r1){
            if(isLeft){
                par1->left = r2;
                par2->left = NULL;
            }
            else{
                par1->right = r2;
                par2->right = NULL;
            }
            return;
        }

        r1->val += r2->val;

        merge(r1->left,  r2->left,  r1, r2, true );
        merge(r1->right, r2->right, r1, r2, false);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;

        merge(root1, root2, NULL, NULL, false);
        return root1;
    }
};