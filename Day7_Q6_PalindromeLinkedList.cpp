class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        ListNode *prev=NULL, *curr=head, *ahead;

        while(curr){
            ahead = curr->next;
            curr->next = prev;

            prev = curr;
            curr = ahead;
        } 

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next; 
        }

        ListNode* revHead = reverse(slow);

        while(revHead){
            if(head->val != revHead->val) return false;
            head = head->next;
            revHead = revHead->next;
        }

        return true;
    }
};