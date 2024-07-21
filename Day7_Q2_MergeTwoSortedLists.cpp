class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *h1=list1, *h2=list2;

        if(h1->val > h2->val) swap(h1,h2);
        ListNode *head = h1;

        while(h1 && h2){
            ListNode *prev = NULL;

            while(h1 && h1->val <= h2->val){
                prev = h1;
                h1 = h1->next;
            }
            prev->next = h2;
            swap(h1,h2);
        }

        return head;
    }
};