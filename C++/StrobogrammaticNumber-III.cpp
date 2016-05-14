/*
 *  Recursion - DFS - 528ms
 *
 */


class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        findStrobogrammatic(low, high, "");
        findStrobogrammatic(low, high, "0");
        findStrobogrammatic(low, high, "1");
        findStrobogrammatic(low, high, "8");
        
        return cnt;
    }
    
private:
    unordered_map<char, char> dirc = {{'6', '9'}, {'9', '6'}, {'0', '0'}, {'1', '1'}, {'8', '8'}};
    int cnt = 0;
    
    void findStrobogrammatic(string& low, string& high, string s){
        // greater
        if(s.size() > high.size()){
            return;
        }
        
        if(s.size() >= low.size()){
            if(inRange(low, high, s) == true){
                //cout << s << endl;
                cnt += 1;
            }
        }
        
        for(auto& e : dirc){
            string ss = e.first + s + e.second;
            findStrobogrammatic(low, high, ss);
        }
    }
    
    bool inRange(string& low, string& high, string& s){
        if(s.empty() || (s.size() > 1 && s[0] == '0')) return false;
        
        bool l = true; // true if s is lower than string low
        bool h = true; // true if s is higher than string high
        if(s.size() == low.size()){
            for(int i = 0; i < s.size(); i++){
                if(s[i] == low[i]){
                    continue;
                }else{
                    if(s[i] > low[i]){
                        l = true;
                    }else if(s[i] < low[i]){
                        l = false;
                    }
                    break;
                }
            }
        }
        if(s.size() == high.size()){
            for(int i = 0; i < s.size(); i++){
                if(s[i] == high[i]){
                    continue;
                }else{
                    if(s[i] < high[i]){
                        h = true;
                    }else if(s[i] > high[i]){
                        h = false;
                    }
                    break;
                }
            }
        }
        
        if(l == true && h == true) return true;
        else return false;
    }
};




/*
 *  Referenced solution - 76ms
 *
 */


class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        for(int len = low.length(); len <= high.length(); len++){
            string s(len, '0');
            findStrobogrammatic(low, high, s, 0, len-1);
        }
        
        return cnt;
    }
    
private:
    unordered_map<char, char> dirc = {{'6', '9'}, {'9', '6'}, {'0', '0'}, {'1', '1'}, {'8', '8'}};
    int cnt;
    
    void findStrobogrammatic(string& low, string& high, string s, int left, int right){
        if(left > right){
            if((s.length() == low.length() && s.compare(low) < 0) || (s.length() == high.length() && s.compare(high) > 0)){
                return;
            }
            cnt++;
            return;
        }
        
        for(auto e : dirc){
            s[left] = e.first;
            s[right] = e.second;
            
            if(s.length() > 1 && s[0] == '0'){
                continue;
            }
            
            if(left < right || (left == right && e.first == e.second)){
                findStrobogrammatic(low, high, s, left+1, right-1);
            }
        }
    }
};