/*
 *  Runtime - O(N)
 *  Space - O(N)
 */


class Solution {
public:
    string reverseString(string s) {
        string rs;
        
        for(int i = s.length() - 1; i >= 0; i--) {
            rs += s[i];
        }
        
        return rs;
    }
};



/*
 *  Inplace solution
 *  Runtime - O(N)
 *  Space - O(1)
 */


class Solution {
public:
    string reverseString(string s) {
        int front = 0;
        int end = s.length() - 1;
        
        while(front < end) {
            // swap(s[front], s[end]);
            char tmp = s[front];
            s[front] = s[end];
            s[end] = tmp;
            
            front++;
            end--;
        }
        
        return s;
    }
};



/*
 *  tricky....
 */


class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};