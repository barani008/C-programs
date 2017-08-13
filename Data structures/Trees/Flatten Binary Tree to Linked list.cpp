/**
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flatten(TreeNode* root) {
        makeList(root);    
    }
    //TreeNode* last=NULL;
    TreeNode* makeList(TreeNode*& root){
        if(root==NULL){
            return NULL;
        }
        TreeNode* tmp = root->right;
        root->right = makeList(root->left);
        root->left = NULL;
        TreeNode* cur = root;
        while(cur->right!=NULL)
            cur = cur->right;
        cur->right = makeList(tmp);
        return root;
    }
};