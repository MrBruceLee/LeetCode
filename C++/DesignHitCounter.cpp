class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hits.push(timestamp + 300);
    }
    
    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int size = hits.size();
        for(int i = 0; i < size; i++) {
            if(hits.front() <= timestamp) {
                hits.pop();
            } else {
                break;
            }
        }
        return hits.size();
    }
    
private:
    queue<int> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */