/*
 *  DFS - Depth-First Search
 */

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        for(auto& ticket : tickets) {
            flight[ticket.first].push_back(ticket.second);
        }
        
        // guarantee smallest lexical order
        for(auto& e : flight) {
            sort(e.second.begin(), e.second.end());
        }
        
        vector<string> trip(tickets.size() + 1);
        trip[0] = "JFK";
        
        visit(trip, 1);
        
        return trip;
    }
    
private:
    unordered_map<string, vector<string>> flight;
    
    bool visit(vector<string>& trip, int idx) {
        if(trip.size() == idx) {
            return true;
        }
        
        string from = trip[idx - 1];
        
        if(flight.find(from) == flight.end()) {
            return false;;
        }
        
        vector<string>& des = flight[from];
        
        for(int i = 0; i < des.size(); i++) {
            if(des[i] == "@") {
                continue;
            }
            
            string to = des[i];
            trip[idx] = to;
            
            des[i] = "@";
            if(visit(trip, idx + 1) == true) {
                return true;
            }
            des[i] = to;
        }
        
        return false;
    }
};