class Solution {
public:

    TreeNode* createBST(int st, int en, vector<int>& nums){
        if(st > en) return NULL;
        int mid = (en-st)/2 + st;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(st, mid-1, nums);
        root->right = createBST(mid+1, en, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(0, nums.size()-1, nums);
    }
};