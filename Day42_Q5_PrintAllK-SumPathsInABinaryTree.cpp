class Solution {
  private:
  
    void solve(Node* root, int k, vector<int> &path, int &count) {
        if (root == nullptr) return;
        
        path.push_back(root->data);
        int sum = 0;
        
        for (int i=path.size()-1; i>=0; i--) {
            sum += path[i]; 
            if (sum == k) count++;
        }
        
        solve(root->left, k, path, count);
        solve(root->right, k, path, count);
        
        path.pop_back();
    }
    
  public:
  
    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        
        solve(root, k, path, count);
        return count;
    }
};