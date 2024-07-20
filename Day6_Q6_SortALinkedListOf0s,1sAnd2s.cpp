class Solution{
public:

    Node* segregate(Node *head) {
        if(!head || !head->next) return head;
        
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node *zero = zeroHead, *one = oneHead, *two = twoHead, *temp = head;
        
        while(temp){
            if(temp->data == 0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = one->next;
            }
            else{
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        
        zero->next = oneHead->next? oneHead->next: twoHead->next;
        one->next  = twoHead->next;
        two->next  = NULL;
        
        Node* newHead = zeroHead->next;
        
        delete zeroHead; delete oneHead; delete twoHead;
        
        return newHead;
        
    }
};