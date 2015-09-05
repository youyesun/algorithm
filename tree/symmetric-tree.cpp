/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

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
    bool helper(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL)
            return left == right;
        if(left->val != right->val)
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left,root->right);
    }
};
