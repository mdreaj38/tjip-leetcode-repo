
//TC: O(N)
//MC: O(N)
class Solution {
public:	
    Node* copyRandomList(Node* head) {
		unordered_map<Node*, Node*> oldToClone;
		Node* curPos = head;

		while(curPos){
			oldToClone[curPos] = new Node(curPos->val);
			curPos = curPos->next;
		}
		
		curPos = head;
		while(curPos){
			Node* cloneNode = oldToClone[curPos];
			cloneNode->next = oldToClone[curPos->next];
			cloneNode->random = oldToClone[curPos->random];
            
			curPos = curPos->next;
		}

		return oldToClone[head];
	}
};
