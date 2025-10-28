class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) return head; 
            node = node->next;
        }

     
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(curr, k);

    
        return prev;
    }
};
