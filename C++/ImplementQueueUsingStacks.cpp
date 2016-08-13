class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        S2.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if(S1.empty() == true) {
            peek();
        }
        S1.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if(S1.empty() == true) {
            while(S2.empty() == false) {
                S1.push(S2.top());
                S2.pop();
            }
        }
        return S1.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return S1.empty() == true && S2.empty() == true;
    }
    
private:
    stack<int> S1; // pop stack
    stack<int> S2; // push stack
};