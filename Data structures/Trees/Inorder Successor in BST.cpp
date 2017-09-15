/**

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL)
            return NULL;
        TreeNode* ret = NULL;
        ret = inorderSuccessor(root->left, p);
        if(ret==NULL && prev!=NULL && prev == p){
            ret = root;
        }
        prev = root;
        if(ret==NULL)
            ret = inorderSuccessor(root->right, p);
        return ret;
    }
};