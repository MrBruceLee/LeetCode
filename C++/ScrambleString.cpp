class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) {
            return true;
        }
        
        int len = s1.length();
        char c[256] = {0};
        for(int i = 0; i < len; i++){
            c[s1[i]]++;
            c[s2[i]]--;
        }
        for(int i = 0; i < 256; i++){
            if(c[i] != 0) {
                return false;
            }
        }
        
        for(int i = 1; i < len; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) == true &&
               isScramble(s1.substr(i), s2.substr(i)) == true){
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(len-i)) == true &&
               isScramble(s1.substr(i), s2.substr(0, len-i)) == true){
                return true;
            }
        }
        
        return false;
    }
};