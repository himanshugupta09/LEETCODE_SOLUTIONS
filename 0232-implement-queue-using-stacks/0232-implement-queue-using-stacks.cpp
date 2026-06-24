class MyQueue {
    stack<int>stk1;
    stack<int>stk2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        shift();
        if(stk2.empty()) return -1;
        int x = stk2.top();
        stk2.pop();
        return x;
    }
    
    int peek() {
        shift();
        if(stk2.empty()) return -1;
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }

    private:
    void shift() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */