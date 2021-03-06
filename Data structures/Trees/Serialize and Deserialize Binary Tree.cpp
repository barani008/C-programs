/**
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless


 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        preOrder(root, ret);
        //cout<<ret<<endl;
        return ret;
    }
    
    void preOrder(TreeNode* root, string& enc){
        if(root==NULL){
            enc += "#";
            enc += ',';
            return;
        }
        enc += to_string(root->val);
        enc += ',';
        preOrder(root->left, enc);
        preOrder(root->right, enc);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string token;
        while(getline(ss, token, ',')){
            q.push(token);
            //cout<<token<<endl;
        }
        return makeTree(q);
    }
    
    TreeNode* makeTree(queue<string>& q){
        if(q.empty()){
            return NULL;
        }
        string next = q.front();        
        q.pop();
        if(next == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(next));
        root->left = makeTree(q);
        root->right = makeTree(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));