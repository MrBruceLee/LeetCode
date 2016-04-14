/*
 *  Bread-First Search - BFS
 *  Reference: https://leetcode.com/discuss/67842/share-my-java-bfs-solution
 *
 *
 *  Time Complexity:
 *
 *  On the first level, there's only one string which is the input string s, let's say the length of it is n, to check whether it's valid, we need O(n) time. On the second level, we remove one ( or ) from the first level, so there are C(n, n-1) new strings, each of them has n-1 characters, and for each string, we need to check whether it's valid or not, thus the total time complexity on this level is (n-1) x C(n, n-1). Come to the third level, total time complexity is (n-2) x C(n, n-2), so on and so forth...
 *
 *  Finally we have this formula:
 *
 *  T(n) = n x C(n, n) + (n-1) x C(n, n-1) + ... + 1 x C(n, 1) = n x 2^(n-1)
 *
 */


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if(s.size() == 0){
            res.push_back(s);
            return res;
        }
        
        queue<string> q; // store strings that need to be checked
        unordered_set<string> visited;  // store strings that are already checked
        q.push(s);
        visited.insert(s);
        
        bool found = false;
        while(q.empty() == false){
            string check = q.front();
            q.pop();
            
            if(isValid(check) == true){
                res.push_back(check);
                found = true;
            }
            
            // if found, stop to increase the level depth
            if(found == true) continue;
            
            for(int i = 0; i < check.size(); i++){
                if(check[i] != '(' && check[i] != ')') continue;
                
                string add = check.substr(0, i) + check.substr(i+1);
                
                if(visited.count(add) == 0){
                    q.push(add);
                    visited.insert(add);
                }
            }
        }
        
        return res;
    }
    
private:
    bool isValid(string& s){
        int cnt = 0;
        for(auto c : s){
            if(c == '(') cnt++;
            else if (c == ')'){
                if(cnt == 0) return false;
                else cnt--;
            }
        }
        return cnt == 0;
    }
};