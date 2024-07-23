class Solution {
public:

    void solve(TreeNode* root, string s, vector<string>& ans){
        
        s += (to_string(root->val) + "->");

        if(!root->left && !root->right){
            ans.push_back(s.substr(0, s.size()-2));
            return;
        }

        if(root->left)  solve(root->left,  s, ans);
        if(root->right) solve(root->right, s, ans);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        string s;

        solve(root, s, ans);
        return ans;
    }
};