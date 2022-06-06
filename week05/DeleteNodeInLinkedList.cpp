// TC: O(1)
// MC: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* dumpNode = node->next;
        
        node->val = node->next->val;
        node->next = node->next->next;
        
        delete(dumpNode);
    }
};
