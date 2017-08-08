/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe){
        if(ps>pe)
            return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int pos = is;
        for(int i=is;i<=ie;i++){
            if(inorder[i] == root->val)
                pos = i;
        }        
        root->left = build(inorder, is, pos-1, postorder, ps, ps-is+pos-1);
        root->right = build(inorder, pos+1, ie, postorder, ps-is+pos, pe-1);
        return root;
    }
};