/*
 *  Not the optimal solution
 */


class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k == 0) {
            return str;
        }
        
        int length = str.length();
        unordered_map<char, int> mp;
        for(auto c : str) {
            mp[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto e : mp) {
            pq.push(make_pair(e.second, e.first));
        }
        
        string res;
        while(pq.empty() == false) {
            vector<pair<int, char>> cache;
            
            int cnt = min(length, k);
            for(int i = 0; i < cnt; i++) {
                if(pq.empty() == true) {
                    return "";
                }
                
                auto temp = pq.top();
                pq.pop();
                
                res += temp.second;
                if(--temp.first > 0) {
                    cache.push_back(temp);
                }
                
                length--;
            }
            
            for(auto e : cache) {
                pq.push(e);
            }
        }
        
        return res;
    }
};