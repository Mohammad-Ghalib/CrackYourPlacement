class Solution {
public:
    
    Node* reverse(Node *head){
        if(!head || !head->next) return head;
        
        Node *prev=NULL, *curr=head, *ahead;
        
        while(curr){
            ahead = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = ahead;
        }
        
        return prev;
    }
    
    Node *compute(Node *head){
        if(!head || !head->next) return head;
        Node *temp = reverse(head), *prev, *newHead;
        
        
        int maxi=temp->data;
        prev = temp, newHead = temp;
        temp = temp->next;
        
        while(temp){
            if(temp->data >= maxi){
                maxi = temp->data;
                prev = temp;
                temp = temp->next;
            }
            else{
                Node *del = temp;
                prev->next = temp->next;
                temp = temp->next;
                
                delete del;
            }
        }
        
        return reverse(newHead);
    }
    
};