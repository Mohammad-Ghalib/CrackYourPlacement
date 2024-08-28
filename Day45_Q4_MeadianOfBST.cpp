int totalNodes(struct Node *root){
    if(!root) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

void median(struct Node* root, struct Node*& prev, int& curr, int total, float& med){
    if(!root || (curr > (total+2)/2)) return;
    
    median(root->left, prev, curr, total, med);
    curr++;
    if(curr == (total+2)/2){ 
        if(total%2) med = root->data;
        else{
            med = (float)(((float)root->data + (float)prev->data)/2.0); 
        } 
    }
    prev = root;
    median(root->right, prev, curr, total, med);
}

float findMedian(struct Node *root){
    if(!root->left && !root->right) return root->data;
    int nodes = totalNodes(root), curr=0;
    float med;
    struct Node* prev;
    
    median(root, prev, curr, nodes, med);
    return med;
    
}