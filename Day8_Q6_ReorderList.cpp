class Solution {
public:

    ListNode* findMid(ListNode* head){
        ListNode *slow = head, *fast = head, *prev;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }

    ListNode* reverse(ListNode* head){
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

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode *st1=head, *mid, *st2, *temp;

        mid = findMid(head);
        st2 = reverse(mid);

        int n=1;

        while(st1 && st2){
            if(n%2){
                temp = st1->next;
                st1->next = st2;
                st1 = temp;
            }
            else{
                temp = st2->next;
                st2->next = st1;
                st2 = temp;
            }
            n++;
        }
    }
};