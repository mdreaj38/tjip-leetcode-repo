/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// TC: O(N)
// MC: O(1)
class Solution {
public:
    int maxDepth(TreeNode* root) {
		if(root == NULL){
			return 0;		
		}
		int leftMax = maxDepth(root->left);
		int rightMax = maxDepth(root->right);
		
		return max(leftMax, rightMax)+1;
    }
};
