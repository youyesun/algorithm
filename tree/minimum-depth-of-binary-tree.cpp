/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return !left || !right ? left+right+1:min(left,right)+1;
    }
};
