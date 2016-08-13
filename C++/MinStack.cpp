class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        S.push(x);
        if(minS.empty() == true || minS.top() >= x) {
            minS.push(x);
        }
    }
    
    void pop() {
        if(S.top() == minS.top()) {
            minS.pop();
        }
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minS.top();
    }
    
private:
    stack<int> S;
    stack<int> minS;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */