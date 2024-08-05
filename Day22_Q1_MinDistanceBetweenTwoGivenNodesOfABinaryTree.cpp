class Solution{
    public:

    int dist(Node* root, int& a){
        if(!root) return 0;
        if(root->data == a) return 1;
        
        int d1 = dist(root->left, a), d2 = dist(root->right, a); 
        
        return  d1>0? d1+1: d1 +  d2>0? d2+1: d2;
    }
    
    Node* lca(Node* root, int& a, int& b){
        if(!root || root->data == a || root->data == b) return root;
        
        Node* left  = lca(root->left,  a, b);
        Node* right = lca(root->right, a, b);
        
        if(!left) return right;
        if(!right) return left;
        return root;
    }
    
    int findDist(Node* root, int a, int b) {
        Node* node = lca(root, a, b);
        
        return dist(node, a) + dist(node, b) -2;
    }
};