/*
 *  Backtracking:
 *  Naive approch 672ms; Improved approch 488ms
 *
 *  There are 32ms or 0ms solution on LeetCode
 *
 */


class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        return findMatch(pattern, 0, str, 0);
    }
    
private:
    unordered_map<char, string> cs;
    unordered_map<string, char> sc;
    
    bool findMatch(string& pattern, int ic, string& str, int is){
        int lenc = pattern.size();
        int lens = str.size();
        if(ic == lenc && is == lens) return true;
        if(ic == lenc || is == lens) return false;
        
        for(int j = is; j < lens; j++){
            char c = pattern[ic];
            string s = str.substr(is, j-is+1);
            
            // if cs[c] = "abcd" while s = "ad", there is no need to increase the lenth of s
            // add the condition improving runtime from 672ms to 488ms
            if(cs.find(c) != cs.end()){
                if(cs[c][j-is] != s.back())
                    return false;
            }
            
            // both c & s are not in map --> map each other and do recursively check
            if(cs.find(c) == cs.end() && sc.find(s) == sc.end()){
                cs[c] = s;
                sc[s] = c;
                if(findMatch(pattern, ic+1, str, j+1) == true)
                    return true;
                cs.erase(c);
                sc.erase(s);
                
            // both c & s are both in map and already mapping with each other --> do recursively check
            }else if(cs.find(c) != cs.end() && sc.find(s) != sc.end()){
                if(cs[c] == s && sc[s] == c){
                    if(findMatch(pattern, ic+1, str, j+1) == true)
                        return true;
                }
            }
        }
        return false;
    }
};