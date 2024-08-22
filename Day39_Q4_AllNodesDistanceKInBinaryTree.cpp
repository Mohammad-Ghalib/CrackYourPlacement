class Solution {

private:

    void markParents(TreeNode* root, map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            } 

            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int currLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel++ == k) break;
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};