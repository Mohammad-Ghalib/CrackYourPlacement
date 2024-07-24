class Solution {
public:

    int length(ListNode* head){
        int n=0;
        while(head){
            head = head->next;
            n++;
        }
        return n;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int n = length(head);
        if(n<k) return head;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *prev = dummyHead, *curr, *next;

        while(n >= k){
            curr = prev->next;
            next = curr->next;

            for(int i=1; i<k; i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            n -= k;
        } 

        return dummyHead->next;
    }
};