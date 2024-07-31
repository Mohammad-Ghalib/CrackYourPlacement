class Solution{ 
public:
    
    Node* findMid(Node* head){
        Node *slow=head, *fast=head, *prev;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        return slow;
    }
    
    Node* reverse(Node* head){
        Node *prev=NULL, *curr=head, *next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    void reorderList(Node* head) {
        if(!head || !head->next) return;
        
        Node *mid, *h1=head, *h2, *temp;
        
        mid = findMid(head);
        h2 = reverse(mid);
        
        bool first = true;
        
        while(h1 && h2){
            if(first){
                temp = h1->next;
                h1->next = h2;
                h1 = temp;
            }
            else{
                temp = h2->next;
                h2->next = h1;
                h2 = temp;
            }
            first = !first;
        }
        
        return;
    }
};