/**
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        TreeNode* cur = root;
        while(!stk.empty() || cur!=NULL){
            if(cur!=NULL){
                stk.push(cur);
                ret.push_back(cur->val);
                cur = cur->left;
            }else{
                cur = stk.top();
                stk.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};