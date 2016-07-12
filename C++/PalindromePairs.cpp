/*
 *  Reference & explanation:
 *  https://discuss.leetcode.com/topic/40654/easy-to-understand-ac-c-solution-o-n-k-2-using-map/2
 */

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> direct;
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            direct[word] = i;
        }
        
        vector<vector<int>> results;
        
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if(direct.find("") != direct.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == direct[""]) {
                    continue;
                }
                if(isPalindrome(words[i])) {
                    results.push_back({direct[""], i});
                }
            }
        }
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                
                //words[i] + words[sth]
                if(direct.find(left) != direct.end() && direct[left] != i && isPalindrome(right) == true) {
                    results.push_back({i, direct[left]});
                }
                
                if(direct.find(right) != direct.end() && direct[right] != i && isPalindrome(left) == true) {
                    results.push_back({direct[right], i});
                }
            }
        }
        
        return results;
    }
    
private:
    bool isPalindrome(string s) {
        int front = 0;
        int end = s.length() - 1;
        
        while(front < end) {
            if(s[front] != s[end]) {
                return false;
            }
            
            front++;
            end--;
        }
        
        return true;
    }
};