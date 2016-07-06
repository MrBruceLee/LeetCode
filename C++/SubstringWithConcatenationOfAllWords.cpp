// runtime - O(s.size() * wordSize)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        if(words.empty() == true) {
            return results;
        }
        
        unordered_map<string, int> wordsDirect;
        for(string& s : words) {
            wordsDirect[s] += 1;
        }
        
        // a list of words that are all of the same length
        int wordSize = words[0].size();
        
        // the expected string may begin from any index, it's not necessary to be a multiple of wordSize
        // e.g. "abcdefooowingdingbarrwingmonkeypoundcake"
        //      ["fooo","barr","wing","ding","wing"]
        // ans: [5], not a multiple of 4
        for(int start = 0; start < wordSize; start++) {
            int wordCount = 0; // how many valid words so far
            unordered_map<string, int> cache; // store those valid words here
            
            for(int i = start; i + wordSize <= s.size(); i += wordSize) {
                string theWord = s.substr(i, wordSize);
                
                // it's a valid word
                if(wordsDirect.find(theWord) != wordsDirect.end()) {
                    cache[theWord] += 1;
                    wordCount += 1;
                    
                    // while the number of a certain word is larger than it should be, remove them
                    // e.g. "barfoofoobarthefoobarman"
                    //      ["bar","foo","the"]
                    // ans: [6,9,12]
                    while(cache[theWord] > wordsDirect[theWord]) {
                        string removeWord = s.substr(i - (wordCount-1) * wordSize, wordSize);
                        cache[removeWord] -= 1;
                        wordCount -= 1;
                    }
                    
                    // it's an invalid word
                } else {
                    cache.clear();
                    wordCount = 0;
                }
                
                if(wordCount == words.size()) {
                    results.push_back(i - (wordCount-1) * wordSize);
                }
            }
        }
        
        return results;
    }
};