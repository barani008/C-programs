/**
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   
Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".

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
    TreeNode* str2tree(string s) {
        int ind = 0;
        return maketree(s, ind);
    }
    
    TreeNode* maketree(string s, int& ind){
        if(ind == s.size())
            return NULL;        
        int start = ind;        
        while(s[ind]!='(' && s[ind]!=')' && ind<s.size())
            ind++;        
        if(ind-start>0){
            TreeNode* root = new TreeNode(stoi(s.substr(start, ind-start)));            
            root->left = NULL;
            root->right = NULL;
            if(ind==s.size()){
                return root;
            }
            ind++;
            if(s[ind-1]==')')
                return root;
            else{
                root->left = maketree(s, ind);
                if(s[ind]==')'){
                    ind++;
                }else if(s[ind] == '('){
                    ind++;
                    root->right = maketree(s, ind);
                    if(s[ind]==')')
                        ind++;
                }
                return root;
            }            
        }else
            return NULL;
    }
};