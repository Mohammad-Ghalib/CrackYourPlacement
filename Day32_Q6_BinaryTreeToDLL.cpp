class Solution {
    public: 

    pair<Node*,Node*> D(Node* root){
        if(!root) return {NULL,NULL};
        if(!root->left&&!root->right){
            return {root,root};
        }
        pair<Node*,Node*> l=D(root->left);
        pair<Node*,Node*> r=D(root->right);
        root->right=r.first;
        if(r.first)
        r.first->left=root;
        root->left=l.second;
        if(l.second)
        l.second->right=root;
        if(!l.first) l.first=root;
        if(!r.second) r.second=root;
        return {l.first,r.second};
    }
    
    Node * bToDLL(Node *root) { 
        return D(root).first;
    }
};