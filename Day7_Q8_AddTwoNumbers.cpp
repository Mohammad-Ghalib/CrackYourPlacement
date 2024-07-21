class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num,n1,n2,c=0;

        ListNode *temp = new ListNode(0), *head = temp; 

        while(l1 || l2 || c){
            n1 = l1? l1->val: 0;
            n2 = l2? l2->val: 0;

            num = n1+n2+c;
            c = num/10;

            ListNode* node = new ListNode(num%10);
            temp->next = node;
            temp = temp->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return head->next;
    }
};