class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        curr = head;
        Node* dummy = new Node(0);
        Node* copy_curr = dummy;
        
        while (curr) {
            copy_curr->next = curr->next;
            copy_curr = copy_curr->next;
            
            curr->next = curr->next->next;
            curr = curr->next;
        }
        
        Node* res = dummy->next;
        delete dummy;
        return res;
    }
};