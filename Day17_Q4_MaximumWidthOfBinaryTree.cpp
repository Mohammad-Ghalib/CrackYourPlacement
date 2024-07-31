class Solution {
public:

    typedef long long int ll;

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty()){
            int n = q.size(), first, last;
            ll mini = q.front().second;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front().first;
                ll currIdx = q.front().second - mini;
                q.pop();

                if(i==0) first = currIdx;
                if(i==n-1) last = currIdx;

                if(node->left) q.push({node->left, 2*currIdx});
                if(node->right) q.push({node->right, 2*currIdx+1});
                
            }

            ans = max(ans, last-first+1);
        }

        return ans;
    }
};