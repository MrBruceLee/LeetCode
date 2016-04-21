/*
 *  Runtime - O(N*logN)
 *  Space - O(K)
 *
 *  priority_queue - <queue>
 *  This context of priority queue is similar to a heap
 *
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < nums.size(); i++){
            // exceed window size
            while( !pq.empty() && pq.top().second <= i-k)
                pq.pop();
            
            pq.push(make_pair(nums[i], i));
            
            if(i >= k-1)
                res.push_back(pq.top().first);
        }
        
        return res;
    }
};



/*
 *  Runtime - O(N)
 *  Space - O(K)
 *
 *  deque - <deque>
 *  double-ended queue
 *
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> idxQ;
        
        for(int i = 0; i < nums.size(); i++){
            // exceed window size
            while( !idxQ.empty() && idxQ.front() <= i-k)
                idxQ.pop_front();
            
            // number at queue's back is smaller than current number
            while( !idxQ.empty() && nums[i] > nums[idxQ.back()] )
                idxQ.pop_back();
            
            idxQ.push_back(i);
            
            if(i >= k-1)
                res.push_back(nums[idxQ.front()]);
        }
        
        return res;
    }
};