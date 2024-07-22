class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *behind=head, *ahead=head;
        while(n--){
            ahead = ahead->next;
        }

        if(!ahead) return head->next;

        while(ahead->next){
            ahead = ahead->next;
            behind = behind->next;
        }

        behind->next = behind->next->next;

        return head;
    }
};