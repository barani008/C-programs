/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        list<string> queue;
        unordered_set<string> dict;
        for(string word:wordList)
            dict.insert(word);
        queue.push_back(beginWord);
        int cost = 1;
        while(queue.size()>0){
            int size = queue.size();
            for(int i=0;i<size;i++){
                string word = queue.front();
                if(word == endWord)
                    return cost;
                queue.pop_front();
                addWords(queue, dict, word);
                //cout<<word<<endl;
            }
            cost++;
        }
        return 0;
    }
    
    void addWords(list<string>& queue, unordered_set<string>& dict, string word){
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            for(int j=0;j<26;j++){
                word[i] = 'a'+j;
                if(dict.find(word)!=dict.end()){
                    queue.push_back(word);
                    dict.erase(word);
                }
                //cout<<word<<endl;
                word[i] = ch;
            }
        }
    }
};