/**
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;
        getPaths(root, ret, path);
        return ret;
    }
    
    void getPaths(TreeNode* root, vector<string>& ret, string path){
        if(root== NULL)
            return;
        path += to_string(root->val);
        if(root->left == NULL && root->right==NULL){
            ret.push_back(path);
            return;
        }
        path += "->";
        getPaths(root->left, ret, path);
        getPaths(root->right, ret, path);        
    }
};