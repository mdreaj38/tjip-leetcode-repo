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
// TC: O(N), where N = max of length of l1 and l2
// MC: O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* curPos;
        int sum = 0;
        
        while(l1 or l2){
            if(l1){
                sum+= l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2 = l2->next;
            }
            
            ListNode* temp = new ListNode(sum%10);
            sum/=10;
            
            if(head==NULL){
                head = curPos = temp;
            }else{
                curPos->next = temp;
                curPos = curPos->next;
            }
        }
        
        if(sum){
            curPos->next = new ListNode(sum);
        }
        
        return head;
    }
};
