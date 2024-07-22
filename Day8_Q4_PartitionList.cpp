class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
        ListNode *curr = head, *head1St = head1, *head2St = head2; 

        while(curr){
            if(curr->val < x){
                head1->next = curr;
                head1 = head1->next;
            }
            else{
                head2->next = curr;
                head2 = head2->next;
            }

            curr = curr->next;
        }

        head1->next = head2St->next;
        head2->next = NULL;
        return head1St->next;
    }
};