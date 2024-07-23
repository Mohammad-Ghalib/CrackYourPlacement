class Solution {
public:

    void findProbableRoots(TreeNode* root, int val, vector<TreeNode*>& v){
        if(!root) return;
        if(root->val == val) v.push_back(root);

        findProbableRoots(root->left, val, v);
        findProbableRoots(root->right, val, v);
    }

    bool findSubtree(TreeNode* r1, TreeNode* r2){
        if(!r1 && !r2) return true;
        if((!r1 && r2) || (r1 && !r2)) return false;
        
        return  (r1->val == r2->val) && 
                findSubtree(r1->left, r2->left) && 
                findSubtree(r1->right, r2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> v;

        findProbableRoots(root, subRoot->val, v);

        for(int i=0; i<v.size(); i++){
            if(findSubtree(v[i], subRoot)) return true;
        }

        return false;
    }
};