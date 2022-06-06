/*
* TC: O(N)
* MC: O(N)
* where N = number Of Node
*/
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        queue<Node*>nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            int sz = nodes.size();
            while(sz)
            {
                Node* cur = nodes.front();
                nodes.pop();
                
                if(sz>1)
                {
                    cur->next= nodes.front();
                }
                if(cur->left)
                {
                    nodes.push(cur->left);
                }
                if(cur->right)
                {
                    nodes.push(cur->right);
                }
                sz--;
            }
        }
        
        return root;
    }
};
