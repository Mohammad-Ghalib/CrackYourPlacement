class Solution {
public:
    
    Node* merge(Node* a, Node* b){
        Node *temp = new Node(0), *ans = temp;
        
        while(a && b){
            if(a->data < b->data){
                temp->bottom = a;
                a = a->bottom;
            }
            else{
                temp->bottom = b;
                b = b->bottom;
            }
            temp = temp->bottom;
        }
        
        if(a) temp->bottom = a;
        else temp->bottom = b;
        
        return ans->bottom;
    }

    Node *flatten(Node *root){
        if(!root || !root->next) return root;
        
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};