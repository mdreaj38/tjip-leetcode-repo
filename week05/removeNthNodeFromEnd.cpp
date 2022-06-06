/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//TC: O(N)
//MC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(INT_MIN, head);
		ListNode* front = dummy;
		ListNode* back = dummy;
		while(n--)
		{
			front = front->next;
		}

        while(front->next)
		{
			front = front->next;
			back = back->next;		
		}
		
        back->next = back->next->next;
        
		return dummy->next;
    }
};

