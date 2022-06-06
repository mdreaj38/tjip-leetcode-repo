//TC: O(N)
//MC: O(N)
class MyLinkedList {
public:
    class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int value, ListNode* nxt=NULL){
            val = value;
            next = nxt;
        }
    };
    
    ListNode* head;
    
    MyLinkedList() {
        head = new ListNode(INT_MIN);
    }
    
    int get(int index) {
        ListNode *cur = head;
        for (int i = 0; i <= index; i++){
            cur = cur->next;
            if (cur == NULL){
                return -1;
            }
        }
        
        return cur->val; 
    }
    
    void addAtHead(int val) {
        ListNode* curNode = new ListNode(val, head->next);
        head->next = curNode;
    }
    
    void addAtTail(int val) {
        ListNode *curNode = head;
        
        while (curNode->next){
            curNode = curNode->next;
        }
        curNode->next = new ListNode(val);
    }
    
    void addAtIndex(int index, int val) {
        ListNode* curNode = head;
        while (curNode){
            if (index == 0){
                if (curNode->next == NULL){
                    curNode->next = new ListNode(val);
                }else{
                    curNode->next = new ListNode(val, curNode->next);
                }
                
                return;
            }
            curNode = curNode->next;
            index--;
        }
        return;
    }
    
    void deleteAtIndex(int index) {
        ListNode* curNode = head;
        
        while (curNode != NULL){
            if (index == 0 and curNode->next){
                ListNode *dumpNode = curNode->next;
                curNode->next = curNode->next->next;
                
                delete (dumpNode);
                return;
            }
            curNode = curNode->next;
            index--;
        }
        
        return;
    }
};
