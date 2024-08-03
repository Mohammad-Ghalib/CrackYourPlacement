class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node *prev = root, *curr=NULL;

        while(prev->left){
            curr = prev;
            while(curr){
                curr->left->next = curr->right;
                if(curr->next) curr->right->next = curr->next->left;
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};