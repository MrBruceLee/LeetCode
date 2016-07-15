class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // if length difference is larger than 1, it must not one edit distance
        if(abs((int)s.size() - (int)t.size()) > 1) {
            return false;
        }
        
        // ignore the case that s or t are empty string
        s.push_back('*');
        t.push_back('*');
        
        for(int i = 0; i < min(s.size(), t.size()); i++) {
            if(s[i] == t[i]) {
                continue;
            }
            
            // one modification
            if(s.size() == t.size()) {
                return s.substr(i+1) == t.substr(i+1);
            }
            // one deletion on string s
            if(s.size() > t.size()) {
                return s.substr(i+1) == t.substr(i);
            }
            // one deletion on string t
            if(s.size() < t.size()) {
                return s.substr(i) == t.substr(i+1);
            }
        }
        
        return false;
    }
};