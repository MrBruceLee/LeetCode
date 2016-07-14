/*
 *  DFS
 *  Time Limit Exceeded
 */


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> results;
        
        resolveString(s, wordDict, "", results);
        
        return results;
    }
    
private:
    void resolveString(string s, unordered_set<string>& wordDict, string sentence, vector<string>& results) {
        if(s.length() <= 0) {
            sentence.pop_back();
            results.push_back(sentence);
        }
        
        for(int i = 1; i <= s.length(); i++) {
            string subs = s.substr(0, i);
            if(wordDict.find(subs) != wordDict.end()) {
                resolveString(s.substr(i), wordDict, sentence + subs + " ", results);
            }
        }
    }
};




"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
