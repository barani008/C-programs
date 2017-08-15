/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool is_balanced;
    bool isBalanced(TreeNode* root) {
        is_balanced = true;
        height1(root, 0);
        return is_balanced;
    }
    
    int height1(TreeNode* root, int height){
        if(root==NULL)
            return height;
        int left = height1(root->left, height+1);
        int right = height1(root->right, height+1);
        if(abs(left-right)>1)
            is_balanced = false;
        return max(left, right);
    }
};