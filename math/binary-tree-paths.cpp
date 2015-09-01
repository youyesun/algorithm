/* Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        helper(res,"",root);
        return res;
    }

    void helper(vector<string> &res, string tmp, TreeNode* root){
        if(tmp.length() == 0)
            tmp = to_string(root->val);
        else
            tmp += "->" + to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            res.push_back(tmp);
            return;
        }

        if(root->left != NULL)
            helper(res,tmp,root->left);
        if(root->right != NULL)
            helper(res,tmp,root->right);

    }

};
