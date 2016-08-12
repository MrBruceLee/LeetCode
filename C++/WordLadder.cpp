/*
 *  BFS - Breadth First Search
 */


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        // BFS - breadth first search
        queue<string> q;
        q.push(beginWord);
        
        int length = 0; // the results
        
        while(q.empty() == false) {
            int size = q.size();
            length += 1; // for each level, increase length by 1
            
            // check each word in the same level
            for(int i = 0; i < size; i++) {
                string theWord = q.front();
                q.pop();
                
                // find all possible changes of theWord - runtime: O(theWord.size() * 26)
                for(int j = 0; j < theWord.size(); j++) {
                    char c = theWord[j];
                    
                    for(int k = 0; k < 26; k++) {
                        theWord[j] = 'a' + k;
                        
                        // if the changes equals to endWord, return (length + 1)
                        if(theWord == endWord) {
                            return length + 1;
                        }
                        
                        // if the changes in wordList, that means theWord may one of the transformation
                        // insert theWord into Q, and erase theWord from wordList
                        if(wordList.count(theWord) == 1) {
                            q.push(theWord);
                            wordList.erase(theWord);
                        }
                    }
                    
                    // recover theWord for further changes
                    theWord[j] = c;
                }
            }
        }
        
        // Could not reach endWord, because there is no such transformation sequence
        return 0;
    }
};