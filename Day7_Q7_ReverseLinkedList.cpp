class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *prev=NULL, *curr=head, *ahead;

        while(curr){
            ahead = curr->next;
            curr->next = prev;

            prev = curr;
            curr = ahead;
        } 

        return prev;
    }
};