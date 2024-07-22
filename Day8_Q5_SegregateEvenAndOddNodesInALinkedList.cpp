class Solution{
public:
    Node* divide(int N, Node *head){
        Node *odd = new Node(-1), *even = new Node(-1);
        Node *curr = head, *oddSt = odd, *evenSt = even;
        
        while(curr){
            if(curr->data%2){
                odd->next = curr;
                odd = odd->next;
            }
            else{
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
        }
        
        even->next = oddSt->next;
        odd->next = NULL;
        
        return evenSt->next;
    }
};