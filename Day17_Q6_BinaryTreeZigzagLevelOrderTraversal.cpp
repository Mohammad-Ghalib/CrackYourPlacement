class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size(), index;
            vector<int> row(size);

            for(int i=0; i<size; i++){
                index = leftToRight? i : size-i-1;

                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                row[index] = node->val;
            }

            leftToRight = !leftToRight;
            ans.push_back(row);
        }

        return ans;
    }
};