class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *newHead = head, *prev=head, *curr=head->next;

        while(curr){
            if(curr->val == prev->val){
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;

                delete temp;
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }

        return newHead;
    }
};