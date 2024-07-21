class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *prev = NULL, *curr = head;

        while(curr){
            if(curr->val == val){
                ListNode* temp = curr;
                if(prev){
                    prev->next = curr->next;
                    curr = curr->next;
                }
                else{
                    curr = curr->next;
                    head = curr;
                }
                delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
        
    }
};