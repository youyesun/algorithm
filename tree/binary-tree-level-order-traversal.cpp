/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

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
    void helper(vector<vector<int>> &res,TreeNode* root,int level){
        if(!root)
            return;
        if(level == res.size())
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        helper(res,root->left,level+1);
        helper(res,root->right,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(res,root,0);
        return res;
    }
};
