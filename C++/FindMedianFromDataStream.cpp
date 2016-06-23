//  #include <functional>   // std::greater
//  #include <functional>   // std::less


class MedianFinder {
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if(max_heap.empty() == true || num <= max_heap.top()) {
            max_heap.emplace(num);
        } else {
            min_heap.emplace(num);
        }
        
        // the return type of size() is size_type, which is an unsigned variable
        if((int)max_heap.size() - (int)min_heap.size() > 1) {
            // if( max_heap.size() > min_heap.size() + 1) {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
            
        } else if((int)min_heap.size() - (int)max_heap.size() > 0) {
            // } else if(min_heap.size() > max_heap.size()) {
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        double median = 0;
        if(min_heap.size() == max_heap.size()) {
            median = (double)(min_heap.top() + max_heap.top()) / 2.0;
        } else {
            median = (double)max_heap.top();
        }
        
        return median;
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> min_heap; // right side --> larger number
    priority_queue<int, vector<int>, less<int>> max_heap; // left side  --> smaller number
};


// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();