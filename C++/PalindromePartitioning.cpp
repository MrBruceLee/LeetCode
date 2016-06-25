class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;
        
        findPartitions(s, p, res);
        
        return res;
    }
    
private:
    void findPartitions(string s, vector<string>& p, vector<vector<string>>& res) {
        if(s.size() == 0) {
            res.push_back(p);
        }
        
        for(int i = 1; i <= s.size(); i++) {
            /*  check if s[0...i] is a palindrome:
             *      if true:    push to vector p, and do recursion to the rest string
             *      if false:   go through the loop again and check s[0...i+1]
             */
            string ss = s.substr(0, i);
            
            if(isPalindrome(ss) == true) {
                p.push_back(ss);
                findPartitions(s.substr(i), p, res);
                p.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;
        
        while(front < back) {
            if(s[front] != s[back]) {
                return false;
            }
            
            front++;
            back--;
        }
        
        return true;
    }
};