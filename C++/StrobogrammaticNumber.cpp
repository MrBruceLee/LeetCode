/*
 *  unordered_map - <unordered_map>
 *  unordered_map is implemented by hash table, while map is implemented by red-black tree
 *
 */


class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> dirc = {{'0','0'}, {'1','1'}, {'8','8'}, {'6','9'}, {'9','6'}};
        
        int front = 0;
        int back = num.size() - 1;
        while(front <= back){
            if( dirc.find(num[front]) == dirc.end() || dirc[num[front]] != num[back])
                return false;
            
            front++;
            back--;
        }
        
        return true;
    }
};