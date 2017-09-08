/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()==0)
            return 0;
        int max_val = 0;
        int bitmap[words.size()];
        fill(bitmap, bitmap+words.size(), 0);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                bitmap[i] |= (1<<(words[i][j]-'a'));
            }
            //cout<<bitmap[i]<<endl;
        }
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                //cout<<(bitmap[i]&bitmap[j])<<endl;
                if((bitmap[i] & bitmap[j]) == 0)
                    max_val = max(max_val, (int)(words[i].size()*words[j].size()));
            }
        }
        return max_val;
    }
};