/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

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
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        bool ret = isValidBST(root->left);
        if(ret && prev!= NULL && prev->val >= root->val){
            ret = false;
        }
        prev = root;
        if(ret)
            ret = isValidBST(root->right);
        return ret;
    }
};