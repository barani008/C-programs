/**
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        vector<int> ret;
        if(root==NULL)
            return ret;
        stack.push(root);
        while(!stack.empty()){
            cur = stack.top();
            ret.insert(ret.begin(), cur->val);
            stack.pop();
            if(cur->left)
                stack.push(cur->left);
            if(cur->right)
                stack.push(cur->right);
        }
        return ret;
    }
};