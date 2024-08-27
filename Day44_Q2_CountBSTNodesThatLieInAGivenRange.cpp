class Solution{
public:

    void solve(Node* root, int low, int high, int &count) {
        if (root == NULL) return;
        
        if (root->data > low) {
            solve(root->left, low, high, count);
        }
        
        if (root->data >= low && root->data <= high) {
            count++;
        }
        
        if (root->data < high) {
            solve(root->right, low, high, count);
        }
    }
    
    int getCount(Node *root, int l, int h) {
        int count = 0;
        solve(root, l, h, count);
        return count;
    }
};
