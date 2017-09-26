/**
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

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
    unordered_map<TreeNode*, int> map;
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(map.find(root)!=map.end())
            return map[root];
        int cur = root->val;
        int next = rob(root->left);
        if(root->left !=NULL){            
                cur += rob(root->left->left);
                cur += rob(root->left->right);
        }
        next += rob(root->right);
        if(root->right !=NULL){
                cur += rob(root->right->left);
                cur += rob(root->right->right);
        }
        map[root] = max(next, cur);
        return max(next, cur);
    }
};