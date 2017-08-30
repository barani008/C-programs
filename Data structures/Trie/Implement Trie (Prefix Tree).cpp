/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
struct trieNode{
        unordered_map<char, trieNode*> map;
        bool endsHere;
};

class Trie {
public:
    struct trieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new trieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct trieNode* cur = root;
        for(int i=0;i<word.size();i++){
            if(cur->map.find(word[i])!=cur->map.end()){
                cur = cur->map[word[i]];
            }else{
                return false;
            }
        }
        return cur->endsHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct trieNode* cur = root;
        for(int i=0;i<prefix.size();i++){
            if(cur->map.find(prefix[i])!=cur->map.end()){
                cur = cur->map[prefix[i]];
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */