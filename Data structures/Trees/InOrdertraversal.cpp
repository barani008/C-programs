/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> ret;
        TreeNode* cur = root;
        if(root==NULL)
            return ret;
        while(!stack.empty()|| cur!=NULL){
            if(cur!=NULL){
                stack.push(cur);                
                cur = cur->left;
            }else{
                cur = stack.top();
                stack.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};