/**
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
        cout<<ret<<endl;
        return ret;
    }
    
    void preOrder(TreeNode* root, string& ret){
        if(root==NULL){
            return;
        }
        ret += to_string(root->val);
        ret += ",";
        preOrder(root->left, ret);
        preOrder(root->right, ret);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string token;
        while(getline(ss, token, ',')){
            q.push(token);
        }
        return dest(q, INT_MIN, INT_MAX);
    }
    
    TreeNode* dest(queue<string>& q, int low, int up){
        if(q.empty())
            return NULL;
        int next = stoi(q.front());
        //cout<<next<<" "<<low<<" "<<up<<endl;
        if(next < low || next > up)
            return NULL;
        q.pop();
        TreeNode* root = new TreeNode(next);
        root->left = dest(q, low, root->val);
        root->right = dest(q, root->val, up);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));