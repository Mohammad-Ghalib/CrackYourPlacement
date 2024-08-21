class Solution {
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        
        if(root==nullptr) return;
        
        findPreSuc(root->left, pre, suc,key);
        
        if(root->key>key){
            if(!suc || (suc&&suc->key>root->key)){
                suc = root;
            }
        }
        else if(root->key<key){
            pre = root;
        }
        
        findPreSuc(root->right, pre, suc, key);
    }
};