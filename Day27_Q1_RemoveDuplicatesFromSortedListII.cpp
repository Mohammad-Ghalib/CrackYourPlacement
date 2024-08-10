class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(!head) return head; 
        ListNode *prev=NULL, *curr=head, *next=curr->next;

        while(next) {
            if(curr->val == next->val) {
                while(next && next->val == curr->val){
                    next=next->next;
                }
                if(!prev) head=next;
                else prev->next = next;
            }
            else prev=curr;
            
            curr=next;
            if(next) next=curr->next;
        }
        return head;
    }
};