/**
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        sumOfLeaves(root->left, true);
        sumOfLeaves(root->right, false);
        return sum;
    }
    
    void sumOfLeaves(TreeNode* root, bool left){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL && left){
            sum += root->val;
        }else{
            sumOfLeaves(root->left, true);
            sumOfLeaves(root->right, false);
        }
    }
};