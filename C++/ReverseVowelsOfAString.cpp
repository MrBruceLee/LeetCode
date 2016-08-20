class Solution {
public:
    string reverseVowels(string s) {
        int begin = 0;
        int end = s.size() - 1;
        
        string vowels = "aeiouAEIOU";
        
        while(begin < end) {
            while(begin < end && vowels.find(s[begin]) == string::npos) {
                begin++;
            }
            while(begin < end && vowels.find(s[end]) == string::npos) {
                end--;
            }
            
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
        
        return s;
    }
};