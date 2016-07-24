class WordDictionary {
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *ptr = head;
        for(int i = 0; i < word.size(); i++) {
            int pos = word[i] - 'a';
            if(ptr->child[pos] == NULL) {
                ptr->child[pos] = new TrieNode();
            }
            ptr = ptr->child[pos];
        }
        ptr->word = word;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word, 0, head);
    }
    
private:
    struct TrieNode{
        TrieNode* child[26];
        string word;
        TrieNode() {
            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            word.clear();
        }
    };
    
    TrieNode* head;
    
    bool dfs(string& word, int idx, TrieNode* ptr) {
        for(int i = idx; i < word.size(); i++) {
            if(word[i] == '.') {
                for(int j = 0; j < 26; j++) {
                    if(ptr->child[j] != NULL) {
                        if(dfs(word, i+1, ptr->child[j]) == true) {
                            return true;
                        }
                    }
                }
                return false;
                
            } else {
                int pos = word[i] - 'a';
                if(ptr->child[pos] != NULL) {
                    ptr = ptr->child[pos];
                } else {
                    return false;
                }
            }
        }
        return (ptr->word).empty() == false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");