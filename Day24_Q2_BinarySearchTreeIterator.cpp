class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right){
            TreeNode* temp = curr->right;
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};