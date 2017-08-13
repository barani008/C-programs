/**
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    vector<int> sum_paths;
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        sumPaths(root, 0);
        for(int num:sum_paths)
            //cout<<num<<endl;
        return accumulate(sum_paths.begin(), sum_paths.end(), 0);
    }
    
    void sumPaths(TreeNode* root, int sum_so_far){
        sum_so_far *= 10;
        sum_so_far += root->val;
        //cout<<sum_so_far<<endl;
        if(root->left==NULL && root->right==NULL)
            sum_paths.push_back(sum_so_far);
        if(root->left!=NULL){
            sumPaths(root->left, sum_so_far);
        }
        if(root->right!=NULL){
            sumPaths(root->right, sum_so_far);
        }
    }
};