/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string nextPermutation(string cur){
        if(cur.size()<2)
            return cur;
        int i = 0;
        for(i=cur.size()-1;i>=1;i--){
            if(cur[i]-'0' > cur[i-1]-'0')
                break;
        }
        if(i!=0){
            int k = cur.size()-1;
            while(k >= i){
                if(cur[k]-'0' > cur[i-1]-'0')
                    break;
                k--;
            }
            char tmp = cur[k];
            cur[k] = cur[i-1];
            cur[i-1] = tmp;
            reverseStr(cur, i, cur.size()-1);
        }else{
            reverseStr(cur, 0, cur.size()-1);
        }
        return cur;
    }
    
    void reverseStr(string& cur, int i, int j){
        while(i<j){
            char ch = cur[i];
            cur[i] = cur[j];
            cur[j] = ch;
            i++;
            j--;
        }
    }
    
    string getPermutation(int n, int k) {
        string cur = "";
        for(int i=1;i<=n;i++)
            cur += to_string(i);
        for(int i = 0;i<k-1;i++){
            //cout<<cur<<endl;
            cur = nextPermutation(cur);
        }
        return cur;
    }
};