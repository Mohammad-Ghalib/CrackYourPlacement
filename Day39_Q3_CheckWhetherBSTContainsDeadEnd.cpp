class Solution{
  public:
  
    bool flag = false, isLeaf = false;
    int prev = 0, curr = 0;
    
    void func(Node* root){
        if(!root) return;
        
        func(root->left);
        
        if(isLeaf && curr-prev == 1 && root->data-curr == 1) flag = true;
        else if(isLeaf) isLeaf = false;
        
        if(!root->left && !root->right) isLeaf = true;
        
        prev = curr;
        curr = root->data;
        func(root->right);
    }
  
    bool isDeadEnd(Node *root) {
        func(root);
        return flag;
    }
};