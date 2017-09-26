/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int w1 = -1;
        int w2 = -1;
        int min1 = INT_MAX;
        for(int i=0;i<words.size();i++){
            if(words[i].compare(word1)==0){
                w1 = i;
                if(w2!=-1){
                    min1 = min(w1-w2, min1);
                }
            }
            if(words[i].compare(word2)==0){
                w2 = i;
                if(w1!=-1){
                    min1 = min(w2-w1, min1);
                }
            }
        }
        return min1;
    }
};