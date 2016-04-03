/*
 *  Reference: http://www.danielbit.com/blog/puzzle/leetcode/leetcode-longest-substring-with-at-most-two-distinct-characters
 *  maintian a sliding window - two pointer
 *
 */

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty()) return 0;
        
        int start = 0; // starting point of sw
        int end = -1; // end point of sw
        int len = 0; // max length
        
        for(int i = 1; i < s.size(); i++){
            // if current char equals previous char, continue
            if(s[i] == s[i-1]) continue;
            
            // if current char is different with s[end]
            if(end >= 0 && s[i] != s[end]){
                len = max(len, i - start); // update max length
                start = end + 1; // update starting point of sw
            }
            
            // When current char is different with previous char, we update end point to the previous one
            // so that, "i" and "end" are always pointint to different characters.
            // we update length and start if only if current char is not equal with "i" and "end"
            end = i - 1;
        }
        
        // take care of the case that the string contains less than two type of characters
        // e.g "aaaa", "aabbaa"
        return max((int)s.size()-start, len);
    }
};