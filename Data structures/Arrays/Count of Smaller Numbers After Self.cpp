/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

struct treeNode{
    int val;
    int leftBot;
    int dup;
    struct treeNode* left;
    struct treeNode* right;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        treeNode* root = NULL;
        vector<int> ret;
        for(int i=nums.size()-1;i>=0;i--){
            treeNode* tmp = new treeNode();
            tmp->val = nums[i];
            tmp->leftBot = 0;
            tmp->dup = 0;
            tmp->left = NULL;
            tmp->right = NULL;
            ret.insert(ret.begin(), insert(root, tmp));
        }
        return ret;
    }
    
    int insert(treeNode*& root, treeNode* tmp){
        int count =0;
        if(root==NULL){
            root= tmp;
            return 0;
        }else{
            treeNode* cur = root;
            while(true){
                if(cur->val > tmp->val){
                    cur->leftBot += 1;
                    if(cur->left != NULL)
                        cur = cur->left;
                    else{
                        cur->left = tmp;
                        break;
                    }
                }else if(cur->val < tmp->val){
                    count++;
                    count += cur->dup;
                    count += cur->leftBot;
                    if(cur->right != NULL){
                        cur = cur->right;
                    }else{
                        cur->right = tmp;
                        break;
                    }
                }else{
                    count+= cur->leftBot;
                    cur->dup++;
                    break;
                }
                //if(tmp->val == 100)
                 //   cout<<count<<endl;
            }
        }
        return count;
    }
};