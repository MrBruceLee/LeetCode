/*
 *  DFS
 *
 */


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if( n % 2 == 0 ){
            recursion("", n, 0);
            
        }else{
            recursion("0", n, 1);
            recursion("1", n, 1);
            recursion("8", n, 1);
            
        }
        
        return res;
    }
    
private:
    unordered_map<char, char> dirc = {{'0','0'}, {'1','1'}, {'8','8'}, {'6','9'}, {'9','6'}};
    vector<string> res;
    
    void recursion(string& s, int n, int idx){
        if(idx == n) {
            res.push_back(s);
            return;
        }
        
        for(auto& e : dirc){
            if(idx >= n -2 && e.first == '0')
                continue;
            
            s.insert(s.begin(), e.first);
            s.push_back(e.second);
            
            recursion(s, n, idx+2);
            
            s = s.substr(1, s.size()-2);
        }
    }
};