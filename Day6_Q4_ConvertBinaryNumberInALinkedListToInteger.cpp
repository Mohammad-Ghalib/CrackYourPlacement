class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num=0;
        while(head){
            if(head->val == 0) num <<= 1;
            else num = (num<<1) + 1;
            head = head->next;
        }

        return num;
    }
};