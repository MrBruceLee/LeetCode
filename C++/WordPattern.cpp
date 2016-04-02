/*
 *  Here we maintain two maps: 
 *  1. map (char) to (string) 
 *  2. map (string) to (char)
 *
 *  insert elements to map if and only if cs & sc are both missing the elements
 *
 *  #include <sstream>      // std::stringstream
 *
 */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        unordered_map<char, string> cs;
        unordered_map<string, char> sc;
        
        int c;
        string s;
        int i = 0;
        
        while(getline(ss, s, ' ')){
            if(i == pattern.size()) return false; // pattern is shorter than str
            c = pattern[i++];
            
            if(cs.find(c) == cs.end() && sc.find(s) == sc.end()){
                cs[c] = s;
                sc[s] = c;
            }
            
            if(cs[c] != s || sc[s] != c) return false;
        }
        
        if(i < pattern.size()) return false; // str is shorter than pattern
        
        return true;
    }
};