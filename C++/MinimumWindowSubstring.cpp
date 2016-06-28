class Solution {
public:
    string minWindow(string s, string t) {
        // construct hash table and store each character in string t
        int table[256] = {0};
        for(char c : t) {
            table[c]++;
        }
        
        int counter = t.size(); // total character number inside string T
        int head = 0;  // head of valid window
        int distance = INT_MAX;  // length of valid window
        
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++) {
            // table[s[fast]] > 0 means string T contains s[fast]
            if(table[s[fast]] > 0) {
                counter--;
            }
            table[s[fast]]--;
            
            // counter == 0 means the current window is valid (the window contains all the characters in T)
            while(counter == 0) {
                // record it, if it is a minimum window
                if(fast - slow + 1 < distance) {
                    head = slow;
                    distance = fast - slow + 1;
                }
                
                // shrink the window until it becomes invalid
                table[s[slow]]++;
                if(table[s[slow]] > 0) {
                    counter++;
                }
                slow++;
            }
        }
        
        if(distance < INT_MAX) {
            return s.substr(head, distance);
        } else {
            return "";
        }
    }
};