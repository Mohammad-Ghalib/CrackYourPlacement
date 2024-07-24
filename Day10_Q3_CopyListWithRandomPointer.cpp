class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        for(Node* temp = head; temp; temp = temp->next->next){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
        }

        Node* newHead = head->next;

        for(Node* temp = head; temp; temp = temp->next->next){
            if(temp->random) temp->next->random = temp->random->next;

        }  

        for(Node* temp = head; temp; temp = temp->next){
            Node* clone = temp->next;

            temp->next = clone->next;
            if(clone->next) clone->next = clone->next->next; 
        }  

        return newHead;
    }
};