class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            while(size){
                TreeNode* node = q.front();
                q.pop();

                if(size == 1) ans.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                size--;
            }
        }

        return ans;
    }
};