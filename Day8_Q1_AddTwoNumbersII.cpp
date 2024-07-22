class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        
        if(head == NULL) return head;
        
        ListNode *prev = NULL, *curr = head, *next = head->next;
        
        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(curr) next = curr->next;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr1 = reverse(l1); 
        ListNode* curr2 = reverse(l2);
        
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        
        int car = 0, num;
        
        while(curr1 != NULL || curr2 != NULL || car){
            num = (curr1?curr1->val:0) + (curr2?curr2->val:0) + car;
            
            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
            
            ListNode* temp = new ListNode(num%10);
            curr->next = temp;
            curr = curr->next;
            
            car = num/10;
        }
        
        return reverse(head->next);
    }
};