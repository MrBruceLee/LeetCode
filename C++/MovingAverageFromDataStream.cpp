class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capacity = size;
        sum = 0.0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        
        if(q.size() > capacity) {
            sum -= q.front();
            q.pop();
        }
        
        return (double)sum / q.size();
    }
    
private:
    queue<int> q;
    int capacity;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */