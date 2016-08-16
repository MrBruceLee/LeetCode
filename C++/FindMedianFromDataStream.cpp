//  #include <functional>   // std::greater
//  #include <functional>   // std::less


class MedianFinder {
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxHeap.empty() == true || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        /* the return type of size() is size_type, which is an unsigned variable */
        if(maxHeap.size() - 1 > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        double median = 0;
        if(maxHeap.size() == minHeap.size()) {
            median = (double)(maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            median = (double)maxHeap.top();
        }
        return median;
    }
    
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();