/**
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
        if(ps>pe)
            return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int pos = is;
        for(int j=is;j<=ie;j++){
            if(inorder[j]==root->val){
                pos = j;
            }
        }
        root->left = build(preorder, ps+1, ps-is+pos, inorder, is, pos-1);
        root->right = build(preorder, ps+pos-is+1, pe, inorder, pos+1, ie);
        return root;
    }
};