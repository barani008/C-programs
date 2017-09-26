/**
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
    int ret = 0;
    int countUnivalSubtrees(TreeNode* root) {
        checkUnival(root);
        return ret;
    }
    
    bool checkUnival(TreeNode* root){
        if(root== NULL)
            return true;
        bool left = checkUnival(root->left);
        bool right = checkUnival(root->right);
        if(left && right && (root->left==NULL || root->left->val == root->val) && 
            (root->right == NULL || root->right->val == root->val)){
                ret++;
                return true;
        }
        return false;
    }
};