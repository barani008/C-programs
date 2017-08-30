/*

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

struct trieNode{
        unordered_map<char, trieNode*> map;
        bool endsHere;
};
class WordDictionary {
public:
    struct trieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new trieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        struct trieNode* cur = root;
        for(int i=0;i<word.size();i++){
            if(cur->map.find(word[i])!=cur->map.end()){
                cur = cur->map[word[i]];
            }else{
                cur->map[word[i]] = new trieNode();
                cur = cur->map[word[i]];
                cur->endsHere = false;
            }
        }
        cur->endsHere = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        struct trieNode* cur = root;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                return findWord(cur, i, word);
            }
            else if(cur->map.find(word[i])!=cur->map.end()){
                cur = cur->map[word[i]];
            }else{
                return false;
            }    
        }
        return cur->endsHere;
    }
    
    bool findWord(trieNode* root, int index, string word){
        //cout<<index<<endl;
        if(index == word.size())
            return root->endsHere;
        struct trieNode* cur = root;
        for(int i=index;i<word.size();i++){
            if(word[i]=='.'){
                if(cur->map.size()==0)
                    return false;
                for(auto it=cur->map.begin(); it!=cur->map.end();it++){
                    if(findWord(it->second, i+1, word))
                        return true;
                }
                return false;
            }else{
                cout<<index<<endl;
                for(auto it=cur->map.begin(); it!=cur->map.end();it++){
                    cout<<it->first<<endl;
                }
                if(cur->map.find(word[i])!=cur->map.end()){
                    cur = cur->map[word[i]];
                }else{
                    return false;
                }
            }
        }
        return cur->endsHere;
    }
    
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */